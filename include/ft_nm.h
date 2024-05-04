#ifndef FT_NM_H
# define FT_NM_H

# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>   
# include <fcntl.h>   
# include <sys/mman.h>

typedef struct s_options
{
    char** file;
    uint64_t options;
} t_options;

typedef struct s_symbol
{
    char* addr;
    char* type; 
    char* name;
    struct s_symbol* next;
    struct s_symbol* prev;
} t_symbol;

void error_message(char* opt, char* message);
char* ft_strchr(char *str, char c);
size_t	ft_strlen(const char *str);
int	ft_strcmp(char *str1, char *str2);
char* ft_isset(char* str, char* set);

#endif