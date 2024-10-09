//
// Created by arena on 25/05/2024.
//

#ifndef KEY_BUFF_KEY_DICT_H
#define KEY_BUFF_KEY_DICT_H
#define key_dict_size 110
#define key_dict_name_size 16
#endif //KEY_BUFF_KEY_DICT_H
#include "Data_struct.h"


typedef struct key_dict{
    const char name[key_dict_size][key_dict_name_size];
    const short index[key_dict_size];
}key_dict;

extern const key_dict GLOBAL_KEY_DICT;


void key_dict_free(key_dict* kd);
int key_find_index(key_dict a, char* name);
char* key_find_name (key_dict a, int index);
int key_find_relativ_index_from_name(key_dict a, char* name);
int key_find_relativ_index_from_index(key_dict a, int index);
List_ht* struct_log_find_key(List_ht* struct_log, int key);
List_ht* struct_log_create();
void struct_log_append_key(List_ht* spine_list, int key);
void struct_log_append_data(List_ht* spine_list, int key,int data[2]);
void struct_log_printf_keys(List_ht* spine_list);
void struct_log_printf_dates(List_ht* spine_list, int key);
void struct_log_printf(List_ht* spine_list);
void struct_log_fprintf_keys(List_ht* spine_list, FILE* file);
void struct_log_fprintf_dates(List_ht* spine_list, int key, FILE* file);
void struct_log_fprintf(List_ht* spine_list, FILE* file);
void tree_bin_print_post(List_ht* spine_list);
void tree_bin_print_prefix(List_ht* spine_list);
void tree_bin_print_in(List_ht* spine_list);
