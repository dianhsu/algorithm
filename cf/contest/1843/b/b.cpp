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

void solve(int case_idx) {
  int n;
  cin >> n;
  vector<ll> arr;
  ll ans = 0;
  for(int i = 0; i < n; ++i){
    int tv;
    cin >> tv;
    ans += abs(tv);
    if(arr.empty()) arr.push_back(tv);
    else if(arr.back() >= 0 and tv >= 0) arr.back() += tv;
    else if(arr.back() <= 0 and tv <= 0) arr.back() += tv;
    else arr.push_back(tv);
  }
  if(arr.size() == 1){
    if(arr.front() >= 0){
      cout << ans << " " << 0 << endl;
    }else{
      cout << ans << " " << 1 << endl;
    }
  }else{
    int tn = arr.size();
    if(arr.front() > 0) --tn;
    if(arr.back() > 0) --tn;
    cout << ans << " " << (tn + 1) / 2 << endl;
  }
}
