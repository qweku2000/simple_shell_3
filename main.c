#include "shell.h"

/**
 * main - Main function contains loop for running commands
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments passed to the program
 *
 * Return: 0 on success
 */
int main(void)
{
    while (1)
      {
	/* Print line and read prompt */
	printprompt_readline();
      }

    return (0);
}

/**
 * printprompt_readline - Function to print prompt and read input from user
 */
void printprompt_readline()
{
    /* Initialization */
    char *buffer = NULL;
    char *sstring;
    char *buffer_copy;
    ssize_t getline_bytes;
    size_t n = 0;
    int ntokens = 0, i;
    char **string_arr;
    char *token;
    char buf[1064];
    int is_interactive = isatty(fileno(stdin));
    if (is_interactive)
      {
	if (getcwd(buf, sizeof(buf)) != NULL)
	  {
	    printf("%s\n$ ", buf);
	  }
	else
	  {
	    perror("Error: cwd error");
	  }
      }
	/* Function for reading input from user */
	getline_bytes = getline(&buffer, &n, stdin);
	if (getline_bytes == -1)
    {
      exit(0);
    }

    buffer_copy = strdup(buffer);

    /* Tokenize string */
    sstring = strtok(buffer, " \n");

    if (sstring)
    {
      /* Keep adding up to keep track of the number of tokens needed */
      ntokens++;
      sstring = strtok(NULL, " \n");
    }
    ntokens++;

    string_arr = malloc(sizeof(char *) * ntokens + 1);

    token = strtok(buffer_copy, " \n");
    for (i = 0; token != NULL; i++)
    {
      string_arr[i] = strdup(token);
      token = strtok(NULL, " \n");
    }
    string_arr[i] = NULL;

    executable(string_arr);

    free(buffer_copy);
    free(buffer);
}
