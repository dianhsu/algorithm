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

template <typename P = int, typename Q = long long, P MOD = 998244353>
class MInt {
public:
  static P selfPow(P base, P p) {
    Q ret = 1;
    while (p) {
      if (p & 1)
        ret = (ret * base) % MOD;
      p >>= 1;
      base = ((Q)base * base) % MOD;
    }
    return ret;
  }
  MInt() : val(0) {}
  MInt(P tv) : val(tv) {}
  MInt operator+(const MInt &arg) const {
    return MInt((val + (Q)arg.val) % MOD);
  }
  MInt operator-(const MInt &arg) const {
    return MInt(((Q)val + MOD - (Q)arg.val) % MOD);
  }
  MInt operator*(const MInt &arg) const {
    return MInt((val * (Q)arg.val) % MOD);
  }
  MInt operator/(const MInt &arg) const {
    return MInt((val * (Q)selfPow(arg.val, MOD - 2)) % MOD);
  }
  MInt operator+(const P argv) const { return MInt((val * (Q)argv) % MOD); }
  MInt operator-(const int argv) const {
    return MInt(((Q)val + MOD - (Q)argv) % MOD);
  }
  MInt operator*(const int argv) const { return MInt((val * (Q)argv) % MOD); }
  MInt operator/(const int argv) const {
    return MInt((val * (Q)selfPow(argv, MOD - 2)) % MOD);
  }
  MInt &operator+=(const MInt &arg) {
    this->val = ((Q)this->val + (Q)arg.val) % MOD;
    return *this;
  }
  MInt &operator-=(const MInt &arg) {
    this->val = ((Q)this->val + MOD - (Q)arg.val) % MOD;
    return *this;
  }
  MInt &operator*=(const MInt &arg) {
    this->val = ((Q)this->val * arg.val) % MOD;
    return *this;
  }
  MInt &operator/=(const MInt &arg) {
    this->val = ((Q)this->val * (Q)selfPow(arg.val, MOD - 2)) % MOD;
    return *this;
  }
  MInt &operator+=(const int argv) {
    this->val = ((Q)this->val + (Q)argv) % MOD;
    return *this;
  }
  MInt &operator-=(const int argv) {
    this->val = ((Q)this->val + MOD - (Q)argv) % MOD;
    return *this;
  }
  MInt &operator*=(const int argv) {
    this->val = ((Q)this->val * (Q)argv) % MOD;
    return *this;
  }
  MInt &operator/=(const int argv) {
    this->val = ((Q)this->val * (Q)selfPow(argv, MOD - 2)) % MOD;
    return *this;
  }
  MInt &operator=(const MInt &arg) {
    this->val = (Q)arg.val % MOD;
    return *this;
  }
  MInt &operator=(const int argv) {
    this->val = (Q)argv % MOD;
    return *this;
  }
  bool operator==(const int argv) const { return (Q)val == (Q)argv; }

  friend MInt operator+(const int argv, const MInt &arg) {
    return MInt(((Q)arg.val + (Q)argv) % MOD);
  }
  friend MInt operator-(const int argv, const MInt &arg) {
    return MInt(((Q)argv + MOD - (Q)arg.val) % MOD);
  }
  friend MInt operator*(const int argv, const MInt &arg) {
    return MInt(((Q)arg.val * (Q)argv) % MOD);
  }
  friend MInt operator/(const int argv, const MInt &arg) {
    return MInt(((Q)argv * (Q)MInt::selfPow(arg.val, MOD - 2)) % MOD);
  }
  friend istream &operator>>(istream &its, MInt &arg) {
    its >> arg.val;
    return its;
  }
  friend ostream &operator<<(ostream &ots, const MInt &arg) {
    ots << arg.val;
    return ots;
  }
  friend P abs(const MInt &arg) { return abs(arg.val); }

private:
  P val;
};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> vec(n);
  for (auto &s : vec)
    cin >> s;
  vector<vector<int>> flag(n, vector<int>(m, 0));
  auto &&check = [&](int x, int y) -> bool {
    return x >= 0 and x < n and y >= 0 and y < m and vec[x][y] == '#';
  };
  auto &&bfs = [&](int x, int y, int color) -> void {
    queue<PII> q;
    q.push({x, y});
    flag[x][y] = color;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        if (check(x + dx[i], y + dy[i]) and !flag[x + dx[i]][y + dy[i]]) {
          flag[x + dx[i]][y + dy[i]] = color;
          q.push({x + dx[i], y + dy[i]});
        }
      }
    }
  };
  int curf = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (vec[i][j] == '#' and !flag[i][j]) {
        curf++;
        bfs(i, j, curf);
      }
    }
  }
  MInt dv = 0;
  MInt sum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (vec[i][j] == '.') {
        dv += 1;
        set<int> st;
        for (int k = 0; k < 4; ++k) {
          if (check(i + dx[k], j + dy[k])) {
            st.insert(flag[i + dx[k]][j + dy[k]]);
          }
        }
        if (st.empty()) {
          sum += curf + 1;
        } else {
          sum += curf - st.size() + 1;
        }
      }
    }
  }
  auto ans = sum / dv;
  cout << sum << " " << dv << endl;
  cout << ans << endl;
  return 0;
}