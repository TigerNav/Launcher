#include "ui_elements.h"

GtkWidget       *Submit;
GtkWidget       *Entry;
GtkWidget       *Label;
GtkWidget       *ScrollWindow;
GtkWidget       *viewport;
GtkWidget       *TextArea;
GtkTextBuffer   *TextBuffer;



void 
DefineElements(GtkBuilder* builder)    {

    Submit          =       GTK_WIDGET(gtk_builder_get_object(builder, "Submit"));
    Entry           =       GTK_WIDGET(gtk_builder_get_object(builder, "entry"));
    Label           =       GTK_WIDGET(gtk_builder_get_object(builder, "username"));
    ScrollWindow    =       GTK_WIDGET(gtk_builder_get_object(builder, "ScrollWindow"));
    viewport        =       GTK_WIDGET(gtk_builder_get_object(builder, "viewport"));
    TextArea        =       GTK_WIDGET(gtk_builder_get_object(builder, "TextArea"));

    TextBuffer      =       gtk_text_view_get_buffer(GTK_TEXT_VIEW(getTextArea()));

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

GtkTextBuffer*
getTextBuffer() {
    return TextBuffer;
}

