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

#ifndef __EXAMPLEAPPWIN_H
#define __EXAMPLEAPPWIN_H

#include <gtk/gtk.h>
#include "exampleapp.h"


#define EXAMPLE_APP_WINDOW_TYPE (example_app_window_get_type ())
#define EXAMPLE_APP_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), EXAMPLE_APP_WINDOW_TYPE, ExampleAppWindow))


typedef struct _ExampleAppWindow         ExampleAppWindow;
typedef struct _ExampleAppWindowClass    ExampleAppWindowClass;


GType                   example_app_window_get_type     (void);
ExampleAppWindow       *example_app_window_new          (ExampleApp *app);
void                    example_app_window_open         (ExampleAppWindow *win,
        GFile            *file);


#endif /* __EXAMPLEAPPWIN_H */
