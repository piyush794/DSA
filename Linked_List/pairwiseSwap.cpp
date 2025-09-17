/*Link :https://www.geeksforgeeks.org/problems/pairwise-swap-of-nodes-in-linkelist/1
Pairwise swap of nodes in Linked List
Difficulty: MediumAccuracy: 71.8%Submissions: 22K+Points: 4Average Time: 30m
Given the head of a singly linked list containing positive integers, your task is to swap the data of every two adjacent nodes in the list. Return the head of the modified linked list after performing pairwise swaps.

Examples:

Input:1->2->3->4->5->6->7 
Output: 2->1->4->3->6->5->7 
Explanation:The linked list after swapping becomes:
 
*/
/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node *pairwiseSwap(Node *head) {
        // code here
        if (head == NULL || head->next == NULL){
            return head;
        }
        int curr = head->data;
        int next =  head ->next->data;
        head->data = next;
        head->next->data = curr;
        return pairwiseSwap(head->next->next);
    }
};
int main(){
    
}