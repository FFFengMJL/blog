# 2019.9.4

## Stack

特点：

- 所有操作（插入删除）都在一端（**栈顶**）进行
- 后进先出：Last In First Out
- 或者先进后出：First In Last Out

C艹提供了 Standard Template Library (STL 标准模板库)

> 学栈时不能用 STL，全部自己写

代码使用样例

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    double item;
    stack<double> numbers;
    cin >> n;

    for(int i = 0; i < n; n++) {
        cin >> item;
        numbers.push(item);
    }

    while(!numbers.empty()) {
        cout << numbers.top() << "";
        numbers.pop();
    }
    cout << endl;
}
```

一个类包括：

1. Constructors
2. Entry Types, Generics
3. Error Processing
4. Specification for Methods

Error code 例子

```cpp
enum Err_code {
    Sucess, Fail, Overflow, Underflow, RangeError, Too_Many, Found, Not_Found
}
```

Stack 的基本模板

```cpp
#include <iostream>
using namespace std;

//template<typename Stack_entry>
class Stack
{
public:
    Stack() {}; //不需要初始化 count 为0
    bool empty() const
    {
        //原版代码，可以优化很多
        /*
        bool outcome = true;
        if(count > 0) outcome = false;
        return outcome;
        */
        return (count == 0);
    }
    Error_code pop() 
    {
        if(count == 0) return underflow;
        count--;
        return success;
    }
    Error_code top(Stack_entry &item) const 
    {
        if(count == 0) return underflow;
        item = entry[count-1];
        return success;
    }
    Error_code push(const Stack_entry &item) 
    {
        // 注释过的是书本代码，下面为优化后代码
        /*
        Error_code outcome = success;
        if (count >= maxstack) outcome = overflow;
        else entry[count++] = item;
        return outcome;
        */
        if(count == maxstack) return overflow;
        entry[count++] = item;
        return success;
    }

private:
    int count;
    Stack_entry entry[maxstack];
};
```
