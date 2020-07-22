#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
    int value;
    struct Node* next = nullptr; //create the pointer to the next Node
};

class LL {
private:
    struct Node* head; //create the pointer to head Node.
public:
    int add(int value) {
        if (head == NULL) {
            this->head = (struct Node*)malloc(sizeof(struct Node));
            this->head->value = value;
        }
        else {
            struct Node* node = this->head;
            while (node->next != NULL) //0xCDCDCDCD (only on MSVS, not g++)
            {
                node = node->next;
            }
            node->next = (struct Node*)malloc(sizeof(struct Node));
            node->next->value = value;
        }
        return 0;
    }

    int show() {
        struct Node* node = this->head;
        while (node != NULL) { 
            cout << node->value << endl;
            node = node->next;
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