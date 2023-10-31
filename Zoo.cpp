#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
	string react, eat, talk;
	int act;
	void Povedenie(int act) 
	{
		if (act <= 3) this->act = act;
		else cout << "Нет такого действия";
		if (act == 1)
		{
			cout << react;
		}
		if (act == 2)
		{
			cout << talk;
		}
		if (act == 3)
		{
			cout << eat;
		}
	}
};

class Popygay : public Animal
{
public:
	void Deyst()
	{
		react = "Ура!";
		talk = "Очень приятно пообщаться";
		eat = "Спасибо, очень вкусно!";
		cout << "Введите действие\n" << "1 - погладить, 2 - поговорить, 3 - поесть";
		cin >> act;
		Povedenie(act);
	}
};
class Tiger : public Animal
{
public:
	void Deyst()
	{
		react = "Откусил руку";
		talk = "Рррррррр";
		eat = "Ладно, теперь может и погладить получится";
		cout << "Введите действие\n" << "1 - погладить, 2 - поговорить, 3 - поесть";
		cin >> act;
		Povedenie(act);
	}
};
class Cat : public Animal
{
public:
	void Deyst()
	{
		react = "Мур";
		talk = "Мяу";
		eat = "Спасибо";
		cout << "Введите действие\n" << "1 - погладить, 2 - поговорить, 3 - покормить\n";
		cin >> act;
		Povedenie(act);
	}
};
int main()
{
	setlocale(LC_ALL, "rus");

	int pers;
	cout << "Введите животное\n" << "1 - попугай, 2 - тигр, 3 - кошка\n";
	cin >> pers;
	if (pers == 1)
	{
		Popygay pers;
		pers.Deyst();
	}
	if (pers == 2)
	{
		Tiger pers;
		pers.Deyst();
	}
	if (pers == 3)
	{
		Cat pers;
		pers.Deyst();
	}
	return 0;
}