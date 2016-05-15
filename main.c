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

int main (int argc, char *argv[])
{
  return g_application_run (G_APPLICATION (example_app_new ()), argc, argv);
}
