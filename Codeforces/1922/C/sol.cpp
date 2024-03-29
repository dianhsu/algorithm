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
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    int m;
    cin >> m;
    vector<PII> brr(m);
    for(auto& it: brr) cin >> it.first >> it.second;
    vector<ll> dl(n + 2, 0), dr(n + 2, 0);
    for (int i = 2; i <= n; ++i){
      if(i == 2) dl[i] = dl[i - 1] + 1;
      else {
        if(abs(arr[i] - arr[i - 1]) < abs(arr[i - 1] - arr[i - 2])) {
          dl[i] = dl[i - 1] + 1;
        }else{
          dl[i] = dl[i - 1] + abs(arr[i] - arr[i - 1]);
        }
      }
    }
    for (int i = n - 1; i >= 1; --i) {
      if (i == n - 1) dr[i] = dr[i + 1] + 1;
      else {
        if (abs(arr[i] - arr[i + 1]) < abs(arr[i + 1] - arr[i + 2])) {
          dr[i] = dr[i + 1] + 1;
        } else {
          dr[i] = dr[i + 1] + abs(arr[i] - arr[i + 1]);
        }
      }
    }
    for (int i = 0; i < m; ++i){
      if (brr[i].first < brr[i].second) {
        cout << dl[brr[i].second] - dl[brr[i].first] << endl;
      }else{
        cout << dr[brr[i].second] - dr[brr[i].first] << endl;
      }
    }
  }
  return 0; 
}