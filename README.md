hell



>"The gates of shell" project
> 

"The gates of shell" is a Holberton School project in the first trimester, helps student to understand the advanced 
concepts behind the shell program including process, system call, bit manipulation, file managment and error 
handling.
Bash is a command processor that typically runs in a text window where the user types commands that cause actions.
Bash can also read and execute commands from a file, called a shell script.


## Basic loop of a shell:

-  Read command from standard input.
- Parse commandline string into an executable program and its arguments.
- Run parsed command.

Our custom shell was developed and tested on Ubuntu 14.04 LTS.
Features:

- displays a prompt and waits for user to type a command
- can handle commands with options and arguments
- prompt displays again each time command is executed
- uses PATH variable to find executable command
- if executable is not found, prints an error message and displays prompt again
- includes an exit function that exits the shell

## Getting HSH
In order to install the shell and get benefits of its features you need to clone the current project, and compile it using the command down below. You need to make sure that this shell tested and garantees work based on gcc-4.8 and the C90 standard.
 ```-gcc -Wall -Werror -Wextra -pedantic -std=gnu89 ```

## Features:

- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- Handles the “end of file” condition (Ctrl+D)
- Handles the command line with arguments
- Handles the PATH
- Support the exit features and the exit status
- Handles the Ctrl-C to not terminate the shell
- Handles the command seperator ;
- Handles && and || logical operators
- Handles variable replacements $? and $$
- Supports the file input.

## File Contents:

This repository contains the following files:

| File | Description |
| ------ | ------ |
| main.c | main function |
| main.h | header file containing function prototypes |
| _strings.c |  contains functions related to strings
| _wich.c | used to identify the location of a given executable that is executed when you type the command in the terminal prompt. |
| _getenv.c| searches for the environment string pointed to by name and returns the associated value to the string. |
| _printf.c | custom printf function, sends formatted output to stdout.|
| _printf_aux.c|contains _putchar,  print_number_xd, print_number, print_char and print_string that prints characters, numbers and string respectively.
| repeat.c |
| hsh | exeutable file for the shell
| man_1_simple_shell| manual

## Usage


-Enter custom shell by typing "./hsh". You should be prompted with a ($).
-Type a command of your liking and press "Enter".
-Appropriate output will appear.
-Prompt reappears and awaits your next command.
-Exit shell by typing "exit"


## Authors

Marcelo Rodríguez | [GitHub](https://github.com/Marcelorb1)
Romina Guimaraens | [GitHub](https://github.com/rominaguimaraens)
   

