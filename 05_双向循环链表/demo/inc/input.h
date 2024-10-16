#ifndef         __INPUT_H__
#define         __INPUT_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include "type.h"

//创建并初始化新节点
P_Node new_node_init(Data_Type data);
bool add_2_list_head(P_Node head, P_Node new);
bool add_2_list_tail(P_Node head, P_Node new);
P_Node del_4_list(P_Node del);
void double_list_mix(P_Node L1, P_Node L2);

#endif