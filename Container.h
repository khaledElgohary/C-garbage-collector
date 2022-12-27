//
//  Container.h
//  Assignment 4
//
//  Created by Khaled Elgohary on 2022-03-24.
//

#ifndef Container_h
#define Container_h

#include <stdio.h>

#endif /* Container_h */

struct Container;
struct Node;
typedef struct Node node;
typedef struct Container Cont;
Cont* createContainer();
void destroyContainer(Cont* c);
void insert(Cont* c,char* data);
void delete(Cont* c,char* data);
void clearContainer(Cont* c);
node* firstItem(Cont* c);
node* nextItem(node *);
node* contains(Cont* c,char* data);
int size(Cont* c);
void checkstate(Cont *c);
