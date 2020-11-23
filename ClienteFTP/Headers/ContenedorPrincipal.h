#ifndef CONTENEDORPRINCIPAL_H_INCLUDED
#define CONTENEDORPRINCIPAL_H_INCLUDED

#include <gtkmm.h>

class Contenedor : public Gtk::Grid {
private:
    /// Labels
    Gtk::Label L_host;
    Gtk::Label L_usuario;
    Gtk::Label L_puerto;
    Gtk::Label L_cont;
    /// Entry
    Gtk::Entry E_host;
    Gtk::Entry E_usuario;
    Gtk::Entry E_puerto;
    Gtk::Entry E_cont;
public:
    Contenedor();
};

#endif // CONTENEDORPRINCIPAL_H_INCLUDED
