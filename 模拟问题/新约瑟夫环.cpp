//https://ac.nowcoder.com/acm/problem/15595 (来源)
//我有一个测例没通过，不知道为啥tmd，我觉得我写的没啥问题

#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n, m;
    deque<int> q;
    cin >> n >> m;

    // 将人员编号从1到n加入队列中
    for (int i = 0; i < n; i++) {
        q.push_back(i);
    }

    // 模拟出圈的过程
    int sign = 1; //处理顺逆时针
    while (q.size() > 1) {
        // 报数为m的人员出圈
        if(sign == 1) {
            for (int i = 1; i < m; i++) {
                q.push_back(q.front());
                q.pop_front();
            }
            q.pop_front();
            sign = 2;
        }
        if(sign == 2) {
            for (int i = 1; i < m; i++) {
                q.push_front(q.back());
                q.pop_back();
            }
            q.pop_front();
            sign = 1;
        }
    }

    // 输出最后留下的人员编号
    cout << q.front() << endl;

    return 0;
}
