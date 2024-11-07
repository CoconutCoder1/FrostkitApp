#pragma once

#include "Object.h"
#include "Singleton.h"

#include <Platform/Window.h>
#include <Platform/Thread.h>

namespace fk {

    class Application : public Object, public Singleton<Application>
    {
    public:
        void initialize( );
        void finalize( );
        void run( );

    private:
        static void updateProc( void* dataPtr );

        static void messageCallback( pf::Window::MessageType msgType, const pf::Window::MessageArgs& args );

    private:
        pf::Window mMainWindow;
        pf::Thread mGameThread;
        bool mGameExit = false;
    };

}