#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>

int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

void printArray(int * arr, int size)
{
  int ind;
  for (ind = 0; ind < size; ind ++)
    {
      fprintf(stdout, "%d\n", arr[ind]);
    }
}

int myAlgorithm(int * arr, int size, int sum){
  qsort (arr, size, sizeof(int), comp);
  int mul_sum = 0;

  for(int i = 0; i < size -2 ; ++i)
  {
    int idx_start = i + 1;
    int idx_end = size -1;
    int small_sum = sum - arr[i];
    while(idx_start < idx_end) {
      int sum_minus = small_sum - arr[idx_start];
      if ( sum_minus == arr[idx_end] )
      {
        mul_sum = arr[i] *  arr[idx_start] * arr[idx_end];
        break;
      }
      else if ( sum_minus > arr[idx_end])
      {
        idx_start++;
      }
      else if ( sum_minus < arr[idx_end] )
      {
        idx_end--;
      } 
    }
  }

  return mul_sum;
}

bool readFileAndProcess(char * filename, int * ans)
{
  // You cannot assume * sum is zero. Thus, * sum needs to be set 0
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  // if fopen succeeds, read integers using fscan (do not use fgetc)
  //
  // * sum stores the result of adding all numbers from the file
  // When no more numbers can be read, fclose, return true
  //
  FILE * fp;
  fp = fopen(filename, "r");
  if (fp == NULL) 
  {
    printf("The reading file is not existed or break.\n");
    return false;
  } 
  else 
  {
    // count the number of integers
    int value;
    int count = 0;
    while(fscanf(fp, "%d", & value) == 1) 
    {
      count ++;
    }
    fprintf(stdout , "The file had %d intergers \n", count);
    // allocate memory to store the numbers
    int * arr = malloc(sizeof(int) * count);
    if (arr == NULL) 
    {
      fprintf(stderr, "malloc fail\n");
      fclose(fp);
      return EXIT_FAILURE;
    }
    fseek(fp, 0, SEEK_SET);
    int ind = 0;
    while(ind < count) 
    {
      if (fscanf(fp, "%d", & arr[ind]) != 1) 
      {
        fprintf(stderr, "fscanf fail\n");
        fclose(fp);
        free(arr);
        return EXIT_FAILURE;
      }
      ind ++;
    }
    fclose(fp);
    *ans = myAlgorithm(arr, count, 2020);
    fprintf(stdout, "The answer is %d\n", *ans);
  }
  return true;
}
