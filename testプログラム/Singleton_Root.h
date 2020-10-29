//=============================================================================
//
// シングルトンrootヘッダ [singleton_Root.h]
// Author : 奥田 真規
// 注意：このヘッダはmain.cppから呼ばれることを前提にして作られています
//=============================================================================
#pragma once
#include <type_traits>
#include "Singleton.h"

// Singleton管理空間
namespace SingletonManagement
{
	// シングルトンrootクラス
	template <class T>
	class RootSingleton final{
	public:
		// エラー内容：Tはシングルトンを継承していません
		static_assert(std::is_base_of<Singleton<T>, T>::value == true, "The \"RootSingleton\" template keyword class does not inherit the \"Singleton\" class.");

		// 実体作成クラス[インターフェイスシングルトンの場合は子クラスを指定できる]
		template<class U>
		static void Create()
		{
			// エラー内容：UはTのシングルトンクラスを継承していません
			static_assert(std::is_base_of<Singleton<T>, U>::value == true, "The specified class does not inherit from the \"singleton\" class");

			Singleton<T>::template CreateInstance<U>();
		}

		// 実体削除クラス
		static void Delete()
		{
			Singleton<T>::DeleteInstance();
		}
	};
}