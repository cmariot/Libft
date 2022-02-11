# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2022/02/05 13:54:34 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                          PROJECT'S DIRECTORIES                               #
# **************************************************************************** #

NAME			= libprint.a
LIBFT			= ../..


# **************************************************************************** #
#                         COMPILATION AND LINK FLAGS                           #
# **************************************************************************** #

CC				= clang

CFLAGS			= -Wall -Wextra -Werror

INCLUDES		= -I ./includes
INCLUDES		+= -I ../../includes


# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #

DIRSRC		= srcs/

DIROBJ		= objs/

SRC			= print.c \
			  ft_print_char.c \
			  ft_print_str.c \
			  ft_print_integer.c \
			  ft_print_unsigned_int.c \
			  ft_print_addr.c \
			  ft_print_hexa.c \
			  ft_print_upper_hexa.c \
			  ft_print_percent.c \
			  get_flags.c \
			  init_flags.c \
			  print_type.c \
			  ft_space_and_precision.c \
			  ft_star_flag.c

OBJ			:= $(SRC:.c=.o)

DIROBJS		= $(addprefix $(DIROBJ), $(OBJ))

SRCS		= $(addprefix $(SRC_DIR), $(SRC))


# **************************************************************************** #
#                                COLORS                                        #
# **************************************************************************** #

GR		= \033[32;1m
RE		= \033[31;1m
YE		= \033[33;1m
CYAN	= \033[36;1m
RC		= \033[0m


# **************************************************************************** #
#                             MAKEFILE'S RULES                                 #
# **************************************************************************** #

.SILENT : all

all : header $(NAME)

$(DIROBJ)%.o: $(DIRSRC)%.c
		@mkdir -p $(DIROBJ)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
$(NAME)	: $(DIROBJS)
		@printf "$(CYAN)"
		@printf "\nLINKING\n"
		@printf "$(RC)"
		ar rcs $(NAME) $(DIROBJS)

clean :
		@rm -rf $(DIROBJ)

fclean :
		@rm -f $(NAME)
		@rm -rf $(DIROBJ)

re :	 fclean all

header :
		@printf "$(CYAN)"
		@printf "\nPRINTF COMPILATION\n"
		@printf "$(RC)"

.PHONY : clean fclean
