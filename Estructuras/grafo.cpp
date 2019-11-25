/* Copyright (C)
 * 2019 - eda1 dot fiunam at yahoo dot com dot mx
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

#include <iostream>

#include <string>

#include <list>

#include <map>

#include <array>

#include <algorithm>

#include <vector>

//----------------------------------------------------------------------
//  Class Vertex
//----------------------------------------------------------------------
class Vertex
{
public:
	enum class Colors { BLACK, GRAY, WHITE };

private:

	std::string name;				///< Nombre del elemento. Se utilizará como key

	std::string Simbolo;			///< Simbolo del elemento

	int numeroAtomico;				///< Número atómico del elemento

	std::list<Vertex> neighbors; 	///< lista de vértices adyacentes

	Colors color{ Colors::BLACK };	///< Color del vértice

	std::string  predecesor;		///< Nombre del vértice predecesor

public:

	/* -------------------------------*/
	/**
	 * @brief Constructor de la clase Vertex
	 *
	 * @param name Nombre para inicializar el vértice
	 */
	/* -------------------------------*/
	Vertex( std::string name );

	/* -------------------------------*/
	/**
	 * @brief Método para obtener el nombre del vértice
	 *
	 * @return
	 */
	/* -------------------------------*/
	std::string get_name() const;

	/* -------------------------------*/
	/**
	 * @brief Método ppara agregar un nodo vecino a la lista del vértice
	 *
	 * @param v Vértice agregado a la lista
	 */
	/* -------------------------------*/
	void add_neighbor( Vertex v );

	/* -------------------------------*/
	/**
	 * @brief Método para imprimir los nodos vecinos al vértice
	 */
	/* -------------------------------*/
	void print_neighbors();

	//Setters

	/* -------------------------------*/
	/**
	 * @brief Método para asignar un color al vértice
	 *
	 * @param color Color ( estado ) asignado
	 */
	/* -------------------------------*/
	void set_color( Vertex::Colors color );

	/* -------------------------------*/
	/**
	 * @brief Método para asignar el predecesor al vértice
	 *
	 * @param predecesor Nombre del vértice predecesor
	 */
	/* -------------------------------*/
	void set_predecesor( std::string predecesor );

	/* -------------------------------*/
	/**
	 * @brief Método para asignar el número atómico
	 *
	 * @param numero Número asignado
	 */
	/* -------------------------------*/
	void set_numero_atomico( int numero );

	//Getters

	/* -------------------------------*/
	/**
	 * @brief Método para obtener el color (estado) de un vértice
	 *
	 * @return Color ( estado ) de un vértice
	 */
	/* -------------------------------*/
	Colors get_color();

	/* -------------------------------*/
	/**
	 * @brief Método para obtener el predecesor a un vértice
	 *
	 * @return Nombre del predecesor al vértice
	 */
	/* -------------------------------*/
	std::string get_predecesor();

	/* -------------------------------*/
	/**
	 * @brief Método para obtener los vecinos de un vértice
	 *
	 * @return Lista con los vecinos de un vértice
	 */
	/* -------------------------------*/
	std::list<Vertex> get_neighbors();

	/* -------------------------------*/
	/**
	 * @brief Método para imprimir el contendo de un vértice
	 */
	/* -------------------------------*/
	void print();
};

Vertex::Vertex( std::string _name ) : name{ _name }
{
	// nada (por el momento)
}

void Vertex::add_neighbor( Vertex v )
{
	this->neighbors.push_back( v );
}

std::string Vertex::get_name() const
{
	return this->name;
}

void Vertex::print_neighbors()
{
	for( auto v : this->neighbors )
		std::cout << v.get_name() << "-> ";
	std::cout << "Nil";
}

void Vertex::set_color( Vertex::Colors color)
{
	this->color = color;
}

void Vertex::set_predecesor( std::string predecesor )
{
	this->predecesor = predecesor;
}

Vertex::Colors Vertex::get_color()
{
	return this->color;
}

std::string Vertex::get_predecesor()
{
	return this->predecesor;
}

std::list<Vertex> Vertex::get_neighbors(){
	return this->neighbors;
}

