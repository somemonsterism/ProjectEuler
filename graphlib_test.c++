#include <iostream>
#include <cstdlib>
#include "graphlib.h++"

using namespace std;

unsigned int errorCount = 0;

#define assert( cond, error ) if ( !(cond) ) { cout << "ERROR " << __FILE__ << ":" << __LINE__ << ": " << error << endl; errorCount++; }

int main( int argc, char *argv[] )
{
  int i = 0;



  //
  // Int promotion ctor
  //

  Graph g;
  assert( g.edgeCount() == 0, "edge count fail" );
  assert( g.vertexCount() == 0, "vertex count fail" );
  assert( g.simple(), "simple fail" );
  assert( g.directed() == false, "directed fail" );
  assert( g.findVertex( 99 ) == NULL, "find vertex fail" );
  assert( g.findEdge( 12, 67 ) == NULL, "find edge fail" );
  assert( g.isConnected(), "connected fail" );
  assert( g.isConnected( 3, 5 ) == false, "connected fail" );



  //
  // Copy ctor
  //

  Graph g_copy( g );
  assert( g_copy.edgeCount() == 0, "edge count fail" );
  assert( g_copy.vertexCount() == 0, "vertex count fail" );
  assert( g_copy.simple(), "simple fail" );
  assert( g_copy.directed() == false, "directed fail" );
  assert( g_copy.findVertex( 99 ) == NULL, "find vertex fail" );
  assert( g_copy.findEdge( 12, 67 ) == NULL, "find edge fail" );
  assert( g_copy.isConnected(), "connected fail" );
  assert( g_copy.isConnected( 3, 5 ) == false, "connected fail" );



  //
  // addVertex
  //

  g.addVertex( 3 );
  assert( g.edgeCount() == 0, "edge count fail" );
  assert( g.vertexCount() == 1, "vertex count fail" );
  assert( g.simple(), "simple fail" );
  assert( g.directed() == false, "directed fail" );
  assert( g.findVertex( 3 ) != NULL, "find vertex fail" );
  assert( g.findEdge( 3, 67 ) == NULL, "find edge fail" );
  assert( g.isConnected(), "connected fail" );
  assert( g.isConnected( 3, 3 ), "connected fail" );
  assert( g.isConnected( 3, 5 ) == false, "connected fail" );

  g.addVertex( 3 );
  assert( g.edgeCount() == 0, "edge count fail" );
  assert( g.vertexCount() == 1, "vertex count fail" );
  assert( g.simple(), "simple fail" );
  assert( g.directed() == false, "directed fail" );
  assert( g.findVertex( 3 ) != NULL, "find vertex fail" );
  assert( g.findEdge( 3, 67 ) == NULL, "find edge fail" );
  assert( g.isConnected(), "connected fail" );
  assert( g.isConnected( 3, 3 ), "connected fail" );
  assert( g.isConnected( 3, 5 ) == false, "connected fail" );



  //
  // addEdge
  //

  g.addEdge( 3, 5 );
  assert( g.edgeCount() == 1, "edge count fail" );
  assert( g.vertexCount() == 2, "vertex count fail" );
  assert( g.simple(), "simple fail" );
  assert( g.directed() == false, "directed fail" );
  assert( g.findVertex( 3 ) != NULL, "find vertex fail" );
  assert( g.findVertex( 5 ) != NULL, "find vertex fail" );
  assert( g.findEdge( 3, 5 ) != NULL, "find edge fail" );
  assert( g.isConnected(), "connected fail" );
  assert( g.isConnected( 3, 3 ), "connected fail" );
  assert( g.isConnected( 5, 5 ), "connected fail" );
  assert( g.isConnected( 3, 5 ), "connected fail" );
  assert( g.isConnected( 5, 3 ), "connected fail" );
  assert( g.isConnected( 9, 5 ) == false, "connected fail" );

  g.addEdge( 3, 5 );
  assert( g.edgeCount() == 2, "edge count fail" );
  assert( g.vertexCount() == 2, "vertex count fail" );
  assert( !g.simple(), "simple fail" );
  assert( g.directed() == false, "directed fail" );
  assert( g.findVertex( 3 ) != NULL, "find vertex fail" );
  assert( g.findVertex( 5 ) != NULL, "find vertex fail" );
  assert( g.findEdge( 3, 5 ) != NULL, "find edge fail" );
  assert( g.isConnected(), "connected fail" );
  assert( g.isConnected( 3, 3 ), "connected fail" );
  assert( g.isConnected( 5, 5 ), "connected fail" );
  assert( g.isConnected( 3, 5 ), "connected fail" );
  assert( g.isConnected( 5, 3 ), "connected fail" );
  assert( g.isConnected( 9, 5 ) == false, "connected fail" );



  //
  // Copy ctor of complex graph
  //

  Graph g_bigcopy( g );
  assert( g_bigcopy.edgeCount() == 2, "edge count fail" );
  assert( g_bigcopy.vertexCount() == 2, "vertex count fail" );
  assert( !g_bigcopy.simple(), "simple fail" );
  assert( g_bigcopy.directed() == false, "directed fail" );
  assert( g_bigcopy.findVertex( 3 ) != NULL, "find vertex fail" );
  assert( g_bigcopy.findVertex( 5 ) != NULL, "find vertex fail" );
  assert( g_bigcopy.findEdge( 3, 5 ) != NULL, "find edge fail" );
  assert( g_bigcopy.isConnected(), "connected fail" );
  assert( g_bigcopy.isConnected( 3, 3 ), "connected fail" );
  assert( g_bigcopy.isConnected( 5, 5 ), "connected fail" );
  assert( g_bigcopy.isConnected( 3, 5 ), "connected fail" );
  assert( g_bigcopy.isConnected( 5, 3 ), "connected fail" );
  assert( g_bigcopy.isConnected( 9, 5 ) == false, "connected fail" );



  //
  // dtor
  //

  Graph *gptr = new Graph();
  gptr->addEdge( 10, 20 );
  delete gptr;



  Graph g2;

  assert( g2.edgeCount() == 0, "edge count fail" );
  assert( g2.vertexCount() == 0, "vertex count fail" );
  assert( g2.simple(), "simple fail" );
  assert( g2.directed() == false, "directed fail" );
  assert( g2.findVertex( 14 ) == NULL, "find vertex fail" );
  assert( g2.findEdge( 14, 14 ) == NULL, "find edge fail" );
  assert( g2.findEdge( 9, 34 ) == NULL, "find edge fail" );
  assert( g2.isConnected(), "connected fail" );
  assert( g2.isConnected( 0, 3 ) == false, "connected fail" );

  g2.addEdge( 9, 9 );
  assert( g2.edgeCount() == 1, "edge count fail" );
  assert( g2.vertexCount() == 1, "vertex count fail" );
  assert( !g2.simple(), "simple fail" );
  assert( g2.directed() == false, "directed fail" );
  assert( g2.findVertex( 9 ) != NULL, "find vertex fail" );
  assert( g2.findEdge( 9, 9 ) != NULL, "find edge fail" );
  assert( g2.findEdge( 9, 12 ) == NULL, "find edge fail" );
  assert( g2.isConnected(), "connected fail" );
  assert( g2.isConnected( 9, 9 ), "connected fail" );
  assert( g2.isConnected( 9, 3 ) == false, "connected fail" );

  int w = 10;
  int h = 10;
  Graph grid( w, h );
  assert( grid.edgeCount() == w * (h + 1) + h * (w + 1), "edge count fail" );
  assert( grid.vertexCount() == (w + 1) * (h + 1), "vertex count fail" );
  assert( grid.simple(), "simple fail" );
  assert( grid.directed() == false, "directed fail" );
  assert( grid.findVertex( 0 ) != NULL, "find vertex fail" );
  assert( grid.findEdge( 0, w + 1 ) != NULL, "find edge fail" );
  assert( grid.findEdge( 0, 2 ) == NULL, "find edge fail" );
  assert( grid.isConnected(), "connected fail" );
  for ( i=0; i<=(w + 1) * (h + 1) - 1; i++ )
    {
      assert( grid.isConnected( 0, i ), "connected fail" );
    }

  w = 1;
  h = 1;
  Graph grid1( w, h );
  assert( grid1.edgeCount() == w * (h + 1) + h * (w + 1), "edge count fail" );
  assert( grid1.vertexCount() == (w + 1) * (h + 1), "vertex count fail" );
  assert( grid1.simple(), "simple fail" );
  assert( grid1.directed() == false, "directed fail" );
  assert( grid1.countRoutes( 0, ((w + 1) * (h + 1) - 1) ) == 2, "count routes fail" );
  assert( grid1.findVertex( 1 ) != NULL, "find vertex fail" );
  assert( grid1.findEdge( 1, w - 1 ) != NULL, "find edge fail" );
  assert( grid1.findEdge( 0, ((w + 1) * (h + 1) - 1) ) == NULL, "find edge fail" );
  assert( grid1.isConnected(), "connected fail" );
  for ( i=0; i<=(w + 1) * (h + 1) - 1; i++ )
    {
      assert( grid1.isConnected( 0, i ), "connected fail" );
    }

  w = 2;
  h = 2;
  Graph grid2( w, h );
  assert( grid2.edgeCount() == w * (h + 1) + h * (w + 1), "edge count fail" );
  assert( grid2.vertexCount() == (w + 1) * (h + 1), "vertex count fail" );
  assert( grid2.simple(), "simple fail" );
  assert( grid2.directed() == false, "directed fail" );
  assert( grid2.countRoutes( 0, ((w + 1) * (h + 1) - 1) ) == 12, "count routes fail" );
  assert( grid2.findVertex( w ) != NULL, "find vertex fail" );
  assert( grid2.findEdge( w + 1, 0 ) != NULL, "find edge fail" );
  assert( grid2.findEdge( 0, ((w + 1) * (h + 1) - 1) ) == NULL, "find edge fail" );
  assert( grid2.isConnected(), "connected fail" );
  for ( i=0; i<=(w + 1) * (h + 1) - 1; i++ )
    {
      assert( grid2.isConnected( 0, i ), "connected fail" );
    }



  //
  // findTriangle
  //

  Graph network;
  int   v3 = 0;

  network.addEdge( 1, 2 );
  network.addEdge( 2, 3 );
  assert( network.findTriangle( 1, 3, v3 ) == false, "findTriangle failure" );
  assert( v3 == 0, "findTriangle failure" );   // v3 must be unchanged

  network.addEdge( 3, 1 );
  assert( network.findTriangle( 1, 2, v3 ), "findTriangle failure" );
  assert( v3 == 3, "findTriangle failure" );
  assert( network.findTriangle( 2, 3, v3 ), "findTriangle failure" );
  assert( v3 == 1, "findTriangle failure" );
  assert( network.findTriangle( 1, 3, v3 ), "findTriangle failure" );
  assert( v3 == 2, "findTriangle failure" );

  network.addEdge( 3, 4 );
  network.addEdge( 4, 1 );
  assert( network.findTriangle( 1, 3, v3 ), "findTriangle failure" );
  assert( v3 == 4, "findTriangle failure" );

  // Three possible triangles
  network.addEdge( 3, 5 );
  network.addEdge( 1, 5 );
  assert( network.findTriangle( 1, 3, v3 ), "findTriangle failure" );

  // Vertices that don't exist
  assert( network.findTriangle( 999, 888, v3 ) == false, "findTriangle failure" );

  exit( errorCount );
}
