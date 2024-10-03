#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(int data) {
    Node* newNode = createNode(data);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteNode(int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                head = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            } else {
                tail = temp->prev;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Node with data %d not found\n", data);
}
void reverseList() {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        Node* next = temp->next;
        temp->next = prev;
        temp->prev = next;
        prev = temp;
        temp = next;
    }

    Node* tempHead = head;
    head = tail;
    tail = tempHead;
}

void printList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtEnd(30);
    insertAtEnd(40);

    printf("List: ");
    printList();

    int data;
    printf("Enter the data value of the node to delete: ");
    scanf("%d", &data);
    deleteNode(data);

    printf("List after deletion: ");
    printList();
    reverseList();
    printf("Reversed List: ");
    printList();

    return 0;
}