#include <iostream>
#include <vector>
#include <sstream>
#include <filesystem>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;
namespace fs = filesystem;

void executePWD();
void executeExit();
void executeHelp();
void executeClear();
vector<string> parseUserInput(string s);
void runBuiltInCommand(vector<string> input);
string takeInput(const string &input);
void shell();
