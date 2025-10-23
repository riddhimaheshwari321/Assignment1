#include <stdio.h>
#include <math.h>
#include "mylib.h"
#include "arraylib.h"

int main() {
    int choice;

    do {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Number Functions (Armstrong / Adams / Prime Palindrome)\n");
        printf("2. Array Functions (Max / Min / Reverse / Sort / Search)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int subchoice, num;
            do {
                printf("\n----- NUMBER FUNCTIONS -----\n");
                printf("1. Check Armstrong Number\n");
                printf("2. Check Adams Number\n");
                printf("3. Check Prime Palindrome Number\n");
                printf("4. Back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &subchoice);

                if (subchoice == 4) break;

                printf("Enter a number: ");
                scanf("%d", &num);

                switch (subchoice) {
                    case 1:
                        if (isArmstrong(num))
                            printf("%d is an Armstrong number.\n", num);
                        else
                            printf("%d is NOT an Armstrong number.\n", num);
                        break;

                    case 2:
                        if (isAdams(num))
                            printf("%d is an Adams number.\n", num);
                        else
                            printf("%d is NOT an Adams number.\n", num);
                        break;

                    case 3:
                        if (isPrimePalindrome(num))
                            printf("%d is a Prime Palindrome number.\n", num);
                        else
                            printf("%d is NOT a Prime Palindrome number.\n", num);
                        break;

                    default:
                        printf("Invalid choice!\n");
                }
            } while (subchoice != 4);
        }

        else if (choice == 2) {
            int n, value;
            printf("\n----- ARRAY FUNCTIONS -----\n");
            printf("Enter the number of elements: ");
            scanf("%d", &n);

            int a[n];
            printf("Enter %d elements: ", n);
            for (int i = 0; i < n; i++)
                scanf("%d", &a[i]);

            printf("\nOriginal array: ");
            displayArray(a, n);

            printf("Max at index %d\n", findMaxIndex(a, n));
            printf("Min at index %d\n", findMinIndex(a, n));
            printf("Average = %.2f\n", findAverage(a, n));

            reverseArray(a, n);
            printf("Reversed array: ");
            displayArray(a, n);

            sortArray(a, n);
            printf("Sorted array: ");
            displayArray(a, n);

            printf("\nEnter a value to search: ");
            scanf("%d", &value);

            int pos = linearSearch(a, n, value);
            if (pos != -1)
                printf("%d found at index %d\n", value, pos);
            else
                printf("%d not found in array\n", value);
        }

        else if (choice != 3) {
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 3);

    printf("\nExiting program. bye!\n");
    return 0;
}
