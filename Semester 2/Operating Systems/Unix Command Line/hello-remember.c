#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char* name;
    struct node* next;
};

struct node* add(struct node* head, char* name) {
    struct node* n;
    struct node* p;

    n = (struct node*)malloc(sizeof(struct node));
    n->name = (char*)malloc(strlen(name)+1);
    strcpy(n->name, name);
    n->next = NULL;

    if(head == (struct node*) NULL) {
        return n;
    } 

    p = head;
    while(p->next != (struct node*) NULL) {
        p = p->next;
    }
    p->next = n;
    return head;
}

int known(struct node* head, char* name) {
    struct node* p;

    p = head;
    while(p != NULL && strcmp(p->name, name) != 0) {
        p = p->next;
    }
    return p != NULL;
}

void clear(struct node* head) {
    if(head == NULL) {
        return;
    }
    clear(head->next);
    free(head->name);
    free(head);
}

int main(int argc, char** argv) {
    char name[64];
    struct node* head = NULL;
    name[0] = 0;
    while(scanf("%s", name) == 1) {
        if(known(head, name)) {
            printf("Still around %s, eh?\n", name);
        }
        else {
            head = add(head, name);
            printf("Hello %s\n", name);
        }
    }
    clear(head);
    return 0;
}
