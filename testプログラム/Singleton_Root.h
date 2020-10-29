//=============================================================================
//
// シングルトンrootヘッダ [singleton_Root.h]
// Author : 奥田 真規
// 注意：このヘッダはmain.cppから呼ばれることを前提にして作られています
//=============================================================================
#pragma once

#include "Singleton.h"

// Singleton管理空間
namespace SingletonManagement
{
	// シングルトンrootクラス
	template <class T>
	class RootSingleton final{
	public:

		// 実体作成クラス[インターフェイスシングルトンの場合は子クラスを指定できる]
		template<class U>
		static void Create()
		{
			Singleton<T>::template CreateInstance<U>();
		}

		// 実体削除クラス
		static void Delete()
		{
			Singleton<T>::DeleteInstance();
		}
	};
}