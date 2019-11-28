/* Copyright (C)
 * 2019 - AbrahamRH
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

/**
 * @file base.c
 * @brief Programa que contiene el las funciones necesarias para el manejo de la base de datos
 * @version 2.0
 * @date 2019-11-23
 */

#include <stdio.h>
#include "sqlite3.h"
#include <stdio.h>

#if 0
//------------------------------------
//			Driver Program
//------------------------------------
int main()
{
	CreateTable();
	InsertTable();
	GetTable();
}
#endif


void CreateTable()
{
	//apuntador a la base de datos
	sqlite3 *db;

	//variable de retorno de sentencia ( se abre la base de datos )
	int rc = sqlite3_open("elementos.sqlite3", &db);

	if( rc ) {
		fprintf(stderr, "Error al abrir la base de datos: %s", sqlite3_errmsg(db));
		return;
	} else {
		fprintf(stderr, "Base de datos abierta satisfactoriamente -- ");
	}

	/*Consulta para la creación de una base de datos*/
	char* query = "DROP TABLE IF EXISTS elementos; "
				  "CREATE TABLE elementos( "
				  "numero_atomico INTERGER PRIMARY KEY NOT NULL,"
				  "electrones_disponibles INTEGER KEY NOT NULL,"
				  "nombre TEXT NOT NULL,"
				  "simbolo TEXT NOT NULL);"
				  ;

	char* err_msg = NULL;

	rc = sqlite3_exec( db, query, NULL, 0, &err_msg);

	if(rc != SQLITE_OK ){
		fprintf( stderr, "SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
	} else {
		fprintf( stdout, "Tabla creada satisfactoriamente\n");
	}

	sqlite3_close(db);
}

void InsertTable()
{
	//apuntador a la base de datos
	sqlite3 *db;

	//variable de retorno de sentencia ( se abre la base de datos )
	int rc = sqlite3_open("elementos.sqlite3", &db);

	if( rc ) {
		fprintf(stderr, "Error al abrir la base de datos: %s", sqlite3_errmsg(db));
		return;
	} else {
		fprintf(stderr, "Base de datos abierta satisfactoriamente -- ");
	}

	/*Consulta para la inserción de datos a la tabla*/
	char* query = "INSERT INTO elementos( numero_atomico,electrones_disponibles, nombre, simbolo) VALUES ( 1,1, 'Hidrógeno', 'H' );"
				  "INSERT INTO elementos( numero_atomico,electrones_disponibles, nombre, simbolo) VALUES ( 2, 0, 'Helio',    'He');"
				  "INSERT INTO elementos( numero_atomico,electrones_disponibles, nombre, simbolo) VALUES ( 8, 6, 'Oxígeno',  'O' );"
				  "INSERT INTO elementos( numero_atomico,electrones_disponibles, nombre, simbolo) VALUES ( 7, 5, 'Nitrógeno','N' );"
				  "INSERT INTO elementos( numero_atomico,electrones_disponibles, nombre, simbolo) VALUES ( 6, 4, 'Carbono',	 'C' );"
				  "INSERT INTO elementos( numero_atomico,electrones_disponibles, nombre, simbolo) VALUES ( 9, 7, 'Flúor',	 'F' );"
				  "INSERT INTO elementos( numero_atomico,electrones_disponibles, nombre, simbolo) VALUES ( 11, 1, 'Sodio',	 'Na');"
				  ;

	char* err_msg = NULL;

	//Se ejecuta la cosulta
	rc = sqlite3_exec( db, query, NULL, 0, &err_msg);

	//Se verifica que la consulta sea correcta
	if(rc != SQLITE_OK ){
		fprintf( stderr, "SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
	} else {
		fprintf( stdout, "Datos insertados\n");
	}

	int last_id = sqlite3_last_insert_rowid( db );
	fprintf( stdout, "El ultimo dato insetado es. %d\n",last_id);

	sqlite3_close(db);

}


int callback( void* data, int argc, char** argv, char** col_name )
{
	fprintf( stderr, "--- %s ---\n", (const char*)data );

	// mensaje del usuario
	for( int i = 0; i < argc; ++i ){
		printf( "%s = %s\n", col_name[ i ], argv[ i ] ? argv[ i ] : "NULL" );
	}
	printf( "\n" );
	return 0;
}


void GetTable()
{
	sqlite3 *db;

	int rc = sqlite3_open("elementos.sqlite3", &db);

	if( rc ) {
		fprintf(stderr, "Error al abrir la base de datos:  %s\n", sqlite3_errmsg(db));
		return;
	} else {
		fprintf(stderr, "Base de datos abierta satisfactoriamente -- \n");
	}
	char* sql = "SELECT * FROM elementos;";
	char* err_msg = NULL;
	const char* user_msg = "Callback llamada";
	rc = sqlite3_exec( db, sql, callback, (void*)user_msg, &err_msg );
	if( rc != SQLITE_OK ){
		fprintf( stderr, "SQL error: %s\n", err_msg );
		sqlite3_free( err_msg );
	} else{ fprintf( stdout, "Hecho!\n" ); }
	sqlite3_close(db);

}
