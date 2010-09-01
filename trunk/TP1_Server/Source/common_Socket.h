#ifndef SOCKET_H_
#define SOCKET_H_
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <netdb.h>
//#include <unistd.h>
#include <string>
#include <winsock.h>
//#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

const int MAXRECV = 100;

using namespace std;

class Socket
{
	private:
		int sockfd;
		int cantConexiones;
		int puerto;
		bool valido;
		string msgError;
		
		Socket(const int sockfd); // constructor privado
		
		bool abrir();
		bool bindear();
	
	public:
		Socket();
		Socket(const int cantConexiones, const int puerto);
		virtual ~Socket();
				
		// Metodos exclusivos para Servidor
		bool escuchar();
		Socket* aceptar();
		
		// Metodo exclusivo para Cliente
		bool conectar(const string& host);
		
		// Metodos para Servidor y Cliente
		bool enviar(const string msg, const int longMsg);
		bool recibir(string& msg);		
		bool cerrar();
						
		bool shutdown();
		bool esValido();
};

#endif /*SOCKET_H_*/
