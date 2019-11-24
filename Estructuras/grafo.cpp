/*Copyright (C)
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
// para cin, cout, cerr. (leer del teclado e imprimir en la pantalla)

#include <string>
// para declarar y procesar cadenas

#include <list>
// para los arreglos []

#include <map>
// para los diccionarios (tablas hash)

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
	std::string name; ///< campo de texto. Se utilizará como key

	// aquí van más campos relacionados con la naturaleza de la información del
	// nodo. P. ej., Estudiante: promedio, semestre. Persona: dirección, edad;
	// etc.

	std::list<Vertex> neighbors; ///< lista de vértices adyacentes

	int distance{ 0 };

	Colors color{ Colors::BLACK };

	std::string  predecesor;

	size_t discovery_time{ 0 };

	size_t finish_time{ 0 };

public:

	Vertex( std::string name );

	std::string get_name() const;

	void add_neighbor( Vertex v );

	void print_neighbors();

	//Métodos agregados
	//Setters

	void set_distance( int distance );

	void set_color( Vertex::Colors color );

	void set_predecesor( std::string predecesor );

	void set_discovery_time( size_t time );

	void set_finish_time( size_t time );

	//Getters

	int get_distance();

	Colors get_color();

	std::string get_predecesor();

	std::list<Vertex> get_neighbors();

	size_t  get_discovery_time();

	size_t  get_finish_time();

	//imprimir

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

//Setters

void Vertex::set_distance( int distance )
{
	this->distance = distance;
}

void Vertex::set_color( Vertex::Colors color)
{
	this->color = color;
}

void Vertex::set_predecesor( std::string predecesor )
{
	this->predecesor = predecesor;
}

void Vertex::set_discovery_time( size_t time ){
	this->discovery_time = time;
}

void Vertex::set_finish_time( size_t time ){
	this->finish_time = time;
}


//Getters

int Vertex::get_distance()
{
	return this->distance;
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


size_t  Vertex::get_discovery_time(){
	return this->discovery_time;
}

size_t  Vertex::get_finish_time(){
	return this->finish_time;
}

//imprimir

void Vertex::print()
{
	std::cout << "\nName: "     << this->get_name() << std::endl;
	std::cout << "Predecesor: " << this->get_predecesor() << std::endl;
	std::cout << "Discovery: "  << this->get_discovery_time() << std::endl;
	std::cout << "Finish: " 	<< this->get_finish_time() << std::endl;

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
	std::map<std::string, Vertex> vertices; ///< lista de vértices en el grafo
	// asociamos un vértice (value) a una cadena (key):
	// vertices[ string ] = a_vertex

	static size_t time;

public:
	Graph();
//	Graph( std::vector<Vertex> vertices );

	bool add_vertex( Vertex v );

	bool add_edge( std::string edge1, std::string edge2 );

	void print();

	void BFS(Vertex* start);

	void DFS(Vertex* start);

	void dfs_traverse( Vertex* v , size_t* time );

	std::vector<Vertex*> DFS_top( Vertex* start );

	void dfs_traverse_top( Vertex* v , std::vector<Vertex*>* list , size_t* time );

	bool add_edge_directed( std::string edge1, std::string edge2 );

	Vertex* get_vertex( std::string name);

	//Setter

	void clear_time(){ Graph::time = 0; }

	void inc_time(){ Graph::time++; }

	//Getter

	size_t get_time() { return Graph::time; }

};

size_t Graph::time = 0;

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

bool Graph::add_edge_directed( std::string edge1, std::string edge2 ){
	bool res = false;
	// uno, o ambos nodos, no existen

	auto v1 = this->vertices.find( edge1 );
	auto v2 = this->vertices.find( edge2 );

	if( v1 != this->vertices.end() and v2 != this->vertices.end() ){

		v1->second.add_neighbor( v2->second );

		return true;
	}

	return res;

}


//Devuelve un apuntador a un vértice del grafo
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

	for( auto v : this->vertices ){
		v.second.set_color(Vertex::Colors::BLACK);
		v.second.set_distance(0);
		v.second.set_predecesor("");
	}

	//Impresión del contenido de los nodos del grafo
	std::cout << "\nDespués de la asignación inicial a los vértices" << std::endl;
	for( auto v : this->vertices ){
		v.second.print();
	}

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
				neighbor->set_distance(vertex->get_distance() + 1);
				neighbor->set_predecesor(vertex->get_name());
				neighbor->set_color(Vertex::Colors::WHITE);
				queue.push_back(neighbor);
			}
		}
		vertex->set_color(Vertex::Colors::WHITE);
	}

	//Impresión del contenido de los nodos del grafo
	std::cout << "\nDespués asignar los valores tras recorrer el grafo" << std::endl;
	for( auto v : this->vertices ){
		v.second.print();
	}
}

//std::vector<Vertex*> Graph::DFS(Vertex start)

void Graph::DFS(Vertex* start)
{

	for( auto v : this->vertices ){
		v.second.set_color(Vertex::Colors::BLACK);
		v.second.set_predecesor("");
		v.second.set_discovery_time(0);
		v.second.set_finish_time(0);
	}

	size_t time = 0;

	this->dfs_traverse( start , &time );

	std::cout << "\nDespués asignar los valores tras recorrer el grafo" << std::endl;
	for( auto v : this->vertices ){
		v.second.print();
	}

}


void Graph::dfs_traverse( Vertex* v , size_t* time)
{

	++*time;

	v->set_discovery_time( *time );

	v->set_color( Vertex::Colors::GRAY );

	for( auto neighbors : v->get_neighbors() ){
		Vertex* neighbor = this->get_vertex( neighbors.get_name() );
		if( neighbor->get_color() == Vertex::Colors::BLACK ){
			neighbor->set_predecesor( v->get_name() );
			this->dfs_traverse( neighbor , time );
		}
	}

	v->set_color( Vertex::Colors::WHITE );

	++*time;

	v->set_finish_time( *time );

}

/*
 * Topológico
 */

