#include "../headers/terminal.h"

void creation_gtkentry(GtkWidget *vbox);
void validation(GtkEntry *entry, gpointer user_data);

GtkWidget* terminal() {
    // Création d'une box verticale pour contenir toutes les lignes
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    // Ajoute la première ligne (hbox)
    creation_gtkentry(vbox);

    return vbox;
}

void creation_gtkentry(GtkWidget *vbox) {
    // Crée une box horizontale pour une ligne
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    // Création du label "$>"
    GtkWidget *prompt_label = gtk_label_new("$>");
    gtk_widget_set_name(prompt_label, "prompt-label");

    // Création du "entry"
    GtkWidget *entry = gtk_entry_new();
    gtk_widget_set_name(entry, "entry");
    gtk_widget_set_hexpand(entry, TRUE);

    // Ajout du label et de l'entrée dans la hbox (ligne)
    gtk_box_append(GTK_BOX(hbox), prompt_label);
    gtk_box_append(GTK_BOX(hbox), entry);

    // Ajout de la hbox (ligne) dans la vbox (terminal)
    gtk_box_append(GTK_BOX(vbox), hbox);

    // Connexion du signal "activate" sur l'entrée, avec comme user_data la vbox (terminal)
    g_signal_connect(entry, "activate", G_CALLBACK(validation), vbox);

    // Mettre le focus sur le nouvel entry
    gtk_widget_grab_focus(entry);
}

typedef struct {
    GtkScrolledWindow *scrolled_window;
    double offset;  // Décalage en pixels
} ScrollContext;

gboolean scroll_to_position(gpointer data) {
    ScrollContext *ctx = (ScrollContext *)data;

    GtkAdjustment *vadjustment = gtk_scrolled_window_get_vadjustment(ctx->scrolled_window);

    // Valeurs importantes
    double lower = gtk_adjustment_get_lower(vadjustment);
    double upper = gtk_adjustment_get_upper(vadjustment);
    double page_size = gtk_adjustment_get_page_size(vadjustment);

    // Position max (scroll le plus bas possible)
    double max_scroll = upper - page_size;

    // Calcul de la nouvelle position avec offset
    double target = max_scroll + ctx->offset;

    // Clamp pour rester dans les bornes
    if (target < lower)
        target = lower;
    if (target > max_scroll)
        target = max_scroll;

    gtk_adjustment_set_value(vadjustment, target);

    g_free(ctx);
    return G_SOURCE_REMOVE;
}

void validation(GtkEntry *entry, gpointer user_data) {
    GtkWidget *vbox = GTK_WIDGET(user_data);

    const gchar *texte = gtk_entry_buffer_get_text(gtk_entry_get_buffer(entry));
    g_print("Texte saisi : %s\n", texte);

    gtk_editable_set_editable(GTK_EDITABLE(entry), FALSE);
    gtk_widget_set_can_focus(GTK_WIDGET(entry), FALSE);

    creation_gtkentry(vbox);

    GtkWidget *scrolled_window = gtk_widget_get_ancestor(vbox, GTK_TYPE_SCROLLED_WINDOW);
    if (scrolled_window) {
        ScrollContext *ctx = g_new(ScrollContext, 1);
        ctx->scrolled_window = GTK_SCROLLED_WINDOW(scrolled_window);

        ctx->offset = -5;  // Décale vers le haut de 50 pixels (ou +50 vers le bas)

        g_timeout_add(30, scroll_to_position, ctx);
    }
}