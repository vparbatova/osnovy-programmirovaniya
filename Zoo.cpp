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
		else cout << "��� ������ ��������";
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
		react = "���!";
		talk = "����� ������� ����������";
		eat = "�������, ����� ������!";
		cout << "������� ��������\n" << "1 - ���������, 2 - ����������, 3 - ������";
		cin >> act;
		Povedenie(act);
	}
};
class Tiger : public Animal
{
public:
	void Deyst()
	{
		react = "������� ����";
		talk = "��������";
		eat = "�����, ������ ����� � ��������� ���������";
		cout << "������� ��������\n" << "1 - ���������, 2 - ����������, 3 - ������";
		cin >> act;
		Povedenie(act);
	}
};
class Cat : public Animal
{
public:
	void Deyst()
	{
		react = "���";
		talk = "���";
		eat = "�������";
		cout << "������� ��������\n" << "1 - ���������, 2 - ����������, 3 - ���������\n";
		cin >> act;
		Povedenie(act);
	}
};
int main()
{
	setlocale(LC_ALL, "rus");

	int pers;
	cout << "������� ��������\n" << "1 - �������, 2 - ����, 3 - �����\n";
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