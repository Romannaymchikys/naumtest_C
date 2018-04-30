#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <tchar.h>
#include <iostream>
#include <cstring>

const size_t SIZE = 100;
size_t _accuracy = 1;
int _Choice_of_actions(int *, char **, size_t&);

int main()
{
	size_t size_h = 2;
	printf_s("\t\t\t ********Spravochnik*******\n");
	int *_lineleft = new int[size_h];
	char **_mass = new char*[size_h];
	for (size_t i = 0; i < size_h - 1; i++) {
		_mass[i] = new char[size_h];
	}
	_Choice_of_actions(_lineleft, _mass, size_h);
	return 0;
}

int _exitornotexit(char **_mass, size_t size_h,
	int *_lineleft, size_t& _selector) {
	system("cls");
	printf_s("1 - vihod;\n");
	printf_s("2 - prodolzit';\n");
	scanf_s("%d", &_selector); 
	if (_selector == 2) { 
		system("cls"),
		_Choice_of_actions(_lineleft, _mass, size_h);
	}
	else { 
		for (size_t i = 0; i < size_h - _accuracy; i++) { 
			delete[] _mass[i]; 
		}
		delete[] _mass;
		delete[] _lineleft;	
	    return 0;
	}
}

void _Search_for_contacts(char **_mass, size_t size_h,
	int *_lineleft, size_t& _selector)// поиск контактов
{
	bool _Selector = false;
	char *_strname = new char[SIZE]; // строка под имя в поиске
	char *_search_name = _strname;
	printf_s("Vvedite imea\n");
	std::cin.get();
	std::cin.getline(_search_name, SIZE);
	size_t i = 0, j = 0;
	for (char **_ptr_h = _mass; _ptr_h < (_mass + size_h - 2); _ptr_h += 2, j += 2) // копирование элементов
	{
		for (char *_ptr_l = *_ptr_h, *_search_dubal = _search_name,
			*_ptr = *_ptr_h + _lineleft[j]; _ptr_l < _ptr; _ptr_l++, _search_dubal++, i++)
		{
			if (*_ptr_l == *_search_dubal) {
				_Selector = true;
			}
			else {
				_Selector = false;
					break;
			}
		}
		if (_Selector == true)
		{
			_ptr_h++;
			for (char *_ptr_l2 = *_ptr_h, *_ptr = *_ptr_h + _lineleft[j + 1];
				_ptr_l2 < _ptr; _ptr_l2++) {
				printf_s("%c", *_ptr_l2); 
			}
			delete[] _strname;
			printf_s("\n");
			system("pause");
			_exitornotexit(_mass, size_h, _lineleft, _selector);
		}
	}
	delete[] _strname;
	printf_s("Takova imeni net v Spravochnike!\n");
	system("pause");
	_exitornotexit(_mass, size_h, _lineleft, _selector);
}

void _Print_mass(char **_mass, size_t size_h,
	int *_lineleft, size_t _selector)// просмотр контактов
{  
	system("cls");
	for (char **_ptr_x = _mass, i = 0; _ptr_x < (_mass + size_h - 2); _ptr_x++, i++)
	{
		for (char *_ptr_y = *_ptr_x, *_ptr = *_ptr_x + _lineleft[i]; 
			_ptr_y < _ptr; _ptr_y++) { printf_s("%c", *_ptr_y); }
		printf_s("\n");
	}
	system ("pause");
	_exitornotexit(_mass, size_h, _lineleft, _selector);
}

int _Setting_the_line_length(int *_lineleftDubal1, size_t size_h,
	size_t _countersize_l, size_t& _index)
{
	for (int *_LINE = _lineleftDubal1; _LINE < (_lineleftDubal1 + size_h); _LINE++)
	{
		if ((_LINE + 2 == (_lineleftDubal1 + size_h)) && (_index == 0)) {
			_index = 1; *_LINE = _countersize_l; 
			break;
		}
		if ((_LINE + 1 == (_lineleftDubal1 + size_h)) && (_index == 1)) { 
			_index = 0; *_LINE = _countersize_l;
		}
	}
	return _index, *_lineleftDubal1;
}

