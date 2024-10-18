# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efaustin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 15:36:45 by efaustin          #+#    #+#              #
#    Updated: 2024/08/28 15:36:46 by efaustin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SERVER = server
CLIENT = client

SERVER_SRC = src/server.c
CLIENT_SRC = src/client.c
UTILS_SRC = src/ft_printf.c src/utils.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
UTILS_OBJ = $(UTILS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(UTILS_OBJ) -o $(SERVER) 

$(CLIENT): $(CLIENT_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(UTILS_OBJ) -o $(CLIENT) 

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(UTILS_OBJ)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
