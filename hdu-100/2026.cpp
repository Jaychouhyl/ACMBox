#include<iostream>
using namespace std;

string s;
int main(){
    while(cin >> s){
        s[0] = s[0] - 32;
        cout << s << " ";
    }

    return 0;
}