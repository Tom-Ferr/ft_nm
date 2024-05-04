#include <ft_nm.h>

void error_message(char* opt, char* message)
{
    write(STDOUT_FILENO, "ft_nm: ", 7);
    if(opt)
    {
        write(STDOUT_FILENO, "'", 1);
        write(STDOUT_FILENO, opt, ft_strlen(opt));
    }
    write(STDOUT_FILENO, message, ft_strlen(message));
}