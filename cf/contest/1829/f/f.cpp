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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1, 0);
    for(int i = 0; i < m; ++i){
      int x, y;
      cin >> x >> y;
      arr[x]++;
      arr[y]++;
    }
    map<int, int> mp;
    for(int i = 1; i <= n; ++i){
      if(arr[i] == 1) continue;
      mp[arr[i]]++;
    }
    if(mp.size() == 2){
      if(mp.begin()->second > mp.rbegin()->second){
        cout << mp.rbegin()->first << " " << mp.begin()->first - 1 << endl;
      }else{
        cout << mp.begin()->first << " " << mp.rbegin()->first - 1 << endl;
      }
    }else if(mp.size() == 1){
      int tv = mp.begin()->first;
      cout << tv << " " << tv - 1 << endl;
    }
  }

  return 0;
}

