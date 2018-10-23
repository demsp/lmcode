#include <stdio.h>
int main(void) {
  int i=0;
  int j=0;
  char str_arr[100] = "+>++>+";
  //char acc[100] = "ABCDF";

  int data_arr[10]={0}; 
  data_arr[0]=1;
  data_arr[1]=1;


while ( str_arr[i] != '\0') { 
    if(str_arr[i]=='+') {data_arr[j]+=1;};//{  printf("he"); };
    if(str_arr[i]=='>') {j++;};//{  printf("ho"); };
    i++;          
  }


  printf("\n");
  for (int k = 0; k<10; k++)
    printf("%d ", data_arr[k]);
  
  printf("\n");
  printf("j=%d",j);
  
  return 0;
}
