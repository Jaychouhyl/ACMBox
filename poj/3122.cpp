#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<cstring>
#include<cmath>
#include <iomanip>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;


const double PI = acos(-1);   // 圆周率 π

int n, f;                     // n 个派，f 个朋友（实际要分 f+1 份）
double r[10005];              // 每个派的半径

// 判断：每人分 mid 面积，是否能分出 >= f+1 份
bool check(double mid){
    int cnt = 0;              // 能分出的总份数

    for(int i = 0; i < n; i++){
        // 当前派的面积 = π * r^2
        double area = PI * r[i] * r[i];

        // 这个派能分多少份 mid 面积的派
        cnt += (int)(area / mid);
    }

    // 如果能分出 f+1 份，说明 mid 可行
    return cnt >= f + 1;
}

signed main(){
 IOS;

    int T;
    cin >> T;                 // 测试组数

    while(T--){
        cin >> n >> f;

        for(int i = 0; i < n; i++){
            cin >> r[i];      // 输入每个派的半径
        }

        double l = 0, rmax = 0;

        // 找最大派面积作为右边界
        for(int i = 0; i < n; i++){
            rmax = max(rmax, PI * r[i] * r[i]);
        }

        // 实数二分，循环 100 次保证精度
        for(int i = 0; i < 100; i++){
            double mid = (l + rmax) / 2;

            if(check(mid))
                l = mid;      // 可行，尝试更大的面积
            else
                rmax = mid;   // 不可行，缩小范围
        }

        // 输出结果，保留 4 位小数
        cout << fixed << setprecision(4) << l << endl;
        // setprecision(4)	总有效数字 4 位
        // fixed + setprecision(4)	小数点后 4 位
    }

    return 0;
}


