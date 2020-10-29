//=============================================================================
//
// �V���O���g��root�w�b�_ [singleton_Root.h]
// Author : ���c �^�K
// ���ӁF���̃w�b�_��main.cpp����Ă΂�邱�Ƃ�O��ɂ��č���Ă��܂�
//=============================================================================
#pragma once
#include <type_traits>
#include "Singleton.h"

// Singleton�Ǘ����
namespace SingletonManagement
{
	// �V���O���g��root�N���X
	template <class T>
	class RootSingleton final{
	public:
		// �G���[���e�FT�̓V���O���g�����p�����Ă��܂���
		static_assert(std::is_base_of<Singleton<T>, T>::value == true, "The \"RootSingleton\" template keyword class does not inherit the \"Singleton\" class.");

		// ���̍쐬�N���X[�C���^�[�t�F�C�X�V���O���g���̏ꍇ�͎q�N���X���w��ł���]
		template<class U>
		static void Create()
		{
			// �G���[���e�FU��T�̃V���O���g���N���X���p�����Ă��܂���
			static_assert(std::is_base_of<Singleton<T>, U>::value == true, "The specified class does not inherit from the \"singleton\" class");

			Singleton<T>::template CreateInstance<U>();
		}

		// ���̍폜�N���X
		static void Delete()
		{
			Singleton<T>::DeleteInstance();
		}
	};
}