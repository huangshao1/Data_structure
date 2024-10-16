#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//设计管理结构体；
typedef struct node
{
    int *Enter; //栈的入口地址（堆空间）
    int top;    //栈顶的元素的下标（偏移量）
    int size;   //栈的大小（元素个数）
}Node, *P_Node;

Node stack_init(int size_of_stack)
{
    Node stack;
    stack.Enter = calloc(size_of_stack, sizeof(int));
    stack.top = 0;
    stack.size = size_of_stack;

    return stack;
}

Node push_stack(Node stack, int num)
{
    if(stack.top >= stack.size-1)
    {
        printf("不好意思，栈已满！！\n");
        return stack;
    }
    printf("num:%d\n", num);
    *(stack.Enter+stack.top) = num;
    
    printf("stack.Enter + stack.top:%d\n" , *(stack.Enter + stack.top));

    stack.top++;

    return stack;
}

Node pop_stack(Node stack)
{
    if(stack.top == 0)
    {
        printf("栈为空！！！\n");
        return stack;
    }

    stack.top--;
    int tmp = stack.Enter[stack.top];
    
    printf("%d", tmp);

    return stack;
}

int main(int argc, char const *argv[])
{
    //初始化栈空间
    Node stack = stack_init(10);

    int num = 168;

    //入栈
    while(1)
    {
        stack = push_stack(stack, num%8);
        num = num / 8;
        if(num < 8)
        {
            printf("%d", num);
            break;
        }
    }    

    //出栈
    for (int i = 0; i < 10; i++)
    {
        stack = pop_stack(stack);
        if(stack.top == 0)
        {
            break;
        }
    }

    printf("\n");

    return 0;
}
