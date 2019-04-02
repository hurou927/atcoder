// http://ctylim.hatenablog.com/entry/2015/08/30/191553
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>

#include "./my_gettime.hpp"
#include "./my_random.hpp"
#include "./my_util.hpp"


#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;



int inputValue(){
    int a;
    std::cin >> a;
    return a;
};

void inputArray(int * p, int a){
    rep(i, a){
        std::cin >> p[i];
    }
};

void inputVector(std::vector<int> * p, int a){
    rep(i, a){
        int input;
        std::cin >> input;
        p -> push_back(input);
    }
}

template <typename T>
void output(T a, int precision) {
    if(precision > 0){
        std::cout << std::setprecision(precision)  << a << "\n";
    }
    else{
        std::cout << a << "\n";
    }
}
