/* Îïðåäåëèòü ñòðóêòóðèðîâàííûé òèï è íàáîð ôóíêöèé äëÿ ðàáîòû ñ òàáëèöåé çàïèñåé, ðåàëèçîâàííîé â ìàññèâå ñòðóêòóð.
Â ïåðå÷åíü ôóíêöèé âõîäÿò: 1. Ââîä çàïèñè òàáëèöû ñ êëàâèàòóðû. 2. Çàãðóçêà è ñîõðàíåíèå òàáëèöû â òåêñòîâîì ôàéëå.
3. Ïðîñìîòð òàáëèöû. 4. Ñîðòèðîâêà òàáëèöû ïî çàäàííîìó ïîëþ 5. Óäàëåíèå çàïèñè. 6. Èçìåíåíèå çàïèñè. 

Ïåðå÷åíü ïîëåé ñòðóêòóðèðîâàííîé ïåðåìåííîé:
2. Íîìåð ñòðàíèöû, íîìåð ñòðîêè, òåêñò èçìåíåíèÿ ñòðîêè, äàòà èçìåíåíèÿ. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n=0; // Íîìåð êîìàíäû
int index=0; // Íîìåð çàïèñè
FILE *fl;
char name_fl[]="table.txt"; //Èìÿ ôàéëà äëÿ çàïèñè
struct data 
      {
      	int day;
      	int month;
      	int year;
      };
struct editor 
      {
      	int page;
      	int line;
      	char text[100];
      	struct data tada;
      };
//.........................................................Ôóíêöèÿ ââîäà
void add(editor *mas, int index)
    {
      printf("\n The number of page: ");
      scanf("%d", &mas[index].page); 
        printf("The number of string: ");
        scanf("%d", &mas[index].line);
      printf("Change text: ");
      scanf("%s",&mas[index].text);
        printf("Date of change (00-00-0000): ");
        scanf("%d%d%d", &mas[index].tada.day, &mas[index].tada.month, &mas[index].tada.year);
        printf("\n");
        /*scanf("%d", &mas[index].tada.day);
        scanf("%d", &mas[index].tada.month);
        scanf("%d", &mas[index].tada.year);*/
     //printf("\n Ready!\n ");
	}
//.........................................................Ôóíêöèÿ çàïèñè â ôàéë
void file(editor *mas, int index)
    {
		if ((fl = fopen(name_fl, "w")) == NULL)
		 {
			printf("\nFile was not open!\n");
			return;
	     }
		for(int i=0;i<index;i++)
		  {
			fprintf(fl, "| %d || %d || %s || %d-%d-%d |\n",mas[i].page,mas[i].line,mas[i].text,mas[i].tada.day,mas[i].tada.month,mas[i].tada.year);
		  }
		printf("Successfull!\n");
		fclose(fl);	
    }
//.........................................................Ôóíêöèÿ âûâîäà òàáëèöû
void view(editor *mas, int i)
    {	
           printf("| %d |",mas[i].page); 
		   printf("| %d |",mas[i].line);
		   printf("| %s |",mas[i].text);
		   printf("| %d-",mas[i].tada.day);
           printf("%d-",mas[i].tada.month);
           printf("%d |\n",mas[i].tada.year);
    }
//.........................................................Ôóíêöèÿ ñîðòèðîâêè òàáëèöû ïî ñòðàíèöàì
void sort(editor *mas, int index)
    {
		for (int i = 0; i < index-1; i++)
		  {
		    for (int j = (index-1); j > i; j--) // äëÿ âñåõ ýëåìåíòîâ ïîñëå i-îãî
		    {
		      if (mas[j - 1].page > mas[j].page) // åñëè òåêóùèé ýëåìåíò ìåíüøå ïðåäûäóùåãî
		      {
		        editor temp = mas[j - 1]; // ìåíÿåì èõ ìåñòàìè
		        mas[j - 1] = mas[j];
		        mas[j] = temp;
		      }
		    }
		  }
		  view(mas, index);
    }
//.........................................................Ôóíêöèÿ óäàëåíèÿ çàïèñè
void delete_str(editor *mas, int numb2,int index)
    {
		editor temp = mas[numb2];
		for(int i=numb2+1;i<index;i++)
		{
		  mas[i-1]=mas[i];
		}
		mas[index-1] = temp;
    }
//.........................................................Ôóíêöèÿ ðåäàêòèðîâàíèÿ çàïèñè
void update(editor *mas, int numb1)
    {
        view(mas,numb1);
    	int page, line, day, month, year;
    	char text[100];
    	printf("\n The number of page: ");
    	scanf("%d",&page);
		if(page!=0)
		  {
		  	mas[numb1].page=page;
		  }
		printf("\n The number of string: ");
		scanf("%d",&line);
		if(line!=0)
		  {
		  	mas[numb1].line=line;
		  }
	    printf("\n Change text: ");
		scanf("%s",&text);
		if(strcmp(text,"0")!=0)
		  {
		  	strcpy(mas[numb1].text,text);
		  	//mas[numb].text=text;
		  }
		printf("\n Day: ");
		scanf("%d",&day);
		if(day!=0)
		  {
		  	mas[numb1].tada.day=day;
		  }
		printf("\n Month: ");
		scanf("%d",&month);
		if(month!=0)
		  {
		  	mas[numb1].tada.month=month;
		  }
		printf("\n Year: ");
		scanf("%d",&year);
		if(year!=0)
		  {
		  	mas[numb1].tada.year=year;
		  }
		view(mas,numb1);
    }
int main()
{
	editor mas[100]; // Ìàññèâ ñòðóêòóð - êîëè÷åñòâî çàïèñåé â òàáëèöå
	bool exit=true; // Ïåðåìåííàÿ äëÿ âûõîäà èõ ïðîãðàììû
	while(exit)
	     {
	       printf(" 1. Enter new string \n 2. Saving to file \n 3. View table \n 4. Sorting a table \n 5. Delete string \n 6. Changing a string \n 7. Exit");
	       printf("\n Enter number of command: ");
	       scanf("%d",&n);
	       switch(n)
		      {
		      	case 1:    //...............................Ôóíêöèÿ ââîäà
		      		printf("\n 1. Enter new string \n");
		      		add(mas,index);
		      		index++;
		      		break;
		      	case 2: //...........................................Ôóíêöèÿ çàïèñè â ôàéë
		      		printf("\n 2. Saving to file\n");
					file(mas, index);
					break;
		        case 3:
		        	printf("\n 3. View table\n"); //..................Ôóíêöèÿ âûâîäà òàáëèöû
		        	for (int i=0; i<index; i++)
		        	{
		        		view(mas,i);
		        	}
		        	break;
		        case 4:
		        	printf("\n 4. Sorting a table \n"); //...................Ôóíêöèÿ ñîðòèðîâêè òàáëèöû ïî ñòðàíèöàì
		        	sort(mas,index);
		        	break;
		      	case 5:
		      		printf("\n 5. Delete string\n"); //......................Ôóíêöèÿ óäàëåíèÿ çàïèñè
		      		printf("Enter the number of string for delete: ");
		      		int numb1;
		      		scanf("%d",&numb1);
		      		delete_str(mas,numb1,index);
		      		index--;
		      		break;
		      	case 6:
		      		printf("\n 6. Changing a string \n"); //...................Ôóíêöèÿ ðåäàêòèðîâàíèÿ çàïèñè
		      		printf("Enter the number of string for changing: ");
		      		int numb2;
		      		scanf("%d",&numb2);
		      		update(mas,numb2);
		      		break;
		      	case 7:
		      	     exit=false;
		      	     break;
		      }
	     }

	return 0;
}
