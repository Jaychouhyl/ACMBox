#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;

signed main(){
    IOS;
    int n,k;
    cin>>n>>k;
    int a[1000005];
    deque<int> dq;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }


    // 求最小值，dq存储下标
    for (int i = 1; i <= n; i++)
    {
        // 先清除过期元素（窗口外的元素）
        while (!dq.empty()&&dq.front()<=i-k) dq.pop_front();
        
        // 维护单调递增队列（队首最小）
        while (!dq.empty()&&a[dq.back()]>=a[i]) dq.pop_back();

        dq.push_back(i);
        
        // 输出结果
        if(i>=k){
            cout<<a[dq.front()]<<" ";
        }
    }
    cout<<endl;
    
  

    // 清空队列
    while (!dq.empty())dq.pop_front();   
    



    // 求最大值
    for (int i = 1; i <= n; i++)
    {
        // 先清除过期元素
        while (!dq.empty()&&dq.front()<=i-k) dq.pop_front();
        

        // 维护单调递减队列（队首最大）
        while (!dq.empty()&&a[dq.back()]<=a[i]) dq.pop_back();

        dq.push_back(i);
        
        // 输出结果
        if (i>=k)
        {
            cout<<a[dq.front()]<<" ";
        }
    }
    cout<<endl;
    
    return 0;
}