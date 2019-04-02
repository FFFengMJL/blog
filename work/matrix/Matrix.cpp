#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdio.h>
#include<cmath>
#include<vector>
using namespace std;

template <typename E>
class Matrix
{
private:
    int rows;
    int columns;
    double * values;

public:
    //initializes all elements in the matrix to 0's.
    Matrix(int rows, int column)
    {
        this->rows = rows;
        this->columns = column;
        this->values = new E [rows * column];
        for(int i = 0; i < rows * column; i ++)
        {
            values[i] = 0;
        }
    }

    // initializes all elements in the matrix to the given values. 
    Matrix(int rows, int column, E values[])
    {
        this->rows = rows;
        this->columns = column;
        this->values = new E [rows * column];
        for(int i = 0;i < rows * column; i ++)
        {
            this->values[i] = values[i];
        }
    }

    Matrix(const Matrix & from)
    {
        this->rows = from.rows;
        this->columns = from.columns;
        if(this->rows * this->columns)
        {
            this->values = new E [this->rows * this->columns];
            for(int i = 0; i < this->rows * this->columns; i ++)
            {
                this->values[i] = from.values[i];
            }
        }
    }

    Matrix(int rows, int cols, const vector<E> values)
    {
        this->rows = rows;
        this->columns = cols;
        if(this->rows * this->columns)
        {
            this->values = new E [this->rows * this->columns];
            for(int i = 0; i < this->rows * this->columns; i ++)
            {
                this->values[i] = values[i];
            }
        }

    }

    //A destructor.
    ~Matrix()
    {
        delete [] this->values;
    }

    //prints each row of elements in a single line, with each element preceded by 4 spaces.
    void print()
    {
        for(int i = 0; i < this->rows; i ++)
        {
            for(int t = 0; t < this->columns; t ++)
            {
                cout << "    " << this->values[i * this->columns + t];
            }
            cout << endl;
        }
    }

    E & get(int row, int col)
    {
        return this->values[(row - 1) * this->columns + col - 1];
    }

    //returns a row matrix for the given row.
    Matrix getRow(int row)
    {
        row --;
        Matrix temp(1, this->columns);
        for(int i = 0; i < this->columns; i ++)
        {
            temp.values[i] = this->values[row * this->columns + i];
        }
        return temp;
    }

    //returns a column matrix for the given column.
    Matrix getColumn(int column)
    {
        column --;
        Matrix temp(this->rows, 1);
        for(int i = 0; i < this->rows; i ++)
        {
            temp.values[i] = this->values[i * this->columns + column];
        }
        return temp;
    }

    //pull a value into a specific place
	void set(int row, int column, E value)
	{
		this->values[(row - 1) * this->columns + column - 1] = value;
	}

    //Matrix equaltion

    //Concatenate 2 Matrix by Rows
    Matrix concatenateRows(const Matrix & matrix2) const
    {
        Matrix node(this->rows + matrix2.rows, this->columns);
        memcpy(node.values, this->values, this->rows * this->columns * sizeof(this->values));
        for(int i = 0, t = this->rows * this->columns; i < matrix2.rows * matrix2.columns; i ++, t ++)
        {
            node.values[t] = matrix2.values[i];
        }
        return node;
    }

    //Concatenate 2 Matrix by Columns
    Matrix concatenateColumns(const Matrix & matrix2) const
    {
        Matrix node(this->rows, this->columns + matrix2.columns);
        for(int i = 0; i < this->rows; i ++)
        {
            for(int t = 0; t < this->columns; t ++)
            {
                node.values[i * node.columns + t] = this->values[i * this->columns + t];
                node.values[i * node.columns + t + this->columns] = matrix2.values[i * matrix2.columns + t];
            }
        }
        return node;
    }

    //Reshape this Matrix
    Matrix reshape(int rows, int columns)
    {
        Matrix node(rows, columns);
        int node_row = 0;
        int node_col = 0;
        for(int i = 0; i < this->columns; i ++)
        {
            for(int t = 0; t < this->rows; t ++)
            {
                node.values[node_row * columns + node_col] = this->values[t * this->columns + i];
                node_row ++;
                if(node_row == rows)
                {
                    node_col ++;
                    node_row = 0;
                }
            }
        }
        return node;
    }

    //Transpose this Matrix
    Matrix transpose()
    {
        Matrix node(this->columns, this->rows);
        for(int i = 0; i < this->rows; i ++)
        {
            for(int t = 0; t < this->columns; t ++)
            {
                node.values[t * this->rows+ i] = this->values[i * this->columns + t];
            }
        }
        return node;
    }

    Matrix max()
    {
        int col = (this->rows == 1) ? 1 : this->columns;
        Matrix node(1, col);
        int max = 0;
        if(node.columns == 1)
        {
            for(int i = 0; i < this->rows * this->columns; i ++)
            {
                max = this->values[max] > this->values[i] ? max : i;
            }
            node.values[0] = this->values[max];
        }
        else
        {
            for(int i = 0; i < node.columns; i ++)
            {
                for(int t = 0; t < this->rows; t ++)
                {
                    node.values[i] = node.values[i] > this->values[t * this->columns + i] ? node.values[i] : this->values[t * this->columns + i];
                }
            }
        }
        return node;
    }

