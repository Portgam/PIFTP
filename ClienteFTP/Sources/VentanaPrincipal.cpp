#include <iostream>
#include <gtkmm.h>
#include "../Headers/VentanaPrincipal.h"

W_principal::W_principal(){
    this->add(b_cajaPrincipal);
    b_cajaPrincipal.add(b_caja1);
    set_caja1();

    this->show_all_children();
    this->set_title("Cliente FTP");
    this->set_default_size(800, 300);
    this->maximize();
}

void W_principal::set_caja1(){
    b_caja1.add(l_host);
    b_caja1.add(e_host);
    b_caja1.add(l_puerto);
    b_caja1.add(e_puerto);
    b_caja1.add(b_connectar);

    l_host.set_label("Host");
    l_puerto.set_label("Puerto");
    b_connectar.set_label("Conectar");
}
