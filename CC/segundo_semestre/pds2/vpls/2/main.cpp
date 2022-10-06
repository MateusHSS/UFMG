#include <iostream>

#define MAX 20

int getSize(int *v){
    return sizeof(v)/sizeof(*v);
}


int main(){
    int n;
    int v[MAX];
    int nums = 1;
    
    while(std::cin >> n){
        v[nums-1] = n;
        
        nums++;
    }
    
    std::cout << sizeof(v)/sizeof(v[0]);
    
    return 0;
}