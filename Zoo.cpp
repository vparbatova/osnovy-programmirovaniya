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
	void Fly()
	{
		cout << animal << " is fly" << endl;
	}
	void Talk() override
	{
		cout << animal << " is talk like peoples" << endl;
	}
};
class Tiger : public Animal
{
public:
	string inf;

	void Jump()
	{
		cout << animal << " is jump:)" << endl;
	}
	void Information() override
	{
		cout << animal << inf << endl;
	}
	void Eat() override
	{
		cout << animal << " eats meat" << endl;
	}
	void Talk() override
	{
		cout << animal << "is growls" << endl;
	}
};
class Cat : public Animal
{
public:
	string inf;
	void Information() override
	{
		cout << animal << inf << endl;
	}
	void Play()
	{
		cout << animal << " is plays with peoples:)" << endl;
	}
	void Talk() override
	{
		cout << animal << " says miy miy" << endl;
	}
	void Eat() override
	{
		cout << animal << " eats meat and cat food" << endl;
	}
};
int main()
{
	Cat cat;
	Tiger tig;
	Popygay pop;
	int an;

	cat.inf = " they like home. Peoples love them so much";

	tig.inf = " They are big pets, they likes hot weather and meat";

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
		cat.Play();
		cat.Information();
		cat.Talk();
		cat.Eat();
	}

	else if (an == 2)
	{
		tig.Information();
		tig.Eat();
		tig.Jump();
		tig.Talk();
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