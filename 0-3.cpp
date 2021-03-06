﻿//Массив чисел размера N проинициализировать случайными числами из промежутка от -N до N. 
//Написать функцию циклического сдвига элементов массива вправо на k элементов.
#include <iostream>
using namespace std;
void initArray(int *A, const int N) {
	for (int *p = A; p < A + N; p++) {
		*p = rand() % (2*N) - N;
	}
}
void swap(int *p, int *k) {
	int z = *k;
	*k = *p;
	*p = z;
}
void my_reshaffleKright(int *A, const int N, int H) {//лучше было написать функцию ReverseArray
	for (int *p = A,i=0, *k=(A + N - 1);i<N/2 ; p++, k--, i++) {
		swap(*k, *p);
	}
	for (int *p = A, i = 0, *k = (A + H - 1); i<H/2 ; p++, k--, i++) {
		swap(*k, *p);
	}
	for (int *p = A + H, i = 0, *k = (A + N - 1); i<(N-H)/2 ; p++, k--, i++) {
		swap(*k, *p);
	}
}



void printArray(int *A, const int N, char delim = '\n') {
	cout << "Элементы массива: ";
	for (int *p = A; p < A + N; p++) {
		cout << *p << delim;
	}

}


int main() {
	setlocale(LC_ALL, "ru");
	int *A;
	int k;
	int N;
	cout << "Введите размер массива: ";
	cin >> N;
	try {
		A = new int[N];
	}
	catch (...) {
		cout << "Ошибка: невозможно создать такой массив.";
		return 1;
	}
	initArray(A, N);
	printArray(A, N);
	cout << "Введите количество элементов, на которое вы хотите сдвинуть массив: ";
	cin >> k;
	my_reshaffleKright(A, N, k);
	printArray(A, N);
	system("pause");
	delete[] A;
	return 0;
}
