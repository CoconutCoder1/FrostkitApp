#include "Application.h"

#include <Platform/Platform.h>

namespace fk {

	void Application::initialize( )
	{
		mMainWindow.addMessageCallback( messageCallback );
		mMainWindow.create( L"Frostkit App", 800, 600 );

		mGameThread.setName( L"GameThread" );
	}

	void Application::finalize( )
	{
		mMainWindow.destroy( );
	}

	void Application::run( )
	{
		mGameThread.dispatch( new pf::JobSet( updateProc, this ) );
		
		while (pf::update( ));

		mGameExit = true;
		mGameThread.wait( );
	}

	void Application::update( )
	{

	}

	void Application::updateLoop( )
	{
		while (mGameExit)
		{
			update( );
		}
	}

	void Application::updateProc( void* dataPtr )
	{
		((Application*)dataPtr)->updateLoop( );
	}

	void Application::messageCallback( pf::Window::MessageType msgType, const pf::Window::MessageArgs& args )
	{
		if (msgType == pf::Window::MessageType_Close)
			pf::exit( 0 );
	}

}