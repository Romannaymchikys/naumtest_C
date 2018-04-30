#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

using namespace::std;

#define Check_for_Homogeneity(mass, _number_1, _number_2){ \
        int _Max = 0;\
        size_t _max_index = 0;\
        for (size_t i = 0; i < M; i++) { if (mass[i] > _Max) { _Max = mass[i]; } }\
        for (size_t i = 0; i < M; i++) { if (mass[i] == _Max) { _max_index = i; } }\
        for (size_t i = 0; i < M; i++) { if (mass[i] == mass[_max_index]) { _number_1; } }\
        _number_2;\
        for (bool _selector = true; _selector == false;) {\
	    _Max = 0;\
	    for (size_t i = 0; i < M; i++) {\
		if (mass[i] > _Max && mass[i] < mass[_max_index]) { _Max = mass[i]; }\
	    }\
	    if (_Max == 0) { _selector = false; break; }\
	    for (size_t i = 0; i < M; i++) { if (mass[i] == _Max) { i = _max_index; } }\
	    for (size_t i = 0; i < M; i++) { if (mass[i] == mass[_max_index]) { _number_1; } }\
	    _number_2;\
         }\
         }
#define The_Finding(mass1, mass2, A, B, SIZE){ \
        for (size_t i = 0; i < A; i++) {\
	    for (size_t j = 0; j < A; j++) {\
		if (mass1[i] != mass1[j] && i != j) { _number++; }\
	    }\
	    for (size_t j = 0; j < B; j++) {\
		if (mass1[i] != mass2[j]) { _number++; }\
	    }\
	    if (_number == SIZE - 1) { _number = 0, mass_C2[_index] = mass1[i], _index++; }\
	    else if (_number < M + N - 1) {\
        for (size_t j = i; j > 0; j--) {\
	    if (mass1[i] == mass1[j]) { _korektor = false; break; }\
        }\
        }\
        if (_korektor = true) { _number = 0, mass_C2[_index] = mass1[i], _index++; }\
        else { _korektor = true, _number = 0; }\
        }\
        }
#define The_Finding_4task(mass1, A, B, SIZE){ \
        for (size_t i = 0; i < A; i++) {\
	    for (size_t j = 0; j < A; j++) {\
		if (mass1[i] != mass1[j] && i != j) { _number++; }\
	    }\
	    if (_number == SIZE - 1) { _number = 0, mass_C2[_index] = mass1[i], _index++; }\
	    else if (_number < M + N - 1) {\
        for (size_t j = i; j > 0; j--) {\
	    if (mass1[i] == mass1[j]) { _korektor = false; break; }\
        }\
        }\
        if (_korektor = true) { _number = 0, mass_C2[_index] = mass1[i], _index++; }\
        else { _korektor = true, _number = 0; }\
        }\
        }

size_t input_MN(size_t&, size_t&);
void All_dynamic_memory(const size_t, const size_t);
int main() {
	size_t M, N;
	input_MN(M, N);
	M = (const size_t)M, N = (const size_t)N;
	All_dynamic_memory(M, N);
	return 0;
}
size_t input_MN(size_t& M, size_t& N)
{
 printf_s("Enter the size of the first and second array:");
 scanf_s("%d", &N);
 scanf_s("%d", &M);
 return  N, M;
}

