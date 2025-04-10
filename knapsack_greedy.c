#include <stdio.h>
#define MAX_ITEMS 100

double computeMaxValue(double W, double weight[], double value[], double ratio[], int nItems);
int getNextItem(double weight[], double value[], double ratio[], int nItems);

int main() {
    int nItems;
    double W; /* capacity of the knapsack */
    double weight[MAX_ITEMS]; // Weights of 'n' items
    double value[MAX_ITEMS]; // Values of 'n' items
    double ratio[MAX_ITEMS]; // ratio or density of 'n' items

    printf("Enter the number of items: ");
    scanf("%d", &nItems);

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < nItems; i++) {
        scanf("%lf", &weight[i]);
    }

    printf("Enter the values/profits of the items:\n");
    for (int i = 0; i < nItems; i++) {
        scanf("%lf", &value[i]);
    }

    for (int i = 0; i < nItems; i++) {
        ratio[i] = value[i] / weight[i];
    }

    printf("Enter the Capacity of the knapsack: ");
    scanf("%lf", &W);

    printf("\nThe maximum value in a knapsack of capacity %.2f is: %.2f\n", W, computeMaxValue(W, weight, value, ratio, nItems));

    return 0;
}

double computeMaxValue(double W, double weight[], double value[], double ratio[], int nItems) {
    double cW = 0; // current weight
    double cV = 0; // current value

    printf("\nItems considered are: ");
    while (cW < W) {
        int item = getNextItem(weight, value, ratio, nItems); // get next highest ratio
        if (item == -1) {
            // No items left
            break;
        }

        printf("%d ", item + 1);
        if (cW + weight[item] <= W) {
            cW += weight[item];
            cV += value[item];
            // mark as used for the getNext() (ratio) function
            ratio[item] = 0;
        } else {
            cV += (ratio[item] * (W - cW)); // Break the value and add
            cW += (W - cW);
            break; // the knapsack is full
        }
    }
    return cV;
}

// Method to get the next highest ratio
int getNextItem(double weight[], double value[], double ratio[], int nItems) {
    double highest = 0;
    int index = -1;
    for (int i = 0; i < nItems; i++) {
        if (ratio[i] > highest) {
            highest = ratio[i];
            index = i;
        }
    }
    return index;
}
