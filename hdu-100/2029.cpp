#include<iostream>
using namespace std;

int T;
string s;
int main(){
    cin >> T;
    while (T--){
        cin >> s;
        bool flag = 1;
        int i=0,j=s.length()-1;
        while(i<j){
            if (s[i]!=s[j]){
                flag = 0;
                break;
            }
            i++;
            j--;
        }
        if (flag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}