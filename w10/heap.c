//Program about heap and its functions
#include <stdio.h>

void shiftup(int arr[], int idx) //shifts up the given element at index   "idx"
{
    int temp;
    int parent;
    parent = (idx - 1) / 2;
    while (arr[idx] <= arr[parent] && idx > 0)
    {
        temp = arr[parent];
        arr[parent] = arr[idx];
        arr[idx] = temp;
        idx = (idx - 1) / 2;
    }
}

void insert(int arr[], int num, int hs) //inserts a number into heap.
{
    hs = hs + 1;
    arr[hs - 1] = num;
    shiftup(arr, hs - 1);
}

void decrease_key(int arr[], int posn, int value, int hs) //decreases the value of the element.
{
    if (posn > hs - 1)
    {
        printf("Operation Fail\n");
    }
    else if (arr[posn] <= value)
    {
        printf("Operation Fail\n");
    }
    else
    {
        arr[posn] = value;
        shiftup(arr, posn);
    }
}

void min_heapify(int arr[], int posn, int hs) //performs the min heapify function.
{
    int left, right;
    int smallest_idx; // = posn;
    left = (2 * posn) + 1;
    right = (2 * posn) + 2;
    if (posn >= hs / 2)
    {
        return;
    }
    if (arr[left] < arr[posn])
    {
        smallest_idx = left;
    }
    else
    {
        smallest_idx = posn;
    }
    if (right <= hs - 1 && arr[right] < arr[smallest_idx])
    {
        smallest_idx = right;
    }
    if (smallest_idx == posn)
    {
        return;
    }
    else
    {
        int temp;
        temp = arr[smallest_idx];
        arr[smallest_idx] = arr[posn];
        arr[posn] = temp;
        min_heapify(arr, smallest_idx, hs);
    }
}

void build_heap(int arr[], int hs) //builds the heap.
{
    int i;
    i = hs / 2;
    for (int k = i; k > -1; k--)
    {
        min_heapify(arr, k, hs);
    }
}

int extract_min(int arr[], int hs) //this will extract minimum value in the heap.
{
    int temp;
    temp = arr[0];
    arr[0] = arr[hs - 1];
    hs = hs - 1;
    min_heapify(arr, 0, hs);
    return temp;
}

int find_min(int arr[], int idx) //this will return the first element of the heap if it is not empty.
{
    if (idx > 0)
    {
        return arr[0];
    }
    else
    {
        printf("Operation faild\n");
        return -1;
    }
}

int delete (int arr[], int posistion, int hs) //this will delete a number from the heap.
{
    if (posistion >= 0 && posistion < hs)
    {
        arr[posistion] = arr[hs - 1];
        min_heapify(arr, posistion, hs - 1);
        return hs - 1;
    }
    else
    {
        printf("Operation Fail\n");
        return hs;
    }
}

void print_heap(int arr[], int n) //this will print the heap.
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void wrapper(int heap[], int *hsize, int *a)
{
    if (*a == 1)
    {
        int num;
        scanf("%d", &num);
        insert(heap, num, *hsize);
        *hsize = *hsize + 1;
    }
    else if (*a == 2)
    {
        int posistion;
        scanf("%d", &posistion);
        *hsize = delete (heap, posistion, *hsize);
    }
    else if (*a == 3)
    {
        int temp;
        temp = extract_min(heap, *hsize);
        *hsize = *hsize - 1;
        printf("%d\n", temp);
    }
    else if (*a == 4)
    {
        print_heap(heap, *hsize);
    }
    else if (*a == 5)
    {
        int posistion;
        int value;
        scanf("%d", &posistion);
        scanf("%d", &value);
        decrease_key(heap, posistion, value, *hsize);
    }
    else if (*a == 6)
    {
        int temp;
        temp = find_min(heap, *hsize);
        if (temp == -1)
        {
            printf("Operation Fail\n");
        }
        printf("%d\n", temp);
    }
}

int main()
{
    int m, n;
    int hsize = 0;
    scanf("%d", &hsize);
    //hsize = num;
    int heap[100];
    for (int i = 0; i < hsize; i++)
    {
        scanf("%d", &heap[i]);
    }
    build_heap(heap, hsize);
    while (1)
    {
        int a;
        scanf("%d", &a);
        if (a > 0 && a < 7)
        {
            wrapper(heap, &hsize, &a);
        }
        else if (a == 7)
        {
            break;
        }
    }
}
//ma'am most of the code is given by jasine ma'am in the class itself.