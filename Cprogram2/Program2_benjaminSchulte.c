/*
Name: Benjamin Schulte
ID #: 3051946
Code Artifact: EECS 348 Lab 3 Problem 1
Date Created: 2/9/23
Last Modified: 2/12/23
Purpose: To return all possible combinations for ways of scoring given a point amount of an NFL game
*/

#include <stdio.h>
#include <math.h>

int main() {
  int score; // Initialized at 2 so the while loop will run, this will instantly get changed so value does not matter
  // int count = 0; *1
  while (1)
  {

    printf("Enter a score for an NFL game (entering 0 or 1 will stop the program): \n");
    fflush(stdout);
    scanf("%d", &score); // Taking user input score until score <= 2

    if (score >= 2)
    {
      printf("Possible combinations of scoring plays: \n");
      /* Checks all possibilities of adding the possible points to be made during a football game and if they add
      up to the score requested, print it. Each variable should only go up to the maximum times the number by itself can be
      added without exceeding the score value, for slight optimization (hence using floor(score/points)). I don't know if it
      will work with all compilers, but works with gcc.*/
      for (int i = 0; i < (floor(score/2) + 1); i ++) {
        for (int j = 0; j < (floor(score/3) + 1); j ++) {
          for (int k = 0; k < (floor(score/6) + 1); k ++) {
            for (int l = 0; l < (floor(score/7) + 1); l ++) {
              for (int m = 0; m < (floor(score/8) + 1); m ++) {
                if (((i*2) + (j*3) + (k*6) + (l*7) + (m*8)) == score) {
                  printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", m, l, k, j, i);
                  // count ++; *1
                }
              }
            }
          }
        }
      }
      putchar('\n');
      // printf("\nNumber of possibilities found: %d\n", count); *1
      // *1 Just a cool metric I was looking at
    }
    else
    {
      printf("0 or 1 entered. Program aborted.\n");
      return 1;
    }
  }
  return 0;
}

