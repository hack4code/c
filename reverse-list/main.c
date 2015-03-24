#include <stdio.h>

struct list_node {
	struct list_node *next;
};


struct list_node * reverse_list(struct list_node *head) {
	struct list_node *p, *q, *s;

	p = head;
	q = NULL;

	while (p->next) {
		s = p->next;
		p->next = q;
		q = p;
		p = s;
	}

	return p;
}
