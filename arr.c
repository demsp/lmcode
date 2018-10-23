#include <stdio.h>
int main(void) {
  int i=0;
  char str_arr[100] = "ABCDF";

  int data_arr[10]={0}; 
  data_arr[0]=2;
  data_arr[1]=5;


while ( str_arr[i] != '\0') { 
    printf( "%c", str_arr[i] );
    i++;          
  }
  printf("\n");
  for (int k = 0; k<10; k++)
    printf("%d ", data_arr[k]);
  
  
  return 0;
}
