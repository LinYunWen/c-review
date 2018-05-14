#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
};


void display(struct node *start) {
    struct node *temp = start;
    printf("Traversal in forward direction \n");
    // for (; temp->next != start; temp = temp->next) {
    for (int i = 0; i < 10 && temp->next != start; temp = temp->next, i++) {
	    printf("%d ", temp->data);
    }
    printf("%d ", temp->data);
    printf("\n");
}

void exchange(struct node **left, struct node **right) {
    (*left)->next = (*right)->next;
    (*right)->prev = (*left)->prev;
    (*left)->prev = *right;
    (*right)->next = *left;
}

void bubble_sort(struct node **start, int length) {
    struct node* left = *start;
    struct node* right = left->next;

    for (int i = 0; i < length - 1; i++) {
        for (int j = i+1; j < length; j++) {
            if (right->data < left->data) {
                exchange(&left, &right);
            }
            left = left->next;
            right = right->next;
        }
    }
}

void append_node(struct node **start, int value) {
    if (!*start) {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
    struct node *last = (*start)->prev;
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = *start;
    (*start)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
}

int getLength(struct node** start) {
    if (!*start) {
        return 0;
    }
    
    int count = 1;
    struct node *temp = (*start)->next;
    while ((*start) != temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    struct node *start = NULL;

    // create a linked list with 51, 48, 72, 23, 86
    append_node(&start, 51);
    append_node(&start, 48);
    append_node(&start, 72);
    append_node(&start, 23);
    append_node(&start, 86);

    display(start);

    // get length of linked list
    int length = getLength(&start);

    // bubble sort
    bubble_sort(&start, length);
    display(start);
    return 0;
}