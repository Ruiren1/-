#pragma warning(disable:4996)
#include <stdio.h>

int main() {
    int x0, a, b, m;
    scanf("%d %d %d %d", &x0, &a, &b, &m);

    int nums[100];
    nums[0] = x0;
    for (int i = 1; i < 100; i++) {
        nums[i] = (a * nums[i - 1] + b) % m;
    }

    int count[100] = { 0 };
    for (int i = 0; i < 100; i++) {
        count[nums[i]]++;
    }

    int max_num = 0;
    int max_count = 0;
    for (int i = 0; i < 100; i++) {
        if (count[i] > max_count) {
            max_num = i;
            max_count = count[i];
        }
    }

    printf("%d\n", max_num);

    return 0;
}