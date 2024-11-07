#pragma once

#include "Window.h"

#include <Windows.h>
#include <string>

namespace fk::pf {

	class Window::Impl
	{
	public:
		void create( const std::wstring& titleStr, int width, int height );
		void destroy( );

		int getWidth( ) const;
		int getHeight( ) const;
		std::wstring getTitle( ) const;

		void addMessageCallback( Window::MessageCallback callback );

	private:
		static LRESULT CALLBACK wndProc( HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam );

	private:
		HWND mHandle = NULL;
		int mWidth = 0;
		int mHeight = 0;
		std::wstring mTitleStr;
		bool mCreated = false;

		std::list<Window::MessageCallback> mMessageCallbacks;
	};

}