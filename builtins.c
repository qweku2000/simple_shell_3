#include "shell.h"
/*Built is added are cd and exit*/



/*Functions to add are dir_change and shell_exit*/

int exit_shell()
{
        exit(EXIT_SUCCESS);
    
  return 0;
}

int dir_change(char argv[])
{
  if(chdir(argv)<0)
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














