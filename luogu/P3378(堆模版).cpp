#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<cstring>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;

//priority_queue的堆的使用
signed main(){
 IOS;
 int n,x;
 cin>>n;
 priority_queue<int,vector<int>,greater<int>>pq;
 for (int i = 1; i <= n; i++)
 {
    int op_type;
    cin>>op_type;
    if (op_type==1)
    {
        cin>>x;
        pq.push(x);
    }

    else if (op_type==2)
    {
        cout<<pq.top()<<endl;
    }
    else
    {
        pq.pop();
    }
 }

 return 0;
}



//手写堆的实现
const int N=1e5+10;
int heap[N],len=0;//len表示堆中元素的个数
void push(int x){
    heap[++len]=x;//从1开始存储
    int i=len;
    while (i>1&&heap[i]<heap[i/2])//当前结点比父节点小，交换
    {
        swap(heap[i],heap[i/2]);
        i/=2;
    }
}
void pop(){
    heap[1]=heap[len--];//用最后一个元素覆盖堆顶
    int i=1;//根结点替换为最后一个元素后，结点数减少1
    while(2*i<=len){
        int son=2*i;//左儿子下标
        if(son<len&&heap[son]>heap[son+1]) son++;//右儿子更小，选右儿子
        if(heap[son]<heap[i]){//儿子比父节点小，交换
            swap(heap[son],heap[i]);
            i=son;
        }
        else break;
    }
}


signed main(){
    IOS;
    int n,x,op_type;
    cin>>n;
    while(n--){
        cin>>op_type;
        if(op_type==1){
            cin>>x;
            push(x);
        }
        else if(op_type==2){
            cout<<heap[1]<<endl;
        }
        else{
            pop();
        }
    }
    return 0;
}