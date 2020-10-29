#pragma once

#include "Singleton.h"

class Car2 :public Singleton<Car2> {
	friend class Singleton<Car2>;

	virtual void Run() {};

protected:
	Car2() {}; virtual ~Car2() {};
};