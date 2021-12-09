//
//  lab.cpp
//  BFS
//
//  Created by Hoang Viet on 08/11/2021.
//
#include<iostream>
void merge(int arr[], int left, int mid, int right)
{
    int i, j, finallArrInd;
    int arrayLeftSize = mid - left + 1;
    int arrayRightSize =  right - mid;
    int L[arrayLeftSize], R[arrayRightSize];
    for (i = 0; i < arrayLeftSize; i++)
        L[i] = arr[left + i];
    for (j = 0; j < arrayRightSize; j++)
        R[j] = arr[mid + 1+ j];
    i = 0;
    j = 0;
    finallArrInd = left;
    while (i < arrayLeftSize && j < arrayRightSize){
        if (L[i] <= R[j])
        {
            arr[finallArrInd] = L[i];
            i++;
        }
        else
        {
            arr[finallArrInd] = R[j];
            j++;
        }
        finallArrInd++;
    }
    while (i < arrayLeftSize)
    {
        arr[finallArrInd] = L[i];
        i++;
        finallArrInd++;
    }
    while (j < arrayRightSize)
    {
        arr[finallArrInd] = R[j];
        j++;
        finallArrInd++;
    }
}
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left+(right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
 
        merge(arr, left, mid, right);
    }
}
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
//int main()
//{
//    int arr[] = {12, 11, 13, 5, 6, 7};
//    int arr_size = sizeof(arr)/sizeof(arr[0]);
// 
//    printf("Given array is \n");
//    printArray(arr, arr_size);
// 
//    mergeSort(arr, 0, arr_size - 1);
// 
//    printf("\nSorted array is \n");
//    printArray(arr, arr_size);
//    return 0;
//}
