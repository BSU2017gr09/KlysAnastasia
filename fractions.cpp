//Класс дроби, состоящий из двух объектов: числитель и знаменатель.
#include <iostream>
using namespace std;
class Fraction
{
public:
	int num;
	int den;
	Fraction() :num(0), den(1) {
		//cout << "Работает конструктор по умолчанию" << '\n';
	}
	~Fraction() {
		//cout << "Работает дeструктор";
	}
	Fraction(Fraction &other) {
		num = other.num;
		den = other.den;
		//cout << "Работает copy конструктор" << endl;
	}
	Fraction(int a, int b = 1) :num(a), den(b) {
		//cout << "Работает конструктор с параметрами" << endl;
	}
	friend ostream& operator<< (ostream &mystream, Fraction &tmp) {
		mystream << tmp.num << "/" << tmp.den;
		return mystream;
	}
	friend istream& operator>> (istream &mystream, Fraction &tmp) {// странное имя tmp
		cout << "Введите числитель: " << endl;
		mystream >> tmp.num;
		cout << "Введите знаменатель: " << endl;
		mystream >> tmp.den;
		if ((tmp.num < 0 && tmp.den < 0) || (tmp.den < 0 && tmp.num>0)) {
			tmp.num = -tmp.num;
			tmp.den = -tmp.den;
		}
		if (tmp.den == 0) {
			cout << "Вы ввели недопустимое значение. Работать с такой дробью невозможно.";
			exit(0); // ну, вот прямо надо exit ))))) 
		}
		return mystream;
	}
	void operator= (const Fraction &other) {
		num = other.num;
		den = other.den;
		//cout << "работает операция присваивания ";
	}
	Fraction operator*(const Fraction &other) {
		Fraction tmp;
		tmp.num = this->num * other.num;
		tmp.den = this->den * other.den;
		return tmp;
	}
	Fraction operator+(const Fraction &other) {
		Fraction tmp;
		if (this->den == other.den) {
			tmp.num = this->num + other.num;
			tmp.den = this->den;
			return tmp;
		}
		else {

			tmp.num = this->num*((this->den*other.den) / this->den) + other.num*((this->den*other.den) / other.den);
			tmp.den = this->den*other.den;
			return tmp;
		}
	}
	Fraction operator-(const Fraction &other) {
		Fraction tmp;
		if (this->den == other.den) {
			tmp.num = this->num - other.num;
			tmp.den = this->den;
			return tmp;
		}
		else {
			tmp.num = this->num*((this->den*other.den) / this->den) - other.num*((this->den*other.den) / other.den);
			tmp.den = this->den*other.den;
			return tmp;
		}
	}
	Fraction operator/(const Fraction &other) {
		Fraction tmp;
		tmp.num = this->num * other.den;
		tmp.den = this->den * other.num;
		return tmp;
	}
	bool operator>(const Fraction &other) {
		if ((this->num*((this->den*other.den) / this->den) - other.num*((this->den*other.den) / other.den)) > 0) {
			return true;
		}
		else return false;
	}
	bool operator<(const Fraction &other) {
		if ((this->num*((this->den*other.den) / this->den) - other.num*((this->den*other.den) / other.den)) < 0) {
			return true;
		}
		else return false;
	}
	bool operator==(const Fraction &other) {
		if ((this->num*((this->den*other.den) / this->den) - other.num*((this->den*other.den) / other.den)) == 0) {
			return true;
		}
		else return false;
	}
};
int main() {
	setlocale(LC_ALL, "ru");
	Fraction a, b, c(2);
	// массив бы еще... И его, например проинициализировать и отсортировать.... Или еще что то
	cout << "Введите дробь: " << endl;
	cin >> a;
	cout << "Введите дробь: " << endl;
	cin >> b;
	cout << "Сложение: " << a + b << "\n";
	cout << "Вычитание: " << a - b << "\n";
	cout << "Произведение: " << a*b << "\n";
	cout << "Деление: " << a / b << "\n";
	if (a > b) cout << "a<b" << "\n";
	else {
		if (a < b) cout << "a<b" << "\n";
		else cout << "a = b" << "\n";
	}
	if (b == c) cout << "b = c" << "\n";
	system("pause");
	return 0;
}
