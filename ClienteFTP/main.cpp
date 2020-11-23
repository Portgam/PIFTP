#include <iostream>
#include <gtkmm.h>
#include <gtkmm/application.h>
#include <gtk/gtk.h>
#include "./Headers/VentanaPrincipal.h"
#include "./Headers/ContenedorPrincipal.h"

class VentanaEjm : public Gtk::Window{
private:
    Gtk::Label l_label;
    Gtk::Box b_caja;
    Gtk::Button b_boton1;
    Gtk::Button b_boton2;

    Gtk::Frame f_marco;

public:
    VentanaEjm();
};

VentanaEjm::VentanaEjm(){
    set_title("Ejemplo de marco");
    set_size_request(300, 300);

    f_marco.set_label("Gtk::Frame Widget");
    l_label.set_label("Label 1");
    b_boton1.set_label("Boton 1");
    b_boton2.set_label("Boton 2");

    add(b_caja);
    f_marco.add(l_label);
    b_caja.add(b_boton1);
    b_caja.add(b_boton2);
    b_caja.add(f_marco);
    b_caja.show_all_children();
    f_marco.show_all_children();

    show_all_children();
}


int main(int argc, char **argv)
{
    std::cout << "Hello world!" << std::endl;
    std::cout << "Iniciar aplicacion" << std::endl;

    W_principal ventana1;
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");
    //VentanaEjm ejemplo;
    //return app->run(ejemplo);
    return app->run(ventana1);
}
