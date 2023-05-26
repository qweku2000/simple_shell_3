#include "shell.h"

void replace_hashtags(char *str)
{
    char *hash_pos = strchr(str, '#');
    if (hash_pos != NULL)
      {
        *hash_pos = '\n';
      }
}
