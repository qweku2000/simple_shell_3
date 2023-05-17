#include "shell.h"

void executable(char *argv[])
{
    char *cmd = NULL;

    if (argv)
    {
        cmd = argv[0];

         if (execve(cmd, argv, NULL)<0)
  {
      perror("Error");
  };
    }
 
}
