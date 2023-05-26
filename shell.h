#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>


#define BUFFER_SIZE 4096
void hashtags(char *input);
void replace_hashtags(char *str);
ssize_t _getline_1(char** lineptr, size_t* n, FILE* stream);
void printprompt_readline();
void executable(char *argv[]);
char* environment(char* env);
int exit_shell();
int dir_change(char* argv);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void environment_variables();
char *_getline();
ssize_t _get_line(char **lineptr, size_t *n, FILE *stream);


extern char **environ;


#endif
