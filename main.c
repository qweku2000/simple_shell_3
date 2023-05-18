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
        //split line into tokens

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
    size_t zero = 0;
    int ntokens=0, i;
    char** string_arr;
    char* token;

    /*Function for reading stdin from user*/
    printf("$ ");
  
    getline_bytes = getline(&buffer,&zero,stdin);
    if (getline_bytes<0)
    {
        perror("Error: Could not read line\n");
        exit(EXIT_FAILURE);
    }
    
    buffer_copy = malloc(getline_bytes);
    strcpy(buffer_copy,buffer);

    // tokenize string
    sstring = strtok(buffer," \n");

    if (sstring)
    {
        ntokens++;
        sstring = strtok(NULL," \n");
    }
    ntokens++;

    string_arr = malloc(sizeof(char*)*ntokens);
    
    token = strtok(buffer_copy," \n");
    for(i=0;token!=NULL;i++)
    {
        string_arr[i] = malloc(sizeof(char)*strlen(token)+1);
        strcpy(string_arr[i],token);
        token = strtok(NULL," \n");
    }
    string_arr[i]=NULL;
  
    executable(string_arr);

    free(buffer_copy);
    free(buffer);
}


