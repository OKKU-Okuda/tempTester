#pragma once
#include <stdio.h>

#include "interface.h"

class Puriusu :public Car {
	friend class Singleton<Car>;

	void Drive() override
	{
		printf("car���p�������v���E�X");
	}

protected:
	Puriusu() {};
	~Puriusu()
	{
		printf("�Ղ�");
	}
};