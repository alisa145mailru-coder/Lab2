#include <stdio.h>

int sum_del(int a, int i) {
    if (i > a / 2) return 0;
    if (a % i == 0) return i + sum_del(a, i + 1);
    return sum_del(a, i + 1);
}

int main() {
    int N, M, flag = 0;
    if (scanf("%d %d", &N, &M) != 2) {
        printf("Ошибка ввода\n");
        return 1;
    }
    if (N <= 0 || M <= 0 || N > M) {
        printf("Некорректные данные\n");
        return 1;
    }
    for (int i = N; i <= M; i++) {
        int s = sum_del(i, 1);
        if (s != i && sum_del(s, 1) == i && i < s && s >= N && s <= M) {
            printf("%d и %d\n", i, s);
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("Таких чисел нет\n");
    }
    return 0;
}