void Print_mass(int *_mass_X, const size_t A) {
	for (size_t i = 0; i < A; i++) {
		printf_s("%d\n", _mass_X[i]);
	}
	
}
//Задание 1
void Filling_in_mass_C_1(int **_mass_A, int **_mass_B, int **_mass_C, 
	const size_t K, const size_t M, const size_t N, size_t& _number)
{
	size_t _index = 0;
	bool _korektor = true;
	int *mass_A2 = *_mass_A, *mass_B2 = *_mass_B, *mass_C2 = *_mass_C;
	for (size_t i = 0; i < M; i++) {
		for (size_t j = 0; j < M; j++) {
			if (mass_A2[i] != mass_A2[j] && i != j) {
				_number++; 
			}
		}
			for (size_t j = 0; j < N; j++) {
				if (mass_A2[i] != mass_B2[j]) { 
					_number++; 
				}
			}
		if (_number == M + N - 1){
			_number = 0, mass_C2[_index] = mass_A2[i], _index++;
		}
		else if (_number < M + N - 1) {
			for (size_t j = i; j > 0; j--) {
				//проверка если есть повторения но в массиве нет таких значений
				if (mass_A2[i] == mass_A2[j]) {
					_korektor = false;
					break;
				}
			}
		}
			if (_korektor = true) { 
				_number = 0, mass_C2[_index] = mass_A2[i], _index++;
			}
		    else { _korektor = true, _number = 0; }
	}
	printf_s("a task 1\n\n");
	Print_mass(*_mass_C, K);
}
int Test_items_1(int **_mass_A, int **_mass_B,
	                 const size_t M, const size_t N, size_t& _number)
{
	int *mass_A2 = *_mass_A, *mass_B2 = *_mass_B;
	for (size_t i = 0; i < M; i++) {
		for (size_t j = 0; j < N; j++) {
			if (mass_A2[i] == mass_B2[j]) {
				_number++;
				break;
			}
		}
	}
	Check_for_Homogeneity(mass_A2, _number-- , _number++);
	return _number;
}
//задание 2
void Filling_in_mass_C_2(int **_mass_A, int **_mass_B, int **_mass_C, const size_t K,
	                                 const size_t M, const size_t N, size_t& _number)
{
	size_t _index = 0;
	bool _korektor = true;
	int *mass_A2 = *_mass_A, *mass_B2 = *_mass_B, *mass_C2 = *_mass_C;

	The_Finding(mass_A2, mass_B2, M, N, M + N);
	The_Finding(mass_B2, mass_A2, N, M, M + N);
	
	printf_s("a task 2\n\n");
	Print_mass(*_mass_C, K);
	
}
int Test_items_2(int **_mass_A, int **_mass_B, const size_t M, 
	                                                 const size_t N, size_t& _number)
{
	int *mass_A2 = *_mass_A, *mass_B2 = *_mass_B;
	for (size_t i = 0; i < M; i++) {
		for (size_t j = 0; j < N; j++) {
			if (mass_A2[i] == mass_B2[j]) { _number++; break; }
		}
	}
	Check_for_Homogeneity(mass_A2, _number--, _number++);
	Check_for_Homogeneity(mass_B2, _number--, _number++);
	return _number;
}
//задание 3
void Filling_in_mass_C_3(int **_mass_A, int **_mass_B, int **_mass_C,
	const size_t K, const size_t M, const size_t N, size_t& _number)
{
	int *mass_A2 = *_mass_A, *mass_B2 = *_mass_B, *mass_C2 = *_mass_C;
	for (size_t i = 0; i < M + N; i++) {
		if (i < M) {
			mass_C2[i] = mass_A2[i]; 
		}
		else { mass_C2[i] = mass_B2[i - M]; }
	}
	printf_s("a task 3\n\n");
	Print_mass(*_mass_C, K);
}
//задание 4
void Filling_in_mass_C_4(int **_mass_A, int **_mass_B, int **_mass_C,
	                const size_t K, const size_t M, const size_t N, size_t& _number)
{
	size_t _index = 0;
	bool _korektor = true;
	int *mass_A2 = *_mass_A, *mass_B2 = *_mass_B, *mass_C2 = *_mass_C;

	The_Finding_4task(mass_A2, M, N, M + N);
	The_Finding_4task(mass_B2, N, M, M + N);
	printf_s("a task 4\n\n");
	Print_mass(*_mass_C, K);

	_getch();
}
int Test_items_4(int **_mass_A, int **_mass_B, const size_t M,
	                            const size_t N, size_t& _number)
{
	int *mass_A2 = *_mass_A, *mass_B2 = *_mass_B;
	Check_for_Homogeneity(mass_A2, _number++, _number--);
	Check_for_Homogeneity(mass_B2, _number++, _number--);
	return _number;
}
void All_dynamic_memory(const size_t M, const size_t N)
{
	size_t _number = 0;
	int *_mass_A = new int[M];
	int *_mass_B = new int[N];
	srand(time(0));
	for (size_t i = 0; i < M; _mass_A[i] = rand(), i++){}
	Print_mass(_mass_A, M);
	for (size_t i = 0; i < N; _mass_B[i] = rand(), i++){}
	Print_mass(_mass_B, N);

	Test_items_1(&_mass_A, &_mass_B, M, N, _number);

	const size_t K = M  - _number;
	_number = 0;
	int *_mass_C1 = new int[K];
	Test_items_2(&_mass_A, &_mass_B, M, N, _number);

	const size_t K2 = M + N - _number;
	_number = 0;
	int *_mass_C2 = new int[K2];
	Filling_in_mass_C_1(&_mass_A, &_mass_B, &_mass_C1, K, M, N, _number);

	const size_t K3 = M + N;
	int *_mass_C3 = new int[K3];
	Filling_in_mass_C_2(&_mass_A, &_mass_B, &_mass_C2, K2, M, N, _number);

	Filling_in_mass_C_3(&_mass_A, &_mass_B, &_mass_C3, K3, M, N, _number);

	Test_items_4(&_mass_A, &_mass_B, M, N, _number);

	const size_t K4 = M + N - _number;
	_number = 0;
	int *_mass_C4 = new int[K4];
	Filling_in_mass_C_4(&_mass_A, &_mass_B, &_mass_C4, K4, M, N, _number);
	delete[] _mass_C1;
	delete[] _mass_C2;
	delete[] _mass_C3;
	delete[] _mass_C4;
	delete[] _mass_B;
	delete[] _mass_A;
}

