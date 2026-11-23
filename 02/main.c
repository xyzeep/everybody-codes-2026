#include <stdio.h>
#include <string.h>

int part1() {
    FILE *fp = fopen("notes1.txt", "r");
    if (fp == NULL) return 1;
    char line_buf[100];
    int sum = 0;
    while((fgets(line_buf, sizeof(line_buf), fp)) != NULL) {
        char *p = line_buf;
        int a, b, used;
        char opr;
        int result = 0;
        int wins[5] = {0};
        while(sscanf(p, "%d%c%d%n", &a, &opr, &b, &used) == 3) {
            p += used;
            if (opr == '>') wins[a-1] ++;
            else wins[b-1]++;
        }
        for (int w = 4; w >= 0; w--) {
            for (int i = 0; i < 5; i++) {
                if (wins[i] == w) result = (result * 10) + (i+1);
            }
        }
        sum += result;
        printf("Result: %d", result);
        printf("\n");
    }
    fclose(fp);
    return sum;
}

int main () {
    printf("Part 1: %d\n", part1());
    // printf("Part 2: %d\n", part2());
    // printf("Part 3: %d\n", part3());
    return 0;
}
