#include <stdio.h>
#include <string.h>

int required_pine_cones(int n) {
    int i = 1;
    while (1) {
        if ((i * i)  == n) return 0;
        else if ((i * i) > n) return (i * i) - n;
        i++;
    };
}

int main () {
    FILE *fp = fopen("notes.txt", "r");
    if (fp == NULL) {
        perror("Error");
        return 1;
    }
    int buf;
    int sum = 0;
    // scan the file int by int
    while(fscanf(fp, "%d,", &buf) == 1) {
        printf("%d ", buf);
        sum += required_pine_cones(buf);
    };
    fclose(fp);
    return 0;
}
