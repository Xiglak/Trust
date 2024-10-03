//
// Created by arena on 18/09/2023.
//
#include "Data_struct.h"
#include <stdio.h>
#include <stdlib.h>

// ===================== Nodes =====================


// Node //

struct Node* node_create_empty() {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node != NULL) {
        new_node->value = NULL;
    }
    return new_node;
}

struct Node* node_create(void* value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node != NULL) {
        new_node->value = value;
    }
    return new_node;
}

void node_destroy(struct Node* node) {
    if (node != NULL) {
        free(node);
    }
}


// Node_n //

struct Node_n* node_n_create_empty() {
    struct Node_n* new_node = (struct Node_n*)malloc(sizeof(struct Node_n));
    if (new_node != NULL) {
        new_node->value = NULL;
        new_node->next = NULL;
    }
    return new_node;
}

struct Node_n* node_n_create_v(void* value) {
    struct Node_n* new_node = (struct Node_n*)malloc(sizeof(struct Node_n));
    if (new_node != NULL) {
        new_node->value = value;
        new_node->next = NULL;
    }
    return new_node;
}

struct Node_n* node_n_create_vn(void* value,struct Node_n* next) {
    struct Node_n* new_node = (struct Node_n*)malloc(sizeof(struct Node_n));
    if (new_node != NULL) {
        new_node->value = value;
        new_node->next = next;
    }
    return new_node;
}

void node_n_destroy(struct Node_n* node) {
    if (node != NULL) {
        free(node);
    }

}


// Node_pn //

struct Node_pn* node_pn_create_empty() {
    struct Node_pn* new_node = (struct Node_pn*)malloc(sizeof(struct Node_pn));
    if (new_node != NULL) {
        new_node->value = NULL;
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    return new_node;
}

struct Node_pn* node_pn_create_v(void* value) {
    struct Node_pn* new_node = (struct Node_pn*)malloc(sizeof(struct Node_pn));
    if (new_node != NULL) {
        new_node->value = value;
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    return new_node;
}

struct Node_pn* node_pn_create_vnp(void* value,struct Node_pn* prev,struct Node_pn* next){
    struct Node_pn* new_node = (struct Node_pn*)malloc(sizeof(struct Node_pn));
    if (new_node != NULL) {
        new_node->value=value;
        new_node->prev= prev;
        new_node->next= next;
    }
    return new_node;
};

void node_pn_destroy(struct Node_pn* node) {
    if (node != NULL) {
        free(node);
    }
}


// node_bin //

struct Node_bin* node_bin_create_empty(){
    struct Node_bin* new_node = (struct Node_bin*)malloc(sizeof(struct Node_bin));
    if (new_node != NULL) {
        new_node->value = NULL;
    }
    return new_node;
}

struct Node_bin* node_bin_create(void* value){
    struct Node_bin* new_node = (struct Node_bin*)malloc(sizeof(struct Node_bin));
    if (new_node != NULL) {
        new_node->value = value;
        new_node->link[0]=NULL;
        new_node->link[1]=NULL;
    }
    return new_node;
}

void node_bin_destroy(struct Node_bin* node) {
    if (node != NULL) {
        free(node);
    }
}


// node_xn //

struct Node_xn* node_xn_create_empty(int x){
    struct Node_xn* new_node = (struct Node_xn*)malloc(x * sizeof(struct Node_xn*));
    if (new_node != NULL) {
        new_node->value = NULL;
        new_node->n_branch = x;
        new_node->link = (struct Node_xn**)malloc(x * sizeof(struct Node_xn*));
    }
    return new_node;
}

struct Node_xn* node_xn_create(int x, void* value){
    struct Node_xn* new_node = (struct Node_xn*)malloc(x * sizeof(struct Node_xn*));
    if (new_node != NULL) {
        new_node->value = value;
        new_node->n_branch = x;
        new_node->link = (struct Node_xn**)malloc(x * sizeof(struct Node_xn*));
    }
    return new_node;
}

void node_xn_destroy(struct Node_xn* node) {
    if (node != NULL) {
        free(node->link);
        free(node);
    }
}



// ===================== Lists =====================

// List_h //
struct List_h* list_h_create_empty() {
    struct List_h* new_list = (struct List_h*)malloc(sizeof(struct List_h));
    if (new_list != NULL) {
        new_list->head = NULL;
    }
    return new_list;
}

struct List_h* list_h_create(void* value) {
    struct List_h* new_list = list_h_create_empty();
    if (new_list != NULL) {
        new_list->head = node_n_create_v(value);
    }
    return new_list;
}

void list_h_destroy(struct List_h* list) {
    if (list != NULL) {
        struct Node_n* current = list->head;
        while (current != NULL) {
            struct Node_n* next = current->next;
            node_n_destroy(current);
            current = next;
        }
        free(list);
    }
}


// List_ht //

struct List_ht* list_ht_create_empty(){
    struct List_ht* mylist=(struct List_ht*)malloc(sizeof(struct List_ht));
    mylist->head=NULL;
    mylist->tail=NULL;
    return mylist;
};

struct List_ht* list_ht_create(struct Node_pn* head,int lenght){
    struct List_ht* mylist = (struct List_ht*)malloc(sizeof(struct List_ht));
    mylist->head=head;
    mylist->tail=head;
    if (lenght<0) {
        while (mylist->tail->next!=NULL) {
            mylist->tail=mylist->tail->next;
        }
    }
    for(int i = 1; i!=lenght; i++)
    {
        if (mylist->tail->next!=NULL) {
            mylist->tail= mylist->tail->next;
        }
    };
    return mylist;
};

void list_ht_append_node(struct List_ht* list, struct Node_pn* node){
    node->prev=list->tail;
    node->next=NULL;
    list->tail->next=node;
    list->tail=list->tail->next;
};

void list_ht_append_value(struct List_ht* list, void* value){
    struct Node_pn *node = node_pn_create_v(value);
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        node->prev=list->tail;
        list->tail->next=node;
        list->tail=list->tail->next;
    }
    node->next=NULL;
};

void list_ht_insert(struct List_ht* list, void* value, int position) {
    struct Node_pn* new_node = node_pn_create_v(value);
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        struct Node_pn* current = list->head;
        int i = 0;
        while (current != NULL && i < position) {
            current = current->next;
            i++;
        }
        if (current != NULL) {
            new_node->next = current->next;
            new_node->prev = current;
            if (current->next != NULL) {
                current->next->prev = new_node;
            }
            else {
                list->tail = new_node;
            }
            current->next = new_node;
        }
    }
}

