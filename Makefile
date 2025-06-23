# Nom de l'exécutable
TARGET = minishell.exe

# Répertoires
SRC_DIR = source
INC_DIR = headers

# Fichiers sources
SRCS = main.c \
       $(SRC_DIR)/window.c \
       $(SRC_DIR)/style.c \
       $(SRC_DIR)/message_start.c \
       $(SRC_DIR)/terminal.c \
       $(SRC_DIR)/contenu.c

# Détection des flags GTK4 via pkg-config
GTK_FLAGS = `pkg-config --cflags --libs gtk4`

# Options du compilateur
CFLAGS = -I$(INC_DIR) -Wall -Wextra -g

# Compilation
$(TARGET): $(SRCS)
	gcc $(CFLAGS) $(SRCS) -o $(TARGET) $(GTK_FLAGS)
	@echo "Compilation terminée : $(TARGET)"

run: minishell.exe
	./minishell.exe

# Nettoyage
clean:
	rm -f $(TARGET)
	@echo "Exécutable supprimé."