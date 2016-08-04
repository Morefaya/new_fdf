#include "libft.h"

int	ft_select_charset(char ch, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}
