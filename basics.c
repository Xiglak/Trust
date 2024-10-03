//
// Created by renau on 05/09/2024.
//

#include "basics.h"
#include <stdio.h>
#include <stdlib.h>

// ===================== Queues =====================

struct queue queue_init(int cap) {
    struct queue q;
    q.top = -1;
    q.cap = cap;
    q.array = (int*)malloc(cap * sizeof(int));
    if (q.array == NULL) {
        perror("Failed to initialize queue");
        exit(EXIT_FAILURE);
    }
    return q;
}

void queue_enqueue(struct queue* q, int item) {
    if (q->top == (int)(q->cap - 1)) {
        printf("Queue overflow\n");
        return;
    }
    q->array[++(q->top)] = item;
}

// ===================== Stacks =====================

struct Stack* stack_create_empty() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        perror("Failed to create stack");
        exit(EXIT_FAILURE);
    }
    stack->top = -1;
    stack->cap = 10; // Default capacity
    stack->array = (int*)malloc(stack->cap * sizeof(int));
    if (stack->array == NULL) {
        perror("Failed to initialize stack");
        free(stack);
        exit(EXIT_FAILURE);
    }
    return stack;
}

void stack_push(struct Stack* stack, int data) {
    if (stack->top == (int)(stack->cap - 1)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++(stack->top)] = data;
}

struct Node* stack_pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return NULL;
    }
    return &stack->array[(stack->top)--];
}

void stack_destroy(struct Stack* stack) {
    free(stack->array);
    free(stack);
}

// ===================== Nodes =====================

struct Node_p* node_p_create() {
    struct Node_p* node = (struct Node_p*)malloc(sizeof(struct Node_p));
    if (node == NULL) {
        perror("Failed to create node");
        exit(EXIT_FAILURE);
    }
    node->data = NULL;
    node->prev = NULL;
    return node;
}

struct Node_n* node_n_create() {
    struct Node_n* node = (struct Node_n*)malloc(sizeof(struct Node_n));
    if (node == NULL) {
        perror("Failed to create node");
        exit(EXIT_FAILURE);
    }
    node->data = NULL;
    node->next = NULL;
    return node;
}


// ===================== Lists =====================

struct list_n_ht list_n_ht_create_empty() {
    struct list_n_ht list;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

struct list_pn_ht list_pn_ht_create_empty() {
    struct list_pn_ht list;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

struct list_c_h* list_c_h_create_empty() {
    struct list_c_h* list = (struct list_c_h*)malloc(sizeof(struct list_c_h));
    if (list == NULL) {
        perror("Failed to create list");
        exit(EXIT_FAILURE);
    }
    list->size = 0;
    list->head = NULL;
    return list;
}

struct list_i list_i_create() {
    struct list_i list;
    list.size = 0;
    list.array = NULL;
    return list;
}
