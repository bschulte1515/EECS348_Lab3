/*
Name: Benjamin Schulte
ID #: 3051946
Code Artifact: EECS 348 Lab 3 Problem 1
Date Created: 2/9/23
Last Modified: 2/11/23
Purpose: To print a sales report given 12-months of sales from a certain year
*/

#include <stdio.h>
#include <string.h>

// Used in bubble sorting to swap two elements in the array of profits from each month
void profitSwap(int a, int b, float arr[])
{
  float temp = arr[a]; 
  arr[a] = arr[b];
  arr[b] = temp;
}  

// Called with profitSwap() so that the months stay attached to the correct profits when sorted using bubble sorting
void monthSwap(int a, int b, char arr[][15])
{
  char temp[15];
  strcpy(temp, arr[a]);
  strcpy(arr[a], arr[b]);
  strcpy(arr[b], temp);
}

int main()
{
  // Input file with monthly profits from user and create an array for each of the 12 months
  FILE *input_file = fopen("sample_input.txt", "r");
  float number, profitArray [12];
  char months[12][15] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

  // Test if file exits
  if (input_file == NULL)
  {
    printf("Couldn't find file.\n");
    return 1;
  }

  for (int i = 0; i < 12; i++)
  {
    fscanf(input_file, "%f", &number); // Scanning each line and adding it to the array of profits
    profitArray[i] = number;
  }

  float min = 100000000000, max = 0, avg = 0;
  int min_i, max_i; // Position of the min and max sales within the profit array

  printf("Monthly sales report for 2022\nMonth     Sales\n");
  for (int i = 0; i < 12; i++) // Each iteration we will check for min and max, add it to avg to keep a total, and print in order
   { 
    if (profitArray[i] < min) // Keep checking for the smallest profit --> make it the new min if it is smaller than min
    {
      min = profitArray[i];
      min_i = i;
    }
    if (profitArray[i] > max) // Keep checking for the biggest profit --> make it the new max if it is bigger than max 
    {
      max = profitArray[i];
      max_i = i;
    }
    avg += profitArray[i];
    printf("%-10s$%.2f\n", months[i], profitArray[i]);
  }

  avg /= 12; // avg is currently the total yearly profit, so just divide by # of months (12) to find correct average
  printf("\nSales summary:\n");
  printf("Minimum sales:  $%.2f  (%s)\n", min, months[min_i]);
  printf("Maximum sales:  $%.2f  (%s)\n", max, months[max_i]);
  printf("Average sales:  $%.2f\n", avg);

  printf("\nSix-Month Moving Average Report:\n");
  for (int i = 0; i < 7; i++) // Works the same as avg before, but finds 6 averages of 6-month lengths of time 
  {
    avg = 0;
    for (int x = i; x < (i + 6); x++)
    {
      avg += profitArray[x];
    }
    avg /= 6;
    printf("%-10s- %-10s$%.2f\n", months[i], months[i + 5], avg);
  }

  // Bubble sorting algorithm  
  for (int i = 0; i < 11; i++)
  {
    for (int j = 0; j < (11 - i); j++)
    {
      if (profitArray[j] < profitArray[j + 1])
      {
        profitSwap(j, (j + 1), profitArray);
        monthSwap(j, (j + 1), months);
      }
    }
  }

  // After sorting using bubble sort, print the array
  printf("\nSales Report (Highest to Lowest):\nMonth     Sales\n");
  for (int i = 0; i < 12; i++)
  {
    printf("%-10s$%.2f\n", months[i], profitArray[i]);
  }

  fclose(input_file);
  return 0;
}