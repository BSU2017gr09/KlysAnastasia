//Объект содержит информацию о книге в библиотеке: 
//фамилия и имя автора, название книги, год издания,
//количество экземпляров данной книги в библиотеке, стоимость одного экземпляра.
//Вывести список книг по заданной теме, выпущенных после заданного года.
//Вывести список книг заданного автора в порядке возрастания год издания.
//По запросу получить (не распечатать, а именно получить) список всех книг, упорядоченный по году 
//издания(по названию, по фамилии автора), количество книг, общую стоимость книг.
#include <iostream>
#include<string>
#include <ctime>
#pragma warning(disable:4996)
using namespace std;

class Book
{
private:
	char* theme;
	char* title;
	char* author;
	unsigned int year;
	unsigned int num;
	double val;
public:
	Book() : theme(nullptr), title(nullptr), author(nullptr), year(0), num(0), val(0) {
		//cout << "Работает конструктор по умалчанию" << '\n';
	}
	Book(char * name, char * topic, char * fio, int y = 0, int n = 0, double v = 0) :theme(nullptr), title(nullptr), author(nullptr), year(y), num(n), val(v) {
		//cout << "конструктор с параметрами для " << Fio << "\n";
		try {
			this->theme = new char[strlen(name) + 1];
			strcpy(this->theme, name);
			this->title = new char[strlen(topic) + 1];
			strcpy(this->title, topic);
			this->author = new char[strlen(fio) + 1];
			strcpy(this->author, fio);
		}
		catch (...) {
			cout << "не получилось выделить место";
		}
	}
	~Book() {
		delete[]theme;
		delete[]title;
		delete[]author;
		//cout << "Работает диструктор"; 
	}
	Book(Book &other) :theme(nullptr), title(nullptr), author(nullptr), year(other.year), num(other.num), val(other.val) {
		//cout << "copy конструктор";
		try {
			theme = new char[strlen(other.theme) + 1];
			strcpy(this->theme, other.theme);
			title = new char[strlen(other.title) + 1];
			strcpy(this->title, other.title);
			author = new char[strlen(other.author) + 1];
			strcpy(this->author, other.author);
		}
		catch (...) {
			cout << "не получилось выделить место";
		}
	}
	void operator=(const Book &other) {
		//cout << "работает оператор равно";
		if (this != &other) {   //сравнивается 2 адреса
			delete[]theme;
			theme = new char[strlen(other.theme) + 1];
			strcpy(theme, other.theme);
			delete[]title;
			title = new char[strlen(other.title) + 1];
			strcpy(title, other.title);
			delete[]author;
			author = new char[strlen(other.author) + 1];
			strcpy(author, other.author);
			year = other.year;
			num = other.num;
			val = other.val;
		}
	}
	friend ostream& operator<<(ostream &output, Book &B) {
		cout << "Книга: " << "\n" << B.getTheme() << "\n" << "Автор: " << B.getAuthor() << "\n";
		cout << "Тематика: " << B.getTitle() << "\n" << "Год издания: " << B.getYear() << "\n" << "Стоимость: " << B.getVal() << " р. " << "\n";
		cout << "Количество книг на данный момент: " << B.getNum() << endl;
		return output;
	}
	void setTheme(char *str) {
		delete[]theme;
		theme = new char[strlen(str) + 1];
		strcpy(theme, str);
	}
	void setTitle(char *str) {
		delete[]title;
		title = new char[strlen(str) + 1];
		strcpy(title, str);
	}
	void setAuthor(char *str) {
		delete[]author;
		author = new char[strlen(str) + 1];
		strcpy(author, str);
	}
	void setYear(int m) {
		year = m;
	}
	void setNum(int k) {
		num = k;
	}
	void setVal(double k) {
		val = k;
	}
	char* getTheme() {
		return theme;
	}
	char* getTitle() {
		return title;
	}
	char* getAuthor() {
		return author;
	}
	int getYear() {
		return year;
	}
	int getNum() {
		return num;
	}
	double getVal() {
		return val;
	}

};
typedef Book* menu(Book *, int);
typedef menu* pmenu;
void forEach(Book *A, const int N, pmenu pf) {
	pf(A, N);
}

