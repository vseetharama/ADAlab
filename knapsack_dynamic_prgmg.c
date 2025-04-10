#include <stdio.h>
#define MAX_ITEMS 10
int knapSack(int W, int wt[], int val[], int n);
int max(int a, int b);

int main() {
    int i;
    int n; // No of items
    int W; // Capacity of the knapsack
    int wt[MAX_ITEMS]; // Weights of 'n' items
    int val[MAX_ITEMS]; // Values of 'n' items

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of the items:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter the values of the items:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("The maximum value in knapsack of capacity %d is: %d\n", W, knapSack(W, wt, val, n));

    return 0;
}

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n) {
    int i, j;
    int v[MAX_ITEMS+1][W+1];

    // Build table v[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                v[i][j] = 0;
            } else if (j - wt[i] < 0) {
                v[i][j] = v[i-1][j];
            } else {
                v[i][j] = max(v[i-1][j], val[i] + v[i-1][j - wt[i]]);
            }
        }
    }

    return v[n][W];
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
