# Sort()函数使用

## 头文件

```c++
#include <algorithm>
```

## 功能

`sort()` 用于对数组或容器中的元素进行排序，默认按升序排列。可以通过自定义比较函数实现按特定规则排序。

---

## 语法

1. **基本用法（升序）**

```c++
sort(start, end);
```

* `start`：起始指针或迭代器
* `end`：结束指针或迭代器（不包含）

**示例：**

```c++
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 7};
    int n = 5;

    sort(arr, arr + n); // 升序排序

    for(int i = 0; i < n; i++)
        cout << arr[i] << " "; // 输出: 1 2 5 7 9
}
```

---

2. **自定义比较函数**

```c++
sort(start, end, cmp);
```

* `cmp` 是一个函数或 lambda，返回 `true` 表示前面元素应排在后面元素之前

**示例（降序排序）：**

```c++
bool cmp(int a, int b) {
    return a > b; // 降序
}

int main() {
    int arr[] = {5, 2, 9, 1, 7};
    int n = 5;

    sort(arr, arr + n, cmp);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " "; // 输出: 9 7 5 2 1
}
```

---

3. **对结构体数组排序**

```c++
struct Person {
    string name;
    int age;
};

Person people[105];
int n;

// 使用 lambda 排序按年龄升序
sort(people, people + n, [](const Person &a, const Person &b) {
    return a.age < b.age;
});
```

**多字段排序示例：**
先按年龄升序，年龄相同按名字字母顺序：

```c++
sort(people, people + n, [](const Person &a, const Person &b){
    if(a.age != b.age) return a.age < b.age;
    return a.name < b.name;
});
```

---

4. **对容器排序（如 vector）**

```c++
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v = {5, 2, 9, 1, 7};
sort(v.begin(), v.end()); // 升序
```

---

5. **注意事项**

* 对 **数组**，使用 `arr` 和 `arr + n`
* 对 **容器**，使用 `容器.begin()` 和 `容器.end()`
* 默认升序排序，如果要降序，必须提供比较函数或 lambda
* `sort()` 的时间复杂度一般是 O(n log n)
