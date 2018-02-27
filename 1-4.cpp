//Ёлементы целочисленного массива ј(N), значени€ которых оказались простыми числами, 
//расположить в пор€дке возрастани€, не наруша€ пор€дка следовани€ других элементов.
#include <iostream>
#include <ctime>
using namespace std;
void initArray(int *A, const int N) {
	for (int *p = A; p < A + N; p++) {
		*p = rand() % 100;
	}
}

void swap(int *p, int *k) {
	int z = *k;
	*k = *p;
	*p = z;
}
bool primes(int *p) {
	if (*p == 1||*p==0) return false;
	for (int k = 2; k*k <= *p; k++) {
		if ((*p)%k == 0) return false;
	}
	return true;
}
void sortArray(int *A, const int N) {
	int h = N;
	for(int l=0; l<h; l++){
		for (int *p = A, i = 1, g=0; p < A + N; p++, g++) {
			if (primes(p)) {
				i++;
				int * k = p;
				for (int *q = k; q < A + N; q++) {
					if (primes(q)) {
						if (*k > *q) {
							swap(*k, *q);
							k = q;
						}
					}
				}
			}
			if (g == N - 1) { h=i+1; }
		}
	}
}


void printArray(int *A, const int N, char delim = '\n') {
	cout << "Ёлементы массива: ";
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
		cout << "ќшибка: невозможно создать такой массив.";
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
	srand(time(NULL));
	int N;
	int *A;
	cout << "¬ведите размер массива: ";
	cin >> N;
	A=enterM(N);
	initArray(A, N);
	printArray(A, N);
	sortArray(A, N);
	cout << "ѕерестановка простых элементов" << endl;
	printArray(A, N);
	system("pause");
	exitM(A, N);
	return 0;
}