int list_ht_count_node(struct List_ht* list) {
    if (list->head!=NULL) {
        int i = 1;
        struct Node_pn* cur=list->head;
        while (cur->next!=NULL) {
            cur=cur->next;
            i++;
        }
        return i;
    }
    return 0;
}

void list_ht_destroy(struct List_ht* list) {
    if (list != NULL) {
        struct Node_pn* current = list->head;
        while (current != NULL) {
            struct Node_pn* next = current->next;
            node_pn_destroy(current);
            current = next;
        }
        free(list);
    }
}


// List_c //

struct List_c* list_c_create_empty() {
    struct List_c* new_list = malloc(sizeof(struct List_c));
    new_list->size = 0;
    new_list->head = NULL;
    return new_list;
}

struct List_c* list_c_create(void* value) {
    struct List_c* new_list = malloc(sizeof(struct List_c));
    if (new_list != NULL) {
        new_list->head = node_pn_create_v(value);
        new_list->size = 1;
    }
    return new_list;
}

void list_c_append(struct List_c* list, void* value) {
    struct Node_pn* new_node = node_pn_create_v(value);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct Node_pn* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
    list->size++;
}

void list_c_destroy(struct List_c* list) {
    if (list != NULL) {
        struct Node_pn* current = list->head;
        while (current != NULL) {
            struct Node_pn* next = current->next;
            node_pn_destroy(current);
            current = next;
        }
        free(list);
    }
}

int list_c_size(struct List_c* list) {
    return list->size;
}

int list_c_is_empty(struct List_c* list) {
    return (list->size == 0);
}

void* list_c_get(struct List_c* list, int index) {
    if (index < 0 || index >= list->size) {
        return NULL;
    }
    struct Node_pn* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}

