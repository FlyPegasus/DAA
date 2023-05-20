/*
Priority Queue using min heap.
Never try to make Heap index start with 0; since loops need to run i/2 and if 0 indexed then
there could be problem for infinite loops and hence wrong output or program crash.
*/
#include <stdio.h>
#define HEAPCAP 100
int heap[HEAPCAP]; // heap initialised
int heapsize = 0;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void insertKey(int key)
{
    if (heapsize == HEAPCAP)
    {
        printf("Overflow.\n");
        return;
    }
    heapsize++;
    heap[heapsize] = key;
    int i = heapsize;
    while (i > 1 && heap[i] < heap[i / 2])
    {
        swap(&heap[i], &heap[i / 2]);
        i = i / 2;
    }
}
void disp_min()
{
    printf("Min: %d\n", heap[1]);
}
// lets adjust the heap
void adjust(int i, int n)
{
    int j = 2 * i;
    int item = heap[i];
    while (j <= n)
    {
        if (j < n && heap[j] > heap[j + 1])
        {
            j = j + 1;
        }
        if (item <= heap[j])
        {
            break;
        }
        swap(&heap[j], &heap[j / 2]);
        j = j * 2;
    }
}
// Now lets delete
void del()
{
    if (heapsize == 0)
    {
        printf("Heap is empty!\n");
        return;
    }
    printf("Deleted: %d\n", heap[1]);
    heap[1] = heap[heapsize];
    heapsize--;
    adjust(1, heapsize);
}
int main(void)
{
    insertKey(9);
    insertKey(5);
    insertKey(3);
    insertKey(7);
    insertKey(1);
    del();
    disp_min();
    return 0;
}
