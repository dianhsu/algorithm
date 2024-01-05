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

class Rectangle{
public:
    typedef pair<int, int> Point;
    Rectangle(int sx, int sy) : dx({1, 0}), dy({0, 1}), vec({Point{0, 0}, Point{0, sy - 1}, Point{sx - 1, 0}, Point{sx - 1, sy - 1}}){}
    void mirror(int dr = 1){
        if(dr == 1){
            // 左右翻转
            swap(vec[0], vec[1]);
            swap(vec[2], vec[3]);
        }else{
            // 上下翻转
            swap(vec[0], vec[2]);
            swap(vec[1], vec[3]);
        }
        update();
    }
    void transpose(int dr = 1){
        if(dr == 1){
            // 沿着y = x 翻转
            swap(vec[1], vec[2]);
        }else{
            // 沿着x + y = n 翻转
            swap(vec[0], vec[3]);
        }
        update();
    }
    void rotate(int dr = 1){
        transpose();
        if(dr == 1){
            // 顺时针
            mirror(1);
        }else{
            // 逆时针
            mirror(0);
        }
        update();
    }
    Point mapping(Point p){
        return {vec[0].first + dx.first * p.first + dy.first * p.second, vec[0].second + dx.second * p.first + dy.second * p.second};
    }
    // 当前状态下，x轴的方向和y轴的方向
    Point dx, dy;
    // 当前状态下的方阵四个角点的坐标
    array<Point, 4> vec;
private:
    void update(){
        int xlim = abs(vec[2].first - vec[0].first) + abs(vec[2].second - vec[0].second);
        int ylim = abs(vec[1].first - vec[0].first) + abs(vec[1].second - vec[0].second);
        assert(xlim > 0 and ylim > 0);
        dx = Point{(vec[2].first - vec[0].first) / xlim, (vec[2].second - vec[0].second) / xlim};
        dy = Point{(vec[1].first - vec[0].first) / ylim, (vec[1].second - vec[0].second) / ylim};
    }

};
int main() {
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<string> vec(n);
    for(auto& it: vec) {
      cin >> it;
    }
    Rectangle rec(n, n);
    int ans = 0;
    for(int i = 0; i < n / 2; ++i){
      for(int j = 0; j < n / 2; ++j){
        int sumv = 0;
        int maxv = 0;
        for (int k = 0; k < 4; ++k){
          auto p = rec.mapping({i, j});
          sumv += vec[p.first][p.second] - '0';
          maxv = max(maxv, vec[p.first][p.second] - '0');
          rec.rotate(1);
        }
        ans += maxv * 4 - sumv;
      }
    }
    cout << ans << endl;
  }
  return 0; 
}