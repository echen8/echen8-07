#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int generate() {
  
  int p;

  int file = open( "/dev/random", O_RDONLY );
  read( file, &p, sizeof( int ) );
  close( file );
  
  return p;
  
}

int main() {

  // HEADER
  printf( "============================================\n\tRunning Random File Generator\n============================================\n\n" );

  // GENERATE ARRAY
  printf( "Generating array of 10 ints...\n\n" );

  int random[10];
  int i;
  for ( i = 0; i < 10; i++ ) {
    random[i] = generate();
    printf( "random %d:\t%d\n", i, random[i] );
  }
  
  // WRITE
  printf( "\nWriting numbers to file...\n\n" );
  
  int wfile = open( "data_stuffs", O_CREAT | O_TRUNC | O_WRONLY, 0666 );
  write( wfile, random, sizeof( random ) );
  close( wfile );

  printf( "Numbers written to file.\n" );
  
  // READ
  printf( "\nReading numbers from file...\n\n" );
  
  int data[10];
  
  int rfile = open( "data_stuffs", O_RDONLY );
  read( rfile, data, sizeof( data ) );
  close( rfile );

  int j;
  for ( j = 0; j < 10; j++ ) {
    printf( "random %d:\t%d\n", j, data[j] );
  }
  
  // FOOTER
  printf( "\n============================================\n\n" );
  
  return 0;
  
}
