#include "shell.h"

/**
*Main function contains loops for running commands
*/

int main(int argc, char* argv[])
{
    char *line;
    char **subs;
    int i = 0;
    
    line = printprompt_readline();
    subs = splitline(line);
   
    
    return (0);

  free(line);
  free(subs);
}



char* printprompt_readline()
{
    /*Initialization*/ 
    char *buffer;
    ssize_t getline_bytes;
    size_t zero = 0;

    /*Print prompt*/ 
    printf("$ ");
  
    buffer = malloc(sizeof(char)*getline_bytes);
    if(!buffer)
    {
        printf("Error:Malloc fail");
    }
    
  
    /*Function for reading stdin from user*/
    getline_bytes = getline(&buffer,&zero,stdin);
    if (getline_bytes<0)
    {
        printf("Error: Could not read line");
    }
    else if (getline_bytes>0)
    {
        while(buffer[getline_bytes-1] == '\n')
          {
               /*Replace newline with null terminator*/
                 buffer[getline_bytes-1] = '\0';
          }
    
    }
   printprompt_readline();
   return (buffer);
}



char** splitline(char *buffer)
{
      char **splitted_buffer;
      int i=0;
      splitted_buffer = malloc(sizeof(char)*strlen(buffer)+1);
      if (!splitted_buffer)
      {
          printf("Error: Malloc failed");
          exit(EXIT_FAILURE);
      }
        

      if (splitted_buffer[i]!=NULL)
      {
          splitted_buffer[i] = strtok(buffer, " ");
          ++i;
          splitted_buffer[i] = strtok(NULL, " ");
      }
  
  return (splitted_buffer); 
}
















