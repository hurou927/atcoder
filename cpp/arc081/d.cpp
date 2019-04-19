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


void print() { std::cout << std::endl; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail){
  std::cout << head << ",";
  print(std::forward<Tail>(tail)...);
}

using namespace std;


int main(int argc, char **argv)
{
  int64_t N;
  int64_t m = 1000000007;
  scanf("%lld", &N);
  char *s1 = new char [N];
  char *s2 = new char [N];
  getc(stdin);
  FOR(i, 0, N){
      s1[i] = getc(stdin);
  }
  getc(stdin);
  FOR(i, 0, N){
      s2[i] = getc(stdin);
  }

  int64_t lut[2][2] = {{2,2},{1,3}};

  int64_t pre = s1[0] != s2[0];  // 0 : |, 1: =
  int64_t s = pre ? 6 : 3;
  int index = pre ? 2 : 1;
  // print(0, pre, s);
  for(int i=index;i<N;i=i+index){
    int64_t cur = s1[i] != s2[i];
    s = s * lut[pre][cur];
    pre = cur;
    index = cur ? 2 : 1;
    s = (s > (1ll<<50)) ? s%m : s;
  }

  cout << s % m << endl;

  free(s1); free(s2);
  return 0;
  }
