//Симметричную матрицу А(N, N), заданную верхним треугольником в виде одномерного массива 
//относительно побочной диагонали, умножить на вектор В(N).В памяти матрицу не получать.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
using namespace std;
typedef int fff(int *, int *, int);
typedef fff *pfff;

void giveMemory1(int *&B, const int N) {
	try { B = new int[N]; }
	catch (...) {
		cout << "Ошибка: невозможно создать массив для строк.";
		exit(0);
	}
}
void giveMemoryC(int *&С, const int N) {
	try { С = new int[(N*(N + 1) / 2)]; }
	catch (...) {
		cout << "Ошибка: невозможно создать массив для строк.";
		exit(0);
	}
}

void initArrayB(int *B, int N) {
	for (int i = 0; i<N; i++) {
		cin >> B[i];
	}
}
void initArrayC(int *C, int N) {
	for (int i = 0; i<(N*(N + 1) / 2); i++) {  //N%2- определяем четность размерности
		cin >> C[i];
	}
}

void printArrayB(int *B, int N) {
	for (int i = 0; i<N; i++) {
		cout << B[i];
		cout << endl;
	}
}
void freeMemory1(int *B, const int N) {
	delete[N]B;
}
void freeMemoryC(int *C, const int N) {
	delete[(N*(N + 1) / 2)]C;
}
int help(int *B, int *C, int N) {
	cout << "Симметричную матрицу А(N,N), заданную верхним треугольником в виде одномерного массива относительно побочной диагонали, умножить на вектор В(N). В памяти матрицу не получать." << "\n";
	return 0;
}
int exit(int *B, int *C, int N) {
	exit(0);
}

int input(int *B, int *C, int N) {
	cout << "Введите элементы верхнетреугольной матрицы: " << "\n";
	initArrayC(C, N);
	cout << "Введите координаты вектра, на который будет умножаться матрица" << "\n";
	initArrayB(B, N);
	return 0;
}
int output(int *B, int *C, int N) {
	int rez = 0, k = 0;
	cout << "Результат произведения: " << "\n";
	for (int i = 0; i < (N + 1)*N / 2;) {
		for (int j = 0; j < N - k; j++, i++) {
			rez += B[j] * C[i];
		}
		cout << rez << "\n";
		rez = 0;
		k++;
	}
	return 0;
}
void forEach(int *B, int* C, const int N, pfff pf) {
	pf(B, C, N);
}
int main() {
	setlocale(LC_ALL, "ru");
	int N, n;
	int *B = nullptr;
	int *C = nullptr;
	cout << "Введите количество строк и столбцов в cимметричной матрице А(N, N): " << "\n";
	cin >> N;
	giveMemoryC(C, N);
	giveMemory1(B, N);
	fff * Fmenu[4] = { exit, help, input, output };
	while (1) {
		cout << "Введите номер операции:" << "\n" << "0-Выход" << "\n" << "1-Условие задачи" << "\n" << "2-Ввести параметры" << "\n" << "3-Вывести результат" << "\n";
		cin >> n;
		forEach(B, C, N, Fmenu[n]);
	}
	freeMemoryC(C, N);
	freeMemory1(B, N);
	system("pause");
	return 0;
}
