#pragma once
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <cmath>
#include <complex>
#include <stdexcept>
#include <vector>
using namespace std;

template <typename T>
class Vector {
private:
	vector<T> data;
	int _size;
	T epsilon;
public:

	Vector() { //конструктор по умолчаниюю
		srand(time(0));
		_size = rand() % 3 + 10;
		epsilon = 0, 000001;
		data = vector<T> (_size);
		for (size_t i = 0; i < _size; i++)
		{
			data.at(i) = ((T)rand()) / 300 - 100;
		}

	}

	Vector(int size, T eps) { // конструктор с параметром
		if (size < 1) throw invalid_argument("Недопустимое значение");
		_size = size;
		epsilon = abs(eps);
		data = vector<T>(_size);
		cout << "Введите значение:\n";
		long double a;
		for (size_t i = 0; i < _size; i++)
		{
			cout << "A[" << i << "] = ";
			cin >> a;
			data.at(i) = (T)a;
		}
	}
	Vector(const Vector& a) = default;
	//  { // конструктор копирования
	//	_size = a._size;
	//	data = new T[_size];
	//	epsilon = a.epsilon;
	//	for (size_t i = 0; i < _size; i++)
	//	{
	//		data[i] = a.data[i];
	//	}
	// }
	~Vector() = default;
	//void Vprint() // ìåòîä âûâîäà
	//{
	//	for (size_t i = 0; i < _size; i++)
	//	{
	//		cout << "A[" << i << "] = " << data[i];
	//	}
	//	cout << "/n";
	//}
	int Get_size() { return _size; }
	/*	double operator()(int i) const {
			if (i<0 or i>_size) throw "Invalid index";
			return data[i];
		}
		double& operator()(int i) {
			if (i<0 or i>_size)  throw "Invalid index";
			return data[i];
		}
	*/
	T operator[](int i) const { //×Òåíèå è çàïèñü
		if (i<0 or i>_size - 1) throw out_of_range("Недопустимое значение");
		return data[i];
	}

	T& operator[](int i) {
		if (i<0 or i>_size - 1)  throw out_of_range("Недопустимое значение");
		return data[i];
	}
	friend ostream& operator<<(ostream& os, const Vector& a)
	{
		/*for (int i = 0; i < a._size; ++i)
		{
			os << left << a.data[i] << ' ';
		}
		return os;*/
	/*	for (auto it = a.data.begin(); it != a.data.end(); ++it)
		{
			os << left << *it << ' ';
		}*/
		for (const auto& n : a.data) {
			os << n << " ";
		}
		return os;
	}
	bool operator==(const Vector& a) {
		if (_size != a._size) {
			return false;
		}
		else {
			for (size_t i = 0; i < _size; i++)
			{
				if (fabs(data[i] - a.data[i]) > epsilon) {
					return false;
				}
			}
		}
		return true;
	}
	bool operator!=(const Vector& a) {
		return !(*this == a);
	}

	Vector& operator=(const Vector& a) = default;
	//{
	//	//Vector<T> temp;
	//	_size = a._size;
	//	epsilon = a.epsilon;
	//	for (size_t i = 0; i < a._size; i++)
	//	{
	//		data[i] = a.data[i];
	//	}
	//	return *this;
	//}
	Vector& operator+=(const Vector& a) {		//сложение векторов
		if (_size != a._size) throw logic_error("Невозможжно сложить векторы разной длины");
		for (size_t i = 0; i < _size; i++)
		{
			data[i] += a.data[i];
		}
		return *this;
	}
	Vector operator+(const Vector& a) const { // *this + a 
		Vector temp(*this);
		temp += a;
		//cout << temp << endl;
		Vector tmp(temp);
		return tmp;
	}
	Vector operator-=(const Vector a) {
		if (_size != a._size) throw logic_error("Невозможжно вычесть векторы разной длины");
		for (size_t i = 0; i < _size; i++)
		{
			data[i] -= a.data[i];
		}
		return *this;
	}
	Vector operator-(const Vector& a) const { //вычитание векторов
		Vector temp(*this);
		temp -= a;
		//cout << temp << endl;
		return temp;
	}
	Vector& operator*=(const Vector& a) { //*this это наш переданный темп, а а соотвтвествеенно как аргумент а
		if (_size != a._size) throw logic_error("Невозможжно умн векторы разной длины");
		for (size_t i = 0; i < _size; i++)
		{
			data[i] *= a.data[i];
		}
		return *this;
	}
	T operator*(const Vector& a) const { // скалярное
		Vector<T> temp(*this);
		temp *= a;
		//cout << temp << endl;
		T scalar = 0;
		for (const auto& n : a.data) 
		{
			scalar += n;
		}
		return scalar;
	}
	Vector& operator*=(const T a) { // Вектор на число
		for (auto& n : data)
		{
			n *= a;
		}
		return *this;
	}
	Vector operator*(const T a) const { // 
		Vector temp(*this);
		temp *= a;
		//cout << temp << endl;
		return temp;
	}
	friend Vector operator*(const T b, const Vector& a) { // число на вектор
		Vector temp(a);
		temp *= b;
		//cout << temp << endl;
		return temp;
	}

