//Problem: 100.
For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).

#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

void merge(Pair* arr, int left, int mid, int right, int* count) {
    int n = right - left + 1;
    Pair* temp = (Pair*)malloc(n * sizeof(Pair));
    int i = left, j = mid + 1, k = 0, rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            count[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = 0; p < n; p++) {
        arr[left + p] = temp[p];
    }

    free(temp);
}

void mergeSort(Pair* arr, int left, int right, int* count) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);
    merge(arr, left, mid, right, count);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    Pair* arr = (Pair*)malloc(numsSize * sizeof(Pair));
    int* count = (int*)calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, 0, numsSize - 1, count);

    free(arr);
    *returnSize = numsSize;
    return count;
}
