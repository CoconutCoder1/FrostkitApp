#pragma once

#include "Thread.h"

#include <Windows.h>

#include <string>

namespace fk::pf {

	class Thread::Impl
	{
	public:
		void dispatch( ThreadProc funcPtr, void* paramPtr );
		void wait( );

		void setName( const std::wstring& nameStr );
		std::wstring getName( ) const;

		uint32_t getThreadId( ) const;

	private:
		HANDLE mHandle;
		DWORD mThreadId;
		std::wstring mNameStr;

		ThreadProc mFuncPtr;
		void* mParamPtr;

		static DWORD WINAPI threadProc( PVOID paramPtr );
	};

}