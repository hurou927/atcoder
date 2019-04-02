#ifndef _MY_RANDOM_HPP_
#define _MY_RANDOM_HPP_

#if __cplusplus >= 201103L

#include <random>


class mrand{
public:
	mrand();
	mrand(int a,int b);
	mrand(double a,double b);
	int rand();
	long long int llrand();
	double rrand();
	void init();
    int operator()() { return this->rand();}
private:
	std::mt19937 mt;
	std::mt19937_64 mt64;
	std::uniform_int_distribution<> randuni;
	std::uniform_real_distribution<> real_randuni;
	int flag;
};

int mrand ::rand(){
	if(flag==1) return mt();
	else	 return randuni(mt);
}
long long int mrand ::llrand(){
	return mt64();
}

double mrand ::rrand(){
	if(flag==1) return mt()/mt();
	else return real_randuni(mt);
}

mrand ::mrand(){
	this->init();
	flag=1;
}

mrand ::mrand(int a,int b){
	this->init();
	std::uniform_int_distribution<> randunitmp(a,b);
	randuni=randunitmp;
	flag=0;
}
mrand ::mrand(double a,double b){
	this->init();
	std::uniform_real_distribution<> real_randunitmp(a,b);
	real_randuni=real_randunitmp;
	flag=2;
}
void mrand ::init(){
	std::random_device seed,seed2;
	std::mt19937 engine(seed());
	std::mt19937_64 engine64(seed2());
	mt=engine;
	mt64=engine64;
}

#endif

#endif
