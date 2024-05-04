FILES			=	ft_strchr.c error_message.c ft_strlen.c ft_strcmp.c ft_isset.c

SRCDIR			= 	src/

SRCS			= 	$(addprefix $(SRCDIR), $(FILES)) main.c

OBJS			= 	${SRCS:.c=.o}

HEADS			=	ft_nm.h

INC				= 	./include/

DEPS			= 	$(addprefix ${INC}, $(HEADS))

NAME			= 	ft_nm

CXX				=	clang

AR				=	ar -rcs

CXXFLAGS		= 	-g -Wall -Wextra -Werror

INCLUDE 		= 	-I${INC}

SANITIZE 		= 	-fsanitize=address

%.o: %.c		
				${CXX} ${CXXFLAGS} ${INCLUDE} -c $< -o $@

$(NAME):		${OBJS} $(DEPS)
				${CXX} ${CXXFLAGS} ${SANITIZE} ${OBJS} ${INCLUDE} -o ${NAME}

all:			${NAME}

clean:
				rm -f ${OBJS}

fclean:			clean
				rm -f ${NAME}
re:				fclean all

.PHONY:			all clean fclean re