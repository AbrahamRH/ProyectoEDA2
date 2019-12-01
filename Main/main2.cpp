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
 * @file main.cpp
 * @brief Programa para la formacion de moléculas con grafos
 * @version 1.2
 * @date 2019-11-28
 */


#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>

#include "../Estructuras/grafo.hpp"
#include "../Base_de_datos/sqlite3.h"
#include "../Base_de_datos/base.h"

using namespace GraphDS;

#if 0
void armar( elemento *elementos[], size_t tam, Graph &g )
{
	/*
		Si el arreglo está ordenado por electronegatividad
		en orden descendente
	*/

	elemento *base;
	size_t i = 0;

	while( !strcmp(elementos[i]->simbolo, "H" ) )
	{
		++i;
	}
	if( i >= tam  ){
		/* Solo hay hidrogeno en el arreglo */
		if( tam == 2 ){
			g.add_vertex(Vertex("H"));
			g.add_vertex(Vertex("H"));
			g.add_edge("H","H");
		}
		else
		{
			std::cout <<"No podemos generar una estructura con los datos proporcionados\n";
		}
	}
	else
	{

		std::pair< elemento*, int> repetidos[tam];
		for(size_t j = 0; j< tam; j++){
			repetidos[i] = std
		}

		/*	Contamos la cantidad de elementos que existen	*/
		for(size_t j = 0; j<tam; ++j){
			for(size_t k = 0; k<tam; j++){
				if( strcmp(repetidos[j].first->simbolo, elementos[k]) ){
					/*Si no existe*/
					repetidos[k] = make_pair(elementos[k],1);
				}
				else{
					/*Si existe*/
					repetidos[k].second++;
				}
			}
		}

		int D = 0;
		for()

		g.print();

	}

}
#endif
int main()
{
    Graph g;
    elemento *elementos[10];
    /*
		1. Se le pide al usuario los elementos a insertar
		2. Se guardan en un arreglo, lista, etc.
		3. Se busca el elemento más electronegativo a excepcion del H ---- 
		4. Se realizan los enlaces, considerando:
			a. Los atomos de O no se enlazan entre ellos a excepción
				del O2, O3
			b. Los atomos de C tienden a unirse entre ellos
			c. En los oxiacidos el H suele unirse al O, y no a los átomos
				centrales, excepciones H3PO3 y H3PO2
			d. Tengan una disposición geométrica
			e. Se complete el octeto en cada uno de ellos
	*/

	CreateTable();
	InsertTable();

	for(size_t i = 0; i< 10; i++){
		elementos[i]= (elemento*) malloc(sizeof(elemento) );
	}
	elementos[0] = GetElement((char*) "H");
	elementos[1] = GetElement((char*) "H");
	elementos[2] = GetElement((char*) "O");
	//armar(elementos, 3, g);
	//g.print();
	//fprintf(stderr,"%s", valores->nombre);
	//std::cout << valores ; 


}

