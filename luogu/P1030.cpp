#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;

char mid[10];
char last[10];

//根 左 右
void dfs(int inL,int inR,int postL,int postR){
    if(inL>inR||postL>postR) return;//可以不写postL>postR，两个是一样的条件

    char root=last[postR];
    cout<<root;// 先序：先输出根
    
    int k=inL;
    while(mid[k]!=root)k++;// 在中序中找根
    int leftSize=k-inL;

    //左子树，k-1是因为中序中根的位置不属于左子树
    dfs(inL,k-1,postL,postL+leftSize-1);
    //右子树
    dfs(k+1,inR,postL+leftSize,postR-1);
    
}


signed main(){
 IOS;
cin>>mid>>last;
int len=strlen(mid);
dfs(0, len - 1, 0, len - 1);

 return 0;
}