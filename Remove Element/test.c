#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int removeElement(int* nums, int numsSize, int val) 
{
    int* left = nums;
    int* right = nums + numsSize - 1;
    int  count = 0;
    while (left <= right)
    {
        if (*right == val)
        {
            right--;
        }
        if (*left != val)
        {
            left++;
        }
        if (left >= right)
            break;
        if (*left == val && *right != val)
        {
            int temp = 0;
            temp = *left;
            *left = *right;
            *right = temp;
            count++;
        }
    }

    return numsSize - count;
}

int main()
{
    int nums[4] = { 3,2,2,3 };
    int numsSize = 4;
    int value = 3;

    int len = removeElement(nums, numsSize, value);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}