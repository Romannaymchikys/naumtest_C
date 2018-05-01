#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>

using namespace std;
char Lola_input(char[], bool&, int&);
bool Proverka(char[], bool&, int&);
int Chisla(char[], int&, int&, int&, int&);
int Proverka_na_visocos(int, int, int);
int Nachalo(int, int&);
int Nomer_nedeli(int, int, int, int, int&);
void Den_nedeli(int);
int main()
{
	setlocale(LC_ALL, "Russian");
	int day, month, year;
	int i = 0, nachalo = 0, numer_nedeli = 0;
	bool Vvod;
	char str[10];
	printf("\t\tКалендарь \n\n");
	Lola_input(str, Vvod, i);
	Chisla(str, day, month, year, i);
	Proverka_na_visocos(day, month, year);
	Nachalo(year, nachalo);
	Nomer_nedeli(day, month, year, nachalo, numer_nedeli);
	Den_nedeli(numer_nedeli);
	system("pause");
	return 0;
	}
char Lola_input(char str[],bool&Vvod, int& i)
{
	printf(" Введите: число.месяц.год(пример 12.04.1658): ");
	cin >> str;
	Proverka(str, Vvod, i);
	if (Vvod == true) { return str[10], i = 0;}
	else { i = 0; Lola_input(str, Vvod, i); }
}
bool Proverka(char str[], bool& Vvod, int& i)
{
	switch (i)
	{
	case(0): if (str[3] == '0' && str[4] == '2')
	        {
		    if (str[i] >= '0' && str[i] <= '2') { i++; return Proverka(str, Vvod, i); }
		    else { printf(" В феврале 28 или 29 дней!\n"); return Vvod = false;}
            }
			  else if (str[i] >= '0' && str[i] <= '3') { i++; return Proverka(str, Vvod, i); }
				 else {printf("Во всех месяцах кроме февраля, 30 или 31 день!\n");
				 return Vvod = false; } 
	case(1): if (str[0] == '3')
	{
		switch (str[3], str[4])
		{
		case('0', '1'): if (str[i] == '0' || str[i] == '1') { i++; return Proverka(str, Vvod, i); }
					else { printf("В январе 31 день !\n"); return Vvod = false; }
		case('0', '3'): if (str[i] == '0' || str[i] == '1') { i++; return Proverka(str, Vvod, i); }
					else { printf("В марте 31 день!\n"); return Vvod = false; }
		case('0', '4'): if (str[i] == '0') { i++; Proverka(str, Vvod, i); }
					else { printf("В апреле 30 дней!\n"); return Vvod = false; }
		case('0', '5'): if (str[i] == '0' || str[i] == '1') { i++; return Proverka(str, Vvod, i); }
					else { printf("В мае 31 день!\n"); return Vvod = false; }
		case('0', '6'): if (str[i] == '0') { i++; Proverka(str, Vvod, i); }
					else { printf("В июне 30 дней!\n"); return Vvod = false; }
		case('0', '7'): if (str[i] == '0' || str[i] == '1') { i++; return Proverka(str, Vvod, i); }
					else { printf("В июле 31 день!\n"); return Vvod = false; }
		case('0', '8'): if (str[i] == '0' || str[i] == '1') { i++; return Proverka(str, Vvod, i); }
					else { printf("В августе 31 день\n !"); return Vvod = false; }
		case('0', '9'): if (str[i] == '0') { i++; return Proverka(str, Vvod, i); }
					else { printf("В сентябре 30 дней!\n"); return Vvod = false; }
		case('1', '0'): if (str[i] == '0' || str[i] == '1') { i++; return Proverka(str, Vvod, i); }
					else { printf("В октябре 31 день!\n"); return Vvod = false; }	
		}
		switch (str[3], str[4])
		{
		case('1', '1'): if (str[i] == '0') { i++; return Proverka(str, Vvod, i); }
					else { printf("В ноябре 30 дней!\n"); return Vvod = false; }
		case('1', '2'): if (str[i] == '0' || str[i] == '1') { i++; return Proverka(str, Vvod, i); }
					else { printf("В декабре 31 день!\n"); return Vvod = false; }
		}
	}
			 else if (str[i] >= '0' && str[i] <= '9') { i++; return Proverka(str, Vvod, i); }
				 else { printf("Вторая цифра дня, введена не верно!!!\n"); return Vvod = false; }
	case(2): if (str[i] == '.') { i++; return Proverka(str, Vvod, i); }
			 else {printf("Первый знак разделение введен не верно!\n");
			 return Vvod = false; }
	case(3): if (str[i] >= '0' && str[i] <= '1') { i++; return Proverka(str, Vvod, i); }
			 else {printf("Месяцев в году 12!!!\n");
			 return Vvod = false; }
	case(4): if (str[i] >= '0' && str[i] <= '2' && str[3] =='1') { i++; return Proverka(str, Vvod, i); }
			 else  if (str[i] >= '1' && str[i] <= '9' && str[3] == '0') { i++; return Proverka(str, Vvod, i); }
	              else {printf("Вторая цифра месяца, введена не верно!\n");
		          return Vvod = false;}
	case(5): if (str[i] == '.') { i++; return Proverka(str, Vvod, i); }
			 else {printf("Второй знак разделение введен не верно!\n");
			 return Vvod = false;}
	case(6): if (str[i] >= '0' && str[i] <= '9') { i++; return Proverka(str, Vvod, i); }
			 else {printf("Первая цифра года ведена не верно!\n");
			 return Vvod = false;}
	case(7): if ((str[i] >= '0' && str[i] <= '9' )|| (str[i] == ' ')) { i++; return Proverka(str, Vvod, i); }
			 else { printf("Вторая цифра года ведена не верно!\n");
			 return Vvod = false; }
	case(8): if ((str[i] >= '0' && str[i] <= '9') || (str[i] == ' ' && str[i - 1] == ' ')) 
	            { i++; return Proverka(str, Vvod, i); }
			 else { printf("Третья цифра года ведена не верно!\n");
			 return Vvod = false; }
	case(9): if ((str[i] >= '0' && str[i] <= '9') || (str[i] == ' ' && str[i - 1] == ' '))
	{
		 return Vvod = true;
	}
             else {printf("Четвертая цифра года ведена не верно!\n");
			 return Vvod = false; }
	}
}
int Chisla(char str[], int& day, int& month, int& year, int& i)
{
			switch (i)
			{
			case(0): day = int(str[i] - '0') * 10; i++; return Chisla(str, day, month, year, i);
			case(1): day += int(str[i] - '0'); i++; return Chisla(str, day, month, year, i);
			case(2): i++; return Chisla(str, day, month, year, i);
			case(3): month = int(str[i] - '0') * 10; i++; return Chisla(str, day, month, year, i);	
			case(4): month += int(str[i] - '0'); i++; return Chisla(str, day, month, year, i);
			case(5): i++; return Chisla(str, day, month, year, i);
			case(6): year = int(str[i] - '0') * 1000; i++; return Chisla(str, day, month, year, i);
			case(7): year = int(str[i] - '0') * 100 + year; i++; return Chisla(str, day, month, year, i);
			case(8): year = int(str[i] - '0') * 10 + year; i++; return Chisla(str, day, month, year, i);
			case(9): year += int(str[i] - '0'); i++; return Chisla(str, day, month, year, i);
			default: return day, month, year;
		   }
}
int Proverka_na_visocos(int day, int month, int year )
{
	if ((!(year % 4) && !(year % 400) || year % 100) && month == 2 && day == 29)
	{
		printf("Это не високосный год, в февпале 28 дней.\n ");
		printf("Перезапустите программу.");
		return -1;
	}
	return 0;
}
int Nachalo(int year, int& nachalo)
{ 
    const int Pervi_2016 = 2016;
	int  visocos = 0;
	if (year >= Pervi_2016)
	{
		for (int i = Pervi_2016; i + 4 < year;i += 4)
		{
		  if ((i % 4 || i % 400) && !(i & 100)){visocos++;}
		}
		return nachalo = (year - Pervi_2016 + visocos ) % 7;
	}
	else {for (int i = Pervi_2016; i - 4 > year; i -= 4)
		     {
			if ((i % 4 || i % 400) && !(i & 100)) { visocos++;}
		     }
	      return nachalo = 6 - ((Pervi_2016 - year + visocos) % 7);
	     }
}
int Nomer_nedeli( int day, int month, int year, int nachalo, int& numer_nedeli)
{
	if ((year % 4 || year % 400) && !(year & 100))
	{
		switch (month)
		{
		case(1): return numer_nedeli = (nachalo + ((month - 1) * 30 + day) % 7) % 7;
		case(2): return numer_nedeli = (nachalo + ((month - 1) * 30 + 2 + day) % 7) % 7;
		case(3): return numer_nedeli = (nachalo + ((month - 1) * 30  + day) % 7) % 7;
		case(4): return numer_nedeli = (nachalo + ((month - 1) * 30 + 1 + day) % 7) % 7;
		case(5): return numer_nedeli = (nachalo + ((month - 1) * 30 + 2 + day) % 7) % 7;
		case(6): return numer_nedeli = (nachalo + ((month - 1) * 30 + 2 + day) % 7) % 7;
		case(7): return numer_nedeli = (nachalo + ((month - 1) * 30 + 1 + day) % 7) % 7;
		case(8): return numer_nedeli = (nachalo + ((month - 1) * 30 + 3 + day) % 7) % 7;
		case(9): return numer_nedeli = (nachalo + ((month - 1) * 30 + 4 + day) % 7) % 7;
		case(10): return numer_nedeli = (nachalo + ((month - 1) * 30 + 4 + day) % 7) % 7;
		case(11): return numer_nedeli = (nachalo + ((month - 1) * 30 + 5 + day) % 7) % 7;
		case(12): return numer_nedeli = (nachalo + ((month - 1) * 30 + 5 + day) % 7) % 7;
		default: return -1;
		}
	}
	else {switch (month)
		{
		case(1): return numer_nedeli = (nachalo + ((month - 1) * 30 + day) % 7) % 7;
		case(2): return numer_nedeli = (nachalo + ((month - 1) * 30 + 1 + day) % 7) % 7;
		case(3): return numer_nedeli = (nachalo + ((month - 1) * 30 - 1 + day) % 7) % 7;
		case(4): return numer_nedeli = (nachalo + ((month - 1) * 30 + day) % 7) % 7;
		case(5): return numer_nedeli = (nachalo + ((month - 1) * 30 + 1 + day) % 7) % 7;
		case(6): return numer_nedeli = (nachalo + ((month - 1) * 30 + 1 + day) % 7) % 7;
		case(7): return numer_nedeli = (nachalo + ((month - 1) * 30  + day) % 7) % 7;
		case(8): return numer_nedeli = (nachalo + ((month - 1) * 30 + 2 + day) % 7) % 7;
		case(9): return numer_nedeli = (nachalo + ((month - 1) * 30 + 3 + day) % 7) % 7;
		case(10): return numer_nedeli = (nachalo + ((month - 1) * 30 + 3 + day) % 7) % 7;
		case(11): return numer_nedeli = (nachalo + ((month - 1) * 30 + 4 + day) % 7) % 7;
		case(12): return numer_nedeli = (nachalo + ((month - 1) * 30 + 4 + day) % 7) % 7;
		default: return -1;
	    }
	}
}
void Den_nedeli( int numer_nedeli)
{
	switch (numer_nedeli)
	{
	case(0): printf("\n пятница.\n\n"); break;
	case(1): printf("\n суббота.\n\n"); break;
	case(2): printf("\n воскресение.\n\n"); break;
	case(3): printf("\n понедельник.\n\n"); break;
	case(4): printf("\n вторник.\n\n"); break;
	case(5): printf("\n среда.\n\n"); break;
	case(6): printf("\n четверг.\n\n"); break;
	default:break;
	}
}