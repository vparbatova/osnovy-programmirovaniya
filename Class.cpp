#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pass {
private:
	string punkt_nazn, FIO, data, nom_reys, stroka, name, fam, otch;
public:
	string ADD()
	{
		cout << "Введите место назначения: \n";
		cin >> punkt_nazn;
		this->punkt_nazn;
		cout << "Введите номер рейса: \n";
		cin >> nom_reys;
		this->nom_reys;
		cout << "Введите ФИО: \n";
		cin >> fam >> name >> otch;
		FIO = fam + ' ' + name + ' ' + otch;
		this->FIO;
		cout << "Введите дату вылета: \n";
		cin >> data;
		this->data;
		stroka = punkt_nazn + ' ' + nom_reys + ' ' + FIO + ' ' + data;
		return stroka;
	}
	string DEL(vector<string> pass)
	{
		if (pass.size() != 0)
		{
			cout << "Введите место назначения: \n";
			cin >> punkt_nazn;
			this->punkt_nazn;
			cout << "Введите номер рейса: \n";
			cin >> nom_reys;
			this->nom_reys;
			cout << "Введите ФИО: \n";
			cin >> fam >> name >> otch;
			FIO = fam + ' ' + name + ' ' + otch;
			this->FIO;
			cout << "Введите дату вылета: \n";
			cin >> data;
			this->data;
			stroka = punkt_nazn + ' ' + nom_reys + ' ' + FIO + ' ' + data;
			bool FLAG = true;
			for (int i = 0; i < pass.size(); i++)
			{
				if (pass[i] == stroka)
				{
					FLAG = false;
					return stroka;
				}
				if (FLAG == true and i == pass.size() - 1)
				{
					cout << "Нет такого пассажира" << endl;
					return "Error";
				}
			}
		}
		else
		{
			cout << "Действие невозможно, пассажиров нет\n";
			return "Error";
		}
	}
	void VIEW(vector<string> pass)
	{
		for (int i = 0; i < pass.size(); i++)
		{
			cout << pass[i] << endl;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Pass a;
	string deystvie, c;
	vector<string> pass{};
	string END;
	do
	{
		cout << "Что вы хотите сделать? (Добавить(add)/удалить(del)/просмотреть(view))\n";
		cin >> deystvie;
		if (deystvie == "add")
		{
			pass.push_back(a.ADD());
		}
		else if (deystvie == "del")
		{
			c = a.DEL(pass);
			if (c != "Error")
			{
				for (int i = 0; i < pass.size(); i++)
				{
					if (pass[i] == c)
					{
						pass.erase(pass.begin() + i);
						break;
					}
				}
			}
		}
		else if (deystvie == "view")
		{
			a.VIEW(pass);
		}
		cout << "Если хотите продолжить - NEXT, если закончить - END\n";
		cin >> END;
	} while (END != "END");
}