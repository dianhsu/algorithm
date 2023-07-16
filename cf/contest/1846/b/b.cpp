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
      vector<string> vec(3);
      for (auto& it : vec) cin >> it;
      set<char> st;
      for (int i = 0; i < 3; ++i) {
        char c = vec[i][0];
        bool ok = true;
        for (int j = 0; j < 3; ++j) {
          if (c != vec[i][j]) {
            ok = false;
            break;
          }
        }
        if (ok and (c == 'X' or c == 'O' or c == '+')) {
          st.insert(c);
        }
      }
      for (int j = 0; j < 3; ++j) {
        char c = vec[0][j];
        bool ok = true;
        for (int i = 0; i < 3; ++i) {
          if (c != vec[i][j]) {
            ok = false;
            break;
          }
        }
        if (ok and (c == 'X' or c == 'O' or c == '+')) {
          st.insert(c);
        }
      }
      char cl = vec[0][0];
      bool okl = true;
      for (int i = 0; i < 3; ++i) {
        if (vec[i][i] != cl) {
          okl = false;
          break;
        }
      }
      if (okl and (cl == 'X' or cl == 'O' or cl == '+')) {
        st.insert(cl);
      }
      char cr = vec[2][0];
      bool okr = true;
      for (int i = 0; i < 3; ++i) {
        if (vec[2 - i][i] != cr) {
          okr = false;
          break;
        }
      }
      if (okr and (cr == 'X' or cr == 'O' or cr == '+')) {
        st.insert(cr);
      }
      if (st.size() == 0 or st.size() > 1) {
        cout << "DRAW" << "\n";
      }else{
        cout << (*st.begin()) << "\n";
      }
    }
    return 0;
  }

