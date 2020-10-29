//=============================================================================
//
// �V���O���g���w�b�_ [singleton.h]
// Author : ���c �^�K
// 
//=============================================================================

#pragma once
#include <type_traits>


// Singleton���p��������1�����N���X�̒��ӓ_
// �P�ASingleton�̃e���v���[�g�N���X���Y���N���X�ɂ��邱�ƁB
// �Q�A�P�A�Ɠ����N���X���t�����h�N���X�Ƃ��Đ錾���邱�ƁB
// �R�A�R���X�g���N�^�A�f�X�g���N�^��protected�A�N�Z�X�Ɏw�肷�邱��
// �S�A�|�����[�t�B�Y���ɂ��p��������l������ꍇ��virtual���w�肷�邱��
// 
// ��Q�����ȍ~�̒��ӓ_
// ��L�Q�A�R�A�S�����炷�邱��

// �O���錾
namespace SingletonManagement {
	template<class>class RootSingleton;
}


// ---------------------------------------------------------
// �V���O���g���N���X
// ---------------------------------------------------------
template <class T>
class Singleton {
	friend class SingletonManagement::RootSingleton<T>;
public:

	// �C���X�^���X�擾�֐�[���̃N���X���p�������ꍇ�͂��̊֐��Ŏ��̂��擾����]
	static T* Instance() 
	{ 
		// �G���[���e�FT�̓V���O���g���N���X���p�����Ă��܂���
		static_assert(std::is_base_of<Singleton<T>, T>::value == true, "The template keyword class does not inherit from the \"Singleton\" class.");
		return instance; 
	}


protected:
	Singleton() {};
	virtual ~Singleton() {};

private:
	static T* instance;		// ����

	// �R�s�[�֎~
	Singleton(const Singleton &) = delete;
	Singleton(Singleton &&) = delete;
	Singleton& operator=(const Singleton &) = delete;
	Singleton& operator=(Singleton &&) = delete;

	/* �ȉ���RootSingleton�N���X�Ŏg�p���� */
	template <class U>
	static void CreateInstance()
	{	// root�p�C���X�^���X�쐬�֐�

		if (instance != nullptr)return;
		instance = dynamic_cast<T*>(new U);
	}

	static void DeleteInstance()
	{	// root�p�C���X�^���X����֐�
		delete instance; instance = nullptr;
	}
};


// �V���O���g���N���X�ÓI�ϐ���`[�e���v���[�g�N���X�̂��߃w�b�_��`]
template<class T> T* Singleton<T>::instance = nullptr;

