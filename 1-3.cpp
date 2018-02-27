//Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования. 
//Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.
#include <iostream>
using namespace std;
void initArray(int *A, const int N) {
	for (int *p = A; p < A + N; p++) {
		*p = rand() % 21-10;
	}
}

void swap(int *p, int *k) {
	int z = *k;
	*k = *p;
	*p = z;
}
void sortArray(int *A, const int N) {
	for (int *p = (A + N - 1); p >= A; p--) {
		for (int *k = p; k >= A; k--) {
			if (*p <0) {
				swap(*p, *k);
			}
		}
	}
	for (int *p = A; p < A + N, *p<0; p++) {
		for (int *k = p; k < A + N; k++) {
			if (*p > *k) {
				swap(*k, *p);
			}
		}
	}
}

void printArray(int *A, const int N, char delim = '\n') {
	cout << "Элементы массива: ";
	for (int *p = A; p < A + N; p++) {
		cout << *p << delim;
	}

}

int * enterM(int N) {
	int *A;
	try {
		A = new int[N];
	}
	catch (...) {
		cout << "Ошибка: невозможно создать такой массив.";
		exit (0);
	}
	return A;
}

int exitM(int *A, int N) {
	delete[N] A;
	return 0;
}
int main() {
	setlocale(LC_ALL, "ru");
	int N;
	int *A;
	cout << "Введите размер массива: ";
	cin >> N;
	A=enterM(N);
	initArray(A, N);
	printArray(A, N);
	sortArray(A, N);
	cout << "перестановка" << endl;
	printArray(A, N);
	system("pause");
	exitM(A, N);
	return 0;
}