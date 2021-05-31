#ifndef SINGLETON_BASE_H
#define SINGLETON_BASE_H

#include <memory>

namespace std
{

template <class T>
class CSingletonBase
{
public:
	static T* GetInstance() {
		static unique_ptr<T> pInstance = make_unique<T>();
		return pInstance.get();
	}

protected:
	// �p���p�̃R���X�g���N�^�E�f�X�g���N�^.
	CSingletonBase(){};
	virtual ~CSingletonBase() {}

private:
	// �R�s�[�E���[�u�R���X�g���N�^, ������Z�q�̍폜.
	CSingletonBase( const CSingletonBase & ) = delete;
	CSingletonBase& operator = ( const CSingletonBase & ) = delete;
	CSingletonBase( CSingletonBase && ) = delete;
	CSingletonBase& operator = ( CSingletonBase && ) = delete;
};

}

#endif	// #ifndef SINGLETON_BASE_H.