void Vertex::print()
{
	std::cout << "\nName: "     << this->get_name() << std::endl;
	std::cout << "Predecesor: " << this->get_predecesor() << std::endl;
	std::string color_as_string;

	switch( this->color ){
		case Vertex::Colors::BLACK: color_as_string = "BLACK"; break;
		case Vertex::Colors::GRAY:  color_as_string = "GRAY";  break;
		case Vertex::Colors::WHITE: color_as_string = "WHITE"; break;
	}

	std::cout << "Color: " << color_as_string << std::endl;
}


//----------------------------------------------------------------------
//  Class Graph
//----------------------------------------------------------------------
class Graph
{
private:
	// asociamos un vértice (value) a una cadena (key):
	// vertices[ string ] = a_vertex
	std::map<std::string, Vertex> vertices; ///< lista de vértices en el grafo

public:
	/* -------------------------------*/
	/**
	 * @brief Constructor de la clase Graph
	 */
	/* -------------------------------*/
	Graph();

	/* -------------------------------*/
	/**
	 * @brief Método para agregar un vértice al grafo
	 *
	 * @param v Vétice que sera agregado al grafo
	 *
	 * @return True: Si se agrego el vértice al grafo False: en caso contrario
	 */
	/* -------------------------------*/
	bool add_vertex( Vertex v );

	/* -------------------------------*/
	/**
	 * @brief Método para agregar las aristas a los vértices
	 *
	 * @param edge1 Nodo de la arista
	 * @param edge2 Nodo de la arista
	 *
	 * @return True: si se agrego la arista False: en caso contrario
	 */
	/* -------------------------------*/
	bool add_edge( std::string edge1, std::string edge2 );

	/* -------------------------------*/
	/**
	 * @brief Método ara la impresión del grafo
	 */
	/* -------------------------------*/
	void print();

	/* -------------------------------*/
	/**
	 * @brief Algoritmo para el recorrido del grafo Breadth-first search
	 *
	 * @param start Apuntador al vértice de inicio del recorrido
	 */
	/* -------------------------------*/
	void BFS( Vertex* start );

	/* -------------------------------*/
	/**
	 * @brief Método para obtener un vértice del grafo
	 *
	 * @param name Nombre del vértice que se desea obtener
	 *
	 * @return Apuntador a el vértice
	 */
	/* -------------------------------*/
	Vertex* get_vertex( std::string name);

};

Graph::Graph()
{
	// nada (por el momento)
}

bool Graph::add_vertex( Vertex v )
{
	auto ret = vertices.insert( { v.get_name(), v } );
	// 'map' no permite duplicados, así que no hay necesidad de buscarlos

	return ret.second;
}

bool Graph::add_edge( std::string edge1, std::string edge2 )
{
	bool res = false;
	// uno, o ambos nodos, no existen

	auto v1 = this->vertices.find( edge1 );
	auto v2 = this->vertices.find( edge2 );

	if( v1 != this->vertices.end() and v2 != this->vertices.end() ){

		v1->second.add_neighbor( v2->second );
		v2->second.add_neighbor( v1->second );

		return true;
	}

	return res;
}

Vertex* Graph::get_vertex( std::string name){
	return &this->vertices.find(name)->second;
}



void Graph::print()
{
	for( auto v : this->vertices ){
		std::cout << "\n" << v.second.get_name() << ": ";
		v.second.print_neighbors();
	}
	std::cout << "\n";
}

void Graph::BFS(Vertex* start)
{
	start->set_color(Vertex::Colors::WHITE);
	std::list<Vertex*> queue;
	queue.push_back(start);

	while ( !queue.empty() ){

		Vertex* vertex = queue.front();
		queue.pop_front();

		for ( auto neighbors : vertex->get_neighbors() ){

			/*Se utilza el nombre de los vecinos para poder acceder a ese
		      vertex por medio de get_vertex que devuelve un apuntador y no su copia*/

			Vertex* neighbor = this->get_vertex(neighbors.get_name());

			if( neighbor->get_color() == Vertex::Colors::BLACK ){
				neighbor->set_color(Vertex::Colors::GRAY);
				neighbor->set_predecesor(vertex->get_name());
				neighbor->set_color(Vertex::Colors::WHITE);
				queue.push_back(neighbor);
			}
		}
		vertex->set_color(Vertex::Colors::WHITE);
	}

	//Impresión del contenido de los nodos del grafo
	for( auto v : this->vertices ){
		v.second.print();
	}
}


int main()
{
	Graph g;
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

	g.print();
	g.BFS(g.get_vertex("A"));

}
