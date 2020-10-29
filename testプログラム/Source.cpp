#include "Puriusu.h"
#include "inter2.h"

#include<stdio.h>
#include "Header.h"

int main()
{

	SingletonManagement::RootSingleton<Car>::Create<Puriusu>();
	SingletonManagement::RootSingleton<Car2>::Create<Car2>();

	printf("%u\n", (unsigned int)Car::Instance());
	printf("%u\n", (unsigned int)Car2::Instance());

	//Puriusu::Instance()->Instance()->Instance()->Instance()->Instance()->Drive();
	Nanka();


	SingletonManagement::RootSingleton<Car>::Delete();
	SingletonManagement::RootSingleton<Car2>::Delete();

	return 0;
}