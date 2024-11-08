#pragma once

#include <memory>
#include <string>
#include <functional>

namespace fk::pf {

	class Window
	{
		class Impl;

	public:
		enum MessageType : short
		{
			MessageType_Close,
		};

		struct MessageArgs
		{

		};

		static const MessageArgs noneMessageArgs;

		using MessageCallback = std::function<void( MessageType msgType, const MessageArgs& args )>;

	public:
		Window( );
		~Window( );

		void create( const std::wstring& titleStr, int width, int height );
		void destroy( );

		int getWidth( ) const;
		int getHeight( ) const;
		std::wstring getTitle( ) const;

		void addMessageCallback( MessageCallback callback );

		static bool getKeyState( uint8_t keyCode );

	private:
		std::unique_ptr<Impl> mImpl;
	};

}