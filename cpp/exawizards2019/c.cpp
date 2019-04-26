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

void solve0(){
  int64_t N, Q;
  scanf("%lld%lld", &N, &Q);
  vector<char> s(N);
  vector<pair<char, char>> td(Q);
  getc(stdin);
  for (int i = 0; i < N; i++)
  {
    s[i] = getc(stdin);
  }
  getc(stdin);
  for (int i = 0; i < Q; i++)
  {
    char t, d;
    scanf("%c %c\n", &t, &d);
    td[i] = make_pair(t, d);
    // print(t,d);
  }

  int L = 0;
  int R = N - 1;
  for (int i = Q - 1; i >= 0; i--)
  {
    char t = td[i].first;
    char d = td[i].second;
    if (L<N && d == 'L') L = L + (t == s[L]);
    else if (L<N && L > 0) L = L - (t == s[L - 1]);

    if (R>=0 && d == 'R') R = R - (t == s[R]);
    else if (R>=0 && R < N - 1) R = R + (t == s[R + 1]);
  }
  

  
  // for (int i = Q - 1; i >= 0; i--)
  // {
  //   char t = td[i].first;
  //   char d = td[i].second;

  //   if (d == 'R') R = R - (t == s[R]);
  //   else if (R < N - 1) R = R + (t == s[R + 1]);
  //   if (R < 0) break;
  // }
  // print(L, R);
  cout << (L <= R ? R - L + 1 : 0) << endl;
}

int main(int argc, char **argv)
{
  solve0(); //wrong answer
  return 0;
}
