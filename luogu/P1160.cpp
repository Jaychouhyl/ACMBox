#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;
#define Max 100020

typedef struct Node{
    int id;
    int leftright;
    list<int>::iterator pos;  // 存储该学号在list中的迭代器位置
};//node[Max],这样也可以，下面就是直接给出node mynodes;

Node nodes[Max];

signed main(){
 IOS;
    int n,m;
    cin>>n;
    list<int> lst;//不需要预先存储所有元素，动态插入即可

    // 初始化所有节点的迭代器位置为end
    auto end_it=lst.end();
    for (int i = 1; i <= n; i++)
    {
        nodes[i].pos=end_it;
    }
    
    for ( int i = 2; i <= n; i++)
    {
        cin>>nodes[i].id>>nodes[i].leftright;
    }

    lst.push_back(1);
    nodes[1].pos = lst.begin();

    for (int i = 2; i <= n; i++)
    {
        int k=nodes[i].id;
        int p=nodes[i].leftright;

        if (p==0)
        {
            nodes[i].pos=lst.insert(nodes[k].pos,i);
        }
        else
        {
            auto it=nodes[k].pos;
            it++;
            nodes[i].pos=lst.insert(it,i);
        }
    }


     cin>>m;
    for ( int i = 1; i <= m; i++)
    {
        int finded_id;
        cin>>finded_id;
        if(finded_id>=1&&finded_id<=n&&nodes[finded_id].pos!=lst.end()){
            lst.erase(nodes[finded_id].pos);
            nodes[finded_id].pos=lst.end();
        }
        
    }

    for (auto it = lst.begin(); it != lst.end(); it++) {
        
        cout << *it<< " ";
    }
    cout << endl;
    

 return 0;
}