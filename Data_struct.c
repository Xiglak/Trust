//
// Created by arena on 18/09/2023.
//
#include "Data_struct.h"
#include <stdio.h>
#include <stdlib.h>

// ===================== Nodes =====================


// Node //

Node* node_create_empty() {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node != NULL) {
        new_node->value = NULL;
    }
    return new_node;
}

Node* node_create(void* value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node != NULL) {
        new_node->value = value;
    }
    return new_node;
}

void node_destroy(Node* node) {
    if (node != NULL) {
        free(node);
    }
}


// Node_n //

Node_n* node_n_create_empty() {
    Node_n* new_node = (Node_n*)malloc(sizeof(Node_n));
    if (new_node != NULL) {
        new_node->value = NULL;
        new_node->next = NULL;
    }
    return new_node;
}

Node_n* node_n_create_v(void* value) {
    Node_n* new_node = (Node_n*)malloc(sizeof(Node_n));
    if (new_node != NULL) {
        new_node->value = value;
        new_node->next = NULL;
    }
    return new_node;
}

Node_n* node_n_create_vn(void* value, Node_n* next) {
    Node_n* new_node = (Node_n*)malloc(sizeof(Node_n));
    if (new_node != NULL) {
        new_node->value = value;
        new_node->next = next;
    }
    return new_node;
}

void node_n_destroy(Node_n* node) {
    if (node != NULL) {
        free(node);
    }

}


// Node_pn //

