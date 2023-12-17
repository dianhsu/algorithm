#include <bits/stdc++.h>
#include <queue>

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
struct Node{
  int h, idx;
  bool operator > (const Node& node) const{
    if(h != node.h) return h > node.h;
    return idx < node.idx;
  }
};
int main() {
  int t;
  cin >> t;
  while(t--){
    int n;
    ll k;
    cin >> n >> k;
    map<int, vector<int>> mp;
    for(int i = 0; i < n; ++i){
      int tv;
      cin >> tv;
      mp[(tv - 1) % k].push_back(i);
    }
    for(auto it = mp.rbegin(); it != mp.rend(); ++it){
      auto& vec = it->second;
      for(auto& cur: vec) cout << cur + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}

