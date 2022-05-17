#include "common.h"

class MyClass {
        public:
        
        MyClass() {
                bShouldQuit     = false;
                bHasInitialized = false;
                init();
        }
        ~MyClass(){}
 
        static bool bShouldQuit;
        static bool bHasInitialized;

        HLib_Task_t* taskPtr;
 
        void init();
 
        static void callbackFn();
        static void mainCallbackFn();
};

bool MyClass::bShouldQuit;
bool MyClass::bHasInitialized;

void MyClass::init()
{
       taskPtr = EnqueueTaskWithoutParameter(MyClass::mainCallbackFn, 0x04, 0xb, EVNT);    
}

void MyClass::callbackFn()
{       
        LOG("Hello, World from callbackFn()!\n");
        TaskCleanupCurrentTask();
}

void MyClass::mainCallbackFn()
{
        if (!bHasInitialized) {
                load_scene(MyClass::callbackFn, 1);
                bHasInitialized = true;
        }
        
        if (bShouldQuit)
                TaskCleanupCurrentTask();       
}

void _entry start(void) 
{
       MyClass instance;
       return;
}