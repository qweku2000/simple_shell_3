#include "shell.h"


/**
*Main function contains loops for running commands
*/

int main(int argc, char* argv[])
{
   
    char *line;
    char **subs;
    
    while (1)
      {
        line = printprompt_readline();
        subs = splitline(line);
        
        // Do something with the command
      
                
        free(line);
        free(subs);
    }  
    return (0);
}



char* printprompt_readline()
{
    /*Initialization*/ 
    char *buffer;
    ssize_t getline_bytes;
    size_t zero = 0;

    /*Function for reading stdin from user*/
    printf("$ ");
  
    getline_bytes = getline(&buffer,&zero,stdin);
    if (getline_bytes<0)
    {
        printf("Error: Could not read line");
        exit(EXIT_FAILURE);
    }
    else if (getline_bytes>0)
    {
        while(buffer[getline_bytes-1] == '\n')
          {
               /*Replace newline with null terminator*/
                 buffer[getline_bytes-1] = '\0';
          }
    
    }
   
   return (buffer);
}



char** splitline(char *buffer)
{
    char **splitted_buffer;
    char *token;
    int i=0;
    const char *delim = " "; // Define delimiters for strtok()

    splitted_buffer = malloc(sizeof(char*) * strlen(buffer) + 1);
    if (!splitted_buffer)
    {
        printf("Error: Malloc failed");
        exit(EXIT_FAILURE);
    }

    token = strtok(buffer, delim);
    while (token != NULL)
    {
        splitted_buffer[i++] = token;
        token = strtok(NULL, delim);
    }
  
    splitted_buffer[i] = NULL; // Terminate the array with NULL pointer
  
    return (splitted_buffer); 
}













