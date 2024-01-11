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
int solve(vector<int> &arr) {
  int n = arr.size();
  int gt = 0, lt = 0;
  int cgt = 0, clt = 0;
  for (int i = 0; i < n; ++i) {
    int cur = i, nex = (i + 1) % n;
    if (arr[cur] < arr[nex]) {
      ++lt;
      clt = nex;
    } else if (arr[cur] > arr[nex]) {
      ++gt;
      cgt = nex;
    }
  }
  // cout << gt << " " << lt << endl;
  // cout << cgt << " " << clt << endl;
  if (gt > 1 and lt > 1) {
    return -1;
  } else if (gt > 1) {
    int dv = (n - clt) % n + 1;
    return dv;
  } else if (lt > 1) {
    int dv = (n - cgt) % n;
    return dv;
  } else {
    if (gt == 1 and lt == 1) {
      int dv = min((n - clt) % n + 1, (n - cgt) % n);
      return dv;
    } else {
      return 0;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    int d1 = solve(arr);
    reverse(itr(arr));
    int d2 = solve(arr) + 1;
    cout << min(d1, d2) << endl;
  }
  return 0;
}