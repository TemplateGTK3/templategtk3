/*
 * Copyright (C) Laurent LAMARD 2016
 *
 * gepub is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * bijiben is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>

#include "exampleapp.h"
#include "exampleappwin.h"

struct _ExampleAppWindow
{
    GtkApplicationWindow parent;
};

struct _ExampleAppWindowClass
{
    GtkApplicationWindowClass parent_class;
};

typedef struct _ExampleAppWindowPrivate ExampleAppWindowPrivate;

struct _ExampleAppWindowPrivate
{
    GtkWidget *stack;
};

G_DEFINE_TYPE_WITH_PRIVATE(ExampleAppWindow, example_app_window, GTK_TYPE_APPLICATION_WINDOW)

static void example_app_window_init (ExampleAppWindow *win)
{

    gtk_widget_init_template (GTK_WIDGET (win));
}

static void example_app_window_class_init (ExampleAppWindowClass *pclass)
{    
   gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (pclass),
          "/org/gtk/exampleapp/window.ui");

   //gtk_widget_class_bind_template_child_private (GTK_WIDGET_CLASS (pclass), ExampleAppWindow, stack);
}

ExampleAppWindow * example_app_window_new (ExampleApp *app)
{
    return g_object_new (EXAMPLE_APP_WINDOW_TYPE, "application", app, NULL);
}

void example_app_window_open (ExampleAppWindow *win,
                         GFile            *file)
{

}
