#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int search(int low, int high, int arr[], int x)
{
	while (low <= high)
	{
		int mid = low + (high - low)/2;
		
		if (arr[mid] == x)
		{
			return mid;
		
		}else if (arr[mid] > x)
		{
			high = mid - 1;
		
		}else if (arr[mid] < x)
		{
			low = mid + 1;
		}
	}
	
	return -1;
}

int main ()
{
	int n, arr[100], x;
	cout << "- Enter a number of elements : ";
	cin  >> n;
	
	
	cout << "- Enter " << n << " element            : ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	
	cout << "- Search for element         : " ;
	cin  >> x;
	int result = search(0, n - 1, arr, x);
	
	if (result == -1)
	{
		cout << endl << "~ Element not found!" << endl;
	
	}else{
		
		cout << endl << "~ Element is located at index number : " << result + 1 << endl;
	}
}