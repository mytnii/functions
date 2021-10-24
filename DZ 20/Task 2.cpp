#include<iostream>
using namespace std;

void comArray1(int array1[], const int num)
{
	for (int i = 0; i < num; ++i)
	{
		array1[i] = rand() % 20 - 10;
	}
}

void printArray1(int array1[], const int num)
{
	for (int i = 0; i < num; ++i)
	{
		cout << array1[i] << " ";
	}

	cout << endl;
}

void comArray2(int array2[], const int num2)
{
	for (int i = 0; i < num2; ++i)
	{
		array2[i] = rand() % 20 - 10;
	}
}

void printArray2(int array2[], const int num2)
{
	for (int i = 0; i < num2; ++i)
	{
		cout << array2[i] << " ";
	}

	cout << endl;
}

int counter(int array1[], int array2[], const int num, const int num2)
{
	int cou = 0;

	for (int i = 0; i < num; ++i)
	{

		bool a = true;

		for (int j = 0; j < num2; ++j)
		{
			if (array1[i] == array2[j])
			{
				a = false;
			}
		}

		if (a == true && cou != 0)
		{
			for (int j = 0; j < cou; ++j)
			{
				if (array1[i] == array1[j])
				{
					a = false;
				}
			}
		}

		if (a == true)
		{
			++cou;
		}
	}

	for (int i = 0; i < num2; ++i)
	{

		bool a = true;

		for (int j = 0; j < num; ++j)
		{
			if (array2[i] == array1[j])
			{
				a = false;
			}
		}

		
			for (int j = i + 1; j < cou; ++j)
			{
				if (array2[i] == array2[j])
				{
					a = false;
				}
			}

		if (a == true)
		{
			++cou;
		}
	}

	return cou;
}

void comArray3(int array1[], int array2[],int array3[], const int num, const int num2)
{
	int cou = 0;

	for (int i = 0; i < num; ++i)
	{

		bool a = true;

		for (int j = 0; j < num2; ++j)
		{
			if (array1[i] == array2[j])
			{
				a = false;
			}
		}

		if (a == true && cou != 0)
		{
			for (int j = 0; j < cou; ++j)
			{
				if (array1[i] == array1[j])
				{
					a = false;
				}
			}
		}

		if (a == true)
		{
			array3[cou] = array1[i];

			++cou;
		}
	}

	for (int i = 0; i < num2; ++i)
	{
		bool a = true;

		for (int j = 0; j < num; ++j)
		{
			if (array2[i] == array1[j])
			{
				a = false;
			}
		}
		
		
			for (int j = i + 1; j < cou ; ++j)
			{
				if (array2[i] == array2[j])
				{
					a = false;
				}
			}

		if (a == true)
		{
			array3[cou] = array2[i];

			++cou;
		}
	}
}

void printArray3(int array3[], const int num3)
{
	for (int i = 0; i < num3; ++i)
	{
		cout << array3[i] << " ";
	}

	cout << endl;
}

int main()
{
	srand(time(NULL));

	int num;

	cout << "Enter number: ";
	cin >> num;

	int* array1 = new int[num];

	int num2;

	cout << "Enter number: ";
	cin >> num2;

	int* array2 = new int[num2];

	comArray1(array1, num);

	printArray1(array1, num);

	comArray2(array2, num2);

	printArray2(array2, num2);

	int num3 = counter(array1, array2, num, num2);

	cout << num3 << endl;

	int* array3 = new int[num3];

	comArray3(array1, array2, array3, num, num2);

	printArray3(array3, num3);

	delete[] array3;

	delete[] array2;

	delete[] array1;
	return 0;
}