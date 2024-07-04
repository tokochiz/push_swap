NAME = push_swap
CC = cc
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./Libft/
INC_DIR = includes
SRC_DIR = srcs
SRCFILES = main.c \
			error.c \

CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)

SRCS = $(addprefix $(SRC_DIR)/, $(SRCFILES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT): 
	make -C $(LIBFT_DIR) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR)  fclean

re: fclean all

.PHONY: all clean fclean re