#include "../../includes/minishell.h"

char	*ft_cut_tail(char *str)
{
	int		i;
	int		size;
	char	*ret;

	i = 0;
	size = ft_strlen(str);
	ret = malloc(sizeof(char) * size);
	while (i < size - 1)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (free(str), ret);
}