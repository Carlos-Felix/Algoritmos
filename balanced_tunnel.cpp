#include <stdio.h>


int main(){
    int n,aux ,ans = 0,max;
    int a[100005];
    int b[100005];
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&aux);
        a[i] = aux;
    }

    for(int i = 1; i <= n; i++){
        scanf("%d",&aux);
        b[aux] = i;
    }
    max = b[a[1]];
    for(int i = 2; i <= n; i++){
        if(max  <= b[a[i]])  max = b[a[i]];
        else ans++;
    }
    printf("%d",ans);

}