
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>

int  chiclo_1, chislo_2, max_diapazon, min_diapazon, number;
int Vvod(int&, int&, int&, int&);
int Diapazon(int, int&, int);
int Glorer(int, int, int Grover(int, int&, int), int);
int main()
{
	Vvod(chiclo_1, chislo_2, max_diapazon, min_diapazon);
	Glorer(max_diapazon, min_diapazon, Diapazon, number);
	return 0;
}
int Minmax(int& chislo_1, int& chislo_2, 
	int& max_diapazon, int& min_diapazon)
{

	if (chislo_1 > chislo_2)
	{
		return 	max_diapazon = chislo_1, min_diapazon = chislo_2;
	}
	else { return 	max_diapazon = chislo_2, min_diapazon = chislo_1; }
}
int Vvod(int& chislo_1, int& chislo_2, int& max_diapazon, int& min_diapazon)
{
	printf("\t\t\tVivod chicel c opredelennogo diopozona\n\n ");
	do
	{
		printf(" Vvedite chiclo 1: ");
		scanf_s("%d", &chislo_1);
		printf(" Vvedite chiclo 2: ");
		scanf_s("%d", &chislo_2);
	} while (chislo_1 == chislo_2);
	Minmax(chislo_1, chislo_2, max_diapazon, min_diapazon);
	return max_diapazon, min_diapazon;
}
int Glorer(int max_diapazon, int min_diapazon, 
	int Grover(int, int&, int), int number)
{
	number = min_diapazon;
	printf("\t Chisla diapazona:\n ");
	Grover(max_diapazon, min_diapazon, number);
	return 0;
}
int Kratnie(int max_diapazon, int& min_diapazon, int kratnoe)
{
	min_diapazon++;
	if (min_diapazon <= max_diapazon)
	{
		if (!(min_diapazon % kratnoe))
		{
			printf(" %d  ", min_diapazon);
		}
		Kratnie(max_diapazon, min_diapazon, kratnoe);
	}
	system("pause");
	return 0;
}
int Nechetnie(int max_diapazon, int& min_diapazon, int number)
{
	min_diapazon++;
	if(min_diapazon <= max_diapazon)
	{
		if (min_diapazon % 2)
		{
			printf(" %d  ", min_diapazon);
		}
		Nechetnie(max_diapazon, min_diapazon, number);
	}
	else
	{
		min_diapazon = number;
		const int kratnoe = 7;
		printf("\n\n Kratnie %d chisla v etom diopozone: \n", kratnoe);
		Kratnie(max_diapazon, min_diapazon, kratnoe);
	}
	return 0;
}
int Chetnie(int max_diapazon, int& min_diapazon, int number)
{
	min_diapazon ++;
	if (min_diapazon <= max_diapazon)
	{
		if(!(min_diapazon % 2))
		{
			printf(" %d  ", min_diapazon);
		}
		Chetnie(max_diapazon, min_diapazon, number);
	}
	else
	{
		min_diapazon = number;
		printf("\n\n Nechetnie chisla v etom diopozone: \n");
		Nechetnie(max_diapazon, min_diapazon, number);
	}
	return 0;
}
int Diapazon(int max_diapazon, int& min_diapazon, int number)
{
	min_diapazon++;
	if (min_diapazon <= max_diapazon)
	{
		printf(" %d  ", min_diapazon);
		Diapazon(max_diapazon, min_diapazon, number);
	}
	else
	{
		min_diapazon = number;
		printf("\n\n chetnie chisla v etom diopozone: \n");
		Chetnie(max_diapazon, min_diapazon, number);
	}
	return 0;
}