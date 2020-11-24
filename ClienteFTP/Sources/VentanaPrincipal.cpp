#include <iostream>
#include <gtkmm.h>
#include "../Headers/VentanaPrincipal.h"

W_principal::W_principal(){
    this->add(b_cajaPrincipal);
    b_cajaPrincipal.set_orientation(Gtk::Orientation::ORIENTATION_VERTICAL);

    b_cajaPrincipal.add(b_caja1);
    b_cajaPrincipal.add(b_caja2);
    b_cajaPrincipal.add(b_caja3);
    b_cajaPrincipal.add(b_caja4);
    b_cajaPrincipal.add(b_caja5);

    set_caja1();
    set_caja2();
    set_caja3();
    set_caja4();
    set_caja5();

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

void W_principal::set_caja2(){
    b_caja2.add(e_mensajes);
    e_mensajes.set_text("Hola Mundo");
}

void W_principal::set_caja3(){
    b_caja3.set_orientation(Gtk::Orientation::ORIENTATION_HORIZONTAL);
    b_caja3.add(b_cargar);
    b_caja3.add(b_descargar);
    b_caja3.add(b_modificar);

    b_cargar.set_label("CargarArchivo");
    b_descargar.set_label("Descargar");
    b_modificar.set_label("Modificar");
}

void W_principal::set_caja4(){
    b_caja4.set_orientation(Gtk::Orientation::ORIENTATION_HORIZONTAL);
    b_caja4.add(b_caja4_1);

    b_caja4_1.add(tv);
    tv.set_model(sl_dir);
    tv.append_column("nombredir", columnasDir.m_col_text);

}

void W_principal::set_caja5(){
    b_caja5.set_orientation(Gtk::Orientation::ORIENTATION_HORIZONTAL);
    b_caja5.add(pb_progreso);
    pb_progreso.set_text("Barra de progreso");
    pb_progreso.set_show_text(true);
}

void W_principal::refrescar_directorios(Gtk::TreeStore *treestore, const char *directorio, Gtk::TreeIter *nivel){

}

