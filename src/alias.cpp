#include "../include/alias.hpp"

unordered_map<string, string> aliasMap;

void loadAliases()
{
    string s = string(getenv("HOME")) + "/.vshrc";
    ifstream file(s);

    if (!file.is_open())
        return;

    string line;
    while (getline(file, line))
    {
        if (line.rfind("alias ", 0) == 0)
        {
            size_t eq = line.find('=');
            if (eq != std::string::npos)
            {
                std::string name = line.substr(6, eq - 6);
                std::string cmd = line.substr(eq + 1);

                if ((cmd.front() == '\'' && cmd.back() == '\'') ||
                    (cmd.front() == '"' && cmd.back() == '"'))
                {
                    cmd = cmd.substr(1, cmd.size() - 2);
                }

                aliasMap[name] = cmd;
            }
        }
    }

    file.close();
}