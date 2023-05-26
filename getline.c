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
 * getline - Reads a line from a file stream
 * @lineptr: Pointer to the buffer where the line is stored
 * @n: Pointer to the size of the buffer
 * @stream: File stream to read from
 *
 * Return: Number of characters read (excluding null terminator),
 *         -1 on error or end of input
 */
ssize_t _get_line(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static ssize_t position = 0;
	static ssize_t bytesRead = 0;
	ssize_t lineSize = 0;

	if (lineptr == NULL || n == NULL)
		return -1;

	if (*lineptr == NULL || *n == 0)
	{
		*lineptr = malloc(BUFFER_SIZE);
		if (*lineptr == NULL)
			return -1;
		*n = BUFFER_SIZE;
	}

	while (1)
	{
		if (position >= bytesRead)
		{
			bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, stream);
			position = 0;

			if (bytesRead <= 0)
				break;
		}

		while (position < bytesRead)
		{
			if (buffer[position] == '\n')
			{
				buffer[position] = '\0';

				if ((size_t)(lineSize + position + 1) > *n)
				{
					char *newLinePtr = realloc(*lineptr, lineSize + position + 1);
					if (newLinePtr == NULL)
						return -1;
					*lineptr = newLinePtr;
					*n = lineSize + position + 1;
				}

				memcpy(*lineptr + lineSize, buffer, position + 1);
				lineSize += position + 1;

				memmove(buffer, buffer + position + 1, bytesRead - position - 1);
				bytesRead -= position + 1;
				position = 0;

				return lineSize - 1;
			}

			position++;
		}

		if ((size_t)(lineSize + bytesRead) > *n)
		{
			char *newLinePtr = realloc(*lineptr, lineSize + bytesRead);
			if (newLinePtr == NULL)
				return -1;
			*lineptr = newLinePtr;
			*n = lineSize + bytesRead;
		}

		memcpy(*lineptr + lineSize, buffer, bytesRead);
		lineSize += bytesRead;
		position = bytesRead;
	}

	if (lineSize == 0)
		return -1;

	(*lineptr)[lineSize] = '\0';

	return (lineSize);
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
