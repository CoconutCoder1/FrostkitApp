#if defined(FK_WIN64)

#include "WindowWin64.h"

namespace fk::pf {

	constexpr wchar_t windowInstanceKey[] = L"FkWindowWin64";

	LRESULT CALLBACK Window::Impl::wndProc( HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam )
	{
		auto* windowPtr = (Window::Impl*)GetPropW( hWnd, windowInstanceKey );

		if (!windowPtr)
			return DefWindowProcW( hWnd, Msg, wParam, lParam );

		switch (Msg)
		{
		case WM_DESTROY:
			for (const auto& callback : windowPtr->mMessageCallbacks)
				callback( Window::MessageType_Close, Window::noneMessageArgs );

			break;

		default:
			break;
		}

		return DefWindowProcW( hWnd, Msg, wParam, lParam );
	}

	void Window::Impl::create( const std::wstring& titleStr, int width, int height )
	{
		if (mCreated)
			return;

		mTitleStr = titleStr;
		mWidth = width;
		mHeight = height;

		HINSTANCE hInstance = GetModuleHandle( NULL );

		WNDCLASSW wc = {};
		wc.lpfnWndProc = wndProc;
		wc.hCursor = LoadCursorW( NULL, IDC_ARROW );
		wc.hInstance = hInstance;
		wc.lpszClassName = L"FrostkitWin";

		RegisterClassW( &wc );
		
		mHandle = CreateWindowW(
			wc.lpszClassName, mTitleStr.c_str( ),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			mWidth, mHeight,
			NULL, NULL, hInstance, NULL
		);

		if (mHandle)
		{
			mCreated = true;

			SetPropW( mHandle, windowInstanceKey, (HANDLE)this );

			ShowWindow( mHandle, SW_SHOWNORMAL );
			UpdateWindow( mHandle );
		}
	}

	void Window::Impl::destroy( )
	{
		if (mCreated)
		{
			if (mHandle)
			{
				DestroyWindow( mHandle );
				mHandle = NULL;
			}
			mCreated = false;
		}
	}

	int Window::Impl::getWidth( ) const
	{
		return mWidth;
	}

	int Window::Impl::getHeight( ) const
	{
		return mHeight;
	}

	std::wstring Window::Impl::getTitle( ) const
	{
		return mTitleStr;
	}

	void Window::Impl::addMessageCallback( Window::MessageCallback callback )
	{
		mMessageCallbacks.push_back( callback );
	}

	bool Window::Impl::getKeyState( uint8_t keyCode )
	{
		return GetKeyState( keyCode ) < 0;
	}

}

#endif