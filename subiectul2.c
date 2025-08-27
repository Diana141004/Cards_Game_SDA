#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct node {

    char nume[50];
    int carti[20];
    struct node * next ;

};

struct node * new_node(char num[],int c[], int n){

    struct node * nou = NULL;
    nou =(struct node *) malloc ( sizeof(struct node) );
    
    strcpy(nou -> nume, num);
    for (int i =0; i< n ;i++) nou -> carti[i]=c[i];
    nou -> next = NULL;

    return nou;
    

}

struct node * insert(struct node * head, char num[], int c[], int n){

    struct node * ptr = head, * nou;
    nou = new_node(num,c,n);

    if(!head) return nou;

    while(ptr -> next) ptr = ptr -> next;
    ptr -> next = nou;

    return head;

}

struct node * loser(struct node * head, int runda){

    struct node * ptr = head, * nod_tinta = NULL;
    int minim = 15;

    while(ptr){

        if(ptr -> carti[runda] < minim){
            minim = ptr -> carti[runda];
            nod_tinta = ptr;
        }

        ptr = ptr -> next;

    }

    return nod_tinta;

}

struct node * delete_node(struct node * head, struct node * to_delete){

    struct node * ptr = head -> next, *prev = head;

    if(head == to_delete){
        prev = prev -> next;
        head -> next = NULL;
        free(head);
        return prev;
    }

    while(ptr -> next ){

        if(ptr == to_delete){
            prev -> next = ptr -> next;
            free(ptr);
            return head;
        }
        prev = ptr;
        ptr = ptr -> next;
    }

    if(ptr == to_delete){
        prev -> next = NULL;
        free(ptr);
        return head;
    }

}

// ------------DISPLAY-------------

void display(struct node *head, int n){

    struct node * ptr = head;

    while(ptr){

        printf("%s ", ptr -> nume);
        for (int i = 0; i<n; i++) printf("%d ", ptr -> carti[i]);
        printf ("\n");
        ptr = ptr -> next;
    }

}

void display_nume(struct node * head){

    struct node * ptr = head;
    while(ptr){
        printf("%s\n", ptr -> nume);
        ptr = ptr -> next;
    }

    printf("\n");

}

int main(){

    int n, comanda, carte[30];
    char cuv[50];
    struct node * lista = NULL;

    printf("Input: ");
    scanf("%d%d", &comanda,&n);

    for (int i= 0; i<n ;i++){

        scanf(" %s", cuv);
        for(int j=0; j<n-1;j++){
            scanf("%d", &carte[j]);
        }
        getchar();

        lista = insert(lista,cuv,carte,n-1);

    }

    switch(comanda){

        case 1:{

            display(lista,n-1);

            break;
        }

        case 2:{

            struct node * sters;

            for ( int i = 0; i< n-1; i++ ){
                sters = loser(lista,i);
                lista = delete_node(lista, sters);
                display_nume(lista);
            }

            break;
        }

    }

}