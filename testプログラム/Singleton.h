#pragma once

template <class>class Singleton;

namespace SingletonManagement
{
	template <class T>
	class RootSingleton {
	public:

		template<class U>
		static void Create()
		{
			//Singleton<T>::instance = dynamic_cast<T*>(new U);

			Singleton<T>::template CreateInstance<U>();
		}

		static void Delete()
		{
			Singleton<T>::DeleteInstance();
			Singleton<T>::instance = nullptr;
		}
	};
}

template <class T>
class Singleton {
	friend class SingletonManagement::RootSingleton<T>;
public:

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

	// root用インスタンス作成関数
	template <class U>
	static void CreateInstance()
	{
		instance = dynamic_cast<T*>(new U);
	}

	// root用インスタンス解放関数
	static void DeleteInstance()
	{
		delete instance;
	}
};


template<class T> T* Singleton<T>::instance = nullptr;

