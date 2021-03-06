//Объект содержит информацию о книге в библиотеке: 
//фамилия и имя автора, название книги, год издания,
//количество экземпляров данной книги в библиотеке, стоимость одного экземпляра.
//Вывести список книг по заданной теме, выпущенных после заданного года.
//Вывести список книг заданного автора в порядке возрастания год издания.
//По запросу получить (не распечатать, а именно получить) список всех книг, упорядоченный по году 
//издания(по названию, по фамилии автора), количество книг, общую стоимость книг.
#include <iostream>
#include<cstring>
#include <ctime>
#include <fstream>
#include <limits>
#pragma warning(disable:4996)
using namespace std;
const int Max_size = 255;
char f[] = "c:\\BSU\\classBook.b";
char delim = '$';
class Book
{
private:
	char* theme;
	char* title;
	char* author;
	unsigned int year;
	unsigned int num;
	unsigned int val;
public:
	Book() : theme(nullptr), title(nullptr), author(nullptr), year(0), num(0), val(0) {
		//cout << "Работает конструктор по умалчанию" << '\n';
	}
	Book(char * name, char * topic, char * fio, int y = 0, int n = 0, int v = 0) :
		theme(nullptr), title(nullptr), author(nullptr), year(y), num(n), val(v) {
		//cout << "конструктор с параметрами для " << "\n";
		try {
			this->theme = new char[strlen(name) + 1];
			strcpy(this->theme, name);
		}
		catch (...) {
			cout << "не получилось выделить место";
			exit(0);
		}
		try {
			this->title = new char[strlen(topic) + 1];
			strcpy(this->title, topic);
		}
		catch (...) {
			cout << "не получилось выделить место";
			exit(0);
		}
		try {
			this->author = new char[strlen(fio) + 1];
			strcpy(this->author, fio);
		}
		catch (...) {
			cout << "не получилось выделить место";
			exit(0);
		}
	}
	~Book() {
		delete[]theme;
		delete[]title;
		delete[]author;
		//cout << "Работает деструктор"; 
	}
	Book(Book &other) :
		theme(nullptr), title(nullptr), author(nullptr), year(other.year), num(other.num), val(other.val) {
		//cout << "copy конструктор";
		try {
			theme = new char[strlen(other.theme) + 1];
			strcpy(this->theme, other.theme);
		}
		catch (...) {
			cout << "не получилось выделить место";
			exit(0);
		}
		try {
			title = new char[strlen(other.title) + 1];
			strcpy(this->title, other.title);
		}
		catch (...) {
			cout << "не получилось выделить место";
			exit(0);
		}
		try {
			author = new char[strlen(other.author) + 1];
			strcpy(this->author, other.author);
		}
		catch (...) {
			cout << "не получилось выделить место";
			exit(0);
		}
	}
	void operator=(const Book &other) {
		//cout << "работает оператор равно";
		if (this != &other) {   //сравнивается 2 адреса
			Book tmp;
			tmp.setTheme(other.theme);
			tmp.setTitle(other.title);
			tmp.setAuthor(other.author);
			tmp.setYear(other.year);
			tmp.setNum(other.num);
			tmp.setVal(other.val);
			swap(*this, tmp);
		}
	}
	friend ostream& operator<<(ostream &output, Book &B) {
		cout << "Книга: " << "\n" << B.getTheme() << "\n" << "Автор: " << B.getAuthor() << "\n";
		cout << "Тематика: " << B.getTitle() << "\n" << "Год издания: " << B.getYear() << "\n";
		cout << "Количество книг на данный момент: " << B.getNum() << endl;
		cout << "Стоимость: " << B.getVal() << " р. " << "\n";
		return output;
	}
	friend istream& operator>> (istream &mystream, Book &tmp) {
		cout << "Введите название книги: " << endl;
		try {
			tmp.theme = new char[Max_size];
			//fflush(stdin); не работает
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.getline(tmp.theme, Max_size);
		}
		catch (...) {
			cout << "не получилось выделить место";
			exit(0);
		}
		cout << "Введите автора книги: " << endl;
		try {
			tmp.author = new char[Max_size];
			fflush(stdin);
			cin.getline(tmp.author, Max_size);
		}
		catch (...) {
			cout << "не получилось выделить место";
			exit(0);
		}
		cout << "Введите тематику книги\n";
		try {
			tmp.title = new char[Max_size];
			fflush(stdin);
			cin.getline(tmp.title, Max_size);
		}
		catch (...) {
			cout << "не получилось выделить место";
			exit(0);
		}
		cout << "Введите год издания: \n";
		cin >> tmp.year;
		cout << "Введите количество книг в библиотеке: \n";
		cin >> tmp.num;
		cout << "Введите стоимость: \n";
		cin >> tmp.val;
		return mystream;
	}
	void setTheme(char *str) {
		try {
			delete[]theme;
			theme = new char[strlen(str) + 1];
			strcpy(theme, str);
		}
		catch (...) {
			cout << "не получилось выделить место";
		}
	}
	void setTitle(char *str) {
		try {
			delete[]title;
			title = new char[strlen(str) + 1];
			strcpy(title, str);
		}
		catch (...) {
			cout << "не получилось выделить место";
		}

	}
	void setAuthor(char *str) {
		try {
			delete[]author;
			author = new char[strlen(str) + 1];
			strcpy(author, str);
		}
		catch (...) {
			cout << "не получилось выделить место";
		}

	}
	void setYear(int m) {
		year = m;
	}
	void setNum(int k) {
		num = k;
	}
	void setVal(int k) {
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
	int getVal() {
		return val;
	}

};
typedef void menu(Book *, int);
typedef menu* pmenu;
void forEach(Book *A, const int N, pmenu pf) {
	pf(A, N);
}

void printList(Book B[], const int N) {
	cout << "----------------------------------------------" << "\n";
	for (int i = 0; i < N; i++) {
		cout << B[i];
		cout << "----------------------------------------------" << "\n";
	}
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
		Books[i].setVal(rand() % 1300);
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
void input(char *&S, int N = 25) {
	try {
		S = new char[N];
		while (1) {
			fflush(stdin);
			cin.getline(S, N);
			if (strlen(S)) break;
		}
	}
	catch (...) {
		cout << "не получилось выделить место";
		exit(0);
	}
}

void exit(Book *A, const int N) {
	exit(0);
}
void help(Book *A, const int N) {
	cout << "Объект содержит информацию о книге в библиотеке: фамилия и имя автора, название книги, год издания,";
	cout << "количество экземпляров данной книги в библиотеке, стоимость одного экземпляра.\n";
}
void bookTY(Book *A, const int N) {
	char *topic;
	int y;
	cout << "Введите тему произведения:\n";
	input(topic);
	cout << "Введите год:\n";
	cin >> y;
	outListT(A, N, topic, y);
}
void bookYear(Book *A, const int N) {
	char *author;
	cout << "Введите автора произведения:\n";
	input(author);
	sort(A, N);
	outListA(A, N, author);
}
void outListYear(Book *A, const int N) {
	sort(A, N);
	printList(A, N);
}
void outListName(Book *A, const int N) {
	sortN(A, N);
	printList(A, N);
}
void outListAuthor(Book *A, const int N) {
	sortA(A, N);
	printList(A, N);
}
void numAllBooks(Book *A, const int N) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		count += A[i].getNum();
	}
	cout << "Количесиво всех книг: " << count << endl;
}
void sumAllVal(Book *A, const int N) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		count += A[i].getVal();
	}
	cout << "Стоимость всех книг: " << count << " р." << endl;
}
void editBook(Book *A, const int N) {
	cout << "Введите номер редактируемой книги(до " << N << ")\n";
	Book tmp;
	int n;
	while (1) {
		cin >> n;
		if (n < 1 || n>N) {
			cout << "Такой книги не существует! Поробуйте еще раз!";
		}
		else break;
	}
	cin >> tmp;
	swap(A[n - 1], tmp);
}
void datafile(Book *A, const int N) {
	int tmp = 0;
	ofstream fout1(f, ios::out | ios::binary);   // открытие файла для вывода
	if (!fout1) { cout << "No file open\n"; exit(1); }
	for (int i = 0; i < N; i++) {
		fout1.write((char*)A[i].getTheme(), strlen(A[i].getTheme()));
		fout1.write((char*)"$", 1);
		fout1.write((char*)A[i].getTitle(), strlen(A[i].getTitle()));
		fout1.write((char*)"$", 1);
		fout1.write((char*)A[i].getAuthor(), strlen(A[i].getAuthor()));
		fout1.write((char*)"$", 1);
		tmp = A[i].getYear();
		fout1.write((char*)&tmp, sizeof(tmp));
		tmp = A[i].getNum();
		fout1.write((char*)&tmp, sizeof(tmp));
		tmp = A[i].getVal();
		fout1.write((char*)&tmp, sizeof(tmp));
		fout1.write((char*)"$", 1);
	}
	fout1.close();
}
void fread(Book *A, const int N) {
	cout << "Введите номер книги, данные которой Вы хотите увидеть:\n";
	int n = 0;
	int tmp = 0, y = 0;
	char q;
	cin >> n;
	if (n < 1 || n>N) {
		cout << "Такой книги не существует! Поробуйте еще раз!";
		exit(1);
	}
	ifstream fin1(f, ios::in);
	//(n-1)*6-кол-во разделителей в файле до определенной книги
	int count = 0;
	while (1) {
		if (n == 1) break;
		fin1.read((char *)&q, 1);
		if (q == '$') {
			count++;
		}
		if (count == (n - 1) * 4) {
			break;
		}
	}
	char tor[255];
	Book a;
	fin1.getline(tor, Max_size, '$');
	a.setTheme(tor);
	fin1.getline(tor, Max_size, '$');
	a.setTitle(tor);
	fin1.getline(tor, Max_size, '$');
	a.setAuthor(tor);
	fin1.read((char *)&tmp, sizeof(tmp));
	a.setYear(tmp);
	fin1.read((char *)&tmp, sizeof(tmp));
	a.setNum(tmp);
	fin1.read((char *)&tmp, sizeof(tmp));
	a.setVal(tmp);
	cout << a << endl;
	fin1.close();
}
void outdatafile(Book *A, const int N) {//запись данных из файла в массив
	char tor[255];
	int tmp = 0;
	char q;
	ifstream fin1(f, ios::in | ios::binary);
	for (int i = 0; i < N; i++) {
		fin1.getline(tor, Max_size, '$');
		A[i].setTheme(tor);
		fin1.getline(tor, Max_size, '$');
		A[i].setTitle(tor);
		fin1.getline(tor, Max_size, '$');
		A[i].setAuthor(tor);
		fin1.read((char *)&tmp, sizeof(tmp));
		A[i].setYear(tmp);
		fin1.read((char *)&tmp, sizeof(tmp));
		A[i].setNum(tmp);
		fin1.read((char *)&tmp, sizeof(tmp));
		A[i].setVal(tmp);
		fin1.read((char *)&q, 1);
	}
	fin1.close();
}
void feditBook(Book *A, const int N) {
	outdatafile(A, N);
	editBook(A, N);
	datafile(A, N);
}
void faddBook(Book *A, int N) {
	Book tmp;
	cin >> tmp;
	swap(tmp, A[N]);//добавляю элемент в конец
	N++;
	datafile(A, N);
}
int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	const int size = 50;
	int N = 12;
	Book B[size];
	int n;
	initArray(B, size);
	pmenu Fmenu[15] = { exit, help,
		printList, bookTY,
		bookYear, outListYear,
		outListName, outListAuthor,
		numAllBooks, sumAllVal,
		editBook,feditBook,
		faddBook, datafile, fread };
	while (1) {
		cout << "Введите номер операции:" << "\n";
		cout << "0  - Выход" << "\n";
		cout << "1  - Вывести формулировку задания" << "\n";
		cout << "2  - Весь список книг" << "\n";
		cout << "3  - Вывести список книг по заданной теме, выпущенных после заданного года." << "\n";
		cout << "4  - Вывести список книг заданного автора в порядке возрастания годa издания." << "\n";
		cout << "5  - Получить список всех книг, упорядоченный по году издания \n";
		cout << "6  - Получить список всех книг, упорядоченный по названию \n";
		cout << "7  - Получить список всех книг, упорядоченный по автору \n";
		cout << "8  - Получить количество всех книг \n";
		cout << "9  - Получить общую стоимость всех книг \n";
		cout << "10 - Редактировать книгу\n";
		cout << "11 - Редактировать книгу в файле\n";
		cout << "12 - Добавить книгу в файл\n";
		cout << "13 - Запись данных в файл\n";
		cout << "14 - Просмотреть книгу из файла\n";
		cin >> n;
		if (n < 0 || n>14) {
			cout << "Вы ввели неверное значение. Попробуйте еще раз!" << "\n";
			continue;
		}
		forEach(B, N, Fmenu[n]);
	}
	system("pause");
	return 0;
}