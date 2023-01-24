#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int year,n;
    int mday[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};//每个月的天数
    while (cin >> year >> n)
    {
        int day = 1;
        int mon = 1;
        for (int i = 0; i < n-1; ++i) {
            bool isRun = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0 );//闰年判断
            if(isRun)
            {
                mday[2]=29;
            }else
            {
                mday[2]=28;
            }
            ++ day;
            if(day >mday[mon])
            {
                day = 1;
                ++ mon;
            }
            if(mon >= 13)
            {
                mon = 1;
                year ++;
            }
        }
        printf("%04d-%02d-%02d\n",year,mon,day);
    }
}
