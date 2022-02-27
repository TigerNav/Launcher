#ifndef UI_ELEMENTS_H
#define UI_ELEMENTS_H

#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include "json_info.h"

GtkWidget*      getEntry();
GtkWidget*      getTextArea();
GtkWidget*      getSubmit();
GtkTextBuffer*  getTextBuffer();
void            DefineElements(GtkBuilder* builder); 

#endif