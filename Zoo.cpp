#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
	string animal, data;
	virtual void Eat()
	{
		cout << animal << data << endl;
	}
	virtual void Talk()
	{
		cout << animal << data << endl;
	}
	virtual void Fly()
	{
		cout << animal << data << endl;
	}
	virtual void Information()
	{
		cout << animal << data << endl;
	}
};

class Popygay : public Animal
{
public:
	string inf;
	bool isFly;
	bool isTalk;

	void Jump()
	{
		cout << animal << " not jump:(" << endl;
	}
	void Information() override
	{
		cout << animal << inf << endl;
	}
	void Fly() override
	{
		cout << animal << " is fly" << endl;
	}
	void Talk() override
	{
		cout << animal << " is talk" << endl;
	}
};
class Tiger : public Animal
{
public:
	string inf;
	bool isFly;

	void Jump()
	{
		cout << animal << " is jump:)" << endl;
	}
	void Information() override
	{
		cout << animal << inf << endl;
	}
	void Fly() override
	{
		cout << animal << "is fly" << endl;
	}
	void Eat()
	{
		cout << animal << " eats meat" << endl;
	}
};
class Cat : public Animal
{
public:
	bool isFly;
	string inf;
	void Information() override
	{
		cout << animal << inf << endl;
	}
	void Fly() override
	{
		cout << animal << " is not fly" << endl;
	}
	void Jump()
	{
		cout << animal << " is jump:)" << endl;
	}
};
int main()
{
	Cat cat;
	Tiger tig;
	Popygay pop;
	int an;

	cat.inf = " they like home. Peoples love them so much";
	cat.isFly = false;

	tig.inf = " They are big pets, they likes hot weather and meat";
	tig.isFly = false;

	pop.inf = " They are not big pets, they likes hot weather";
	pop.isTalk = true;
	pop.isFly = true;

	cat.animal = "Cat";
	tig.animal = "Tiger";
	pop.animal = "Parrot";

	cout << "Choose your animal: 1 - cat; 2 - tig; 3 - parrot\n";
	cin >> an;

	if (an == 1)
	{
		cat.Fly();
		cat.Jump();
		cat.Information();
	}

	else if (an == 2)
	{
		tig.Information();
		tig.Jump();
		tig.Fly();
		tig.Eat();
	}

	else if (an == 3)
	{
		pop.Jump();
		pop.Information();
		pop.Fly();
		pop.Talk();
	}
	else
	{
		cout << "we don't have any more animals";
	}
}