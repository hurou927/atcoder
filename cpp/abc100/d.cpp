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

inline int64_t cmp(vector<int64_t> &psum, int64_t s, int64_t c, int64_t t){
  //sum(s<=i<=c)
  //sum(c<i<=t)
  return abs((psum[t+1] - psum[c+1]) - (psum[c+1] - psum[s]));
}

typedef pair<int64_t, int64_t> Mm;
inline Mm binSearch(vector<int64_t> &psum, int64_t start, int64_t end){
  int64_t s = start;
  int64_t t = end;
  int64_t c;
  char b = 0;
  while (t - s > 1){ // s<c<=t
    c = (t + s) / 2;
    if (end == c){
      break;
    }
    // print(start, "<=", s, "<", c, "<=", t, "<=", end, cmp(psum, start, c, end), cmp(psum, start, c + 1, end));
    if (cmp(psum, start, c, end) <=  cmp(psum, start, c+1, end)){
      t = c;
    }else{
      s = c;
    }
  }
  // print("*", t, (psum[t + 1] - psum[start]), (psum[end+1] - psum[t + 1]));
  print(">>>>>>>>>>>>>>>>>>>>",start,"<",t,"<=",end);
  return make_pair((psum[t + 1] - psum[start]), (psum[end+1] - psum[t + 1]));
}

int main(int argc, char **argv)
{
  int64_t N = inputValue();
  vector<int64_t> A;
  A.reserve(N);
  inputVector(A, N);
  vector<int64_t> psum(N+1);
  psum[0]=0;
  FOR(i,0,N){
    psum[i+1] = A[i] + psum[i];
  }
  // print("ALL", psum[N]);

  // int64_t start = 0;
  // int64_t end = N-1;
  // // binSearch(psum, start, end-1);
  // FOR(i,1,N-1){
  //   // print(i,cmp(psum, start, i, end));
  //   auto mm0 = binSearch(psum, start, i); //start<c<=end
  //   auto mm1 = binSearch(psum, i, end-1);
  //   print(i,":",mm0.first,mm0.second,mm1.first,mm1.second);
  // }


  int64_t c0=0, c1=1, c2=2;
  vector<int64_t> sum(4);
  sum[0] = A[0]; sum[1] = A[1]; sum[2] = A[2]; sum[3] = psum[N]-psum[3];

  for(int64_t c=c2+1;c<N;c++){
    if(c==N-1){
        c2 = c - 1;
        break;
      }
    int64_t s0 = sum[2] + A[c], s1 = sum[3] - A[c];// print(c,":",A[c],"||",s0,s1,sum[2],sum[3]);
    if(abs(s1-s0) >= abs(sum[3]-sum[2]) || c<c1+1){// print("*", abs(s1 - s0) , abs(sum[3] - sum[2]));
      c2 = c - 1;
      break;
    }else{// print("?", abs(s1 - s0), abs(sum[3] - sum[2]));
      sum[2]=s0; sum[3]=s1;
    }
  }
  int64_t min_diff = *std::max_element(sum.begin(), sum.end()) - *std::min_element(sum.begin(), sum.end());
  // print(c0, c1, c2, "{", sum[0], sum[1], sum[2], sum[3], "}",min_diff);
  for(c1=c1+1;c1<N-2;c1++){
    sum[1] = sum[1] + A[c1];
    sum[2] = sum[2] - A[c1];

    for(int64_t c=c0+1;c<N;c++){
      int64_t s0 = sum[0] + A[c], s1 = sum[1] - A[c];// print(c,":",A[c],"||",s0,s1,sum[2],sum[3]);
      if(abs(s1-s0) >= abs(sum[1]-sum[0]) || c<c0+1 || c==c1){// print("*", abs(s1 - s0) , abs(sum[3] - sum[2]));
        c0 = c - 1;
        break;
      }else{// print("?", abs(s1 - s0), abs(sum[3] - sum[2]));
        sum[0]=s0; sum[1]=s1;
      }
    }

    for(int64_t c=c2+1;c<N;c++){
      int64_t s0 = sum[2] + A[c], s1 = sum[3] - A[c];// print(c,":",A[c],"||",s0,s1,sum[2],sum[3]);
      if(abs(s1-s0) >= abs(sum[3]-sum[2]) || c<c1+1 || c==N-1){// print("*", abs(s1 - s0) , abs(sum[3] - sum[2]));
        c2 = c - 1;
        break;
      }else{// print("?", abs(s1 - s0), abs(sum[3] - sum[2]));
        sum[2]=s0; sum[3]=s1;
      }
    }


    int64_t diff = *std::max_element(sum.begin(), sum.end()) - *std::min_element(sum.begin(), sum.end());
    min_diff = min(min_diff, diff);
    // print(c0, c1, c2, "{", sum[0], sum[1], sum[2], sum[3], "}", min_diff);
  }

  cout<< min_diff <<endl;

  return 0;
}
