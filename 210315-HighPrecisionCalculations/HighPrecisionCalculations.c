#include<stdio.h>
#include<string.h>
#define N 5
//自定义大小
//实验
char temp_1[N + 1], temp_2[N + 1], o_symbol;
int and_1[N + 1], and_2[N + 1], and_0[N + 1];
char final[N + 1];

int Complementary(int temp[]){
    for(int i = 0;i < N + 1;i++){
        temp[i] = 9 - temp[i];
    }
    temp[0]++;

    int i = 0;
    while(temp[i] == 10){
        temp[i++] = 0;
        temp[i]++;
    }//若末位为10，数字进1;
    return 0;
}//求补码;

int Convert(char in[], int out[]){
    int n = strlen(in) - 1, i = 0, j = 0;
    if(in[0] == '-' || in[0] == '+'){
        i = 1;
    }
    for(;n >= i;n--){
        out[j++] = in[n] - '0';
    }
    if(in[0] == '-'){
        Complementary(out);
    }

    return 0;
}//字符串转十进制

int Compute(void){
    for(int i = 0;i < N + 1;i++){
        and_0[i] = 0;
    }//循环清零

    if(o_symbol == '-'){
        Complementary(and_2);
    }
    for(int i = 0; i < N; i++){
        and_0[i] = and_1[i] + and_2[i] + and_0[i];
        if(and_0[i] > 9){
            and_0[i + 1] ++;
            and_0[i] %= 10;
        }
    }
    and_0[N] = and_1[N] + and_2[N] + and_0[N];
    and_0[N] %= 2;

    printf("The calculation result is:                   ");
    if(and_0[N] % 2 == 1){
        printf("-");
        Complementary(and_0);
        for(int i = N - 1;i >= 0;i--){
            if(and_0[i] != 0){
                for(int k = i;k >= 1;k--){
                    printf("%d", and_0[k]);
                }
                break;
            }
        }
        printf("%d", and_0[0]);
        Complementary(and_0);
    }//检测是否为补码形式，是则反转化以输出结果，输出后恢复以用于下一步计算
    else{
        for(int i = N - 1;i >= 0;i--){
            if(and_0[i] != 0){
                for(int k = i;k >= 1;k--){
                    printf("%d", and_0[k]);
                }
                break;
            }
        }
        printf("%d", and_0[0]);
    }
    
    printf("\n\nType an operator to continue.\nType a figure to start a new calculation.\nType \"exit\" to exit.\n");
    printf("Type:                                        ");
    scanf("%s", final);
    return 0;
}//计算并输出结果



int main(void){
    for(int i = 0; i < N + 1;i++){
        and_0[i] = and_1[i] = and_2[i] = 0;
    }

    printf("Enter the first figure:                      ");
    scanf("%s", temp_1);
    Convert(temp_1, and_1);
    printf("Enter the operational symbol(\'+\'/\'-\'):       ");
    scanf("%s", &o_symbol);
    printf("Enter another figure:                        ");
    scanf("%s", temp_2);
    Convert(temp_2, and_2);

    Compute();
    
    while(strcmp(final, "exit") != 0){
        for(int i = 0;i < N + 1;i++){
            and_1[i] = and_2[i] = 0;
            temp_1[i] = 0;
            temp_2[i] = 0;
        }//循环清零
        if(strcmp(final, "+") == 0 || strcmp(final, "-") == 0){
            o_symbol = final[0];
            for(int i = 0;i < N + 1;i++){
                and_1[i] = and_0[i];
            }
        }
        else{
            /*
            for(int i = 0;i < strlen(final);i++){
                temp_1[i] = final[i];
            }
            */
            strcpy(temp_1, final);
            for(int i = 0;i < N + 1;i++){
                final[i] = 0;
            }
            Convert(temp_1, and_1);
            printf("Enter the operational symbol(\'+\'/\'-\'):       ");
            scanf("%s", &o_symbol);
        }
        printf("Enter another figure:                        ");
        scanf("%s", temp_2);
        Convert(temp_2, and_2);

        Compute();
    }
    

    return 0;
}