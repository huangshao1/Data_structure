#include "main.h"

int main(int argc, char const *argv[])
{
    //初始化头节点
    P_Node L1 = new_node_init(0);
    P_Node L2 = new_node_init(0);
    P_Node new = NULL;

    for (int i = 0; i < 10; i++)
    {
        //创建新节点
        new = new_node_init(i);

        //添加新数据
        add_2_list_tail(L1, new);

        new = new_node_init(i+20);

        //添加新数据
        add_2_list_tail(L2, new);
    }

    //合并两个链表
    double_list_mix(L1, L2);
    free(L2);
    L2 = NULL;
    //遍历显示链表
    display_list(L1, false);

    // display_list(L2, false);

    return 0;
}
