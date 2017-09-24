//
//  main.cpp
//  First
//
//  Created by scott on 23/9/2017.
//  Copyright © 2017 scott. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int calc_length(int input[], int n);
int calc_first_one(int input[], int n){
    for(int i = 0; i < n; i++){
        if(input[i] == 1)
            return i;
    }
    return -1;
}
int calc_length(int input[], int n){
    int best_sweet = 0;
    int best_not = 0;
    int n_sweet = 0;
    int n_not = 0;
    int first_one;
    int upper_bound = 0;
    if(n <= 0)
        return 0;
    first_one = calc_first_one(input, n);
    if(first_one == -1)
        return 0;
    for(int i = first_one; i < n; i++){
        if(input[i] == 1){
            n_sweet = n_sweet + 1;
        }
        else{
            n_not = n_not + 1;
        }
        if((n_sweet - n_not) >= 1){
            if((n_sweet + n_not) >= (best_sweet + best_not)){
                upper_bound = i;
                best_sweet = n_sweet;
                best_not = n_not;
            }
        }
    }
    if(first_one != 0 && (best_sweet- best_not) > 1){
        int allowed_zero = best_sweet - best_not -1;
        if(first_one > allowed_zero)
            best_not = best_not + allowed_zero;
        else if(first_one == allowed_zero)
            best_not = best_not + first_one;
        else{
            best_not = best_not + first_one;
        }
    }
    return best_sweet + best_not + calc_length(input + upper_bound + 1, n - upper_bound -1);
}
int main(int argc, const char * argv[]) {
    int cases;
    cin >> cases;
    vector<int> results;
    while(cases--){
        
        int len;
        // length of array
        cin >> len;
        int arr[len+5]; // actual array
        
        // array insertion
        for(int i = 0; i < len; i++){
            char tmp;
            cin >> tmp;
            arr[i] = (int)(tmp-'0');
        }
        
        results.push_back(calc_length(arr, len));
    }
    
    for(int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
    
    return 0;
}
