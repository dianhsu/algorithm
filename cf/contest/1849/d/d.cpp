#include <bits/stdc++.h>

using namespace std;
#define sx(x) ((x) * (x))
#define vx(x) (sx(x) * (x))
#define itr(x) begin(x), end(x)
#define debug(x...)                                                            \
  do {                                                                         \
    cout << "\033[32;1m" << #x << " -> ";                                      \
    rd_debug(x);                                                               \
  } while (0)

void rd_debug() { cout << "\033[39;0m" << endl; }

template <class T, class... Ts> void rd_debug(const T& arg, const Ts &...args) {
  cout << arg << " ";
  rd_debug(args...);
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const double eps = 1e-7;
const int MOD1 = 1e9 + 7;
const int MOD9 = 998244353;
const int inf = 0x3f3f3f3f;
const ll infl = 0x3f3f3f3f3f3f3f3fll;

int __INIT_IO__ = [](){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);
  return 0;
}();

int main() {
  int n;
  cin >> n;
  vector<int> arr;
  for(int i = 0; i < n; ++i){
    int tv;
    cin >> tv;
    if(tv == 0){
      arr.push_back(tv);
    }else if(!arr.empty() and arr.back() != 0){
      arr.back() = max(arr.back(), tv);
    }else{
      arr.push_back(tv);
    }
  }
  stack<int> st;
  int ans = 0;
  for(auto& it: arr){
    if(st.empty()){
      st.push(it);
    }else if(st.top() == 0){
      if(it == 0){
        ++ans;
      }else if(it == 1){
        st.pop();
        ++ans;
      }else{
        st.push(it);
      }
    }else{
      if(st.top() == 1){
        st.pop();
        ++ans;
      }else{
        st.pop();
        ++ans;
        if(!st.empty()) st.pop();
      }
    }
  }
  while(!st.empty()){
    if(st.top() == 1 or st.top() == 2){
      st.pop();
      ++ans;
      if(!st.empty()) st.pop();
    }else{
      st.pop();
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}

