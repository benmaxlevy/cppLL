#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
    int value;
    struct Node* next; //create the pointer to the next Node
};

class LL {
private:
    struct Node* head; //create the pointer to head Node.
public:
    int add(int value) {
        if (head == nullptr) { //check if the pointer to the head node is null
            this->head = (struct Node*)malloc(sizeof(struct Node)); //allocate memory for the pointer to the head node, and allocate memory for the actual node in the heap.
            this->head->value = value; //set the value of the head node to the value passed.
        }
        else {
            struct Node* node = this->head; //create a pointer to the pointer of the head node 
            while (node->next != nullptr) //check if the next pointer to a node is null
            {
                node = node->next; //if the next pointer is null, set node to the next node. (to keep looking).
            }
            node->next = (struct Node*)malloc(sizeof(struct Node)); //allocate memory for both the next node's pointer, and the actual node in the heap.
            node->next->value = value; //set the value of the next node to the value passed.
        }
        return 0;
    }

    int show() {
        struct Node* node = this->head; //make a pointer to the head node
        while (node != nullptr) { //check if the pointer to the node is not null
            cout << node->value << endl; //print the value of the node
            node = node->next; //set the node to the next node. (to keep looking).
        }
        return 0;
    }

};

int main() {
    LL* linked_list = new LL;
    linked_list->add(1);
    linked_list->add(2);
    linked_list->add(10);
    linked_list->show();
}