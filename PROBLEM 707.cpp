    class Node{
        public:
        int val;
        Node* next;
        Node(int val1){
            val = val1;
            next = NULL;
        }
    };
class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList() {
        head = new Node(0);
        size =0;
    }
    
    int get(int index) {
        if(index >= size || index < 0){
            return -1;
        }
        Node* temp = head;
        for(int i =0;i<=index;i++){
            temp = temp ->next;
        }
        if(temp){
            return temp->val;
        }
        return -1;
    }
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size){
            return;
        }
        Node* temp  = head;
        for(int i =0;i<index;i++){
            temp = temp ->next;
        }
        Node* newnode = new Node(val);
        newnode -> next = temp ->next;
        temp->next = newnode;
        size += 1;
    }
    void deleteAtIndex(int index) {
        if(index <0 || index >= size){
            return;
        }
        Node* temp = head;
        for(int i =0;i<index ;i++){
            temp = temp->next;
        }
        Node* delnode = temp->next;
        temp ->next = temp->next->next;
        delete delnode;
        size -= 1;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
