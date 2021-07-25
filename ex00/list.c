#include "list.h"

#include <stdlib.h>

/* adds new elem with key and value to the list.
 * If li is null, creates the list. Notice that t_list is 
 * a double pointer, because othewise you wouldn't be able
 * to create the list.
 * also DOES NOT check if malloc returns NULL pointer */
void	li_create_append(t_list **li, long key, char *value)
{
	t_list	*n;
	t_list	*cur;

	n = malloc(sizeof(t_list));
	n->key = key;
	n->value = value;
	n->next = (t_list *)0;
	if (*li == (t_list *)0)
	{
		*li = n;
		return ;
	}
	cur = *li;
	while (cur->next != (t_list *)0)
	{
		cur = cur->next;
	}
	cur->next = n;
}

/* frees the entire list, including the value strings. */
/* TODO: fix*/
void	li_free(t_list *li)
{
	t_list	*cur;
	t_list	*t;

	cur = li;
	while (cur != (t_list *)0)
	{
		t = cur->next;
		free(cur->value);
		free(cur);
		cur = t;
	}
}

/* walks over the list and runs func for every element. */
void	li_foreach(t_list *li, void (*func)(t_list *li))
{
	t_list	*cur;

	cur = li;
	while (cur != (t_list *)0)
	{
		func(cur);
		cur = cur->next;
	}
}
