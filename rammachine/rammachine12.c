// gcc  test.c -o test.exe

#include <stdio.h>
int main(void) {
int i=0;        // индекс текущей команды
int j=0;        // индекс массива данных
int acc = 0;
int pos_flag = 1; // Флаг acc>0
int zero_flag =1;   // Флаг acc==0
char metka_jmp;
char metka_pos;
char metka_zero;
int data_mem[20]={0}; 
//int dop_reg;

//char command_mem[100] = ",~+."; //вывод удвоенного числа
//char command_mem[100] = ",~>~b>~!a>~>~a>~_b>~"; //jmp
//char command_mem[100] = "^>-}a^!ba<^b."; // максимум
//char command_mem[100] = "a^.>-<~{a"; // вывод чётных чисел с10до2
//char command_mem[100] = "a>>>^<+>~<<< ^>-<~{a>>>^."; // перемножение чисел 1вар
//char command_mem[100] = "b>>>^<+>~<<<^>-<~)a_ba>>>^."; // перемножение чисел 2вар
//char command_mem[100] = "a>>^>+.~<+.~<<^>-<~{a"; // Фибоначчи
//пример 1.8
//char command_mem[100] = "a,)f =1%-)b-)c b>^=1%-~!d c>^=1%+~ d<_a f>^.";  
char command_mem[100] = "a,)f =1-)b-)c b>^=1-~!d c>^=1+~ d<_a f>^.";  

     
while ( command_mem[i] != '\0') {
	
if(command_mem[i]=='|')    
    break;
if(command_mem[i]=='='){    
    i++;
	data_mem[j]=command_mem[i]-48;
    }
	
if(command_mem[i]==',')  // считываем число в аккумулятор
    scanf("%d", &acc);	
if(command_mem[i]=='+')  // прибавляем число из data_mem
    acc=acc+data_mem[j];     // к аккумулятору
if(command_mem[i]=='-')  // вычитаем число data_mem 
    acc=acc-data_mem[j];     // из аккумулятора
if(command_mem[i]=='>'){  // переход на следующий элемент данных  
    j++;
	//printf("j=%d",j);printf(" ");
    }
if(command_mem[i]=='<'){  // переход на предыдущий элемент данных  
    j--;
	//printf("j=%d",j);printf(" ");
    }
if(command_mem[i]=='~')  // загружаем число из аккумулятора 
    data_mem[j]=acc;         // в память данных
if(command_mem[i]=='^')  // загружаем число из data_mem  
    acc=data_mem[j];         // в аккумулятор
if(command_mem[i]=='.') {   // выводим число из аккумулятора на экран 
    printf("Output: %d",acc); 
    printf(" ");
    };
 
// безусловный переход вперёд
if (command_mem[i]=='!' ) {
	i++;
	metka_jmp=command_mem[i];
	i++;
    while(command_mem[i] != metka_jmp) i++; 	 
    } 
// безусловный переход назад
if (command_mem[i]=='_' ) {
	i++;
	metka_jmp=command_mem[i];
	i--;
    while(command_mem[i] != metka_jmp) i--; 	 
    } 
	
// переход вперёд по условию acc=0 
if (command_mem[i]==')' && zero_flag==1) {
	i++;
	metka_zero=command_mem[i];
	i++;
    while(command_mem[i] !=metka_zero) i++;  
    } 
// переход назад по условию acc=0
if (command_mem[i]=='(' && zero_flag==1) {
	i++;
	metka_zero=command_mem[i];
	i--;
    while(command_mem[i] != metka_zero) i--; 	 
    } 
// переход вперёд по условию acc>0 
if (command_mem[i]=='}' && pos_flag==1 ) {
	i++;
	metka_pos=command_mem[i];
	i++;
    while(command_mem[i] != metka_pos) i++;  
    } 
// переход назад по условию acc>0 
if (command_mem[i]=='{' && pos_flag==1 ) {
	i++;
	metka_pos=command_mem[i];
	i--;
while(command_mem[i] != metka_pos) i--; 	 
}
// флаги		  
if(acc>0){
    pos_flag=1;}
else {
    pos_flag=0;}	
if(acc==0){
    zero_flag=1;}
else {
    zero_flag=0;}		  

i++;   //увеличиваем индекс текущей команды
//printf("i=%d",i);printf(" ");
printf("\n");
//  for (int k = 0; k<20; k++)
//  printf("%d ", data_mem[k]);
//  printf("\n");
}
//переход на новую строку
printf("\n");
// выводим массив данных
for (int k = 0; k<20; k++)
   printf("%d ", data_mem[k]);
return 0;
}
