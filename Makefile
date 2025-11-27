SRC_DIR=src
TEST_DIR=tests

SRC=$(SRC_DIR)/*.c
TEST=$(TEST_DIR)/test_ctype.c\
		$(TEST_DIR)/test_string.c\
		$(TEST_DIR)/main.c

all:
	gcc $(SRC) $(TEST) -Iinclude -I/opt/homebrew/include -L/opt/homebrew/lib -lcunit
