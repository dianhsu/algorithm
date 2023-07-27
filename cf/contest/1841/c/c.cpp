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
int mv[] = {1, 10, 100, 1000, 10000};
int cal(const string& s){
  char maxc = 'A';
  int ans = 0;
  for(int i = s.length() - 1; i >= 0; --i){
    if(s[i] >= maxc){
      ans += mv[s[i] - 'A'];
    }else{
      ans -= mv[s[i] - 'A'];
    }
    maxc = max(maxc, s[i]);
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int n = s.size();
    map<char, PII> mp;
    for(int i = 0; i < n; ++i){
      if(mp.count(s[i])){
        mp[s[i]].second = i;
      }else{
        mp[s[i]] = {i, i};
      }
    }
    int ans = INT_MIN;
    for(auto& [c, p]: mp){
      for(char nc = 'A'; nc <= 'E'; ++nc){
        if(nc == c) continue;
        else if(nc > c){
          s[p.first] = nc;
          ans = max(ans, cal(s));
          s[p.first] = c;
        }else{
          s[p.second] = nc;
          ans = max(ans, cal(s));
          s[p.second] = c;
        }
      }
    }
    cout << ans << "\n";
  }

  return 0;
}

