NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

OPERATIONS_PATH = operations/

COMMON_FILES = $(OPERATIONS_PATH)ft_push.c \
               $(OPERATIONS_PATH)ft_swap.c \
               $(OPERATIONS_PATH)ft_rotate.c \
               $(OPERATIONS_PATH)ft_reverse_rotate.c \
               ft_bench.c \
               ft_check.c \
               ft_chunk_sort_utils.c \
               ft_chunk_sort.c \
               ft_costs.c \
               ft_disorder_tendency.c \
               ft_free.c \
               ft_init_sort.c \
               ft_init.c \
               ft_ksort.c \
               ft_lists.c \
               ft_parsing.c \
               ft_push_swap_utils.c \
               ft_simple_sort.c \

PUSH_SWAP_FILES = ft_push_swap.c

LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

COMMON_OBJS = $(COMMON_FILES:.c=.o)
PUSH_SWAP_OBJS = $(PUSH_SWAP_FILES:.c=.o)

all: subsystems $(NAME)

subsystems:
	@make -C $(LIBFT_PATH) all

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

$(NAME): $(COMMON_OBJS) $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(PUSH_SWAP_OBJS) $(LIBFT_LIB) -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(COMMON_OBJS) $(PUSH_SWAP_OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all subsystems clean fclean re
