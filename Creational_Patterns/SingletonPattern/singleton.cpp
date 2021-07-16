
#include <iostream>
#include "singleton.h"


#ifdef THREAD_SAFE

Singleton* Singleton::p_instance = nullptr; //= Singleton Singleton::*p_instance = nullptr;
std::mutex Singleton::mutex_;

Singleton* Singleton::getInstance(void)
{

    std::lock_guard<std::mutex> lock(mutex_);

    if (!p_instance) {
        p_instance = new Singleton();
        std::cout << "Firs but last instance has been created!\n";
        return p_instance;
    }
    else {
        std::cout << "Intance was already created. You are getting the same instance!\n";
        return p_instance;
    }
}

#else

Singleton* Singleton::p_instance = nullptr; //= Singleton Singleton::*p_instance = nullptr;

Singleton* Singleton::getInstance(void)
{
    if (!p_instance) {
        p_instance = new Singleton();
        std::cout << "Firs but last instance has been created!\n";
        return p_instance;
    }

    else {
        std::cout << "Intance was already created. You are getting the same instance!\n";
        return p_instance;
    }


}

#endif







