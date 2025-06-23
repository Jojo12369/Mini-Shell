// Inclusion des bibliothèques nécéssairent
#include "../headers/contenu.h"
#include "../headers/message_start.h"
#include "../headers/terminal.h"

GtkWidget* create_main_vbox() {
    // Création de la box verticale principale
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_name(vbox, "vbox");
    gtk_widget_set_vexpand(vbox, TRUE);

    // Ajout du label d’accueil (header)
    GtkWidget *welcome_label = message_start();
    gtk_box_append(GTK_BOX(vbox), welcome_label);

    // Ajout de la ligne terminal (entrée)
    GtkWidget *terminal_line = terminal();
    gtk_box_append(GTK_BOX(vbox), terminal_line);

    return vbox;
}