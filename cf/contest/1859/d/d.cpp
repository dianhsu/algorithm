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
struct Line {
  int l, r, a, b;
};
struct Node {
  int l, r, v;
  Node(const int &il, const int &ir, const int &iv) : l(il), r(ir), v(iv) {}
  bool operator<(const Node &o) const { return l < o.l; }
};
int fa[200005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<Line> intervals(n);
    for (auto &it : intervals) {
      cin >> it.l >> it.r >> it.a >> it.b;
    }
    sort(itr(intervals), [](const Line &it1, const Line &it2) {
      return it1.b < it2.b;
    });
    auto &&tf = [&](auto &&self, int x) {
      if (fa[x] == x)
        return x;
      return fa[x] = self(self, fa[x]);
    };
    set<Node> odt;
    odt.insert(Node(0, inf, -1));
    auto &&split = [&](int x) {
      if (x > inf)
        return odt.end();
      auto it = prev(odt.upper_bound(Node(x, inf, inf)));
      if (it->l == x)
        return it;
      int l = it->l, r = it->r, v = it->v;
      odt.erase(it);
      odt.insert(Node(l, x - 1, v));
      return odt.insert(Node(x, r, v)).first;
    };
    auto &&assign = [&](int l, int r, int v) {
      auto itr = split(r + 1), itl = split(l);
      odt.erase(itl, itr);
      odt.insert(Node(l, r, v));
    };
    queue<int> qIdx;
    for (int i = 0; i < n; ++i) {
      fa[i] = i;
      while (!qIdx.empty()) {
        auto idx = qIdx.front();
        if (intervals[idx].b < intervals[i].l) {
          fa[idx] = i - 1;
          qIdx.pop();
        } else {
          break;
        }
      }
      assign(intervals[i].l, intervals[i].r, i);
      qIdx.push(i);
    }
    while (!qIdx.empty()) {
      auto idx = qIdx.front();
      fa[idx] = n - 1;
      qIdx.pop();
    }
    int q;
    cin >> q;
    vector<int> ans;
    while (q--) {
      int cur;
      cin >> cur;
      auto it = prev(odt.upper_bound({cur, inf, inf}));
      int idx = it->v;
      if(idx != -1){
        ans.push_back(max(intervals[tf(tf, idx)].b, cur));
      }else{
        ans.push_back(cur);
      }
    }
    for(auto& it: ans ) cout << it << " ";
    cout << endl;
  }

  return 0;
}