int list_c_set(struct List_c* list, int index, void* value) {
    if (index < 0 || index >= list->size) {
        return 0;
    }
    struct Node_pn* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->value = value;
    return 1;
}

void list_c_insert(struct List_c* list, int index, void* value) {
    if (index < 0 || index > list->size) {
        return;
    }
    if (index == list->size) {
        list_c_append(list, value);
        return;
    }
    struct Node_pn* new_node = node_pn_create_v(value);
    if (index == 0) {
        new_node->next = list->head;
        new_node->prev = list->head->prev;
        list->head->prev->next = new_node;
        list->head->prev = new_node;
        list->head = new_node;
    } else {
        struct Node_pn* current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        new_node->prev = current;
        current->next->prev = new_node;
        current->next = new_node;
    }
    list->size++;
}

void* list_c_remove(struct List_c* list, int index) {
    if (index < 0 || index >= list->size) {
        return NULL;
    }
    struct Node_pn* to_remove;
    if (index == 0) {
        to_remove = list->head;
        list->head = to_remove->next;
        list->head->prev = to_remove->prev;
        to_remove->prev->next = list->head;
    } else {
        struct Node_pn* current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        to_remove = current->next;
        current->next = to_remove->next;
        to_remove->next->prev = current;
    }
    void* value = to_remove->value;
    node_pn_destroy(to_remove);
    list->size--;
    if (list->size == 0) {
        list->head = NULL;
    }
    return value;
}

void list_c_clear(struct List_c* list) {
    while (!list_c_is_empty(list)) {
        list_c_remove(list, 0);
    }
}



// ===================== Stacks =====================

struct Stack* stack_create_empty() {
    struct Stack* new_stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (new_stack != NULL) {
        new_stack->head = NULL;
        new_stack->lenth = 0;
        new_stack->count = 0;
    }
    return new_stack;
}

void stack_push(struct Stack* stack, void* data) {
    if (stack != NULL) {
        struct Node_n* new_node = node_n_create_v(data);
        new_node->next = stack->head;
        stack->head = new_node;
        stack->count++;
        stack->lenth++;
    }
}

struct Node_n* stack_pop(struct Stack* stack) {
    if (stack != NULL && stack->head != NULL) {
        struct Node_n* popped = stack->head;
        stack->head = stack->head->next;
        stack->count--;
        return (struct Node_n*)popped;
    }
    return NULL;
}

void stack_destroy(struct Stack* stack) {
    if (stack != NULL) {
        while (stack->head != NULL) {
            struct Node_n* temp = stack->head;
            stack->head = stack->head->next;
            node_n_destroy(temp);
        }
        free(stack);
    }
}

int stack_is_empty(struct Stack* stack) {
    return (stack == NULL || stack->count == 0);
}

void* stack_peek(struct Stack* stack) {
    if (!stack_is_empty(stack)) {
        return stack->head->value;
    }
    return NULL;
}

int stack_size(struct Stack* stack) {
    if (stack != NULL) {
        return stack->count;
    }
    return 0;
}

void stack_clear(struct Stack* stack) {
    while (!stack_is_empty(stack)) {
        stack_pop(stack);
    }
}

void stack_print(struct Stack* stack) {
    if (stack_is_empty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    struct Node_n* current = stack->head;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", *(int*)current->value);
        current = current->next;
    }
    printf("\n");
}



// ===================== Queues =====================

struct Queue* queue_create_empty() {
    struct Queue* new_queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (new_queue != NULL) {
        new_queue->head = NULL;
        new_queue->tail = NULL;
        new_queue->done = 0;
        new_queue->aloc = 0;
    }
    return new_queue;
}

void queue_destroy(struct Queue* queue) {
    if (queue != NULL) {
        struct Node_n* current = queue->head;
        while (current != NULL) {
            struct Node_n* next = current->next;
            node_n_destroy(current);
            current = next;
        }
        free(queue);
    }
}

void element_process(struct Node_n* node)
{
    node->next=node->next;
};

void queue_advence(struct Queue* queue)
{
    element_process(queue->head);
    queue->done=queue->done++;
    queue->head=queue->head->next;
};

void queue_skip(struct Queue* queue)
{
    queue->done=queue->done++;
    queue->head= (struct Node_n *) queue->head->next;
};

