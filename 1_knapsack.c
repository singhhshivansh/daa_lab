#include <stdio.h>

int main() {
    int n, i, j;
    float v[20], w[20], W, total = 0, t;

    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter value and weight of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &v[i], &w[i]);
    }
    printf("Enter knapsack capacity: ");
    scanf("%f", &W);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (v[j] / w[j] > v[i] / w[i]) {
                t = v[i]; v[i] = v[j]; v[j] = t;
                t = w[i]; w[i] = w[j]; w[j] = t;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (w[i] <= W) {
            W = W - w[i];
            total = total + v[i];
        } else {
            total = total + v[i] * (W / w[i]);
            break;
        }
    }

    printf("Maximum value = %.2f\n", total);
    return 0;
}
