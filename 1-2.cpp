//Даны точки плоскости своими координатами в виде двух одномерных массивов. 
//Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.
#include <iostream>
using namespace std;
void initArray(float *A, const int N) {
	for (float *p = A; p < A + N; p++) {
		*p = rand() % 11;
	}
}
float distance(float x, float y , float a, float b, float c) {
	float dist = abs(a*x + b*y + c) / sqrt(a*a + b*b);
	return dist;
}
void swap(int *p, int *k) {
	int z = *k;
	*k = *p;
	*p = z;
}
void sortArray(float *A, float *B, const int N, float a, float b, float c) {
	for (float *p = A, *q=B; p < A + N; p++, q++) {
		for (float *k = p, *l= q; k < A + N; k++, l++) {
			if (distance(*p, *q, a, b, c) > distance(*k, *l, a, b, c)) {
				swap(*k, *p);
				swap(*l, *q);
			}

		}
	}
}
void printArray(float *A, const int N, char delim = '\n') {
	cout << "Элементы массива: ";
	for (float *p = A; p < A + N; p++) {
		cout << *p << delim;
	}

}

float * enterM(int N) {
	float *A;
	try {
		A = new float[N];
	}
	catch (...) {
		cout << "Ошибка: невозможно создать такой массив.";
		exit (0);
	}
	return A;
}

int exitM(float *A, int N) {
	delete[N] A;
	return 0;
}
int main() {
	setlocale(LC_ALL, "ru");
	int N, K;
	float a, b, c;
	float *A;
	float *B;
	cout << "Введите количество точек плоскости: ";
	cin >> N;
	A=enterM(N);
	B = enterM(N);
	while (1)
	{
		cout << "Введите коэффициенты уравнения прямой: ";
		cin >> a;
		cin >> b;
		cin >> c;
		if ((a*a + b*b) == 0) {
			cout << "Уравнение не имеет смысла. Повторите попытку: " << "\n";
		}
		else break;
	}
	initArray(A, N);
	initArray(B, N);
	printArray(A, N);
	printArray(B, N);
	sortArray(A, B, N, a, b, c);
	cout << "перестановка" << endl;
	printArray(A, N);
	printArray(B, N);
	system("pause");
	exitM(A, N);
	return 0;
}