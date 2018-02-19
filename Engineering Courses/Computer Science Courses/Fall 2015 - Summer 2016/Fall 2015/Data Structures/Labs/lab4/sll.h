//
//  sll.h
//  Lab4
//
//  Created by Todd Kulesza on 1/25/14.
//

#ifndef Lab4_sll_h
#define Lab4_sll_h

struct sll;
struct sll_node;

struct sll* sll_create();
void sll_free(struct sll *list);

void sll_push(struct sll *list, char value);
char sll_pop(struct sll *list);
char sll_top(struct sll *list);

#endif