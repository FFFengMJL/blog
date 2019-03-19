#include<iostream>
#include<iomanip>
#include<string.h>
#include<stdio.h>
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
        this->values = new double [rows * column];
        for(int i = 0; i < rows * column; i ++)
        {
            values[i] = 0;
        }
    }

    // initializes all elements in the matrix to the given values. 
    Matrix(int rows, int column, double values[])
    {
        this->rows = rows;
        this->columns = column;
        this->values = new double [rows * column];
        memcpy(this->values, values, rows * column * sizeof(this->values));
    }

    Matrix(const Matrix & matrix2)
    {
		this->rows = matrix2.rows;
		this->columns = matrix2.columns;
		this->values = new double [this->rows * this->columns];
		memcpy(this->values, matrix2.values, this->rows * this->columns * sizeof(this->values));
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
	void set(int row, int column, double value)
	{
		this->values[(row - 1) * this->columns + column - 1] = value;
	}

    //Matrix equaltion
	Matrix & operator = (const Matrix & right)
	{
        delete [] this->values;
		this->rows = right.rows;
		this->columns = right.columns;
		this->values = new double [this->rows * this->columns];
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

    //Return the Determinant of this Matrix
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

};


int main()
{
    return 0;
}