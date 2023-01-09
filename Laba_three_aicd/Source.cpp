#include <iostream>
#include <string>
#include <conio.h>
#include "Header.h"


using namespace std;
void menu_2()
{
	system("cls");
	cout << "1. Создать рандомный вектор" << endl;
	cout << "2. Создать вектор с параметрами" << endl;
	cout << "3. Создать два одинаковых вектора" << endl;


}
void menu()
{
	system("cls");
	cout << "Выберите тип данных" << endl;
	cout << "1. int" << endl;
	cout << "2. double" << endl;
	cout << "3. float" << endl;
	cout << "4. complex<double>" << endl;
	cout << "5. complex<float>" << endl;
}
void menu_3()
{
	system("cls");
	cout << "1. Сложить векторы" << endl;
	cout << "2. Вычесть векторы" << endl;
	cout << "3. Найти скалярное произведение" << endl;
	cout << "4. Разделить вектор на число" << endl;
	cout << "5. Умножить вектор на число" << endl;
	cout << "6. вычислить площадь треугольника" << endl;
	cout << "7. Сравнить вектора" << endl;
	cout << "8. Изменить элемент вектора" << endl;
	cout << "9. Просмотреть элемент вектора" << endl;
	cout << "esc -  выход" << endl;
}
template <class T>
void Nomain()
{
	Vector <T>A;
	Vector <T>B;
	cout << "Хорошо продолжим.." << endl;
	int key = 0;
	while (key != 27)
	{
		menu_2();
		key = _getch();
		switch (key)
		{
		case 49:
		{
			Vector<T> b;
			B = b;
			cout << "Ваши рандомные вектора" << endl << "Вектор А: " << A << endl << "Вектор В: " << B << endl;

			//goto random;
			_getch();
			key = 27;
			break;
		}
		case 50:
		{
			system("cls");
			cout << "Давайте заполгним наши векторы" << endl << "Введите размерность первого вектора" << endl;
			int size_one;
			int size_two;
			double epsilon;
			cin >> size_one;
			cout << "А теперь введем размерность 2 вектора" << endl;
			cin >> size_two;
			cout << "Замечательно, а теперь введите точность сравнения" << endl;
			cin >> epsilon;
			cout << "Самое время заполнить вектора" << endl;
			Vector <T>a(size_one, epsilon);
			cout << endl << "Остался последний вектор" << endl;
			Vector <T>b(size_two, epsilon);
			A = a;
			B = b;
			cout << "Готово, вы справились с этим" << endl << "Вы только поглядите какие они красивые :)" << endl << "Вектор А: " << A << endl << "Вектор В: " << B << endl;
			//goto Par;
			_getch();
			key = 27;
			break;
		}
		case 51:
		{
			system("cls");
			cout << "1. Создать два моих собственных вектора" << endl << "2. Создать два одинаковых и рандомных вектора" << endl;
			key = _getch();
			switch (key)
			{
			case 49:
			{
				int size;
				int epsilon;
				cout << "Давайте заполгним наши векторы" << endl << "Введите размерность векторов" << endl;
				cin >> size;
				cout << "Замечательно, а теперь введите точность сравнения" << endl;
				cin >> epsilon;
				cout << "Самое время заполнить вектора" << endl;
				Vector <T>a(size, epsilon);
				A = a;
				B = a;
				cout << "Готово, вы справились с этим" << endl << "Вы только поглядите какие они красивые :)" << endl << "Вектор А: " << A << endl << "Вектор В: " << B << endl;
				//goto My_copy;
				_getch();
				key = 27;
				break;
			}
			case 50:
			{
				B = A;
				cout << "Ваши рандомные вектора" << endl << "Вектор А: " << A << endl << "Вектор В: " << B << endl;

				//goto random_copy;
				_getch();
				key = 27;
				break;
			}
			}
			_getch();
			break;
		}
		}

	}
	key = 0;
	while (key != 27)
	{
		menu_3();
		cout << "Вектор А: " << A << endl << "Вектор В: " << B << endl;
		key = _getch();
		Vector <T>res;
		switch (key)
		{
		case 49:
		{

			res = A + B;
			cout << "A + B = " << res << endl;
			_getch();
			break;
		}
		case 50:
		{
			while (key != 0) {
				cout << "Шо вычитаем?" << endl << "1. A - B" << endl << "2. B - A" << endl;


				key = _getch();
				if (key == 49) { res = A - B; cout << "A - B = " << res << endl; key = 0; }

				else {
					if (key == 50) { res = B - A; cout << "B - A = " << res << endl;  key = 0; }
					else { cout << "тут только два выбора! :)" << endl; }
				}
			}
			_getch();
			break;
		}
		case 51:
		{
			T x = A * B;
			cout << "A * B = " << x << endl;
			_getch();
			break;
		}
		case 52:
		{
			T x;
			cout << "Введите делитель" << endl;
			cin >> x;
			while (key != 0) {
				cout << "Что делим?" << endl << "1. A / x" << endl << "2. B / x" << endl;


				key = _getch();
				if (key == 49) {
					res = A / x; cout << "A / x = " << res << endl; key = 0;
				}

				else {
					if (key == 50) {
						res = B / x; cout << "B / x = " << res << endl; key = 0;
					}
					else { cout << "тут только два выбора! :)" << endl; }
				}
			}
			_getch();
			break;
		}
		case 53:
		{
			T x;
			cout << "Введите множитель" << endl;
			cin >> x;
			while (key != 0) {
				cout << "Что на что умножаем?" << endl << "1. A * x" << endl << "2. x * B" << endl;


				key = _getch();
				if (key == 49) {
					res = A * x; cout << "A * x = " << res << endl; key = 0;
				}

				else {
					if (key == 50) {
						res = x * B; cout << "x * B = " << res << endl; key = 0;
					}
					else { cout << "тут только два выбора! :)" << endl; }
				}
			}
			_getch();
			break;
		}
		case 54:
		{
			T x;
			x = B.square(A, B);
			cout << "Площадь = " << x << endl;
			_getch();
			break;
		}
		case 55:
		{
			if (A == B) cout << A << "==" << B << endl;
			else cout << A << "!=" << B << endl;
			_getch();
			break;
		}
		case 56:
		{

			cout << "1. Изменить значения вектора 1" << endl << "2. Изменить значения вектора 2" << endl;
			int y;
			int x;
			y = _getch() - 48;
			if (y == 1)
			{
				cout << "Выберите элемент" << A << endl;
				cin >> x;
				T temp = A[x];
				cout << "Введите новое значение" << endl;
				cin >> A[x];
				cout << "предыдущее значение: " << temp << "изменено на " << A[x] << endl;

			}
			else
			{
				if (y == 2)
				{
					cout << "Выберите элемент" << B << endl;
					cin >> x;
					T temp = B[x];
					cout << "Введите новое значение" << endl;
					cin >> B[x];
					cout << "предыдущее значение: " << temp << "изменено на " << B[x] << endl;
				}
				else
				{
					cout << "У вас только два выбора! Красная или синия таблетка?" << endl;
					_getch();

				}
			}

			_getch();
			break;
		}
		case 57:
		{
			system("cls");
			cout << "1. Просмотреть значения вектора 1" << endl << "2. Просмотреть значения вектора 2" << endl;
			int x;
			cin >> x;
			if (x == 1)
			{
				cout << A << endl << "какое число вы хотите лицезреть??" << endl;
				cin >> x;
				cout << A[x];
				_getch();

			}
			else
			{
				if (x == 2)
				{
					cout << B << endl << "какое число вы хотите лицезреть??" << endl;
					cin >> x;
					cout << B[x];
					_getch();

				}
				else {
					cout << "У вас только два выбора! Красная или синия таблетка?" << endl;
					_getch();

				}
			}
		}
		case 27:
		{
			system("cls");
			break;
		}
		}
	}
}
template <class V>
void Nomain_complex()
{
	Vector <complex<V>>A;
	Vector <complex<V>>B;
	cout << "Хорошо продолжим.." << endl;
	int key = 0;
	while (key != 27)
	{
		menu_2();
		key = _getch();
		switch (key)
		{
		case 49:
		{
			Vector <complex<V>> b;
			B = b;
			cout << "Ваши рандомные вектора" << endl << "Вектор А: " << A << endl << "Вектор В: " << B << endl;

			//goto random;
			_getch();
			key = 27;
			break;
		}
		case 50:
		{
			system("cls");
			cout << "Давайте заполгним наши векторы" << endl << "Введите размерность первого вектора" << endl;
			int size_one;
			int size_two;
			double epsilon;
			cin >> size_one;
			cout << "А теперь введем размерность 2 вектора" << endl;
			cin >> size_two;
			cout << "Замечательно, а теперь введите точность сравнения" << endl;
			cin >> epsilon;
			cout << "Самое время заполнить вектора" << endl;
			Vector <complex<V>> a(size_one, epsilon);
			cout << endl << "Остался последний вектор" << endl;
			Vector <complex<V>> b(size_two, epsilon);
			A = a;
			B = b;
			cout << "Готово, вы справились с этим" << endl << "Вы только поглядите какие они красивые :)" << endl << "Вектор А: " << A << endl << "Вектор В: " << B << endl;
			//goto Par;
			_getch();
			key = 27;
			break;
		}
		case 51:
		{
			system("cls");
			cout << "1. Создать два моих собственных вектора" << endl << "2. Создать два одинаковых и рандомных вектора" << endl;
			key = _getch();
			switch (key)
			{
			case 49:
			{
				int size;
				complex<V> epsilon;
				cout << "Давайте заполгним наши векторы" << endl << "Введите размерность векторов" << endl;
				cin >> size;
				cout << "Замечательно, а теперь введите точность сравнения" << endl;
				cin >> epsilon;
				cout << "Самое время заполнить вектора" << endl;
				Vector <complex<V>> a(size, epsilon);
				A = a;
				B = a;
				cout << "Готово, вы справились с этим" << endl << "Вы только поглядите какие они красивые :)" << endl << "Вектор А: " << A << endl << "Вектор В: " << B << endl;
				//goto My_copy;
				_getch();
				key = 27;
				break;
			}
			case 50:
			{
				B = A;
				cout << "Ваши рандомные вектора" << endl << "Вектор А: " << A << endl << "Вектор В: " << B << endl;

				//goto random_copy;
				_getch();
				key = 27;
				break;
			}
			}
			_getch();
			break;
		}
		}

	}
	key = 0;
	while (key != 27)
	{
		menu_3();
		cout << "Вектор А: " << A << endl << "Вектор В: " << B << endl;
		key = _getch();
		Vector <complex<V>>res;
		switch (key)
		{
		case 49:
		{

			res = A + B;
			cout << "A + B = " << res << endl;
			_getch();
			break;
		}
		case 50:
		{
			while (key != 0) {
				cout << "Шо вычитаем?" << endl << "1. A - B" << endl << "2. B - A" << endl;


				key = _getch();
				if (key == 49) { res = A - B; cout << "A - B = " << res << endl; key = 0; }

				else {
					if (key == 50) { res = B - A; cout << "B - A = " << res << endl;  key = 0; }
					else { cout << "тут только два выбора! :)" << endl; }
				}
			}
			_getch();
			break;
		}
		case 51:
		{
			complex<V> x = A * B;
			cout << "A * B = " << x.real() << endl;
			_getch();
			break;
		}
		case 52:
		{
			V x;
			cout << "Введите делитель" << endl;
			cin >> x;
			while (key != 0) {
				cout << "Что делим?" << endl << "1. A / x" << endl << "2. B / x" << endl;


				key = _getch();
				if (key == 49) {
					res = A / x; cout << "A / x = " << res << endl; key = 0;
				}

				else {
					if (key == 50) {
						res = B / x; cout << "B / x = " << res << endl; key = 0;
					}
					else { cout << "тут только два выбора! :)" << endl; }
				}
			}
			_getch();
			break;
		}
		case 53:
		{
			V x;
			cout << "Введите множитель" << endl;
			cin >> x;
			while (key != 0) {
				cout << "Что на что умножаем?" << endl << "1. A * x" << endl << "2. x * B" << endl;


				key = _getch();
				if (key == 49) {
					res = A * x; cout << "A * x = " << res << endl; key = 0;
				}

				else {
					if (key == 50) {
						res = x * B; cout << "x * B = " << res << endl; key = 0;
					}
					else { cout << "тут только два выбора! :)" << endl; }
				}
			}
			_getch();
			break;
		}
		case 54:
		{
			V x;
			x = B.square(A, B);
			cout << "Площадь = " << x << endl;
			_getch();
			break;
		}
		case 55:
		{
			if (A == B) cout << A << "==" << B << endl;
			else cout << A << "!=" << B << endl;
			_getch();
			break;
		}
		case 56:
		{

			cout << "1. Изменить значения вектора 1" << endl << "2. Изменить значения вектора 2" << endl;
			int y;
			int x;
			y = _getch() - 48;
			if (y == 1)
			{
				cout << "Выберите элемент" << A << endl;
				cin >> x;
				complex<V> temp = A[x];
				cout << "Введите новое значение" << endl;
				cin >> A[x];
				cout << "предыдущее значение: " << temp << "изменено на " << A[x] << endl;

			}
			else
			{
				if (y == 2)
				{
					cout << "Выберите элемент" << B << endl;
					cin >> x;
					complex<V> temp = B[x];
					cout << "Введите новое значение" << endl;
					cin >> B[x];
					cout << "предыдущее значение: " << temp << "изменено на " << B[x] << endl;
				}
				else
				{
					cout << "У вас только два выбора! Красная или синия таблетка?" << endl;
					_getch();

				}
			}

			_getch();
			break;
		}
		case 57:
		{
			system("cls");
			cout << "1. Просмотреть значения вектора 1" << endl << "2. Просмотреть значения вектора 2" << endl;
			int x;
			cin >> x;
			if (x == 1)
			{
				cout << A << endl << "какое число вы хотите лицезреть??" << endl;
				cin >> x;
				cout << A[x];
				_getch();

			}
			else
			{
				if (x == 2)
				{
					cout << B << endl << "какое число вы хотите лицезреть??" << endl;
					cin >> x;
					cout << B[x];
					_getch();

				}
				else {
					cout << "У вас только два выбора! Красная или синия таблетка?" << endl;
					_getch();

				}
			}
		}
		case 27:
		{
			system("cls");
			break;
		}
		}
	}
}
int get_key()
{
	int key;
	key = _getch();
	system("cls");
	return key;
}

