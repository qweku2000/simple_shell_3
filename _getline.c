#include "shell.h"



/**
 * _getchar - Reads a single character from stdin.
 *
 * Return: The character read from stdin.
 */
int _getchar(void)
{
	char c;
	ssize_t bytes_read = read(STDIN_FILENO, &c, 1);

	if (bytes_read == -1)
	{
		perror("failed\n");
	}
	else if (bytes_read == 0)
	{
		return 0;
	}

	return c;
}

/**
 * _getline - Reads a line from a stream.
 * @lineptr: Pointer to the buffer that will store the line.
 * @n: Pointer to the size of the buffer.
 * @stream: Stream to read the line from.
 *
 * Return: The number of characters read (excluding the null terminator),
 *         or -1 if an error occurred.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return -1;
	}

	ssize_t bytes_allocated = *n;
	size_t position = 0;
	int current_char;

	/* Allocate memory for the initial line buffer */
	if (*lineptr == NULL)
	{
		*lineptr = (char *)malloc(bytes_allocated);
		if (*lineptr == NULL)
		{
			perror("malloc failed");
			return -1;
		}
	}

	while (1)
	{
		if (position == bytes_allocated - 1)
		{
			bytes_allocated *= 2;
			char *new_line_buffer = (char *)realloc(*lineptr, bytes_allocated);

			if (new_line_buffer == NULL)
			{
				perror("realloc failed");
				free(*lineptr);
				return -1;
			}

			*lineptr = new_line_buffer;
		}

		current_char = _getchar();

		if (current_char == EOF || current_char == '\n')
		{
			(*lineptr)[position] = '\0';
			break;
		}

		(*lineptr)[position] = current_char;
		position++;
	}

	*n = bytes_allocated;

	return (ssize_t)position;
}
