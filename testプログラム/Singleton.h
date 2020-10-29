//=============================================================================
//
// シングルトンヘッダ [singleton.h]
// Author : 奥田 真規
// 
//=============================================================================

#pragma once
#include <type_traits>


// Singletonを継承した第1直下クラスの注意点
// １、Singletonのテンプレートクラスを該当クラスにすること。
// ２、１、と同じクラスをフレンドクラスとして宣言すること。
// ３、コンストラクタ、デストラクタはprotectedアクセスに指定すること
// ４、ポリモーフィズムによる継承が今後考えられる場合はvirtualを指定すること
// 
// 第２直下以降の注意点
// 上記２、３、４を厳守すること

// 前方宣言
namespace SingletonManagement {
	template<class>class RootSingleton;
}


// ---------------------------------------------------------
// シングルトンクラス
// ---------------------------------------------------------
template <class T>
class Singleton {
	friend class SingletonManagement::RootSingleton<T>;
public:

	// インスタンス取得関数[このクラスを継承した場合はこの関数で実体を取得する]
	static T* Instance() 
	{ 
		// エラー内容：Tはシングルトンクラスを継承していません
		static_assert(std::is_base_of<Singleton<T>, T>::value == true, "The template keyword class does not inherit from the \"Singleton\" class.");
		return instance; 
	}


protected:
	Singleton() {};
	virtual ~Singleton() {};

private:
	static T* instance;		// 実体

	// コピー禁止
	Singleton(const Singleton &) = delete;
	Singleton(Singleton &&) = delete;
	Singleton& operator=(const Singleton &) = delete;
	Singleton& operator=(Singleton &&) = delete;

	/* 以下はRootSingletonクラスで使用する */
	template <class U>
	static void CreateInstance()
	{	// root用インスタンス作成関数

		if (instance != nullptr)return;
		instance = dynamic_cast<T*>(new U);
	}

	static void DeleteInstance()
	{	// root用インスタンス解放関数
		delete instance; instance = nullptr;
	}
};


// シングルトンクラス静的変数定義[テンプレートクラスのためヘッダ定義]
template<class T> T* Singleton<T>::instance = nullptr;

