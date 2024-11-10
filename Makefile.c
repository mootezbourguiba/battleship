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

# Nom de l'ex�cutable
EXEC = $(BINDIR)/BatailleNavale

# R�gle par d�faut pour compiler le programme
all: $(EXEC)

# Cr�er le dossier obj si n�cessaire
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Cr�er le dossier bin si n�cessaire
$(BINDIR):
	mkdir -p $(BINDIR)

# Compiler l'ex�cutable
$(EXEC): $(OBJFILES)
	$(CC) $(OBJFILES) -o $(EXEC) $(LDFLAGS)

# R�gle pour compiler les fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'ex�cutable
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# R�gle pour nettoyer uniquement les fichiers objets
clean_objs:
	rm -rf $(OBJDIR)

