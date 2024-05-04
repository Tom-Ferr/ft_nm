
#include <ft_nm.h>

char* ft_strchr(char *str, char c)
{
	while (*str)
    {
	    if (*str == c)
		    return (str);
		str++;
    }
	return (NULL);
}