#include <bits/stdc++.h>

using namespace std;
#define PF(x) ((x) * (x))
#define LF(x) (PF(x) * (x))
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
    map<int, PII> mp;
    vector<int> vis(n, 0);
    vector<int> ans;
    set<int> st, del;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      cin >> mp[i].first;
      q.push(i);
    }
    for (int i = 0; i < n; ++i) {
      cin >> mp[i].second;
    }
    for (int i = 0; i < n; ++i) {
      while (!q.empty()) {
        auto it = q.front();
        q.pop();
        auto ptr = mp.find(it);
        if (ptr == mp.begin() and next(ptr) == mp.end()) {
          continue;
        } else if (ptr == mp.begin()) {
          auto nxt = next(ptr);
          if (nxt->second.first > ptr->second.second) {
            del.insert(ptr->first);
            st.insert(nxt->first);
          }
        } else if (next(ptr) == mp.end()) {
          auto pre = prev(ptr);
          if (pre->second.first > ptr->second.second) {
            del.insert(ptr->first);
            st.insert(pre->first);
          }
        } else {
          auto pre = prev(ptr);
          auto nxt = next(ptr);
          if (pre->second.first + nxt->second.first > ptr->second.second) {
            del.insert(ptr->first);
            st.insert(pre->first);
            st.insert(nxt->first);
          }
        }
      }
      for (auto &it : st) {
        if (del.contains(it))
          continue;
        q.push(it);
      }
      ans.push_back(del.size());
      st.clear();
      for (auto &it : del) {
        mp.erase(it);
      }
      del.clear();
    }
    for (auto& it: ans) cout << it << " "; cout << endl;
  }
  return 0;
}