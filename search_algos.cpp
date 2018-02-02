#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

void populate(int* list, int size);
void print(int* list, int size);
int linearSearchComps(int* list, int size, int target);
void RandLinear(int search, int*list, int& size);
int binarySearchComps(int* list, int min, int max, int target, int& comps);
void doBinarysearch(int search, int* list, int& size);

int main()
{	
int size = 0;
cout << "Enter a +ve int number: ";
cin >> size;
int* list = new int[size];
populate(list, size);
print(list, size);
RandLinear(100, list, size);
doBinarysearch(100, list, size);
return 0;
}

void populate(int* list, int size)
{	int i = 0;
	int k = 0;
	srand(time(0));

	for(int m = 0; i < size; m++)
	{
		k = rand() % 10 + 1;

		for(int j = 0; j < k; j++)
		{
			list[i++] = m;
		}
	}
}

void print(int* list, int size)
{   cout<<"the array is :"<<endl;
	for(int i = 0; i < size; i++)
	{	cout << list[i] << ' ';
	}
	cout << endl;
}

int linearSearchComps(int* list, int size, int target)
{
	int comparisons = 0;
	for(int i = 0; i < size; i++)
	{	comparisons++;
		if(list[i] == target)
		{
			return comparisons;
		}
	}
	return size;
}

void RandLinear(int search, int* list, int& size)
{
	int comps = 0;
	int randTarget = 0;
   float avg1 = 0.0;
   
	srand(time(0));

	for(int i = 1; i <= search; i++)
	{
		randTarget = list[rand() % (size)];
		comps = linearSearchComps(list, size, randTarget);
		avg1 =((avg1 + comps) / i);
	}
	cout<< "the average of linear comaprisons are :" << avg1 <<endl;
}

int binarySearchComps(int* list, int min, int max, int target, int& comps)
{

	if(min > max)
	{
		return comps;
	}

	int mid = (max + min) / 2;

	comps++;

	if(list[mid] > target)
	{
		return binarySearchComps(list, min, mid - 1, target, comps);
	}
	else if(list[mid] < target)
	{
		return binarySearchComps(list, mid+1, max, target, comps);
	}
	else
	{
		return comps;
	}
}

void doBinarysearch(int search, int* list, int& size)
{
	int comps = 0;
	int randTarget = 0;
	srand(time(0));
float avg = 0.0;
	for(int i = 1; i <= search; i++)
	{
		comps = 0;
		randTarget = list[rand() % (size)];
		comps = binarySearchComps(list, 0, size - 1, randTarget, comps);
		avg =( (avg + comps) / i);
	}
	cout << "the average of binary comparisons are : " << avg;
}