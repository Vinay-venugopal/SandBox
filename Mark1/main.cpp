#include<iostream>
using namespace std;

struct Array {
	int A[20];
	int size;
	int length;
};

void Display(struct Array arr)
{
	for (auto i = 0; i < arr.length; i++)
	{
		cout << arr.A[i] << " ";
	}
	cout << endl;
}

void Append(struct Array* arr, int x)
{
	if (arr->length < arr->size)
	{
		arr->A[arr->length++] = x;
	}
}

void insert(struct Array* arr, int index, int x)
{
	if (index >= 0 && index <= arr->length)
	{
		for (int i = arr->length; i > index; i--)
		{
			arr->A[i] = arr->A[i - 1];
		}

		arr->A[index] = x;
		arr->length++;
	}
}

int Delete(struct Array* arr, int index)
{
	int x = 0;

	if (index >= 0 && index < arr->length)
	{
		x = arr->A[index];

		for (int i = index; i < arr->length - 1; i++)
		{
			arr->A[i] = arr->A[i + 1];
		}

		arr->length--;

		return x;
	}

	return x;
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int LinearSearch(struct Array *arr, int key)
{
	for (int i = 0; i < arr->length; i++)
	{
		if (arr->A[i] == key)
		{
			//swap(&arr->A[i], &arr->A[i - 1]); // Improvement of Linear Search: 1. Tranportation
			swap(&arr->A[i], &arr->A[0]);		// Improvement of Linear Search: 2. Move to Front/Head
			return i;
		}
	}

	return -1;
}

int BinarySearch(struct Array arr, int key)
{
	int l = 0;
	int h = arr.length - 1;
	
	while (l <= h)
	{
		int mid = (l + h) / 2;

		if (arr.A[mid] == key)
			return mid;
		else if (arr.A[mid] > key)
			h = mid - 1;
		else
			l = mid + 1;
	}

	return -1;
}

int RBinSearch(struct Array arr, int l, int h, int key)
{
	if (l <= h)
	{
		int mid = (l + h) / 2;

		if (arr.A[mid] == key)
			return mid;
		else if (arr.A[mid] > key)
			return RBinSearch(arr, l, mid - 1, key);
		else
			return RBinSearch(arr, mid + 1, h, key);
	}

	return -1;
}

int Get(struct Array arr, int index)
{
	if (index >= 0 && index < arr.length)
		return arr.A[index];

	return -1;
}

void Set(struct Array* arr, int index, int x)
{
	if (index >= 0 && index < arr->length)
		arr->A[index] = x;
}

int Max(struct Array arr)
{
	int max = arr.A[0];

	for (auto i = 1; i < arr.length; ++i)
	{
		if (arr.A[i] > max)
			max = arr.A[i];
	}

	return max;
}

int Min(struct Array arr)
{
	int min = arr.A[0];

	for (auto i = 1; i < arr.length; ++i)
	{
		if (arr.A[i] < min)
			min = arr.A[i];
	}

	return min;
}

int Sum(struct Array arr)
{
	int sum = 0;

	for (auto i = 0; i < arr.length; ++i)
	{
		sum += arr.A[i];
	}

	return sum;
}

float Avg(struct Array arr)
{
	return (float)Sum(arr) / arr.length;
}

void Reverse(struct Array* arr)
{
	int* B = new int[arr->length]();

	for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
	{
		B[j] = arr->A[i];
	}

	for (int i = 0; i < arr->length; i++)
	{
		arr->A[i] = B[i];
	}
}

void Reverse2(struct Array* arr)
{
	for (int i = 0, j = arr->length - 1; i < j; i++, j--)
	{
		swap(&arr->A[i], &arr->A[j]);
	}
}

void LeftShift(struct Array* arr)
{
	for (int i = 0; i < arr->length - 1; i++)
	{
		arr->A[i] = arr->A[i + 1];
	}

	arr->A[arr->length - 1] = 0;
}

void LeftRotate(struct Array* arr)
{
	int temp = arr->A[0];

	for (int i = 0; i < arr->length - 1; i++)
	{
		arr->A[i] = arr->A[i + 1];
	}

	arr->A[arr->length - 1] = temp;
}

void RightShift(struct Array* arr)
{
	for (int i = arr->length - 1; i > 0; i--)
	{
		arr->A[i] = arr->A[i - 1];
	}

	arr->A[0] = 0;
}

void RightRotate(struct Array* arr)
{
	int temp = arr->A[arr->length - 1];

	for (int i = arr->length - 1; i > 0; i--)
	{
		arr->A[i] = arr->A[i - 1];
	}

	arr->A[0] = temp;
}

void InsertSort(struct Array* arr, int x)
{
	if (arr->length == arr->size)
		return;

	int i = arr->length - 1;

	while (i >= 0 && arr->A[i] > x)
	{
		arr->A[i + 1] = arr->A[i];
		i--;
	}

	arr->A[i + 1] = x;
	arr->length++;
}

int isSorted(struct Array arr)
{
	for (int i = 0; i < arr.length - 1; i++)
	{
		if (arr.A[i] > arr.A[i + 1])
			return 0;
	}

	return 1;
}

void ReArrange(struct Array* arr)
{
	int i = 0;
	int j = arr->length - 1;

	while (i < j)
	{
		while (arr->A[i] < 0)i++;
		while (arr->A[j] >= 0)j--;

		if (i < j)
		{
			swap(&arr->A[i], &arr->A[j]);
		}
	}
}

struct Array* Merge(struct Array* arr1, struct Array* arr2)
{
	int i, j, k;
	i = j = k = 0;

	struct Array* arr3 = new struct Array();

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else
			arr3->A[k++] = arr2->A[j++];
	}

	for(; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];

	for (; j < arr2->length; j++)
		arr3->A[k++] = arr2->A[j];

	arr3->length = arr1->length + arr2->length;
	arr3->size = 10;

	return arr3;
}

