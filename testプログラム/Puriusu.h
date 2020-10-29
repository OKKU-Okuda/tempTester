#pragma once
#include <stdio.h>

#include "interface.h"

class Puriusu :public Car {
	friend class Singleton<Car>;

	void Drive() override
	{

	}

protected:
	Puriusu() {};
	~Puriusu()
	{
		printf("‚Õ‚è");
	}
};