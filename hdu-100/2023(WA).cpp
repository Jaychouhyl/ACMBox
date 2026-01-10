#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n, m;
    double a[50][5];
    while (cin >> n >> m){
        double stu_avg[50] = {0};
        double cls_avg[5] = {0};
        int cnt = 0;
        double k = 0;
        for (int i=0;i<n;i++){
            for (int j=0 ;j<m ;j++){
                cin >> a[i][j];
                stu_avg[i] += a[i][j];
                cls_avg[j] += a[i][j];
            }
        }
        // for (int i=0;i<n;i++) stu_avg[i] /= m;
        // for (int j=0;j<m;j++) cls_avg[j] /= n;

        for (int i=0;i<n;i++){
            int flag = 0;
            for (int j=0;j<m;j++){
                if (a[i][j] >= cls_avg[j] / n) flag++;
            }
            if (flag==m) cnt++;
        }

        cout << fixed << setprecision(2);
        for (int i=0;i<n;i++){
            cout << stu_avg[i] / m;
            if (i!=n-1) cout << " "; 
        }
        cout << endl;
        for (int i=0;i<m;i++){
            cout << cls_avg[i] / n;
            if (i!=m-1) cout << " "; 
        }
        cout << endl;
        cout << cnt << endl << endl;
    }
    return 0;
}
