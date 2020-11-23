#include <iostream>
#include <gtkmm.h>
#include "./Headers/VentanaPrincipal.h"

int main(int argc, char **argv)
{
    std::cout << "Hello world!" << std::endl;
    std::cout << "Iniciar aplicacion" << std::endl;

    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");
    Gtk::Window window;
    W_principal ventanaPrin;
    window.set_default_size(200, 200);

    //ventanaPrin.set_title("Cliente FTP");
    //ventanaPrin.set_default_size(800, 200);

    return app->run(ventanaPrin);
}
