#include "Puriusu.h"
#include "inter2.h"

#include<stdio.h>
#include "Header.h"

#include "Singleton_Root.h"

class A {

};

class B :public Singleton<int>
{

};
int main()
{
	SingletonManagement::RootSingleton<Car>::Create<Puriusu>();
	SingletonManagement::RootSingleton<Car2>::Create<Car2>();
	//SingletonManagement::RootSingleton<A>::Create<A>();
	//B::Instance();
	printf("%u\n", (unsigned int)Car::Instance());
	printf("%u\n", (unsigned int)Car2::Instance());

	Puriusu::Instance()->Instance()->Instance()->Instance()->Instance()->Drive();
	Car::Instance()->Instance()->Instance()->Instance()->Instance()->Drive();

	Nanka();
	//Puriusu p;
	//Car2 a;
	SingletonManagement::RootSingleton<Car>::Delete();
	SingletonManagement::RootSingleton<Car2>::Delete();


	return 0;
}