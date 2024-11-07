#if defined(FK_WIN64)

#include "ThreadWin64.h"

namespace fk::pf {

	DWORD WINAPI Thread::Impl::threadProc( PVOID paramPtr )
	{
		auto threadPtr = (Thread::Impl*)paramPtr;

		SetThreadDescription( GetCurrentThread( ), threadPtr->mNameStr.c_str( ) );

		threadPtr->mFuncPtr( threadPtr->mParamPtr );

		return 0;
	}

	void Thread::Impl::dispatch( ThreadProc funcPtr, void* paramPtr )
	{
		mFuncPtr = funcPtr;
		mParamPtr = paramPtr;

		if (mHandle)
			wait( );

		mHandle = CreateThread( NULL, 0, threadProc, this, 0, &mThreadId );
	}

	void Thread::Impl::wait( )
	{
		WaitForSingleObject( mHandle, INFINITE );
		CloseHandle( mHandle );
		mHandle = NULL;
	}

	void Thread::Impl::setName( const std::wstring& nameStr )
	{
		mNameStr = nameStr;
	}

	std::wstring Thread::Impl::getName( ) const
	{
		return mNameStr;
	}

	uint32_t Thread::Impl::getThreadId( ) const
	{
		return (uint32_t)mThreadId;
	}

}

#endif