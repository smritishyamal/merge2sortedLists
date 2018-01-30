//
//  main.cpp
//  Merge2SortedLists
//
//  Created by Smriti Shyamal on 2018-01-29.
//  Copyright © 2018 Smriti Shyamal. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ;

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode root_merged(-1);
        ListNode *head = &root_merged;
        while (l1 != NULL && l2 != NULL){
            if (l1->val <= l2->val){
                head->next = l1;
                l1 = l1->next;
            }
            else{
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        return root_merged.next;
    }
} sol;

int main() {
    ListNode head(1);
    ListNode *root;
    root = &head;
    ListNode second(2);
    head.next = &second;
    ListNode third(4);
    second.next = &third;
    
    ListNode head1(1);
    ListNode *root1;
    root1 = &head1;
    ListNode second1(3);
    head1.next = &second1;
    ListNode third1(4);
    second1.next = &third1;
    
    ListNode *root_merged;
    root_merged = sol.mergeTwoLists(root, root1);
    ListNode *root_print = root_merged;
    while (root_print != NULL) {
        cout << root_print->val << endl;
        root_print = root_print->next;
    }
    return 0;
}
