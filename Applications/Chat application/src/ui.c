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


void 
UI()                        {

    builder = gtk_builder_new_from_file("/home/navin/Desktop/Programming shit i did/Launcher/Applications/Chat application/src/GUI/GUI.glade");

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    connect_gui_components();

    gtk_widget_show(window);

}

void 
connect_gui_components()    {

    gtk_builder_connect_signals(builder, NULL);

    DefineJson();
    DefineElements(builder);

}