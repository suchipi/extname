/*
  extname - a filename extension finder
  the long-lost sister of dirname and basename

  made by Lily Skye in December 2022
  
  I release this work into the public domain
*/

#include <stdio.h>
#include <string.h>
#include <libgen.h>

int main(int argc, char *argv[])
{
  int eaten = 1;
  int full_mode = 0;
  char *str;

  if (argc < 2) goto usage;

  str = argv[1];
  if (str == NULL) goto usage;
  eaten++;

  if (!strcmp(str, "-f") || !strcmp(str, "--full")) {
    full_mode = 1;
    if (argc < 3) goto usage;
    str = argv[2];
    if (str == NULL) goto usage;
    eaten++;
  }

  if (
    !strcmp(str, "-h") ||
    !strcmp(str, "--help")
  ) {
    goto usage;
  }

  if (argc > eaten) {
    int unused = argc - eaten;
    fprintf(stderr, "warning: %d unused input", unused);
    if (unused != 1) {
      fprintf(stderr, "s");
    }
    fprintf(stderr, "\n");
  }

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

  printf("%s\n", str);
  return 0;

usage:
  printf("usage: extname [options] <string>\noptions:\n  -f/--full: show full extension (more than one dot)\n");
  return 1;
}
