#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char *previous_dir = NULL;

/**
 * executable - Executes the given command
 * @argv: Array of arguments passed to the command
 */
void executable(char *argv[])
{
    char *cmd = NULL;
    char *cmd_act = NULL;

    if (argv)
    {
        /* Command is assigned to the first string in argv */
        cmd = argv[0];

        if (strcmp(cmd, "exit") == 0)
        {
            exit_shell();
        }
        else if (strcmp(cmd, "cd") == 0)
        {
            /* Change directory using chdir function */
            if (argv[1] == NULL)
            {
                /* Change to previous directory */
                if (previous_dir != NULL)
                {
                    if (chdir(previous_dir) != 0)
                    {
                        perror("Error: chdir failed");
                    }
                }
                else
                {
                    printf("Error: No previous directory available\n");
                }
            }
            else if (strcmp(argv[1], "-") == 0)
            {
                /* Change to previous directory and update previous_dir */
                if (previous_dir != NULL)
                {
                    char *current_dir = getcwd(NULL, 0);
                    if (current_dir != NULL)
                    {
                        if (chdir(previous_dir) != 0)
                        {
                            perror("Error: chdir failed");
                        }
                        else
                        {
                            free(previous_dir);
                            previous_dir = current_dir;
                        }
                    }
                    else
                    {
                        perror("Error: getcwd failed");
                    }
                }
                else
                {
                    printf("Error: No previous directory available\n");
                }
            }
            else
            {
                /* Change to the specified directory */
                if (chdir(argv[1]) != 0)
                {
                    perror("Error: chdir failed");
                }
                else
                {
                    /* Update previous_dir */
                    if (previous_dir != NULL)
                        free(previous_dir);
                    previous_dir = getcwd(NULL, 0);
                    if (previous_dir == NULL)
                        perror("Error: getcwd failed");
                }
            }
        }
        else if (strcmp(cmd, "env") == 0)
        {
            environment_variables();
        }
        else
        {
            /* Execute external command */

            /* Create a child process */
            pid_t pid = fork();

            if (pid < 0)
            {
                perror("Error: Fork failed");
            }
            else if (pid == 0)
            {
                /* Child process */

                /* Make sure that the new command is now a full path of the command */
                cmd_act = environment(cmd);

                if (cmd_act != NULL)
                {
                    if (execve(cmd_act, argv, NULL) < 0)
                    {
                        perror("Error: execve failed");
                    }
                }
                else
                {
                    printf("Command not found: %s\n", cmd);
                }

                /* Exit the child process */
                exit(EXIT_FAILURE);
            }
            else
            {
                /* Parent process */

                /* Wait for the child process to finish */
                int status;
                waitpid(pid, &status, 0);
            }
        }

        /* Print a new prompt */
        printprompt_readline();
    }
}
