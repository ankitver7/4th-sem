#include<stdio.h>
#include<stdlib.h>
struct Item {
    int value;
    int weight;
};
int compare(const void *a, const void *b) {
    double ratioA = ((double)((struct Item *)b)->value) / ((struct Item *)b)->weight;
    double ratioB = ((double)((struct Item *)a)->value) / ((struct Item *)a)->weight;
    
    if (ratioA > ratioB) return 1;
    else if (ratioA < ratioB) return -1;
    else return 0;
}
int discreteknapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(items[0]), compare);

    int totalvalue = 0;
    int remainingcapacity = capacity;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingcapacity) {
            totalvalue += items[i].value;
            remainingcapacity -= items[i].weight;
        } else {
            double fraction = (double) remainingcapacity / items[i].weight;
            totalvalue += items[i].value * fraction;
            break;
        }
    }
    return totalvalue;
}
double continuousknapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(items[0]), compare);

    double totalvalue = 0.0;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            totalvalue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalvalue += items[i].value * ((double) capacity / items[i].weight);
            break;
        }
    }
    return totalvalue;
}
int main() {
    int n, capacity;
    printf("Enter the number of items:");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &items[i].value, &items[i].weight);
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    int maxvalue = discreteknapsack(items, n, capacity);
    printf("Maximum value in discrete knapsack: %d\n", maxvalue);

    double maxvaluecont = continuousknapsack(items, n, capacity);
    printf("Maximum value in continuous knapsack: %.2f\n", maxvaluecont);

    return 0;
}
