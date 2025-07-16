# ==========================================================
# Variables générales
# ==========================================================
NAME = libpipex.a
EXEC = pipex

SRC = src/execute.c \
	  src/utils.c

MAIN = src/main.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Iinclude -ILibft -IPrintf
RM = rm -f

LIBFT_DIR = libft
PRINTF_DIR = printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# ==========================================================
# Couleurs
# ==========================================================
GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
RESET = \033[0m

# ==========================================================
# Règles
# ==========================================================
all: $(LIBFT) $(PRINTF) $(NAME) $(EXEC)

$(LIBFT):
	@echo "$(YELLOW)📚 Compilation de la libft dans Libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@echo "$(YELLOW)📚 Compilation de ft_printf dans Printf...$(RESET)"
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJ)
	@echo "$(GREEN)📦 Création de la librairie $(NAME)...$(RESET)"
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREEN)✅ Compilation terminée avec succès !$(RESET)"

$(EXEC): $(NAME)
	@echo "$(YELLOW)🚀 Compilation de l'exécutable pipex...$(RESET)"
	@$(CC) $(CFLAGS) -o $(EXEC) $(MAIN) $(NAME) $(LIBFT) $(PRINTF)

%.o: %.c
	@echo "$(GREEN)🛠️   Compilation de $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)🧹 Suppression des fichiers objets et dépendances...$(RESET)"
	@find . -type f \( -name '*.o' -o -name '*.d' \) -delete
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@echo "$(RED)💣 Suppression de la librairie et des exécutables...$(RESET)"
	@$(RM) $(NAME) $(EXEC)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

valgrind: $(EXEC)
	@echo "$(YELLOW)🔍 Lancement de Valgrind sur ./pipex...$(RESET)"
	valgrind -q --suppressions=$(PWD)/ignore --trace-children=yes \
		--leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes \
		./pipex infile /bin/cat /bin/"wc -l" outfile 
re: fclean all
