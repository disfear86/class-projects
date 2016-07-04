#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>


enum week{ sun=1, mon, tue, wed, thu, fri, sat};
enum years {Jan=1, Feb=4, Mar=4, Apr=0, May=2, Jun=5, Jul=0, Aug=3, Sep=6, Oct=1, Nov=4, Dec=6};

//set text color (to highlight selected day)
void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

//check year value
int input_year()
{
	int etos;
	while(1){
		printf("\nEnter Year (1900-2099) or press 0 to exit: ");
		scanf("%d",&etos);
		if(etos == 0)
			break;
		if(etos<1900 || etos>2099){
			printf("Wrong value.");
		}
		if(etos>=1900 && etos<2099){
			return etos;
		}	
}
}

//check month value
int input_month()
{
	int month;
	while(1){
		printf("\nEnter month(1-12): ");
		scanf("%d",&month);
		if(month<1 || month>12){
			printf("Wrong value.");
		}
		if(month >= 1 && month <= 12){
			return month;
		}
}
}

//check day value
int input_day(int numdays)
{
	int day;
	while(1){
		if (numdays == 28)
			printf("\nEnter Day(1-28): ");
		if (numdays == 29)
			printf("\nEnter Day(1-29): ");
		if (numdays == 30)
			printf("\nEnter Day(1-30): ");
		if (numdays == 31)
			printf("\nEnter Day(1-31): ");
			
		scanf("%d",&day);
		
		if(day > numdays || day <=0)
		{
			printf("Wrong value. Selected month doesn't have that many days.");
		}
		if(day > 0 && day <= numdays){
			return day;
		}
}
}

//how many days in month
int days_of_month(int year,int month)
{
	int num_days;
	
	if (month == 4 || month == 6 || month == 9 || month == 11)  
  		num_days = 30;  
	else if (month == 2)  
		{ 	
		bool leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		  
  		if (leap_year)  
    		num_days = 29;  
  		else  
    		num_days = 28;  
		}  
	else  
  	num_days = 31; 
  	
  	return num_days;
}

//find the first day of the month
int first_day(enum week day, int date)
{
	int i;
	for(i = date; i>=1; i--)
	{
		if (day == sun)
			day = sat;
		else
			day--;
	}
	return day+1;
}

//find month code
int month_code(int mon)
{
	int month;
	if(mon == 1 || mon == 10)
	month = 1;
	if(mon == 2 || mon == 3 || mon == 11)
		month = 4;
	if(mon == 7 || mon == 4)
		month = 0;
	if(mon == 5)
		month = 2;
	if(mon == 6)
		month = 5;
	if(mon == 8)
		month = 3;
	if(mon == 9 || mon == 12)
		month = 6;
	return month;
}

//find day number (Key Value Method)
int find_day(int year, int month, int day)
{
	int res,cent;
	
	if(year>=2000 && year<=2099)
		cent = 6;				//century code
	if(year>=1900 && year<=1999)
		cent = 0;
		
	res = ((year % 100) / 4) + day;
	res += month;
	if(month == Feb || month == Jan)
	{
		bool leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);		  
  		if (leap_year)  
    		res -= 1;
	  }  
    res += cent;
    res += (year % 100);
    res = res % 7;
    if(res == 0)
    	res = 7;
	return res;
}
//print month and year
void print_month_year(int year,int month)
{
	printf("\n");
	if(month==1)
		printf("JANUARY ");
	if(month==2)
		printf("FEBRUARY ");
	if(month==3)
		printf("MARCH ");
	if(month==4)
		printf("APRIL ");
	if(month==5)
		printf("MAY ");
	if(month==6)
		printf("JUNE ");
	if(month==7)
		printf("JULY ");
	if(month==8)
		printf("AUGUST ");
	if(month==9)
		printf("SEPTEMBER ");
	if(month==10)
		printf("OCTOBER ");
	if(month==11)
		printf("NOVEMBER ");
	if(month==12)
		printf("DECEMBER ");
		
	printf("%d",year);
}

//print calendar
void calendar(int year, int month,int day, int num_days, int date)
{
	int i;
	printf("\n S   M   T   W   T   F   S");
	
	//print spaces depending on first day of the month
	if(day==2)
		printf("\n%*s", 4, "");
	else if(day==3)
		printf("\n%*s", 8, "");
	else if(day==4)
		printf("\n%*s", 12, "");
	else if(day==5)
		printf("\n%*s", 16, "");
	else if(day==6)
		printf("\n%*s", 20, "");
	else if(day==7)
		printf("\n%*s", 24, "");
	else
		printf("\n");
			
	for (i=1; i<=num_days; i++)
	{		
		
		if(day % 7 == 0) //print and change line if day is saturday
		{
			printf("%2d  ",i);
			printf("\n");
		}
		else if(i == date)//change color on selected date
		{
			SetColor(20);
			printf("%2d  ",i);
			SetColor(0);
		}
		else
			printf("%2d  ",i);		
		
		
		day++;
	}
	printf("\n");
}

main()
{
	int i, day, month, year, NumOfDays, what_day, m_code, first;
	system("color 70");
	
	while(1)
	{
		year = input_year();
		if(years == 0)
			break;
		
		month = input_month();
		
		NumOfDays = days_of_month(year, month);
		
		day = input_day(NumOfDays);
		
		m_code = month_code(month);
		what_day = find_day(year, m_code, day);
		first = first_day(what_day, day);
		
		print_month_year(year, month);
		calendar(year, montn, first, NumOfDays, day);
		

	}
	
}
