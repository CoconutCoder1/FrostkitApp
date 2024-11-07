#include "Singleton.h"

namespace fk {

	SingletonManager* SingletonManager::mInstancePtr = nullptr;

	void SingletonManager::registerSingleton( Handle* handlePtr )
	{
		if (!mInstancePtr)
		{
			mInstancePtr = new SingletonManager( );
		}

		mInstancePtr->mInstancesTbl.push_back( handlePtr );
		handlePtr->listPos = std::prev( mInstancePtr->mInstancesTbl.end( ) );
	}

	void SingletonManager::unregisterSingleton( Handle* handlePtr )
	{
		if (!mInstancePtr)
			return;

		mInstancePtr->mInstancesTbl.erase( handlePtr->listPos );

		if (mInstancePtr->mInstancesTbl.empty( ))
		{
			delete mInstancePtr;
			mInstancePtr = nullptr;
		}
	}

}