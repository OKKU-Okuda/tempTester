#include "Header.h"

#include "Puriusu.h"
#include "inter2.h"

#include<stdio.h>


void Nanka()
{

	printf("%u\n", (unsigned int)Car::Instance());
	printf("%u", (unsigned int)Car2::Instance());

}