//
//  Container.c
//  Assignment 4
//
//  Created by Khaled Elgohary on 2022-03-24.
//
#include <stdlib.h>
#include "Container.h"
#include <string.h>
#include <assert.h>
struct Node{
    char* Data;
    struct Node* next;
}typedef node;

struct Container{
    node *top;
    int node_count;
}typedef Cont;
void checkstate(Cont* c){
    node* curr=c->top;
    while(curr!=NULL){
        assert(contains(c,c->top->Data)!=NULL);
        }
}
Cont* createContainer(){
    Cont* c=(Cont *)malloc(sizeof(Cont));
    c->top=NULL;
    c->node_count=0;
    return c;
}
void insert(Cont* c,char* data){
    //dynamically allocate the data
    //use strcypy to copy the data from the data pointer to the actual struct
    assert(c!=NULL);
    assert(data!=NULL);
    node *link=(node*)malloc(sizeof(node));
    link->Data=(char*)malloc(strlen(data)*sizeof(char));
    strcpy(link->Data,data);
    link->next=c->top;
    c->top=link;
    c->node_count=c->node_count +1;
    assert(c->node_count>0);
    assert(c->top!=NULL);
}
node* contains(Cont* c,char* data){
    node* curr=c->top;
    node* temp=NULL;
    assert(c!=NULL);
    assert(data!=NULL);
    if(c->top==NULL){
        printf("the container is empty,hence the data doesn't exist in the specified container container \n");
    }
    else{
        while(curr!=NULL){
            if(strlen(curr->Data)==strlen(data)){
                for(int i=0;i<strlen(data);i++){
                    if(curr->Data[i]==data[i]){
                        temp=curr;
                    }
                    else{
                        temp=NULL;
                        break;
                    }
                }
                if(temp!=NULL){
                    return temp;
                }
                else{
                    temp=curr;
                    curr=curr->next;
                }
            }
            else{
                curr=curr->next;
            }
        }
    }
    assert(curr==NULL);
    printf("the specified data doesn't exist in the specified container! \n");
    return NULL;
}
void delete(Cont* c,char* data){
    node* temp=NULL;
    int m=c->node_count;
    assert(c!=NULL);
    assert(data!=NULL);
    if(contains(c,data)!=NULL){
        node* curr=c->top;
        if(c->top==contains(c,data)){
            temp=c->top;
            c->top=c->top->next;
            c->node_count=c->node_count -1;
            free(temp);
            assert(c->node_count<m);
        }
        else{
            while(curr->next!=contains(c,data)){
                curr=curr->next;
            }
            node* before_delet=curr;
            node* temp=before_delet->next;
            before_delet->next=temp->next;
            free(temp);
            c->node_count=c->node_count -1;
            assert(c->node_count<m);
        }
    }
    else{
        printf("the data you want to delete is not present in the specified container\n");
    }
}
void clearContainer(Cont* c){
    assert(c!=NULL);
    if(c->top!=NULL){
        node* temp=NULL;
        while(c->top!=NULL){
            temp=c->top;
            c->top=c->top->next;
            free(temp);
        }
        printf("clearance of the container was successfully done\n");
    }
    else{
        printf("the container is already empty\n");
    }
    c->node_count=0;
    assert(c->top==NULL);
}
int size(Cont* c){
    return c->node_count;
}
void destroyContainer(Cont* c){
    assert(c!=NULL);
    clearContainer(c);
    free(c);
    c=NULL;
    assert(c==NULL);
}
node* firstItem(Cont* c){
    if(c->top!=NULL){
        char* string=c->top->Data;
        for(int i=0;i<strlen(string);i++){
            printf("%c",string[i]);
        }
        printf("\n");
    }
    else{
        printf("there is no first item, the container is empty.\n");
    }
    return c->top;
}
node* nextItem(node* curr){
    if(curr->next!=NULL){
        char* string=curr->next->Data;
        for(int i=0;i<strlen(string);i++){
            printf("%c",string[i]);
        }
        printf("\n");
    }
    else{
        printf("there is no next item in this container! \n");
    }
    return curr->next;
}
