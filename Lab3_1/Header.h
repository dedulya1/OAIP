#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

void randomArray(int* arr, int n);
void yourArray(int* arr, int n);
void printArray(int arr[1000], int n);
int minArray(int arr[1000], int n);
int findIndex(int arr[1000], int n, int value);
void deleteArray(int* arr, int n);
void swap(int* xp, int* yp);
void bubbleSortHigh(int* arr, int n);
void bubbleSortLow(int* arr, int n);
void menu1();
void menu2();
void menu3();

void menu3()
{
	srand(time(NULL));
	int choose, n1, n2, arr1[100], arr2[100];

	printf("Input next number for the first array:\n1 - Your numbers.\n2 - Random input.\n");
	printf("Your answer: ");
	while (scanf_s("%d", &choose) != 1 || getchar() != '\n' || choose < 1 || choose >2)
	{
		printf("Incorrect value. Try again: ");
		rewind(stdin);
	}

	rewind(stdin);


	printf("Input amount of elements: ");
	while (scanf_s("%d", &n1) != 1 || getchar() != '\n' || n1 < 0)
	{
		printf("Incorrect value. Try again: ");
		rewind(stdin);
	}
	rewind(stdin);

	if (choose == 1)
	{
		yourArray(arr1, n1);
		bubbleSortHigh(arr1, n1);
	}
	else if (choose == 2)
	{
		randomArray(arr1, n1);
		bubbleSortHigh(arr1, n1);
	}

	printArray(arr1, n1);

	printf("\n\nInput next number for the second array:\n1 - Your numbers.\n2 - Random input.\n");
	printf("Your answer: ");
	while (scanf_s("%d", &choose) != 1 || getchar() != '\n' || choose < 1 || choose >2)
	{
		printf("Incorrect value. Try again: ");
		rewind(stdin);
	}
	void randomArray(arr, n);
	rewind(stdin);


	printf("Input amount of elements: ");
	while (scanf_s("%d", &n2) != 1 || getchar() != '\n' || n2 < 0)
	{
		printf("Incorrect value. Try again: ");
		rewind(stdin);
	}
	rewind(stdin);

	if (choose == 1)
	{
		yourArray(arr2, n2);
		bubbleSortLow(arr2, n2);

	}
	else if (choose == 2)
	{
		randomArray(arr2, n2);
		bubbleSortLow(arr2, n2);
	}
	printArray(arr2, n2);

	int arr3[200];
	for (int i = 0; i < n1 + n2; i++)
	{
		if (i - n1 < 0)
		{
			arr3[i] = arr1[i];
		}
		else
		{
			arr3[i] = arr2[i - n1];
		}
	}
	for (int i = 0; i < n1 + n2 - 1; i++)
	{
		for (int j = 0; j < (n1 + n2) - i - 1; j++)
		{
			if (arr3[j] < arr3[j + 1])
			{
				swap(&arr3[j], &arr3[j + 1]);
			}
		}
	}
	printArray(arr3, n1 + n2);
}





void menu2()
{

	int sum = 0;
	srand(time(NULL));
	int choose, n, arr[1000];

	printf("Input next number:\n1 - Your numbers.\n2 - Random input.\n");
	printf("Your answer: ");
	while (scanf_s("%d", &choose) != 1 || getchar() != '\n' || choose < 1 || choose >2)
	{
		printf("Incorrect value. Try again: ");
		rewind(stdin);
	}
	void randomArray(arr, n);
	rewind(stdin);


	printf("Input amount of elements: ");
	while (scanf_s("%d", &n) != 1 || getchar() != '\n')
	{
		printf("Incorrect value. Try again: ");
		rewind(stdin);
	}
	rewind(stdin);

	if (choose == 1)
	{
		yourArray(arr, n);
	}
	else if (choose == 2)
	{
		randomArray(arr, n);
	}
	deleteArray(arr, n);

	printArray(arr, n);

}


void menu1()
{

	int index1, index2, sum = 0;
	srand(time(NULL));
	int choose, n, arr[1000];

	printf("Input next number:\n1 - Your numbers.\n2 - Random input.\n");
	printf("Your answer: ");
	while (scanf_s("%d", &choose) != 1 || getchar() != '\n' || choose < 1 || choose >2)
	{
		printf("Incorrect value. Try again: ");
		rewind(stdin);
	}
	void randomArray(arr, n);
	rewind(stdin);


	printf("Input amount of elements: ");
	while (scanf_s("%d", &n) != 1 || getchar() != '\n' || n < 0)
	{
		printf("Incorrect value. Try again: ");
		rewind(stdin);
	}
	rewind(stdin);

	if (choose == 1)
		yourArray(arr, n);
	else if (choose == 2)
		randomArray(arr, n);


	for (int i = 0; i < n; i++)
	{
		if (arr[i] >= 0)
		{
			index1 = findIndex(arr, n, arr[i]);
			break;
		}
	}
	for (int i = n; i >= 0; --i)
	{
		if (arr[i] >= 0)
		{
			index2 = findIndex(arr, n, arr[i]);
			break;
		}
	}

	for (int i = index1; i <= index2; i++)
	{
		sum += arr[i];
	}

	printf("Minimal element is %d.\n", minArray(arr, n));
	printf("Sum = %d\n", sum);
	return 0;
}
void randomArray(int* arr, int n)
{
	for (int j = 0; j < n; j++)
	{
		arr[j] = rand();
		printf("%d elenment:%d\n", j + 1, arr[j]);

	}
	return 1;
}
void yourArray(int* arr, int n)
{
	printf("Input your values: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d element: ", i + 1);
		if (scanf_s("%d", &arr[i]) != 1 || getchar() != '\n' || arr[i] < 0)
		{
			printf("Error. Try again.\n");
			i--;
			rewind(stdin);
		}
		else
			continue;
	}


}

void printArray(int arr[1000], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int minArray(int arr[1000], int n)
{
	int min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (min > arr[i])
			min = arr[i];
	}
	return min;
}

int findIndex(int arr[1000], int n, int value)
{
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == value)
		{
			index = i;
			break;
		}
	}
	return index;

}

void deleteArray(int* arr, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] % 2 == 0)
		{
			for (int j = n - 1; j >= i + 1; j--)
			{
				arr[j] = 0;
			}
			break;
		}


	}
}

void bubbleSortLow(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
void bubbleSortHigh(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}