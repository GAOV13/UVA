#include <stdio.h>

#define lli long long int
#define SEG 8640000
#define DEC 10000000

int main(){
    char lectura[9], ans[8];
    int i;
    lli temp;
    while(scanf("%s", lectura) != EOF){
        temp = (((int)lectura[0]-48)*10+(int)lectura[1]-48)*360000;
        temp += (((int)lectura[2]-48)*10+(int)lectura[3]-48)*6000;
        temp += (((int)lectura[4]-48)*10+(int)lectura[5]-48)*100;
        temp += (((int)lectura[6]-48)*10+(int)lectura[7]-48);
        temp = (temp*DEC)/SEG;
        for(i = 0; i < 7; ++i){
            if(temp == 0) ans[6-i] = '0';
            else{
                ans[6-i] = (char)((temp%10)+48);
                temp /= 10;
            }
        }
        ans[7] = '\0';
        printf("%s\n", ans);
    }
    return 0;
}