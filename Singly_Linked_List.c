#include <stdlib.h>
#include <stdio.h>
#include <string.h> // memcmp()
/*
    single linked list
*/
struct data
{
    int a;
    char *c;
};
struct LinkedList{
    struct data *staff;
    struct LinkedList *next;
 };

typedef struct LinkedList *node; 
/*
* Tao mot node moi chua duoc dua vao list
*/
node CreateNode(struct data *value)
{
    node tmp;
    tmp = (node)malloc(sizeof(node));
    tmp -> staff = value;
    tmp -> next  = NULL;
    return tmp;
}
/*
~~~~~~~~~~~~~~~ Add to HEAD ~~~~~~~~~~~~~~~~~~~~~~
1. Neu head = null 
=> chua co gia tri trong list 
-> gan value = head
2. Khoi tao node moi
-> cho tmp->next = head
-> dat tmp lam head moi 
*/
node AddHead(node head,struct data *value)
{
    node NewNode = CreateNode(value);
    if(head == NULL){
        head = NewNode;
    }
    else{
        NewNode->next = head;
        head = NewNode;
    }
    return head;
}
/*
~~~~~~~~~~~~~~~~Add to Tail~~~~~~~~~~~~~~~~~~~~~~~~
*1. Neu head = NULL => chua co gia tri nao trong list
*-> gan value = head
*2. Neu head != NULL 
*-> duyet den node cuoi cung(END) 
*-> dat New.next = END
*/
node AddTail(node head, struct data *value)
{
    node NewNode = CreateNode(value);
    node tmp = head;
    if(head == NULL){
        head = NewNode;
    }
    else{
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = NewNode;
    }
    return head;
}
/*
~~~~~~~~~~~~ Delete the Head~~~~~~~~~~~~~
*1.if head = Null -> print that empty
*2.if head != Null -> head = head.next
*/
node DelHead(node head)
{
    if(head == NULL)
    {
        printf("Linked list empty\n");
    }
    else
    {
        head = head->next;
    }
    return head;
}
/*
~~~~~~~~~~~~ Delete the Tail~~~~~~~~~~~~~
*1.if head = Null -> print that empty
*2.if head != Null -> come to node behind 
*the tail and assign *next = null
*/
node DelTail(node head)
{
    node tmp = head;
    if(head == NULL)
    {
        printf("Linked list empty\n");
    }
    else
    {
        while(tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = NULL;
    }
    return head;
}
/*~~~~~~~~~~Check_exist~~~~~~~~~~~
 * traverse data and then
 * use memory compare check data exist
 */
void CheckExist(node head, struct data *value)
{
    node tmp;
    int err;
    for(tmp = head; tmp != NULL; tmp = tmp->next )
    {
        err = memcmp(tmp->staff,value,sizeof(struct data));
        if(err == 0)
        {
            break;
        }
    }
    if(err == 0)
    {
        printf("Data %d %s exist!\n",tmp->staff->a,tmp->staff->c);
    }
    else{
        printf("Data %d %s NOT exist!\n",value->a,value->c);
    }
}
/*
*show all list
*/
void show(node head)
{
    printf("~~~~~start~~~~\n");
    node tmp;
    for(tmp = head; tmp!= NULL; tmp = tmp->next)
    {
        printf("%d %s \n",tmp->staff->a,tmp->staff->c);
    }
    printf("~~~~~end~~~~~\n");
}
int main(void)
{
    struct data d1 = {1,"a"};
    struct data d2 = {2,"b"};
    struct data d3 = {3,"c"};
    struct data d4 = {4,"d"};

    node head = CreateNode(&d1);
    show(head);
    head = AddHead(head,&d2);
    show(head);
    CheckExist(head,&d2);
    head = DelTail(head);
    show(head);
    head = AddTail(head,&d3);
    show(head);
    head = DelHead(head);
    show(head); 
    CheckExist(head,&d4);
}