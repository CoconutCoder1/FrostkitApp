#include "Window.h"

#if defined(FK_WIN64)
#include "WindowWin64.h"
#else
#error "No window implementation for this platform"
#endif

namespace fk::pf {

	const Window::MessageArgs Window::noneMessageArgs{ };

	Window::Window( )
	{
		mImpl.reset( new Impl( ) );
	}

	Window::~Window( ) = default;

	void Window::create( const std::wstring& titleStr, int width, int height )
	{
		mImpl->create( titleStr, width, height );
	}

	void Window::destroy( )
	{
		mImpl->destroy( );
	}

	int Window::getWidth( ) const
	{
		return mImpl->getWidth( );
	}

	int Window::getHeight( ) const
	{
		return mImpl->getHeight( );
	}

	std::wstring Window::getTitle( ) const
	{
		return mImpl->getTitle( );
	}

	void Window::addMessageCallback( MessageCallback callback )
	{
		mImpl->addMessageCallback( callback );
	}

	bool Window::getKeyState( uint8_t keyCode )
	{
		return Impl::getKeyState( keyCode );
	}

}