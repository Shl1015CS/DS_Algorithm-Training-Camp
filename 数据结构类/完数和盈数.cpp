#题源 https://www.nowcoder.com/practice/ccc3d1e78014486fb7eed3c50e05c99d?tpId=60&tqId=29492&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking
#KN20
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int shu(int i){
    int sum = 1;
    for(int j = 2;j < i; ++j){
        if(i % j == 0) sum+= j;
    }
    return sum;
}
int main() {
    vector<int> vec1;
    vector<int> vec2;
    for(int i = 2; i <= 60; ++i){
        if(shu(i) == i) vec1.push_back(i);
        else if (shu(i) > i) vec2.push_back(i);
    }
    printf("E:");
    for(vector<int>::iterator it=vec1.begin();it != vec1.end(); ++it){
        printf(" %d", *it);
    }
    printf("\n");
    printf("G:");
    for(vector<int>::iterator it=vec2.begin();it != vec2.end(); ++it){
        printf(" %d", *it);
    }
    printf("\n");
    return 0;
}
