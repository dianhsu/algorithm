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
class DSU {
public:
  vector<int> fa;
  DSU(int n) : fa(n){ iota(fa.begin(), fa.end(), 0); }
  int tf(int x) {
    if (fa[x] == x) {
      return x;
    }
    return fa[x] = tf(fa[x]);
  }
  void mg(int x, int y) {
    int a = tf(x);
    int b = tf(y);
    if (a == b) {
      return;
    }
    fa[b] = a;
  }
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> nex(n + 2, 0), pre(n + 2, n + 1);
    for(int i = 1; i <= n; ++i){
      if(s[i - 1] == '0'){
        nex[i] = i;
      }else{
        nex[i] = nex[i - 1];
      }
    }
    for(int i = n; i >= 1; --i){
      if(s[i - 1] == '1'){
        pre[i] = i;
      }else{
        pre[i] = pre[i + 1];
      }
    }
    set<PII> st;
    while(m--){
      int l, r;
      cin >> l >> r;
      l = pre[l];
      r = nex[r];
      if(l > r){
        st.insert({0, 0});
      }else{
        st.insert({l, r});
      }
    }
    cout << st.size() << endl;
  }

  return 0;
}
