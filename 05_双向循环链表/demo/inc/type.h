#ifndef         __TYPE_H__
#define         __TYPE_H__

typedef int Data_Type;

typedef struct node
{
    Data_Type data;
    struct node *Prev;
    struct node *Next;
}Node, *P_Node;

#endif