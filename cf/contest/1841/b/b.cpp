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
  int t;
  cin >> t;
  while(t--){
    int q;
    cin >> q;
    string ans;
    bool retry = false;
    vector<int> arr;
    for(int i = 0; i < q; ++i){
      int tv;
      cin >> tv;
      if(arr.empty()){
        arr.push_back(tv);
        ans.push_back('1');
      }else{
        if(retry){
          if(tv >= arr.back() and tv <= arr.front()){
            arr.push_back(tv);
            ans.push_back('1');
          }else{
            ans.push_back('0');
          }
        }else{
          if(tv >= arr.back()){
            arr.push_back(tv);
            ans.push_back('1');
          }else if(tv <= arr.front()){
            arr.push_back(tv);
            ans.push_back('1');
            retry = true;
          }else{
            ans.push_back('0');
          }
        }
      }
    }
    cout << ans << "\n";
  }

  return 0;
}

