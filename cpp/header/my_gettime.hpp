/*
[] gcc main.c -O2
[] g++ main.cpp -O2
[] g++ main.cpp -O2 -std=c++11
----------------------------
* c/c++
double start = get_time_sec();
// hogehoge
double end = get_time_sec();
----------------------------
* c++
mtime::timeStamp timer(2,mtime::timeStampMillisecond); // instance
timer.stamp();  //time stamp
// hogehoge
timer.stamp();  //time stamp
timer.print();
-----------------------------
* c
timeStamp timer;
init_timeStamp(&timer,2);
stamp(&timer);
// hogehoge
stamp(&timer);
print_timeStamp(&timer);
------------------------------
*/


#ifndef _GETTIME
#define _GETTIME

#define _USE_GETTIMEOFDAY  0 // 1: gettimeofday 0: clock_gettime-CLOCK_REALTIME(-lrt)
#define TIME() get_time_sec()

#if __cplusplus >= 201103L  //-std=c++11
	#define __GETTIMEMETHOD "chrono"
	#include <chrono>

namespace mtime{	
	using namespace std::chrono;
	inline double get_time_sec(void){
		return static_cast<double>(duration_cast<nanoseconds>(
			steady_clock::now().time_since_epoch()).count())/1000000000;
	}
}

#elif defined(__unix)||defined(__APPLE__)
	#if _USE_GETTIMEOFDAY == 1
		#include <sys/time.h>
		
		#if defined(__cplusplus)
			namespace mtime{
		#endif		
			#define __GETTIMEMETHOD "gettimeofday"
			inline double get_time_sec(void){
    			struct timeval tv;
   				gettimeofday(&tv,NULL);
    			return((double)(tv.tv_sec)+(double)(tv.tv_usec)/1000000);
				}
		#if defined(__cplusplus)		
			}
		#endif

	#else
            #include <time.h>// -lrt
		#if defined(__cplusplus)
			namespace mtime{
		#endif
			#define __GETTIMEMETHOD "clock_gettime"
			inline double get_time_sec(void){
				struct timespec ts;
				clock_gettime(CLOCK_REALTIME,&ts);
				return ((double)ts.tv_sec+(double)ts.tv_nsec/1000000000);
			}
		#if defined(__cplusplus)		
			}
		#endif

	#endif
#elif defined(_WIN32)
	#define __GETTIMEMETHOD "QueryPerformanceCounter"
	#include <windows.h>
	inline double get_time_sec(void){
    	LARGE_INTEGER freq,time;
    	QueryPerformanceFrequency(&freq);
    	QueryPerformanceCounter(&time);
    	return((double)time.QuadPart/freq.QuadPart);
	}
#endif

#ifdef __cplusplus

	#include <vector>
	#include <iostream>
	#include <cstdio>
	#include <string>
	#include <map>
//	using namespace std;
namespace mtime{
	enum tsUnitOfTime{
		timeStampNanosecond = 0,
		timeStampMicrosecond,
		timeStampMillisecond,
		timeStampSecond,
	};
	#define __DEFAULT_TIME_UNIT (timeStampSecond)
	#define __DEFAULT_MAX_EVENT_NUM 20

	class timeStamp{
	public:
		timeStamp()                                     { initialize(__DEFAULT_MAX_EVENT_NUM ,__DEFAULT_TIME_UNIT); };
		timeStamp(size_t num)                           { initialize(num                     ,__DEFAULT_TIME_UNIT); };
		timeStamp(tsUnitOfTime time_unit)               { initialize(__DEFAULT_MAX_EVENT_NUM ,time_unit); };
		timeStamp(size_t num, tsUnitOfTime time_unit)   { initialize(num                     ,time_unit); };
		double& operator[](size_t i)                    { return _sec_vec[i];} ;
	//	void operator()()                           { _sec_vec[ _timeCount++ ] = get_time_sec();};
		inline void stamp()                             { _sec_vec[ _timeCount++ ] = get_time_sec();};
		double interval  (size_t from, size_t to)       { return (_sec_vec[ to  ]  - _sec_vec[from])   * _xrate; };
		double operator()(size_t from, size_t to)       { return (_sec_vec[ to  ]  - _sec_vec[from])   * _xrate; };
		double operator()(size_t n)                     { return (_sec_vec[ n+1 ]  - _sec_vec[n]   )   * _xrate; };

		double  sum()                                   { return (_sec_vec[ _timeCount-1 ] - _sec_vec[0]) * _xrate; };
		/*int     gettimeCount()                { return _timeCount; };*/

		friend std::ostream& operator<<(std::ostream& os, timeStamp &ts);
		void print();// {std::cout<<*this;};
		void print_oneLine();
	private:
		void initialize(size_t limitOfTimeCount,tsUnitOfTime time_unit);

		std::vector <double> _sec_vec;
		size_t               _limitOfTimeCount;
		size_t               _timeCount;
		tsUnitOfTime         _time_unit;
		double               _xrate;
		std::string          _str_unit;
	};
	void timeStamp::initialize(size_t i,tsUnitOfTime unit){

		_sec_vec.resize(i);
		_limitOfTimeCount=i;
		_timeCount=0;
		_time_unit = unit;

		_time_unit = unit;
		if     (unit == timeStampNanosecond)  {_xrate = 1000000000; _str_unit = "ns"    ;}
		else if(unit == timeStampMicrosecond) {_xrate = 1000000;    _str_unit = "micros";}
		else if(unit == timeStampMillisecond) {_xrate = 1000;       _str_unit = "ms"    ;}
		else if(unit == timeStampSecond)      {_xrate = 1;          _str_unit = "s"     ;}

	}
	void timeStamp::print_oneLine(){
		for(size_t i=1;i<_timeCount;i++)
			std::cout<<std::fixed <<(_sec_vec[i]-_sec_vec[i-1]) * _xrate <<" , "<<_str_unit/*<< std::endl*/;
	}
	void timeStamp::print(){
		for(size_t i=1;i<_timeCount;i++)
			std::cout<<std::fixed <<(_sec_vec[i]-_sec_vec[i-1]) * _xrate <<" , "<<_str_unit<< std::endl;
	}

	std::ostream& operator<<(std::ostream& os, timeStamp &ts){
		ts.print();
		return os;
	}
}

#else // C code
	#include <stdio.h>
	#include <stdlib.h>
	 typedef struct{
		size_t limitOfTimeCount;
		size_t timeCount;
		double *sec;
	 } timeStamp;

	void init_timeStamp(timeStamp *ts, size_t limitOfTimeCount){
		ts->limitOfTimeCount = limitOfTimeCount;
		ts->timeCount = 0;
		ts->sec = (double *)malloc(sizeof(double)*limitOfTimeCount);
	}
	void free_timeStamp(timeStamp *ts){
		free(ts->sec);
	}

	void stamp(timeStamp *ts){
		ts->sec[ts->timeCount] = get_time_sec();
		( ts->timeCount )++;
	}
	void print_timeStamp(timeStamp *ts){
		size_t i;
		for(i=1;i<ts->timeCount;i++){
			printf("%f,s\n",ts->sec[i] - ts->sec[i-1]);
		}
	}
	void print_timeStamp_oneLine(timeStamp *ts){
		size_t i;
		for(i=1;i<ts->timeCount;i++){
			printf("%f,s,",ts->sec[i] - ts->sec[i-1]);
		}
	}


#endif


#endif
