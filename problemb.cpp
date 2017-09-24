//
//  main.cpp
//  problem-b
//
//  Created by scott on 23/9/2017.
//  Copyright © 2017 scott. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int steps(int a, int b, int c){
    if(a < c && b < c)
        return -1;
    if( a == b && b == c)
        return 1;
    if(a == b && b != c)
        return -1;
    
    int n_beta = b / a;
    int remainder = b % a;
    
    int result1 = -1;
    int result2 = -1;
    
    if(c % a == 0)
        result1 = c / a;
    if(remainder > c){
        result2 = -1;
    }else if((c - remainder) % a != 0 && result1 == -1){
        result2 = -1;
    }else if(c == remainder)
        result2 = n_beta + 1;
    else{
        int alpha = (c-remainder) / a;
        result2 = n_beta - alpha + 1;
    }
    
    if(result1 != -1 && result2 != -1){
        if(result1 < result2)
            return result1;
        else
            return result2;
    }else if(result1 == -1){
        return result2;
    }else{
        return result1;
    }
}

int main() {
    
    int cases;
    cin >> cases;
    
    while(cases--){
        
        int a, b, c;
        cin >> a >> b >> c;
        if(a > b){
            int tmp = a;
            a = b;
            b = tmp;
        }
        cout << steps(a, b, c) << "\n";
    }
    
    return 0;
}
