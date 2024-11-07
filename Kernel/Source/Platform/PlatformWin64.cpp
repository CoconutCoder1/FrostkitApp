#if defined(FK_WIN64)

#include "Platform.h"

#include <Windows.h>

namespace fk::pf {

	namespace {
		bool isExitRequested = false;
		int lastExitCode = 0;
	}

	bool update( )
	{
		MSG msg;
		while (GetMessageW( &msg, NULL, 0, 0 ))
		{
			TranslateMessage( &msg );
			DispatchMessageW( &msg );

			if (isExitRequested)
				break;
		}

		return false;
	}

	void exit( int code )
	{
		lastExitCode = code;
		isExitRequested = true;
	}

	int getExitCode( )
	{
		return lastExitCode;
	}

}

#endif