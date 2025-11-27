all:
	gcc src/ss_isdigit.c tests/main.c tests/test_ctype.c -Iinclude -I/opt/homebrew/include -L/opt/homebrew/lib -lcunit
