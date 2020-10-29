#pragma once
#include <stdio.h>
#include "Singleton.h"

class Car :public Singleton<Car>{
	friend class Singleton<Car>;
public:
	virtual void Drive() =0;

protected:
	Car() {}; virtual ~Car() { printf("[[Ç©Å[Çó"); };

};