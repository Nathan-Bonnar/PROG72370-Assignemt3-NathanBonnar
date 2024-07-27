//PROG72370 - Nathan Bonnar - Data Structures - Assignment 3
#include"heap.h"
void swap(int* heap, int locationone, int locationtwo)
{
	int temp = heap[locationone];
	heap[locationone] = heap[locationtwo];
	heap[locationtwo] = temp;
}
bool addnumtoheap(int* heap, int data)
{
	for (int i = 1; i < SIZE; i++)
	{
		int base = i / 2;
		if (base == 0)
		{
			base = 1;
		}
		int current = i;
		if (heap[1] == 0)
		{
			heap[1] = data;
			return true;
		}
		else
		{
			if (heap[current] == 0 && heap[base] > data)
			{
				heap[current] = data;
				return;
			}
			if (data > heap[base] && heap[current] == 0)
			{
				while (base >= 1)
				{
					if (data > heap[base])
					{
						heap[current] = data;
						swap(heap, current, base);
					}
					current = base;
					base = current / 2;
				}
				return;
			}
		}
	}
}
void heapify(int* heap, int* sorted)
{
	for (int i = 1; i < SIZE; i++)
	{
		//set the temp number to the root of the heap
		int temp = heap[1];
		if (sorted[i - 1] >= temp || sorted[i - 1] == 0)
		{
			sorted[i] = temp;
		}
		int left = 1 + 1;
		int right = 1 + 2;
		//if the left side is the larger out of the two numbers below the base move that one to the new root
		// the loop will then continue moving throughout the heap and continue moving through the heap assessing to make sure that the numbers will fit;
		if (heap[left] > heap[right])
		{
			int base = left;
			assess(heap, base);

		}
		//if the right side is larger then the left then scope into the right side and move through to find the new root
		else if (heap[right] > heap[left])
		{
			int base = right;
			assess(heap, right);
		}
		//if the numbers are equal just pick a side and go down it
		else if (heap[right] == heap[left])
		{
			int base = right;
			assess(heap, base);
		}
	}
	return;
}
void assess(int* heap, int base)
{
	//make the loop run through all of the side you want to assess
	while (base < SIZE)
	{
		//keep track of the base of the base you are assessing
		//the leftside of the path you are taking and the right side
		int baseofbase = base / 2;
		int loopleft = base * 2;
		int loopright = (base * 2) + 1;
		//if the left or right side goes larger then the tree we know we have reached the end 
		if (loopleft > SIZE || loopright > SIZE)
		{
			if (loopleft > loopright)
			{
				break;
			}
			else
			{
				break;
			}
		}
		//if the begining of the heap is smaller then the heap location the the left or right then swap them
		if (heap[1] < heap[loopleft])
		{
			swap(heap, 1, loopleft);
		}
		if (heap[1] < heap[loopright])
		{
			swap(heap, 1, loopright);
		}
		//if the base of the section you are assessing is less then the the left side then swap them
		if (heap[base] < heap[loopleft] && heap[loopleft] >= heap[loopright])
		{
			swap(heap, base, loopleft);
			base = loopleft;
		}
		//if the base of the section you are assessing is less then the the right side then swap them
		else if (heap[base] < heap[loopright] && heap[loopright] >= heap[loopleft])
		{
			swap(heap, base, loopright);
			base = loopright;
		}
		//if the base is 0 then we know that area has been assessed already
		else if (heap[base] == 0)
		{
			break;
		}
		//if none of those condition are true then move the base up and then swap the current base for the larger number
		else
		{
			heap[baseofbase] = heap[base];
			if (heap[loopleft] > heap[loopright])
			{
				heap[base] = heap[loopleft];
				heap[loopleft] = 0;
				base = loopleft;
			}
			else if (heap[loopleft] == heap[loopright])
			{
				heap[base] = heap[loopleft];
				heap[loopleft] = 0;
				base = loopleft;
			}
			else
			{
				heap[base] = heap[loopright];
				heap[loopright] = 0;
				base = loopright;
			}
		}
	}
}