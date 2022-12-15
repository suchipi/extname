/*
  extname - a filename extension finder
  the long-lost sister of dirname and basename

  made by Lily Skye in December 2022
  
  I release this work into the public domain
*/

#include "extname.h"

char *extname(char *input, int full_mode)
{
  char *str = input;

  str = basename(str);
  if (full_mode) {
    while (str[0] != '\0' && str[0] != '.') {
      str++;
    }
  } else {
    size_t len = strlen(str);
    int offset = len;
    for (int i = len - 1; i > 0; i--) {
      if (str[i] == '.') {
        offset = i;
        break;
      }
    }
    str += offset;
  }

  return str;
}
