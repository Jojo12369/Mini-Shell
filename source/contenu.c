#include "../headers/contenu.h"
#include "../headers/message_start.h"
#include "../headers/terminal.h"
#include <math.h>

static gboolean
on_scroll(GtkEventControllerScroll *controller,
          double scroll_dx,
          double scroll_dy,
          gpointer user_data) {
    GtkWidget *scrolled_window = GTK_WIDGET(user_data);
    GtkWidget *child = gtk_scrolled_window_get_child(GTK_SCROLLED_WINDOW(scrolled_window));

    if (!GTK_IS_SCROLLABLE(child))
        return FALSE;

    GtkAdjustment *vadjustment = gtk_scrollable_get_vadjustment(GTK_SCROLLABLE(child));
    const double step = 19.0;
    double scroll_pixels = scroll_dy * step;

    if (fabs(scroll_pixels) < step)
        return FALSE;

    double value = gtk_adjustment_get_value(vadjustment);
    double lower = gtk_adjustment_get_lower(vadjustment);
    double upper = gtk_adjustment_get_upper(vadjustment) - gtk_adjustment_get_page_size(vadjustment);
    if (upper < lower)
        upper = lower;

    // Bloque le scroll hors limites
    if ((scroll_pixels > 0 && value >= upper) || (scroll_pixels < 0 && value <= lower))
        return TRUE;

    double new_value = value + scroll_pixels;

    // Clamp et arrondi au multiple de step
    if (new_value < lower) new_value = lower;
    else if (new_value > upper) new_value = upper;
    new_value = round(new_value / step) * step;

    if (new_value == value)
        return TRUE;

    gtk_adjustment_set_value(vadjustment, new_value);
    return TRUE;
}

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

    gtk_box_append(GTK_BOX(vbox), message_start());
    gtk_box_append(GTK_BOX(vbox), terminal());

    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window), vbox);

    GtkEventController *scroll_controller = gtk_event_controller_scroll_new(GTK_EVENT_CONTROLLER_SCROLL_VERTICAL);
    g_signal_connect(scroll_controller, "scroll", G_CALLBACK(on_scroll), scrolled_window);
    gtk_widget_add_controller(vbox, scroll_controller);

    return scrolled_window;
}