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
#define LEFT (cur << 1)
#define RIGHT (LEFT | 1)
#define MID ((l + r) >> 1)

class Seg {
public:
  Seg(int len) : node((len << 2) + 10, 0) {}
  void insert(int cur, int l, int r, int p, int v) {
    if (l == r) {
      node[cur] = v;
      return;
    }
    if (p <= MID) insert(LEFT, l, MID, p, v);
    else insert(RIGHT, MID + 1, r, p, v);
    node[cur] = (node[LEFT] | node[RIGHT]);
  }
  int query(int cur, int l, int r, int st, int ed) {
    if (ed < l or r < st) return 0;
    if (st <= l and r <= ed) return node[cur];
    return query(LEFT, l, MID, st, ed) | query(RIGHT, MID + 1, r, st, ed);
  }
private:
  vector<int> node;
};
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
      int n, q;
      cin >> n >> q;
      map<PII, ll> cache;
      auto&& getStringPosition = [&](auto&& self, int p, int l) -> ll {
        if (cache.count({ p, l })) return cache[{p, l}];
        if (l == 1) return cache[{p, l}] = p;
        return cache[{p, l}] = self(self, p % n + 1, l - 1) + n - 1;
        };
      vector<int> arr(n + 1, 0);
      vector<set<int>> st(32);
      Seg seg(n);
      for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        seg.insert(1, 1, n, i, arr[i]);
        for (int j = 0; j < 32; ++j) {
          if (arr[i] & (1 << j)) {
            st[j].insert(i);
          }
        }
      }

      vector<PII> qrr(n);
      for (int i = 0; i < n; ++i) {
        cin >> qrr[i].first;
        qrr[i].second = i;
      }
      vector<ll> ans(n, infl);
      sort(qrr.begin(), qrr.end());
      auto&& update_qrr = [&](int curp, int curl) {
        int tv = 0;
        if (n - curp + 1 >= curl) {
          tv = seg.query(1, 1, n, curp, curp + curl - 1);
        } else {
          int len1 = n - curp + 1;
          tv += seg.query(1, 1, n, curp, n);
          tv += seg.query(1, 1, n, 1, curl - len1);
        }
        auto qp = upper_bound(qrr.begin(), qrr.end(), PII{ tv, inf });
        if (qp != qrr.begin()) {
          int pos = (int)distance(qrr.begin(), qp) - 1;
          ans[pos] = min(ans[pos], getStringPosition(getStringPosition, curp, curl));
        }
        };
      for (int i = 1; i <= n; ++i) {
        int curp = i, curl = 1;
        update_qrr(curp, curl);
        int curv = arr[i];
        bool ok = true;
        for(int j = 0; j < 32 and ok; ++j){
          ok = false;
          int nex = inf;
          for(int k = 0; k < 32; ++k){
            if((curv & (1 << k)) == 0){
              if(st[k].upper_bound((curp + curl) % n + 1) != st[k].end()){
                int p = *(st[k].upper_bound((curp + curl) % n + 1));
              }else if(!st[k].empty()){
                int p = *st[k].begin();
              }
            }
          }
        }
      }
    }

    return 0;
  }

