#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

#define numsSize 1

//void rotate(int* nums, int k)
//{
//    int arr[numsSize] = { 0 };
//
//      for (int i = 0; i < k; i++)
//    {
//        arr[i] = nums[numsSize  - k + i];
//    }
//
//    for (int i = 0; i < numsSize - k; i++)
//    {
//        arr[k  + i] = nums[i];
//    }
//
//    for (int k = 0; k < numsSize; k++)
//    {
//        printf("%d ", arr[k]);
//    }
//}
//
//int main()
//{
//    int  nums[1] = { 6 };
//
//     rotate(nums, 3);
//
//    return 0;
//}

int main()
{
	int arr[6] = { 1,2,3,4,6 };
	int nums = 0;

	for (int i = 0; i <= 6; i++)
	{
		nums = nums ^ i;
	}

	for (int i = 0; i < 6; i++)
	{
		nums^ arr[i];
	}
	return 0;
}