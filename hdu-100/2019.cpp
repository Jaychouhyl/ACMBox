#include<iostream>
using namespace std;
int n,m;
int a;
int main(){
    while(cin>>n>>m){
        if(!n&&!m) break;
        bool flag = 0;
        for (int i=0;i<n;i++){
            cin >> a;
            if (a > m && !flag) {
                flag = 1;
                cout << m << " ";
            }
            cout << a << " ";
        }
        if (!flag) cout << m << " ";
        cout <<endl;
    }
    return 0;
}