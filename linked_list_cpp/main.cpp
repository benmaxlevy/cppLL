#include <cstdlib>
#include <iostream>

using namespace std;

// Let's change this to a typedef to save ourselves the agony of using "struct Node" everywhere. -AJ
/// <summary>
/// Represents a node of a linked list.
/// </summary>
typedef struct Node {
	int value;
	struct Node* next = nullptr; //create the pointer to the next Node
} Node;


// What's an LL? Let's rename this so it's more clear about what this class does. Use F2 in Visual Studio to rename an element. -AJ
class LinkedList {
private:
	struct Node* head; //create the pointer to head Node.

	/// <summary>
	/// Creates a new node with a value of 0 and allocates it on the heap.
	/// </summary>
	/// <returns>A pointer to the new node.</returns>
	static Node* createNewNode() {
		auto newNode = (Node*)malloc(sizeof(Node));
		return newNode;
	}

	/// <summary>
	/// Initializes a node with a value of 0 and a next of nullptr.
	/// </summary>
	/// <param name="node">A node</param>
	/// <returns>0 if the initialization was successful, 1 otherwise.</returns>
	static int initializeNode(Node* node) {
		// Only initialize the node if it's not nullptr.
		if (node != nullptr) {
			node->value = 0;
			node->next = nullptr;
			return 0;
		}

		// We couldn't initialize the node because it's nullptr.
		return 1;
	}

public:
	int add(int value) {
		// We always have to make a new node if we're adding a node. Let's create the new node up here to avoid doing it twice. -AJ
		auto newNode = createNewNode();
		initializeNode(newNode);
		newNode->value = value;

		// Now that we have the node set up, we can add it to the linked list. -AJ

		// If there's no head to the linked list, we can just make the new node the head and call it a day. -AJ
		if (head == nullptr) {
			this->head = newNode;
		}
		else {
			Node* node = this->head; //create a pointer to the pointer of the head node 
			while (node->next != nullptr) //check if the next pointer to a node is null
			{
				node = node->next; //if the next pointer is null, set node to the next node. (to keep looking).
			}

			// Now that we've created those fancy-shmancy methods and initialized the node at the top, 
			// there's no more work to be done here other than pointing the end of the list at the new node. -AJ
			node->next = newNode;
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
	LinkedList* linked_list = new LinkedList;
	linked_list->add(1);
	linked_list->add(2);
	linked_list->add(10);
	linked_list->add_after(2, 5);
	linked_list->show();
}
