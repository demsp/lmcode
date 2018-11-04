// gcc  test.c -o test.exe

#include <stdio.h>
#include <time.h>
void delay(int ms) // аргумент- требуемое время задержки в миллисекундах
{
  int c = clock() + ms;
  while (clock() < c);
}

int main(void) {
int i=0;        // индекс текущей команды
int j=0;        // индекс массива данных
int acc = 0;
int count_reg = 0;
int pzflag = 1; // Флаг acc>=0
int zflag =1;   // Флаг acc==0
int pz_prev=0;  // прыжок назад по условию acc>=0
int z_prev=0;   // прыжок назад по условию acc==0
int prev=0;     // безусловный прыжок назад 
 
char command_mem[100] ="^>>[^<+>~]"; // data_mem[0]*data_mem[1]
//char command_mem[100] ="^[>~-<~>^]"; //перенос 5 в соседнюю ячейку
	
int data_mem[10]={0}; 
data_mem[0]=5;  //инициализируем начальные значения    
data_mem[1]=5; //1;
//data_mem[2]=5;
 
while ( command_mem[i] != '\0') {
if(command_mem[i]==',')  // считываем число в аккумулятор
    scanf("%d", &acc);	
if(command_mem[i]=='+')  // прибавляем число из data_mem
    acc=acc+data_mem[j];     // к аккумулятору
if(command_mem[i]=='-')  // вычитаем число data_mem 
    acc=acc-data_mem[j];     // из аккумулятора
if(command_mem[i]=='>')  // переход на следующий элемент данных  
    j++;
if(command_mem[i]=='<')  // переход на предыдущий элемент данных  
    j--;
if(command_mem[i]=='~')  // загружаем число из аккумулятора 
    data_mem[j]=acc;         // в память данных
if(command_mem[i]=='^')  // загружаем число из data_mem  
    acc=data_mem[j];         // в аккумулятор
if(command_mem[i]=='.') {   // выводим число из аккумулятора на экран 
    printf("Output: %d",acc); 
	printf(" ");
    };
if(command_mem[i]==':') {   // выводим число из аккумулятора на экран 
    printf("Output: %c",acc); 
    printf(" ");
    };
	
if (command_mem[i]=='}') // прыгаем назад?
    pz_prev=1;
if (command_mem[i]==')') // прыгаем назад?
    z_prev=1;   
if (command_mem[i]=='!') // прыгаем назад?
    prev=1; 
if (command_mem[i]=='[') // цикл
    count_reg=acc-1; 
// цикл
if (command_mem[i]==']' && count_reg!=0) {
    while(command_mem[i] != '[') 
        i--;
	    count_reg--;
    } 	
// безусловный переход вперёд
if (command_mem[i]=='?' && prev==0) {
    while(command_mem[i] != '!') 
        i++;  
    } 
// безусловный переход назад
if (command_mem[i]=='?' && prev==1) {
    while(command_mem[i] != '!') 
        i--; 	 
    } 
// переход вперёд по условию acc=0 
if (command_mem[i]=='(' && zflag==1 && z_prev==0) {
    while(command_mem[i] != ')') 
        i++;  
    } 
// переход назад по условию acc=0
if (command_mem[i]=='(' && zflag==1 && z_prev==1) {
    while(command_mem[i] != ')') 
        i--; 	 
    } 
// переход вперёд по условию acc>=0 
if (command_mem[i]=='{' && pzflag==1 && pz_prev==0) {
    while(command_mem[i] != '}') 
        i++;  
    } 
// переход назад по условию acc>=0 
if (command_mem[i]=='{' && pzflag==1 && pz_prev==1) {
while(command_mem[i] != '}') 
i--; 	 
}
// флаги		  
if(acc>=0){
    pzflag=1;}
else {
    pzflag=0;}	
if(acc==0){
    zflag=1;}
else {
    zflag=0;}		  
for (int k = 0; k<10; k++)
   printf("%d ", data_mem[k]);
printf("\r\r\r\r\r\r\r\r\r\r");
delay(1000);
	
//printf("i=%d",i);printf(" ");
i++;   //увеличиваем индекс текущей команды
}
//переход на новую строку
printf("\n");
// выводим массив данных
//for (int k = 0; k<10; k++)
//   printf("%d ", data_mem[k]);
return 0;
}
