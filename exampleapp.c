#include <gtk/gtk.h>

#include "exampleapp.h"
#include "exampleappwin.h"

struct _ExampleApp
{
    GtkApplication parent;

    int version;
};

struct _ExampleAppClass
{
    GtkApplicationClass parent_class;
};

G_DEFINE_TYPE(ExampleApp, example_app, GTK_TYPE_APPLICATION)

static void
example_app_init (ExampleApp *app)
{
     g_print("%s\n",__func__);
}

static void
preferences_activated (GSimpleAction *action,
                       GVariant      *parameter,
                       gpointer       app)
{
     g_print("%s\n",__func__);
}

static void
quit_activated (GSimpleAction *action,
                GVariant      *parameter,
                gpointer       app)
{
    g_print("%s\n",__func__);

    GtkApplication *ap = GTK_APPLICATION (app);
    GtkWidget* win = GTK_WIDGET(gtk_application_get_windows(ap)->data);

    gtk_window_close (GTK_WINDOW (win));
}

static void about_activated(GSimpleAction *action,GVariant *parameter, gpointer  app)
{

    g_print("%s\n",__func__);
}

static const GActionEntry app_entries[] =
{
    { "preferences", preferences_activated, NULL, NULL, NULL },
    { "about", about_activated, NULL, NULL, NULL },
    { "quit", quit_activated, NULL, NULL, NULL }
};

static void example_app_startup (GApplication *app)
{
    g_print("%s\n",__func__);
    GtkBuilder *builder;
    GMenuModel *menu;

    const gchar *quit_accels[2] = { "<Ctrl>Q", NULL };

    G_APPLICATION_CLASS (example_app_parent_class)->startup (app);

    g_action_map_add_action_entries (G_ACTION_MAP (app),
                                     app_entries, G_N_ELEMENTS (app_entries),
                                     app);

    gtk_application_set_accels_for_action (GTK_APPLICATION (app),
                                           "app.quit",
                                           quit_accels);

    builder = gtk_builder_new_from_resource ("/org/gtk/exampleapp/menu.ui");
    // se up application menu
    menu = G_MENU_MODEL (gtk_builder_get_object (builder, "appmenu"));
    gtk_application_set_app_menu (GTK_APPLICATION (app), menu);
    // set up window menu
    menu = (GMenuModel *)gtk_builder_get_object (builder, "menubar");
    gtk_application_set_menubar (GTK_APPLICATION (app), menu);

    g_object_unref (builder);
}

static void example_app_activate (GApplication *app)
{
    ExampleAppWindow *win;

    win = example_app_window_new (EXAMPLE_APP (app));
    gtk_window_present (GTK_WINDOW (win));
}


static void
example_app_open (GApplication  *app,
                  GFile        **files,
                  gint           n_files,
                  const gchar   *hint)
{
    GList *windows;
    ExampleAppWindow *win;
    int i;

    windows = gtk_application_get_windows (GTK_APPLICATION (app));
    if (windows)
        win = EXAMPLE_APP_WINDOW (windows->data);
    else
        win = example_app_window_new (EXAMPLE_APP (app));

    for (i = 0; i < n_files; i++)
        example_app_window_open (win, files[i]);

    gtk_window_present (GTK_WINDOW (win));
}



static void example_app_class_init (ExampleAppClass *pclass)
{

    GObjectClass *objclass = G_OBJECT_CLASS (pclass);

    GApplicationClass*   appclass = G_APPLICATION_CLASS (pclass);

    appclass->startup = example_app_startup;
    appclass->activate = example_app_activate;
    appclass->open = example_app_open;    
}

ExampleApp *
example_app_new (void)
{
    return g_object_new (EXAMPLE_APP_TYPE,
                         "application-id", "org.gtk.exampleapp",
                         "flags", G_APPLICATION_HANDLES_OPEN,
                         NULL);
}
