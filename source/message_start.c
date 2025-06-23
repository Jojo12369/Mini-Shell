// Inclusion de la bibliothèques nécéssaire
#include "../headers/message_start.h"

GtkWidget* message_start() {
    // Création d'un label d'info fixe en haut
    GtkWidget *hbox_info_label = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    GtkWidget *info_label = gtk_label_new("MiniShell v1.0 - Un terminal simple\n");
    gtk_widget_set_name(info_label, "info-label");
    gtk_box_append(GTK_BOX(hbox_info_label), info_label);
    return hbox_info_label;
}