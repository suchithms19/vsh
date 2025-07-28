# VSH SHELL

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

