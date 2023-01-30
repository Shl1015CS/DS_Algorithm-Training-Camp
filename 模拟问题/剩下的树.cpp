//剩下的树，KN25
#include <iostream>
using  namespace std;
int main() {
    int tree[10010];
    int L,M;
    while(cin >> L >> M)
    {
        for(int init = 0 ;init <= L;++ init )
        {
            tree[init] = 1;//表示树活
        }
        for(int num = 0;num < M ;++ num)
        {
            int left , right;
            cin >> left >> right;
            for (int idx = left; idx <= right; ++idx) {
                tree[idx] = 0;
            }
        }
        int total = 0;
        for (int i = 0; i <= L; ++i) {
            if(1 == tree [i])
                ++ total;
        }
        cout << total;
    }
    return 0;
}
