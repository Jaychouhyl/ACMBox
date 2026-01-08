# 队列

## 1.比赛一般使用queue或是自定义一个静态数组



## 2.queue**⭐️**

队列是一种先进先出（FIFO, First In First Out）的数据结构，它允许在一端添加元素（称为队尾），并在另一端移除元素（称为队首）。

### 语法

在 C++ 中，队列的语法如下：

```
#include <queue>

// 声明队列
std::queue<Type> q;//这里 `Type` 是队列中存储元素的数据类型。
```

### 常用操作

队列提供了以下常用操作：

- `empty()`: 检查队列是否为空。
- `size()`: 返回队列中的元素数量。
- `front()`: 返回队首元素的引用。
- `back()`: 返回队尾元素的引用。
- `push()`: 在队尾添加一个元素。
- `pop()`: 移除队首元素。

### 实例

```
\#include <iostream>
\#include <queue>

int main() {
  // 创建一个整数队列
  std::queue<int> q;

  // 向队列中添加元素
  q.push(10);
  q.push(20);
  q.push(30);

  // 打印队列中的元素数量
  std::cout << "队列中的元素数量: " << q.size() << std::endl;

  // 打印队首元素
  std::cout << "队首元素: " << q.front() << std::endl;

  // 打印队尾元素
  std::cout << "队尾元素: " << q.back() << std::endl;

  // 移除队首元素
  q.pop();
  std::cout << "移除队首元素后，队首元素: " << q.front() << std::endl;

  // 再次打印队列中的元素数量
  std::cout << "队列中的元素数量: " << q.size() << std::endl;

  return 0;
}
```

输出结果：

```
队列中的元素数量: 3
队首元素: 10
队尾元素: 30
移除队首元素后，队首元素: 20
队列中的元素数量: 2
```

### 注意事项

- 队列**不允许随机访问元素**，即**不能直接通过索引访问队列中的元素**。
- 队列的实现通常使用**链表或动态数组**，这取决于具体的实现。



## 3.双端队列deque⭐️

双端队列是一种允许在两端进行插入和删除操作的线性数据结构。

`<deque>` 是一个动态数组，它提供了**快速的随机访问能力**，同时允许在两端进行**高效的插入和删除操作**。这使得 `<deque>` 成为处理需要**频繁插入和删除元素**的场景的理想选择。

### 语法

```
#include <iostream>
#include <deque>

int main() {
    std::deque<int> myDeque; // 创建一个整数类型的双端队列
    // 接下来可以进行插入、删除等操作
    return 0;
}
```

### 常用操作

<img src="C:\Users\admin\AppData\Roaming\Typora\typora-user-images\image-20260107171150830.png" alt="image-20260107171150830" style="zoom:67%;" />

| 函数名称                                                     | 功能描述                                          |
| :----------------------------------------------------------- | :------------------------------------------------ |
| `deque()`                                                    | 默认构造函数，创建一个空的 `deque` 容器。         |
| `deque(size_type n)`⭐️                                        | 创建一个包含 `n` 个默认值元素的 `deque` 容器。    |
| `deque(size_type n, const T& value)`⭐️                        | 创建一个包含 `n` 个值为 `value` 的 `deque` 容器。 |
| `deque(initializer_list<T> il)`（deque<int> d = {1, 2, 3, 4};) | 使用初始化列表 `il` 构造 `deque` 容器。           |
| `operator=`                                                  | 赋值操作符，赋值给 `deque` 容器。                 |
| `assign()`                                                   | 用新值替换 `deque` 容器中的所有元素。             |
| `at(size_type pos)`                                          | 返回 `pos` 位置的元素，并进行范围检查。           |
| `operator[](size_type pos)`                                  | 返回 `pos` 位置的元素，不进行范围检查。           |
| `front()`⭐️                                                   | 返回第一个元素的引用。                            |
| `back()`⭐️                                                    | 返回最后一个元素的引用。                          |
| `begin()`⭐️                                                   | 返回指向第一个元素的迭代器。                      |
| `end()⭐️`                                                     | 返回指向末尾元素后一位置的迭代器。                |
| `rbegin()`                                                   | 返回指向最后一个元素的逆向迭代器。                |
| `rend()`                                                     | 返回指向第一个元素之前位置的逆向迭代器。          |
| `empty()`                                                    | 检查容器是否为空。                                |
| `size()`                                                     | 返回容器中的元素个数。                            |
| `max_size()`                                                 | 返回容器可容纳的最大元素个数。                    |
| `clear()`                                                    | 清除容器中的所有元素。                            |
| `insert(iterator pos, const T& value)`⭐️                      | 在 `pos` 位置插入 `value` 元素。                  |
| `erase(iterator pos)`⭐️                                       | 移除 `pos` 位置的元素。                           |
| `push_back(const T& value)`⭐️                                 | 在容器末尾添加 `value` 元素。                     |
| `pop_back()`⭐️                                                | 移除容器末尾的元素。                              |
| `push_front(const T& value)`⭐️                                | 在容器前端添加 `value` 元素。                     |
| `pop_front()`⭐️                                               | 移除容器前端的元素。                              |
| `resize(size_type count)`⭐️                                   | 调整容器大小为 `count`，多出部分用默认值填充。    |
| `swap(deque& other)`                                         | 交换两个 `deque` 容器的内容。                     |
| `get_allocator()`                                            | 返回一个用于构造双端队列的分配器对象的副本。      |

