#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "day1.h"

int main(int argc, char * * argv)
{
  // argv[1] is the input file name
  // argv[2] is the output file name
  if (argc != 2)
    {
      return EXIT_FAILURE;
    }
  int ans; // not initialized
  bool rtv;
  rtv = readFileAndProcess(argv[1], & ans);
  if (rtv == false)
    {
      return 0;
    }
  return EXIT_SUCCESS;
}