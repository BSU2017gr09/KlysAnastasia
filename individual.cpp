//Определить,сколько слов в строке состоит только из цифр. 
//Вывести такие слова на экран и удалить после них следующее слово.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
const int N = 255;
typedef char fff(char *, int);
typedef fff *pfff;
char * enter(const int N) {
	char *S;
	try {
		S = new char[N];
	}
	catch (...) {
		cout << "Ошибка: невозможно создать такой массив.";
		exit(0);
	}
	return S;
}
char exitS(char *S, int N) {
	delete[N] S;
	return 0;
}
int digword(char *S1, int b) {           //определяет: состоит ли слово только из цифр
	int t = 0;
	for (char *p = S1; p < S1 + b; p++) {
		if (*p >= 48 && *p <= 57) t++;
	}
	if (t == b) return 1;
	else return 0;
}
char *oneword(char *S1, size_t b) {
	char S3[N];
	strncpy(S3, S1, b);
	*(S3 + b) = '\0';
	return S3;
}
char print(char *S1, size_t b) {
	char S3[N];
	strncpy(S3, S1, b);   
	*(S3 + b) = '\0';    
	cout << S3 << endl;
	return 0;
}

char *shear(char *S1, int b) {    //удаляет слово после слова, кторое состоит только из цифр
	char *kuf = enter(N);
	char *S2 = enter(N);
	strcpy(kuf, S1+b+1);  
	strcpy(S2, kuf);
	exitS(kuf, N);
	exitS(S2, N);
	return S2;
}
char numword(char *S, const int N) { //основная функция работы со строкой
	char *S1 = S;
	char *Fin= enter(N);
	*Fin = '\0';
	int a, b;
	char *S2 = " ,.!?";
	int w = 0, k=0, t=1;
	while (*S1)
	{
		a = strspn(S1, S2);
		b = strcspn(S1, S2);
		if ((a - b) > 0) {
			S1++;
			continue;
		}
		if (t&&!w) { 
			if (digword(S1, b)) w++;
		}
		if (!w) {  
			if (!*S1) break;
			Fin = strcat(Fin, oneword(S1, b+1)); 
			S1 = S1 + strcspn(S1, S2) + 1;
		}
		else {
			if (!*S1) break;
			t = 0;
			if (digword(S1, b)) {
				print(S1, b);
				w++;
				k++;
				Fin = strcat(Fin, oneword(S1, b+1));
				S1 = S1 + strcspn(S1, S2) + 1;
			}
			else {
				if (!*S1) break;
				if (k > 0) {
					if (!*(S1 + b))  break;
					S1 = shear(S1, b);
					if (digword(S1, b)) print(S1, b);
					if (!*S1) break;
					Fin = strcat(Fin, oneword(S1, b+1));
					S1 = S1 + strcspn(S1, S2) + 1;
				}
			}
		}

	}
	cout << "Строка со сдвигами " << Fin << endl;
	cout << "Всего слов, состоящих только из цифр: " << w<<endl;
	exitS(Fin, N);
	return 0;
}

char input(char *S, int N) {
	while (1) {
		cout << "Введите строку" << "\n";    //2 раза выводит эту запись
		fflush(stdin);
		cin.getline(S, N);
		if (strlen(S)) break;
	}
	return 0;
}
char exit(char *S, int b) {
	exit(0);
}

char help(char *S, int b) {
	cout << "Определить, сколько слов в строке состоит только из цифр. Вывести такие слова на экран и удалить после них следующее слово" << "\n";
	return 0;
}
void forEach(char *S, const int N, pfff pf) {
	pf(S, N);
}

int main() {
	setlocale(LC_ALL, "ru");
	int n;
	char *S = enter(N);
	fff * Fmenu[4] = { exit, help, input, numword };
	while (1) {
		cout << "Введите номер операции:" << "\n" << "0-Выход" << "\n" << "1-Условие задачи" << "\n" << "2-Ввести строку" << "\n" << "3-Вывести результат" << "\n";
		cin >> n;
		forEach(S, N, Fmenu[n]);
	}
	system("pause");
	exitS(S, N);
	return 0;
}
