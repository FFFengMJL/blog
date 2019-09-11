import java.util.Scanner;

public class Main {
    public static int getEle(int col, int row, int order_n, int [] element)
    {
        return element[col + row * order_n];
    }

    public static int getMaxCol(int start_col, int start_rol, int order_n, int [] element)
    {
        int res = 0;
        for(int i = start_col; i < order_n; i++) {
            if(getEle(i, start_rol, order_n, element) == 0) return res;
            res++;
        }
        return res;
    }

    public static int getMaxRol(int start_col, int start_rol, int order_n, int [] element)
    {
        int res = 0;
        for(int i = start_rol; i < order_n; i++) {
            if(getEle(start_col, i,order_n, element) == 0) return res;
            res++;
        }
        return res;
    }

    public static int [] maxOrder(int start_rol, int start_col, int order_n, int [] element)
    {
        int max_col = order_n, max_rol = 1;
        int [] max_order = {1, 1, 1};
        for(int i = start_rol; i < order_n; i++) {
            if(getEle(start_col, i, order_n, element) == 0) return max_order;
            int max_col_now = getMaxCol(start_col, i, order_n, element);
            max_col = max_col < max_col_now ? max_col : max_col_now;
            if(max_order[2] < (i - start_rol + 1) * max_col) {
                max_order[2] = (i - start_rol + 1) * max_col;
                max_order[1] = i - start_rol + 1;
                max_order[0] = max_col;
            }
        }
        return max_order;
    }

    public static void maxOne(int order_n, int [] element)
    {
        int x = 0, y = 0;
        int [] max_order = {0, 0, 0};
        int [] n = {0, 0, 0};
        for(int i = 0; i < order_n; i++) {
            for(int j = 0; j < order_n; j++) {
                if(element[i + j * order_n] == 1) {
                    n = maxOrder(i, j, order_n, element);
                    if(n[2] > max_order[2]) {
                        x = i;
                        y = j;
                        max_order = n;
                    }
                }
            }
        }
        System.out.printf("position: (%d,%d), order: %d*%d\n", x, y, max_order[1], max_order[0]);
    }

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
        // t.print();
        maxOne(n, arr);
        sc.close();
    }
}

// public class matrix
// {
//     private int col;
//     private int row;
//     private int [] element;

//     public matrix(int col, int row)
//     {
//         this.col = col;
//         this.row = row;
//         this.element = new int[row * col];
//     }

//     public matrix(int col, int row, int[] arr)
//     {
//         this.col = col;
//         this.row = row;
//         this.setElement(arr);
//     }

//     public void setElement(int[] arr)
//     {
//         this.element = arr;
//     }

//     public void print()
//     {
//         for(int i = 0; i < this.row * this.col; i++) {
//             System.out.print(this.element[i]);
//             System.out.print(' ');
//             if((i + 1) % col == 0) System.out.print('\n');
//         }
//     }

//     public int getEle(int col, int row)
//     {
//         return this.element[col + row * this.col];
//     }

//     public int order()
//     {
//         // return max(this.row, this.col); 没有max()函数
//         return this.col > this.row ? this.col : this.row;
//     }

//     public Boolean allOne()
//     {
//         for(int i : this.element) {
//             if(i != 0) {
//                 return false;
//             }
//         }
//         return true;
//     }

//     public int getMaxCol(int start_col, int start_rol)
//     {
//         int res = 0;
//         for(int i = start_col; i < this.col; i++) {
//             if(this.getEle(i, start_rol) == 0) return res;
//             res++;
//         }
//         return res;
//     }

//     public int getMaxRol(int start_col, int start_rol)
//     {
//         int res = 0;
//         for(int i = start_rol; i < this.row; i++) {
//             if(this.getEle(start_col, i) == 0) return res;
//             res++;
//         }
//         return res;
//     }

//     public int [] maxOrder(int start_rol, int start_col)
//     {
//         int max_col = this.col, max_rol = 1;
//         int [] max_order = {1, 1, 1};
//         for(int i = start_rol; i < this.row; i++) {
//             if(this.getEle(start_col, i) == 0) return max_order;
//             int max_col_now = this.getMaxCol(start_col, i);
//             max_col = max_col < max_col_now ? max_col : max_col_now;
//             if(max_order[2] < (i - start_rol + 1) * max_col) {
//                 max_order[2] = (i - start_rol + 1) * max_col;
//                 max_order[1] = i - start_rol + 1;
//                 max_order[0] = max_col;
//             }
//         }
//         return max_order;
//     }

//     public void maxOne()
//     {
//         int x = 0, y = 0;
//         int [] max_order = {1, 1, 1};
//         int [] n = {1, 1, 1};
//         for(int i = 0; i < this.col; i++) {
//             for(int j = 0; j < this.row; j++) {
//                 if(this.getEle(i, j) == 1) {
//                     n = this.maxOrder(i, j);
//                     if(n[2] > max_order[2]) {
//                         x = i;
//                         y = j;
//                         max_order = n;
//                     }
//                 }
//             }
//         }
//         System.out.printf("position: (%d, %d), order: %d * %d\n", x, y, max_order[1], max_order[0]);
//     }
// }

