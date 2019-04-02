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

int inputValue(){
  int a;
  std::cin >> a;
  return a;
}

void inputArray(int *p, int a){
    rep(i, a){
        std::cin >> p[i];
    }
}

void inputVector(std::vector<int> *p, int a){
  rep(i, a){
    int input;
    std::cin >> input;
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

using namespace std;

void shrink(vector<int> &v){
  int newIndex = 0;
  v[newIndex++] = v[0];
  for (int i = 1; i < v.size(); i++){
    if (v[newIndex - 1] != v[i]){
      v[newIndex++] = v[i];
    }
  }
  v.resize(newIndex);
}

pair<int, int> findMinDiff(vector<int> &v){
  int min = INT32_MAX;
  int index = -1;
  for (int i = 1; i < v.size(); i++){
    int diff = v[i] - v[i - 1];
    if (diff != 0 && min > diff){
      min = diff;
      index = i;
    }
  }
  return make_pair(min, index);
}

void insert(vector<int> &v, int min, int index){
  v.erase(v.begin() + index);
  for (auto i = (v).begin(); i != (v).end(); ++i){
    if (i == (v).begin()){
      if (*i >= min){
        v.insert(i, min);
        break;
      }
    }
    else{
      if (*i >= min && min >= *(i - 1)){
        v.insert(i, min);
        break;
      }
    }
  }
}


int main(int argc ,char **argv){

  int N = inputValue();
  vector <int> v;
  inputVector(&v, N);

  SORT(v);


  for(int i=0;i<10;i++){
  // while(1){
    shrink(v);
    if (v[0] == 1 || v.size() == 1) {
      cout << v[0] << endl;
      break;
    } else if (v.size() == 2){
      int mod = v[1] % v[0];
      cout << (mod == 0 ? v[0] : mod) << endl;
      break;
    } 

    auto p = findMinDiff(v);
    int min = p.first;
    int index = p.second;
    // cout << min << "," << index << endl;

    if(index != -1) {
      insert(v, min, index);
    }


    // EACH(k, v)
    //   cout << *k << ",";
    // cout << endl;
  }


	return 0;
}