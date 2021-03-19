#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* your code here */
    if (head == NULL || head->next == NULL) {
    	return 0;
    }
    /* 龟兔赛跑 */
    node *hare = head->next;
    node *tortoise = head;
    while (hare != NULL) {
    	if (tortoise == hare) {
    		return 1;
    	}
    	if (hare->next == NULL) {
    		return 1;
    	}
    	hare = hare->next->next;
    	tortoise = tortoise->next;
    }
    return 0;
}