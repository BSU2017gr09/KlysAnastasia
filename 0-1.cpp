//В массиве размера N, заполненного случ.числами от 0 до 10,
//подсчитать количество элементов, встречающихся более одного раза.
#include <iostream>
using namespace std;
void initArray(int *A, const int N) {
	for (int *p = A; p < A + N; p++) {
		*p = rand() % 11;
	}
}

void swap(int *p,int *k) {
	int z = *k;
	*k = *p;
	*p = z;
}
void sortArray(int *A, const int N) {
	for (int *p = A; p < A + N; p++) {
		for (int *k = p; k < A + N; k++) {
			if (*p > *k) {
				swap(*k,*p);
			}
			
		}
	}
}
void sumrepeat(int *A, const int N) {
	sortArray(A, N);
	int t = 0, z = 0;
	for (int *p = A; p < A + N; p++) {
		if (p == (A + N - 1)) {
			if (t >= 1) {
				z++;
				t = 0;
			}
		}
		else {
			if (*p != *(p + 1)) {
				if (t >= 1) {
					z++;
					t = 0;
				}
			}
			else t++;
		}
	}
	cout << "Количество элементов, встречающиеся более одного раза: " << z<<endl;
}

int main() {
	setlocale(LC_ALL, "ru");
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
	sumrepeat(A, N);
	system("pause");
	delete[] A;
	return 0;
}