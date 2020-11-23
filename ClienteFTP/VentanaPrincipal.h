#ifndef VENTANAPRINCIPAL_H_INCLUDED
#define VENTANAPRINCIPAL_H_INCLUDED

#include <gtkmm.h>

class W_principal : public Gtk::Window {
private:
    Gtk::Grid *Contenedor_principal;

public:
    W_principal();
};

class Contenedor : public Gtk::Grid {
private:
    Gtk::Label L_host;
    Gtk::Label L_usuario;
    Gtk::Label L_puerto;
    Gtk::Label L_cont;

public:
    Contenedor();
};

#endif // VENTANAPRINCIPAL_H_INCLUDED