int _Adding_contacts(int *_lineleft, char **_mass, 
	size_t& size_h, size_t& _selector)// добавление контактов
{
	int *_lineleftDubal = new int[size_h];
	for (int *_str_h = _lineleft, *_str_hDubal = _lineleftDubal;
		_str_h < (_lineleft + size_h); _str_h++, _str_hDubal++) { 
		*_str_hDubal = *_str_h; 
	}
	delete[]  _lineleft;
	_lineleft = new int[size_h];
	for (int *_str_h = _lineleft, *_str_hDubal = _lineleftDubal; 
		_str_h < (_lineleft + size_h); _str_h++, _str_hDubal++)
	{
		*_str_h = *_str_hDubal;
	}
	delete[] _lineleftDubal;
	system("cls");
	char *_strname = new char[SIZE]; // строка под имя 
	char *_strDubal = _strname;
	printf_s("Vvedite imea\n");
	std::cin.get();
	std::cin.getline(_strDubal, SIZE);
	size_t _countersize_l = 0, _index = 0;
	for (size_t i = 0; _strDubal[i] != '\0';i++) {
		_countersize_l++; 
	}
	
	int *_lineleftDubal1 = _lineleft ;
	_Setting_the_line_length(_lineleftDubal1, size_h, _countersize_l, _index);

	char *_strnumer = new char[SIZE];// строка под телефон
	char *_strdubalw = _strnumer;
	printf_s("Vvedite  numer\n");
	std::cin.getline(_strdubalw, SIZE);
	_countersize_l = 0;
	for (size_t i = 0; _strdubalw[i]  != '\0'; i++)
	{
		_countersize_l++; 
	}                              
	_countersize_l ++;
	int *_lineleftDubal2 = _lineleft;
	_Setting_the_line_length(_lineleftDubal2, size_h, _countersize_l, _index);
	
	char **_massDUBAL = new char*[size_h];
	for (size_t i = 0; i < size_h; i++) {
		_massDUBAL[i] = new char[_lineleft[i]]; } // каждая строка имеет свою длинну
	size_t i = 0;
	for (char **_str_h = _mass, **_str_hDUBAL = _massDUBAL; _str_h
		< (_mass + size_h); _str_h++, i++, _str_hDUBAL++) 
	{
		for (char *_str_l = *_str_h, *_str_lDUBAL = *_str_hDUBAL, *_str_hname = _strname,
			*_str_hnumer = _strnumer, *_ptr = _str_l + _lineleft[i];
			_str_l < _ptr; _str_lDUBAL++, _str_l++) 
		{
			if ((_mass + size_h) - 2 == _str_h) {
				*_str_lDUBAL = *_str_hname; _str_hname++; 
			}// добавели имя
			else if ((_mass + size_h) - 1 == _str_h) {
				*_str_lDUBAL = *_str_hnumer; _str_hnumer++; 
			}// добавели телефон
			else { *_str_lDUBAL = *_str_l; }
		}
	}
	for (size_t i = 0; i < size_h - _accuracy; i++) { delete[] _mass[i]; }
	delete[] _mass;
	_accuracy = 3;
	_mass = new char*[size_h]; //замена временного массива
	for (size_t i = 0; i < size_h; i++) { _mass[i] = new char[_lineleft[i]]; }
	size_t j = 0;
	for (char **_ptr_h = _mass, **_str_hDUBAL = _massDUBAL; _ptr_h <
		(_mass + size_h); _ptr_h++, j++, _str_hDUBAL++) // копирование элементов
	{
		for (char *_ptr_l = *_ptr_h, *_str_lDUBAL = *_str_hDUBAL,
			*_ptr = _ptr_l + _lineleft[j]; _ptr_l < _ptr; _ptr_l++, _str_lDUBAL++)
		{
			*_ptr_l = *_str_lDUBAL;
		}
	}
	//_Print_mass(_mass, size_h, _lineleft);
	delete[] _massDUBAL;
	delete[] _strname;
	delete[] _strnumer;
	size_h += 2;
	_exitornotexit(_mass, size_h, _lineleft, _selector);
	return 0;
}
int _Choice_of_actions(int *_lineleft, char **_mass, size_t& size_h) {
	size_t _selector = 2, _number;
	if (_selector == 2) {
		printf_s("0 - Vihod;\n");
		printf_s("1 - prosmotr kontaktov;\n");
		printf_s("2 - poisk kontaktov;\n");
		printf_s("3 - dobavlenie kontaktov;\n");
		scanf_s("%d", &_number);  
		switch (_number){
		case(0): return 0;
		case(1): _Print_mass(_mass,  size_h, _lineleft, _selector);// просмотор контактов
		case(2): _Search_for_contacts(_mass, size_h, _lineleft, _selector);//поиск контактов
		case(3): _Adding_contacts(_lineleft, _mass, size_h, _selector); break;// добавление контактов
		}
	}
	else { return 0;}
}



