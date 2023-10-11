#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int a, b;
std::string deystvie;
int sum(int a, int b);
int razn(int a, int b);
int mnoj(int a, int b);
float del(int a, int b);
int step(int a, int b);
float koren(int a, int b);

int main()
{
	setlocale(LC_ALL, "RU");
	std::cout << "Введите операцию (+, -, //, *, ^, sqrt):" << "\n";
	std::cin >> deystvie;
	if (deystvie == "+")
	{
		cout << "Введите 2 числа:" << "\n";
		cout << sum(a, b) << "\n";
	}
	if (deystvie == "-")
	{
		cout << "Введите 2 числа, сначала уменьшаемое, потом вычитаемое:" << "\n";
		cout << razn(a, b) << "\n";
	}
	if (deystvie == "*")
	{
		cout << "Введите 2 числа:" << "\n";
		cout << mnoj(a, b) << "\n";
	}
	if (deystvie == "^")
	{
		cout << "Введите 2 числа, сначала основание, потом степень:" << "\n";
		cout << step(a, b) << "\n";
	}
	if (deystvie == "sqrt")
	{
		cout << "Введите 2 числа, сначала подкоренное выражение, потом степень корня:" << "\n";
		cout << koren(a, b) << "\n";
	}
	if (deystvie == "//")
	{
		cout << "Введите 2 числа, сначала делимое, потом делитель:" << "\n";
		cout << del(a, b) << "\n";
	}
	else
	{
		cout << "Недопустимый оператор";
	}
	return 0;
}

int sum(int a, int b)
{
	cin >> a >> b;
	return (a + b);
}
int razn(int a, int b)
{
	cin >> a >> b;
	return (a - b);
}
int mnoj(int a, int b)
{
	cin >> a >> b;
	return (a * b);
}
float del(int a, int b)
{
	cin >> a >> b;
	if (b == 0)
	{
		while (b == 0)
		{
			cout << "Введите другой делитель:" << "\n";
			cin >> b;
		}
	}
	return (a * 1.0) / (b*1.0);
}
int step(int a, int b)
{
	cin >> a >> b;
	return pow(a, b);
}
float koren(int a, int b)
{
	cin >> a >> b;
	if (a < 0 and b % 2 == 0)
	{
		while (a < 0 and b % 2 == 0)
		{
			cout << "Невозможная операция, изменитие данные:";
			cin >> a;
			cin >> b;
		}
	}
	return pow(a*1.0, 1/(b*1.0));
}