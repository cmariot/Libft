# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2022/01/22 00:39:52 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                          PROJECT'S DIRECTORIES                               #
# **************************************************************************** #

NAME			= libprint.a

SRCS_DIR		= srcs
INCL_DIR		= includes
OBJS_DIR		= objs/

LIBFT			= ../..
LIBFT_INCL		= $(LIBFT)/includes/


# **************************************************************************** #
#                         COMPILATION AND LINK FLAGS                           #
# **************************************************************************** #

CC			= clang

CFLAGS			= -Wall -Wextra -Werror

INCLUDES		= -I $(INCL_DIR)
INCLUDES		+= -I $(LIBFT_INCL)

LFLAGS			= -Wall -Wextra -Werror


# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #

SRCS		= print.c \
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

SRC		:= $(notdir $(SRCS))

OBJ		:= $(SRC:.c=.o)

OBJS		:= $(addprefix $(OBJS_DIR), $(OBJ))

VPATH		:= $(SRCS_DIR) $(OBJS_DIR) $(shell find $(SRCS_DIR) -type d)


# **************************************************************************** #
#                                  COLORS                                      #
# **************************************************************************** #

GR		= \033[32;1m
RE		= \033[31;1m
YE		= \033[33;1m
CY		= \033[36;1m
RC		= \033[0m


# **************************************************************************** #
#                             MAKEFILE'S RULES                                 #
# **************************************************************************** #


all : $(NAME)

# Compiling
srcs_compil :
		@printf "$(YE)$(NAME) compilation ... \n"

$(OBJS_DIR)%.o : %.c
		@mkdir -p $(OBJS_DIR)
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
		@printf "$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@\n"
	
# Linking
obj_link :
		@printf "$(YE)$(NAME) compilation success.\n\n"
		@printf "$(GR)Creating $(NAME) library ...\n"
		@printf "ar rc $(NAME) $(OBJS) $(RC)\n"

$(NAME)	: srcs_compil $(SRCS) $(OBJS) obj_link
		@ar rc $(NAME) $(OBJS)
		@printf "$(GR)Success, $(NAME) is ready.\n\n$(RC)"

# Remove object files
clean :
		@printf "Removing print.a $(OBJS_DIR) ... "
		@rm -rf $(OBJS_DIR)
		@printf "Done\n$(RC)"

# Remove object and binary files
fclean :
		@printf "Removing $(NAME) ... "
		@rm -f $(NAME)
		@printf "Done\n$(RC)"
		@printf "Removing print.a $(OBJS_DIR) ... "
		@rm -rf $(OBJS_DIR)
		@printf "Done\n"

print_divider :
		@printf "\n"

# Remove all and recompile
re :	 fclean print_divider all

.PHONY : clean fclean
