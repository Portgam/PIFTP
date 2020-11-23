#ifndef VENTANAPRINCIPAL_H_INCLUDED
#define VENTANAPRINCIPAL_H_INCLUDED

#include <gtkmm.h>

class W_principal : public Gtk::Window {
private:
    /// Grid
    Gtk::Grid *Contenedor_principal;

public:
    W_principal();
};



#endif // VENTANAPRINCIPAL_H_INCLUDED
