#include <bits/stdc++.h>

using namespace std;
#define InitIO() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout << fixed << setprecision(12)
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

#define MULTIPLE_CASES

void solve(int);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int kase = 1;
#ifdef MULTIPLE_CASES
  cin >> kase;
#endif
  for (int i = 1; i <= kase; ++i) {
    solve(i);
  }
  return 0;
}
#define LEFT (cur << 1)
#define RIGHT (LEFT | 1)
#define MID ((l + r) >> 1)
void solve(int case_idx) {
  int n, m;
  cin >> n >> m;
  vector<PII> seg(m);
  for (auto& it : seg) cin >> it.first >> it.second;
  int q;
  cin >> q;
  vector<int> qrr(q);
  for (auto& it : qrr) cin >> it;
  auto&& handle = [&](int pos) -> bool {
    vector<int> node((n << 2) + 10, 0);
    auto&& insert = [&](auto&& self, int cur, int l, int r, int p, int v) -> void {
      if (l == r) {
        node[cur] = v;
        return;
      }
      if (p > MID) self(self, RIGHT, MID + 1, r, p, v);
      else self(self, LEFT, l, MID, p, v);
      node[cur] = node[LEFT] + node[RIGHT];
      };
    auto&& query = [&](auto&& self, int cur, int l, int r, int st, int ed) -> int {
      if (ed < l or r < st) return 0;
      if (st <= l and r <= ed) return node[cur];
      return self(self, LEFT, l, MID, st, ed) + self(self, RIGHT, MID + 1, r, st, ed);
      };
    for (int i = 0; i < pos; ++i) {
      insert(insert, 1, 1, n, qrr[i], 1);
    }
    for (int i = 0; i < m; ++i) {
      if (query(query, 1, 1, n, seg[i].first, seg[i].second) * 2 > seg[i].second - seg[i].first + 1) {
        return true;
      }
    }
    return false;
    };
  if(handle(q) == false){
    cout << -1 << "\n";
    return;
  }
  int r = q;
  for(int d = 1 << 20; d > 0; d >>= 1){
    if(r >= d and handle(r - d)){
      r -= d;
    }
  }
  cout << r << "\n";
}
