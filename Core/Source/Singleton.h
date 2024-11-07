#pragma once

#include "Object.h"

#include <memory>
#include <list>
#include <typeinfo>

namespace fk {

	class SingletonManager
	{
	public:
		struct Handle
		{
			Object* objectPtr = nullptr;
			std::list<Handle*>::iterator listPos = { };
		};

		static void registerSingleton( Handle* handlePtr );
		static void unregisterSingleton( Handle* handlePtr );

	private:
		std::list<Handle*> mInstancesTbl;

		static SingletonManager* mInstancePtr;
	};

	template<typename T>
	class Singleton
	{
	public:
		static void createInstance( )
		{
			if (!mInstancePtr)
			{
				mInstancePtr = new T( );

				mInstanceHandle.objectPtr = mInstancePtr;
				SingletonManager::registerSingleton( &mInstanceHandle );
			}
		}

		static void deleteInstance( )
		{
			if (mInstancePtr)
			{
				delete mInstancePtr;

				mInstanceHandle.objectPtr = nullptr;
				SingletonManager::unregisterSingleton( &mInstanceHandle );
			}
		}

		static T* instance( )
		{
			return mInstancePtr;
		}

	private:
		inline static T* mInstancePtr = nullptr;
		inline static SingletonManager::Handle mInstanceHandle;
	};

}