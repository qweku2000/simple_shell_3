#include "shell.h"

/**
 * exit_shell - Exits the shell program
 *
 * Return: Always returns 0
 */
int exit_shell()
{
    exit(EXIT_SUCCESS);
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
        perror("cd failed\n");
        return (-1);
    }
    else
    {
        printprompt_readline();
        return (0);
    }
    
    return (0);
}

/**
 * environment_variables - Prints the environment variables
 */
void environment_variables()
{
    char **env = environ;
    // Iterate through the array of environment variables
    for (int i = 0; env[i] != NULL; i++)
    {
        printf("%s\n", env[i]);
    }
}
