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
       $(SRC_DIR)/contenu.c \
	   $(SRC_DIR)/scroll.c \
	   $(SRC_DIR)/promp_label.c \
	   $(SRC_DIR)/fonctionnalites_prompt.c \
	   $(SRC_DIR)/defilement_auto.c \
	   $(SRC_DIR)/infos.c

# Détection des flags GTK4 via pkg-config
GTK_FLAGS = `pkg-config --cflags --libs gtk4`

# Options du compilateur
CFLAGS = -I$(INC_DIR) -Wall -Wextra -g

# Gestion du nom de l'ordinateur
HOSTNAME = -lws2_32

# Compilation
$(TARGET): $(SRCS)
	gcc $(CFLAGS) $(SRCS) -o $(TARGET) $(GTK_FLAGS) $(HOSTNAME)
	@echo "Compilation terminée : $(TARGET)"

run: minishell.exe
	./minishell.exe

# Nettoyage
clean:
	rm -f $(TARGET)
	@echo "Exécutable supprimé."