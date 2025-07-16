NAME = libftprintf.a
EXEC = main
SRC = src/ft_putchar.c src/ft_puthex.c src/ft_putnbr.c \
      src/ft_putstr.c src/ft_parse_printf.c src/ft_putunsigned.c \
      src/ft_putptr.c src/ft_put_hex_long_long.c ft_printf.c 

OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -MMD -MP -Iincludes
RM = rm -f

GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)📦 Création de la librairie $(NAME)...$(RESET)"
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)✅ Compilation terminée avec succès !$(RESET)"


%.o: %.c
	@echo "$(GREEN)🛠️   Compilation de $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)🧹 Suppression des fichiers objets...$(RESET)"
	@$(RM) $(OBJ) $(DEP)

fclean: clean
	@echo "$(RED)💣 Suppression de la librairie et de $(EXEC)...$(RESET)"
	@$(RM) $(NAME) $(EXEC) 

re: fclean all

run: all
	@echo "$(YELLOW)🚀 Compilation et exécution...$(RESET)"
	@$(CC) $(CFLAGS) main.c -L. -lftprintf -o $(EXEC)
	@./$(EXEC)

-include $(DEP)
