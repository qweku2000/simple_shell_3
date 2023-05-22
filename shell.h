

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>




void printprompt_readline();
void executable(char *argv[]);
char* environment(char* env);
int exit_shell();
int dir_change(char* argv);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
