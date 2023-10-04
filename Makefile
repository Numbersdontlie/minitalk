SERVER = server
CLIENT = client

CFLAGS = -Wall -Wextra -Werror
CC = gcc
FLAGS = -Wall -Wextra -Werror -I$(PRINTF)
PRINTF = Printf

all:
		@make -s -C $(PRINTF)
		@gcc $(FLAGS) server.c -o $(SERVER)
		@gcc $(FLAGS) client.c -o $(CLIENT)
		@echo "Server and Cliente are ready to go!"

clean:
		@make clean -s -C $(PRINTF)

fclean:
		@make fclean -s -C $(PRINTF)
		@rm -f $(SERVER) $(CLIENT)
		@echo "Server and Client cleaned and ready to use again"

re: fclean all