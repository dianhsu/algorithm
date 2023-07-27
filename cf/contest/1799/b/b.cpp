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
    set<PII> st;
    vector<int> arr(n);
    bool containsOne = false;
    bool containsOther = false;
    for (auto &x : arr) {
      cin >> x;
      if (x == 1) {
        containsOne = true;
      } else {
        containsOther = true;
      }
    }
    if (containsOne and containsOther) {
      cout << -1 << "\n";
    } else if (containsOne) {
      cout << 0 << "\n";
    } else if (n == 1) {
      cout << 0 << "\n";
    } else {
      for (int i = 0; i < n; ++i) {
        st.insert({arr[i], i});
      }
      vector<PII> ops;
      while (st.begin()->first < st.rbegin()->first) {
        auto maxv = *st.rbegin();
        st.erase(maxv);
        ops.push_back({maxv.second + 1, st.begin()->second + 1});
        maxv.first = (maxv.first + st.begin()->first - 1) / st.begin()->first;
        st.insert(maxv);
      }
      //debug(st.begin()->first, st.rbegin()->first);
      cout << ops.size() << "\n";
      for(auto& it: ops){
        cout << it.first << " " << it.second << "\n";
      }
    }
  }
  return 0;
}
