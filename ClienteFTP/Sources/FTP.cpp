#include <iostream>
#include <stdio.h>
#include <string>
#include <winsock2.h>
#include <winsock.h>
#include "../Headers/FTP.h"

Ftp::Ftp(){};

int Ftp::iniciar_socket()
{
    socket_conectar = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(socket_conectar == INVALID_SOCKET)
    {
        std::cout<<"Funcion de socket fallo con error: "<<WSAGetLastError()<<std::endl;
        WSACleanup();
        return -1;
    }
    return 1;
}

int Ftp::cerrar_socket()
{
    // Cerrar el socket
    resultado_conexion = closesocket(socket_conectar);
    if(resultado_conexion == SOCKET_ERROR)
    {
        std::cout<<"Cerrar el socket fallo con el error: "<<WSAGetLastError()<<std::endl;
        return -1;
    }
    return 1;
}

void Ftp::estructurar_addr()
{
    conexion_addr.sin_family = AF_INET;
    conexion_addr.sin_addr.s_addr = inet_addr(direccion_ip.c_str());
    conexion_addr.sin_port = htons(puerto);
}

int Ftp::conectar_al_servidor()
{
    // Realizar la conexion al servidor
    resultado_conexion = connect(socket_conectar, (SOCKADDR*)&conexion_addr, sizeof(conexion_addr));
    if(resultado_conexion == SOCKET_ERROR)
    {
        conectado = false;
        std::cout<<"Fallo la conexion con el error:"<<WSAGetLastError()<<std::endl;
        resultado_conexion = closesocket(socket_conectar);
        if(resultado_conexion == SOCKET_ERROR)
        {
            std::cout<<"Cierre de la conexion fallo con el error:"<<WSAGetLastError()<<std::endl;
        }
        WSACleanup();
        return -1;
    }
    conectado = true;
    shutdown_socket();
    recivir_respuesta_de_servidor();
    cerrar_socket();
    WSACleanup();

    return 1;
}

int Ftp::recivir_respuesta_de_servidor()
{
    char recvBuffer[255];
    // Recibir respuesta del servidor
    do
    {
        resultado_conexion = recv(socket_conectar, recvBuffer, 255, 0);
        if(resultado_conexion > 0)
            std::cout<<"Bytes recibidos: "<<resultado_conexion<<std::endl;
        else if(resultado_conexion == 0)
            std::cout<<"Conexion cerrada"<<std::endl;
        else
            std::cout<<"Recv fallo con el error: "<<WSAGetLastError()<<std::endl;

    }while(resultado_conexion > 0);
    std::cout<<recvBuffer<<std::endl;
    return 0;
}

int Ftp::shutdown_socket()
{
    resultado_conexion = shutdown(socket_conectar, SD_SEND);
    if(resultado_conexion == SOCKET_ERROR)
    {
        std::cout<<"Shutdown fallo con el error: "<<WSAGetLastError()<<std::endl;
        cerrar_socket();
        WSACleanup();
        return -1;
    }
    return 1;
}

int Ftp::_user()
{
    // Darle formato al comando
    char sendBuffer[255];
    memset(sendBuffer, '\0', 255);
    sprintf(sendBuffer, "USER %s\r\n", usuario.c_str());
    resultado_conexion = send(socket_conectar, sendBuffer, (int)strlen(sendBuffer),0);
    std::cout<<"Bytes enviados: "<<resultado_conexion<<std::endl;
    if(resultado_conexion == SOCKET_ERROR)
    {
        std::cout<<"Envio de usuario fallo con error: "<<WSAGetLastError();
        cerrar_socket();
        WSACleanup();
        return -1;
    }
    // Recivir respuesta
    recivir_respuesta_de_servidor();
    cerrar_socket();
    return 1;
}

int Ftp::_pass()
{
    // Darle formato al comando
    char sendBuffer[255];
    memset(sendBuffer, '\0', 255);
    sprintf(sendBuffer, "PASS %s\r\n", pase.c_str());
    resultado_conexion = send(socket_conectar, sendBuffer, (int)strlen(sendBuffer),0);
    std::cout<<"Bytes enviados: "<<resultado_conexion<<std::endl;
    if(resultado_conexion == SOCKET_ERROR)
    {
        std::cout<<"Envio de usuario fallo con error: "<<WSAGetLastError();
        cerrar_socket();
        WSACleanup();
        return -1;
    }
    // Recivir respuesta
    recivir_respuesta_de_servidor();
    cerrar_socket();
    return 1;
}

int Ftp::_feat()
{
    char sendBuffer[255];
    memset(sendBuffer, '\0', 255);
    sprintf(sendBuffer, "FEAT\r\n");
    resultado_conexion = send(socket_conectar, sendBuffer, (int)strlen(sendBuffer),0);
    std::cout<<"Bytes enviados: "<<resultado_conexion<<std::endl;
    if(resultado_conexion == SOCKET_ERROR)
    {
        std::cout<<"Envio de usuario fallo con error: "<<WSAGetLastError();
        cerrar_socket();
        WSACleanup();
        return -1;
    }
    // Recivir respuesta
    recivir_respuesta_de_servidor();
    cerrar_socket();
    return 1;
}

int Ftp::_list()
{
    char sendBuffer[255];
    memset(sendBuffer, '\0', 255);
    sprintf(sendBuffer, "LIST\r\n");
    resultado_conexion = send(socket_conectar, sendBuffer, (int)strlen(sendBuffer),0);
    std::cout<<"Bytes enviados: "<<resultado_conexion<<std::endl;
    if(resultado_conexion == SOCKET_ERROR)
    {
        std::cout<<"Envio de usuario fallo con error: "<<WSAGetLastError();
        cerrar_socket();
        WSACleanup();
        return -1;
    }
    // Recivir respuesta
    recivir_respuesta_de_servidor();
    cerrar_socket();
    return 1;
}

void Ftp::set_ip(std::string x)
{ direccion_ip = x;}

void Ftp::set_puerto(std::string x)
{ puerto = std::stoi(x);}

void Ftp::set_usuario(std::string x)
{ usuario = x;}

void Ftp::set_pase(std::string x)
{ pase = x;}
