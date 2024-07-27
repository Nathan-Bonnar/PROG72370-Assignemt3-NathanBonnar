#pragma once
//PROG72370 - Nathan Bonnar - Data Structures - Assignment 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#define SIZE 500
void swap(int* heap, int locationone, int locationtwo);
bool addnumtoheap(int* heap, int data);
void heapify(int* heap, int* sorted);
void assess(int* heap, int base);