//
// Created by renau on 05/09/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "basics.h"


int Node_test(int verbose) {
    struct Node_n* test=node_n_create();
    if (test==NULL) {
        if(verbose) {
            printf("Node creation failed\n");
        }
        return 1;
    }
    else {
        if(verbose) {
            printf("Node created\n");
        }
        int witness = rand();
        test->data=witness;
        if ((int)test->data != witness) {
            if(verbose) {
                printf("Node data mismatch\n");
            }
            return 1;
        }
        else {
            if(verbose) {
            printf("Node data match\n");
        }
            return 0;
        }
    }
}

void test_basics() {
    printf("Testing basics start\n");
    srand( time( NULL ) );
    printf("Testing struct Node\n");
    if(1==Node_test(0)){
        Node_test(1);
        printf("Testing basics end\n");
    };
    if(1==Node_test(0)){
        Node_test(1);
        printf("Testing basics end\n");
    };
};