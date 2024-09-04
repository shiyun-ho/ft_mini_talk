# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshi-yun <hshi-yun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 20:03:42 by hshi-yun          #+#    #+#              #
#    Updated: 2024/09/04 21:04:27 by hshi-yun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft

SERVER = server
CLIENT = client

SRC_CLIENT = client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

SRC_SERVER = server.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER) $(CLIENT): $(OBJ_SERVER) $(OBJ_CLIENT) $(LIBFT)
	@echo ">>>Compiling sublibrary: $(LIBFT): "
	$(MAKE) -C $(LIBFT)
	cp $(LIBFT)/libft.a .
	@echo ">>> Starting compilation of CLIENT and SERVER files: "
	$(CC) $(CFLAGS) $(LIBFT)/libft.a -o $(SERVER) $(SRC_SERVER)
	$(CC) $(CFLAGS) $(LIBFT)/libft.a -o $(CLIENT) $(SRC_CLIENT)
	@echo ">>> Compilation completed. "

norminette:
	@echo ">>> Checking norminette for all files"
	norminette -R CheckForbiddenSourceHeader $(SRC_CLIENT) $(SRC_SERVER)

clean:
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER) 
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -rf $(CLIENT) $(SERVER) $(LIBFT).a
	$(MAKE) -C $(LIBFT) clean

re: fclean all

test: $(NAME) test.c
	@echo ">>> Running test files"
	$(CC) $(CFLAGS) -o test test.c libftprintf.a
	@./test


.PHONY: all norminette clean fclean re bonus test