Book* printList(Book B[], const int N) {
	cout << "----------------------------------------------" << "\n";
	for (int i = 0; i < N; i++) {
		cout << B[i];
		cout << "----------------------------------------------" << "\n";
	}
	return 0;
}
void initArray(Book Books[], const int N) {
	//A-Topic, B-Name, C-Fio
	char *A[15] = { "Art","Biography","Children's","Classics","Comics","Fantasy","History","Horror","Memoir","Detective", "Poetry","Psychology","Romance","Science","Thriller" };
	char *B[13] = { "Fantastic beasts and where to find them","Harry Potter", "The Hobbit", "The Hunger Games", "The Lord of the Rings", "The Lion, the Witch and the Wardrobe", "A Game of Thrones", "The Little Prince", "The Chronicles of Narnia", "Eragon", "Alice's Adventures in Wonderland and Through the Looking Glass ", "Robinson Crusoe", "Sherlock Holmes" };
	char *C[10] = { "Melinda Leigh", "J. K. Rowling", "Bella Forrest", "James Patterson","Stephen King", "Suzanne Collins", "Stephenie Meyer", "Mark Twain", "C. S. Lewis", "Agatha Christie" };
	for (int i = 0; i < N; i++) {
		Books[i].setTheme(B[rand() % 12]);
		Books[i].setTitle(A[rand() % 14]);
		Books[i].setAuthor(C[rand() % 9]);
		Books[i].setYear(rand() % 100 + 1889);
		Books[i].setNum(rand() % 100);
		Books[i].setVal((double)(rand() % 1300));
	}
}
void outListT(Book B[], const int N, char * topic, int y = 0) {
	cout << "------------------------------------------" << endl;
	int k = 0;
	for (int i = 0; i < N; i++) {
		if (!strcmp(B[i].getTitle(), topic) && B[i].getYear() >= y) {
			k++;
			cout << B[i];
			cout << "------------------------------------------" << endl;
		}
	}
	if (!k) cout << "Запрос не найден. Попробуйте еще раз.\n";
}
void outListA(Book B[], const int N, char * author) {
	cout << "------------------------------------------" << endl;
	int k = 0;
	for (int i = 0; i < N; i++) {
		if (!strcmp(B[i].getAuthor(), author)) {
			k++;
			cout << B[i];
			cout << "------------------------------------------" << endl;
		}
	}
	if (!k) cout << "Запрос не найден. Попробуйте еще раз.\n";
}
void swap(Book &A, Book &B) {
	Book T;
	T.setTheme(A.getTheme());
	T.setTitle(A.getTitle());
	T.setAuthor(A.getAuthor());
	T.setYear(A.getYear());
	T.setNum(A.getNum());
	T.setVal(A.getVal());

	A.setTheme(B.getTheme());
	A.setTitle(B.getTitle());
	A.setAuthor(B.getAuthor());
	A.setYear(B.getYear());
	A.setNum(B.getNum());
	A.setVal(B.getVal());

	B.setTheme(T.getTheme());
	B.setTitle(T.getTitle());
	B.setAuthor(T.getAuthor());
	B.setYear(T.getYear());
	B.setNum(T.getNum());
	B.setVal(T.getVal());
}
void sort(Book *A, const  int N) {
	Book T;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (A[i].getYear() > A[j].getYear()) {
				swap(A[i], A[j]);
			}
		}
	}
}
void sortN(Book *A, const int N) {
	Book T;
	for (int i = 0; i < N; i++) {//сортировка по алфавиту 
		for (int j = i + 1; j < N; j++) {
			if ((int)*A[i].getTheme() >= (int)*A[j].getTheme()) {
				swap(A[i], A[j]);
			}
		}
	}
	for (int i = 0; i < N; i++) { //сортировка по конкретному названию
		for (int j = i + 1; j < N; j++) {
			if (!strcmp(A[i].getTheme(), A[j].getTheme())) {
				if (j - i >= 1) {
					swap(A[i + 1], A[j]);
				}
			}
			continue;
		}
	}
}
void sortA(Book *A, const  int N) {
	Book T;
	for (int i = 0; i < N; i++) {//сортировка по алфавиту 
		for (int j = i + 1; j < N; j++) {
			if ((int)*A[i].getAuthor() >= (int)*A[j].getAuthor()) {
				swap(A[i], A[j]);
			}
		}
	}
	for (int i = 0; i < N; i++) { //сортировка по конкретному автору
		for (int j = i + 1; j < N; j++) {
			if (!strcmp(A[i].getAuthor(), A[j].getAuthor())) {
				if (j - i >= 1) {
					swap(A[i + 1], A[j]);
				}
			}
			continue;
		}
	}
}
char input(char *&S, int N = 25) {
	S = new char;
	while (1) {
		fflush(stdin);
		cin.getline(S, N);
		if (strlen(S)) break;
	}
	return 0;
}