int main()
{
	int key = 0;
	while (key != 27)
	{
		setlocale(LC_ALL, "Rus");
		int size;

		try
		{
			while (key != 27)
			{
				while (key != 27)
				{
					menu();
					key = get_key();
					switch (key)
					{
					case 49:
					{
						Nomain<int>();
						_getch();
						break;
					}

					case 50:
					{
						Nomain<double>();
						_getch();
						break;
					}
					case 51:
					{
						Nomain<float>();
						_getch();
						break;
					}
					case 52:
					{
						Nomain_complex<double>();
						_getch();
						break;
					}
					case 53:
					{
						Nomain_complex<float>();
						_getch();
						break;
					}
					}

				}
			}
		}
		catch (invalid_argument err)
		{
			cout << "invalid argument: " << err.what() << std::endl;
			_getch();
		}
		catch (out_of_range err)
		{
			cout << "Our of range " << err.what() << std::endl;
			_getch();
		}
		catch (logic_error err)
		{
			cout << "Logic error: " << err.what() << std::endl;
			_getch();
		}

	}
}

//int main()
//{
//	setlocale(LC_ALL, "Rus");
//	Vector <int> t;
//	cout << t << endl;
//
//	Vector <double> temp(3,1);
//	cout << temp;
//
//	Vector<double> x(temp);
//	cout << x;
//
//	Vector<double> rav;
//	rav = temp;
//	cout << rav;
//	
//	Vector <double>res = rav + x;
//	cout << endl <<"a + b" << res;
//}