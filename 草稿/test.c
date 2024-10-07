#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//int removeElement(int* nums, int numsSize, int val)
//{
//    int fast = 0;
//    int slow = 0;
//
//    while (fast < numsSize)
//    {
//        if (nums[fast] != val)
//        {
//            nums[slow++] = nums[fast++];
//        }
//        else
//        {
//            fast++;
//        }
//    }
//    return slow;
//}
//
//int main()
//{
//	int arr[4] = {3, 2, 2, 3};
//	int val = 3;
//
//    int len = removeElement(arr, 4, 3);
//
//    for (int i = 0; i < len; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//
//    return 0;
//}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int arr[100000] = { 0 };
    int i = 0;
    int j = numsSize - 1;
    int k = numsSize - 1;

    while (i <= j) {
        if (nums[i] * nums[i] > nums[j] * nums[j]) {
            arr[k--] = nums[i] * nums[i];
            i++;
        }
        else {
            arr[k--] = nums[j] * nums[j];
            j--;
        }
    }
    return arr;
}

int main()
{
	//int arr[5] = { -4,-1,0,3,10 };
 //   int* ptr = sortedSquares(arr, 5, 4);

    double i = 1;
    double nums = 0;

    float c = (float)1 / 3;
    printf("%f\n", c);

    for (i = 1; i < 201; i += 2) {
        double b = (double)(1 / i);
        double a = (double)(1 / i) * pow(-1, (i - 1) / 2);
        nums += a ;
    }

    printf("%f\n", nums * 4);
}