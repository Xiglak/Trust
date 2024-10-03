//
// Created by arena on 18/09/2023.
//

#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H




// ===================== Nodes =====================

struct Node
{
    void *value;
};
struct Node* node_create_empty();
struct Node* node_create(void*);
void         node_destroy(struct Node*);


struct Node_n
{
    void *value;
    struct Node_n *next;
};
struct Node_n* node_n_create_empty();
struct Node_n* node_n_create_v(void* value);
struct Node_n* node_n_create_vn(void* value,struct Node_n* next);
void           node_n_destroy(struct Node_n*);


struct Node_pn
{
    void *value;
    struct Node_pn *prev;
    struct Node_pn *next;
};
struct Node_pn* node_pn_create_empty();
struct Node_pn* node_pn_create_v(void* Value);
struct Node_pn* node_pn_create_vnp(void* Value,struct Node_pn* prev,struct Node_pn* next);
void            node_pn_destroy(struct Node_pn*);


struct Node_bin
{
    void* value;
    struct Node_bin* link[2];
};
struct Node_bin* node_bin_create_empty();
struct Node_bin* node_bin_create(void* value);
void             node_bin_destroy(struct Node_bin*);


struct Node_xn
{
    int n_branch;
    void* value;
    struct Node_xn** link;
};
struct Node_xn* node_xn_create_empty(int n_branch);
struct Node_xn* node_xn_create(int x, void* value);
void            node_xn_destroy(struct Node_xn*);



// ===================== Lists =====================

struct List_h
{
    struct Node_n *head;
};
struct List_h* list_h_create_empty();
struct List_h* list_h_create(void*);
void           list_h_destroy(struct List_h*);


struct List_c {
    int size;
    struct Node_pn* head;
};
struct List_c* list_c_create_empty();
struct List_c* list_c_create(void*);
void           list_c_append(struct List_c* list, void* value);
int            list_c_size(struct List_c* list);
int            list_c_is_empty(struct List_c* list);
void*          list_c_get(struct List_c* list, int index);
int            list_c_set(struct List_c* list, int index, void* value);
void           list_c_insert(struct List_c* list, int index, void* value);
void*          list_c_remove(struct List_c* list, int index);
void           list_c_clear(struct List_c* list);
void           list_c_destroy(struct List_c*);


struct List_ht
{
    struct Node_pn *head;
    struct Node_pn *tail;
};
struct List_ht* list_ht_create_empty();
struct List_ht* list_ht_create(struct Node_pn* head,int);
void            list_ht_append_node(struct List_ht*, struct Node_pn*);
void            list_ht_append_value(struct List_ht*,void*);
int             list_ht_count_node(struct List_ht*);
void            list_ht_insert(struct List_ht* list, void* value, int position);
void            list_ht_destroy(struct List_ht*);



// ===================== Stacks =====================

struct Stack
{
    struct Node_n *head;
    int lenth;
    int count;
};
struct Stack* stack_create_empty();
void          stack_push(struct Stack* stack, void* data);
struct Node_n*stack_pop(struct Stack* stack);
int           stack_is_empty(struct Stack* stack);
void*         stack_peek(struct Stack* stack);
int           stack_size(struct Stack* stack);
void          stack_clear(struct Stack* stack);
void          stack_print(struct Stack* stack);
void          stack_destroy(struct Stack*);



// ===================== Queues =====================

struct Queue
{
    struct Node_n *head;
    struct Node_n *tail;
    int done;
    int aloc;
};
struct Queue* queue_create_empty();
void          queue_advence(struct Queue*);
void          queue_skip(struct Queue*);
void          queue_add_node(struct Queue* queue, struct Node_n* Node);
void          queue_add_value(struct Queue* queue, void* value);
void          queue_add_outflow(struct Queue*, struct Node_n*);
void          queue_pop(struct Queue*);
void          queue_destroy(struct Queue*);
void          queue_peek(struct Queue* queue, void** value);
int           queue_is_empty(struct Queue* queue);
int           queue_size(struct Queue* queue);
void          queue_clear(struct Queue* queue);
struct Queue* queue_copy(struct Queue* original);



// ===================== Tree =====================


struct tree_bin
{
    struct Node_bin *root;
};


struct tree_bin  tree_create_empty();
struct tree_bin  tree_create_node(struct Node_bin*);
void             tree_bin_destroy(struct tree_bin*);
int              tree_count_node(struct Node_bin* node);
struct Node_bin* tree_bin_search_value(struct Node_bin* node, void*);
void             tree_bin_insert(struct tree_bin* tree, void* value);
void             tree_bin_inorder_traversal(struct Node_bin* node);
void             tree_bin_preorder_traversal(struct Node_bin* node);
void             tree_bin_postorder_traversal(struct Node_bin* node);
int              tree_bin_height(struct Node_bin* node);

#endif //UNTITLED8_DATA_STRUCT_H
