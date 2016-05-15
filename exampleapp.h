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
#ifndef __EXAMPLEAPP_H
#define __EXAMPLEAPP_H

#include <gtk/gtk.h>


#define EXAMPLE_APP_TYPE (example_app_get_type ())
#define EXAMPLE_APP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), EXAMPLE_APP_TYPE, ExampleApp))


typedef struct _ExampleApp       ExampleApp;
typedef struct _ExampleAppClass  ExampleAppClass;


GType           example_app_get_type    (void);
ExampleApp     *example_app_new         (void);


#endif /* __EXAMPLEAPP_H */
