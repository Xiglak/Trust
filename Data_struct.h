//
// Created by arena on 18/09/2023.
//

#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H




// ===================== Nodes =====================

typedef typedef struct S_Node
{
    void *value;
}Node;
Node* node_create_empty();
Node* node_create(void*);
void  node_destroy(Node*);


typedef struct S_Node_n
{
    void *value;
    struct Node_n *next;
}Node_n;
Node_n* node_n_create_empty();
Node_n* node_n_create_v(void* value);
Node_n* node_n_create_vn(void* value, Node_n* next);
void    node_n_destroy(Node_n*);


typedef struct S_Node_pn
{
    void *value;
    struct Node_pn *prev;
    struct Node_pn *next;
}Node_pn;

Node_pn* node_pn_create_empty();
Node_pn* node_pn_create_v(void* Value);
Node_pn* node_pn_create_vnp(void* Value, Node_pn* prev, Node_pn* next);
void     node_pn_destroy(Node_pn*);


typedef struct S_Node_bin
{
    void* value;
    struct Node_bin* link[2];
}Node_bin;
Node_bin* node_bin_create_empty();
Node_bin* node_bin_create(void* value);
void      node_bin_destroy(Node_bin*);


typedef struct S_Node_xn
{
    int n_branch;
    void* value;
    struct Node_xn** link;
}Node_xn;
Node_xn* node_xn_create_empty(int n_branch);
Node_xn* node_xn_create(int x, void* value);
void     node_xn_destroy(Node_xn*);



// ===================== Lists =====================

typedef struct S_List_h
{
    struct Node_n *head;
}List_h;
List_h* list_h_create_empty();
List_h* list_h_create(void*);
void    list_h_destroy(List_h*);


typedef struct S_List_c
{
    int size;
    struct Node_pn* head;
}List_c;
List_c* list_c_create_empty();
List_c* list_c_create(void*);
void    list_c_append(List_c* list, void* value);
int     list_c_size(List_c* list);
int     list_c_is_empty(List_c* list);
void*   list_c_get(List_c* list, int index);
int     list_c_set(List_c* list, int index, void* value);
void    list_c_insert(List_c* list, int index, void* value);
void*   list_c_remove(List_c* list, int index);
void    list_c_clear(List_c* list);
void    list_c_destroy(List_c*);


typedef struct S_List_ht
{
    struct Node_pn *head;
    struct Node_pn *tail;
}List_ht;
List_ht* list_ht_create_empty();
List_ht* list_ht_create(Node_pn* head,int);
void     list_ht_append_node(List_ht*, struct Node_pn*);
void     list_ht_append_value(List_ht*,void*);
int      list_ht_count_node(List_ht*);
void     list_ht_insert(List_ht* list, void* value, int position);
void     list_ht_destroy(List_ht*);



// ===================== Stacks =====================

typedef struct S_Stack
{
    struct Node_n *head;
    int lenth;
    int count;
}Stack;

Stack* stack_create_empty();
void    stack_push(Stack* stack, void* data);
Node_n* stack_pop(Stack* stack);
int     stack_is_empty(Stack* stack);
void*   stack_peek(Stack* stack);
int     stack_size(Stack* stack);
void    stack_clear(Stack* stack);
void    stack_print(Stack* stack);
void    stack_destroy(Stack*);



// ===================== Queues =====================

typedef struct S_Queue
{
    struct Node_n *head;
    struct Node_n *tail;
    int done;
    int aloc;
}Queue;
Queue* queue_create_empty();
void   queue_advence(Queue*);
void   queue_skip(Queue*);
void   queue_add_node(Queue* queue, struct Node_n* Node);
void   queue_add_value(Queue* queue, void* value);
void   queue_add_outflow(Queue*, struct Node_n*);
void   queue_pop(Queue*);
void   queue_destroy(Queue*);
void   queue_peek(Queue* queue, void** value);
int    queue_is_empty(Queue* queue);
int    queue_size(Queue* queue);
void   queue_clear(Queue* queue);
Queue* queue_copy(Queue* original);



// ===================== Tree =====================


typedef struct S_Tree_bin
{
    struct Node_bin *root;
}Tree_bin;


Tree_bin  tree_create_empty();
Tree_bin  tree_create_node(Node_bin*);
void      tree_bin_destroy(Tree_bin*);
int       tree_count_node(Node_bin* node);
Node_bin* tree_bin_search_value(Node_bin* node, void*);
void      tree_bin_insert(Tree_bin* tree, void* value);
void      tree_bin_inorder_traversal(Node_bin* node);
void      tree_bin_preorder_traversal(Node_bin* node);
void      tree_bin_postorder_traversal(Node_bin* node);
int       tree_bin_height(Node_bin* node);

#endif //UNTITLED8_DATA_STRUCT_H
