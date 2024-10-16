#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//节点设计
typedef struct stack
{
    struct book
    {
        char Name[32];
        float Price;
        int Num;
    }Book;

    struct stack *Next;
}Node, *P_Node;
int main(int argc, char const *argv[])
{
    Node data;
    P_Node p = calloc(1, sizeof(Node));

    strncpy(data.Book.Name, "xiao", 32);
    data.Book.Price = 32.68;
    data.Book.Num = 1024;

    printf("%s\t%d\t%f\n", data.Book.Name, data.Book.Num, data.Book.Price);

    strncpy(p->Book.Name, "xiao", 32);
    p->Book.Price = 32.68;
    p->Book.Num = 1024;

    printf("%s\t%d\t%f\n", p->Book.Name, p->Book.Num, p->Book.Price);

    return 0;
}
