#ifndef         __OUTPUT_H__
#define         __OUTPUT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include "type.h"

bool display_list(P_Node head, bool R_L);
P_Node find_4_list(P_Node head, Data_Type data);

#endif