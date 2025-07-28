# VSH SHELL

A custom Unix shell implementation written in C++17 with advanced terminal features, alias support, and external command execution capabilities.


## ✅ Requirements
- C++17 or higher
- make utility

## 🛠️ Build Instructions
1. Open terminal in the root folder of the project.
2. Run:
```bash
  make
```
3. Then execute:
```bash
  ./app
```

## 🏗️ Project Structure

```
vsh/
├── include/          # Header files
│   ├── shell.hpp     # Main shell interface
│   ├── terminal.hpp  # Terminal control functions
│   └── alias.hpp     # Alias system interface
├── src/              # Source files
│   ├── shell.cpp     # Core shell implementation
│   ├── terminal.cpp  # Terminal input handling
│   └── alias.cpp     # Alias loading and management
├── main.cpp          # Entry point
├── Makefile          # Build configuration
└── README.md         # This file
```

## Supported Commands (so far)

1. clear — clears the screen
2. pwd — prints the current working directory
3. source — sources alias definitions from ~/.vshrc
✅ All system binaries like ls, echo, cat, touch, etc., are supported and executed like in a normal shell.

##  Aliases via source

- You can define aliases by editing your ~/.vshrc file:
```bash
  alias cls="clear"
  alias ll="ls -l"
  alias la="ls -a"
```
- Then load them in your shell session using:
```bash
  source
```

