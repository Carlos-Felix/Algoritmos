#include <iostream>
#include <vector>

bool suma_0(std::vector<int> &v){
    int suma = 0;
    for(int i = 0; i < v.size(); i++){
        suma = suma + v[i];
    }
    if(suma == 0) {
        std::cout << "suma 0" << std::endl;
        return true;
    }
    else{
        std::cout << "nel" << std::endl;
        return false;
    } 
}

void imp(std::vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << std::endl;;
    }
    
}

void balance(std::vector<int> &v){
    bool b = true;
    for(int i = 0; i < v.size(); i++){
        if(v[i] % 2 != 0){
            if(b == true){
                if(v[i] < 0) v[i] = v[i]/2;
                else v[i] = v[i]/2 + 1;
                
                b = false;
            }else{
                if(v[i] < 0) v[i] = v[i]/2 - 1;
                else v[i] = v[i]/2;
                b = true;
            }
        }else{
            v[i] = v[i]/2;
        }    
    }
}

int main(){
    int n,aux;
    std::cin >> n;
    std::vector<int> v;
    for(int i = 0; i < n; i++){
        std::cin >> aux;
        v.push_back(aux);
    }
    //if(suma_0(v)) std::cout << "suma cero";
    //else std::cout << "no suma cero";
    //suma_0(v);
    balance(v);
    //suma_0(v);
    
    imp(v);

    return 0;
}