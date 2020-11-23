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

public:
    W_principal();
    void set_caja1();
    void set_caja2();
};



#endif // VENTANAPRINCIPAL_H_INCLUDED
