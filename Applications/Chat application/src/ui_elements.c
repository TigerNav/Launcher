#include "ui_elements.h"

GtkWidget       *Submit;
GtkWidget       *TextArea;
GtkWidget       *Entry;
GtkWidget       *Label;

void 
DefineElements(GtkBuilder* builder)    {

    Submit          =       GTK_WIDGET(gtk_builder_get_object(builder, "Submit"));
    TextArea        =       GTK_WIDGET(gtk_builder_get_object(builder, "textarea"));
    Entry           =       GTK_WIDGET(gtk_builder_get_object(builder, "entry"));
    Label           =       GTK_WIDGET(gtk_builder_get_object(builder, "username"));

    gtk_label_set_text(GTK_LABEL(Label), getUsername());

}

GtkWidget* 
getSubmit()         {
    return Submit;
}

GtkWidget*
getTextArea()       {
    return TextArea;
}

GtkWidget*
getEntry()          {    
    return Entry;
}

