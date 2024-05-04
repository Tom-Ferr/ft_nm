
#include <ft_nm.h>

static void help(int i)
{
    write(STDOUT_FILENO, "Usage: ft_nm", 12);
    write(STDOUT_FILENO, " [options] [files...]\nValid options are:\n", 41);

    write(STDOUT_FILENO, "-help\t\tDisplay this summary\n", 28);
    write(STDOUT_FILENO, "-a\t\tDisplay debugger-only symbols\n", 34);
    write(STDOUT_FILENO, "-g\t\tDisplay only external symbols\n", 34);
    write(STDOUT_FILENO, "-u\t\tDisplay only undefined symbols\n", 35);
    write(STDOUT_FILENO, "-r\t\tReverse the sense of the sort\n", 34);
    write(STDOUT_FILENO, "-p\t\tDo not sort the symbols\n", 28);
    exit(i);
}

static t_options options_parser(char* argv[], int argc)
{
    int i = 1;
    t_options ret;
    ret.file = NULL;
    ret.options = 0;
    char flags[6] = "agurp";
    char* wrg;

    while(i < argc)
    {
        if(!ft_strcmp(*(argv + i), "-help") && ret.file == NULL)
            help(0);
        else if((**(argv + i) == '-' && ret.file == NULL) && !(wrg = ft_isset(*(argv + i) + 1, flags)))
        {
            if(ft_strchr(*(argv + i), 'a'))
                ret.options |= 0b01;
            if(ft_strchr(*(argv + i), 'g'))
                ret.options |= 0b11;
            if(ft_strchr(*(argv + i), 'u'))
                ret.options |= 0b111;
            if(ft_strchr(*(argv + i), 'r'))
                ret.options |= 0b01000;
            if(ft_strchr(*(argv + i), 'p'))
                ret.options |= 0b11000;
        }
        else if(**(argv + i) != '-' && ret.file == NULL)
            ret.file = argv + i;
        else if(ret.file == NULL)
        {
            error_message(wrg, "' is an invalid option.\n\n");
            help(1);
        }
        i++;
    }
    return(ret);
}

int main(int argc, char* argv[])
{
    t_options op;
    int fd;
    char null_file[6] = "a.out";
    char* file;

    op = options_parser(argv, argc);

    if(op.file == NULL)
       file = (char*)null_file;
    else
        file = *op.file;
    fd = open(file, O_RDONLY);
    if(fd == -1)
    {
        error_message(file, "': No such file\n");
        return(1);
    }

    close(fd);
    return(0);
}