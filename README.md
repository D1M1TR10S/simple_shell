# The Simple Shell
A basic reproduction of the shell (UNIX command line interpreter) that reads and executes commands from standard input.

## Installation
This program was written in **C** and compiled on `Ubuntu 14.04.3 LTS` with `gcc version 4.8.4`

**Clone repo**:
`$ git clone git@github.com:DimitriCat/simple_shell.git`

**Compile**
`$ gcc -Wall -Werror -Wextra -pedantic *.c -o shell`

**Instructions**:
#### Execute Commands Within Shell
`$ ./shell`

A prompt will follow upon executing `./shell` command. <br />
The shell is ready for user input: <br />
`$ `

#### Send Commands Into Shell
Pipe a command into the `shell`:
`$ echo "ls" | ./shell`

## Usage
Built-in functions:
* `env`
* `exit`

Functions from /bin folder:
* `ls`
* `pwd`

## C Functions and Syscalls Utilized
```
execve (man 2 execve)
exit (man 3 exit)
fork (man 2 fork)
free (man 3 free)
stat (man 2 fstat)
getline (man 3 getline)
malloc (man 3 malloc)
perror (man 3 perror)
strtok (man 3 strtok)
wait (man 2 wait)
```

## File Descriptions
**README.md** - Description of the Simple\_shell program.

**shell.h** -  Header file containing function prototypes, struct definitions, macros, standard libraries.

**builtins.c** - Builtin functions to be executed.

**getinput.c** - Reads input, turns it into a string, and then tokenizes the string into a double pointer array.

**helper.c** - Checks a struct for builtins.

**main.c** - Opens up the Simple\_shell.

**shellfunctions.c** - Container for various functions executed within shell.

**strfunctions.c** - Container for various string functions, such as: \_strcmp, str\_concat, \_strdup, etc.

**tokenizer.c** - Splits the standard input string into an array of tokens.

## Authors
[Dimitrios Philliou] (https://github.com/DimitriCat)

[Cameron Moore] (https://github.com/cameronlpmoore)

## License
Don't even think about it buddy.
