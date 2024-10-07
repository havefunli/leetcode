#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int GetMidi(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}


void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int begin = left;
	int end = right;

	int midi = GetMidi(a, left, right);
	swap(&a[left], &a[midi]);

	int keyi = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}

		swap(&a[left], &a[right]);
	}
	swap(&a[keyi], &a[left]);

	keyi = left;
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {

	QuickSort(nums, 0, numsSize);
	*returnSize = numsSize;

	return nums;
}

int main()
{
	int arr[10] = { 1,5,6,4,7,8,9,3,2,10 };

	sortArray(arr, 10, 10);
}