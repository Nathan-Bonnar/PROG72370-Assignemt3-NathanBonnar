//PROG72370 - Nathan Bonnar - Data Structures - Assignment 3
#include"bubble.h"
int main()
{
	srand(time(NULL));
	//starting bubble sort
	int bubblearray[SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++)
	{
		bubblearray[i] = (rand() % (1 - 1000 + 1)) + 1000;
	}
	printf("STARTING TIMER for BUBBLE\n");
	clock_t bubblestarttime = clock();
	bubblesort(bubblearray);
	clock_t bubbleendtime = clock();
	double bubblesorttime = (double)(bubbleendtime - bubblestarttime) / CLOCKS_PER_SEC;
	printf("it took %lf to bubble sort the array\n", bubblesorttime);
	
	//starting heap sort
	int heap[SIZE] = { 0 };
	int sorted[SIZE] = { 0 } ;
	for (int i = 1; i < SIZE; i++)
	{
		addnumtoheap(heap, (rand() % (10 - 1000 + 1)) + 1000);
	}
	printf("STARTING TIMER for HEAP\n");
	clock_t heapstarttime = clock();
	heapify(heap, sorted);
	clock_t heapendtime = clock();
	double heapsorttime = (double)(heapendtime - heapstarttime) / CLOCKS_PER_SEC;
	printf("it took %lf to heap sort the array\n", heapsorttime);
	printf("\n\n\n\n\n");
	printf("heap sort \n");
	for (int i = 1; i < SIZE; i++)
	{
	printf("location at array %d: %d\n",i, sorted[i]);
	}
	printf("bubblesort\n");
	for (int i = 0; i < SIZE; i++)
	{
	printf("array at location %d: %d\n", i, bubblearray[i]);
	}
	return 0;
}
