#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

long long n,k,A,B,x,r;
std::vector<long long> av;

long long li(long long p,long long q,long long x){
    long long ans = -1;
    if(av[k] < x) return -1;
    if(x <= av[1]) return 1;
    if(p+1 == q || p == q){
        if(x > av[q] && x <= av[q+1]) return q+1;
        else if(x <= av[p]) return p;
        else return q;
    }
    
    if(p < q){
        
        r = (p+q)/2;
        if(av[r] == x){
            while(r >= 1){
                if(av[r] == x) r--;
                else break;
            }
            return r+1;
        }
        else if(av[r] > x) ans = li(p,r-1,x);
        else if(av[r] < x) ans = li(r+1,q,x);
        
    }
    return ans;
}
long long ls(long long p,long long q,long long x){
    long long ans = -1;
    if(av[1] > x) return -1;
    if(x >= av[k]) return k;
    if(p+1 == q || p == q){
        if(x < av[p] && x >= av[p-1]) return p-1;
        else if(x >= av[q]) return q;
        else return p;
    }

    if(p < q){
        int r = (p+q)/2;
        if(av[r] == x){
            while(r <= k){
                if(av[r] == x) r++;
                else break;
            }
            return r-1;
        }
        else if(av[r] > x)  ans = ls(p,r-1,x);
        else if(av[r] < x)  ans = ls(r+1,q,x);
    }
    return ans;
}


long long destroy(int i,int j){
    long long lmi,lms,mid,c1,c2,ct;
    lmi = li(1,k,i);
    lms = ls(1,k,j);
    
    if(lmi == -1 || lms == -1) return A;
    if(lmi > lms) return A;
    if(i == j){
        if(lms < lmi) return A;
        else return B*(lms-lmi+1);
    } 
    if(lms >= lmi){
        if(i < j){
            mid = (j-i)/ 2;
            c1 = destroy(i,i+mid);
            c2 = destroy(i+mid+1,j); 
        }
    }
    ct = B*(lms-lmi +1)*(j-i+1);
    if(ct < c1 + c2) return ct;
    else return (c1 + c2);
}

void imp(std::vector<int> av){
    for(int i = 1; i <= k; i++ ){
        printf("%d ",av[i]);
    }
    printf("\n");
}
 
int main(){
    scanf("%lld %lld %lld %lld", &n,&k,&A,&B);

    av.push_back(-1);
    for(long long i = 1; i <= k; i++){
        scanf("%lld",&x);
        av.push_back(x);
    }
    sort(av.begin(),av.end());

   long long x = 1;
    for(long long i = 1; i <= n; i++){
        x = 2*x;
    }
    
    printf("%lld",destroy(1,x));
    return 0;
}