## 二叉树⭐️

BFS和DFS是二叉树的绝配

P1030,P1087,P1229是一类

P5018!!难题也是个模版

P2168!!!k叉哈夫曼树+前缀码优化！(未解答)

竞赛常用静态存储二叉树：

```
struct Node{
char value;
int lson,rson;
}tree[N];
```

完全二叉树用数组存储有三个性质，此时都不需要定义lson、rson

(1)编号i>1的结点，其父节点是i/2;

(2)如果2i>k，那么节点i没有孩子；如果2i+1>k,那么节点i没rson

(3)如果i有孩子，左为2i，rson为2(i+1)

### 哈夫曼树（贪心思想的应用）



## map⭐️

 C++ 中，`<map>` 是标准模板库（STL）的一部分，它提供了一种关联容器，用于存储键值对（key-value pairs）。

`map` 容器中的元素是按照键的顺序自动排序⭐️的，这使得它非常适合需要快速查找和有序数据的场景。

### 定义和特性

- **键值对**：`map` 存储的是键值对，其中每个键都是唯一的。⭐️
- **排序**：`map` 中的元素按照键的顺序自动排序，通常是升序。⭐️
- **唯一性**：每个键在 `map` 中只能出现一次。⭐️
- **双向迭代器**：`map` 提供了双向迭代器，可以向前和向后遍历元素。⭐️

### 基本语法

包含头文件:

```
#include <map>
```

声明 map 容器:

```
map<key_type, value_type> myMap;
```

- `key_type` 是键的类型。
- `value_type` 是值的类型。

插入元素:

```
myMap[key] = value;
```

访问元素:

```
value = myMap[key];
```

遍历 map:

```
for (map<key_type, value_type>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
    cout << it->first << " => " << it->second << endl;
}
```

C++11 及以上标准，遍历部分可以简化为范围 for 循环，代码更简洁：

```
for (auto &p : m) {
	cout << p.first << " : " << p.second << std::endl;
}
```

## 实例

```
int main() {
  // 创建一个 map 容器，存储员工的姓名和年龄
 map<string, int> employees;

  // 插入员工信息
  employees["Alice"] = 30;
  employees["Bob"] = 25;
  employees["Charlie"] = 35;

  // 遍历 map 并打印员工信息
  for (std::map<std::string, int>::iterator it = employees.begin(); it != employees.end(); ++it) {
    std::cout << it->first << " is " << it->second << " years old." << std::endl;
  }

  return 0;
}
```

输出结果:

```
Alice is 30 years old.
Bob is 25 years old.
Charlie is 35 years old.
```

### 进阶用法

检查键是否存在:

```c++
if (myMap.find(key) != myMap.end()) {
    // 键存在
}
```

删除元素:

```c++
myMap.erase(key);
```

清空 map:

```
myMap.clear();
```

获取 map 的大小:

```
size_t size = myMap.size();
```

其他方法：

```
myMap.empty();      // 是否为空
myMap.count("Bob"); // key 是否存在（返回 0 或 1）
```

自定义排序，默认升序排序，可以用 std::greater 或自定义比较函数：

```
map< int, string, greater<int> > m;  // 降序
```



### 使用自定义比较函数:

```
bool myCompare(const std::string& a, const std::string& b) {
  return a < b;
}

int main() {
  map<string, int, function<bool(const std::string&, const std::string&)>> myMap(myCompare);

  // 其他操作...

  return 0;
}
```

map 是 C++ STL 中一个非常有用的容器，特别适合需要**快速查找和有序数据**的场景。

### 实例

```
int main() {
  std::map<std::string, int> scores;

  // 插入
  scores["Alice"] = 90;
  scores["Bob"] = 85;
  scores.insert({"Charlie", 92});

  // 遍历
  for (auto &p : scores) {
    std::cout << p.first << " => " << p.second << std::endl;
  }

  // 查找
  auto it = scores.find("Bob");
  if (it != scores.end()) {
    std::cout << "Bob's score: " << it->second << std::endl;
  }

  // 删除
  scores.erase("Alice");

  std::cout << "Size: " << scores.size() << std::endl;

  return 0;
}
```

运行结果（自动按 key 排序）：

```
Alice => 90
Bob => 85
Charlie => 92
Bob's score: 85
Size: 2
```