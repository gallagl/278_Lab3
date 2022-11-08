// LAB03BST2.c – Lab 03 – Liam, Gallagher

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int main(){
    Tree *myTree = {NULL};

    FILE *ptr = fopen("IDENTSTEST.txt","r");
    if (ptr == NULL){
        printf("Error Reading File");
    }

    int employeeid;
    char passwordbuffer[20];
    int count = 0;

    while (fscanf(ptr,"%d",&employeeid)==1){
        char ch;
        int i = 0;

        printf("%d \t",employeeid);

        do {
            ch = fgetc(ptr);
        } while (ch == ' ');
        do{
            passwordbuffer[i] = ch;
            i++;
            ch = fgetc(ptr); // get next character
        } while (ch != '\r' && ch != '\n');
        passwordbuffer[i] = '\0';
        printf("%s \n",passwordbuffer);

        if (count == 0){
            myTree = initTree(employeeid,passwordbuffer);
            count++;
        }else{
            insert(employeeid,passwordbuffer,myTree->root);
            count++;
        }
    }

    fclose(ptr);

}