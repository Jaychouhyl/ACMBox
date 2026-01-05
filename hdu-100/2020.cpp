#include<iostream>
#include <algorithm>
using namespace std;
int n;
bool flag[105];
typedef struct{
    int val;
    bool flag;
}number;
bool cmpByVal(const number &a, const number &b){
    return a.val > b.val;
}
number a[105];
int temp;
string s;
int main(){
    while(cin >> n){
        if (!n) break;
        for(int i=0;i<n;i++){
            cin >> temp;
            a[i].val = abs(temp);
            a[i].flag = temp < 0 ? true: false;
        }
        sort(a,a+n,cmpByVal);
        for (int i=0;i<n;i++){
            s = a[i].flag? "-":"" ;
            cout << s << a[i].val <<" ";
        }
        cout << endl;
    }

    return 0;
}