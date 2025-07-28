#include "../include/shell.hpp"
#include "../include/terminal.hpp"
#include "../include/alias.hpp"

void executePWD()
{
    cout << fs::current_path().string() << endl;
}

void executeExit()
{
    exit(EXIT_SUCCESS);
}

void executeHelp()
{
    cout << "Help will be soon available" << endl;
}

void executeClear()
{
    cout << "\033[H\033[J";
}

void executeSource()
{
    loadAliases();
}

vector<string> parseUserInput(string s)
{
    vector<string> inputs;
    stringstream ss(s);
    string word;
    while (ss >> word)
    {
        inputs.push_back(word);
    }
    return inputs;
}

void runExternalCommand(vector<string> input)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        signal(SIGINT, SIG_DFL);
        vector<char *> argv;
        for (string &s : input)
        {
            argv.push_back(&s[0]);
        }

        argv.push_back(nullptr);
        if (execvp(argv[0], argv.data()) == -1)
        {
            cout << argv[0] << " : Command not found" << endl;
        }
        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
    }
    else
    {
        perror("Fork Failed");
    }
}

void executeCommand(vector<string> input)
{
    if (input.empty())
        return;
    string command = input[0];
    if (command == "cd")
    {
        // executeCd();
    }
    else if (command == "clear")
    {
        executeClear();
    }
    else if (command == "help")
    {
        executeHelp();
    }
    else if (command == "quit" || command == "exit")
    {
        executeExit();
    }
    else if (command == "pwd")
    {
        executePWD();
    }
    else if (command == "source")
    {
        executeSource();
    }
    else if (aliasMap.find(command) != aliasMap.end())
    {
        executeCommnad(parseUserInput(aliasMap[command]));
    }
    else
    {
        runExternalCommand(input);
    }
}

string takeInput(const string &prompt)
{
    enableRawMode();
    string buffer;
    size_t cursor = 0;

    char c;
    cout << prompt << flush;

    while (true)
    {
        if (read(STDIN_FILENO, &c, 1) == 1)
        {
            if (c == '\n')
            {
                cout << endl;
                break;
            }
            else if (c == 127 || c == 8)
            { // backspace
                if (cursor > 0)
                {
                    buffer.erase(cursor - 1, 1);
                    cursor--;
                }
            }
            else if (c == '\x1b')
            {
                char seq[2];
                read(STDIN_FILENO, &seq[0], 1);
                read(STDIN_FILENO, &seq[1], 1);

                if (seq[0] == '[')
                {
                    switch (seq[1])
                    {
                    case 'C': // Right
                        if (cursor < buffer.size())
                            cursor++;
                        break;
                    case 'D': // Left
                        if (cursor > 0)
                            cursor--;
                        break;
                    }
                }
            }
            else if (c == 4)
            {
                if (buffer.size() == 0)
                {
                    cout << endl;
                    exit(EXIT_SUCCESS);
                }
            }
            else
            {
                buffer.insert(buffer.begin() + cursor, c);
                cursor++;
            }

            // Clear current line
            cout << "\r\033[K";
            cout << prompt << buffer;

            // Move cursor back if needed
            int rightShift = buffer.size() - cursor;
            if (rightShift > 0)
            {
                cout << "\033[" << rightShift << "D";
            }

            cout << flush;
        }
    }

    return buffer;
}

void sigint_handler(int sig)
{
    cout << "Signal Recieved" << sig << endl;
}

void shell()
{
    cout << "Welcome to our Vizz SHELL" << endl;
    signal(SIGINT, sigint_handler);
    loadAliases();

    while (true)
    {
        string input = takeInput("➜  vsh ");
        if (input.size() > 0)
        {
            vector<string> arr = parseUserInput(input);
            executeCommnad(arr);
        }
    }
}
