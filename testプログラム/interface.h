#pragma once

#include "Singleton.h"

class Car :public Singleton<Car>{
	friend class Singleton<Car>;

	virtual void Drive() =0;

protected:
	Car() {};
	~Car() {};
};