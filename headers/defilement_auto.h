#ifndef DEFILEMENT_AUTO_H
#define DEFILEMENT_AUTO_H

// Inclusion de la bibliothèque gtk4
#include <gtk/gtk.h>

// Déclaration de la fonction qui gère le defilement du terminal

// Structure pour stocker le contexte nécessaire au défilement automatique
typedef struct {
    GtkScrolledWindow *scrolled_window;
    double offset;  // Décalage en pixels
} ScrollContext;

gboolean scroll_to_position(gpointer data);

#endif // DEFILEMENT_AUTO_H