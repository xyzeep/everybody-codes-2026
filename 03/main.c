#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int part1() {
    FILE *fp = fopen("notes1.txt", "r");
    if (fp == NULL) return 1;
    char line_buf[256];
    int digits = 4;
    int sum = 0;
    while((fgets(line_buf, sizeof(line_buf), fp)) != NULL) {
        int standard, number;
        int result = 0;
        sscanf(line_buf, "ISO-%d %d", &standard, &number);
        char standard_str[digits + 1];
        char number_str[digits + 1];
        int s, n;
        snprintf(standard_str, sizeof(standard_str), "%d", standard);
        snprintf(number_str, sizeof(number_str), "%d", number);
        for (int i = 0; i < digits; i++) {
            s = standard_str[i] - '0';
            n = number_str[i] - '0';
            result += n * pow(s, abs(i - (digits - 1)));
            printf("result = %d\n", result);
        }
        printf("\n");
        sum += result;
    }
    fclose(fp);
    return sum;
}

int main() {
    printf("Part 1: %d\n", part1());
    return 0;
}


