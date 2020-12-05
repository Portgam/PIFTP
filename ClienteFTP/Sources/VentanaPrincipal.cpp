#include <iostream>
#include <gtkmm.h>
#include <filesystem>
#include <string>
#include "../Headers/VentanaPrincipal.h"
#include "../Headers/FuncionesBotones.h"

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
    set_caja_modifcar_nombre();
    set_caja_seleccionar_archivo();

    this->show_all_children();
    this->set_title("Cliente FTP");
    this->set_default_size(800, 300);
    //this->maximize();
}

void W_principal::set_caja1(){
    b_caja1.add(l_host);
    b_caja1.add(e_host);
    b_caja1.add(l_puerto);
    b_caja1.add(e_puerto);
    b_caja1.add(l_usuario);
    b_caja1.add(e_usuario);
    b_caja1.add(l_pass);
    b_caja1.add(e_pass);
    b_caja1.add(b_connectar);

    l_host.set_label("Host");
    l_puerto.set_label("Puerto");
    l_usuario.set_label("Usuario");
    l_pass.set_label("Pase");
    b_connectar.set_label("Conectar");

    e_host.set_text("192.168.0.10");
    e_puerto.set_text("21");
    e_usuario.set_text("usuario1");
    e_pass.set_text("123456");

    b_connectar.signal_clicked().connect(sigc::mem_fun(this,&W_principal::on_button_pressed_b_conectar));
}

void W_principal::set_caja2(){
    b_caja2.add(e_mensajes);
    e_mensajes.set_text("Hola Mundo");
}

void W_principal::set_caja3(){
    b_caja3.set_orientation(Gtk::Orientation::ORIENTATION_HORIZONTAL);
    b_caja3.add(b_cargar);
    b_caja3.add(b_descargar);
    b_caja3.add(b_nueva_carpeta);
    b_caja3.add(b_cambiar_nombre);

    b_cargar.set_label("CargarArchivo");
    b_descargar.set_label("Descargar");
    b_nueva_carpeta.set_label("Nueva carpeta");
    b_cambiar_nombre.set_label("Cambiar nombre");

    b_cargar.signal_clicked().connect(sigc::mem_fun(this,&W_principal::on_button_pressed_b_cargar));
    b_descargar.signal_clicked().connect(sigc::mem_fun(this,&W_principal::on_button_pressed_b_descargar));
    b_nueva_carpeta.signal_clicked().connect(sigc::mem_fun(this,&W_principal::on_button_pressed_b_nueva_carpeta));
    b_cambiar_nombre.signal_clicked().connect(sigc::mem_fun(this,&W_principal::on_button_pressed_b_cambiar_nombre));
}

void W_principal::set_caja4(){
    b_caja4.set_orientation(Gtk::Orientation::ORIENTATION_HORIZONTAL);
    b_caja4.add(tv_archivos);
    ls_archivos_columnas = Gtk::ListStore::create(modelo_columnas);
    tmf_archivos_filtro = Gtk::TreeModelFilter::create(ls_archivos_columnas);
    ts_archivos_seleccion = tv_archivos.get_selection();
    ts_archivos_seleccion->set_mode(Gtk::SELECTION_SINGLE);
    tv_archivos.set_model(tmf_archivos_filtro);

    tv_archivos.append_column("Tipo.", modelo_columnas.tipo_archivo);
    tv_archivos.append_column("Nombre de archivo.", modelo_columnas.nombre_archivo);
    tv_archivos.append_column("Ultima fecha de modificacion.", modelo_columnas.ultima_modificacion_archivo);
    tv_archivos.append_column("Tamanio", modelo_columnas.tamanio_archivo);

    agregar_filas(".txt", "Archivo_0.txt", "03/12/2020", "303kb");
    agregar_filas(".txt", "Archivo_1.txt", "03/12/2020", "303kb");
    agregar_filas(".txt", "Archivo_2.txt", "03/12/2020", "303kb");
}

void W_principal::set_caja5(){
    b_caja5.set_orientation(Gtk::Orientation::ORIENTATION_HORIZONTAL);
    b_caja5.add(pb_progreso);
    pb_progreso.set_text("Barra de progreso");
    pb_progreso.set_show_text(true);
}

void W_principal::set_caja_modifcar_nombre()
{
    b_contendor_modificar_nombre.set_orientation(Gtk::Orientation::ORIENTATION_HORIZONTAL);
    b_contendor_modificar_nombre.add(l_texto);
    b_contendor_modificar_nombre.add(e_nombre);
    b_contendor_modificar_nombre.add(b_aceptar_cambiar_nombre);
    b_contendor_modificar_nombre.add(b_cancelar_cambio_nombre);
    d_modificar_nombre.add(b_contendor_modificar_nombre);

    l_texto.set_label("Nuevo nombre");
    b_cambiar_nombre.set_label("Aceptar");
    b_cancelar_cambio_nombre.set_label("Cancelar");


    b_aceptar_cambiar_nombre.signal_clicked().connect(sigc::mem_fun(this, &W_principal::aceptar_modifcar_nombre));
    b_cancelar_cambio_nombre.signal_clicked().connect(sigc::mem_fun(this, &W_principal::cancelar_modifcar_nombre));
}

void W_principal::set_caja_seleccionar_archivo()
{
    //std::cout<<"set_caja_seleccionar_archivo"<<std::endl;
    d_seleccionar_archivos.add(fc_seleccionar_archivo);
    d_seleccionar_archivos.add(b_seleccionar_aceptar);
    d_seleccionar_archivos.add(b_seleccionar_cancelar);

    fc_seleccionar_archivo.set_current_folder("./Headers");
    b_seleccionar_aceptar.set_label("Aceptar");
    b_seleccionar_cancelar.set_label("Cancelar");
}

void W_principal::cancelar_modifcar_nombre()
{
    std::cout<<modificar_nombre_despues<<std::endl;
    e_nombre.set_text("");
    d_modificar_nombre.close();
}

void W_principal::aceptar_modifcar_nombre()
{
    modificar_nombre_antes = e_nombre.get_text();
    e_nombre.set_text("");
    d_modificar_nombre.close();
}

void W_principal::agregar_filas(Glib::ustring tipo, Glib::ustring nombre, Glib::ustring modificacion, Glib::ustring tamanio){
    // Agregar fila a tv_archivos.
    Gtk::TreeModel::Row fila = *(ls_archivos_columnas->append());
    fila[modelo_columnas.tipo_archivo] = tipo;
    fila[modelo_columnas.nombre_archivo] = nombre;
    fila[modelo_columnas.ultima_modificacion_archivo] = modificacion;
    fila[modelo_columnas.tamanio_archivo] = tamanio;
}

