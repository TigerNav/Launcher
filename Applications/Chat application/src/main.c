/**
 * @file main.c
 * 
 * @author your name (@TigerNav)
 * @brief Inits GTK and all of its stuff. I dont like a lot of stuff in my main method so yea
 * 
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <gtk-3.0/gtk/gtk.h>
#include <gtk-3.0/gtk/gtkx.h>
#include "ui.h"

int main(int argc, char *argv[]) {
    
    gtk_init(&argc, &argv);

    UI();

    gtk_main();

    return 0;

}
