# Simple Shell

This project is a simple UNIX command line interpreter written in C.

## Description

The simple shell can execute commands read from the standard input or from a file. It supports the following features:

- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word or one word followed by arguments.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors, including the end of file condition (Ctrl+D).
- Handle the PATH variable to find executables.
- Implement some built-in commands: exit, env, setenv, unsetenv.

## Compilation

The shell will be compiled this way:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

The shell can work in interactive mode:

```bash
$ ./hsh
:) /bin/ls
barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
:) ls -l
total 96
-rw-rw-r-- 1 vagrant vagrant   186 Nov 25 21:40 barbie_j
-rw-rw-r-- 1 vagrant vagrant   132 Nov 25 21:40 env-environ.c
-rw-rw-r-- 1 vagrant vagrant   133 Nov 25 21:40 env-main.c
-rwxrwxr-x 1 vagrant vagrant 13864 Nov 25 21:40 exec
-rw-rw-r-- 1 vagrant vagrant   356 Nov 25 21:40 exec.c
-rwxrwxr-x 1 vagrant vagrant 13616 Nov 25 21:40 fork
-rw-rw-r-- 1 vagrant vagrant   209 Nov 25 21:40 fork.c
-rwxrwxr-x 1 vagrant vagrant   879 Nov 25 21:40 hsh
-rwxrwxr-x 1 vagrant vagrant   879 Nov 25 21:40 mypid
-rw-rw-r-- 1 vagrant vagrant    17 Nov 25


# File Structure

The project consists of the following files:

- README: Contains the documentation and instructions for the project.
- builtins.c: Contains the functions that implement the built-in commands, such as cd, exit, env, setenv, unsetenv, alias, etc., and use the variables.
- executor.c: Contains the functions that execute the command based on the tokens, handle pipes, redirections, wildcards, etc., use the path, fork and execve functions, wait for the child process, etc.
- getline.c: Contains the function that reads a line of input from stdin or a file.
- handler.c: Contains the functions that handle errors and signals.
- main.c: Contains the main function that initializes, loops, and terminates the shell program.
- parser.c: Contains the functions that parse the input line into tokens, handle special characters, logical operators, separators, etc., and use the custom strtok function.

