##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile for eval_expr
##

SRC	=	src/*.c

NEW_SRC = src/get_map.c \
		  src/help.c

TESTS_SRC = tests/*.c

NAME	=	my_sokoban

LIB	=	-L./lib/my -lmy

CFLAGS = -Iinclude -lncurses

TESTS_FLAGS = --coverage -lcriterion

all:	$(NAME)

$(NAME):
	make makelib
	gcc -o $(NAME) $(CFLAGS) $(SRC) $(LIB)

makelib:
	make -C ./lib/my

clean:
	rm -f *~
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit-tests
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f unit_tests
	make fclean -C ./lib/my

re:	fclean all


unit_tests: fclean makelib
	make clean
	gcc -o unit_tests $(TESTS_SRC) $(NEW_SRC) $(CFLAGS) $(LIB) $(TESTS_FLAGS)
	./unit_tests
	
coverage:
	gcovr --exclude tests

branch_coverage:
	gcovr -b --exclude tests

push:
	make fclean
	git add .
	@read -p "Give a commit message " TAG \
    && git commit -m "$${TAG}"
	git push

.PHONY: all makelib clean fclean re
