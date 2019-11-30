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
 * @file base.h
 * @brief Libreria encargada de contener los prototipos de función del programa base.c
 * @version 1.0
 * @date 2019-11-28
 */


typedef struct {
	char* val;
	char* num_atom;
	char* nombre;
	char* simbolo;
} elemento ;


/* -------------------------------*/
/**
 * @brief Función para la creación de la tabla de Elementos
 */
/* -------------------------------*/
void CreateTable();

/* -------------------------------*/
/**
 * @brief Función para la inseción de elementos en la base de datos
 */
/* -------------------------------*/
void InsertTable();


/* -------------------------------*/
/**
 * @brief Función para obtener los datos de una tabla
 */
/* -------------------------------*/
void GetTable();


/* -------------------------------*/
/**
 * @brief Función para obtener un elemento en específico de la tabla
 * @param nombre Nombre del elemento a buscar. 
 */
/* -------------------------------*/
elemento* GetElement(char* nombre );


/* -------------------------------*/
/**
 * @brief Callback para las consultas (query)
 *
 * @param data Campo de uso para el usuario. El usuario la usa como quiera.
 * @param argc Número de columnas encontradas
 * @param argv Valor (como texto) de cada columna
 * @param col_name Nombre (en la base de datos) de cada columna
 *
 * @return 0: ok, !0: algún error
 */
/* -------------------------------*/
int callback( void* data, int argc, char** argv, char** col_name );

int callback2( void* data, int argc, char** argv, char** col_name );
