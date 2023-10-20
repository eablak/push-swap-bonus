NAME        := push_swap

BONUS = checker

CC        := gcc
FLAGS    := -Wall -Wextra -Werror -g

SRCS        :=      src/main.c \
 					libft/ft_tolower.c \
					libft/ft_substr.c \
					libft/ft_toupper.c \
					libft/ft_strncmp.c \
					libft/ft_strjoin.c \
					libft/ft_putendl_fd.c \
					libft/ft_memset.c \
					libft/ft_strchr.c \
					libft/ft_isascii.c \
					libft/ft_strlcat.c \
					libft/ft_lstsize.c \
					libft/ft_striteri.c \
					libft/ft_putchar_fd.c \
					libft/ft_strtrim.c \
					libft/ft_strnstr.c \
					libft/ft_lstclear.c \
					libft/ft_memcmp.c \
					libft/ft_putnbr_fd.c \
					libft/ft_lstmap.c \
					libft/ft_isalnum.c \
					libft/ft_strlcpy.c \
					libft/ft_isprint.c \
					libft/ft_strlen.c \
					libft/ft_lstadd_back.c \
					libft/ft_isalpha.c \
					libft/ft_lstlast.c \
					libft/ft_strmapi.c \
					libft/ft_memchr.c \
					libft/ft_atoi.c \
					libft/ft_lstadd_front.c \
					libft/ft_memcpy.c \
					libft/ft_strrchr.c \
					libft/ft_split.c \
					libft/ft_calloc.c \
					libft/ft_isdigit.c \
					libft/ft_memmove.c \
					libft/ft_putstr_fd.c \
					libft/ft_lstiter.c \
					libft/ft_strdup.c \
					libft/ft_lstnew.c \
					libft/ft_bzero.c \
					libft/ft_lstdelone.c \
					libft/ft_itoa.c \
					src/utils.c \
					src/checkers.c \
					src/processes.c \
					src/process_by_size.c \
					src/indexing.c \
					src/swap.c \
					src/reverse.c \
					src/reverse_rotate.c \
					src/big_sort.c \
					src/push.c \
					src/placement.c \
					src/ascending.c \
					src/position_processes.c \
					src/pre_processes.c \
					src/rotates.c \

BONUS_SRCS = 		libft/ft_tolower.c \
					libft/ft_substr.c \
					libft/ft_toupper.c \
					libft/ft_strncmp.c \
					libft/ft_strjoin.c \
					libft/ft_putendl_fd.c \
					libft/ft_memset.c \
					libft/ft_strchr.c \
					libft/ft_isascii.c \
					libft/ft_strlcat.c \
					libft/ft_lstsize.c \
					libft/ft_striteri.c \
					libft/ft_putchar_fd.c \
					libft/ft_strtrim.c \
					libft/ft_strnstr.c \
					libft/ft_lstclear.c \
					libft/ft_memcmp.c \
					libft/ft_putnbr_fd.c \
					libft/ft_lstmap.c \
					libft/ft_isalnum.c \
					libft/ft_strlcpy.c \
					libft/ft_isprint.c \
					libft/ft_strlen.c \
					libft/ft_lstadd_back.c \
					libft/ft_isalpha.c \
					libft/ft_lstlast.c \
					libft/ft_strmapi.c \
					libft/ft_memchr.c \
					libft/ft_atoi.c \
					libft/ft_lstadd_front.c \
					libft/ft_memcpy.c \
					libft/ft_strrchr.c \
					libft/ft_split.c \
					libft/ft_calloc.c \
					libft/ft_isdigit.c \
					libft/ft_memmove.c \
					libft/ft_putstr_fd.c \
					libft/ft_lstiter.c \
					libft/ft_strdup.c \
					libft/ft_lstnew.c \
					libft/ft_bzero.c \
					libft/ft_lstdelone.c \
					libft/ft_itoa.c \
					get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c \
					bonus/main_bonus.c \
					bonus/utils_bonus.c \
					bonus/checkers_bonus.c \
					bonus/processes_bonus.c \
					bonus/process_by_size_bonus.c \
					bonus/indexing_bonus.c \
					bonus/swap_bonus.c \
					bonus/reverse_bonus.c \
					bonus/reverse_rotate_bonus.c \
					bonus/big_sort_bonus.c \
					bonus/push_bonus.c \
					bonus/placement_bonus.c \
					bonus/ascending_bonus.c \
					bonus/position_processes_bonus.c \
					bonus/pre_processes_bonus.c \
					bonus/checker_bonus.c \
					bonus/control_bonus.c \
					

                          
OBJS        := $(SRCS:.c=.o)
C_OBJS        := $(BONUS_SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		$(BONUS)

${BONUS}:	${C_OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(BONUS) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${BONUS} ${C_OBJS}
			@echo "$(GREEN)$(BONUS) created[0m ✔️"

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
			@rm -rf $(BONUS)

re:			fclean all

.PHONY:		all clean fclean re



