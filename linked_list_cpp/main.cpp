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
	/// Creates a new node, but does not initialize it.
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
	/// <summary>
	/// Adds a node to the end of the linked list.
	/// </summary>
	/// <param name="value">The value to add to the end of the linked list.</param>
	/// <returns>0 if the operation was successful.</returns>
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
		auto to_add_after = this->getNodeByIndex(index);
		
		// I prefer to handle the unexpected cases like this, but you can totally handle
		// them like you did before. -AJ
		// The node to add after is a nullptr, there's no such node at the given index. Fail out.
		if (to_add_after == nullptr) {
			return 1;
		}

		// Create the new node.
		auto newNode = createNewNode();
		
		// Initialize the new node.
		initializeNode(newNode);
		newNode->value = value;

		// The next node (after the node we found) needs to be moved to
		// the next element of the new node we created.
		newNode->next = to_add_after->next;
		to_add_after->next = newNode;

		// Operation successful.
		return 0;
	}
	
	// Your function show_one_node was good, I just rewrote it slightly to use a while loop and with a different name.
	/// <summary>
	/// Gets a node given a specific index.
	/// </summary>
	/// <param name="index">The index of the node to get.</param>
	/// <returns>The node at index or nullptr if no such node exists.</returns>
	Node* getNodeByIndex(int index) {
		// Store a pointer to the current node, starting at the head of the list.
		auto currentNode = this->head;

		// Keep track of the current index.
		int currentIndex = 0;

		// Keep looping while we have a node that isn't nullptr.
		while (currentNode != nullptr) {
			// If we get to the node with the right index, great! Return it.
			if (currentIndex == index) {
				return currentNode;
			}
			
			// Otherwise, keep looping. Increment the current index.
			currentIndex++;

			// Move to the next node.
			currentNode = currentNode->next;
		}

		// No such node exists. That's very sad. Return nullptr to signal that there's no node.
		return nullptr;
	}

	int show() {
		// Using auto simplifies things a bit.
		auto node = this->head; //make a pointer to the head node
		
		// Check if the pointer to the node is not null
		while (node != nullptr) {
			// Print the value of the node
			cout << node->value << endl;
			
			// Set the node to the next node. (to keep looking).
			node = node->next;
		}

		// Why free the node? No need if we're just showing the elements. -AJ
		//free(node);
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
