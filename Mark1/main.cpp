#include<iostream>
using namespace std;

int main()
{
	int arr1[9] = {10, 20, 40, 60, 80, 100, 150, 170, 190 };
	int arr2[6] = {30, 50, 70, 90, 110, 130};
	
	int size_of_arr1 = sizeof(arr1) / sizeof(arr1[0]);
	int size_of_arr2 = sizeof(arr2) / sizeof(arr2[0]);

	int size_of_arr3 = size_of_arr1 + size_of_arr2;
	int* arr3 = new int[size_of_arr3]();

	int i = 0;
	int j = 0;
	int k = 0;

	while (i < size_of_arr1 && j < size_of_arr2)
	{
		if (arr1[i] < arr2[j])
			arr3[k++] = arr1[i++];
		else
			arr3[k++] = arr2[j++];
	}

	for(; i < size_of_arr1; )
		arr3[k++] = arr1[i++];

	for (; j < size_of_arr2; )
		arr3[k++] = arr2[j++];

	for(auto l = 0; l < size_of_arr3; ++l)
	{
		cout << arr3[l] << endl;
	}

	return 0;
}
