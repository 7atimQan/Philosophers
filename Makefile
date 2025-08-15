NAME = philo
CC = cc
CFLAGS = 

SRCS = main.c init_struct.c create_threads.c

OBJS = $(SRCS:.c=.o)


do: all clean

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
