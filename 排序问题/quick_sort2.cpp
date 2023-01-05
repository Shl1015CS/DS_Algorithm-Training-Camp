void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;
    int x = q[l] , i = l, j = r;
    while (i < j)
    {
        while (j > i && q[j] >= x)
            j--;
        while (i < j && q[i] <= x)
            i++;
        swap(q[i], (i == j) ? q[l] : q[j]);  
    }
    quick_sort(q, l, i-1);
    quick_sort(q, j+1, r);
}
//这个就不适用的do-while语句，因为有些地方可能用不习惯do-while
//开启Q2优化，洛谷能过
