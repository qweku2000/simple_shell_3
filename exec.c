#include "shell.h"
void executable(char *argv[])
{
    char *cmd = NULL;
    char *cmd_act = NULL;

    if (argv) 
    {
        // Command is assigned to the first string in argv
        cmd = argv[0];

        if(strcmp(cmd,"exit")==0)
        {
            exit_shell();
        }
       else if (strcmp(cmd,"cd")==0)
       {
            //chdir function used to change dir
            dir_change(argv[1]);
            printprompt_readline();
       }
      else
       {   
        //make sure that the new command is now a full path of the commmand
        cmd_act = environment(cmd);
        
        if (cmd_act != NULL) 
        {
            if (execve(cmd_act, argv, NULL) < 0) 
            {
                perror("Error: execve failed");
            }
        } else 
            {
                printf("Command not found: %s\n", cmd);
            }
    }
  }
  
}
