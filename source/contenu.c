#include "../headers/contenu.h"
#include "../headers/message_start.h"
#include "../headers/terminal.h"
#include "../headers/scroll.h"

// Gestion des éléments dans la page
GtkWidget* create_main_vbox() {
    GtkWidget *scrolled_window = gtk_scrolled_window_new();
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrolled_window),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_widget_set_vexpand(scrolled_window, TRUE);
    gtk_widget_set_hexpand(scrolled_window, TRUE);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_widget_set_name(vbox, "vbox");
    gtk_widget_set_valign(vbox, GTK_ALIGN_START);
    gtk_widget_set_halign(vbox, GTK_ALIGN_FILL);

    // Supposons que message_start() et terminal() soient définis ailleurs
    gtk_box_append(GTK_BOX(vbox), message_start());
    gtk_box_append(GTK_BOX(vbox), terminal());

    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window), vbox);

    GtkEventController *scroll_controller = gtk_event_controller_scroll_new(GTK_EVENT_CONTROLLER_SCROLL_VERTICAL);
    g_signal_connect(scroll_controller, "scroll", G_CALLBACK(on_scroll), scrolled_window);
    gtk_widget_add_controller(vbox, scroll_controller);

    // Connexion du signal "value-changed" de l'ajustement vertical
    GtkWidget *child = gtk_scrolled_window_get_child(GTK_SCROLLED_WINDOW(scrolled_window));
    GtkAdjustment *vadjustment = gtk_scrollable_get_vadjustment(GTK_SCROLLABLE(child));
    g_signal_connect(vadjustment, "value-changed", G_CALLBACK(on_adjustment_value_changed), NULL);

    return scrolled_window;
}