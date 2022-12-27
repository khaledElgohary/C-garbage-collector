//
//  main.c
//  Assignment 4
//
//  Created by Khaled Elgohary on 2022-03-24.
//

#include <stdio.h>
#include "Container.h"
int main(int argc, const char * argv[]) {
    Cont* people=createContainer();
    insert(people,"john");
    insert(people,"michael");
    insert(people,"max");
    insert(people,"khaled");
    insert(people,"ahmed");
    insert(people,"julia");
    insert(people,"maria");
    int len=7;
    int errors=0;
    int passed=0;
    int tests=0;
    printf("Testing typical cases.\n");
    //////////////////////////////////////////////////////////////////////////////////////////////////
    tests++;
    if(size(people)==len){
        printf("test pass for the size of the container.\n");
        passed++;
    }
    else{
        printf("test failed for the size of the container.\n");
        errors++;
        
    }
    tests++;
    printf("searching for john.\n");
    if(contains(people,"john")!=NULL){
        printf("SUCCESS:expected to find john and found it.\n");
        passed++;
    }
    else{
        printf("FAILED:expected to find john and didn't find it.\n");
        errors++;
    }
    tests++;
    printf("searching for max.\n");
    if(contains(people,"max")!=NULL){
        passed++;
        printf("SUCCESS:expected to find max and found it.\n");
    }
    else{
        printf("FAILED:expected to find max and didn't find it.\n");
        errors++;
    }
    tests++;
    printf("searching for maria.\n");
    if(contains(people,"maria")!=NULL){
        passed++;
        printf("SUCCESS:expected to find maria and found it.\n");
    }
    else{
        printf("FAILED:expected to find maria and didn't find it.\n");
        errors++;
    }
    delete(people,"john");
    delete(people,"max");
    delete(people,"maria");
    len=4;
    tests++;
    if(size(people)==len){
        passed++;
        printf("test pass for the size of the container after deletion.\n");
    }
    else{
        printf("test failed for the size of the container after deletion.\n");
        errors++;
    }
    tests++;
    printf("searching for john after deletion.\n");
    if(contains(people,"john")==NULL){
        passed++;
        printf("SUCCESS:expected not to find john after deletion and didn't find it.\n");
    }
    else{
        printf("FAILED:expected not to find after deletion john and found it.\n");
        errors++;
    }
    tests++;
    printf("searching for max after deletion.\n");
    if(contains(people,"max")==NULL){
        passed++;
        printf("SUCCESS:expected not to find max after deletion and didn't find it.\n");
    }
    else{
        printf("FAILED:expected not to find max after deletion and found it.\n");
        errors++;
    }
    tests++;
    printf("searching for maria after deletion.\n");
    if(contains(people,"maria")==NULL){
        passed++;
        printf("SUCCESS:expected to not find maria after deletion and didn't find it.\n");
    }
    else{
        printf("FAILED:expected not to find max after deletion and found it.\n");
        errors++;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    printf("Testing edge cases.\n");
    insert(people,"\n");
    insert(people," ");
    insert(people,"982309283109281029831092380193821098320918302918230-98231098321dlmslakdsmdasaldsdsal,sdadasadsas");
    insert(people,"");
    tests++;
    if(contains(people,"\n")){
        passed++;
        printf("SUCCESS:expected to find new line character and found it.\n");
    }
    else{
        printf("FAILED:expected to find new line character and didn't find it.\n");
        errors++;
    }
    tests++;
    if(contains(people," ")){
        passed++;
        printf("SUCCESS:expected to find space character and found it.\n");
    }
    else{
        printf("FAILED:expected to find space character and didn't find it.\n");
        errors++;
    }
    tests++;
    if(contains(people,"982309283109281029831092380193821098320918302918230-98231098321dlmslakdsmdasaldsdsal,sdadasadsas")){
        passed++;
        printf("SUCCESS:expected to find the long sequence of characters above and found it.\n");
    }
    else{
        printf("FAILED:expected to find the long sequence of characters above and didn't find it.\n");
        errors++;
    }
    tests++;
    if(contains(people,"")){
        passed++;
        printf("SUCCESS:expected to find an empty entry in the container and found it.\n");
    }
    else{
        errors++;
        printf("FAILED:expected to find an empty entry in the container and didn't find it.\n");
    }
    destroyContainer(people);
    tests++;
    if(people==NULL){
        printf("SUCCESS:expected the Container to be destroyed and it its.\n");
        passed++;
    }
    else{
        printf("FAILED:expected the container to be destroyed but it isn't.\n");
        errors++;
    }
    printf("%s %d %s","number of tests used : ",tests,"\n");
    printf("%s %d %s","number of tests passed : ",passed,"\n");
    printf("%s %d %s","number of tests failed : ",errors,"\n");
    }