### 实例

```
#include <iostream>
#include <deque>

int main() {
  std::deque<int> myDeque;

  // 插入元素
  myDeque.push_back(10);
  myDeque.push_back(20);
  myDeque.push_front(5);

  // 访问元素
  std::cout << "Deque contains: ";
  for (int i = 0; i < myDeque.size(); ++i) {
    std::cout << myDeque[i] << " ";
  }
  std::cout << std::endl;

  // 删除元素
  myDeque.pop_back();
  myDeque.pop_front();

  // 再次访问元素
  std::cout << "Deque after popping: ";
  for (int i = 0; i < myDeque.size(); ++i) {
    std::cout << myDeque[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
```

输出结果:

```
Deque contains: 5 10 20 
Deque after popping: 10 
```

在不知道 deque 长度的时候，可以使用 deque.front() 与 deque.back() 来访问头尾元素：

### 实例

```
#include <iostream>
#include <deque>

int main() {
  std::deque<int> d;

  // 向双端队列中添加元素
  d.push_back(10);
  d.push_back(20);
  d.push_front(5);

  // 访问前端元素
  std::cout << "Front element: " << d.front() << std::endl;

  // 访问后端元素
  std::cout << "Back element: " << d.back() << std::endl;

  // 修改前端元素
  d.front() = 15;

  // 修改后端元素
  d.back() = 25;

  // 再次访问元素
  std::cout << "Modified front element: " << d.front() << std::endl;
  std::cout << "Modified back element: " << d.back() << std::endl;

  return 0;
}
```

输出结果为：

```
Front element: 5
Back element: 20
Modified front element: 15
Modified back element: 25
```

**注意：**在使用 front() 或 back() 之前，**确保双端队列不为空，否则会引发未定义的行为**。如果需要检查双端队列是否为空，可以使用 empty() 成员函数。

## 4.优先队列priority_queue⭐️

优先队列是一种特殊的队列，它允许我们快速访问队列中具有最高（或最低）优先级的元素。

在 C++ 中，`priority_queue` 默认是一个最大堆，这意味着**队列的顶部元素总是具有最大的值**。

`priority_queue` 是一个容器适配器，它提供了对底层容器的堆操作。**它不提供迭代器，也不支持随机访问**。

### 语法

以下是 `priority_queue` 的基本语法：

```
#include <queue>

// 声明一个整型优先队列
priority_queue<int> pq;

// 声明一个自定义类型的优先队列，需要提供比较函数⭐️
struct compare {
    bool operator()(int a, int b) {
        return a > b; // 这里定义了最小堆
    }
};
priority_queue<int, vector<int>底层存储容器, compare> pq_min;

(我的理解是将<符号给重定义成>号，则若后面的比前面的小，为true要进行交换这种)⭐️
struct Node {
    int x;
    bool operator<(const Node& other) const {
        return x > other.x;// 小顶堆
    }
};
priority_queue<Node> pq;
```

### 常用操作⭐️

- `empty()`: 检查队列是否为空。
- `size()`: 返回队列中的元素数量。
- `top()`: 返回队列顶部的元素（不删除它）。
- `push()`: 向队列添加一个元素。
- `pop()`: 移除队列顶部的元素。



### 实例

我们将创建一个最大堆，并展示如何添加元素和获取队列顶部的元素

