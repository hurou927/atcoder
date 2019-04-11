// https://atcoder.jp/contests/abc118/tasks/abc118_c

// http://ctylim.hatenablog.com/entry/2015/08/30/191553
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstdio>

#define INDEX(W, h, w) ((W) * (h) + (w))
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
typedef pair<int, int> P;

void move(int *visited, int *input, stack<P> &st, int H, int W, int center_h, int center_w, int neighbor_h, int neighbor_w)
{
  if (neighbor_h >= 0 &&
      neighbor_w >= 0 &&
      neighbor_h < H &&
      neighbor_w < W &&
      input[INDEX(W, center_h, center_w)] != input[INDEX(W, neighbor_h, neighbor_w)] &&
      !visited[INDEX(W, neighbor_h, neighbor_w)])
  {
    visited[INDEX(W, neighbor_h, neighbor_w)] = 1;
    st.push(P(neighbor_h, neighbor_w));
  }
}

int main(int argc, char **argv)
{
  int H = inputValue<int>();
  int W = inputValue<int>();
  int *input = new int [H*W];
  int *visited = new int [H*W];

  vector<list<int>> graph(H * W, list<int>());
  int i = 0;
  char c;
  while ((c = getc(stdin)) != EOF) {
    if  (c == '#' || c == '.') {
      input[i++] = (c=='.'); // if black(#) is 0, otherwise 1  
    }
  }

  
  for(int i=0; i<H*W; i++){
    visited[i] = 0;
  }

 
  stack<P> st;
  ulli sum = 0;
  for (int i=0; i<H; i++){
    for(int j=0; j<W; j++){
      if (visited[INDEX(W, i, j)])
      {
        continue;
      }
      st.push(pair<int, int>(i, j));
      ulli ones = 0;
      ulli N = 0;
      while (st.size() != 0)
      {
        P p = st.top();
        st.pop();
        int y = p.first;
        int x = p.second;
        // cout <<i<<"#"<<j<<"|" << y << "," << x << "," << st.size() << endl;
        visited[INDEX(W, y, x)] = 1;
        N++;
        ones = ones + ulli(input[INDEX(W, y, x)]);

        move(visited, input, st, H, W, y, x, y - 1, x);
        move(visited, input, st, H, W, y, x, y + 1, x);
        move(visited, input, st, H, W, y, x, y, x - 1);
        move(visited, input, st, H, W, y, x, y, x + 1);
      }
      // cout << N << "#" << ones << endl;
      sum = sum + ones * (N-ones);
    }
  }

  // for (int i=0; i<H; i++){
  //   for(int j=0; j<W; j++){
  //     cout << input[INDEX(W, i, j)];
  //   }
  //   cout << endl;
  // }
    cout << sum << endl;
    free(input);
    free(visited);
    return 0;
}
