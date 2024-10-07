#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void ShellSort(int* a, int n)
{
    int gap = n;
    while (gap > 1)
    {
        gap = gap /= 3 + 1;

        for (int i = 0; i < n - gap; i += gap)
        {
            int temp = a[i + gap];
            int end = i;

            while (end >= 0)
            {
                if (a[end] > temp)
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            a[end + gap] = temp;
        }
    }
}

int main()
{
	int arr[2] = { 3,-1 };
	ShellSort(arr, 2);
}