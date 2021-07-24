#include "list.h"

int main()
{
	t_list * li;
	li_create_append(&li, 0, "Abi");
	li_create_append(&li, 1, "Job");
	li_create_append(&li, 2, "Will");
	li_display(li);
	li_free(li);
	return (0);
}
