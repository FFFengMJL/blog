#include<iostream>
#include<string.h>
using namespace std;

int pow_n1(int times)
{
    if(times % 2)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

class Matrix
{
public:
    int row;
    double * values;

    Matrix(int row, double values[])
    {
        this->row = row;
        this->values = new double [row * row];        
        for(int i = 0; i < this->row * this->row; i ++)
        {
            this->values[i] = values[i];
        }
    }

    ~Matrix()
    {
        delete [] this->values;
    }

    double Determinant()
    {
        if(this->row == 1)
        {
            return this->values[0];
        }

        double res = 0;
        for(int i = 0; i < this->row; i ++)
        {
            if(this->values[i] == 0)
            {
                //i ++;
                continue;
            }
            //用数组储存余子式
            double yuzishi[(this->row - 1) * (this->row - 1)];

            //获取余子式的数组
            for(int t = 1, k = 0; t < this->row; t ++)
            {
                for(int j = 0; j < this->row; j ++)
                {
                    if(j == i)//跳过当前的列
                    {
                        continue;
                    }
                    yuzishi[k ++] = this->values[t * this->row + j];                  
                }
            }
            Matrix node(this->row - 1, yuzishi);
            node.print();
            res += pow_n1(i) * node.Determinant() * this->values[i];
        }
        return res;
    }

    void print()//debug用
    {
        for(int i = 0; i < this->row * this->row; i ++)
        {
            if(i && i % this->row == 0)
            {
                cout << endl;
            }
            cout << this->values[i] << ' ';
        }
        cout << endl;
    }
};

int main()
{
    int len = 4;
    double test_arr[len * len] = {};
    Matrix a(len, test_arr);
    a.print();
    cout <<` a.Determinant() << endl;
}