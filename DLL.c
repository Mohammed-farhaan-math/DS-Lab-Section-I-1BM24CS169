#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Define the structure for a Node
struct Node {
    int data;
    struct Node* next; // Pointer to the next node
    struct Node* prev; // Pointer to the previous node
};

// Global head pointer for simplicity in this example
struct Node* head = NULL;

// Helper function to create a new node
struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to add a node to the end of the list (for list creation)
void append(int data) {
    struct Node* new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

// d) Display the contents of the list
void display_list() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("List contents (forward): ");
    while (temp != NULL) {
        printf("<-> %d ", temp->data);
        temp = temp->next;
    }
    printf("<-> NULL\n");
}

// b) Insert a new node to the left (before) of a specific target value
void insert_before(int target_value, int new_data) {
    struct Node* target_node = head;
    while (target_node != NULL && target_node->data != target_value) {
        target_node = target_node->next;
    }

    if (target_node == NULL) {
        printf("Error: Target node with value %d not found.\n", target_value);
        return;
    }

    struct Node* new_node = create_node(new_data);

    // Adjust new node's pointers
    new_node->next = target_node;
    new_node->prev = target_node->prev;

    // Adjust surrounding nodes' pointers
    if (target_node->prev != NULL) {
        target_node->prev->next = new_node;
    } else {
        // If target was the head, new node is the new head
        head = new_node;
    }
    target_node->prev = new_node;

    printf("Inserted %d before %d.\n", new_data, target_value);
}

// c) Delete the node based on a specific value
void delete_node_by_value(int key) {
    struct Node* current = head;

    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: Node with value %d not found for deletion.\n", key);
        return;
    }

    // Adjust pointers of the previous node
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        // If the node to be deleted is the head
        head = current->next;
    }

    // Adjust pointers of the next node
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    printf("Deleted node with value: %d\n", key);
    free(current); // Free the memory of the deleted node
}


int main() {
    // a) Create a doubly linked list
    append(10);
    append(20);
    append(30);
    append(40);
    printf("Initial list created:\n");
    display_list();

    // b) Insert a new node to the left of the node with value 30
    insert_before(30, 25);
    display_list();

    // c) Delete the node based on a specific value (20)
    delete_node_by_value(20);
    display_list();

    // d) Display the contents of the list (handled in previous steps)

    // Remember to free all memory when done in a complete application
    return 0;
}
