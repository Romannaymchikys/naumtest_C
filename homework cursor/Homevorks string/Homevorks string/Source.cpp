
//Задание 4
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <stdio.h>

#define Check_whether_the_text_is_a_palindrom(_index) {\
for (size_t i = 0; i <= (_countparity - _index ) / 2;){\
	if (_ptr[i] == _ptr[_countparity - (i + 2)]) {     \
		i++;                                           \
		_palindrom = true;                             \
	}                                                  \
	else { _palindrom = false; break; }                \
}                                                      \
}
using namespace::std;
void Input_string(const size_t);

int main() {
	const size_t M = 200;
	Input_string(M);
	return 0;
}
void Input_string(const size_t M) {
	char *_Str = new char[M];

	printf_s("Input text: ");
	cin.getline(_Str, M);
	bool _palindrom = false;
	size_t _countparity = 0;
	char *_ptr = _Str;

	while (_Str[_countparity] != '\0') {_countparity++;}
	_countparity++;

	if (_countparity % 2) { Check_whether_the_text_is_a_palindrom(1); }
	else { Check_whether_the_text_is_a_palindrom(2); }
		
	if (_palindrom == true) { printf_s("\t Your text is palindrom"); }
	else { printf_s("\t Your text is NOT palindrom"); }
	delete[] _Str;
	_getch();
}
