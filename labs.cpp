#include <stdio.h>

int main(){
    int b[90005];
    int n,j,ac;
    scanf("%d",&n);
    int itu = 2*n - 1,itd = 1;


    for(int i = 1; i <= n; i++){
        printf("%d ",i);
        ac = i;
        j = 2;
        while(j >= 2 && j <= n){
            if(j % 2 == 0) {
                ac = ac + itu;
                printf("%d ",ac);
            }
            else{
                ac = ac + itd;
                printf("%d ",ac);
            }
            j++;
        }
        itu = itu -2;
        itd = itd +2;
        printf("\n");
    }
    return 0;
}