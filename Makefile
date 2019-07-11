CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2
NAME = fractol
SRCDIR = ./
INCLDIR = ./includes/
ADDMLX = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework Appkit
LIBDIR = ./libft/
LIB = $(LIBDIR)libft.a
SRCS = $(SRCDIR)main.c \
	$(SRCDIR)mlx_init.c \
	$(SRCDIR)draw_point_on_renderer.c \
	$(SRCDIR)create_mandelbrot.c \
	$(SRCDIR)commands.c \
	$(SRCDIR)take_screen_for_fdf.c \
	$(SRCDIR)zoom.c \
	$(SRCDIR)chose_color.c \
	$(SRCDIR)data_init.c \
	$(SRCDIR)data_init2.c \
	$(SRCDIR)calcul_fractals.c \
	$(SRCDIR)calcul_fractals2.c \
	$(SRCDIR)commands_translation.c
OBJS_ = $(SRCS:.c=.o)
OBJS = $(notdir $(OBJS_))

all : $(LIB) $(NAME)

$(NAME) : $(SRCS) $(LIB)
	@make objects
	@$(CC) $(CFLAGS) -I $(INCLDIR) $^ -o $@ -L $(LIBDIR) -lft $(ADDMLX)
	@echo "\n\033[36mCreation :\033[0m \033[35;4m$(NAME)\033[0m\n"

objects : $(OBJS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $^ -I $(INCLDIR)
	@echo "\033[36mCompilation :\033[0m \033[32m$*\033[0m"

$(LIB) :
	@echo "\n\033[36mLibs Compilation :\033[0m \033[33m$(LIBDIR)\033[0m\n"
	@make -C libft

clean :
	@rm -rf $(OBJS)
	@echo "\n\033[36mDeletion :\033[0m \033[32mObjects\033[0m\n"

fclean :
	@make clean
	@rm -rf $(NAME)
	@make -C libft/ fclean
	@echo "\033[36mDeletion :\033[0m \033[35;4m$(NAME)\033[0m\n"

re :
	@make fclean
	@make all

.PHONY : all clean fclean re objects
