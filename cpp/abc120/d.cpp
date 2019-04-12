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
 
void print() { std::cout << std::endl; }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail)
{
  std::cout << head << ",";
  print(std::forward<Tail>(tail)...);
}
 
using namespace std;
 
typedef pair<int64_t, int64_t> EDGE;
 
int main(int argc, char **argv)
{
  int64_t N = inputValue<int64_t>();
  int64_t M = inputValue<int64_t>();
  vector<EDGE> edges(M);
 
  int64_t *belongTo = new int64_t [N];
  int64_t *nodes = new int64_t [N];
  int64_t *inconvs = new int64_t [M+1];
  vector <list<int64_t>> graph(N, list<int64_t>(1));
 
  for(int i=0;i<N;i++){
    belongTo[i]=i;
    nodes[i] = 1;
    *(graph[i].begin()) = i;
  }
  // print(N, M);
  for(int i=0;i<M;i++){
    int64_t s = inputValue<int64_t>();
    int64_t e = inputValue<int64_t>();
    edges[i] = EDGE(s-1, e-1);
    
    // print(edges[i].first, edges[i].second);
  }
 
 
  int64_t sum = 0;
  int64_t max_inconv = N*(N-1)/2;
  inconvs[M] = max_inconv - sum;
  // print(M, ":", sum, inconvs[M] );
  for(int i=M-1; i>=0; i--){
    int64_t s = edges[i].first;
    int64_t e = edges[i].second;
 
    int64_t s_parent = belongTo[s];
    int64_t e_parent = belongTo[e];
 
 
    if (s_parent == e_parent) {
      inconvs[i] = max_inconv - sum;
      // print(i, ":", sum, inconvs[i] );
      continue;
    }
 
    // print("#", nodes[s_parent], nodes[e_parent]);
    sum += nodes[s_parent] * nodes[e_parent];
    // print(i, ":", sum, inconvs[i] );
    inconvs[i] = max_inconv - sum;
 
    int64_t ori =  s_parent;
    int64_t dep =  e_parent;
 
    // print("#",graph[ori].size(), graph[dep].size());
    if (nodes[dep] > nodes[ori]){
      swap(ori, dep);
    }
    
    // print(graph[ori].size(), graph[dep].size());
    nodes[ori] += nodes[dep];
    EACH(node, graph[dep]) {
      belongTo[*node]=ori;
    }
    graph[ori].splice(graph[ori].end(), move(graph[dep]));
  }
 
 
  for(int i=1;i<=M;i++){
    cout << inconvs[i] << endl;
  }
 
  free(belongTo);
  free(nodes);
  return 0;
}