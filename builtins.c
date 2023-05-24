#include "shell.h"

/**
 * exit_shell - Exits the shell program
 *
 * Return: Always returns 0
 */
int exit_shell(char *status)
{
    int code;
    if (status)
    {
      code = atoi(status);
    }
    exit(code);
    return 0;
}

/**
 * dir_change - Changes the current working directory
 * @argv: The directory to change to
 *
 * Return: 0 on success, -1 on failure
 */

int dir_change(char argv[])
{
    
    if (chdir(argv) < 0)
    {
        printf("cd failed\n");
        return (-1);
    }
    else
    {
        printprompt_readline();
        return (0);
    }
    
    return (0);
}



extern char **environ;

void environment_variables() 
{
    int i;
    char **env = environ;
    for (i=0;env[i] != NULL; i++) 
    {
        printf("%s\n", env[i]);
    }
}




