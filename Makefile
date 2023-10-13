NAME = minitalk

SRCS = client.c server.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

%.o: %.c
		gcc ${CFLAGS} -IPrintf -c $? -o $@

${NAME}: server client

server: server.o
		@make -C Printf
		gcc ${CFLAGS} $? -LPrintf -lftprintf -o server

client: client.o
		@make -C Printf
		gcc ${CFLAGS} $? -LPrintf -lftprintf -o client
		@echo "Server and Client are ready to go"

printf:
		@make -C Printf

clean:
		@make clean -s -C Printf
		@make fclean -s -C Printf
		rm -f ${OBJS}

fclean: clean
		@rm -f server client
		@echo "Server and Client cleaned and ready to use again"

re: fclean all

.PHONY: printf