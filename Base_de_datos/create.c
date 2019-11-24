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

#include <stdio.h>
#include "sqlite3.h"

void CreateTable();
void InsertTable();

//------------------------------------
//			Driver Program
//------------------------------------
int main()
{
	CreateTable();
	InsertTable();
}

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
	char* query = "INSERT INTO elementos( numero_atomico, nombre, simbolo) VALUES ( 1, 'Hidrógeno', 'H');"
				  "INSERT INTO elementos( numero_atomico, nombre, simbolo) VALUES ( 2, 'Helio', 'He');"
			;

	char* err_msg = NULL;

	rc = sqlite3_exec( db, query, NULL, 0, &err_msg);

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

