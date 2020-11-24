#ifndef VENTANAPRINCIPAL_H_INCLUDED
#define VENTANAPRINCIPAL_H_INCLUDED

#include <gtkmm.h>

class W_principal : public Gtk::Window {
private:
    Gtk::Box b_cajaPrincipal;
    /// Caja 1
    Gtk::Box b_caja1;
    Gtk::Label l_host;
    Gtk::Label l_puerto;
    Gtk::Entry e_host;
    Gtk::Entry e_puerto;
    Gtk::Button b_connectar;

    /// Caja 2
    Gtk::Box b_caja2;
    Gtk::Entry e_mensajes;

    /// Caja 3
    Gtk::Box b_caja3;
    Gtk::Button b_cargar;
    Gtk::Button b_descargar;
    Gtk::Button b_modificar;

    /// Caja 4
    Gtk::Box b_caja4;
    // Directory explorer
    Gtk::Box b_caja4_1;
    Gtk::FileChooserWidget fc_archivos;
    // File / directory Info
    Gtk::Box b_caja4_2;

    /// Caja 5
    Gtk::Box b_caja5;
    Gtk::ProgressBar pb_progreso;

public:
    W_principal();
    void set_caja1();
    void set_caja2();
    void set_caja3();
    void set_caja4();
    void set_caja5();
};



#endif // VENTANAPRINCIPAL_H_INCLUDED
