#include <stdio.h>
int main(void) {
  int i=0;
  char str_arr[100] = "ABCDF";


while ( str_arr[i] != '\0') { 
    printf( "%c", str_arr[i] );
    i++;          
  }
  return 0;
}
