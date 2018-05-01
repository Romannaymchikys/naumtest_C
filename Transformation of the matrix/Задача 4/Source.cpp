#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <tchar.h>
#include <iostream>
#include <string.h>
using namespace std;

const size_t N = 5, M = 15;

void _init_mass(int**, size_t, size_t);
void TRANSPONATION_mass(int **, size_t, size_t);
int main()
{
	int **_mass = new int*[N];
	for (size_t i = 0; i < N; i++) _mass[i] = new int[M];
	_init_mass(_mass, N, M);
	TRANSPONATION_mass(_mass, N, M);
	return 0;
}
void _Print_mass(int **mass, size_t size_x, size_t size_y)
{
	for (int **_ptr_x = mass; _ptr_x < (mass + size_x); _ptr_x++) {
		for (int *_ptr_y = *_ptr_x, *_ptr = *_ptr_x + size_y; _ptr_y < _ptr; _ptr_y++) {
			printf_s(" %2d ", *_ptr_y);
		}
		printf_s("\n");
	}
	system("pause");
}
void _init_mass(int **mass, size_t size_x, size_t size_y)
{
	size_t _size = size_x + size_y;
	for (int **_ptr_x = mass; _ptr_x < (mass + size_x); _ptr_x++) {
		for (int *_ptr_y = *_ptr_x, *_ptr = *_ptr_x + size_y; _ptr_y < _ptr; _ptr_y++) {
			*_ptr_y = rand() % (_size);
		}
	}
	_Print_mass(mass, size_x, size_y);
}
void TRANSPONATION_mass(int **mass, size_t size_x, size_t size_y) 	
{
	int **_massUpdated = new int*[M];
	for (size_t i = 0; i < M; i++) _massUpdated[i] = new int[N];

	for (int **_ptr_xUpdated = _massUpdated, i = 0, **ptr_z = _ptr_xUpdated + M ;
		_ptr_xUpdated < ptr_z; i++,  _ptr_xUpdated++) {
		for (int**_ptr_y = mass, *_ptr_yUpdated = *_ptr_xUpdated,*ptr_z = _ptr_yUpdated + N;
			_ptr_yUpdated < ptr_z; _ptr_yUpdated++, _ptr_y++) {
			int *_tr_y = *_ptr_y;
			_tr_y += i;
			*_ptr_yUpdated = *_tr_y;		
		}
	}
	for (size_t i = 0; i < N; i++) delete[] mass[i];
	delete[] mass;


	_Print_mass(_massUpdated, M, N);
	for (size_t i = 0; i < N; i++) delete[] _massUpdated[i];
	delete[] _massUpdated;
}
