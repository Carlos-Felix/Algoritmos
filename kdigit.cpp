#include <iostream>
long long getDigits(long long x){
    long long s,n,p;
    s = 0;
    p = 1;
    n = 1;
    while(p*10 < x){
        s = s + n*9*p;
        p = 10*p;
        ++n;
    }
    //std::cout << "n: " << n << std::endl;
    //std::cout << "p: " << p << std::endl;

    return s + (n)*(x-p);
}
void found(long long cmenor,long long cmayor,long long x){
    long long medio = (cmayor + cmenor)/2;
    std::cout << "menor: " << medio << std::endl;
    if(cmayor > cmenor){
        if(getDigits(medio) > x && x > getDigits(cmenor)) found(cmenor,medio,x);
        else if(getDigits(cmayor) > x && x > getDigits(medio)) found(medio,cmayor,x);
    }
    std::cout << getDigits(medio) << std::endl;
}

int main(){
    long long cotamenor,cotamayor,s,p,n,x;
    std::cin >> x;
    s = 0;
    p = 1;
    n = 1;
    while(n*9*p < x){
        s = s + n*9*p;
        p = 10*p;
        ++n;
    }
    std::cout << s << std::endl;
    std::cout << "n: " << n << std::endl;
    std::cout << "p: " << p << std::endl;
    cotamenor = p;
    cotamayor = p*10;
    std::cout << "ACA" << std::endl;
    //std::cout << getDigits(102) << std::endl;
    found(cotamenor,cotamayor,x);
    return 0;
}