struct Array* Union(struct Array* arr1, struct Array* arr2)
{
	int i, j, k;
	i = j = k = 0;

	struct Array* arr3 = new struct Array();

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if(arr1->A[i] > arr2->A[j])
			arr3->A[k++] = arr2->A[j++];
		else
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}

	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];

	for (; j < arr2->length; j++)
		arr3->A[k++] = arr2->A[j];

	arr3->length = k;
	arr3->size = 10;

	return arr3;
}

struct Array* Intersection(struct Array* arr1, struct Array* arr2)
{
	int i, j, k;
	i = j = k = 0;

	struct Array* arr3 = new struct Array();

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			i++;
		else if (arr1->A[i] > arr2->A[j])
			j++;
		else if(arr1->A[i] == arr2->A[j])
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}

	arr3->length = k;
	arr3->size = 10;

	return arr3;
}

struct Array* Difference(struct Array* arr1, struct Array* arr2)
{
	int i, j, k;
	i = j = k = 0;

	struct Array* arr3 = new struct Array();

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if (arr1->A[i] > arr2->A[j])
			j++;
		else
		{
			i++;
			j++;
		}
	}

	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];

	arr3->length = k;
	arr3->size = 10;

	return arr3;
}

int main()
{
	//struct Array arr = { {2,3,4,5,6,11,15,17,20,25,35,41,47,56,57,60,70,80,90}, 20, 19 };
	//struct Array arr = { {2,3,4,-11,-9,11,15,17,20,25,35,41,47,-2,57,60,-55,-95,-120}, 20, 19 }; // for testing ReArrange method
	//struct Array arr1 = { {2, 4, 5, 6, 7}, 10, 5 };
	//struct Array arr2 = { {1, 3, 9, 10, 15}, 10, 5 };
	//struct Array* arr3;

	//Append(&arr, 10);
	
	//insert(&arr, 2, 9);
	
	//int x = Delete(&arr, 4);
	//cout << x << endl;

	//int index = LinearSearch(&arr, 5);
	//cout << index << endl;

	//int index = BinarySearch(arr, 100);
	//cout << index << endl;

	//int index = RBinSearch(arr, 0, arr.length - 1, 202);
	//cout << index << endl;

	//cout << "Get at 15: " << Get(arr, 15) << endl;
	//
	//cout << "Set 20 at 15: " << endl;
	//Set(&arr, 15, 20);
	//cout << "Get at 15: " << Get(arr, 15) << endl;

	//cout << "Max: " << Max(arr) << endl;
	//cout << "Min: " << Min(arr) << endl;
	//cout << "Sum: " << Sum(arr) << endl;
	//cout << "Avg: " << Avg(arr) << endl;

	//Reverse(&arr);
	//Reverse2(&arr);

	//LeftShift(&arr);
	//LeftRotate(&arr);

	//RightShift(&arr);
	//RightRotate(&arr);

	//InsertSort(&arr, -1);

	//cout << isSorted(arr) << endl;

	//ReArrange(&arr);

	//arr3 = Merge(&arr1, &arr2);
	//Display(*arr3);

	struct Array arr1 = { {2,6,10,15,25}, 10, 5 };
	struct Array arr2 = { {3,6,7,15,20}, 10, 5 };
	struct Array* arr3;

	//arr3 = Union(&arr1, &arr2);
	//Display(*arr3);

	//arr3 = Intersection(&arr1, &arr2);
	//Display(*arr3);

	arr3 = Difference(&arr1, &arr2);
	Display(*arr3);

	//Display(arr);

	return 0;
}