std::vector<Vertex*> Graph::DFS_top( Vertex* start )
{

	for( auto v : this->vertices ){
		v.second.set_color(Vertex::Colors::BLACK);
		v.second.set_predecesor("");
		v.second.set_discovery_time(0);
		v.second.set_finish_time(0);
	}

	size_t time = 0;

	std::vector<Vertex*> list;

	this->dfs_traverse_top( start , &list , &time);

	std::sort(  list.begin() ,
				list.end() ,
				[]( Vertex* lhs, Vertex* rhs )
				{
					return lhs->get_finish_time() > rhs->get_finish_time();
				}
			);

	return list;

}

void Graph::dfs_traverse_top( Vertex* v , std::vector<Vertex*>* list , size_t* time )
{
	++*time;

	v->set_discovery_time( *time );

	v->set_color( Vertex::Colors::GRAY );

	for( auto neighbors : v->get_neighbors() ){
		Vertex* neighbor = this->get_vertex( neighbors.get_name() );
		if( neighbor->get_color() == Vertex::Colors::BLACK ){
			neighbor->set_predecesor(v->get_name());
			this->dfs_traverse_top( neighbor , list , time );
		}
	}

	v->set_color( Vertex::Colors::WHITE );

	++*time;

	v->set_finish_time( *time );

	list->push_back( v );

}

int main()
{
	Graph g;
/*
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


	g.add_edge_directed( "A", "B" );
	g.add_edge_directed( "B", "F" );
	g.add_edge_directed( "F", "G" );
	g.add_edge_directed( "F", "I" );
	g.add_edge_directed( "G", "C" );
	g.add_edge_directed( "G", "J" );
	g.add_edge_directed( "J", "F" );
	g.add_edge_directed( "I", "H" );
	g.add_edge_directed( "H", "D" );
	g.add_edge_directed( "D", "E" );
	g.add_edge_directed( "E", "H" );
	g.add_edge_directed( "E", "A" );

	g.print();
*/
	//g.DFS(g.get_vertex("A"));

	#if 1
	std::vector<Vertex*> vertices;

	vertices = g.DFS_top(g.get_vertex("A"));

	for ( auto v : vertices ){
		v->print();
	}
	#endif

}
