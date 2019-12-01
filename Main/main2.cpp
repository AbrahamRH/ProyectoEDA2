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

#if 1
void armar( elemento *elementos[], size_t tam, Graph &g )
{
	/*
		Si el arreglo está ordenado por electronegatividad
		en orden descendente
	*/

	size_t indice = 0;

	while( !strcmp(elementos[indice]->simbolo, "H" ) )
	{
		++indice;
	}
	if( indice >= tam  ){
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
		elemento* base = nullptr;
		size_t indice_base;

		for( size_t i = 0; i< tam; ++i )
		{
			repetidos[i] = std::make_pair(nullptr,0);
		}

		size_t aux = 1;
		repetidos[0] = std::make_pair(elementos[0],0);

		/*
			Agregamos al arreglo de repetido los nombres de los elementos
		*/
		for(size_t i = 0; i<aux && i<tam;i++ )
		{
			for(size_t j = 0; j<tam ; j++)
			{
				if( repetidos[i].first != nullptr ){
					size_t a = 0;
					if( strcmp( repetidos[i].first->nombre, elementos[j]->nombre ) ){
						for( size_t k = 0; k< aux; k++ ){
							if( strcmp( repetidos[k].first->nombre, elementos[j]->nombre ) ){
								a++;
							}
							if( a >= aux ){
								repetidos[aux] = std::make_pair(elementos[j],0);
								aux++;
							}

						}
					}
				}
			}
		}
		/* 	Contamos cuantas veces se repite cada elemento	*/
		for(size_t i = 0; i<aux; ++i){
			for(size_t j = 0; j<tam; ++j){
				if(!strcmp(repetidos[i].first->nombre, elementos[j]->nombre)){
					repetidos[i].second++;
				}
			}
		}

		/*	Obtenemos el menos electronegativo, que será la base	*/
		for(size_t i = aux-1; i>=0; i--){
			if( strcmp(repetidos[i].first->simbolo,"H") ){
				base = repetidos[i].first;
				g.add_vertex(Vertex(base->nombre));
				indice_base = i;
				printf("Base: %s\n", base->nombre);
				break;
			}
		}



		for(int i = 1; i<repetidos[indice_base].second;++i){
			char b[10];
			sprintf(b,"%s%d",b,i);
			g.add_vertex(Vertex(b));
			g.add_edge(base->nombre,base->nombre);
		}
		/*
		int e_faltantes = 8 - repetidos[indice_base].second;
		if( atoi(base->val) < 8 && indice_base>0){
			int numero_enlaces = repetidos[indice_base-1].second;
			printf("%d\n", atoi(repetidos[indice_base-1].first->val) );
			if( numero_enlaces<=4 || e_faltantes <=  atoi(repetidos[indice_base-1].first->val)){
				for( int i = 0;i < numero_enlaces; ++i){
					g.add_vertex( Vertex(repetidos[indice_base-1].first->nombre));
					g.add_edge(base->nombre,repetidos[indice_base-1].first->nombre);
				}
			}
		}
		else{
			int numero_enlaces = repetidos[indice_base+1].second;
			if( numero_enlaces<=4 || e_faltantes <=  atoi(repetidos[indice_base+1].first->val)){
				for (int i = 0; i <numero_enlaces ; ++i)
				{
					g.add_vertex( Vertex(repetidos[indice_base+1].first->nombre));
					g.add_edge(base->nombre,repetidos[indice_base+1].first->nombre);
				}
			}
		}
*/

		//g.print();

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

	elementos[0] = GetElement((char*) "O");
	//elementos[1] = GetElement((char*) "O");
	//elementos[2] = GetElement((char*) "N");
	//elementos[1] = GetElement((char*) "O");
	elementos[1] = GetElement((char*) "C");
	elementos[2] = GetElement((char*) "C");
	elementos[3] = GetElement((char*) "C");
	elementos[4] = GetElement((char*) "H");
	elementos[5] = GetElement((char*) "H");
	elementos[6] = GetElement((char*) "H");
	elementos[7] = GetElement((char*) "H");
	elementos[8] = GetElement((char*) "H");
	elementos[9] = GetElement((char*) "H");

	armar(elementos, 9, g);
	g.print();
}

