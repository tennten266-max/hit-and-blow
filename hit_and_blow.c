#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int f_pow(int s, int n) {
    int ss = 1;
    for (int i = 0; i < n; i++) {
        ss *= s;
    }

    return (int)ss;
}

int n = 4;

int main(void) {
    
    int a[n];
    do {
        a[0] = rand() % 10;
    } while(a[0] == 0);
    for (int i = 1; i < n; i++) {
        a[i] = rand() % 10;
    }

    int ansbox[10];
    memset(ansbox, 0, sizeof(ansbox));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < n; j++) {
            if(i == a[j]) {
                ansbox[i]++;
            }
        }
    }


    int response, hit_count, blow_count;
    printf("桁数は%d\n", n);

    do {
        hit_count = 0;
        blow_count = 0;

        printf("what do you think number is ?\n");
        if(scanf("%d", &response) != 1) {
            printf("数字を入力してください\n");
            getchar()
            continue;
        }

        


        printf("hit_count = %d\n", hit_count);
        printf("blow_count = %d\n", blow_count);

    } while(hit_count != n);

    return 0;

}
