// https://atcoder.jp/contests/abc118/tasks/abc118_c

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
#include <cstdlib>
#include <cstdio>

#define ALL(a) (a).begin(), (a).end()
#define EACH(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort((c).begin(), (c).end())
#define RSORT(c) sort((c).rbegin(), (c).rend())
#define MAXINDEX(c) distance((c).begin(), max_element((c).begin(), (c).end()))
#define MININDEX(c) distance((c).begin(), min_element((c).begin(), (c).end()))
#define DEBUG(x) std::cerr << #x << " = " << (x) << " (" << __FILE__ << "::" << __LINE__ << ")" << std::endl;
#define ERROR(s) std::cerr << "Error::" << __FILE__ << "::" << __LINE__ << "::" << __FUNCTION__ << "::" << (s) << std::endl;
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)

#define repd(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) repd(i, 0, n)
typedef long long ll;


int64_t inputValue(){
  int64_t a;
  scanf("%llu", &a);
  return a;
}


void inputVector(std::vector<int64_t> &p, int64_t a){
  rep(i, a){
    int64_t input;
    scanf("%llu", &input);
    p.push_back(input);
  }
}

template <typename T>
void output(T a, int precision){
  if (precision > 0){
    std::cout << std::setprecision(precision) << a << "\n";
  }else{
    std::cout << a << "\n";
  }
}

void print() { std::cout << std::endl; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail){
  std::cout << head << ",";
  print(std::forward<Tail>(tail)...);
}

using namespace std;


int main(int argc, char **argv)
{
  int64_t N = inputValue();
  vector<int64_t> A;
  A.reserve(N);
  inputVector(A, N);
  

  print('c', 1, 2.01, 3);

  return 0;
}
