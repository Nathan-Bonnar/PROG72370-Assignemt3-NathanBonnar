//PROG72370 - Nathan Bonnar - Data Structures - Assignment 3
#include"bubble.h"
void bubblesort(int* sortingarray)
{
	for (int i = 0; i < SIZE; i++)
	{
		int checkingnumber = sortingarray[i];
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE - i - 1; j++)
			{
				if (sortingarray[j] < sortingarray[j + 1])
				{
					swap(sortingarray, j, j + 1);
				}
			}
		}
	}
}
int addnumtoarray(int* array)
{
	int randomnumber = rand() % (25 + 1);
	int randomspot = (rand() % (SIZE - 1)) + 1;
	array[randomspot] = randomnumber;
	return randomnumber;
}
