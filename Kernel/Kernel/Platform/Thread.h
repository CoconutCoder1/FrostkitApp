#pragma once

#include <memory>
#include <cstdint>
#include <string>

namespace fk::pf {

	using ThreadProc = void(*)(void*);

	class Thread
	{
		class Impl;

	public:
		Thread( );
		~Thread( );

		void dispatch( ThreadProc funcPtr, void* paramPtr );
		void wait( );

		void setName( const std::wstring& nameStr );
		std::wstring getName( ) const;

		uint32_t getThreadId( ) const;

	private:
		std::unique_ptr<Impl> mImpl;
	};

}