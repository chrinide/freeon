#include <stdio.h>

int
main (int argc, char **argv)
{
  int i;

  printf("[slave 2] called with");
  for (i = 1; i < argc; ++i)
  {
    printf(" %s", argv[i]);
  }
  printf("\n");

  return 0;
}