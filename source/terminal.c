// Inclusion de la bibliothèques nécéssaire
#include "../headers/terminal.h"

GtkWidget* terminal() {
    // Création d'une box horizontale
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    // Création du label "$>"
    GtkWidget *prompt_label = gtk_label_new("$>");
    gtk_widget_set_name(prompt_label, "prompt-label");

    // Création du "entry"
    GtkWidget *entry = gtk_entry_new();
    gtk_widget_set_name(entry, "entry");
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "");
    gtk_widget_set_hexpand(entry, TRUE);

    // Ajout de "entry" dans la "hbox"
    gtk_box_append(GTK_BOX(hbox), prompt_label);
    gtk_box_append(GTK_BOX(hbox), entry);

    return hbox;
}