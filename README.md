# holbertonschool-shell_v2
Simple shell v2


### Restrictions
List of allowed functions and system calls

- access
- chdir
- close
- execve
- fork
- stat (__xstat)
- lstat (__lxstat)
- fstat (__fxstat)
- kill
- open
- read
- signal
- wait
- waitpid
- wait3
- wait4
- write
- _exit
- dup
- dup2
- pipe
- unlink
- time
- gethostname
- geteuid
- sigaction
- sigemptyset
- select
- getpid
- __errno_location (errno macros)
- closedir
- exit
- free
- getcwd
- getline
- malloc
- opendir
- perror
- readdir
- strtok
- localtime
- getpwuid
- isatty
- printf
- fflush
- fprintf
- vfprintf
- sprintf

### Compilation
```
make
```
compilation option
```
-Wall -Werror -Wextra -pedantic -std=gnu89
```

## Testing
#### This shell should work like this in interactive mode:
(example)
```
$ ./hsh
$ /bin/ls
hsh main.c shell.c
$
$ exit
$
```

#### But also in non-interactive mode:
(example)
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

## Project made by:

- Jordan MPOUNZA - https://github.com/ozswar94

## Social Networks
- [Linkedin] (https://www.linkedin.com/in/jordan-mpounza/)