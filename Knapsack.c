#include <stdio.h>
struct Item {
    int weight;
    int profit;
};
void sortByProfit(struct Item items[], int n) {
    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-1-i; j++)
            if (items[j].profit < items[j+1].profit) {
                struct Item t = items[j];
                items[j] = items[j+1];
                items[j+1] = t;
            }
}
void sortByWeight(struct Item items[], int n) {
    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-1-i; j++)
            if (items[j].weight > items[j+1].weight) {
                struct Item t = items[j];
                items[j] = items[j+1];
                items[j+1] = t;
            }
}
void sortByRatio(struct Item items[], int n) {
    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-1-i; j++) {
            float r1 = (float)items[j].profit / items[j].weight;
            float r2 = (float)items[j+1].profit / items[j+1].weight;
            if (r1 < r2) {
                struct Item t = items[j];
                items[j] = items[j+1];
                items[j+1] = t;
            }
        }

float knapsack(struct Item items[], int n, int M) {
    float profit = 0;
    int cap = M;
    for (int i=0; i<n && cap>0; i++) {
        if (items[i].weight <= cap) {
            profit += items[i].profit;
            cap -= items[i].weight;
        } else {
            profit += items[i].profit * (float)cap / items[i].weight;
            break;
        }
    }
    return profit;
}
int main() {
    int n = 4;
    int M = 15;

    struct Item items[] = {
        {2, 10},
        {3, 5},
        {5, 15},
        {7, 7}
    };
    struct Item byProfit[4], byWeight[4], byRatio[4];
    for (int i=0; i<n; i++) {
        byProfit[i] = items[i];
        byWeight[i] = items[i];
        byRatio[i]  = items[i];
    }
    sortByProfit(byProfit, n);
    sortByWeight(byWeight, n);
    sortByRatio(byRatio, n);
    float profit1 = knapsack(byProfit, n, M);
    float profit2 = knapsack(byWeight, n, M);
    float profit3 = knapsack(byRatio, n, M);
    printf("profit (sortByWeight) : %.2f\n", profit2);
    printf("profit (sortByProfit) :%.2f\n", profit1);
    printf("profit (sortByRatio) :%.2f\n", profit3);
    return 0;
}
