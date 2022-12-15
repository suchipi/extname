/*
  extname - a filename extension finder
  the long-lost sister of dirname and basename

  made by Lily Skye in December 2022

  I release this work into the public domain
*/

#include <string.h>
#include <libgen.h>

char *extname(char *input, int full_mode);
