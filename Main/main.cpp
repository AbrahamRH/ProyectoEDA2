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

#include "../Estructuras/grafo.hpp"
#include "../Base_de_datos/sqlite3.h"
#include "../Base_de_datos/base.h"

using namespace GraphDS;


int main()
{
    Graph g;
	
	Vertex v = Vertex("Li");
	

    /*
		✔ 1. Se le pide al usuario los elementos a insertar
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

	//CreateTable();
	//InsertTable();
	//GetTable();

	size_t n;
	std::string input;
	

	std::cout << "Cuantos elementos va a juntar" << std::endl;
	std::cin >> n;
	

	std::vector<elemento*> valores;
	std::list<Vertex> nodos;
	std::vector<int> asd;

	for (size_t i = 0; i < n; i++)
	{
		std::cout << "Nombre del elemento: " << i+1 << " a insertar." << std::endl;
		std::cin >> input;
		valores.push_back( GetElement( input.c_str() ) );
	}
	
	//fprintf(stderr,"%s", valores.at(0)->nombre);
	 
	

}

