#include<iostream>
#include<stack>
using namespace std;
string s;

int main(){
    while(cin>>s){
        char max_c = 'a' - 1;
        for (int i=0; i<s.length();i++){
            if (s[i]>max_c){
                max_c = s[i];
            }
        }
        for (int i=0;i<s.length();i++){
            cout << s[i];
            if (s[i] == max_c) cout << "(max)";
        }
        cout << endl;
    }
    return 0;
}