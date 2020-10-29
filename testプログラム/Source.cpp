#include "Puriusu.h"
#include "inter2.h"

#include<stdio.h>
#include "Header.h"

int main()
{

	Car::CreateInstance<Puriusu>();
	Car2::CreateInstance();

	printf("%u\n", Car::Instance());
	printf("%u\n", Car2::Instance());

	Nanka();
	return 0;
}