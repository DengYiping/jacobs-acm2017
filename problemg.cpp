//
//  main.cpp
//  problem-g
//
//  Created by scott on 23/9/2017.
//  Copyright © 2017 scott. All rights reserved.
//

#include <iostream>
using namespace std;

int nums[105][2005];

int main() {
    
    ios_base:: sync_with_stdio(false);
    
    int cases;
    cin >> cases;
    for(int c = 0; c < cases; c += 1){
        
        int num_of_data;
        cin >> num_of_data;

        for(int i = 0; i < num_of_data; i += 1){
            int tmp;
            cin >> tmp;
            if(tmp < 0){
                nums[c][(-tmp)+1000] += 1;
            } else {
                nums[c][tmp] += 1;
            }
        }
        
        bool found = false;
        for(int i = 0; i <= 2000; i++){
            if(nums[c][i] > num_of_data/2){
                cout << "YES ";
                if(i <= 1000){
                    cout << i << "\n";
                } else {
                    cout << -(i-1000) << "\n";
                }
                found = true;
                break;
            }
        }
        if(!found)
            cout << "NO\n";
    }
    
    
    return 0;
}
