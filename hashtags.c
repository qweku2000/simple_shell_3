#include "shell.h"

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
      if (input[0] == '#')
        {
          printprompt_readline();
        }
      else if (input[i] == '#')
        {
          input[i] = '\0';
          return;
        }
    }
}