Node_pn* node_pn_create_empty() {
    Node_pn* new_node = (Node_pn*)malloc(sizeof(Node_pn));
    if (new_node != NULL) {
        new_node->value = NULL;
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    return new_node;
}

Node_pn* node_pn_create_v(void* value) {
    Node_pn* new_node = (Node_pn*)malloc(sizeof(Node_pn));
    if (new_node != NULL) {
        new_node->value = value;
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    return new_node;
}

Node_pn* node_pn_create_vnp(void* value, Node_pn* prev, Node_pn* next){
    Node_pn* new_node = (Node_pn*)malloc(sizeof(Node_pn));
    if (new_node != NULL) {
        new_node->value=value;
        new_node->prev= prev;
        new_node->next= next;
    }
    return new_node;
};

void node_pn_destroy(Node_pn* node) {
    if (node != NULL) {
        free(node);
    }
}


// node_bin //

Node_bin* node_bin_create_empty(){
    Node_bin* new_node = (Node_bin*)malloc(sizeof(Node_bin));
    if (new_node != NULL) {
        new_node->value = NULL;
    }
    return new_node;
}

Node_bin* node_bin_create(void* value){
    Node_bin* new_node = (Node_bin*)malloc(sizeof(Node_bin));
    if (new_node != NULL) {
        new_node->value = value;
        new_node->link[0]=NULL;
        new_node->link[1]=NULL;
    }
    return new_node;
}

void node_bin_destroy(Node_bin* node) {
    if (node != NULL) {
        free(node);
    }
}


// node_xn //

Node_xn* node_xn_create_empty(int x){
    Node_xn* new_node = (Node_xn*)malloc(x * sizeof(Node_xn*));
    if (new_node != NULL) {
        new_node->value = NULL;
        new_node->n_branch = x;
        new_node->link = (Node_xn**)malloc(x * sizeof(Node_xn*));
    }
    return new_node;
}

Node_xn* node_xn_create(int x, void* value){
    Node_xn* new_node = (Node_xn*)malloc(x * sizeof(Node_xn*));
    if (new_node != NULL) {
        new_node->value = value;
        new_node->n_branch = x;
        new_node->link = (Node_xn**)malloc(x * sizeof(Node_xn*));
    }
    return new_node;
}

void node_xn_destroy(Node_xn* node) {
    if (node != NULL) {
        free(node->link);
        free(node);
    }
}



// ===================== Lists =====================

// List_h //
List_h* list_h_create_empty() {
    List_h* new_list = (List_h*)malloc(sizeof(List_h));
    if (new_list != NULL) {
        new_list->head = NULL;
    }
    return new_list;
}

List_h* list_h_create(void* value) {
    List_h* new_list = list_h_create_empty();
    if (new_list != NULL) {
        new_list->head = node_n_create_v(value);
    }
    return new_list;
}

void list_h_destroy(List_h* list) {
    if (list != NULL) {
        Node_n* current = list->head;
        while (current != NULL) {
             Node_n* next = current->next;
            node_n_destroy(current);
            current = next;
        }
        free(list);
    }
}


// List_ht //

List_ht* list_ht_create_empty(){
    List_ht* mylist=malloc(sizeof(List_ht));
    mylist->head=NULL;
    mylist->tail=NULL;
    return mylist;
};

List_ht* list_ht_create(Node_pn* head,int lenght){
    List_ht* mylist = malloc(sizeof(List_ht));
    if (head==NULL) {
        mylist->head = NULL;
        mylist->tail = NULL;
    }
    else {
        mylist->head = head;
        mylist->tail = mylist->head;
        if (lenght<0) {
            mylist->head=NULL;
            mylist->tail=NULL;
        }
        else {
            for(; 0!=lenght; lenght--)
            {
                if ((Node_pn*)(mylist->tail)->next!=NULL) {
                    mylist->tail= mylist->tail->next;
                }
            };
        }
    }
    return mylist;
};

void list_ht_append_node(List_ht* list,  Node_pn* node){
    node->prev=list->tail;
    node->next=NULL;
    if (list->tail!=NULL) {
        list->tail->next=node;
        list->tail=list->tail->next;
    }
    else {
        list->tail=node;
    }
};

void list_ht_append_value(List_ht* list, void* value){
     Node_pn *node = node_pn_create_v(value);
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

void list_ht_insert(List_ht* list, void* value, int position) {
     Node_pn* new_node = node_pn_create_v(value);
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
         Node_pn* current = list->head;
        int i = 0;
        while (current != NULL && i < position) {
            current = current->next;
            i++;
        }
        if (current != NULL) {
            new_node->next = current->next;
            new_node->prev = current;
            if (current->next != NULL) {
                (current->next)->prev = new_node;
            }
            else {
                list->tail = new_node;
            }
            current->next = new_node;
        }
    }
}

int list_ht_count_node(List_ht* list) {
    if (list->head!=NULL) {
        int i = 1;
         Node_pn* cur=list->head;
        while (cur->next!=NULL) {
            cur=cur->next;
            i++;
        }
        return i;
    }
    return 0;
}

void list_ht_destroy(List_ht* list) {
    if (list != NULL) {
         Node_pn* current = list->head;
        while (current != NULL) {
             Node_pn* next = current->next;
            node_pn_destroy(current);
            current = next;
        }
        free(list);
    }
}


// List_c //

List_c* list_c_create_empty() {
     List_c* new_list = malloc(sizeof(List_c));
    new_list->size = 0;
    new_list->head = NULL;
    return new_list;
}

List_c* list_c_create(void* value) {
    List_c* new_list = malloc(sizeof(List_c));
    if (new_list != NULL) {
        new_list->head = node_pn_create_v(value);
        new_list->size = 1;
    }
    return new_list;
}

void list_c_append(List_c* list, void* value) {
    Node_pn* new_node = node_pn_create_v(value);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node_pn* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
    list->size++;
}

void list_c_destroy(List_c* list) {
    if (list != NULL) {
        Node_pn* current = list->head;
        while (current != NULL) {
            Node_pn* next = current->next;
            node_pn_destroy(current);
            current = next;
        }
        free(list);
    }
}

int list_c_size(List_c* list) {
    return list->size;
}

int list_c_is_empty(List_c* list) {
    return (list->size == 0);
}

void* list_c_get(List_c* list, int index) {
    if (index < 0 || index >= list->size) {
        return NULL;
    }
    Node_pn* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}

int list_c_set(List_c* list, int index, void* value) {
    if (index < 0 || index >= list->size) {
        return 0;
    }
    Node_pn* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->value = value;
    return 1;
}

void list_c_insert(List_c* list, int index, void* value) {
    if (index < 0 || index > list->size) {
        return;
    }
    if (index == list->size) {
        list_c_append(list, value);
        return;
    }
    Node_pn* new_node = node_pn_create_v(value);
    if (index == 0) {
        new_node->next = list->head;
        new_node->prev = list->head->prev;
        list->head->prev->next = new_node;
        list->head->prev = new_node;
        list->head = new_node;
    } else {
        Node_pn* current = list->head;
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

void* list_c_remove(List_c* list, int index) {
    if (index < 0 || index >= list->size) {
        return NULL;
    }
    Node_pn* to_remove;
    if (index == 0) {
        to_remove = list->head;
        list->head = to_remove->next;
        list->head->prev = to_remove->prev;
        to_remove->prev->next = list->head;
    } else {
        Node_pn* current = list->head;
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

void list_c_clear(List_c* list) {
    while (!list_c_is_empty(list)) {
        list_c_remove(list, 0);
    }
}



// ===================== Stacks =====================

Stack* stack_create_empty() {
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    if (new_stack != NULL) {
        new_stack->head = NULL;
        new_stack->lenth = 0;
        new_stack->count = 0;
    }
    return new_stack;
}

void stack_push(Stack* stack, void* data) {
    if (stack != NULL) {
        Node_n* new_node = node_n_create_v(data);
        new_node->next = stack->head;
        stack->head = new_node;
        stack->count++;
        stack->lenth++;
    }
}

Node_n* stack_pop(Stack* stack) {
    if (stack != NULL && stack->head != NULL) {
        Node_n* popped = stack->head;
        stack->head = stack->head->next;
        stack->count--;
        return (Node_n*)popped;
    }
    return NULL;
}

void stack_destroy(Stack* stack) {
    if (stack != NULL) {
        while (stack->head != NULL) {
            Node_n* temp = stack->head;
            stack->head = stack->head->next;
            node_n_destroy(temp);
        }
        free(stack);
    }
}

int stack_is_empty(Stack* stack) {
    return (stack == NULL || stack->count == 0);
}

void* stack_peek(Stack* stack) {
    if (!stack_is_empty(stack)) {
        return stack->head->value;
    }
    return NULL;
}

int stack_size(Stack* stack) {
    if (stack != NULL) {
        return stack->count;
    }
    return 0;
}

void stack_clear(Stack* stack) {
    while (!stack_is_empty(stack)) {
        stack_pop(stack);
    }
}

void stack_print(Stack* stack) {
    if (stack_is_empty(stack)) {
        printf("Stack is empty\n");
        return;
    }

    Node_n* current = stack->head;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", *(int*)current->value);
        current = current->next;
    }
    printf("\n");
}



// ===================== Queues =====================

Queue* queue_create_empty() {
    Queue* new_queue = (Queue*)malloc(sizeof(Queue));
    if (new_queue != NULL) {
        new_queue->head = NULL;
        new_queue->tail = NULL;
        new_queue->done = 0;
        new_queue->aloc = 0;
    }
    return new_queue;
}

void queue_destroy(Queue* queue) {
    if (queue != NULL) {
        Node_n* current = queue->head;
        while (current != NULL) {
            Node_n* next = current->next;
            node_n_destroy(current);
            current = next;
        }
        free(queue);
    }
}

void element_process(Node_n* node)
{
    node->next=node->next;
};

void queue_advence(Queue* queue)
{
    element_process(queue->head);
    queue->done=queue->done++;
    queue->head=queue->head->next;
};

void queue_skip(Queue* queue)
{
    queue->done=queue->done++;
    queue->head= (Node_n *) queue->head->next;
};

void queue_add_node(Queue* queue,  Node_n* Node)
{
    queue->aloc=queue->aloc++;
    queue->tail->next=(Node_n *)Node;
};

void queue_add_value(Queue* queue, void* value)
{
    queue->aloc=queue->aloc++;
    queue->tail->next=(Node_n *) node_n_create_v(value);
};

void queue_add_outflow(Queue* queue,  Node_n* Node)
{
    queue->aloc=queue->aloc++;
    Node->next=queue->head;
    queue->head=(Node_n *)Node;
};

void queue_pop(Queue* queue)
{
    queue->aloc=queue->aloc--;
    queue->tail=NULL;
};


void queue_peek(Queue* queue, void** value) {
    if (queue == NULL || queue->head == NULL) {
        *value = NULL;
        return;
    }
    *value = queue->head->value;
}

int queue_is_empty(Queue* queue) {
    return (queue == NULL || queue->head == NULL);
}

int queue_size(Queue* queue) {
    if (queue == NULL) {
        return 0;
    }
    return queue->aloc - queue->done;
}

void queue_clear(Queue* queue) {
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

Queue* queue_copy(Queue* original) {
    if (original == NULL) {
        return NULL;
    }
    Queue* new_queue = queue_create_empty();
    Node_n* current = original->head;
    while (current != NULL) {
        queue_add_value(new_queue, current->value);
        current = current->next;
    }
    new_queue->done = original->done;
    new_queue->aloc = original->aloc;
    return new_queue;
}





// ===================== Tree =====================

Tree_bin tree_create_node(Node_bin* root_node)
{
    Tree_bin new_tree;
    new_tree.root=root_node;
    return new_tree;
};

Tree_bin tree_create_empty()
{
    Tree_bin new_tree;
    new_tree.root=NULL;
    return new_tree;
};


int tree_count_node(Node_bin* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + tree_count_node(node->link[0]) + tree_count_node(node->link[1]);
}

void tree_bin_insert(Tree_bin* tree, void* value) {
    Node_bin* new_node = node_bin_create(value);
    if (tree->root == NULL) {
        tree->root = new_node;
    } else {
        Node_bin* current = tree->root;
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

Node_bin* tree_bin_search_value(Node_bin* node, void* search_value) {
    if (node == NULL || node->value == search_value) {
       return node;
    }
    Node_bin * left_result = tree_bin_search_value(node->link[0], search_value);
    if (left_result != NULL) {
       return left_result;
    }
    return tree_bin_search_value(node->link[1], search_value);
}


void tree_bin_destroy(Tree_bin* tree) {
    if (tree->root != NULL) {
        tree->root = NULL;
    }
}


void tree_bin_inorder_traversal(Node_bin* node) {
    if (node != NULL) {
        tree_bin_inorder_traversal(node->link[0]);
        printf("%p ", node->value);
        tree_bin_inorder_traversal(node->link[1]);
    }
}

void tree_bin_preorder_traversal(Node_bin* node) {
    if (node != NULL) {
        printf("%p ", node->value);
        tree_bin_preorder_traversal(node->link[0]);
        tree_bin_preorder_traversal(node->link[1]);
    }
}

void tree_bin_postorder_traversal(Node_bin* node) {
    if (node != NULL) {
        tree_bin_postorder_traversal(node->link[0]);
        tree_bin_postorder_traversal(node->link[1]);
        printf("%p ", node->value);
    }
}

int tree_bin_height(Node_bin* node){
    if (node == NULL) {
        return 0;
    }
    int left_height = tree_bin_height(node->link[0]);
    int right_height = tree_bin_height(node->link[1]);
    return (left_height > right_height ? left_height : right_height) + 1;
}

