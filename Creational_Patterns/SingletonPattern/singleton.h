#ifndef SINGLETON_H
#define SINGLETON_H

#include <mutex>


/* If you would like to use thread safe implementation, please define THREAD_SAFE macro. So just uncomment the below line :) */
//#define THREAD_SAFE


#ifdef THREAD_SAFE

/* Thread safe implementation*/
class Singleton
{
public:
	static Singleton* getInstance()                    ;
	Singleton(const Singleton&)             = delete   ; //non-copyable
	Singleton& operator=(const Singleton&)  = delete   ; //non-assignable
private:
	Singleton()                             = default  ;
	static Singleton* p_instance                       ;
	static std::mutex mutex_                           ;
};


#else

/* This implementation is not thread safe */
class Singleton
{
public:
	static Singleton* getInstance(void)                ;
	Singleton(const Singleton&)             = delete   ; //non-copyable
	Singleton& operator=(const Singleton&)  = delete   ; //non-assignable
private:
	Singleton()                             = default  ;
	static Singleton* p_instance                       ;
	
};



#endif //THREAD_SAFE


#endif //SINGLETON_H
