#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
public:
    Node* segregate(Node* h) {
        multiset<int> s;
        Node *p = h;
        
        while(p) s.insert(p->data), p = p->next;
        
        p = h;
        for(int i : s) p->data = i, p = p->next;
        
        return h;
    }
};