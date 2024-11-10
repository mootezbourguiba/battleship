# Variables
CC = gcc
CFLAGS = -Wall -std=c99 -I./include
LDFLAGS = 

# Dossiers de source et d'inclusion
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Fichiers source
SRCFILES = $(SRCDIR)/main.c $(SRCDIR)/game.c $(SRCDIR)/player.c $(SRCDIR)/grid.c $(SRCDIR)/ship.c
OBJFILES = $(SRCFILES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Nom de l'exécutable
EXEC = $(BINDIR)/BatailleNavale

# Règle par défaut pour compiler le programme
all: $(EXEC)

# Créer le dossier obj si nécessaire
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Créer le dossier bin si nécessaire
$(BINDIR):
	mkdir -p $(BINDIR)

# Compiler l'exécutable
$(EXEC): $(OBJFILES)
	$(CC) $(OBJFILES) -o $(EXEC) $(LDFLAGS)

# Règle pour compiler les fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Règle pour nettoyer uniquement les fichiers objets
clean_objs:
	rm -rf $(OBJDIR)

