import java.util.Scanner;

public class test {
    
        public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int [] arr = new int [n * n];
        for(int i = 0; i < n * n; i++) {
            arr[i] = sc.nextInt();
        }
        // System.out.println("the order of test matrix");
        // int n = 5;
        // int[] test_arr = {1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1};
        matrix t = new matrix(n, n, arr);
        // t.print();
        t.maxOne();
    }
}

public class matrix
{
    private int col;
    private int row;
    private int [] element;

    public matrix(int col, int row)
    {
        this.col = col;
        this.row = row;
        this.element = new int[row * col];
    }

    public matrix(int col, int row, int[] arr)
    {
        this.col = col;
        this.row = row;
        this.setElement(arr);
    }

    public void setElement(int[] arr)
    {
        this.element = arr;
    }

    public void print()
    {
        for(int i = 0; i < this.row * this.col; i++) {
            System.out.print(this.element[i]);
            System.out.print(' ');
            if((i + 1) % col == 0) System.out.print('\n');
        }
    }

    public int getEle(int col, int row)
    {
        return this.element[col + row * this.col];
    }

    public int order()
    {
        // return max(this.row, this.col); 没有max()函数
        return this.col > this.row ? this.col : this.row;
    }

    public Boolean allOne()
    {
        for(int i : this.element) {
            if(i != 0) {
                return false;
            }
        }
        return true;
    }

    public int getMaxCol(int start_col, int start_rol)
    {
        int res = 0;
        for(int i = start_col; i < this.col; i++) {
            if(this.getEle(i, start_rol) == 0) return res;
            res++;
        }
        return res;
    }

    public int getMaxRol(int start_col, int start_rol)
    {
        int res = 0;
        for(int i = start_rol; i < this.row; i++) {
            if(this.getEle(start_col, i) == 0) return res;
            res++;
        }
        return res;
    }

    public int [] maxOrder(int start_rol, int start_col)
    {
        int max_col = this.col, max_rol = 1;
        int [] max_order = {1, 1, 1};
        for(int i = start_rol; i < this.row; i++) {
            if(this.getEle(start_col, i) == 0) return max_order;
            int max_col_now = this.getMaxCol(start_col, i);
            max_col = max_col < max_col_now ? max_col : max_col_now;
            if(max_order[2] < (i - start_rol + 1) * max_col) {
                max_order[2] = (i - start_rol + 1) * max_col;
                max_order[1] = i - start_rol + 1;
                max_order[0] = max_col;
            }
        }
        return max_order;
    }

    public void maxOne()
    {
        int x = 0, y = 0;
        int [] max_order = {1, 1, 1};
        int [] n = {1, 1, 1};
        for(int i = 0; i < this.col; i++) {
            for(int j = 0; j < this.row; j++) {
                if(this.getEle(i, j) == 1) {
                    n = this.maxOrder(i, j);
                    if(n[2] > max_order[2]) {
                        x = i;
                        y = j;
                        max_order = n;
                    }
                }
            }
        }
        System.out.printf("position: (%d, %d), order: %d * %d\n", x, y, max_order[1], max_order[0]);
    }
}

