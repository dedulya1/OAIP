#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include"Header.h"

int main()
{
	int task;
	while (1) 
	{
		printf("Input task number (4 to stop): ");
		while (scanf_s("%d", &task) != 1 || getchar() != '\n' || task < 1 || task>4)
		{
			printf("Incorrect value. Try again: ");
			rewind(stdin);
		}
		rewind(stdin);
		if (task == 1)
		{
			menu1();
			system("pause");
			system("cls");
			continue;
		}
		else if (task == 2)
		{
			menu2();
			system("pause");
			system("cls");
			continue;

		}
		else if (task == 3)
		{
			menu3();
			system("pause");
			system("cls");
			continue;
			
		}
		else if (task == 4)
		{
			
			break;
		}
	}
	return 0;
}

