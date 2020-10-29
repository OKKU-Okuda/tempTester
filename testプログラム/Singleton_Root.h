//=============================================================================
//
// �V���O���g��root�w�b�_ [singleton_Root.h]
// Author : ���c �^�K
// ���ӁF���̃w�b�_��main.cpp����Ă΂�邱�Ƃ�O��ɂ��č���Ă��܂�
//=============================================================================
#pragma once

#include "Singleton.h"

// Singleton�Ǘ����
namespace SingletonManagement
{
	// �V���O���g��root�N���X
	template <class T>
	class RootSingleton final{
	public:

		// ���̍쐬�N���X[�C���^�[�t�F�C�X�V���O���g���̏ꍇ�͎q�N���X���w��ł���]
		template<class U>
		static void Create()
		{
			Singleton<T>::template CreateInstance<U>();
		}

		// ���̍폜�N���X
		static void Delete()
		{
			Singleton<T>::DeleteInstance();
		}
	};
}