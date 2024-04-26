##
## EPITECH PROJECT, 2024
## B-NWP-400-LYN-4-1-myteams-yohann.mangenot
## File description:
## Makefile
##

all: client server

FLAGS	=
LIBFLAGS	=

client:
	@make -C libs $(LIBFLAGS) --no-print-dir
	@make -C client $(FLAGS)

server:
	@make -C libs $(LIBFLAGS) --no-print-dir
	@make -C server $(FLAGS)

debug:	FLAGS += debug
debug:	LIBFLAGS += debug
debug: client server

completion:	FLAGS += completion
completion: client server

clean:
	@make -C libs clean --no-print-dir
	@make -C client clean --no-print-dir
	@make -C server clean --no-print-dir


fclean:	clean
	@make -C libs fclean --no-print-dir
	@make -C client fclean --no-print-dir
	@make -C server fclean --no-print-dir
	rm -rf coding-style-reports.log

re:    fclean all

unit_tests:
	@make -C client unit_tests --no-print-dir
	@make -C server unit_tests --no-print-dir

tests_run:    unit_tests

.PHONY: all clean re fclean tests_run client server debug completion
