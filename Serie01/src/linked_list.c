/* gcc -Wall -O2 linked_list.c */
/* valgrind ./a.out */

#include <stdio.h>
#include <stdlib.h>

struct elem {
	int pos;
	struct elem *next;
};

static void panic(const char *serror)
{
	printf("%s", serror);
	exit(1);
}

static void *xmalloc(size_t size)
{
	void *ptr;
	if (size == 0)
		panic("Size is 0!\n");
	ptr = malloc(size);
	if (!ptr)
		panic("No mem left!\n");
	return ptr;
}

static void xfree(void *ptr)
{
	if (ptr == NULL)
		panic("Got Null-Pointer!\n");
	free(ptr);
}

static struct elem *init_list(size_t len)
{
	struct elem *head;
	struct elem *prev;

	head = xmalloc(sizeof(struct elem));
	head->pos = 0;
	head->next = NULL;

	// floating reference to previous item
	prev = head;
	for (int i = 1; i < len; i++) {
		struct elem *curr = xmalloc(sizeof(struct elem));
		curr->pos = i;
		curr->next = NULL;
		prev->next = curr;
		prev = curr;
	}

	// link last to first
	prev->next = head;

	return head;
}

static void clean_list(struct elem *head, size_t len)
{
	struct elem *curr = head;
	for (int i = 0; i < len; i++) {
		struct elem *next = curr->next;
		xfree(curr);
		curr = next;
	}
}

static void traverse_list(struct elem *head, int times)
{
	int start = head->pos;
	struct elem *curr = head;

	for (int i = 0; times > 0; i++) {
		printf("(i = %i) -> (%i = pos)\n", i, curr->pos);
		curr = curr->next;
		if (start == curr->pos) times--;
	}
}

int main(void)
{
	struct elem *head = NULL;
	size_t len = 10;

	head = init_list(len);
	traverse_list(head, 2);
	clean_list(head, len);

	return 0;
}

