// #include <stdio.h>

// void siftup(int A[], int n)
// {
//     int temp, parent;
//     parent = (n - 1) / 2;
//     while (n > 0 && A[n] <= A[parent])
//     {
//         temp = A[n];
//         A[n] = A[parent];
//         A[parent] = temp;
//         n = (n - 1) / 2;
//     }
//     return;
// }

// void insert(int A[], int x, int n)
// {
//     n = n + 1;
//     A[n - 1] = x;
//     siftup(A, n - 1);
// }

// void DecreaseKey(int A[], int pos, int x)
// {
//     if (A[pos] <= x)
//     {
//         printf("Operation Fail\n");
//     }
//     else
//     {
//         A[pos] = x;
//         siftup(A, pos);
//     }
// }

// // void MinHeapify(int arr[], int posistion, int hsize)
// // {
// //     int left, right;
// //     int min;
// //     int idx = posistion;
// //     min = arr[posistion];
// //     left = (2 * posistion) + 1;
// //     right = (2 * posistion) + 2;
// //     if (left > hsize - 1)
// //     {
// //         return;
// //     }
// //     if (right > hsize - 1)
// //     {
// //         if (arr[left] < arr[idx])
// //         {
// //             int temp;
// //             temp = arr[posistion];
// //             arr[posistion] = arr[left];
// //             arr[left] = temp;
// //             min = temp;
// //             idx = left;
// //             MinHeapify(arr, idx, hsize);
// //             return;
// //         }
// //     }
// //     if (arr[left] < arr[posistion] || arr[right] < arr[posistion])
// //     {
// //         if (arr[left] < arr[posistion] && arr[right] > arr[left])
// //         {
// //             int temp;
// //             temp = arr[posistion];
// //             arr[posistion] = arr[left];
// //             arr[left] = temp;
// //             min = temp;
// //             idx = left;
// //             MinHeapify(arr, idx, hsize);
// //         }
// //         else
// //         {
// //             int temp;
// //             temp = arr[posistion];
// //             arr[posistion] = arr[right];
// //             arr[right] = temp;
// //             min = temp;
// //             idx = right;
// //             MinHeapify(arr, idx, hsize);
// //         }
// //     }
// //     else
// //     {
// //         return;
// //     }
// // }

// void MinHeapify(int A[], int pos, int n)
// {
//     int left, right, small = A[0];
//     left = (2 * pos) + 1;
//     right = (2 * pos) + 2;
//     if (left > n - 1)
//     {
//         return;
//     }
//     if (A[left] < A[pos])
//     {
//         small = left;
//     }
//     else
//     {
//         small = pos;
//     }
//     if (right <= n - 1 && A[right] < A[small])
//     {
//         small = right;
//     }
//     if (small == pos)
//     {
//         return;
//     }
//     else
//     {
//         int temp;
//         temp = A[small];
//         A[small] = A[pos];
//         A[pos] = temp;
//         MinHeapify(A, small, n);
//     }
// }

// void BuildHeap(int A[], int n)
// {
//     int ind;
//     ind = n / 2;
//     for (int i = ind; i >= 0; i--)
//     {
//         MinHeapify(A, i, n);
//     }
// }

// int ExtractMin(int A[], int n)
// {
//     int temp;
//     temp = A[0];
//     A[0] = A[n - 1];
//     n -= 1;
//     MinHeapify(A, 0, n);
//     return (temp);
// }

// int FindMin(int A[], int n)
// {
//     if (n >= 1)
//     {
//         return (A[0]);
//     }
//     else
//     {
//         return (-1);
//     }
// }

// int delete (int A[], int pos, int n)
// {
//     if (pos >= 0 && pos < n)
//     {
//         A[pos] = A[n - 1];
//         MinHeapify(A, pos, n - 1);
//         return (n - 1);
//     }
//     else
//     {
//         printf("Operation Fail\n");
//         return (n);
//     }
// }

