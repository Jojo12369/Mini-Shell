#ifndef TERMINAL_H
#define TERMINAL_H

// Inclusion de la bibliothèque gtk4
#include <gtk/gtk.h>

// Déclaration de la fonction qui gère le terminal
void creation_gtkentry(GtkWidget *hbox);
void validation(GtkEntry *entry, gpointer user_data);
GtkWidget* terminal();

#endif // TERMINAL_H