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
T inputValue(){
  T a;
  std::cin >> a;
  // scanf("%llu", &a);
  return a;
}

void inputArray(int *p, int a){
  rep(i, a){
    std::cin >> p[i];
    // scanf("%d",p+i);
  }
}

template <typename T>
void inputVector(std::vector<T> *p, int a){
  rep(i, a){
    T input;
    std::cin >> input;
    // scanf("%llu", &input);
    p->push_back(input);
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

struct Edge{
  int64_t from;
  int64_t to;
  int64_t w;
};

struct DNode {
  int64_t cost;
  int64_t prev;
};

const int64_t INF = INT64_MAX;
std::vector<DNode> dijkstra(std::vector<std::vector<Edge>> &adj, const int64_t nodeCount, int64_t start)
{
  typedef std::pair<int64_t, int64_t> P; // first: weight, second: node_index

  std::vector<DNode> dinfo(nodeCount, DNode{INF, -1});
  std::priority_queue<P, vector<P>, greater<P>> q;

  dinfo[start] = DNode{0, -1};
  q.push(P(0, start));

  while(q.size() != 0) {

    P n = q.top();
    q.pop();
    int64_t fCost = n.first;
    int64_t fNode = n.second;

    if(dinfo[fNode].cost< fCost) {
      continue;
    }
    //     cost_S2F     cost_F2N
    // [S] --....-->[F]---------|
    //  |----....--------[N]<---|
    //      cost_S2N

    int64_t cost_S2F = dinfo[fNode].cost;
    for (auto i = (adj[fNode]).begin(); i != (adj[fNode]).end(); ++i){
      int64_t nNode = (*i).to;
      int64_t cost_F2N = (*i).w;
      int64_t cost_S2N = dinfo[nNode].cost;

      if(cost_S2F + cost_F2N < cost_S2N){
        dinfo[nNode].cost = cost_S2F + cost_F2N;
        q.push(P(dinfo[nNode].cost, nNode));
        dinfo[nNode].prev = fNode;
      }
    }

  }

  // EACH(i, dinfo){
  //   print("|", (*i).cost, (*i).prev);
  // }

  return dinfo;
}


std::vector<DNode> spfa(std::vector<std::vector<Edge>> &adj, const int64_t nodeCount, int64_t start)
{
  typedef std::pair<int64_t, int64_t> P; // first: weight, second: node_index

  std::vector<DNode> dinfo(nodeCount, DNode{INF, -1});
  std::priority_queue<P, vector<P>, greater<P>> q;
  std::vector<bool> inQ(nodeCount, false);

  dinfo[start] = DNode{0, -1};
  q.push(P(0, start));
  inQ[start] = true;

  while(q.size() != 0) {

    P n = q.top();
    q.pop();
    int64_t fCost = n.first;
    int64_t fNode = n.second;
    inQ[fNode] = false;

    // if(dinfo[fNode].cost< fCost) {
    //   continue;
    // }
    //     cost_S2F     cost_F2N
    // [S] --....-->[F]---------|
    //  |----....--------[N]<---|
    //      cost_S2N

    int64_t cost_S2F = dinfo[fNode].cost;
    for (auto i = (adj[fNode]).begin(); i != (adj[fNode]).end(); ++i){
      int64_t nNode = (*i).to;
      int64_t cost_F2N = (*i).w;
      int64_t cost_S2N = dinfo[nNode].cost;

      if(cost_S2F + cost_F2N < cost_S2N){
        dinfo[nNode].cost = cost_S2F + cost_F2N;
        dinfo[nNode].prev = fNode;
        if(inQ[nNode] == false){
          q.push(P(dinfo[nNode].cost, nNode));
          inQ[nNode] = true;
        }
      }
    }

  }

  return dinfo;
}


int main(int argc, char **argv)
{
  int64_t W = 1000000000000000;

  int64_t N,M,s,t;
  cin >> N >> M >> s >> t;

  s--; t--;
  // print(N,M,s,t);

  vector<int64_t> u(M), v(M), a(M), b(M);

  FOR(i,0,M){
    cin >>  u[i] >> v[i] >> a[i] >> b[i];
    u[i]--; v[i]--;
    // print(u[i], v[i], a[i], b[i]);
  }

  vector<vector<Edge>> graphYen(N);
  vector<vector<Edge>> graphDoll(N);

  FOR(i,0,M){
    graphYen[u[i]].push_back(Edge{u[i], v[i], a[i]});
    graphYen[v[i]].push_back(Edge{v[i], u[i], a[i]});
    graphDoll[u[i]].push_back(Edge{u[i], v[i], b[i]});
    graphDoll[v[i]].push_back(Edge{v[i], u[i], b[i]});
  }
  vector<DNode> &&fromStart = spfa(graphYen, N, s);
  vector<DNode> &&fromEnd = spfa(graphDoll, N, t);
  // print(fromStart.size());

  typedef std::pair<int64_t, int64_t> P;
  vector<P> costs(N);
  FOR(i, 0, N){
    costs[i] = P(W - (fromStart[i].cost+fromEnd[i].cost), i);
  }

  sort(costs.begin(), costs.end(), greater<P>());


  // FOR(i,0,N){
    // print(costs[i].second, costs[i].first);
    // print(i, ">",fromStart[i].cost,"|", fromEnd[i].cost,fromStart[i].cost+fromEnd[i].cost);
    // print(fromStart[i].cost+fromEnd[i].cost);
    // print(W-(fromStart[i].cost+fromEnd[i].cost));
  // }

  int64_t k = 0;
  FOR(i,0,N){
    while(i>costs[k].second){
      k++;
    }
    cout << costs[k].first << endl;
  }


  return 0;
}
