#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    char data[256];
    struct node *next;
}node_t;

void luckyperson(node_t **head, char *val){
    node_t *temp_node = (*head), *prev;

    if(temp_node != NULL && strcmp(temp_node->data, val) == 0)
        *head = temp_node->next;
    else{
        while (temp_node != NULL && strcmp(temp_node->data, val) != 0){
            prev = temp_node;
            temp_node = temp_node->next;
        }
        if(temp_node == NULL){
            printf("There is no such customer.\n");
            return;
        }
        prev->next = temp_node->next;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    node_t *last = *head;
    strcpy(new_node->data, temp_node->data);
    new_node->next = NULL;

    while(last->next != NULL)
        last = last->next;

    last->next = new_node;
    free(temp_node);
    temp_node = NULL;
}

void admit(node_t **head){
    if (*head == NULL){
        printf("The queue is empty.\n");
        return;
    }

    node_t *next_node = (*head)->next;
    printf("%s has been admitted\n", (*head)->data);

    free(*head);
    *head = next_node;
}

void addToTail(node_t **head, char *val){
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    node_t *last = *head;
    strcpy(new_node->data,val);
    new_node->next = NULL;

    while(last->next != NULL)
        last = last->next;
    last->next = new_node;
}

void printList(node_t *node){
    printf("Queue:");
    while(node != NULL){
        printf("%s", node->data);
        node = node->next;
        if (node != NULL)
            printf(", ");
    }
    printf("\n");
}

void delete_list(node_t **head){
        node_t *current = *head, *next;

        while (current != NULL){
                next = current -> next;
                free(current);
                current = next;
        }

        *head = NULL;
}


int main(){

    node_t *head = (node_t *)malloc(sizeof(node_t));
    char input[256];
    bool quit = 0;

    strcpy(head->data, "Turgut");
    head->next = NULL;

    addToTail(&head, "Nazrin");
    addToTail(&head, "Nigar");
    addToTail(&head, "Kamran");
    addToTail(&head, "Eljan");

    printList(head);

    while(!quit){
        printf("\nenter a command:");
        scanf("%s", input);

        if(strcmp(input, "quit") == 0)

            quit = 1;

        else if(strcmp(input, "admit") == 0)

            admit(&head);

        else
            luckyperson(&head, input);

        printList(head);
    }

    delete_list(&head); //freeing memory

    return 0;
}
            
