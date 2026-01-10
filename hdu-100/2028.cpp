#include<iostream>
using namespace std;
int N;
string s;
int main(){
    cin >> N;
    cin.ignore();
    for (int j=0;j<N;j++){
        getline(cin,s);
        int a=0,e=0,i=0,o=0,u=0;
        for (int k=0;k<s.length();k++){
            if (s[k]=='a' || s[k]=='A') a++;
            if (s[k]=='e' || s[k]=='E') e++;
            if (s[k]=='i' || s[k]=='I') i++;
            if (s[k]=='o' || s[k]=='O') o++;
            if (s[k]=='u' || s[k]=='U') u++;
        } 
        if (j != 0) cout << endl;
        cout << "a:" << a << endl;
        cout << "e:" << e << endl;
        cout << "i:" << i << endl;
        cout << "o:" << o << endl;
        cout << "u:" << u << endl;
    }
    return 0;
}