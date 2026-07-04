#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int f_pow(int s, int n) {
    int ss = 1;
    for (int i = 0; i < n; i++) {
        ss *= s;
    }

    return (int)ss;
}

void clear_buffer(void) {
    int c;
    while(( c = getchar() ) != '\n' && c != EOF)
}

#define n 4

int main(void) {
    srand(time(NULL));
    
    int a[n];
    int b[n]; //作業列
    do {
        a[0] = rand() % 10;
    } while(a[0] == 0);
    for (int i = 1; i < n; i++) {
        a[i] = rand() % 10;
    }

    int number = 0;
    for (int i = 0; i < n; i++)  {
        number += a[i] * f_pow(10, n-1-i);
    }


    int response, hit_count, blow_count;
    printf("桁数は%dです\n", n);
    int ans_count = 1;

    do {
        hit_count = 0;
        blow_count = 0;

        printf("%d回目の挑戦です\n", ans_count);
        printf("what do you think number is ?\n");
        if(scanf("%d", &response) != 1) {
            printf("数字を入力してください\n\n");
            clear_buffer();
            continue;
        } 
            char str[256];
            snprintf(str, sizeof(str), "%d", response);
            if(strlen(str) != n) {
                if(response == 0) {
                    printf("%d\n", number);
                    printf("you lose\n");
                    return 1;
                }
                printf("数字は%d桁です\n\n", n);
                getchar();
                continue; 
            }
            
        
        memcpy( b, a, sizeof(a));
        
        //hit_count
        for (int i = 0; i < n; i++) {
            if(str[i] == b[i] + '0') {
                hit_count++;
            }
        ｝
        
        
        //blow_count
        for (int i = 0; i < n; i++) {       // 入力された文字のループ
            for (int j = 0; j < n; j++) {   // 正解配列のループ
                if(i != j && str[i] == b[j] + '0') {
                    
                    b[j] = -1;
                    blow_count++;
                    break;
                }
            }
        }

        printf("hit_count = %d\n", hit_count);
        printf("blow_count = %d\n\n", blow_count);
        ans_count++;
        

    } while(hit_count != n);
    printf("Congraturation!!!!\n");
    printf("%d回目で成功しました", ans_count-1);

    return 0;
}
