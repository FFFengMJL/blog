#include<iostream>
using namespace std;
//对于存在的东西，先 delete 再 new，防止内存泄露
class Student
{
public:
    int id;

    Student()
    {
        cout << "constructor" << endl;
    }
    
    ~Student()
    {
        cout << "distructor" << endl;
    }

};

//重载操作符，但参数由操作符本身来决定
bool operator > (Student &s1, Student &s2)
{
    return s1.id > s2.id;
}


int main()
{
    Student t;
    cin >> t.id;
    return 0;
}