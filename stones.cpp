#include <iostream>
#include <vector>

int stones(int sh1,int sh2,int sh3){
    int max_st = 0;
    if(sh2 == 0) return 0;
    while(sh3 >= 2 && sh2 > 0){
        max_st = max_st + 3;
        sh2--;
        sh3= sh3-2;
    }
    while(sh2 >= 2 && sh1 > 0){
        max_st = max_st + 3;
        sh1--;
        sh2= sh2-2;
    }
    return max_st;
}

int main(){
    int t,sh1,sh2,sh3;
    std::cin >> t;
    std::vector<int> ans;
    //t = 1;
    for(int i = 1; i <= t; ++i){
        std::cin >> sh1 >> sh2 >> sh3;
        ans.push_back(stones(sh1,sh2,sh3));
    }
    for(int i = 0; i < ans.size(); ++i){
        std::cout << ans[i] << std::endl;
    }
    
    return 0;
}