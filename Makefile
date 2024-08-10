NAME = push_swap
CC = cc
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./Libft/
INC_DIR = includes
OP_DIR = ./$(SRC_DIR)/operations
SRC_DIR = srcs
SRCFILES = main.c \
			error.c \
			is_sorted.c \
			sort_stack.c \
			sort_small_stack.c \
			find_median.c \
			find_min_max.c \
			cost.c \
			move.c

OPFILES = sa_sb_ss.c \
		  pa_pb.c \
		  ra_rb_rr.c \
		  rra_rrb_rrr.c

CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)

SRCS = $(addprefix $(SRC_DIR)/, $(SRCFILES))
OP_SRCS = $(addprefix $(OP_DIR)/, $(OPFILES))
OBJS = $(SRCS:.c=.o) $(OP_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT): 
	make -C $(LIBFT_DIR) 
	ranlib $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
#	del /Q $(subst /,\,$(OBJS))
	rm -f $(OBJS)

fclean: clean
#	del /Q $(subst /,\,$(NAME))
	rm -f $(NAME)
	make -C $(LIBFT_DIR)  fclean

re: fclean all

.PHONY: all clean fclean re