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
template<int N>
vector<int> SieveOfEuler() {
    vector<int> prime;
    bitset<N + 1> notPrime;
    for (int i = 2; i <= N; ++i) {
        if (!notPrime[i]) {
            prime.push_back(i);
        }
        for (auto it : prime) {
            if ((long long) it * i <= N) {
                notPrime[it * i] = 1;
                if (i % it == 0) {
                    break;
                }
            }else{
                break;
            }
        }
    }
    return prime;
}
int main() {
  vector<int> prime = SieveOfEuler<1000000>();
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    if(n == 1){
      cout << "a\n";
    }else if(n & 1){
      for(int i = 0; i < n; ++i){
        cout << (char)((i & 1) ? 'a': 'b');
      }
      cout << "\n";
    }else{
      for(int it = 2; it <= 100; ++it){
        if(n % it != 0){
          for(int i = 0; i < n; ++i){
            cout << (char)((i % it) + 'a');
          }
          cout << "\n";
          break;
        }
      }
    }
  }
  return 0;
}