int main() {
  // 创建一个整型优先队列
priority_queue<int> pq;

  // 向优先队列中添加元素
  pq.push(30);
  pq.push(10);
  pq.push(50);
  pq.push(20);

  // 输出队列中的元素
  std::cout << "队列中的元素：" << std::endl;
  while (!pq.empty()) {
  cout << pq.top() << endl;
    pq.pop();
  }

  return 0;
}

输出结果：

```
队列中的元素：
50
30
20
10
```

### 自定义优先级⭐️

如果你需要一个最小堆，可以通过自定义比较函数来实现：

struct compare {
  bool operator()(int a, int b) {
    return a > b; // 定义最小堆
  }
};

int main() {
  // 创建一个自定义类型的优先队列，使用最小堆
priority_queue<int, vector<int>, compare> pq_min;

  // 向优先队列中添加元素
  pq_min.push(30);
  pq_min.push(10);
  pq_min.push(50);
  pq_min.push(20);

  // 输出队列中的元素
  std::cout << "最小堆中的元素：" << std::endl;
  while (!pq_min.empty()) {
    std::cout << pq_min.top() << std::endl;
    pq_min.pop();
  }

  return 0;
}

输出结果：

```
最小堆中的元素：
10
20
30
50
```

`<priority_queue>` 是C++ STL中一个非常有用的容器，特别适合需要快速访问最高或最低优先级元素的场景。通过自定义比较函数，我们可以轻松地实现最大堆或最小堆。希望这篇文章能帮助初学者更好地理解和使用 `priority_queue`。

## 5.queue / deque / priority_queue 对比总表⭐️

| 对比维度         | `queue`          | `deque`                        | `priority_queue`  |
| ---------------- | ---------------- | ------------------------------ | ----------------- |
| 中文含义         | 队列（FIFO）     | 双端队列                       | 优先队列（堆）    |
| 是否容器适配器   | 是               | 否（是真正容器）               | 是                |
| 底层实现         | 默认基于 `deque` | 分段连续数组                   | 默认基于 `vector` |
| 元素顺序         | 先进先出         | 插入顺序                       | 按优先级排序      |
| 是否有迭代器     | 否               | 是⭐️                            | 否                |
| 访问队首         | `front()`        | `front()`                      | `top()`           |
| 访问队尾         | `back()`         | `back()`                       | 不支持            |
| 插入方式         | `push()`（队尾） | `push_front()` / `push_back()` | `push()`          |
| 删除方式         | `pop()`（队首）  | `pop_front()` / `pop_back()`   | `pop()`           |
| 随机访问         | 不支持           | 支持（`operator[]`）⭐️          | 不支持            |
| 默认排序规则     | 无               | 无                             | 大顶堆⭐️           |
| 是否可自定义比较 | 否               | 否                             | 是⭐️               |
| 典型时间复杂度   | O(1)             | O(1)                           | O(log n)          |
| 典型应用         | BFS              | 滑动窗口                       | Top-K / 调度⭐️     |

------

### 时间复杂度对比（关键）

| 操作              | `queue` | `deque` | `priority_queue` |
| ----------------- | ------- | ------- | ---------------- |
| 插入              | O(1)    | O(1)    | O(log n)         |
| 删除              | O(1)    | O(1)    | O(log n)         |
| 访问最大/最早元素 | O(1)    | O(1)    | O(1)             |
| 随机访问          | ❌       | O(1)    | ❌                |

------

### 典型使用场景⭐️

#### 1️⃣ `queue` —— 先进先出（FIFO）

**适用场景**

- BFS
- 多线程任务队列
- 生产者-消费者模型

**特点**

- 只能从一头进、一头出
- 接口最简单，最安全

```
queue<int> q;
q.push(1);
q.push(2);
q.pop();
```

------

#### 2️⃣ `deque` —— 双端高效操作

**适用场景**

- 滑动窗口最值⭐️
- 单调队列⭐️
- 需要两端频繁操作

**特点**

- 可前后插入删除⭐️
- 支持随机访问⭐️
- 性能接近 vector⭐️

```
deque<int> dq;
dq.push_front(1);
dq.push_back(2);
dq.pop_front();
```

------

#### 3️⃣ `priority_queue` —— 按优先级取元素

**适用场景**

- Top K 问题⭐️
- Dijkstra⭐️
- 调度系统⭐️
- 贪心算法⭐️

**特点**

- 本质是堆
- 不保证遍历顺序
- 只能访问最大/最小值

```
priority_queue<int> pq;
pq.push(3);
pq.push(1);
cout << pq.top();  // 3
```