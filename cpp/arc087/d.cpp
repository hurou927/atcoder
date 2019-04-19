// https://atcoder.jp/contests/abc082/tasks/arc087_b
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


int main(int argc, char **argv)
{
  char c = 0;
  
  char s[8000];
  int len = 0;
  while (( c = getc(stdin)) != EOF && (c == 'T' || c == 'F') ) {
    s[len++] = c;
  }
  int64_t x, y;
  scanf("%lld%lld",&x, &y);


  vector<int64_t> X;
  X.reserve(len);
  vector<int64_t> Y;
  Y.reserve(len);

  int64_t xlen = 0;
  int64_t ylen = 0;

  
  int64_t sum = 0;
  
  // cout << len << endl;
  char state = 'x';
  FOR(i,0,len){
    if(s[i]=='T'){
      // cout << sum << endl;
      if(sum!=0){
        if(state=='x'){
          X.push_back(sum);
          print('x', sum);
        }else{
          Y.push_back(sum);
          print('y', sum);
        }
      }
      state = (state=='x') ? 'y' : 'x';
      sum=0;
    }else{
      sum++;
    }
  }
  if(sum!=0){
    if(state=='x'){
      X.push_back(sum);
      print('x', sum);
    }else{
      Y.push_back(sum);
      print('y', sum);
    }
  }

  // もし，最初がTなら
  if(s[0] == 'F' && X.size()>0){
    x = x - X[0];
    X.erase(X.begin());
  }

  sum = 0;
  FOR(i, 0, X.size()){
    sum += X[i];
    X[i] = X[i] * 2;
  }
  x = x + sum;

  sum = 0;
  FOR(i, 0, Y.size()){
    sum += Y[i];
    Y[i] = Y[i] * 2;
  }
  y = y + sum;


  int h = max(X.size(),Y.size());
  vector<vector<char>> dp( max(h,1) , vector<char>(max(x+1,y+1), 0));

  print("X,Y = ",x,y);
  print("DP:",x+1,"X",X.size(),"=================");


  FOR(i,0,X.size()){
    dp[i][0] = 0==x;
  }
  FOR(m,1,x+1){
    dp[0][m] = m==X[0];
  }

  FOR(i,1,X.size()){
    FOR(m,1,x+1){
      dp[i][m] = (dp[i-1][m] == 1) || ( m>=X[i] && dp[i-1][m-X[i]]==1 );
    }
  }

  FOR(i,0,X.size()){
    FOR(m,0,x+1){
      printf("%d,",dp[i][m]);
    }
    cout << endl;
  }

  if(X.size() == 0) {
    if(x == 0) {
      cout << "Yes" << endl;
    }else{
      cout << "NO" << endl;
    }
  }else if(dp[X.size()-1][x] == 1) {
    cout << "Yes" << endl;
  }else{
    cout << "NO" << endl;
  }

  return 0;
}
