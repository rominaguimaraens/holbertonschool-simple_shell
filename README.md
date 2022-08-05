#                                             Simple shell
![linux logo](https://www.profesionalreview.com/wp-content/uploads/2017/03/Shell-Script-Linux.png)

"The gates of shell" is a Holberton School project in the first trimester, helps student to understand the advanced 
concepts behind the shell program including process, system call, bit manipulation, file managment and error 
handling.
Bash is a command processor that typically runs in a text window where the user types commands that cause actions.
Bash can also read and execute commands from a file, called a shell script.

## List of allowed functions

- access (man 2 access)

- chdir (man 2 chdir)

- close (man 2 close)

- closedir (man 3 closedir)

- execve (man 2 execve)

- exit (man 3 exit)

- _exit (man 2 _exit)

- fflush (man 3 fflush)

- fork (man 2 fork)

- free (man 3 free)

- getcwd (man 3 getcwd)

- getline (man 3 getline)

- getpid (man 2 getpid)

- isatty (man 3 isatty)

- kill (man 2 kill)

- malloc (man 3 malloc)

- open (man 2 open)

- opendir (man 3 opendir)

- perror (man 3 perror)

- read (man 2 read)

- readdir (man 3 readdir)

- signal (man 2 signal)

- stat (__xstat) (man 2 stat)

- lstat (__lxstat) (man 2 lstat)

- fstat (__fxstat) (man 2 fstat)

- strtok (man 3 strtok)

- wait (man 2 wait)

- waitpid (man 2 waitpid)

- wait3 (man 2 wait3)

- wait4 (man 2 wait4)

- write (man 2 write)

## Testing

This shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

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
## Syntax

The shell works by using commands given by the user input. The shell commands take in the following syntax: command name {arguments}. The shell executes a command after it is written by user using the command followed by the arguments.

 It contains system calls, libraries and other important files.

The shell also contains two builtins which are commands that are within the shell itself. The two builtins are exit and env. You can also use help command to know which builtins are provided by the shell. The help command works similarly to the manual where it provides further detail or information on given builtin.

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
| _strings.c |  contains functions related to strings.|
| aux_functions.c| contains auxiliary functions.|
| _printf.c | custom printf function, sends formatted output to stdout.|
| _printf_aux.c|contains _putchar,  print_number_xd, print_number, print_char and print_string that prints characters, numbers and string respectively.
| hsh | exeutable file for the shell
| man_1_simple_shell| manual.

## Function used in this project: 

- _wich.c: used to identify the location of a given executable that is executed when you type the command in the terminal prompt.

- _getenv.c: searches for the environment string pointed to by name and returns the associated value to the string.

- _printf.c: custom printf function, sends formatted output to stdout.
repeat.c: counts how many times a character is repeated.

- _str_concat: appends one String to the end of another.

- _strdup: duplicates a string

- _strcmp : compares two strings character by character.

- _strcat: appends the string pointed to by src to the end of the string pointed to by dest.

- _strcpy: copies the string pointed by source (including the null character) to the destination.

- _printf: sends a formatted string to the standard output (the display).

- ** _putchar:** used to write a character, of unsigned char type, to stdout.

## Usage


- Enter custom shell by typing "./hsh". You should be prompted with a ($).

- Type a command of your liking and press "Enter".

- Appropriate output will appear.

- Prompt reappears and awaits your next command.

- Exit shell by typing "exit"


## Authors

Marcelo Rodríguez | [GitHub](https://github.com/Marcelorb1)

Romina Guimaraens | [GitHub](https://github.com/rominaguimaraens)
   

