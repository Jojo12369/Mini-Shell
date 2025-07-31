#include "../headers/terminal.h"
#include "../headers/prompt_label.h"

GtkWidget* terminal() {
    // Création d'une box verticale pour contenir toutes les lignes
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    // Ajoute la première ligne (hbox)
    creation_gtkentry(vbox);

    return vbox;
}