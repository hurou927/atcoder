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


template<typename T>
bool subset(vector<T> nums, T k){
  int64_t N = nums.size();
  if (k<0){
    ERROR("parameter error");
    return false;
  }
  if (k==0) {
    return true;
  }
  if (N==0) {
    return false;
  }

  vector<vector<char>> dp(N, vector<char>(k+1, 0));

  //init
  for(int64_t m=0;m<=k;m++){
    dp[0][m] = (m==nums[0]);
  }
  for(int64_t i=1;i<N;i++){
    dp[i][0] = 1;
  }

  for (int64_t i = 1; i < N; i++){
    T num = nums[i];
    for (int64_t m = 1; m <= k; m++){
      dp[i][m] = (dp[i - 1][m] == 1) || (m >= num && dp[i - 1][m - num] == 1);
    }
    if(dp[i][k] == 1) {
      return true;
    }
  }
  
  // print("=====",N,'x',k+1);
  // cout << "==================" <<endl;
  // for (int64_t i = 0; i < N; i++){
  //   printf("[%3lld:%4lld] ", i,nums[i]);
  //   for (int64_t m = 0; m <= k; m++){
  //     printf("%d,",dp[i][m]);
  //   }
  //   cout << endl;
  // }
  // cout << "==================" << endl;

  return dp[N-1][k] == 1;
}



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
  // print(x,y);

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
          // print('x', sum);
        }else{
          Y.push_back(sum);
          // print('y', sum);
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
      // print('x', sum);
    }else{
      Y.push_back(sum);
      // print('y', sum);
    }
  }

  // もし，最初がTなら
  if(s[0] == 'F' && X.size()>0){
    x = x - X[0];
    X.erase(X.begin());
  }
  // print("X,Y",x,y);
  sum = 0;
  FOR(i, 0, X.size()){
    sum += X[i];
    X[i] = X[i] * 2;
  }
  x = x + sum;
  // print("sum of x_0-x_i",sum);
  sum = 0;
  FOR(i, 0, Y.size()){
    sum += Y[i];
    Y[i] = Y[i] * 2;
  }
  y = y + sum;
  // print("sum of y_0-y_i", sum);

  // print(">>>>>>>>>>(Nx,Ix,Ny,Iy)", X.size(),x,Y.size(),y);
  bool flag = true;
  if (X.size()==0){
    flag = flag && (x == 0);
  }else{
    flag = flag && subset(X, x);
  }
  if (Y.size()==0){
    flag = flag && (y == 0);
  }else{
    flag = flag && subset(Y, y);
  }


  cout << (flag ? "Yes" : "No") << endl;
  return 0;

}

//1_40だけ通らない