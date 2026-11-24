#include <stdio.h>

#define N 9

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
    }
    fclose(fp);
    return sum;
}


long long int part2() {
    FILE *fp = fopen("notes2.txt", "r");
    if (fp == NULL) return 1;
    char line_buf[512];
    long long int sum = 0;
    while((fgets(line_buf, sizeof(line_buf), fp)) != NULL) {
        char *p = line_buf;
        int a, b, used;
        char opr;
        long long int result = 0;
        int wins[N] = {0};
        int loses[N] = {0};
        while(sscanf(p, "%d%c%d%n", &a, &opr, &b, &used) == 3) {
            p += used;
            if (opr == '>') {
                wins[a-1] ++;
                loses[b-1] ++;
            }
            else {
                wins[b-1] ++;
                loses[a-1] ++;
            }
        }
        for (int j = 1; j<N; j++) {
            for (int k = 0; k<N; k++) {
                if (j != k && wins[j] == wins[k]) {
                    if (loses[j] > loses[k]) wins[k] ++;
                    else wins[j]++;
                }
            }
        }
        for (int w = N-1; w >= 0; w--) {
            for (int i = 0; i < N; i++) {
                if (wins[i] == w) result = (result * 10) + (i+1);
            }
        }
        sum += result;
    }
    fclose(fp);
    return sum;
}


long long int part3() {
    FILE *fp = fopen("notes3.txt", "r");
    if (fp == NULL) return 1;
    char line_buf[512];
    long long int sum = 0;
    while((fgets(line_buf, sizeof(line_buf), fp)) != NULL) {
        char *p = line_buf;
        int a, b, used;
        char opr;
        long long int result = 0;
        int beats[N][N] = {0};
        while(sscanf(p, "%d%c%d%n", &a, &opr, &b, &used) == 3) {
            p += used;
            if (opr == '>') beats[a-1][b-1] = 1;
            else beats[b-1][a-1] = 1;
        }
        int placed[N] = {0};
        int incoming[N] = {0};
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j && beats[i][j] == 1) incoming[j] ++;
            }   
        }   

        for (int step = 0; step < N; step++) {
            int cur = -1;
            for (int i = 0; i < N; i++) {
                if (incoming[i] == 0 && !placed[i]) {cur = i; break;}
            }
            if (cur == -1) break;

            placed[cur] = 1;
            result = (result * 10) + (cur + 1);

            for (int j = 0; j < N; j++) {
                if (beats[cur][j] == 1) incoming[j]--;
            }
        }
        sum += result;
    }
    fclose(fp);
    return sum;
}

int main () {
    printf("Part 1: %d\n", part1());
    printf("Part 2: %lld\n", part2());
    printf("Part 3: %lld\n", part3());
    return 0;
}
