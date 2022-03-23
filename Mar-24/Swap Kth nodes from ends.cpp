https://practice.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1#

Node *swapkthnode(Node* head, int num, int K)
{
    if(K > num) {
        return head;    
    }
    if(num == 1 || ((num & 1) && ((num/2 + 1) == K))) {
        return head;
    }
    if(num == 2) {
        Node* node1 = head;
        Node* node2 = head->next; 
        
        node2->next = node1; 
        node1->next = NULL;
        head = node2;
        
        return head;
    }
    if(K == 1 || (num - K + 1) == 1) {
        Node* node1 = head;
        Node* node2 = head; 
        Node* nextnode1 = head->next;
        Node* prevnode2;
        bool flag = true;
        while(node2->next != NULL) {
            node2 = node2->next;
            if(flag && node2->next->next == NULL){
               prevnode2 = node2;
               flag = false;
            } 
        }
        node2->next = nextnode1;
        prevnode2->next = node1;
        
        node1->next = NULL;
        head = node2;
        
        return head;
    }
    
    int first = min(K, num - K + 1);
    int second = max(K, num - K + 1);
    int cntnode = 1;
    Node* temp = head;
    Node* prevnode1 = head;
    Node* nextnode1 = head;
    Node* prevnode2 = head; 
    Node* nextnode2 = head;
    Node* node1 = head;
    Node* node2 = head;
    while(temp) {
        if(cntnode + 1 == first) {
            prevnode1 = temp;
        }
        if(cntnode + 1 == second) {
            prevnode2 = temp;
        }
        cntnode += 1;
        temp = temp->next;
    }
    node1 = prevnode1->next;
    node2 = prevnode2->next;
    
    nextnode1 = node1->next;
    nextnode2 = node2->next;
    
    if(nextnode1 == prevnode2) {
        prevnode1->next = node2;
        nextnode1->next = node1;
        
        node2->next = nextnode1;
        node1->next = nextnode2;
    }
    else if(nextnode1 == node2) {
        prevnode1->next = node2;
        node2->next = node1;
        node1->next = nextnode2;
    }
    else {
        node1 = prevnode1->next; 
        node2 = prevnode2->next; 
        
        nextnode1 = node1->next;
        nextnode2 = node2->next;
        
        prevnode1->next = node2;
        prevnode2->next = node1; 
        node2->next = nextnode1;
        node1->next = nextnode2;
    }
    
    
    return head;
}
