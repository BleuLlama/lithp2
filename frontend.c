/*
	interactive.c

	an interactive frontend for the lithp2 engine

	(A total rewrite from "lithp" to be more compatible, 
	and easier to work with.)

	Scott Lawrence
	2006-Nov-27
*/

#include <stdio.h>
#include <string.h> /* for strcmp */
#include "lithp.h"
#include "version.h"

#define BUFSIZE (2048)

/* wipe out some useless characters from the input string */
void trim( char * buf )
{
	int pos = 0;
	if( !buf ) return;

	for( pos=0; buf[pos] != '\0' && pos < BUFSIZE ; pos++ )
	{
		switch( buf[pos] ) {
		
		/* anything from a 'newline' on gets eliminated */
		/* this might become obsolete with a better parser later */
		case( '\n' ):
		case( '\r' ):
			buf[pos] = '\0';
			return;
			
		default: 
			break;
		}
	}
}

/* a simple user input-parsing loop */
void cmdloop()
{
	LITHP_STATE * ls;
	int done = 0;
	char buf[BUFSIZE];
	char *str;

	ls = lithp_create();

	while( !done )
	{
		/* print the prompt */
		printf( "-> " );
		fflush( stdout );

		/* read in a command */
		str = fgets( buf, BUFSIZE, stdin );
		trim( str );
		if( !str ) {
			if( feof( stdin )) {
				/* silently exit on EOF -- ctrl-D */
				printf( "\n" );
				done = 1;
			} else if( ferror( stdin )) {
				clearerr( stdin );
				printf( "E: File error %d\n", ferror( stdin ));
				done = 1;
			}
		} else {
			if( !strcmp( str, "Exit." )) done = 1;
			if( !done ) {
				lithp_read( ls, str );
				lithp_evaluate( ls );
			}
		}
	}
	lithp_destroy( ls );
}


/* print out a standard usage string */
void usage( char * argv0 )
{
	/*
	fprintf( stderr, "Usage:  %s [file.lsp]\n", argv0 );
	fprintf( stderr, "\tSpecify lsp file or use interactive mode.\n");
	*/
	fprintf( stderr, "Usage:  %s\n", argv0 );
	fprintf( stderr, "\tInteractive mode only for now.\n");
}

/* main() - argv parsing, etc */
int main( int argc, char ** argv )
{
	/*
	if( argc == 2 )
	{
		printf( "Should parse in file %s\n", argv[1] );
	} else */
	if( argc == 1 ) {
		printf( "Generic Common Lithp v%s r%s\n", VERSION, REVISION );
		printf( "\t\"%s\"\n", TPOTV );
		printf( "[ctrl]-[d] or \"Exit.\" to exit\n" );
		cmdloop();
		printf( "Exiting.\n" );
	} else {
		usage( argv[0] );
		return( -1 );
	}
	return( 0 );
}
