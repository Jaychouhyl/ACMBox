#include<iostream>
using namespace std;
int T;
string s;
int main(){
    cin >> T;
    cin.ignore(); 
    while(T--){
        getline(cin, s);
        bool flag = 1;
        if (!(s[0]>='a'&&s[0]<='z' || s[0]=='_' || s[0]>='A'&&s[0]<='Z' )){
            cout << "no" << endl;
            continue;
        }
        for (int i=1;i<s.length();i++){
            if (!(s[i]>='0' && s[i]<='9' || s[i]>='a' && s[i]<='z' || s[i]=='_'|| s[i]>='A'&&s[i]<='Z')){
                flag = 0;
                cout << "no" << endl;
                break;
            }
        }
        if (flag) cout << "yes" << endl;
    }
    return 0;
}