# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmanique <gmanique@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 19:04:58 by gmanique          #+#    #+#              #
#    Updated: 2025/08/08 19:17:01 by gmanique         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = woody_woodpacker

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iheaders

SRC_DIR = src
OBJ_DIR = obj


# AJOUTER ICI CHAQUE FICHIER .c AVEC LE DIRECTORY CORRESPONDANT (ex : utils/main_utils/util.c )
SRC =	main.c


OBJ = $(patsubst $(SRC_DIR)/%,%,$(SRC))
OBJ := $(OBJ:.c=.o)
OBJ := $(subst /,_,$(OBJ))
OBJ := $(addprefix $(OBJ_DIR)/,$(OBJ))

all: $(NAME)

$(OBJ_DIR)/%.o: $(OBJ_DIR)
	@src_file=$$(echo $* | sed 's/_/\//'); \
	src_file=$(SRC_DIR)/$$src_file.c; \
	$(CC) $(CFLAGS) $(INCLUDES) -c $$src_file -o $@

$(NAME): $(OBJ)
	@echo "\033[0;32mCompiling woody_woodpacker..\e[m"
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -o $(NAME)
	@echo "\033[1;32mWoody_woodpacker successfully compiled !\n\e[m"

$(OBJ_DIR):
	@echo "\n\033[0;32mCreating obj directory..\e[m"
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "\033[0;31mDeleting woody_woodpacker objects..\e[m"
	@rm -rf $(OBJ_DIR)
	@echo "\033[1;31mSuccessfully deleted objects !\n\e[m"

fclean: clean
	@echo "\033[0;31mDeleting executable..\e[m"
	@rm -f $(NAME)
	@echo "\033[1;31mSuccessfully deleted executables !\n\e[m"

re: fclean all

.PHONY: all clean fclean re

.SILENT: $(OBJ)
