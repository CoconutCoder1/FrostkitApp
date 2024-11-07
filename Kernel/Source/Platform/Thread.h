#pragma once

#include <memory>
#include <cstdint>
#include <string>

namespace fk::pf {

	using ThreadProc = void(*)(void*);

	class JobSet
	{
	public:
		ThreadProc procFn;
		void* dataPtr;

		JobSet( ) :
			procFn( nullptr ),
			dataPtr( nullptr )
		{
		}

		JobSet( ThreadProc procFn, void* dataPtr ) :
			procFn( procFn ),
			dataPtr( dataPtr )
		{
		}
	};

	class Thread
	{
		class Impl;

	public:
		Thread( );
		~Thread( );

		void dispatch( JobSet* jobPtr );
		void wait( uint32_t timeoutMS = UINT32_MAX );

		void setName( const std::wstring& nameStr );
		std::wstring getName( ) const;

		uint32_t getThreadId( ) const;

	private:
		std::wstring mNameStr;
		std::unique_ptr<Impl> mImpl;
	};

}