	/*Vector& operator/=(const Vector& a) { //*this ýòî íàø ïåðåäàííûé òåìï, à à ñîîòâòâåñòâååííî êàê àðãóìåíò à
		if (_size != a._size) throw "Íåâîçìîææíî ðàçäåëèòü âåêòîðû";
		for (size_t i = 0; i < _size; i++)
		{
			if (a.data[i] == 0) throw "íåëüçÿ äåëèòü íà íîëü";
			data[i] /= a.data[i];
		}
		return *this;
	}
	Vector operator/(const Vector& a) const { // *this + a
		Vector temp(*this);
		temp /= a;
		//cout << temp << endl;
		return temp;
	}
	*/
	Vector& operator/=(const T a) {
		if (a == 0) throw logic_error("Невозможно делит 0");
		for (auto& n : data)
		{
			n /= a;
		}
		return *this;
	}
	Vector operator/(const T a) const { // *this + a 
		Vector temp(*this);
		temp /= a;
		//cout << temp << endl;
		return temp;
	}
	static T square(Vector& a, Vector& b)// âû÷èñëåíèå ïëîùàäè òðåóãîëüíèêà ÷åðçå 2 âåêòîðà
	{
		return 0.5 * sin(a, b) * length(a, b);
	}
	static T sin(Vector a, Vector b) //âû÷åñëåíèå ñèíóñà äëÿ ïëîùàäè
	{
		if (a._size != b._size) throw logic_error("Íåâîçìîææíî âû÷èñëèòü ñèíóñ ìåæäó âåêòîðàìè ðàçíîé ðàçìåðíîñòè");
		T chislitel = 0;
		T temp = 0, tmp = 0;
		T znamenatel = 1;
		//for (size_t i = 0; i < a._size; i++)
		//{
		chislitel = a * b;

		//}
		for (size_t i = 0; i < a._size; i++)
		{
			temp += pow(a.data[i], 2);
			tmp += pow(b.data[i], 2);
		}
		temp = sqrt(temp);
		tmp = sqrt(tmp);
		znamenatel = temp * tmp;
		return sqrt(1 - pow((chislitel / znamenatel), 2));
	}
	static T length(Vector a, Vector b) //âû÷åñëåíèå ïðîèçâåäåíèÿ äëèí âåêòîðîâ
	{
		T temp = 0;
		T tmp = 0;
		for (size_t i = 0; i < a._size; i++)
		{
			temp += pow(a.data[i], 2);
			tmp += pow(b.data[i], 2);
		}
		temp = sqrt(temp);
		tmp = sqrt(tmp);
		return temp * tmp;
	}
};
template <typename V>
class Vector <complex<V>>
{
private:
	vector<complex<V>> data;
	int _size;
	complex<V> epsilon;
public:
	Vector() { //êîíñòðóêòîð ïî óìîë÷àíèþþ
		srand(time(0));
		_size = rand() % 3 + 10;
		epsilon = complex<V>(0.0001, 0.00001);
		data = vector<complex<V>>(_size);
		for (size_t i = 0; i < _size; i++)
		{
			data.at(i) = complex<V>((V)rand() / 3, (V)rand() / 4);
		}

	}

