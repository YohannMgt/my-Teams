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

COMMAND_SRC	=	src/input_command/display.c \
				src/input_command/clear.c \
				src/command/help.c \
				src/command/create/create.c \
				src/command/create/team.c \
				src/command/create/channel.c \
				src/command/create/thread.c \
				src/command/create/message.c \
				src/command/use.c \
				src/command/login.c \
				src/command/logout.c \
				src/command/messages.c \
				src/command/broadcast.c \
				src/command/send.c \
				src/command/quit.c \
				src/command/info.c \
				src/command/list.c \
				src/command/users.c \
				src/command/subscribed.c \
				src/command/subscribe.c \
				src/command/unsubscribe.c \
				src/command/user.c	\
				src/command/nothing.c	\
				src/save_restore/restore.c	\
				src/save_restore/save.c	\

COMMON_SRC	=	../src/load_file.c \
				../src/usage.c \
				../src/args.c \
				../src/command.c \
				../src/get_env.c \
				../src/display.c \
				../src/free.c

FILE_SRC    =	$(COMMON_SRC) \
				$(COMMAND_SRC) \
				src/get_resource.c \
				src/team/create_team.c \
				src/team/delete_team.c \
				src/channel/create_channel.c \
				src/channel/delete_channel.c \
				src/thread/create_thread.c \
				src/thread/delete_thread.c \
				src/account/create_account.c \
				src/account/delete_account.c \
				src/message/create_message.c \
				src/message/delete_message.c \
				src/loop.c \
				src/send.c \
				src/stdin.c \
				src/server.c \
				src/reset_fds.c \
				src/disconnect.c \
				src/conn/accept.c \
				src/loop_command.c \
				src/command_parsing.c \
				src/user/create_user.c \
				src/user/delete_user.c \
				src/user/get_context.c \
				src/load/load_server.c \
				src/load/unload_server.c \
				src/load/load_account.c
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
EXE    =    $(OUTPUT_DIR)/myteams_server
TEST_EXE    =    $(EXE)_test

all:    $(EXE)

%.o:    %.c
	$(CC) $(CFLAGS)   -c -o $@ $<


%_test.o:	%.o
	$(CC)   -c -o $@ $<

$(EXE):	$(FILE_OBJ) $(MAIN_OBJ) $(ARCHIVE)
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
unit_tests: $(FILE_OBJ) $(TEST_OBJ) $(ARCHIVE)
	$(CC) -o $(EXE) $(FILE_OBJ) $(TEST_OBJ) $(LDFLAGS)

tests_run:    clean unit_tests
	./$(TEST_EXE) --jobs 1

.PHONY: all clean re fclean unit_tests tests_run
