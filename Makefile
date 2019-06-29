# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabshire <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/28 13:13:58 by gabshire          #+#    #+#              #
#    Updated: 2019/03/28 13:14:01 by gabshire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

SRCDIR = srcs/
OBJDIR = obj/

CH_FILES = checker
CH_OBJ = $(addprefix $(OBJDIR),$(addsuffix .o,$(CH_FILES)))

PS_FILES = answer1	logik1	logik2	logik3	logik4 push_swap
PS_OBJ = $(addprefix $(OBJDIR),$(addsuffix .o,$(PS_FILES)))

COMMON = answer	maindop	sort2		stack_print \
		answer2	sort1	sort3	
COMMON_OBJ = $(addprefix $(OBJDIR),$(addsuffix .o,$(COMMON)))

LIBFT = ./libft/libft.a 
INCDIR = -I ./includes
LIBLINK = -L ./libft -lft
LIBINC = -I ./libft/includes

all: $(LIBFT) $(CHECKER) $(PUSH_SWAP)

$(LIBFT):
	@make -C ./libft

$(OBJDIR):
	@echo "Creating object files directory..."
	@mkdir $(OBJDIR)
	@echo "Directory created!"

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@$(CC) $(FLAGS) $(INCDIR) $(LIBINC) -c $< -o $@

$(CHECKER): $(CH_OBJ) $(COMMON_OBJ)
	@echo "Compiling checker..."
	@$(CC) $(LIBLINK) -o $(CHECKER) $(CH_OBJ) $(COMMON_OBJ)
	@echo "Checker is compiled!"

$(PUSH_SWAP): $(PS_OBJ) $(COMMON_OBJ)
	@echo "Compiling push_swap..."
	@$(CC) $(LIBLINK) -o $(PUSH_SWAP) $(PS_OBJ) $(COMMON_OBJ)
	@echo "Push_swap is compiled!"

libclean:
	@make clean -C ./libft

clean: libclean
	@echo "Deleting object files..."
	@rm -rf $(OBJDIR)
	@echo "Object files deleted!"

fclean: clean
	@echo "Deleting push_swap and checker..."
	@rm -rf $(CHECKER) $(PUSH_SWAP)
	@echo "Executable files are deleted!"
	@make fclean -C ./libft
	@echo "Everything is cleaned!"

re: fclean
	@$(MAKE) all
