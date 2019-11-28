#include <iostream>
#include <stdio.h>
#include <string>

#include "../Estructuras/grafo.hpp"
#include "../Base_de_datos/sqlite3.h"

using namespace GraphDS;

int print_records(void * data, int argc, char** argv, char** col_name)
{
    fprintf(stderr, "--- %s ---\n", (const char*)data);

    for( int i = 0; i < argc; ++i ){
      printf( "%s = %s\n", col_name[ i ], argv[ i ] ? argv[ i ] : "NULL" );
    }
    printf( "\n" );
    return 0;

}


int main(){
    Graph g;
	/*

    sqlite3* DataBase;
    int rc = sqlite3_open("./Base_de_datos/elementos.sqlite3", &DataBase);

    if ( rc ){
        fprintf(stderr,"No se pudo abrir la base de datos: %s\n",sqlite3_errmsg(DataBase));
        return(0);
    }else{ fprintf(stderr,"Base de Datos abierta exitosamente\n"); }

    char* sql = NULL;
    char* err_msg = NULL;
    const char* user_msg = "Callback llamada!";

    rc = sqlite3_exec(DataBase, nullptr, print_records, (void*)user_msg, &err_msg );

     if( rc != SQLITE_OK ){
      fprintf( stderr, "SQL error: %s\n", err_msg );
      sqlite3_free( err_msg );
    } else{ fprintf( stdout, "Hecho!\n" ); }

   sqlite3_close(DataBase);


*/

    /*
		1. Se le pide al usuario los elementos a insertar
		2. Se guardan en un arreglo, lista, etc.
		3. Se busca el elemento más electronegativo a excepcion del H
		4. Se realizan los enlaces, considerando:
			a. Los atomos de O no se enlazan entre ellos a excepción
				del O2, O3
			b. Los atomos de C tienden a unirse entre ellos
			c. En los oxiacidos el H suele unirse al O, y no a los átomos
				centrales, excepciones H3PO3 y H3PO2
			d. Tengan una disposición geométrica
			e. Se complete el octeto en cada uno de ellos
	*/

    g.add_vertex( Vertex( "A" ) );
	g.add_vertex( Vertex( "B" ) );
	g.add_vertex( Vertex( "C" ) );
	g.add_vertex( Vertex( "D" ) );
	g.add_vertex( Vertex( "E" ) );
	g.add_vertex( Vertex( "F" ) );
	g.add_vertex( Vertex( "G" ) );
	g.add_vertex( Vertex( "H" ) );
	g.add_vertex( Vertex( "I" ) );
	g.add_vertex( Vertex( "J" ) );


	g.add_edge( "A", "B" );
	g.add_edge( "B", "F" );
	g.add_edge( "F", "G" );
	g.add_edge( "F", "I" );
	g.add_edge( "G", "C" );
	g.add_edge( "G", "J" );
	g.add_edge( "J", "F" );
	g.add_edge( "I", "H" );
	g.add_edge( "H", "D" );
	g.add_edge( "D", "E" );
	g.add_edge( "E", "H" );
	g.add_edge( "E", "A" );

	//g.print();
	//g.BFS(g.get_vertex("A"));

    std::cout << " Saludos! ";


}

