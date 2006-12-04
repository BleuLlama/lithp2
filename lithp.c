/*
	lithp.c

	the main Lithp engine - a common lisp-like thang

	Scott Lawrence
	2006-Nov-27
*/

#include <stdio.h>
#include <stdlib.h>	/* malloc, free */
#include <string.h>
#include "lithp.h"

/* ********************************************************************** */

/* prime the system */
LITHP_STATE * lithp_create()
{
	LITHP_STATE * ls = NULL;

	ls = (LITHP_STATE *)malloc( sizeof( LITHP_STATE ));
	if( ls ) {
		ls->variables = NULL;
		ls->functions = NULL;
		ls->lps.nParens = 0;
	}

	return( ls );
}

/* unprime the system */
void lithp_destroy( LITHP_STATE * ls )
{
	if( !ls ) return;

	/* free all data structures and such */
	free( ls );
}

/* read a new line in */
void lithp_read( LITHP_STATE * ls, char * buffer )
{
	int pos;
	int comment = 0;
	int inString = 0;
	int searchForToken = 0;
	int inToken = 0;
	char acc[2048];
	int accpos = 0;

	if( !buffer || !ls ) return;

	for( pos = 0 ; !comment && buffer[pos] != '\0' ; pos++ )
	{
		/* in quotation */
		if( inString ) {
			if( buffer[pos] == '\"' ) {
				acc[accpos] = '\0';
				inString = 0;
				printf( "Accumulated String: |%s|\n", acc );
			} else {
				acc[accpos++] = buffer[pos];
			}
		} else if( inToken ) {

		/* open water */
		switch( buffer[pos] ){
		case( ';' ):
		case( '#' ):
			buffer[pos] = '\0';
			comment = 1;		/* short circuit */
			break;

		case( '\"' ):			/* start quote */
			accpos = 0;
			acc[0] = '\0';
			inString = 1;
			break;
		
		case( '(' ):
			ls->lps.nParens++;
			break;
		case( ')' ):
			ls->lps.nParens--;
			break;
		}
		}
	}
	printf( "Read %s\n", buffer );

	if( ls->lps.nParens < 0 ) {
		printf( "  ERROR: Paren count is negative!\n" );
	}

	if( inString ) {
		acc[accpos] = '\0';
		printf( "  ERROR: Unclosed string! - %s\n", acc );
	}

}

/* evaluate a line */
void lithp_evaluate( LITHP_STATE * ls )
{
}



/* ********************************************************************** */

/* hash functions */
/* on all of these - write on existing overwrites */
LITHP_HASH * lithp_hash_find( LITHP_HASH * lh, char * key )
{
	if( !lh || !key ) return( NULL );
	while( lh != NULL ) {
		if( !strcmp( key, lh->key )) return( lh );
		lh = lh->next;
	}
	return( NULL );
}


LITHP_HASH * lithp_hash_createAndPrepend( LITHP_HASH * lh, char * key )
{
	LITHP_HASH * rv = (LITHP_HASH *)malloc( sizeof( LITHP_HASH ));
	rv->key = strdup( key );
	rv->type = LITHP_HASHNODE_NIL;
	rv->value.charData = NULL;
	rv->next = lh;
	return( rv );
}

void lithp_hash_clearExistingNode( LITHP_HASH * lh )
{
	if( !lh ) return;
	switch( lh->type ){
	case( LITHP_HASHNODE_INT ):
		lh->value.intData = 0;
		break;

	case( LITHP_HASHNODE_CHAR ):
		free( lh->value.charData );
		lh->value.charData = NULL;
		break;

	case( LITHP_HASHNODE_LEAF ):
		/* XXX free it */
		lh->value.treeData = NULL;
	}

	lh->type = LITHP_HASHNODE_NIL;
}

LITHP_HASH * lithp_hash_addChar( LITHP_HASH * lh, char * key, char * val )
{
	LITHP_HASH * found;
	if( !key ) return( lh );

	found = lithp_hash_find( lh, key );
	if( !found ) {
		lh = lithp_hash_createAndPrepend( lh, key );
		found = lh;
	}
	if( found ) {
		lithp_hash_clearExistingNode( found );
	}

	lh->type = LITHP_HASHNODE_CHAR;
	lh->value.charData = strdup( val );

	return( lh );
}

char * lithp_hash_lookup( LITHP_HASH * lh, char * key )
{
	LITHP_HASH * found;
	if( !key ) return( NULL );

	found = lithp_hash_find( lh, key );
	if( found ) {
		return( found->value.charData );
	}
	return( NULL );
}