	Vector(int size, complex<V> eps) { // êîíñòðóêòîð ñ ïàðàìåòðîì
		if (size < 1) throw invalid_argument("Íåäîïóñòèìîå çíà÷åíèå");
		_size = size;
		data = vector<complex<V>>(size);
		cout <<"ВВедите точность" << "Введите значения в виде (число,число):\n";
		epsilon = eps;
		for (size_t i = 0; i < size; i++)
		{
			cin >> data[i];
		}
	}
	Vector(const Vector<complex<V>>& a) = default;
	
	~Vector() = default;
	friend ostream& operator<<(ostream& os, const Vector<complex<V>>& a) //âûâîä
	{
		for (const auto& n : a.data) {
			os << n << " ";
		}
		return os;
	}
	friend ostream& operator>>(ostream& os, complex<V>& x)
	{
		V a;
		V b;
		cout << "ВВедите реально значение";
		cin >> a;
		cout << "Введите мнимое значение";
		cin >> b;
		x = complex<V>(a, b);

	}
	int Get_size() { return _size; }
	complex<V> operator[](int i) const { //×Òåíèå è çàïèñü
		if (i<0 or i>_size - 1) throw out_of_range("Invalid index");
		return data[i];
	}

	complex<V>& operator[](int i) {
		if (i<0 or i>_size - 1)  throw out_of_range("Invalid index");
		return data[i];
	}

	bool operator==(const Vector<complex<V>>& a) {				//Îïåðàòîðû ñðàâíåíèÿ
		if (_size != a._size) {
			return false;
		}
		else {
			for (size_t i = 0; i < _size; i++)
			{
				if ((data[i].real() - a.data[i].real()) > epsilon.real()) {

					return false;
				}
				if ((data[i].imag() - a.data[i].imag()) > epsilon.imag()) {

					return false;
				}
			}
		}
		return true;
	}
	Vector& operator=(const Vector& a) = default;
	//{
	//	_size = a._size;
	//	for (size_t i = 0; i < _size; i++)
	//	{
	//		data[i] = a.data[i];
	//	}
	//	return *this;
	//}

