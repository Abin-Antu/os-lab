#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MIN 10

int ref[MAX], count, frame[MIN], n;

void input() {
    int temp;
    count = 0;
    printf("\nEnter the number of page frames: ");
    scanf("%d", &n);
    printf("Enter the reference string (-1 to end): ");
    while (scanf("%d", &temp) && temp != -1) {
        ref[count++] = temp;
    }
}

void LRU() {
    int stack[MIN], top = 0, fault = 0;

    // Clear screen (optional)
    // system("cls"); // Windows
    // system("clear"); // Linux

    for (int i = 0; i < count; i++) {
        int found = 0;
        for (int j = 0; j < top; j++) {
            if (stack[j] == ref[i]) {
                found = 1;
                // Move the recently used page to the end (most recently used)
                int temp = stack[j];
                for (int k = j; k < top - 1; k++) {
                    stack[k] = stack[k + 1];
                }
                stack[top - 1] = temp;
                break;
            }
        }

        if (!found) {
            if (top < n) {
                stack[top++] = ref[i]; // Add new page
            } else {
                // Replace the least recently used page (first element)
                for (int k = 0; k < n - 1; k++) {
                    stack[k] = stack[k + 1];
                }
                stack[n - 1] = ref[i];
            }
            fault++;
        }

        // Display stack status after each insertion
        printf("\nAfter inserting %d, stack status: ", ref[i]);
        for (int j = 0; j < top; j++) {
            printf("%d ", stack[j]);
        }
    }

    printf("\n\nTotal page faults: %d", fault);
    printf("\nPress any key to continue...");
    getchar(); // Wait for key press
    getchar();
}

int main() {
    int choice;

    while (1) {
        printf("\n----- MENU -----");
        printf("\n1. Input");
        printf("\n2. LRU (Least Recently Used) Algorithm");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input();
                break;
            case 2:
                LRU();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
    }
    return 0;
}
