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

template <typename T>
T inputValue()
{
  T a;
  std::cin >> a;
  // scanf("%llu", &a);
  return a;
}

void inputArray(int *p, int a)
{
  rep(i, a)
  {
    std::cin >> p[i];
    // scanf("%d",p+i);
  }
}

template <typename T>
void inputVector(std::vector<T> *p, int a)
{
  rep(i, a)
  {
    T input;
    std::cin >> input;
    // scanf("%llu", &input);
    p->push_back(input);
  }
}

template <typename T>
void output(T a, int precision)
{
  if (precision > 0)
  {
    std::cout << std::setprecision(precision) << a << "\n";
  }
  else
  {
    std::cout << a << "\n";
  }
}

using namespace std;

int gcd(int a, int b)
{
  while (1)
  {
    if (a < b)
      swap(a, b);
    if (!b)
      break;
    a %= b;
  }
  return a;
}

typedef unsigned long long int ulli;
int main(int argc, char **argv)
{
  int H = inputValue<int>();
  int W = inputValue<int>();
  int *graph = new int [H*W];
  int *connect = new int [H*W];

  int i = 0;
  char c;
  while ((c = getc(stdin)) != EOF) {
    if  (c == '#' || c == '.') {
      graph[i++] = (c=='.'); // if black(#) is 0, otherwise 1  
      // cout << graph[i-1] << endl;
    }
  }

  for(int i=0; i<H*W; i++){
    connect[i] = i;
  }

  // 上から下
  for(int j=0; j<W; j++){
    for(int i=0; i<H; i++){
      
    }
  }

  free(graph);
  return 0;
}
