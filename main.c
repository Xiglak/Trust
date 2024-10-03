#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <direct.h>
#include <iso646.h>
#include <unistd.h>
#include "data_struct.h"
#include <string.h>
#include "key_dict.h"

float clock_dif(clock_t a,clock_t b){
    return (float)(a-b)/CLOCKS_PER_SEC;
}

void line_printer(FILE* stream,float timing,int key,key_dict a, unsigned int kval) {
    const char* kval_str;
    const char* color_code;
    switch (kval) {
        case 0x8001:
            kval_str = "v";
            color_code = "\033[32m"; // Green
            break;
        case 0x8000:
            kval_str = "_";
            color_code = "\033[33m"; // Yellow
            break;
        case 0x0:
            kval_str = "^";
            color_code = "\033[34m"; // Blue
            break;
        default:
            kval_str = "~~";
            color_code = "\033[31m"; // Red
            break;
    }
    fprintf(stream, " \033[0m[Time: %f] [Key: 0x%X] [Name: %s] [Value: 0x%X] [%s%s\033[0m]\n", timing, key, key_find_name(a,key), kval, color_code, kval_str);
}



void intToStr(int N, char *str) {
    int i = 0;
    int sign = N;
    if (N < 0)
        N = -N;
    while (N > 0) {
        str[i++] = N % 10 + '0';
        N /= 10;
    }
    if (sign < 0) {
        str[i++] = '-';
    }
    str[i] = '\0';

    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }
}



void string_date(char *destination) {
    char date[20];
    time_t now;
    time(&now);
    struct tm *tm_info = localtime(&now);
    strftime(date, sizeof(date), "%Y_%m_%d_%H_%M_%S", tm_info);
    strncpy(destination, date, 19);
    destination[19] = '\0';
}

int main(void) {
    SHORT keyStates_tmp[256];
    char PATH[1024],sub_path[1024],out_path[1024],err_path[1024],date[20];

    if (getcwd(PATH, sizeof(PATH)) != NULL) {
        printf("Current workeyng dir: %s\n", PATH);
    } else {
        perror("getcwd() error");
        return 1;
    }
    string_date(date);
    snprintf(out_path, sizeof(out_path), "%s\\logs\\stdout\\stdout_%s.txt",PATH, date);
    snprintf(err_path, sizeof(err_path), "%s\\logs\\stderr\\stderr_%s.txt",PATH, date);
    FILE *out = fopen(out_path, "w");
    if (out == NULL) {
        perror("Error opening out ");
    }
    printf("Path : %s\n",out_path);
    FILE *err = fopen(err_path,"w");
    if (err == NULL) {
        perror("Error opening err");
    }
    printf("Path : %s\n",err_path);
    fprintf(stdout,"streams test");
    fprintf(out,"streams test");
    fprintf(err,"streams test");
    clock_t time_past;
    clock_t start = clock();
    struct List_ht* struct_log = struct_log_create();
    unsigned short buff[256] = {0};
    unsigned short kval_last;
    int t = 1;
    int print_time_mode=1;// 0: delta, 1: runing_time //
    clock_t time_current = clock();
    while (TRUE){
        for (int key = 0; key < 256; key++) {
            unsigned short kval = GetAsyncKeyState(key);
            if (kval != buff[key]) {
                clock_t time_past = time_current;
                time_current = clock();
                float delta = (float) clock_dif(time_current,time_past);
                float runing_time = (float) clock_dif(time_current,start);
                struct List_ht* struct_maj_node = struct_log_find_key(struct_log,key);
                if(struct_maj_node==NULL){
                    struct_log_append_key(struct_log,&key);
                }
                else {
                    int data[2]={delta,kval};
                    struct_log_append_data(struct_maj_node,key,data);
                }
                if (print_time_mode==0){
                    line_printer(out,delta,key,GLOBAL_KEY_DICT,kval);
                }
                else if (print_time_mode==1){
                    line_printer(out,delta,key,GLOBAL_KEY_DICT,kval);
                    line_printer(stdout,delta,key,GLOBAL_KEY_DICT,kval);
                }
                buff[key] = kval;
            }
        }
        if (buff[0x1b] == 0x8000) {break;}
    }
    struct_log_fprintf(struct_log,out);
    struct_log_fprintf_keys(struct_log,stdout);
    fclose(out);
    fclose(err);
    return 0;
}

