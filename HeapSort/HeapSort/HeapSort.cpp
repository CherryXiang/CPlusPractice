#include <iostream>

using namespace std;

void heapAdjust1(int a[], int len, int index)
{
	int left = 2*index + 1;
	int right = 2*index +2;

	if ((index > len - 1) || (left > len - 1) || (right > len - 1))
	{
		return;
	}

	if (a[index] > a[left] && a[index] > a[right])
	{
		return;
	}

	int temp = a[index];

	if (a[left] > a[right])
	{
		a[index] = a[left];
		a[left] = temp;
		heapAdjust1(a, len, left);
	}
	else
	{
		a[index] = a[right];
		a[right] = temp;
		heapAdjust1(a, len, right);
	}
}

void HeapAdjust2(int a[], int len, int i)
{
	int nChild;
	int nTemp;

	for (nTemp = array[i]; 2 * i + 1 < len; i = nChild)
	{
		nChild = 2 * i + 1;

		if ( nChild < len-1 && array[nChild + 1] > array[nChild])
			++nChild;

		if (nTemp < array[nChild])
		{
			array[i] = array[nChild];
			array[nChild]= nTemp;
		}
		else
		{
			break;
		}
	}
}

void heapCreate(int a[], int len)
{
	for (int i = (len/2 - 1); i >= 0; i--)
	{
		heapAdjust(a, len, i);
	}
}

void heapSort(int a[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

	heapCreate(a, len);

	for (int i = len - 1; i >= 0; --i)
	{
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapAdjust(a, i, 0);
	}

	for (int i = 0; i < len; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int a[13] = {7, 3, 9, 1, 2, 8, 12, 4, 6, 18, 5, 21, 10};
	heapSort(a, 13);

	return 0;
}