	Vector<complex<V>>& operator+=(const Vector<complex<V>>& a) {		//Ñëîæåíèå âåêòîðîâ
		if (_size != a._size) throw logic_error("Íåâîçìîææíî ñëîæèòü âåêòîðû ðàçíîé äëèíû");
		for (size_t i = 0; i < _size; i++)
		{
			data[i] += a.data[i];
		}
		return *this;
	}
	Vector<complex<V>> operator+(const Vector<complex<V>>& a) const { // *this + a 
		Vector temp(*this);
		temp += a;
		//cout << temp << endl;
		Vector tmp(temp);
		return tmp;
	}
	Vector<complex<V>>& operator-=(const Vector<complex<V>>& a) {
		if (_size != a._size) throw logic_error("Íåâîçìîææíî âû÷åñòü âåêòîðû ðàçíîé äëèíû");
		for (size_t i = 0; i < _size; i++)
		{
			data[i] -= a.data[i];
		}
		return *this;
	}
	Vector<complex<V>> operator-(const Vector<complex<V>>& a) const { //âû÷èòàíèå âåêòîðîâ
		Vector temp(*this);
		temp -= a;
		//cout << temp << endl;
		return temp;
	}
	Vector<complex<V>>& operator*=(const Vector<complex<V>>& a) { //*this ýòî íàø ïåðåäàííûé òåìï, à à ñîîòâòâåñòâååííî êàê àðãóìåíò à
		if (_size != a._size) throw logic_error("Íåâîçìîææíî óìíîæèòü âåêòîðû ðàçíîé äëèíû");
		for (size_t i = 0; i < _size; i++)
		{
			data[i] *= a.data[i];
		}
		return *this;
	}
	complex<V> operator*(const Vector<complex<V>>& a) const { // ñêàëÿðíîå óìíîæåíèå ÂÅÊÒÎÐÎÂ
		Vector <complex<V>>temp(*this);
		//cout << temp << endl;
				//новое!!!!

		Vector<complex<V>>tmp(a);
		for (size_t i = 0; i < tmp.Get_size(); i++)
		{
			V real = tmp[i].real();
			V imag = tmp[i].imag();
			complex<V> copy(real, -imag);
			//cout << copy;
			tmp[i] = copy;
		}
		temp *= tmp;
		complex<V>scalar(0, 0);
		for (size_t i = 0; i < _size; i++)
		{
			scalar += temp.data[i];
		}
		return scalar;
	}
	Vector<complex<V>>& operator*=(const complex<V> a) { // ÂÅÊÒÎÐ íà ÷èñëî
		for (auto& n : data)
		{
			n *= a;
		}
		return *this;
	}
	Vector<complex<V>> operator*(const complex<V> a) const { // 
		Vector <complex<V>>temp(*this);
		temp *= a;
		//cout << temp << endl;
		return temp;
	}
	friend Vector<complex<V>> operator*(const complex<V> b, const Vector<complex<V>>& a) { // ×èñëî íà âåêòîð
		Vector <complex<V>>temp(a);
		temp *= b;
		//cout << temp << endl;
		return temp;
	}
	Vector<complex<V>>& operator/=(const complex<V> a) { //*this ýòî íàø ïåðåäàííûé òåìï, à à ñîîòâòâåñòâååííî êàê àðãóìåíò à
		if (a.real() == 0 && a.imag() == 0) throw "Íåâîçìîææíî ðàçäåëèòü âåêòîðû";
		for (auto& n : data)
		{
			n /= a;
		}
		return *this;
	}
	Vector<complex<V>> operator/(const complex<V> a) const { // *this \ a 
		if (a.real() == 0 && a.imag() == 0) throw logic_error("нельзя делить на (0,0)");

		Vector<complex<V>> temp(*this);
		temp /= a;
		//cout << temp << endl;
		return temp;
	}
	static V square(Vector<complex<V>>& a, Vector<complex<V>>& b)// âû÷èñëåíèå ïëîùàäè òðåóãîëüíèêà ÷åðçå 2 âåêòîðà
	{
		complex<V> x(0.5, 0);
		x = x * sin(a, b) * length(a, b);
		return x.real();
	}
	static complex<V> sin(Vector<complex<V>> a, Vector<complex<V>> b) //âû÷åñëåíèå ñèíóñà äëÿ ïëîùàäè
	{
		if (a._size != b._size) throw logic_error("Íåâîçìîææíî âû÷èñëèòü ñèíóñ ìåæäó âåêòîðàìè ðàçíîé ðàçìåðíîñòè");
		complex<V> numerator(0, 0);
		complex<V> temp(0, 0);
		complex<V> tmp(0, 0);
		complex<V> denominator(1, 0);
		//for (size_t i = 0; i < a._size; i++)
		//{
		numerator = a * b;
		//}
		for (size_t i = 0; i < a._size; i++)
		{
			temp += pow(a.data[i], 2);
			tmp += pow(b.data[i], 2);
		}
		temp = sqrt(temp);
		tmp = sqrt(tmp);
		denominator = temp * tmp;
		complex<V> w(1, 0);
		complex<V> q(2, 0);
		complex<V> res = sqrt(w - pow(numerator / denominator, q));

		return res.real();
	}
	static complex<V> length(Vector<complex<V>> a, Vector<complex<V>> b) //âû÷åñëåíèå ïðîèçâåäåíèÿ äëèí âåêòîðîâ
	{
		complex<V> temp(0, 0);
		complex<V> tmp(0, 0);
		for (size_t i = 0; i < a._size; i++)
		{
			temp += pow(a.data[i], 2);
			tmp += pow(b.data[i], 2);
		}
		temp = sqrt(temp);
		tmp = sqrt(tmp);
		return temp * tmp;
	}
};