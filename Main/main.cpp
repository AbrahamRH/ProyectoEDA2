#include <iostream>
#include <string>

#include "../Estructuras/grafo.h" 

int main(){
    Graph g;
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

	g.print();
	g.BFS(g.get_vertex("A"));

    std::cout << " Saludos! ";


}

