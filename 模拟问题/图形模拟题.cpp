
// Created by 16651 on 2023/1/14.

/*
 * 清华大学上机考试题
 * 输出梯形
 */
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

char arr[1000][3000] ;

int main()
/*
{
    int n;
    while(cin >> n)
    {
        for (int i = 0; i < n; i++)//梯形格数
        {
            for (int j = 0; j < 2 * n - 2 - 2 * i; j++) {
                cout << " ";//打印空格
            }
            for (int k = 0; k < n + 2 * i; k++) {
                cout << "*";//打印✳
            }
            cout << endl;//换行
        }
    }
    return 0;
}
*/
{
    int h;
    while(cin >> h)
    {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < 3*h - 2; ++j) {
                arr[i][j] = ' ';
            }
            arr[i][3 * h -2] = '\0';//每一行字符串结束
        }
        int beg = 0 ;
        for (int i = h - 1; i >= 0; --i) {
            for (int j = beg; j < 3 * h - 2 ; ++j) {
                arr[i][j] = '*';
            }
            beg += 2;
        }
        for(int  i =0; i < h; ++ i) {
/*            for(int j = 0 ; j < 3 * h - 2; ++ j){
                printf("%c" , arr[i][j]);
            }
            printf("\n"); */
            printf("%s", arr[i]);
            printf("\n");
        }
    }
    return 0;
}
