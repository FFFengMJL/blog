#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string code(string sourse, string & to)
{
    if(sourse.length() % 2)
    {
        to += sourse[sourse.length() / 2];
    }
    else
    {        
        to = to.insert(0, sourse.substr(sourse.length() / 2, 1));
        if(sourse.length()  == 2)
        {
            to += sourse[0];
        }
    }
    if(sourse.length() > 2)
    {
        string left = sourse.substr(0, sourse.length() / 2);
        string right = sourse.substr(sourse.length() / 2 + 1);
        code(left, to);
        code(right, to);
    }
    return to;
}

int main()
{
    //string s = "encryption";
    string s;
    string to;
    char c;
    while((c = cin.get()) != '\n')
    {
        s += c;
    }
    //cin >> s;
    code(s, to);
    cout << s << endl;
    cout << to << endl;
}