#include "shell.h"


int _getchar() {
    char c;
    ssize_t bytes_read = read(STDIN_FILENO, &c, 1);

    if (bytes_read == -1) {
        perror("failed\n");
    } else if (bytes_read == 0) {
        return 0;
    }

    return c;
}



ssize_t _getline(char **lineptr, size_t *n, FILE *stream) {
  char *new_line_buffer;
  int current_char;
  size_t position = 0;
  static ssize_t bytes_allocated = 0;
  *n = (size_t)bytes_allocated;

  
    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1;
    }
    
    if (bytes_allocated == 0) {
      bytes_allocated = (ssize_t)(*n);
    }
    
    /*Allocate memory for the initial line buffer*/
    if (*lineptr == NULL) {
      *lineptr = (char *)malloc(bytes_allocated);
      if (*lineptr == NULL)
	{
	  perror("malloc failed");
	  return -1;
        }
    }
    
    while (1) {
      if (position == (size_t)bytes_allocated - 1) {
	bytes_allocated *= 2;
	new_line_buffer = (char *)realloc(*lineptr, bytes_allocated);
	
	if (new_line_buffer == NULL) {
	  perror("realloc failed");
	  free(*lineptr);
                return -1;
	}
	
	*lineptr = new_line_buffer;
      }
      
      current_char = fgetc(stream);

      if (current_char == EOF || current_char == '\n') {
	(*lineptr)[position] = '\0';
	break;
      }
      
      (*lineptr)[position] = (char)current_char;
      position++;
    }
    

    return (ssize_t)position;
}



