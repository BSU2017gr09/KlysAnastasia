//Симметричную матрицу А(N, N), заданную верхним треугольником в виде одномерного массива 
//относительно побочной диагонали, умножить на вектор В(N).В памяти матрицу не получать.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
using namespace std;
typedef int fff(int **, int *, int);
typedef fff *pfff;
void giveMemory(int **&A, const int N) {
	try { A = new int*[N]; }
	catch (...) {
		cout << "Ошибка: невозможно создать массив для строк.";
		exit(0);
	}

	for (int i = 0; i<N; i++) {
		try { A[i] = new int[N]; }
		catch (...) {
			cout << "Ошибка: невозможно создать очередную строку.";
			exit(0);
		}
	}

}
void giveMemory1(int *&B, const int N) {
	try { B = new int[N]; }
	catch (...) {
		cout << "Ошибка: невозможно создать массив для строк.";
		exit(0);
	}
}
void giveMemoryC(int *&С, const int N) {
	try { С = new int[(2 * N - N % 2)]; }
	catch (...) {
		cout << "Ошибка: невозможно создать массив для строк.";
		exit(0);
	}
}
void initArray(int **A, int*C, int N) { //Заполнение симметричной матрицы А(N, N), заданной верхним треугольником относительно побочной диагонали
	for (int i = 0, k=0; i<N; i++) {
		for (int j = 0; j < N; j++, k++) {
			if (i && (N - j - i) <= 0) { k--; A[i][j] = 0; }
			else {
				if( i && j < N / 2 && i>j) {    
					A[i][j] = A[j][i]; 
					k--; 
					continue;
				}
				A[i][j]=C[k];
			}
		}
	}
}
void initArrayB(int *B, int N) {
	for (int i = 0; i<N; i++) {
		cin >> B[i];
	}
}
void initArrayC(int *C, int N) {
	for (int i = 0; i<(2*N-N%2); i++) {  //N%2- определяем четность размерности
		cin >> C[i];
	}
}
void printArray(int **A, int N) {
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			cout << setw(3) << A[i][j];
		}
		cout << endl;
	}
}
void printArrayB(int *B, int N) {
	for (int i = 0; i<N; i++) {
		cout << B[i];
		cout << endl;
	}
}
void freeMemory(int **A, const int N) {
	for (int i = 0; i<N; i++) {
		delete[]A[i];
	}
}
void freeMemory1(int *B, const int N) {
		delete[N]B;
}
int help(int **A, int *B, int N) {
	cout << "Симметричную матрицу А(N,N), заданную верхним треугольником в виде одномерного массива относительно побочной диагонали, умножить на вектор В(N). В памяти матрицу не получать." << "\n";
	return 0;
}
int exit(int **A, int *B, int N) {
	exit(0);
}

int input(int **A, int *B, int N) {
	cout << "Введите элементы верхнетреугольной матрицы: " << "\n";
	int *C = nullptr;
	giveMemoryC(C, N);
	initArrayC(C, N);
	initArray(A, C, N);
	cout << "Введите координаты вектра, на который будет умножаться матрица" << "\n";
	initArrayB(B, N);
	printArray(A, N);
	freeMemory1(C, (2 * N - N % 2));
	return 0;
}
int output(int **A, int *B, int N) {
	int rez = 0;
	cout << "Результат произвыедения: " << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0, k = 0; j < N; j++, k++) {
			rez += B[k] * A[i][j];
		}
		cout << rez << "\n";
		rez = 0;
	}
	return 0;
}
void forEach(int **A, int* B, const int N, pfff pf) {
	pf(A, B, N);
}
int main() {
	setlocale(LC_ALL, "ru");
	int N, n;
	int* *A = nullptr;
	int *B = nullptr;
	cout << "Введите количество строк и столбцов в cимметричной матрице А(N, N): " << "\n";
	cin >> N;
	giveMemory(A, N);
	giveMemory1(B, N);
	fff * Fmenu[4] = { exit, help, input, output };
	while (1) {
		cout << "Введите номер операции:" << "\n" << "0-Выход" << "\n" << "1-Условие задачи" << "\n" << "2-Ввести параметры" << "\n" << "3-Вывести результат" << "\n";
		cin >> n;
		forEach(A, B, N, Fmenu[n]);
	}
	freeMemory(A, N);
	freeMemory1(B, N);
	system("pause");
	return 0;
}
