#pragma once

template <class T>
class Singleton {
public:

	static void CreateInstance()
	{
		instance = new T;
	}

	template <class U>
	static void CreateInstance()
	{
		instance = dynamic_cast<T*>(new U);
	}



	static T* Instance() { return instance; }
protected:
	Singleton() {};
	virtual ~Singleton() {};

private:
	static T* instance;

	Singleton(const Singleton &) = delete;
	Singleton(Singleton &&) = delete;

	Singleton& operator=(const Singleton &) = delete;
	Singleton& operator=(Singleton &&) = delete;

};


template<class T> T* Singleton<T>::instance;