    Matrix min()
    {
        int col = (this->rows == 1) ? 1 : this->columns;
        Matrix node(1, col);
        int min = 0;
        if(node.columns == 1)
        {
            for(int i = 0; i < this->rows * this->columns; i ++)
            {
                min = this->values[min] < this->values[i] ? min : i;
            }
            node.values[0] = this->values[min];
        }
        else
        {
            for(int i = 0; i < node.columns; i ++)
            {
                node.values[i] = this->values[i];
                for(int t = 0; t < this->rows; t ++)
                {
                    node.values[i] = node.values[i] < this->values[t * this->columns + i] ? node.values[i] : this->values[t * this->columns + i];
                }
            }
        }
        return node;
    }

    Matrix sum()
    {
        int col = this->rows == 1 ? 1 : this->columns;
        Matrix node(1, col);
        if(node.columns == 1)
        {
            for(int i = 0; i < this->columns; i ++)
            {
                node.values[0] += this->values[i];
            }
        }
        else
        {
            for(int i = 0; i < node.columns; i ++)
            {
                for(int t = 0; t < this->rows; t ++)
                {
                    node.values[i] += this->values[t * this->columns + i];
                }
            }
        }
        return node;
    }

	Matrix pow(E exponent)
    {
        Matrix node(this->rows, this->columns);
        for(int i = 0; i < this->rows * this->columns; i ++)
        {
            node->values[i] = std::pow(this->values[i], exponent);
        }
        return node;
    }

    Matrix exp()
    {
        Matrix node(this->rows, this->columns);
        for(int i = 0; i < this->rows * this->columns; i ++)
        {
            node->values[i] = std::exp(this->values[i]);
        }
        return node;
    }

    Matrix log()
    {
        Matrix node(this->rows, this->columns);
        for(int i = 0; i < this->rows * this->columns; i ++)
        {
            node.values[i] = std::log(this->values[i]);
        }
        return node;
    }

    Matrix abs()
    {
        Matrix node(this->rows, this->columns);
        for(int i = 0; i < this->rows * this->columns; i ++)
        {
            node.values[i] = std::abs(this->values[i]);
        }
        return node;
    }


	Matrix & operator = (const Matrix & right)
	{
        delete [] this->values;
		this->rows = right.rows;
		this->columns = right.columns;
		this->values = new E [this->rows * this->columns];
    	memcpy(this->values, right.values, this->rows * this->columns * sizeof(this->values));
        return * this;
	}

    //Addtion between 2 Matrixs
    Matrix operator + (const Matrix & matrix2) const
    {
        Matrix node(this->rows, this->columns);
        for(int i = 0; i < this->rows * this->columns; i ++)
        {
            node.values[i] = this->values[i] + matrix2.values[i];
        }
        return node;
    }

    //Addtion between Matrix and value
    Matrix operator + (double value)
    {
        Matrix node(this->rows, this->columns);
        for(int i = 0; i < this->rows * this->columns; i ++)
        {
            node.values[i] = this->values[i] + value;
        }
        return node;
    }

    //Subtraction between 2 Matrix
    Matrix operator - (const Matrix & matrix2) const
    {
        Matrix node(this->rows, this->columns);
        for(int i = 0; i < this->rows * this->columns; i ++)
        {
            node.values[i] = this->values[i] - matrix2.values[i];
        }
        return node;
    }

    //Subtraction between Matrix and value
    Matrix operator - (double value)
    {
        Matrix node(this->rows, this->columns);
        for(int i = 0; i < this->rows * this->columns; i ++)
        {
            node.values[i] = this->values[i] - value;
        }
        return node;
    }

    Matrix operator * (const Matrix & matrix2) const
    {
        Matrix node(this->rows, matrix2.columns);
        for(int i = 0; i < node.rows * node.columns; i ++)
        {
            for(int t = 0; t < this->columns; t ++)
            {
                node.values[i] += this->values[i / node.rows * this->columns + t] * matrix2.values[t * matrix2.columns + i % node.rows];
            }
        }
        return node;
    }

    Matrix operator * (double value) const
    {
        Matrix node(this->rows, this->columns);
        for(int i = 0; i < this->rows * this->columns; i ++)
        {
            node.values[i] = this->values[i] * value;
        }
        return node;
    }

/*
    //Return the Determinant of this Matrix
    //some problems
    double Determinant()
    {
        if(this->rows == 1)
        {
            return this->values[0];
        }

        double res = 0;
        for(int i = 0; i < this->rows; i ++)
        {
            if(this->values[i] == 0)
            {
                //i ++;
                continue;
            }
            //用数组储存余子式
            double yuzishi[(this->rows - 1) * (this->rows - 1)];

            //获取余子式的数组
            for(int t = 1, k = 0; t < this->rows; t ++)
            {
                for(int j = 0; j < this->rows; j ++)
                {
                    if(j == i)//跳过当前的列
                    {
                        continue;
                    }
                    yuzishi[k ++] = this->values[t * this->rows + j];                  
                }
            }
            Matrix node(this->rows - 1, yuzishi);
            node.print();
            res += pow_n1(i) * node.Determinant() * this->values[i];
        }
        return res;
    }
*/
};


int main()
{
    int rows = 4; 
    int columns = 5; 
    double values[1000] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}; 
    //double value[1000] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    Matrix matrix(rows, columns, values);
    double exponent = 2; 

    matrix.print(); 
    cout << endl; 
    matrix.pow(exponent).print(); 
    cout << endl; 

    matrix.exp().print(); 
    cout << endl; 

    matrix.log().print(); 
    cout << endl; 
    matrix.abs().print(); 
    cout << endl; 

}