// int main()
// {
//     int n, menu;
//     scanf("%d", &n);
//     int A[n];
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &A[i]);
//     }
//     BuildHeap(A, n);
//     while (1)
//     {
//         scanf("%d", &menu);
//         if (menu == 1)
//         {
//             int element;
//             scanf("%d", &element);
//             insert(A, element, n);
//             n += 1;
//         }
//         else if (menu == 2)
//         {
//             int pos;
//             scanf("%d", &pos);
//             n = delete (A, pos, n);
//         }
//         else if (menu == 4)
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 printf("%d\n", A[i]);
//             }
//         }
//         else if (menu == 5)
//         {
//             int pos, new_value;
//             scanf("%d", &pos);
//             scanf("%d", &new_value);
//             DecreaseKey(A, pos, new_value);
//         }
//         else if (menu == 3)
//         {
//             int temp;
//             temp = ExtractMin(A, n);
//             n -= 1;
//             printf("%d\n", temp);
//         }
//         else if (menu == 6)
//         {
//             int min;
//             min = FindMin(A, n);
//             printf("%d\n", min);
//         }
//         else if (menu == 7)
//         {
//             return 0;
//         }
//         else
//         {
//             return (-1);
//         }
//     }
// }

#include <stdio.h>

void siftup(int A[], int n)
{
    int temp, parent;
    parent = (n - 1) / 2;
    while (n > 0 && A[n] <= A[parent])
    {
        temp = A[n];
        A[n] = A[parent];
        A[parent] = temp;
        n = (n - 1) / 2;
    }
    return;
}

void insert(int A[], int x, int n)
{
    n = n + 1;
    A[n - 1] = x;
    siftup(A, n - 1);
}

void DecreaseKey(int A[], int pos, int x)
{
    if (A[pos] <= x)
    {
        printf("Operation Fail\n");
    }
    else
    {
        A[pos] = x;
        siftup(A, pos);
    }
}

void MinHeapify(int A[], int pos, int n)
{
    int left, right, small = A[0];
    left = (2 * pos) + 1;
    right = (2 * pos) + 2;
    if (left > n - 1)
    {
        return;
    }
    if (A[left] < A[pos])
    {
        small = left;
    }
    else
    {
        small = pos;
    }
    if (right <= n - 1 && A[right] < A[small])
    {
        small = right;
    }
    if (small == pos)
    {
        return;
    }
    else
    {
        int temp;
        temp = A[small];
        A[small] = A[pos];
        A[pos] = temp;
        MinHeapify(A, small, n);
    }
}

void BuildHeap(int A[], int n)
{
    int ind;
    ind = n / 2;
    for (int i = ind; i >= 0; i--)
    {
        MinHeapify(A, i, n);
    }
}

int ExtractMin(int A[], int n)
{
    int temp;
    temp = A[0];
    A[0] = A[n - 1];
    n -= 1;
    MinHeapify(A, 0, n);
    return (temp);
}

int FindMin(int A[], int n)
{
    if (n >= 1)
    {
        return (A[0]);
    }
    else
    {
        return (-1);
    }
}

int delete (int A[], int pos, int n)
{
    if (pos >= 0 && pos < n)
    {
        A[pos] = A[n - 1];
        MinHeapify(A, pos, n - 1);
        return (n - 1);
    }
    else
    {
        printf("Operation Fail\n");
        return (n);
    }
}

int main()
{
    int n, menu;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    BuildHeap(A, n);
    while (1)
    {
        scanf("%d", &menu);
        if (menu == 1)
        {
            int element;
            scanf("%d", &element);
            insert(A, element, n);
            n += 1;
        }
        else if (menu == 2)
        {
            int pos;
            scanf("%d", &pos);
            n = delete (A, pos, n);
        }
        else if (menu == 4)
        {
            for (int i = 0; i < n; i++)
            {
                printf("%d\n", A[i]);
            }
        }
        else if (menu == 5)
        {
            int pos, new_value;
            scanf("%d", &pos);
            scanf("%d", &new_value);
            DecreaseKey(A, pos, new_value);
        }
        else if (menu == 3)
        {
            int temp;
            temp = ExtractMin(A, n);
            n -= 1;
            printf("%d\n", temp);
        }
        else if (menu == 6)
        {
            int min;
            min = FindMin(A, n);
            printf("%d\n", min);
        }
        else if (menu == 7)
        {
            return 0;
        }
        else
        {
            return (-1);
        }
    }
}