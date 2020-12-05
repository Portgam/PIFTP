#ifndef MODELOCOLUMNAS_H_INCLUDED
#define MODELOCOLUMNAS_H_INCLUDED

#include <gtkmm/treemodelcolumn.h>

class ModeloColumnas : public Gtk::TreeModelColumnRecord{
public:
    ModeloColumnas()
    {
        add(tipo_archivo);
        add(nombre_archivo);
        add(ultima_modificacion_archivo);
        add(tamanio_archivo);
    }
    Gtk::TreeModelColumn<Glib::ustring> tipo_archivo;
    Gtk::TreeModelColumn<Glib::ustring> nombre_archivo;
    Gtk::TreeModelColumn<Glib::ustring> ultima_modificacion_archivo;
    Gtk::TreeModelColumn<Glib::ustring> tamanio_archivo;
    //Gtk::TreeModelColumn<Glib:> icono_archivo;
};

#endif // MODELOCOLUMNAS_H_INCLUDED
