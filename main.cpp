#include <iostream>
#include "singleton.h"


int main(void)
{
  
    Singleton* singletonA = Singleton::getInstance(); 
    Singleton* singletonB = Singleton::getInstance();

    /* The addresses will be the same. */
    std::cout << singletonA << '\n';
    std::cout << singletonB << '\n';

    return 0;

}