void queue_add_node(struct Queue* queue, struct Node_n* Node)
{
    queue->aloc=queue->aloc++;
    queue->tail->next=(struct Node_n *)Node;
};

void queue_add_value(struct Queue* queue, void* value)
{
    queue->aloc=queue->aloc++;
    queue->tail->next=(struct Node_n *) node_n_create_v(value);
};

void queue_add_outflow(struct Queue* queue, struct Node_n* Node)
{
    queue->aloc=queue->aloc++;
    Node->next=queue->head;
    queue->head=(struct Node_n *)Node;
};

void queue_pop(struct Queue* queue)
{
    queue->aloc=queue->aloc--;
    queue->tail=NULL;
};


void queue_peek(struct Queue* queue, void** value) {
    if (queue == NULL || queue->head == NULL) {
        *value = NULL;
        return;
    }
    *value = queue->head->value;
}

int queue_is_empty(struct Queue* queue) {
    return (queue == NULL || queue->head == NULL);
}

int queue_size(struct Queue* queue) {
    if (queue == NULL) {
        return 0;
    }
    return queue->aloc - queue->done;
}

void queue_clear(struct Queue* queue) {
    if (queue == NULL) {
        return;
    }
    while (!queue_is_empty(queue)) {
        queue_pop(queue);
    }
    queue->head = NULL;
    queue->tail = NULL;
    queue->done = 0;
    queue->aloc = 0;
}

struct Queue* queue_copy(struct Queue* original) {
    if (original == NULL) {
        return NULL;
    }

    struct Queue* new_queue = queue_create_empty();
    struct Node_n* current = original->head;

    while (current != NULL) {
        queue_add_value(new_queue, current->value);
        current = current->next;
    }

    new_queue->done = original->done;
    new_queue->aloc = original->aloc;

    return new_queue;
}





// ===================== Tree =====================

struct tree_bin tree_create_node(struct Node_bin* root_node)
{
    struct tree_bin new_tree;
    new_tree.root=root_node;
    return new_tree;
};

struct tree_bin tree_create_empty()
{
    struct tree_bin new_tree;
    new_tree.root=NULL;
    return new_tree;
};


int tree_count_node(struct Node_bin* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + tree_count_node(node->link[0]) + tree_count_node(node->link[1]);
}

void tree_bin_insert(struct tree_bin* tree, void* value) {
    struct Node_bin* new_node = node_bin_create(value);
    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        struct Node_bin* current = tree->root;
        while (1) {
            int direction = (value > current->value) ? 1 : 0;
            if (current->link[direction] == NULL) {
                current->link[direction] = new_node;
                break;
            }
            current = current->link[direction];
        }
    }
}

struct Node_bin* tree_bin_search_value(struct Node_bin* node, void* search_value) {
    if (node == NULL || node->value == search_value) {
        return node;
    }
    struct node_bin* left_result = tree_bin_search_value(node->link[0], search_value);
    if (left_result != NULL) {
        return left_result;
    }

    return tree_bin_search_value(node->link[1], search_value);
}


void tree_bin_destroy(struct tree_bin* tree) {
    if (tree->root != NULL) {
        tree->root = NULL;
    }
}


void tree_bin_inorder_traversal(struct Node_bin* node) {
    if (node != NULL) {
        tree_bin_inorder_traversal(node->link[0]);
        printf("%p ", node->value);
        tree_bin_inorder_traversal(node->link[1]);
    }
}

void tree_bin_preorder_traversal(struct Node_bin* node) {
    if (node != NULL) {
        printf("%p ", node->value);
        tree_bin_preorder_traversal(node->link[0]);
        tree_bin_preorder_traversal(node->link[1]);
    }
}

void tree_bin_postorder_traversal(struct Node_bin* node) {
    if (node != NULL) {
        tree_bin_postorder_traversal(node->link[0]);
        tree_bin_postorder_traversal(node->link[1]);
        printf("%p ", node->value);
    }
}

int tree_bin_height(struct Node_bin* node){
    if (node == NULL) {
        return 0;
    }
    int left_height = tree_bin_height(node->link[0]);
    int right_height = tree_bin_height(node->link[1]);
    return (left_height > right_height ? left_height : right_height) + 1;
}

