#pragma once

#include "Object.h"
#include "Singleton.h"

#include <Kernel/Platform/Window.h>
#include <Kernel/Platform/Thread.h>

namespace fk {

    class Application : public Object, public Singleton<Application>
    {
    public:
        void initialize( );
        void finalize( );
        void run( );

    private:
        void update( );
        void updateLoop( );

        static void updateProc( void* dataPtr );
        static void messageCallback( pf::Window::MessageType msgType, const pf::Window::MessageArgs& args );

    private:
        pf::Window mMainWindow;
        pf::Thread mGameThread;
        bool mGameExit = false;
    };

}