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

struct Edge {
  int64_t f, t, w;
};
typedef vector<vector<Edge>> Graph;

void printGraph(vector<vector<Edge>> G) {
  for(int i=0;i<G.size();i++){
    cout << setw(3) << i << "->";
    EACH(j,G[i]){
      cout  << setw(3) << (*j).t << "(" << (*j).w << ")";
    }
    cout << endl;
  }
}

bool isBipartite;
vector<int16_t> visited;
void dfs(Graph &G){
  int64_t N = G.size();
  visited = vector<int16_t>(N+1,0);
  stack<Edge> st;
  st.push(Edge{N,0,0});
  visited[N] = 2;
  isBipartite = true;
  while(!st.empty()){
    auto top = st.top();
    st.pop();
    int64_t from = top.f, to = top.t;
    if(visited[to]!=0){
      continue;
    }
    visited[to] = 3 - visited[from];
    // print(to, visited[to]);
    for(auto i=G[to].begin();i!=G[to].end();i++){
      if(visited[(*i).t] == 0) {
        st.push((*i));
      }else{
        if (visited[(*i).t] == visited[to]){
          isBipartite = false;
        }
      }
    }
  }
  // cout << isBipartite << endl;
}

int main(int argc, char **argv)
{
  int64_t N = inputValue(), M = inputValue();    
  Graph G(N, vector<Edge>());
  FOR(i,0,M){
    int64_t A, B;
    scanf("%lld%lld",&A, &B);
    A--; B--;
    G[A].push_back(Edge{A,B,1});
    G[B].push_back(Edge{B,A,1});
  }

  // printGraph(G);


  dfs(G);
  if(isBipartite == true) {
    int64_t B = 0;
    for(int i=0;i<N;i++){
      B += (visited[i]==1);
    }
    cout << B * (N-B) - M << endl;
  } else {
    cout << N * (N-1) / 2 - M << endl;
  }

  return 0;
}
