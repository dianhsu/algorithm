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
template<typename T>
struct FenWick {
    int N;
    vector<T> arr;
    FenWick(int sz): N(sz), arr(sz + 1, 0) {}
    void update(int pos, T val) {
        for (; pos <= N;pos |= (pos + 1)) {
            arr[pos] += val;
        }
    }
    // 获取 [1, pos] 的和
    T get(int pos) {
        T ret = 0;
        for (; pos > 0; --pos) {
            ret += arr[pos];
            pos &= (pos + 1);
        }
        return ret;
    }
    // 获取 [l, r] 的和
    T query(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  string s;
  cin >> s;
  set<int> st;
  for(int i = 1; i <= n; ++i){
    st.insert(i);
  }
  vector<int> reorder;
  reorder.reserve(n + 1);
  reorder.push_back(0);
  while(m--){
    int l, r;
    cin >> l >> r;
    auto pos = st.lower_bound(l);
    while(pos != st.end() and *pos <= r){
      reorder.push_back(*pos);
      st.erase(pos);
      pos = st.lower_bound(l);
    }
  }
  int whoCares = (int)reorder.size() - 1;
  for(auto& it: st){
    reorder.push_back(it);
  }
  map<int, int> mp;
  for(int i = 0; i <= n; ++i){
    mp[reorder[i]] = i;
  }
  FenWick<int> fw(n);
  vector<int> vec(n + 1, 0);
  for(int i = 1; i <= n; ++i){
    int tv = (s[reorder[i] - 1] - '0');
    vec[i] = tv;
    fw.update(i, tv);
  }
  while(q--){
    int p;
    cin >> p;
    int np = mp[p];
    if(vec[np] == 1){
      vec[np] = 0;
      fw.update(np, -1);
    }else{
      vec[np] = 1;
      fw.update(np, 1);
    }
    int sum = fw.query(1, n);
    int minv = min(sum, whoCares);
    cout << minv - fw.query(1, minv) << "\n";
  }
  return 0;
}

