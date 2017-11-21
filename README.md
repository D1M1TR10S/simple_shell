# The Simple Shell
A basic reproduction of the shell (UNIX command line interpreter) that reads and executes commands from standard input.

## Installation
This program was written in **C** and compiled on `Ubuntu 14.04.3 LTS` with `gcc version 4.8.4`

**Clone repo**:
`$ git clone git@github.com:DimitriCat/simple_shell.git`

**Compile**
`$ gcc -Wall -Werror -Wextra -pedantic *.c -o shell`

**Instructions**:
#### Interactive Mode
`$ ./shell`

A prompt will follow upon executing `./shell` command. <br />
The shell is ready for user input: <br />
`$ `

#### NonInteractive Mode
Pipe a command into the `shell` as follows:
`$ echo "ls -la" | ./shell`

## Usage
The following built-in functions are available in our shell
* `env`
* `exit`
 
Functions found by traversing the environment variable `PATH` may also be executed.
Examples of these functions:
* `ls` with or without arguments
* `pwd`
* `touch`

## C Functions and Syscalls Utilized
```
access (man 2 access)
execve (man 2 execve)
exit (man 3 exit)
fork (man 2 fork)
free (man 3 free)
fstat (man 2 fstat)
getline (man 3 getline)
malloc (man 3 malloc)
perror (man 3 perror)
strtok (man 3 strtok)
wait (man 2 wait)
```

## File Descriptions
[shell.h](shell.h) - header file containing function prototypes, struct definitions, macros, standard libraries.

[simple_shell](simple_shell.c) - simple shell program that 1) checks if in interactice/noninteractice mode 2) prints prompt and waits for user input 3) splits user input into an array 4) prints prompt again if in interactice mode

[execution](execution.c) - executes the command passed as a string

[man_1_simple_shell](man_1_simple_shell) - man page for our shell

**PATH**
- [search_path](search_path.c) - looks for files in the current PATH. Returns file path on success, NULL on failure
- [link_path](link_path.c) - creates a linked list of directories in PATH. Returns pointer to first element of linked list.
- [free_linked_path](free_linked_path.c) - frees the linked path

**BUILTINS**
[search_builtins](search_builtins.c) - searchs for builtins from user input
- `_env` - prints environment variable
- `execute_exit` - exits function

**HELPER FUNCTIONS**
- [_getenv](_getenv.c) - get an environment variable. Returns pointer to the variable <br />
- `copy_env` - copies environment variable. Returns double pointer to copy of environment variable
- [free_dblptr](free_dblptr.c) - frees a double pointer
- [add_node_end](add_node_end.c) - adds a new node at the end of a list_t list. Returns pointer to added node, or NULL
- [clear_buff](clear_buff.c) - sets buffer to '\0'
- [_putchar](_putchar.c) - writes character to stdout
- [putstring](putstring.c) - prints a string
- [strfcns](strfcns.c) - helper string functions:<br />
  `_strcat` - concatenates two strings. Returns pointer to resulting string <br />
  `_strcmp` - compares two strings. Returns (-) if s1 < s2, (0) if s1 > s2, 0 if s1 = s2 <br />
  `_strcpy` - copies string from src to dest. Returns pointer to dest <br />
  `_strncmp` - compares two character strings up to n bytes. Return 0-success, -1-failure <br />
  `strlen_rec` - finds and returns length of a string <br />
- [tokenizer](tokenizer.c) - splits a character string into an array of tokens

## Authors
Jennifer Huang      <a href='https://github.com/jhuang10123'>Jennifer's Github</a>
Kristen Loyd        <a href='https://github.com/KRLoyd'>Kristen's Github</a>

## License
Public Domain, no copyright protection
