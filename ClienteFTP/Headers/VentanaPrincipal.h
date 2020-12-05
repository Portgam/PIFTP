#ifndef VENTANAPRINCIPAL_H_INCLUDED
#define VENTANAPRINCIPAL_H_INCLUDED

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/treeview.h>
#include <gtkmm/liststore.h>
#include <gtkmm/progressbar.h>
#include <gtkmm/filechooserwidget.h>
#include <gtkmm/widget.h>
//#include <gtkmm.h>
#include <iostream>
#include <string>
#include "../Headers/Modelocolumnas.h"
#include "../Headers/FTP.h"

class W_principal : public Gtk::Window {
private:
    // FTP
    Ftp servidor_ftp;
    Gtk::Box b_cajaPrincipal;
    // Modificar nombre.
    std::string modificar_nombre_antes;
    std::string modificar_nombre_despues;
    int archivo_o_carpeta;
    // Modificar nombre de carpeta/archivo GUI
    Gtk::Dialog d_modificar_nombre;
    Gtk::Box b_contendor_modificar_nombre;
    Gtk::Label l_texto;
    Gtk::Entry e_nombre;
    Gtk::Button b_aceptar_cambiar_nombre;
    Gtk::Button b_cancelar_cambio_nombre;
    // Subir archivo
    Gtk::Dialog d_seleccionar_archivos;
    Gtk::FileChooserWidget fc_seleccionar_archivo;
    Gtk::Button b_seleccionar_aceptar;
    Gtk::Button b_seleccionar_cancelar;
    std::string subir_archivo_nombre;

    /// Caja 1
    Gtk::Box b_caja1;
    Gtk::Label l_host;
    Gtk::Label l_puerto;
    Gtk::Label l_usuario;
    Gtk::Label l_pass;
    Gtk::Entry e_host;
    Gtk::Entry e_puerto;
    Gtk::Entry e_usuario;
    Gtk::Entry e_pass;
    Gtk::Button b_connectar;

    /// Caja 2
    Gtk::Box b_caja2;
    Gtk::Entry e_mensajes;

    /// Caja 3
    Gtk::Box b_caja3;
    Gtk::Button b_cargar;
    Gtk::Button b_descargar;
    Gtk::Button b_nueva_carpeta;
    Gtk::Button b_cambiar_nombre;

    /// Caja 4
    Gtk::Box b_caja4;
    // Directory explorer
    Gtk::Box b_caja4_1;
    ModeloColumnas modelo_columnas;
    Glib::RefPtr<Gtk::ListStore> ls_archivos_columnas;
    Glib::RefPtr<Gtk::TreeModelFilter> tmf_archivos_filtro;
    Glib::RefPtr<Gtk::TreeSelection> ts_archivos_seleccion;
    Gtk::TreeView tv_archivos;

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

    // Ventana de modificar nombre
    void set_caja_modifcar_nombre();
    void cancelar_modifcar_nombre();
    void aceptar_modifcar_nombre();
    // Ventana de seleccionar archivo.
    void set_caja_seleccionar_archivo();
    void cancelar_seleccionar_archivo();
    void aceptar_seleccionar_archivo();

    void agregar_filas(Glib::ustring tipo, Glib::ustring nombre, Glib::ustring modificacion, Glib::ustring tamanio);
    void refrescar_archivos();

    void set_addr(Glib::ustring ip, Glib::ustring port, Glib::ustring user, Glib::ustring pass);

    // Caja 1
    void on_button_pressed_b_conectar();
    // Caja 3
    void on_button_pressed_b_cargar();
    void on_button_pressed_b_descargar();
    void on_button_pressed_b_nueva_carpeta();
    void on_button_pressed_b_cambiar_nombre();
    // Caja 4
    void on_button_pressed_tv_archivos();
    void on_row_double_pressed_tv_archivos();
    // Cambiar nombre de archivo.
    void on_button_pressed_b_aceptar_cambiar_nombre();
    void on_button_pressed_b_cancelar_cambio_nombre();
    // Seleccionar archivo.
    void on_button_pressed_b_seleccionar_aceptar();
    void on_button_pressed_b_seleccionar_cancelar();
};



#endif // VENTANAPRINCIPAL_H_INCLUDED