Book* exit(Book *A, const int N) {
	exit(0);
	return 0;
}
Book* help(Book *A, const int N) {
	cout << "Объект содержит информацию о книге в библиотеке: фамилия и имя автора, название книги, год издания,";
	cout << "количество экземпляров данной книги в библиотеке, стоимость одного экземпляра.\n";
	return 0;
}

Book* bookTY(Book *A, const int N) {
	char *topic;
	int y;
	cout << "Введите тему произведения:\n";
	input(topic);
	cout << "Введите год:\n";
	cin >> y;
	outListT(A, N, topic, y);
	return 0;
}
Book* bookYear(Book *A, const int N) {
	char *author;
	cout << "Введите автора произведения:\n";
	input(author);
	sort(A, N);
	outListA(A, N, author);
	return 0;
}
Book* outListYear(Book *A, const int N) {
	sort(A, N);
	printList(A, N);
	return 0;
}
Book* outListName(Book *A, const int N) {
	sortN(A, N);
	printList(A, N);
	return 0;
}
Book* outListAuthor(Book *A, const int N) {
	sortA(A, N);
	printList(A, N);
	return 0;
}
Book* numAllBooks(Book *A, const int N) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		count += A[i].getNum();
	}
	cout << "Количесиво всех книг: " << count << endl;
	return 0;
}
Book* sumAllVal(Book *A, const int N) {
	double count = 0;
	for (int i = 0; i < N; i++) {
		count += A[i].getVal();
	}
	cout << "Стоимость всех книг: " << count << " р." << endl;
	return 0;
}
int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	Book B[14];
	int n;
	const int N = 14;
	initArray(B, N);
	pmenu Fmenu[10] = { exit, help, printList, bookTY, bookYear, outListYear, outListName, outListAuthor, numAllBooks, sumAllVal };
	while (1) {
		cout << "Введите номер операции:" << "\n";
		cout << "0-Выход" << "\n";
		cout << "1-Вывести формулировку задания" << "\n";
		cout << "2-Весь список книг" << "\n";
		cout << "3-Вывести список книг по заданной теме, выпущенных после заданного года." << "\n";
		cout << "4-Вывести список книг заданного автора в порядке возрастания годa издания." << "\n";
		cout << "5-Получить список всех книг, упорядоченный по году издания \n";
		cout << "6-Получить список всех книг, упорядоченный по названию \n";
		cout << "7-Получить список всех книг, упорядоченный по автору \n";
		cout << "8-Получить количество всех книг \n";
		cout << "9-Получить общую стоимость всех книг \n";
		cin >> n;
		if (n < 0 || n>9) {
			cout << "Вы ввели неверное значение. Попробуйте еще раз!" << "\n";
			continue;
		}
		forEach(B, N, Fmenu[n]);
	}
	system("pause");
	return 0;
}