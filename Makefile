##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile for eval_expr
##

#################ALL SRC##################

SRC			=	src/display_storage.c	\
				src/engine.c 			\
				src/get_map.c 			\
				src/height_width_calc.c \
				src/help.c 				\
				src/lose_win.c       	\
				src/move_object.c 		\
				src/move_player.c 		\
				src/seek_player.c       \
				src/two_d_array.c

MAIN 		= 	src/main.c

TESTS_SRC 	= 	tests/tests.c

#################ALL OBJ##################

OBJ			=	$(SRC:%.c=%.o)

OBJ_MAIN	=	$(MAIN:%.c=%.o)

OBJT		=	$(TESTS_SRC:%.c=%.o)

#################ALL NAMES##################

NAME		=	my_sokoban

TEST_NAME	=	unit_test

#################ALL FLAGS##################

CC			=	gcc

LIB			=	-L./lib/my -lmy

CFLAGS 		= 	-I./include -lncurses

TESTS_FLAGS = 	--coverage -lcriterion

#################ALL##################

all:	$(NAME)

$(NAME): 		$(OBJ) $(OBJ_MAIN)
	make makelib
	$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS) $(LIB)

#################LIB##################

makelib:
	make -C ./lib/my

#################CLEAN##################

clean:
	rm -f *~
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit_test
	rm -f *.o
	rm -f src/*~
	rm -f src/*.gcno
	rm -f src/*.gcda
	rm -f src/unit_test
	rm -f src/*.o
	rm -f tests/*.o

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests
	make fclean -C ./lib/my

#################TESTS##################

tests_run: fclean makelib $(OBJT)
	make clean
	$(CC) -o $(TEST_NAME) $(TESTS_SRC) $(SRC) $(LIB) $(CFLAGS) --coverage -lcriterion
	./unit_test
	
coverage:
	gcovr --exclude tests

branch_coverage:
	gcovr -b --exclude tests

#################PUSH##################

push:
	make fclean
	git add -A
	@read -p "Give a commit message " TAG \
    && git commit -m "$${TAG}"
	git push

#################RE##################

re: fclean all

.PHONY: clean fclean re all tests_run coverage
