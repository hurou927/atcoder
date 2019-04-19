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

uint64_t INF = 1ll<<60;
int main(int argc, char **argv)
{
  uint64_t N, K;
  scanf("%lld%lld",&N, &K);
  vector<uint64_t> w(N);
  vector<uint64_t> d(N);

  // print(N,K);
  FOR(i,0,N){
    scanf("%lld%lld",&w[i],&d[i]);
    // print(w[i], d[i]);
  }

  uint64_t P = 0;
  uint64_t n = (K+(N-1)) / N;
  FOR(i,0,N){
    P = max(P, w[i] + n * d[i]);
  }


  uint64_t s = 1;
  uint64_t t = P;
  uint64_t c;
  
  while(s <= t) {
    c = s + (t-s)/2;
    uint64_t sum = 0;
    // uint64_t flag = 0;
    uint64_t dif = INF;
    FOR(i,0,N){
      if(c<w[i]) continue;
      sum = sum + (c-w[i])/d[i] + 1;
      dif = min(dif, (c-w[i])%d[i]);
    }
    if (sum == K ) {
      c = c - dif;
      break;
    } else if (sum < K) {
      s = c + 1;
    } else {
      t = c - 1;
    }

  }

  cout << c << endl;

  return 0;
}
