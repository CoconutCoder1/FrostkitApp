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

	void Thread::dispatch( JobSet* jobPtr )
	{
		mImpl->dispatch( jobPtr );
	}

	void Thread::wait( uint32_t timeoutMS )
	{
		mImpl->wait( timeoutMS );
	}

	void Thread::setName( const std::wstring& nameStr )
	{
		mNameStr = nameStr;
	}

	std::wstring Thread::getName( ) const
	{
		return mNameStr;
	}

	uint32_t Thread::getThreadId( ) const
	{
		return mImpl->getThreadId( );
	}

}