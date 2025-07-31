#ifndef SCROLL_H
#define SCROLL_H

// Inclusion de la bibliothèque gtk4
#include <gtk/gtk.h>

// Crée la box verticale principale avec ses enfants
gboolean on_scroll(GtkEventControllerScroll *controller, double scroll_dx, double scroll_dy, gpointer user_data);
void on_adjustment_value_changed(GtkAdjustment *adjustment, gpointer user_data);

#endif // SCROLL_H