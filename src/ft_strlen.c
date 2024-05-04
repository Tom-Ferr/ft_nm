#include <ft_nm.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if(str == NULL)
		return(i);
	while (*str++)
		i++;
	return (i);
}