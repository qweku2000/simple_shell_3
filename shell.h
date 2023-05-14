
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>




void shell_loop(void);
char* printprompt_readline();
char **tokens();
char** splitline(char *buffer);
