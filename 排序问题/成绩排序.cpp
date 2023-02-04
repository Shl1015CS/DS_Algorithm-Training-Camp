//https://www.nowcoder.com/practice/0383714a1bb749499050d2e0610418b1
//注意段错误，数组越界
#include <array>
#include<iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxx = 10000;

struct Student {
    string name;
    int grade;
    int sit;
};
Student arr[maxx];
bool comp(Student lhs, Student rhs) {
    if (lhs.grade < rhs.grade) {
        return true;
    } else if (lhs.grade == rhs.grade && lhs.sit < rhs.sit) {
        return true;
    } else {
        return false;
    }
}
bool comp1(Student lhs, Student rhs) {
    if (lhs.grade > rhs.grade) {
        return true;
    } else if (lhs.grade == rhs.grade && lhs.sit < rhs.sit) {
        return true;
    } else return false;
}
int main() {
    int N;
    int order;
    while (scanf("%d%d", &N, &order) != EOF) {
        for (int i = 0; i < N ; ++i) {
            cin >> arr[i].name >> arr[i].grade;
            arr[i].sit = i;
        }
        if (1 == order) {
            sort(arr, arr + N, comp);
        }
        if (0 == order) {
            sort(arr, arr + N, comp1);
        }
        for (int i = 0; i < N ; ++i) {
            cout << arr[i].name << " " << arr[i].grade << endl;
        }
    }
    return 0;
}
