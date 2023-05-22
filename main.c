#include "shell.h"


/**
*Main function contains loops for running commands
*/

int main(int argc,char* argv[])
{ 
    
    while (1)
      {
        //print line and read prompt
        printprompt_readline();  
      }  
    
    return (0);
}



void printprompt_readline()
{
    /*Initialization*/ 
    char *buffer = NULL;
    char *sstring;
    char* buffer_copy;
    ssize_t getline_bytes;
    size_t n = 0;
    int ntokens=0, i;
    char** string_arr;
    char* token;
    char buf[1064];
       
  
  
        if(getcwd(buf, sizeof(buf))!=NULL)
        {
          printf("%s\n$ ",buf);
        }
        else{
          perror("Error:cwd error");
        }
    /*Function for reading stdin from user*/
    
  
    getline_bytes = getline(&buffer,&n,stdin);
    if (getline_bytes<0)
    {
        perror("Error: getline failed\n");
        exit(EXIT_FAILURE);
    }
    
    buffer_copy = strdup(buffer);

    // tokenize string
    sstring = strtok(buffer," \n");

    if (sstring)
    {
        //Keep adding up to keep track of the number of bytes needed//
        ntokens++;
        sstring = strtok(NULL," \n");
    }
    ntokens++;

    string_arr = malloc(sizeof(char*)*ntokens);
    
    token = strtok(buffer_copy," \n");
    for(i=0;token!=NULL;i++)
    {
        string_arr[i] = strdup(token);
        token = strtok(NULL," \n");
    }
    string_arr[i]=NULL;
  
    executable(string_arr);

    free(buffer_copy);
    free(buffer);
    
}


