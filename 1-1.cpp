//Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.
#include <iostream>
using namespace std;
void initArray(int *A, const int N) {
	for (int *p = A; p < A + N; p++) {
		*p = rand() % 11;
	}
}

void swap(int *p, int *k) {
	int z = *k;
	*k = *p;
	*p = z;
}
void sortArrayK(int *A, const int N, int K) {
	for (int *p = (A+K-1); p < A + N; p++) {
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
	int N, K;
	int *A;
	cout << "Введите размер массива: ";
	cin >> N;
	A=enterM(N);
	initArray(A, N);
	printArray(A, N);
	cout << "Введите номер элемента, с которого Вы хотите начать сортировку: ";
	cin >> K;
	sortArrayK(A, N, K);
	printArray(A, N);
	system("pause");
	exitM(A, N);
	return 0;
}