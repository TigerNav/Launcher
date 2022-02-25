/**
 * @file ui.c
 * @author Navin Sethi (@TigerNav)
 * @brief everything for UI
 * @version 0.1
 * @date 2022-02-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "ui.h"

GtkBuilder      *builder;
GtkWidget       *window;
GtkTextBuffer   *TextBuffer;
GtkCssProvider  *provider;
GtkStyleContext *context;

char            tmp[1024];

void 
UI()                        {
    

    builder     =   gtk_builder_new_from_file("/home/navin/Desktop/Programming shit i did/Launcher/Applications/Chat application/src/GUI/GUI.glade");
    window      =   GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    provider    =   gtk_css_provider_new();
    

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    connect_gui_components();
    
    context     = gtk_widget_get_style_context(getTextArea());

    gtk_css_provider_load_from_path(provider, "/home/navin/Desktop/Programming shit i did/Launcher/Applications/Chat application/src/GUI/ui.css", NULL);
    
    gtk_style_context_add_provider(context,GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    TextBuffer  =   gtk_text_view_get_buffer(GTK_TEXT_VIEW(getTextArea()));
    
    strcpy(tmp, "fuck!");

    gtk_text_buffer_set_text(TextBuffer, tmp, -1);

    gtk_widget_show(window);

    ConnectToServer();

}

void 
connect_gui_components()    {

    gtk_builder_connect_signals(builder, NULL);

    DefineJson();
    DefineElements(builder);

}