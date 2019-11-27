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
 * @file ejemplo.cpp
 * @brief Ejemplo del|uso de una libreria estática
 * @author AbrahamRH
 * @version 1
 * @date 2019-11-27
 */


#include "grafo.hpp"

//Para un uso más facil de las estructuras
using namespace GraphDS;

int main()
{

	//Forma 1 de usar la estructura
	GraphDS::Graph g;

	//Forma 2 (Solo si se incluye el namespace)
	Graph h;

	g.add_vertex(GraphDS::Vertex("A"));
	g.add_vertex(GraphDS::Vertex("B"));
	h.add_vertex(Vertex("C"));
	h.add_vertex(Vertex("D"));

	g.add_edge("A","B");
	h.add_edge("C","D");

	printf("\n-----Grafo g-----\n");
	g.print();
	g.BFS(g.get_vertex("A"));

	printf("\n-----Grafo h-----\n");
	h.print();
	h.BFS(h.get_vertex("C"));







}
