//题目地址牛客网KY19
//日期问题常用技巧

/* 闰年判断
 * 利用辅助数组,用空间换时间
 * 让代码量变得精简
 */

#include <iostream>
using namespace std;

int main() {
    int year,mon,day;//定义变量
    int mday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};//每个月的天数
    int totalday[13] = {0};
    for (int mon = 2; mon <= 12 ; ++mon) {

        totalday[mon] = totalday [mon-1]+mday[mon-1];//叠加器

    }
    while(cin >> year >>mon >> day)
    {
        bool isRun = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0 );//闰年判断
        if(isRun && mon > 2) // 闰年且大于2月才会对时间有所影响
        {
            cout << totalday[mon] + day +1 << endl; //闰年加一天
        } else {
            cout << totalday[mon] + day << endl;
        }
    }
    return 0;
}
