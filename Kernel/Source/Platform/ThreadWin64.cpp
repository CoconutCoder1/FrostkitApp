#if defined(FK_WIN64)

#include "ThreadWin64.h"

namespace fk::pf {

	DWORD WINAPI Thread::Impl::threadProc( PVOID paramPtr )
	{
		auto* jobPtr = (JobSet*)paramPtr;
		jobPtr->procFn( jobPtr->dataPtr );
		delete jobPtr;

		return 0;
	}

	void Thread::Impl::dispatch( JobSet* jobPtr )
	{
		mHandle = CreateThread( NULL, 0, threadProc, jobPtr, 0, &mThreadId );
	}

	void Thread::Impl::wait( uint32_t timeoutMS )
	{
		if (mHandle)
		{
			WaitForSingleObject( mHandle, timeoutMS );
		}
	}

	uint32_t Thread::Impl::getThreadId( ) const
	{
		return (uint32_t)mThreadId;
	}

}

#endif