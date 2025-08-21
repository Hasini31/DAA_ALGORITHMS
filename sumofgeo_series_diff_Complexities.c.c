#include <stdio.h>
#include <math.h>

double formula_sum(double a, double r, int n) {
    if (r == 1) return a * n;
    return a * (pow(r, n) - 1) / (r - 1);
}

double iterative_sum(double a, double r, int n) {
    double sum = 0, term = a;
    for (int i = 0; i < n; i++) {
        sum += term;
        term *= r;
    }
    return sum;
}

double log_sum(double a, double r, int n) {
    if (n == 0) return 0;
    if (n % 2 == 0) return log_sum(a, r, n/2) * (1 + pow(r, n/2));
    else return a + r * log_sum(a, r, n-1);
}

int main() {
    double a, r;
    int n;
    scanf("%lf %lf %d", &a, &r, &n);

    double f = formula_sum(a, r, n);
    double i = iterative_sum(a, r, n);
    double l = log_sum(a, r, n);

    printf("Formula method sum: %.2lf , Time Complexity: O(1)\n", f);
    printf("Iterative method sum: %.2lf , Time Complexity: O(n)\n", i);
    printf("Logarithmic method sum: %.2lf , Time Complexity: O(log n)\n", l);

    return 0;
}
