
#include <stdlib.h>
#include "libft.h"

int		main(void)
{
	char *str = "la al fds rewr we";
	char **arr = ft_strsplit(str, ' ');
	int i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (0);
}