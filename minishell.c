#include <gtk/gtk.h>

static void app_activate(GApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(GTK_APPLICATION(app));
    gtk_window_set_title(GTK_WINDOW(window), "Mini Shell");     // Nom de la fenêtre
    gtk_window_set_default_size(GTK_WINDOW(window), 700, 450);  // Taille de la fenêtre
    gtk_window_present(GTK_WINDOW(window));                     // Affiche la fenêtre au premier plan
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);        // Empèche le redimensionnement
    gtk_widget_set_name(window, "main-window");                 // Donne un nom à la fenêtre pour le CSS

    // Création d'une box verticale
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);  // "0" Espace entre les widgets
    gtk_widget_set_name(vbox, "vbox");
    gtk_widget_set_vexpand(vbox, TRUE);  // Permet au champ de s'étirer

    // Création d'un label d'info fixe en haut
    GtkWidget *hbox_info_label = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    GtkWidget *info_label = gtk_label_new("MiniShell v1.0 - Un terminal simple\n");
    gtk_widget_set_name(info_label, "info-label");
    gtk_box_append(GTK_BOX(hbox_info_label), info_label);
    gtk_box_append(GTK_BOX(vbox), hbox_info_label);
    gtk_window_set_child(GTK_WINDOW(window), vbox);



    //////////////////
    // Code de ma page
    //////////////////

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

    // Ajout de mes box à la fenêtre
    gtk_box_append(GTK_BOX(vbox), hbox);
    gtk_window_set_child(GTK_WINDOW(window), vbox);



    // Création du CSS pour ma fenêtre
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "style.css");  // Liason au fichier "style.css"

    // Récupère l'affichage par défaut (l'écran principal de l'utilisateur)
    GdkDisplay *display = gdk_display_get_default();
    gtk_style_context_add_provider_for_display(display, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);  // Applique le CSS à ma fenêtre avec une priorité élevée
}

int main(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("org.example.GtkApp", G_APPLICATION_FLAGS_NONE);

    g_signal_connect(app, "activate", G_CALLBACK(app_activate), NULL);

    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}