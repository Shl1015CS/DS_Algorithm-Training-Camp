// 题目来源是KY108
/* map的使用C++特有
 * map的功能是映射关系
 *
 */
#include <map>
#include <cstdio>
#include <string>
using namespace std;
int main() {
    int mDay[13] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};
    string Weekday[7] = {"Sunday","Monday","Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int year,mon,day;
    char str[100];
    string month;
    //键 key（很像数组下标） --> 值 value
    //<key 类型, value 类型>
    map<string,int> myMap = {
            {"January",1},
            {"February",2},
            {"March",3},
            {"April",4},
            {"May",5},
            {"June",6},
            {"July",7},
            {"August",8},
            {"September",9},
            {"October",10},
            {"November",11},
            {"December",12},
    };
    bool isBefore;
    while(scanf("%d%s%d",&day,str,&year) != EOF)
    {
        month = str;//把C字符转换成C++
        mon = myMap[month];//下表month对应的整数
        if(year < 2022
        || 2022 == year && mon <11
        || 2022 == year && 11 == mon && day < 3){
            isBefore =true;
        }else {
            isBefore = false;
        }
        int bY,bM,bD,eY,eM,eD;
        if(isBefore){
            bY = year;
            bM = mon;
            bD = day;
            eY = 2022;
            eM = 11;
            eD = 3;
        }else{
            bY = 2022;
            bM = 11;
            bD = 3;
            eY = year;
            eM = mon;
            eD = day;
        }
        int totalDay = 0;
        while(true)
        {
            if(bY == eY
            && bM == eM
            && bD == eD)
            {
                break;
            }
            ++ totalDay;
            //nextday计算距离现在多少天
            bool isLeap = (bY % 400 == 0 || bY %4 == 0 && bY % 100 !=0);
            if(isLeap){
                mDay[2] = 29;
            }else{
                mDay[2] = 28;
            }
            ++bD;
            if(bD > mDay[bM]){
                bD = 1;
                ++ bM;
                if(bM > 12){
                    bM = 1;
                    ++ bY;
                }
            }
        }
        if(isBefore){
            printf("%s\n",Weekday[(11-totalDay%7)%7].c_str());
        }else{
            printf("%s\n",Weekday[(totalDay+4)%7].c_str());
        }
    }
}
