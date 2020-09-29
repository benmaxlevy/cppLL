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

	int add_after(int index, int value) {
		struct Node* to_add_after = this->show_one_node(index);
		cout << to_add_after << endl;
		if (to_add_after != nullptr) {
			if (to_add_after->next == nullptr) {
				to_add_after->next = (struct Node*)malloc(sizeof(struct Node));
				to_add_after->next->value = value;
				return 0;
			}
		}
		else {
			cout << "Something went wrong! (to_add_after == nullptr)" << endl;
			return 1;
		}
	}

	struct Node* show_one_node(int index) {
		struct Node* node = this->head; //store a pointer to the head node in variable node.
		for (int i = 0; node->next != nullptr; i++) { //for loop that increments i by 1 if the pointer to the next node isn't null.
			if (i == index) {  //check if i is equal to the index passed
				return node;
			}
			else {
				node = node->next; //if it isn't, set node to the next node
			}
		}
	}

	int show() {
		struct Node* node = this->head; //make a pointer to the head node
		while (node != nullptr) { //check if the pointer to the node is not null
			cout << node->value << endl; //print the value of the node
			node = node->next; //set the node to the next node. (to keep looking).
		}
		free(node);
		return 0;
	}

};

int main() {
	LL* linked_list = new LL;
	linked_list->add(1);
	linked_list->add(2);
	linked_list->add(10);
	linked_list->add_after(2, 5);
	linked_list->show();
}
