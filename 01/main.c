#include <stdio.h>
#include <string.h>

int part1() {
    FILE *fp = fopen("notes1.txt", "r");
    if (fp == NULL) return 1;
    int buf;
    int sum = 0;
    while(fscanf(fp, "%d,", &buf) == 1) {
        int x = 1;
        while (1) {
            if ((x * x)  == buf break;
            else if ((x * x) > buf) {
                sum += ((x * x) - buf);
                break;
            }
            x++;
        }
    }
    fclose(fp);
    return sum;
}


int part2() {
    FILE *fp = fopen("notes2.txt", "r");
    if (fp == NULL) return 1;
    int buf;
    int sum = 0;
    while(fscanf(fp, "%d,", &buf) == 1) {
        int x = 3;
        while (1) {
            int required = (x * x)- ((x - 2) * (x - 2));
            if (required  == buf) {
                sum += 0;
                break;
            }
            else if (required > buf) {
                sum += (required - buf);
                break;
            }
            x++;
        }
    }
    fclose(fp);
    return sum;
}


int part3() {
    FILE *fp = fopen("notes3.txt", "r");
    if (fp == NULL) return 1;
    int buf;
    int sum = 0;
    while(fscanf(fp, "%d,", &buf) == 1) {
        int x = 3;
        while (1) {
            int required = (x * x) - 1;
            if (required  == buf) break;
            else if (required > buf) {
                sum += (required - buf);
                break;
            }
            x+=2;
        }
    }
    fclose(fp);
    return sum;
}

int main () {
    printf("Part 1: %d\n", part1());
    printf("Part 2: %d\n", part2());
    printf("Part 3: %d\n", part3());
    return 0;
}
