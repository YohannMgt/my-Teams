##
## EPITECH PROJECT, 2024
## myteams
## File description:
## Makefile
##

ARCHIVE	=	../libs/libsocket.a \
			../libs/libarray.a \
			../libs/libdlloader.a \
			../libs/liblogging.a \
			../libs/libcompletion.a \
			../libs/libqueue.a \
			../libs/libbuffer.a

MAIN_SRC    =	src/main.c

COMMON_SRC	=	../src/load_file.c \
				../src/usage.c \
				../src/args.c

FILE_SRC    =	$(COMMON_SRC) \
				src/client.c \
				src/loop.c \
				src/read.c \
				src/reset_fds.c \
				src/commands.c \
				src/response_handler.c \
				src/load/load_client.c \
				src/load/unload_client.c \
				src/response_handler/login.c \
				src/response_handler/logout.c \
				src/response_handler/send.c \
				src/response_handler/create.c \
				src/response_handler/messages.c \
				src/response_handler/unknown.c \
				src/response_handler/users.c \
				src/response_handler/info.c \
				src/response_handler/subscribe_unsubscribe.c \
				src/response_handler/list.c \

TEST_SRC    =

FILE_OBJ    =    $(FILE_SRC:.c=.o)
MAIN_OBJ    =    $(MAIN_SRC:.c=.o)
TEST_OBJ    =    $(TEST_SRC:.c=_test.o)

FILE_GCDA	=	$(FILE_SRC:.c=.gcda)
FILE_GCNO	=	$(FILE_SRC:.c=.gcno)

CC    =    gcc

DEBUG	=	-g3 -DDEBUG
INCLUDE	=	-Iinclude
NO_UNUSED	=	-Wno-unused-parameter -Wno-unused-function
CFLAGS    = -Wall -Wextra -fanalyzer \
			$(NO_UNUSED) $(INCLUDE)

LIB	=	-L../libs/ -lsocket -larray -llogging -ldlloader -lcompletion -lqueue \
		-lbuffer -L../libs/myteams -lmyteams
LDFLAGS    =    $(LIB) -luuid

COVERAGE    =    --coverage -lcriterion

OUTPUT_DIR	=	..
EXE    =    $(OUTPUT_DIR)/myteams_cli
TEST_EXE    =    $(EXE)_test

all:    $(EXE)

%.o:	%.c
	$(CC) $(CFLAGS)   -c -o $@ $<

%_test.o:	%.o
	$(CC)   -c -o $@ $<

$(EXE):	$(FILE_OBJ) $(MAIN_OBJ) $(LIB_DEPENDENCY)
	$(CC) -o $(EXE) $(FILE_OBJ) $(MAIN_OBJ) $(LDFLAGS)

debug:	CFLAGS += $(DEBUG)
debug:	all

completion:	CFLAGS += -DCOMPLETION
completion:	all

clean:
	rm -rf $(MAIN_OBJ) $(TEST_OBJ) $(FILE_OBJ)
	rm -rf $(FILE_GCNO) $(FILE_GCDA)
	rm -rf coding-style-reports.log
	$(shell find * -name "vgcore.*" -delete)

fclean:	clean
	rm -rf $(EXE)
	rm -rf $(TEST_EXE)

re:    fclean all

unit_tests:	CFLAGS += $(COVERAGE) -DTEST
unit_tests: LDFLAGS += $(COVERAGE)
unit_tests: $(FILE_OBJ) $(TEST_OBJ)
	$(CC) -o $(EXE) $(FILE_OBJ) $(TEST_OBJ) $(LDFLAGS)

tests_run:    clean unit_tests
	./$(TEST_EXE) --jobs 1

.PHONY: all clean re fclean unit_tests tests_run
