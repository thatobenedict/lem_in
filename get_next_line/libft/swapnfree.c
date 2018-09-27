#include "libft.h"

void			swapnfree(char **var, char *new_val)
{
	char	*tmp;

	free(*var);
	tmp = new_val;
	*var = tmp;
}
