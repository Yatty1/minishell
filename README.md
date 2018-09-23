# minishell

## Getting started
### Compiling
```
$ make
```

### Run
```
$ ./minishell
```

## Description

- Implementation of minimum function shell
- Wait until command is typed, and validated by pressing enter
- No pipes, no redirections, or any other advanced functions
- The executables are those you can find in the PATH variable
- In case where the executables cannot be found, it has to show an error message and display the prompt
- error should be handled without using `errno`
- PATH and environment must be handled correctly (copy of system char \*\*cnvironment)
- A series of buildins: echo, cd, setenv, unsetenv, exit must be implemented
- expantions: $ and ~ must be handled
