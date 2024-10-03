//
// Created by renau on 05/09/2024.
//

#ifndef BASICS_H
#define BASICS_H


// ===================== Queues =====================

struct queue {
    int top;
    unsigned cap;
    int* array;
};

struct queue queue_init(int cap);
void queue_enqueue(struct queue* queue, int item);


// ===================== Stacks =====================

struct Stack {
    int top;
    unsigned cap;
    int* array;
};

struct Stack* stack_create_empty();
void stack_push(struct Stack* stack, int data);
struct Node* stack_pop(struct Stack* stack);
void stack_destroy ();

struct Stack_n {
    int size;
    unsigned cap;
    struct Node_n* head;
    struct Node_n* tail;
};

struct Stack_n* stack_n_create_empty();
void stack_n_push(struct Stack* stack, int data);
struct Node* stack_n_pop(struct Stack* stack);
void stack_n_destroy ();

struct Stack_c {
    int size;
    unsigned cap;
    struct Node_n* head;
};


// ===================== Nodes =====================

struct Node_p {
    void* data;
    struct Node* prev;
};

struct Node_p* node_p_create();

struct Node_n {
    void* data;
    struct Node* next;
};

struct Node_n* node_n_create();

struct Node_pn {
    void* data;
    struct Node* next;
    struct Node* prev;
};

struct Node_pn* node_pn_create();


// ===================== Lists =====================

struct list_n_ht {
    struct Node_n* head;
    struct Node_n* tail;
};

struct list_n_ht list_n_ht_create_empty();

struct list_pn_ht {
    struct Node* head;
    struct Node* tail;
};

struct list_pn_ht list_pn_ht_create_empty();

struct list_c_h {
    int size;
    struct Node* head;
};

struct list_c_h* list_c_h_create_empty();

struct list_i {
    int size;
    void* array;
};

struct list_i list_i_create();

#endif //BASICS_H
