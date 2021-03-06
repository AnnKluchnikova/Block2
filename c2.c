/* Разработать две функции, одна из которых вводит с клавиатуры набор данных в произвольной последовательности
и размещает в памяти в заданном формате. Другая функция читает эти данные и выводит на экран. Программа запрашивает 
и размещает в памяти несколько наборов данных при помощи первой функции, а затем читает их и выводит на экран при помощи 
второй. Размещение данных производить в выделенном массиве байтов с контролем его переполнения.

Последовательность строк символов. Каждая строка предваояется целым - счетчиком символов. Ограничение последовательности - 
счетчик со значением 0. 

Ограничения: В строке не может быть значимого символа "0", так как он обозначает конец строки */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <malloc.h>
#include <iostream>
  //char input; // Переменная для временного хранения введенного символа
  int count = 0; // Счетчик введенных символов
  int c_str=0; //Количество вводимых строк
  char *str = NULL; // Массив, содержащий вводимуюстроку
  char *fin = NULL; // Массив для конечной строки
  int size=0; // Определение длины конечного массива
  int indx=0; // Индексы для конечного массива
//.........................................Функция ввода
void input(int c_str)
    {
      char input; // Переменная для временного хранения введенного символа
	  for (int i=0; i<c_str; i++)
	  {
	  	do 
		  {
	         printf ("Enter a char value (0 to end): "); // Введите цифру "0", чтобы закончить ввод текущий строки
	         scanf("%s",&input); // Нет объяснения, почему с этой функцией программа не работает!!!
	         str = (char*) realloc (str, count + sizeof(char)+2);
	         str[count]=input;
	         count++;
	      }
	    while (input!='0');
	    //.........................................................Работа с конечной строкой
	    size=size+count; // Определение длины финальной строки
	    fin = (char*) realloc (fin, size+10); // Выделение памяти под конечный массив
	    fin[indx]= count-1 | 0x30; // Указание длины строки перед присвоением этой строки
	    
	    //.............................................Заполнение конечного массива текущей строкой   
	    for (int n=0;n<count;n++)
		   {
			 indx++;
			 fin[indx]=str[n];
	       } 
	       
	    indx++;
	    count=0;
	    *str=NULL;
	    printf("\n");
	  }
    }
//...........................................Функция вывода
void output(char fin[], int indx)
    {
      printf("\nFinal line: ");
      for (int n=0;n<indx;n++)
	    {
		  printf ("%c",fin[n]);
        } 
    	
    }
//.........................................Основная программа
int main ()
{
  //...........................................................Введите количество строк  
  printf("Enter the number of strings: ");
  scanf("%d",&c_str);
  printf("\n");
  //.....................................Вызов функции ввода
  input(c_str);
	//.....................................Вызов функции вывода
  output(fin,indx);
  free (str);
  free (fin);
  return 0;
}
