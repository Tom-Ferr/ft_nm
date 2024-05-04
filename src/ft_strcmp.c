#include <ft_nm.h>

int	ft_strcmp(char *str1, char *str2)
{
	if (!str1 || !str2)
		return (-1);
	while (*str1 && *str2)
	{
		if (*str1++ != *str2++)
			return (*(--str1) - *(--str2));
	}
	return (*str1 - *str2);
}