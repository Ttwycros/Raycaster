NAME =	fdf

CC =	gcc

RM =	rm -rf

SRC =	main.c \
		read_file.c \
		get_next_line.c \
		draw.c \
		hooks.c \
		utils.c \
		utils2.c \
		3d_projection.c \

INC =	-I cube.h \
		-I get_next_line.h \
		-I libft/libft.h \
		#-I minilibx/mlx.h \

OBJS =	$(SRC:.c=.o)
DEP =	$(SRC:.c=.d)

LD_FLAGS =	-L libft -Lmlx -lmlx -framework OpenGL -framework AppKit -lz

.PHONY :	all clean re fclean norm

.c.o :		
		${CC} ${CFLAGS} -Imlx ${INC} -c $< -o ${<:.c=.o}


$(NAME):	$(OBJS)
			make -C ./libft/
			${CC} ${OBJS} ${LD_FLAGS} ./libft/libft.a ./mlx/libmlx.a -o ${NAME}
#-lft

all: 		$(NAME)

clean:
			$(RM) $(OBJS) $(DEP) get_next_line.o get_next_line.d get_next_line_utils.o get_next_line_utils.d
			make clean -C libft/

fclean: 	clean
			$(RM) $(NAME)
			make fclean -C libft/

re: 		fclean all

-include $(DEP)