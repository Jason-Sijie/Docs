#include <iostream>
#include <map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        
        map<Node*, int> M;
        map<int, Node*> InvM;
        
        Node* ptr = head;        
        Node* newHead, *curptr, *lastptr;
        int index = 0;
        
        while(ptr != nullptr){
            M.insert(make_pair(ptr, index));
            curptr = new Node(ptr->val, nullptr, nullptr);
            InvM.insert(make_pair(index, curptr));
            if(!newHead){
                // the new list is empty
                newHead = curptr;
                lastptr = curptr;
            }
            else{
                lastptr->next = curptr;
                lastptr = curptr;
            }
            ptr = ptr->next;
            index++;
        }
        
        for(ptr = head, curptr = newHead; ptr!=nullptr; ptr=ptr->next, curptr=curptr->next){
            auto ite = M.find(ptr->random);
            if(ite != M.end()){
                curptr->random = InvM.find(ite->second)->second;
            }
        }
        return newHead;
        
    }
};

int main(){
    Node* head = new Node(0, nullptr, nullptr);
    Node* p1 = new Node(1, nullptr, nullptr);
    Node* p2 = new Node(2, nullptr, nullptr);
    Node* p3 = new Node(3, nullptr, nullptr);
    Node* p4 = new Node(4, nullptr, nullptr);

    head->next = p1;
    head->random = p1;
    p1->next = nullptr;
    p1->random = p1;
    // p2->next = p3;
    // p2->random = p4;
    // p3->next = p4;
    // p3->random = p1;
    // p4->random = p4;

    Solution S;
    Node* newHead = S.copyRandomList(head);

    for(; head != nullptr; head = head->next){
        cout << "index: " << head << endl
            << "value: " << head->val << endl
            << "random: " << head->random << endl;
    }
    
    for(; newHead != nullptr; newHead = newHead->next){
        cout << "index: " << newHead << endl
            << "value: " << newHead->val << endl
            << "random: " << newHead->random << endl;
    }
}