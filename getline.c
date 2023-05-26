#include "shell.h"


/**
 *_getline - Reads user input
 *
 *Return - user input
*/


char *_getline()
{
  int i,rd;
  char c;
  char *buff = malloc(1024);

  if (!buff)
    {
      free (buff);
      return (NULL);
    }
  for (i = 0; c != EOF && c != '\n'; i++)
    {
      /*clear stdin*/
      fflush(stdin);
      rd = read(STDIN_FILENO,&c,1);
	if (rd == 0)
	  {
	   free(buff);
	   return ("\0");
	  }
      if (i >= 1024)
	{
	 buff = realloc(buff,1024);
	 if (buff == NULL)
	   {
	     return (NULL);
	   }
	}
    }
  buff[i] = '\0';
  hashtags(buff);
  return (buff);
}


/**
 * hashtags - handle comments
 * @buff: user input;
 * Return:void
 */
void hashtags(char *input)
{
  int i;
  
  for (i = 0; input[i] != '\0'; i++)
    {
      if (input[i] == '#')
	{
	  input[i] = '\0';
	  break;
	}
    }
}
