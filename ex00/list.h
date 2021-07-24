#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	struct s_list	*next;
	long			key;
	char			*value;
}				t_list;

/* adds new elem with key and value to the list.
 * if li is null, creates the list */
void	li_create_append(t_list **li, long key, char *value);

/* frees the entire list, including the value strings */
void	li_free(t_list *li);

/* walks over the list and runs func for every element */
void	li_foreach(t_list *li, void (*func)(t_list *li));

/* prints list to stdout */
void	li_display(t_list *li);

#endif /* LIST_H */
