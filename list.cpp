#include <iostream>
#include <string>
using namespace std;

struct tovar
{
	string name;
	float price;
	int amount;
	tovar* next;
};

void addfirst(tovar *&tlist, string n, float p, int am)
{
	tovar* tmp = new tovar;
	tmp->name = n;
	tmp->price = p;
	tmp->amount = am;
	tmp->next = tlist;
	tlist = tmp;
	return;
}

int addafter(tovar *tlist, string n, float p, int am, string nafter)
{
	if (tlist == NULL) return 1;
	tovar *tmp = tlist;
	while (tmp != NULL && tmp->name != nafter)
	{
		tmp = tmp->next;
	}
	if (tmp == NULL) return 1;
	tovar* newtovar = new tovar;
	newtovar->name = n;
	newtovar->price = p;
	newtovar->amount = am;
	newtovar->next = tmp->next;
	tmp->next = newtovar;
	return 0;
}

int addbefor(tovar *&tlist, string n, float p, int am, string nbefore)
{
	if (tlist == NULL) return 1;
	tovar* tmp = tlist;
	tovar* pred = NULL;
	if (tmp->name == nbefore)
	{
		addfirst(tlist, n, p, am);
		return 0;
	}
	while (tmp->name != nbefore && tmp != NULL)
	{
		pred = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL) return 1;
	tovar* newtovar = new tovar;
	newtovar->name = n;
	newtovar->price = p;
	newtovar->amount = am;
	newtovar->next = tmp;
	pred->next = newtovar;
	return 0;
}

void printlist(tovar*tlist)
{
	if (tlist == NULL)
	{
		cout << "Список пуст" << endl;
	}
	else
	{
		while (tlist != NULL)
		{
			cout << "Имя: " << tlist->name << "; Цена: "<< tlist->price << "; Количество: " << tlist->amount << endl;
			tlist = tlist->next;
		}
	}
}

void addlast(tovar*&tlist, string n, float p, int am)
{
	tovar* tmp = tlist;
	if (tlist != nullptr)
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		addafter(tlist, n, p, am, tmp->name);
		return;
	}
	addfirst(tlist, n, p, am);
	return;
	
}

int deltovar(tovar*& tlist, string n)
{
	if (tlist == NULL) return 1;
	tovar* tmp = tlist;
	if (tlist->name == n)
	{
		tlist = tlist->next;
		delete tmp;
		return 0;
	}
	if (tlist->next == NULL) return 1;
	tovar* pred = tlist;
	tmp = tlist->next;
	while (tmp->next != NULL && tmp->name != n)
	{
		pred = tmp;
		tmp = tmp->next;
	}
	pred->next = tmp->next;
	delete tmp;
}

int main()
{
	setlocale(LC_ALL, "RU");
	int d = 100;
	string n;
	string n1;
	float p;
	int am;
	tovar* tlist;
	tlist = NULL;
	while (d != 0)
	{
		system("pause && cls");
		cout << "0 - Завершение" << endl;
		cout << "1 - Добавление в начало" << "\n" << "2 - Добавление после заданого" << "\n" << "3 - Вывод на экран" << endl << "4 - Добавление до" << endl << "5 - Добавление в конец" << endl << "6 - Удаление" << endl;
		cin >> d;
		if (d == 1)
		{
			cout << "Введите название товара" << endl;
			cin >> n;
			cout << "Введите цену товара" << endl;
			cin >> p;
			cout << "Введите количество товара" << endl;
			cin >> am;
			addfirst(tlist, n, p, am);
		}
		else if (d == 2)
		{
			cout << "Введите название товара, после которого хотите добавить" << endl;
			cin >> n1;
			cout << "Введите название товара" << endl;
			cin >> n;
			cout << "Введите цену товара" << endl;
			cin >> p;
			cout << "Введите количество товара" << endl;
			cin >> am;
			addafter(tlist, n, p, am, n1);
		}
		else if (d == 3)
		{
			printlist(tlist);
		}
		else if (d == 4)
		{
			cout << "Введите название товара, до которого хотите добавить" << endl;
			cin >> n1;
			cout << "Введите название товара" << endl;
			cin >> n;
			cout << "Введите цену товара" << endl;
			cin >> p;
			cout << "Введите количество товара" << endl;
			cin >> am;
			addbefor(tlist, n, p, am, n1);
		}
		else if (d == 5)
		{
			cout << "Введите название товара" << endl;
			cin >> n;
			cout << "Введите цену товара" << endl;
			cin >> p;
			cout << "Введите количество товара" << endl;
			cin >> am;
			addlast(tlist, n, p, am);
		}
		else if (d == 6)
		{
			cout << "Введие имя удаляемого товара" << endl;
			cin >> n;
			deltovar(tlist, n);
		}
	}
	return 0;
}