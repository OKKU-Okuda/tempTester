#pragma once
#include <stdio.h>

#include "interface.h"

class Puriusu :public Car {
	friend class Singleton<Car>;

	void Drive() override
	{
		printf("carπp³΅½vEX");
	}

protected:
	Puriusu() {};
	~Puriusu()
	{
		printf("Υθ");
	}
};