#include <iostream>
#include <gtkmm.h>
#include "../Headers/VentanaPrincipal.h"

W_principal::W_principal(){
    add(Contenedor_principal);
    show_all_children();
}
