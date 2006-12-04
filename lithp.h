/*
	lithp.h

	the main Lithp engine - a common lisp-like thang

	Scott Lawrence
	2006-Nov-27
*/


typedef struct lithp_leaf {
	char * data;
	struct lithp_leaf * sub;
	struct lithp_leaf * next;
} LITHP_LEAF;


#define LITHP_HASHNODE_IGNORED	(-1) /* rather than deleting */
#define LITHP_HASHNODE_NIL	(0)
#define LITHP_HASHNODE_INT	(1)
#define LITHP_HASHNODE_CHAR	(2)
#define LITHP_HASHNODE_LEAF	(3)
#define LITHP_HASHNODE_INTERNAL	(4) /* for internal functions */

typedef LITHP_LEAF * (*fcnp) ( LITHP_LEAF * leaf, int argc );

typedef struct lithp_hash {
	char * key;
	int type;
	union {
		char * charData;
		int intData;
		struct lithp_leaf * treeData;
		fcnp function;
	} value;
	struct lithp_hash * next;
} LITHP_HASH;

typedef struct lithp_parsestate {
	int nParens;
} LITHP_PARSE_STATE;

typedef struct lithp_state {
	LITHP_HASH * variables;
	LITHP_HASH * functions;

	/* for parsing */
	LITHP_PARSE_STATE lps;
	
} LITHP_STATE;


/* start up the system */
LITHP_STATE * lithp_create();

/* end the system */
void lithp_destroy( LITHP_STATE * ls );

/* read a new string */
void lithp_read( LITHP_STATE * ls, char * buffer );

/* evaluate absorbed strings */
void lithp_evaluate( LITHP_STATE * ls );
