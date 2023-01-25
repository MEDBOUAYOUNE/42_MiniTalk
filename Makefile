# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouayou <mbouayou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 11:52:13 by mbouayou          #+#    #+#              #
#    Updated: 2023/01/25 12:19:56 by mbouayou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME_C = client
NAME_S = server
NAME_C_B = client_bonus
NAME_S_B = server_bonus

SRC_C = client.c help.c
SRC_S = server.c help.c
SRC_C_B = client_bonus.c help_bonus.c
SRC_S_B = server_bonus.c help_bonus.c

CC = CC
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

OBJ_C = $(SRC_C:.c=.o)
OBJ_S = $(SRC_S:.c=.o)
OBJ_C_B = $(SRC_C_B:.c=.o)
OBJ_S_B = $(SRC_S_B:.c=.o)


all : $(NAME_C) $(NAME_S)

$(NAME_C) : $(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_C) -o $(NAME_C)
$(NAME_S) : $(OBJ_S)
	$(CC) $(CFLAGS) $(OBJ_S) -o $(NAME_S)


bonus: $(NAME_C_B) $(NAME_S_B)

$(NAME_C_B) : $(OBJ_C_B)
	$(CC) $(CFLAGS) $(OBJ_C_B) -o $(NAME_C_B)
$(NAME_S_B) : $(OBJ_S_B)
	$(CC) $(CFLAGS) $(OBJ_S_B) -o $(NAME_S_B)

	
clean:
	$(RM) $(OBJ_C) $(OBJ_S) $(OBJ_C_B) $(OBJ_S_B)


fclean: clean
	$(RM) $(NAME_C) $(NAME_S) $(NAME_C_B) $(NAME_S_B)


re: fclean all