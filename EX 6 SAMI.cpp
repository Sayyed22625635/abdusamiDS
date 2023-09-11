#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
	printf("Memory allocation failed!\n");
	exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
	return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
	current = current->next;
    }
    current->next = newNode;
    return head;
}

struct Node* deleteNode(struct Node* head, int data) {
    if (head == NULL) {
	printf("List is empty. Nothing to delete.\n");
	return head;
    }
    if (head->data == data) {
	struct Node* temp = head;
	head = head->next;
	free(temp);
	return head;
    }
    struct Node* current = head;
    while (current->next != NULL && current->next->data != data) {
	current = current->next;
    }
    if (current->next == NULL) {
	printf("Element %d not found in the list.\n", data);
	return head;
    }
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

void displayList(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
	printf("%d -> ", current->data);
	current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
	printf("\nSingly Linked List Operations:\n");
	printf("1. Insert at the beginning\n");
	printf("2. Insert at the end\n");
	printf("3. Delete a node\n");
	printf("4. Display the list\n");
	printf("5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
	    case 1:
		printf("Enter data to insert at the beginning: ");
		scanf("%d", &data);
		head = insertAtBeginning(head, data);
		break;
	    case 2:
		printf("Enter data to insert at the end: ");
		scanf("%d", &data);
		head = insertAtEnd(head, data);
		break;
	    case 3:
		printf("Enter data to delete: ");
		scanf("%d", &data);
		head = deleteNode(head, data);
		break;
	    case 4:
		displayList(head);
		break;
	    case 5:
		exit(0);
	    default:
		printf("Invalid choice. Please try again.\n");
	}
    }

    return 0;
}

