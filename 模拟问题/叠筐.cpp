#include <algorithm>
#include <iostream>
#include <cstdio>
//题目来源是杭电oj中的叠筐
/* 2023/01/16
 * 图案问题为 -> 建立二维数组 + 找数字规律
 * 循环的每一步罗列出来从中循州规律
 * 把规律变成代码
 */

using namespace std;

int main() {
    int n;
    char inner,outter;
    bool flag = true;
    while(cin >> n >> inner >> outter) {
        if(flag == true)
        {
            flag = false;
        }else {
            cout << endl ;
        }
        char patten[80][80] = {0};//定义二维数组可以定义初始化为0
        char color = inner;
        int x, y;
        for (int length = 1, x = n / 2, y = n / 2; length <= n; length += 2, --x, --y) {
            //xy为起点下标， 每次迭代都到左上，每次填满一个框框
            for (int i = x, j = y; i < x + length; ++i) {
                patten[i][j] = color;
            }
            for (int j = y, i = x; j < y + length; ++j) {
                patten[i][j] = color;
            }
            for (int i = x + length - 1, j = y; j < y + length; ++j) {
                patten[i][j] = color;
            }
            for (int i = x, j = y + length - 1; i < x + length; ++i) {
                patten[i][j] = color;
            }
            //更换内外
            if (color == inner) {
                color = outter;
            } else {
                color = inner;
            }
        }
        if (n != 1) {
            patten[0][0] = ' ';
            patten[0][n - 1] = ' ';
            patten[n - 1][0] = ' ';
            patten[n - 1][n - 1] = ' ';
        }
        for (int i = 0; i < n; ++i) {
            printf("%s\n", patten[i]);
        }
        //printf("%d,%c,%c",n,inner,outter);
    }
    return 0;
}
