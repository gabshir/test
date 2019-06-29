NAME	:= libft.a

LISTDIR :=	ft_lists/
LIST 	:=	ft_lstadd ft_lstdel ft_lstdelone ft_lstiter ft_lstmap \
			ft_lstnew \


MEMDIR	:=	ft_mem/
MEM 	:=	ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy \
			ft_memdel ft_memmove ft_memset


STRDIR	:=	ft_str/
STR		:=	ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy \
			ft_strdel ft_strdup ft_strequ ft_striter ft_striteri \
			ft_strjoin ft_strlcat ft_strlen ft_strmap ft_strmapi \
			ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew \
			ft_strnstr ft_strrchr ft_strsplit ft_strstr ft_strsub \
			ft_strtrim \


OVERDIR :=	ft_over/
OVER	:=	ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit \
			ft_isprint ft_itoa ft_putchar_fd ft_putchar ft_putendl_fd \
			ft_putendl ft_putnbr_fd ft_putnbr ft_putstr_fd ft_putstr \
			ft_tolower ft_toupper get_next_line \

PFDIR	:=	ft_printf/
PF 		:=	flagidiux flagifo ft_itua_e ft_printchar ft_printf \
			ft_printfl ft_printnbr ft_printnbro ft_printstr \
			ft_printx general itua over parseng printf spec \

COMPILE :=	gcc -Wall -Wextra -Werror -g
OBJDIR	:=	obj/
SRCDIR 	:=	srcs/
INCDIR	:=	includes/

FILES := $(addprefix $(LISTDIR),$(LIST))
FILES += $(addprefix $(MEMDIR),$(MEM))
FILES += $(addprefix $(STRDIR),$(STR))
FILES += $(addprefix $(OVERDIR),$(OVER))
FILES += $(addprefix $(PFDIR),$(PF))

OBJ := $(addprefix $(OBJDIR),$(addsuffix .o,$(FILES)))

all: $(NAME)

$(OBJDIR):
	@echo "Creating library object files directories..."
	@mkdir $(OBJDIR)
	@mkdir $(OBJDIR)$(LISTDIR)
	@mkdir $(OBJDIR)$(MEMDIR)
	@mkdir $(OBJDIR)$(STRDIR)
	@mkdir $(OBJDIR)$(OVERDIR)
	@mkdir $(OBJDIR)$(PFDIR)
	@echo "Library object files directory created!"

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@$(COMPILE) -I $(INCDIR) -c $< -o $@

$(NAME): $(OBJ)
	@echo "Compiling library..."
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Library is compiled!"

clean:
	@echo "Deleting library object files..."
	@rm -rf $(OBJDIR)
	@echo "Library is cleaned!"

fclean: clean
	@echo "Deleting library binary..." 
	@rm -f $(NAME)
	@echo "libft.a is deleted!"

re: fclean
	@$(MAKE) all