#include "shell.h"
void executable(char *argv[]) {
    char *cmd = NULL;
    char *cmd_act = NULL;

    if (argv) {
        // Command is assigned to the first string in argv
        cmd = argv[0];
        cmd_act = environment(cmd);

        if (cmd_act != NULL) {
            if (execve(cmd_act, argv, NULL) < 0) {
                perror("Error: execve failed");
            }
        } else {
            printf("Command not found: %s\n", cmd);
        }
    }
}
