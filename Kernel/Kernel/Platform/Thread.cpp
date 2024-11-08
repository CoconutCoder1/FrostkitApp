#include "Thread.h"

#if defined(FK_WIN64)
#include "ThreadWin64.h"
#endif

namespace fk::pf {

	Thread::Thread( )
	{
		mImpl.reset( new Impl( ) );
	}

	Thread::~Thread( ) = default;

	void Thread::dispatch( ThreadProc funcPtr, void* paramPtr )
	{
		mImpl->dispatch( funcPtr, paramPtr );
	}

	void Thread::wait( )
	{
		mImpl->wait( );
	}

	void Thread::setName( const std::wstring& nameStr )
	{
		mImpl->setName( nameStr );
	}

	std::wstring Thread::getName( ) const
	{
		return mImpl->getName( );
	}

	uint32_t Thread::getThreadId( ) const
	{
		return mImpl->getThreadId( );
	}

}