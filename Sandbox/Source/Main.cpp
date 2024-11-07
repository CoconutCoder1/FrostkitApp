#include "Application.h"

#include <Platform/Platform.h>
#include <Platform/Window.h>

namespace fk {

	int entryPoint( )
	{
		Application::createInstance( );

		Application* appPtr = Application::instance( );
		appPtr->initialize( );

		appPtr->run( );

		appPtr->finalize( );

		Application::deleteInstance( );

		return pf::getExitCode( );
	}

}

#if defined(FK_CONSOLE)
int main( )
{
	return fk::entryPoint( );
}
#elif defined(FK_WIN64)
#include <Windows.h>

int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow )
{
	return fk::entryPoint( );
}
#endif