#pragma once

#include "Thread.h"

#include <Windows.h>

#include <string>

namespace fk::pf {

	class Thread::Impl
	{
	public:
		void dispatch( JobSet* jobPtr );
		void wait( uint32_t timeoutMS );

		uint32_t getThreadId( ) const;

	private:
		HANDLE mHandle;
		DWORD mThreadId;

		static DWORD WINAPI threadProc( PVOID paramPtr );
	};

}