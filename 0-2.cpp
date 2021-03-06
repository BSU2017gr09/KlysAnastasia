//В массиве размера N, заполненного случ.числами от 0 до 10, 
//определить максимальную длину последовательности равных элементов.
#include <iostream>
#include <ctime>
using namespace std;
void initArray(int *A, const int N) {
	for (int *p = A; p < A + N; p++) {
		*p = rand() % 11;
	}
}


int MaxLen(int *A, const int N) {
	int K = 0;
	for (int *p = A, t = 1; p < A + N - 1; p++) {
		if (*p == *(p + 1)) {
			t++;
			if (t > K) K = t;
		}
		else {
			t = 1;

		}
	}
	if (K == 1) cout << "Последовательности равных элементов в этом массиве нет." << endl;
	else cout << "Максимальная длина последовательности равных элементов: " << K << endl;
	return K;

}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int *A;
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
	MaxLen(A, N);
	system("pause");
	delete[] A;
	return 0;
}




