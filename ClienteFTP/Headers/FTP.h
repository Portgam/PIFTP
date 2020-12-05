#ifndef FTP_H_INCLUDED
#define FTP_H_INCLUDED

#include <iostream>
#include <string>
#include <winsock2.h>
#include <winsock.h>
#include <vector>

struct Descarga{
    std::string nombre_archivo;
    int total_tam;
    int desc_tam;
};

class Ftp {
private:
    SOCKET socket_conectar;
    int resultado_conexion;
    sockaddr_in conexion_addr;
    bool conectado;

    std::string usuario, pase, direccion_ip;
    int puerto;

    std::string parent_directory;
    std::string current_directory;
    std::vector<std::string> ficheros_de_directorio;
    std::vector<std::string> ultimas_modificaciones_ficheros;
    std::vector<std::string> tams_ficheros;
    std::vector<int> extensiones_de_archivos;
    std::vector<int> indices_de_directorio;
public:
    Ftp();
    //void recibir();
    void set_usuario(std::string x);
    void set_pase(std::string x);
    void set_puerto(std::string x);
    void set_ip(std::string x);
    // Funciones de Socket
    int iniciar_socket();
    int cerrar_socket();
    int shutdown_socket();
    void estructurar_addr();
    //
    int conectar_al_servidor();
    int recivir_respuesta_de_servidor();
    // COMANDOS
    int _user();
    int _pass();
    int _feat();
    int _list();
    int _pwd();
};

#endif // FTP_H_INCLUDED
