/* В строке найти последовательности цифр, каждую из них считать числом той системы счисления, 
которая соответствует первой цифре, заменить числа в строке символами с кодами, полученными из этих чисел. 
Пример: aaa2010101bbb8343ccc */

/* Примечание: Программа предназначена для перевода числа из цепочки цифр в указанной системе счисления в десятичное целое число. 
При этом в начале цепочки цифра, указывающая систему счисления не может быть "0". Однако в строке могут присутствовать одиночные числа, например: 1r1u4 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <malloc.h>
#include <math.h>

int main ()
{
	int len; //Количество символов в строке
	int count=0; //Для подсчета количества цифр в строке
	int j=0, n=0, st=0, pr=0, s=0;
	int b=0; //Для разделения числа по цифрам
	//.....................................Ввод длины строки
	printf("Enter length of string: ");
	scanf("%d",&len);
	//.....................................Динамический массив/строка
	char *str=(char*)malloc(len+1);
	if (str==NULL)exit(1);
	//......................................Массив для перезаписи строки с преобразованными цифрами
	char *fin=(char*)malloc(len+1);
	if (fin==NULL)exit(1);
	//.....................................Заполнение массива
	printf("\nEnter string: ");
	scanf("%s",str);
	//.....................................Поиск числовой цепочки
	for (int i=0; i<len; i++)
	     {
	     	 if ((('a'<=str[i])&&(str[i]<='z'))||((i==len)&&(('a'<=str[i])&&(str[i]<='z'))))
	     	  {
	     	  	fin[s]=str[i];
	     	  	s++;
	     	  }
	     	//.................................Поиск цифр
	     	if (('0'<=str[i])&&(str[i]<='9'))
	     	    {
	     	    	//...........................................Поиск первого числа цепочки
	     	    	if ((i==0)&&(('0'<=str[i+1])&&(str[i+1]<='9')))
	     	    	   {
	     	    	   	 fin[i]=str[i];
	     	    	   	 s++;
	     	    	   	 n=str[i]&0x0F;// Не забыть присвоить этот символ конечному массиву
	     	    	   	 j=i+1;
//................................................Начало................................................................
                         count=0;
                         pr=0;
                         //.......................................Подсчет количества цифр в цепочке
	     	    	   	 while (('0'<=str[j])&&(str[j]<='9'))
	     	    	   	      {
	     	    	   	      	j++; //После обработки цепочки, счетчик основного цикла перейдет на конец цепочки цифр

	     	    	   	      	count++; //Подсчет количества цифр в строке
	     	    	   	      }
	     	    	   	 j=j-1;
	     	    	   	 i=j;  //После обработки цепочки, счетчик основного цикла перейдет на конец цепочки цифр
	     	    	   	 //......................................Создание массива для цепочки цифр
	     	    	   	 int *a=(int*)malloc(count*sizeof(int));
	     	    	   	 //.......................................Заполнения массива целыми числами
	     	    	   	 for (int k=0; k<count; k++)
	     	    	   	    {
	     	    	   	    	a[k]=str[j]&0x0F; //Перевод из строки в число
	     	    	   	    	j--;
	     	    	   	    	st=pow(n,k);
	     	    	   	    	pr=pr+a[k]*st; //Полученное десятичное число
	     	    	   	    }
	     	    	   	//............................Подсчет количества цифр в десятичном числе
	     	    	   	count=pr;
	     	    	   	b=0;
	     	    	   	while (count!=0)
	     	    	   	    {
	     	    	   	    	count/=10;
	     	    	   	    	b++;
	     	    	   	    }
                        //..........................Запись десятичного числа в конечный массив
	     	    	   	if (b>1)
	     	    	   	 {
	     	    	   	   s=s+b-1;
	     	    	   	   count=s+1;
	     	    	   	   for (b;b>0;b--)
	     	    	   		  {
	     	    	   		  	fin[s]=(pr%10)|0x30; // Перевод из числа в строку
	     	    	   		  	pr/=10;
	     	    	   		  	s--;
	     	    	   		  }
	     	    	   	   s=count;
	     	    	   	 }
	     	    	   	else
	     	    	   	   {
	     	    	   	   	 fin[s]=pr|0x30; // Перевод из числа в строку
	     	    	   	   	 s++;
	     	    	   	   }
//................................................Конец.............................................................
	     	    	   }
	     	    	else 
					 {
					 	if ((i==0)&&(('a'<=str[i+1])&&(str[i+1]<='z')))
                          {
                          	fin[i]=str[i];
	     	    	     	s++;
                          }
                        else
                           {
                            if (i!=len)
					 	     {
					 	     	if ((('a'<=str[i-1])&&(str[i-1]<='z'))&&(('0'<=str[i+1])&&(str[i+1]<='9')))
					 	         {
					 		       fin[s]=str[i];
	     	    	   	           s++;
					 	           n=str[i]&0x0F;
					 	           j=i+1;
//.......................................................Начало.......................................................
                                   count=0;
                                   pr=0;
                                  //.......................................Подсчет количества цифр в цепочке
	     	    	   	          while (('0'<=str[j])&&(str[j]<='9'))
	     	    	   	              {
	     	    	   	             	j++; //После обработки цепочки, счетчик основного цикла перейдет на конец цепочки цифр
	     	    	   	             	//printf("\nj= %d\n",j);
	     	    	   	      	        count++; //Подсчет количества цифр в строке
	     	    	   	              }
	     	    	              j=j-1;
	     	    	   	          i=j;  //После обработки цепочки, счетчик основного цикла перейдет на конец цепочки цифр
	     	    	   	          //......................................Создание массива для цепочки цифр
	     	    	   	          int *a=(int*)malloc(count*sizeof(int));
	     	    	   	          //.......................................Заполнения массива целыми числами
	     	    	   	          for (int k=0; k<count; k++)
	     	    	   	            {
	     	    	   	    	     a[k]=str[j]&0x0F; //Перевод из строки в число
	     	    	   	    	     j--;
	     	    	   	    	     st=pow(n,k);
	     	    	   	    	     pr=pr+a[k]*st; //Полученное десятичное число
	     	    	   	            }
                                  //............................Подсчет количества цифр в десятичном числе
	     	    	   	          count=pr;
	     	    	   	          b=0;
	     	    	              while (count!=0)
	     	    	   	              {
	     	    	   	    	       count/=10;
	     	    	   	    	       b++;
	     	    	   	              }
                                  //..........................Запись десятичного числа в конечный массив
	     	    	   	          if (b>1)
	     	    	   	           {
	     	    	   	             s=s+b-1;
	     	    	   	             count=s+1;
	     	    	   	             for (b;b>0;b--)
	     	    	   		           {
	     	    	   		  	         fin[s]=(pr%10)|0x30; // Перевод из числа в строку
	     	    	   		  	         pr/=10;
	     	    	   		  	         s--;
	     	    	   		           }
	     	    	   	            s=count;
	     	    	   	           }
	     	    	   	          else
	     	    	   	             {
	     	    	   	   	          fin[s]=pr|0x30; // Перевод из числа в строку
	     	    	   	   	          s++;
	     	    	   	             }
//....................................................Конец.........................................................
					 	         }
					 	         else //Если цифра одна в цепочке
					 	             {
					 	               fin[s]=str[i];
	     	    	     	                               s++;
					 	             }
					 	      }	
                           }	 	
					 }
                 }
        }
    //....................................Конечная строка
    printf("\nFinal line: ");
    for (int i=0; i<s; i++)
       {
         printf("%c",fin[i]);
       }
	return 0;
}
