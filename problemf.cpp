//
//  main.cpp
//  problem-f
//
//  Created by scott on 23/9/2017.
//  Copyright © 2017 scott. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Trie{
  
    struct Node{
        Node *nums[10];
        
        Node(){
            for(int i = 0; i < 10; i++){
                this->nums[i] = NULL;
            }
        }
    };
    
    Node *root;
    
    int get_num(char c){
        return (int)(c-'0');
    }
    
    bool private_insert(string str, int idx, Node *p, bool b){
        
        if(idx == str.length())
            return b;
        
        int curr_num = get_num(str[idx]);
        if(p->nums[curr_num] == NULL){
            b = false;
            p->nums[curr_num] = new Node();
        }
        
        return private_insert(str, idx+1, p->nums[curr_num], b);
    }
    
public:
    
    Trie(){
        root = NULL;
    }
    
    bool insert(string str){
        if(root == NULL){
            root = new Node();
        }
        return private_insert(str, 0, root, true);
    }
};

bool f_cmp(const string &a, const string &b){
    return a.length() > b.length();
}

int main() {
    
    ios_base::sync_with_stdio(false);
    
    int cases;
    cin >> cases;

    for(int c = 0; c < cases; c += 1){

        Trie trie;
        int num_data;
        cin >> num_data;
        vector<string> strs;
        strs.resize(num_data);

        for(int i = 0; i < num_data; i++){
            cin >> strs[i];
        }

        sort(strs.begin(), strs.end(), f_cmp);

        bool yes = true;
        for(int i = 0; i < num_data; i++){
            if(trie.insert(strs[i])){
                yes = false;
                cout << "NO\n";
                break;
            }
        }
        if(yes){
            cout << "YES\n";
        }

    }
    
    
    return 0;
}
