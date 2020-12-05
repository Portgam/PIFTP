#include <iostream>
#include <gtkmm/dialog.h>
#include "../Headers/FuncionesBotones.h"
#include "../Headers/VentanaPrincipal.h"

void W_principal::on_button_pressed_b_conectar()
{
    std::cout<<"Boton [conectar] presionado \n";
    servidor_ftp.set_ip(e_host.get_text());
    servidor_ftp.set_puerto(e_puerto.get_text());
    servidor_ftp.set_usuario(e_usuario.get_text());
    servidor_ftp.set_pase(e_pass.get_text());

    servidor_ftp.iniciar_socket();
    servidor_ftp.estructurar_addr();

    servidor_ftp.conectar_al_servidor();
    servidor_ftp._user();
    servidor_ftp._pass();
}

void W_principal::on_button_pressed_b_cargar()
{
    std::cout<<"Boton [cargar] presionado \n";
}

void W_principal::on_button_pressed_b_descargar()
{
    std::cout<<"Boton [descargar] presionado \n";
}

void W_principal::on_button_pressed_b_nueva_carpeta()
{
    std::cout<<"Boton [nueva_carpeta] presionado \n";
    Gtk::Dialog dialogo("Nueva carpeta", Gtk::DialogFlags::DIALOG_MODAL);
    dialogo.run();
}

void W_principal::on_button_pressed_tv_archivos()
{
    std::cout<<"TreeeView presionado \n";
}

void W_principal::on_row_double_pressed_tv_archivos()
{
    // Primero verificar si es carpeta o archivo.
    // Si es archivo: descargar.
    // Si es carpeta: cambiar de directorio.
    std::cout<<"Fila presionada \n";
}

void W_principal::on_button_pressed_b_cambiar_nombre()
{
    d_modificar_nombre.run();
}
