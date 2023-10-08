#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <pthread.h>

int contador;

//Estructura necesaria para acceso excluyente
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int i;
int sockets[100];

void *AtenderCliente (void *socket)
{
	int sock_conn;
	int *s;
	s= (int *) socket;
	sock_conn= *s;
	
	//int socket_conn = * (int *) socket;
	
	char peticion[512];
	char respuesta[512];
	int ret;
	
	
	int terminar =0;
	// Entramos en un bucle para atender todas las peticiones de este cliente
	//hasta que se desconecte
	while (terminar ==0)
	{
		// Ahora recibimos la petici?n
		ret=read(sock_conn,peticion, sizeof(peticion));
		printf ("Recibido\n");
		
		// Tenemos que anadirle la marca de fin de string 
		// para que no escriba lo que hay despues en el buffer
		peticion[ret]='\0';
		
		
		printf ("Peticion: %s\n",peticion);
		
		// vamos a ver que quieren
		char *p = strtok(peticion, "/");
		int codigo =  atoi (p);
		int numForm;
		// Ya tenemos el c?digo de la petici?n
		char nombre[20];
		
		if (codigo !=0)
		{
			p = strtok( NULL, "/");
			numForm =  atoi (p);
			p = strtok( NULL, "/");
			strcpy (nombre, p);
			// Ya tenemos el nombre
			printf ("Codigo: %d, Nombre: %s\n", codigo, nombre);
		}
		
		if (codigo ==0) //peticion de desconexion
		{
			terminar=1;
		}
		else if (codigo ==1) //Piden la longitd del nombre
		{
			sprintf (respuesta,"1/%d/%d",numForm,strlen (nombre));
		}
		else if (codigo ==2) //Quieren saber si el nombre es bonito
		{
			if((nombre[0]=='M') || (nombre[0]=='S'))
			sprintf (respuesta,"2/%d/SI", numForm);
			else
				sprintf (respuesta,"2/%d/NO", numForm);
		}
		else if (codigo ==3) //Quiere saber si es alto
		{
			p = strtok( NULL, "/");
			float altura =  atof (p);
			if (altura > 1.70)
				sprintf (respuesta, "3/%d/%s: eres alto",numForm,nombre);
			else
				sprintf (respuesta, "3/%d/%s: eres bajo",numForm, nombre);
		}
			
		else if	(codigo == 4) //Quieren saber si el nombre es palindromo
		{
			int numeroletraactual1 = 0;
			int numeroletraactual2 = (strlen(nombre)-1);		
			int x = strlen(nombre)/2;
			char nombreenmayus[20];
			
			//Pone el nombre en mayusculas para poder evitar distinciones
			//por tener caracteres en mayusculas o minusculas
			for(int i=0; nombre[i] != '\0'; i++)
			{
				nombreenmayus[i] = toupper(nombre[i]);
			}
			
			//Comprobamos si el número es par o no
			if (strlen(nombre)%2 == 0)
			{
				while(numeroletraactual1 != x)
				{
					if(nombreenmayus[numeroletraactual1] != nombreenmayus[numeroletraactual2])
					{
						sprintf (respuesta, "4/%d/%s: no es un nombre palindromo", numForm, nombre);
						numeroletraactual1 = x;
					}
					else
					{
						numeroletraactual1 = numeroletraactual1 + 1;
						numeroletraactual2 = numeroletraactual2 - 1;
						sprintf (respuesta, "4/%d/%s: es un nombre palindromo", numForm, nombre);
					}
					
				}
			}
			//Que hacer en caso de que el nombre tenga un número
			//de caracteres impar
			else
			{
				//Sumamos 1 para que asi el número quede en uno más que la mitad,
				//de tal manera que el while se parara cuando ya hayamos cruzado
				//la mitad de la palabra
				int y = x + 1;
				
				while(numeroletraactual1 != y)
				{
					printf("%c\n", nombreenmayus[numeroletraactual1]);
					printf("%c\n", nombreenmayus[numeroletraactual2]);
					if(nombreenmayus[numeroletraactual1] != nombreenmayus[numeroletraactual2])
					{
						sprintf (respuesta, "4/%d/%s: no es un nombre palindromo", numForm, nombre);
						numeroletraactual1 = y;
					}
					else
					{
						numeroletraactual1 = numeroletraactual1 + 1;
						numeroletraactual2 = numeroletraactual2 - 1;
						sprintf (respuesta, "4/%d/%s: es un nombre palindromo", numForm, nombre);
					}
				}
			}
		}	
		else if (codigo == 5) //Quieren saber como es su nombre en mayusculas
		{
			char nombreenmayus[20];
			
			//Pone el nombre en mayusculas para poder evitar distinciones
			//por tener caracteres en mayusculas o minusculas
			for(int i=0; nombre[i] != '\0'; i++)
			{
				nombreenmayus[i] = toupper(nombre[i]);
			}
			
			sprintf (respuesta, "5/%d/%s es tu nombre en mayusculas", numForm, nombreenmayus);
		}
		if (codigo !=0)
		{
				printf ("Respuesta: %s\n", respuesta);
				// Enviamos respuesta
				write (sock_conn,respuesta, strlen(respuesta));
		}
		if ((codigo ==1) || (codigo==2) || (codigo==3) || (codigo==4) || (codigo==5))
		{
				pthread_mutex_lock( &mutex ); //No me interrumpas ahora
				contador = contador +1;
				pthread_mutex_unlock( &mutex); //ya puedes interrumpirme
				// notificar a todos los clientes conectados
				char notificacion[20];
				sprintf (notificacion, "6/%d",contador);
				int j;
				for (j=0; j< i; j++)
					write (sockets[j],notificacion, strlen(notificacion));
				
		}
	}
	// Se acabo el servicio para este cliente
	close(sock_conn); 
	
}


int main(int argc, char *argv[])
{
	
	int sock_conn, sock_listen;
	struct sockaddr_in serv_adr;
	
	// INICIALITZACIONS
	// Obrim el socket
	if ((sock_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		printf("Error creant socket");
	// Fem el bind al port
	
	
	memset(&serv_adr, 0, sizeof(serv_adr));// inicialitza a zero serv_addr
	serv_adr.sin_family = AF_INET;
	
	// asocia el socket a cualquiera de las IP de la m?quina. 
	//htonl formatea el numero que recibe al formato necesario
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	// establecemos el puerto de escucha
	serv_adr.sin_port = htons(9050);
	if (bind(sock_listen, (struct sockaddr *) &serv_adr, sizeof(serv_adr)) < 0)
		printf ("Error al bind");
	
	if (listen(sock_listen, 3) < 0)
		printf("Error en el Listen");
	
	contador =0;
	
	pthread_t thread;
	i=0;
	for (;;){
		printf ("Escuchando\n");
		
		sock_conn = accept(sock_listen, NULL, NULL);
		printf ("He recibido conexion\n");
		
		sockets[i] =sock_conn;
		//sock_conn es el socket que usaremos para este cliente
		
		// Crear thead y decirle lo que tiene que hacer
		
		pthread_create (&thread, NULL, AtenderCliente,&sockets[i]);
		i=i+1;
		
	}
	

	
}
