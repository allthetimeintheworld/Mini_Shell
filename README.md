# Minishell

Minishell is a project from 42 School where you will build a simple shell, much like your own little version of Bash. This project provides deep insights into processes, file descriptors, and system calls, while ensuring strict adherence to the 42 Norm.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Bonus Features](#bonus-features)
- [Testing](#testing)
- [Contributors](#contributors)

## Description
Minishell is a basic shell implementation that allows users to execute commands in an interactive or non-interactive environment. It supports features like redirection, pipes, environment variables, and several built-in commands. The project helps in understanding the basics of process creation and management using the C programming language.

## Features
- Displays a prompt while waiting for commands.
- Supports command execution using both absolute and relative paths.
- Command history support (via readline).
- Handles single (`'`) and double (`"`) quotes in commands.
- Implements the following built-in commands:
  - `echo` with option `-n`.
  - `cd` with relative or absolute paths.
  - `pwd` with no options.
  - `export`, `unset`, `env` with no options.
  - `exit` to terminate the shell.
- Redirection:
  - Input (`<`), Output (`>`), Append (`>>`), and Heredoc (`<<`).
- Pipes (`|`) to connect multiple commands.
- Environment variable expansion (`$VARIABLE`, `$?`).
- Signal handling for `Ctrl-C`, `Ctrl-D`, and `Ctrl-\` in interactive mode.

## Requirements
- The project must be written in C and comply with the [42 Norm](https://github.com/42School/norminette).
- Must use the following functions: `readline`, `add_history`, `printf`, `malloc`, `free`, `write`, `fork`, `execve`, `pipe`, `dup`, `signal`, `wait`, etc.
- Memory leaks are forbidden except for those caused by `readline`.

## Installation
1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/yourusername/minishell.git
   cd minishell
