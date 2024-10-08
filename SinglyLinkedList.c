#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertFront(struct node **head, int item){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Can't allocate memory");
    }
    else{
        newnode -> data = item;
        newnode -> next = *head;
        *head = newnode;
    }
}

void insertEnd(struct node **head, int item){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *current;
    current = *head;
    if(newnode == NULL){
        printf("Can't allocate memory");
    }
    else{
        newnode -> data = item;
        while(current -> next != NULL){
            current = current -> next;
        }
        current -> next = newnode;
    }
}

void insertLoc(struct node **head, int item, int pos){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *current;
    int count = 0, i;
    if(newnode == NULL){
        printf("Can't allocate memory");
        return;
    }
    else{
    current = *head;
        while(current != NULL){
            current = current -> next;
            count++;
        }
        if(pos > count + 1 || pos < 1){
            printf("Invalid position");
            free(newnode);
            return;
        }
        if(pos == 1){
            insertFront(head, item);
            return;
        }
            newnode -> data = item;
            newnode -> next = NULL;
            current = *head;
            for(i = 1; i < pos - 1; i++){
                current = current -> next;
            }
                newnode -> next = current -> next;
                current -> next = newnode;
    }
}

void deleteFront(struct node **head){
    struct node *temp;
    if(*head == NULL){
        printf("List is empty");
    }
    else if((*head) -> next == NULL){
        temp = *head;
        *head = NULL;
        free(temp);
    }
    else{
        temp = *head;
        *head = (*head) -> next;
        free(temp);
    }
}

void deleteEnd(struct node **head){
    struct node *temp, *prev;
    if(head == NULL){
        printf("List is empty");
    }
    else if((*head) -> next == NULL){
        temp = *head;
        *head = NULL;
        free(temp);
    }
    else{
        temp = *head;
        while(temp -> next != NULL){
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = NULL;
        free(temp);
    }
}

void deleteLoc(struct node **head, int pos){
    struct node *temp, *prev;
    int i;
    int count = 0;
    if(head == NULL){
        printf("List is empty");
    }
    temp = *head;
    if(pos == 1){
        head = (*head) -> next;
        free(temp);
    }
    prev = NULL;
    for(i = 1; i < pos && temp != NULL; i++){
        prev = temp;
        temp = temp -> next;
    }
    if(temp == NULL){
        printf("Position out of range");
    }
    else{
        prev -> next = temp -> next;
        free(temp);
    }
}

void display(struct node **head){
    if(*head == NULL){
        printf("List is empty");
    }
    struct node *temp;
    temp = *head;
    printf("%d", temp -> data);
    temp = temp -> next;
    while(temp != NULL){
        printf(" -> %d ", temp -> data);
        temp = temp -> next;
    }
    printf(" -> NULL\n");
}

int main(){
    struct node *head = NULL;
    int choice, data, pos;
    while(1){
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a position\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at a position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter you choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data : ");
                scanf("%d", &data);
                insertFront(&head, data);
                break;
            case 2:
                printf("Enter data : ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 3:
                printf("Enter data : ");
                scanf("%d", &data);
                printf("Enter position : ");
                scanf("%d", &pos);
                insertLoc(&head, data, pos);
                break;
            case 4:
                deleteFront(&head);
                break;
            case 5:
                deleteEnd(&head);
                break;
            case 6:
                printf("Enter position : ");
                scanf("%d", &pos);
                deleteLoc(&head, pos);
                break;
            case 7:
                display(&head);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}