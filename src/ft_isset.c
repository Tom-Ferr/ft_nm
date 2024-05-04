#include <ft_nm.h>

char* ft_isset(char* str, char* set)
{
    char* set_0 = set;

    while (*str)
    {
        while(*set)
        {
            if(*set == *str)
                break ;
            set++;
        }
        if(*set == 0)
        {
            *(str+1) = '\0';
            return(str);
        }
        set = set_0;
        str++;
    }
    return(0);
}