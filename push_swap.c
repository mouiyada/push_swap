#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node* next;
  struct node* prev;
} Node;

typedef struct list {
  struct node* top;
} List;

Node* create_node(int val) {
  Node *node = (Node*)malloc(sizeof(Node));
  node->val = val;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void create_list(List* list) {
  Node *dummy = (Node*)malloc(sizeof(Node));
  dummy->next = dummy;
  dummy->prev = dummy;
  list->top =  dummy;
}

void destroy_list(List* list) {
   Node *current = list->top->next;
   Node *next;
   while (current != list->top) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list->top);
    list->top = NULL;
}

void print_list(List* list) {
  Node *current = list->top->next;
  while (current != list->top) {
    printf("%d ", current->val);
    current = current->next;
  }
  printf("\n");
}