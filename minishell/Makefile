
CC = gcc -fsanitize=address -g -o minishell

SRC =  *.c

NAME = minishell

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC)

clean:
	rm -f $(NAME) 

fclean: clean	
	rm -f $(NAME) 

re : fclean all
