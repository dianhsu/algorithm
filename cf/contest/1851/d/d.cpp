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

template <class T, class... Ts> void rd_debug(const T &arg, const Ts &...args) {
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

int __INIT_IO__ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);
  return 0;
}();

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 1; i < n; ++i) {
      cin >> arr[i];
    }
    if (arr.back() > 1ll * n * (n + 1) / 2) {
      cout << "NO\n";
      continue;
    }else if(arr.back() < 1ll * n * (n + 1) / 2){
      arr.push_back(1ll * n * (n + 1) / 2 );
      bool ok = true;
      set<ll> st;
      for(int i = 1; i <= n; ++i){
        if(st.count(arr[i] - arr[i - 1])){
          ok = false;
          break;
        }
        st.insert(arr[i] - arr[i - 1]);
      }
      if(ok){
        cout << "YES\n";
      }else{
        cout << "NO\n";
      }
      continue;
    }
    set<ll> st1, st2;
    for(int i = 1; i <= n; ++i) st1.insert(i);
    for (int i = 1; i < n; ++i) {
      if (!st1.count(arr[i] - arr[i - 1])) {
        st2.insert(arr[i] - arr[i - 1]);
      } else {
        st1.erase(arr[i] - arr[i - 1]);
      }
    }
    ll sum = 0;
    for(auto& it: st1) sum += it;
    cout << (st1.size() == 2 and st2.size() == 1 and sum == *st2.begin() ? "YES\n" : "NO\n");
  }
  return 0;
}
