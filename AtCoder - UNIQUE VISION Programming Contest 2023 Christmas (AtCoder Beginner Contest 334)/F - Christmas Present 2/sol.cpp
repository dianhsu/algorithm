#include "atcoder/segtree.hpp"
#include <atcoder/all>
#include <bits/stdc++.h>
#include <iostream>

using namespace atcoder;
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
typedef pair<double, double> PDD;

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

template <typename T> T op(T a, T b) { return min(a, b); }
template <typename T> T e() { return 1e18; }

double dis(PDD a, PDD b) {
  return sqrt(PF(a.first - b.first) + PF(a.second - b.second));
}

int main() {
  int n, k;
  cin >> n >> k;
  PDD s;
  cin >> s.first >> s.second;
  vector<PDD> arr(n);
  for(auto& it: arr) cin >> it.first >> it.second;
  arr.push_back(s);
  double ans = dis(s, arr[0]);
  vector<double> d(n);
  for (int i = 0; i < n; ++i) {
    double dir = dis(arr[i], arr[i + 1]);
    double ret = dis(arr[i], s) + dis(arr[i + 1], s);
    ans += dir;
    d[i] = ret - dir;
  }
  segtree<double, op<double>, e<double>> dp(n + 1);
  dp.set(0, 0);
  for(int i = 1; i <= n; ++i) {
    dp.set(i, dp.prod(max(0, i - k), i) + d[i - 1]);
  }
  ans += dp.get(n);
  cout << ans << endl;
  return 0;
}