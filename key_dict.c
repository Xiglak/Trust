//
// Created by arena on 25/05/2024.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "key_dict.h"
#include "Data_struct.h"





const key_dict GLOBAL_KEY_DICT = {
    {
            "Rclick","Lclick","BackSpace", "Tab", "Return", "Shift", "Control", "Alt", "Pause", "CapsLock", "Escape", "Space",
            "PageUp", "PageDown", "End", "Home", "Left", "Up", "Right", "Down", "PrintScreen", "Insert",
            "Delete", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G",
            "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
            "LWin", "RWin", "Apps", "NumPad0", "NumPad1", "NumPad2", "NumPad3", "NumPad4", "NumPad5",
            "NumPad6", "NumPad7", "NumPad8", "NumPad9", "Multiply", "Add", "Subtract", "Decimal", "Divide",
            "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14", "F15",
            "F16", "NumLock", "ScrollLock", "LShift", "RShift", "LControl", "RControl", "LAlt", "RAlt",
            "SemiColon", "Equals", "Comma", "UnderScore", "Period", "Slash", "BackSlash", "RightBrace",
            "LeftBrace"
    },
    {
            1,2,8, 9, 13, 16, 17, 18, 19, 20, 27, 32, 33, 34, 35, 36, 37, 38, 39, 40, 44, 45, 46,
            48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75,
            76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 96, 97, 98,
            99, 100, 101, 102, 103, 104, 105, 106, 107, 109, 110, 111, 112, 113, 114, 115, 116,
            117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 144, 145, 160, 161, 162, 163,
            164, 165, 186, 187, 188, 189, 190, 191, 220, 221, 219
    }
};


void key_dict_free(key_dict* kd) {
    if (kd != NULL) {
        for (int i = 0; i < 256; i++) {
            if (kd->name[i] != NULL) {
                free(kd->name[i]);  
            }
        }
        free(kd);  
    }
}


int key_find_index(key_dict a, char* name) {
    for (int i = 0; i < key_dict_size; i++) {
        if (a.name[i] == name) {
            return a.index[i];
        }
    }
    return -1;
}

char* key_find_name (key_dict a, int index) {
    for (int i = 0; i < key_dict_size; i++) {

        if (a.index[i] == index) {
             char*r =a.name[i];
             return r;
        }
    }
    return "??";
}

int key_find_relativ_index_from_name(key_dict a, char* name) {
    for (int i = 0; i < key_dict_size; i++) {
        int verif=0;
        for (int j = 0; j < key_dict_name_size||a.index[j]; j++) {
            if (a.name[i][j] != name[j]) {
                verif++;
            }
        }
        if (verif == 0) {
            return i;
        }
        return -1;
    }
}

struct List_ht* struct_log_find_key(struct List_ht* spine_list, int key){
    if (spine_list->head==NULL) {
        return NULL;
    }
    struct Node_pn* struct_traverse = spine_list->head;
    while ((int)((struct List_ht*)(struct_traverse->value))->head->value != key){
        if(struct_traverse->next==NULL){
            return NULL;
        }
        struct_traverse=struct_traverse->next;
    }
    return struct_traverse->value;
}

struct List_ht* struct_log_create(){
    struct List_ht* spine_list = list_ht_create_empty();
    return spine_list;
}

void struct_log_append_key(struct List_ht* spine_list, int key){
    list_ht_append_value(spine_list,list_ht_create_empty());
    list_ht_append_value((struct List_ht*)(spine_list->tail->value),key);
}

void struct_log_append_data(struct List_ht* spine_list, int key,int data[2]){
    struct List_ht* key_log_list = struct_log_find_key(spine_list,key);
    list_ht_append_value(key_log_list,data);
}

void struct_log_printf_keys(struct List_ht* spine_list){
    struct Node_pn* key_node = spine_list->head;
    printf("struct_log_printf_keys keys :\n");
    while (key_node != NULL) {
        printf("%s\n",key_find_name(GLOBAL_KEY_DICT,((struct List_ht*)(key_node->value))->head->value));
        key_node = key_node->next;
    }
}

void struct_log_printf_data(struct List_ht* spine_list, int key){
    struct Node_pn* key_node = struct_log_find_key(spine_list,key)->head;
    while (key_node != NULL) {
        printf("%f",key_node->value);
        key_node = key_node->next;
    }
}

void struct_log_printf(struct List_ht* spine_list){
    for (int i=0;i<key_dict_size;i++){
        printf("%s",key_find_name(GLOBAL_KEY_DICT,i));
        struct_log_printf_data(spine_list,i);
        printf("\n");
    }
}

void struct_log_fprintf_keys(struct List_ht* spine_list, FILE* file){
    struct Node_pn* key_node = spine_list->head;
    while (key_node != NULL) {
        fprintf(file,"%s",key_find_name(GLOBAL_KEY_DICT,((struct List_ht*)(key_node->value))->head->value));
        key_node = key_node->next;
    }
}

void struct_log_fprintf_data(struct List_ht* spine_list, int key, FILE* file){
    struct Node_pn* key_node = struct_log_find_key(spine_list,key)->head;
    fprintf(file,"%s",key_find_name(GLOBAL_KEY_DICT,key));
    while (key_node != NULL) {
        //fprintf(file,"%f",(float)key_node->value[1]);
        key_node = key_node->next;
    }
}

void struct_log_fprintf(struct List_ht* spine_list, FILE* file){
    for (int i=0;i<key_dict_size;i++){
        fprintf(file,"%s",key_find_name(GLOBAL_KEY_DICT,i));
        struct_log_fprintf_data(spine_list,i,file);
        fprintf(file,"\n");
    }
}




