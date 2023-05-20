// using structure
#include <stdio.h>
typedef struct Pair
{
    int min;
    int max;
} maxmin;
int arr[6] = {10, 90, 80, 20, 70, 50};
maxmin Maxmin(int i, int j)
{
    maxmin m1, m2, m;
    if (i == j)
    {
        m.max = arr[i];
        m.min = arr[i];
        return m;
    }
    else if (i == j - 1)
    {
        if (arr[i] > arr[j])
        {
            m.max = arr[i];
            m.min = arr[j];
        }
        else
        {
            m.max = arr[j];
            m.min = arr[i];
        }
        return m;
    }
    else
    {
        int mid = (i + j) / 2;
        m1 = Maxmin(i, mid);
        m2 = Maxmin(mid + 1, j);
        if (m2.max > m1.max)
        {
            m.max = m2.max;
        }
        else
        {
            m.max = m1.max;
        }
        if (m2.min < m1.min)
        {
            m.min = m2.min;
        }
        else
        {
            m.min = m1.min;
        }
        return m;
    }
}

int main(void)
{
    maxmin p;
    p = Maxmin(0, 5);
    printf("Max: %d, Min: %d\n", p.max, p.min);
    return 0;
}