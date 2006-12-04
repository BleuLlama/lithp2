/*
	internals.c

	internal functions for the lithp engine

	Scott Lawrence
	2006-Nov-27
*/

#include <stdio.h>
#include "lithp.h"

/*typedef le * (*eval_cb)( const int argc, le * branch ); */

/*
        { "+"           , eval_cb_add           },
        { "-"           , eval_cb_subtract      },
        { "*"           , eval_cb_multiply      },
        { "/"           , eval_cb_divide        },

        { "1+"          , eval_cb_oneplus       },
        { "1-"          , eval_cb_oneminus      },

        { "%"           , eval_cb_modulus       },

        { "<"           , eval_cb_lt            },
        { "<="          , eval_cb_lt_eq         },
        { ">"           , eval_cb_gt            },
        { ">="          , eval_cb_gt_eq         },
        { "="           , eval_cb_eqsign        },

        { "and"         , eval_cb_and           },
        { "or"          , eval_cb_or            },
        { "not"         , eval_cb_not           },
        { "null"        , eval_cb_not           },

        { "atom"        , eval_cb_atom          },
        { "car"         , eval_cb_car           },
        { "cdr"         , eval_cb_cdr           },
        { "cons"        , eval_cb_cons          },
        { "list"        , eval_cb_list          },
        { "equal"       , eval_cb_equal         },

        { "if"          , eval_cb_if            },
        { "unless"      , eval_cb_unless        },
        { "when"        , eval_cb_when          },
        { "cond"        , eval_cb_cond          },
        { "select"      , eval_cb_select        },

        { "princ"       , eval_cb_princ         },
        { "terpri"      , eval_cb_terpri        },

        { "eval"        , eval_cb_eval          },
        { "prog1"       , eval_cb_prog1         },
        { "prog2"       , eval_cb_prog2         },
        { "progn"       , eval_cb_progn         },

        { "set"         , eval_cb_set           },
        { "setq"        , eval_cb_setq          },
        { "setf"        , eval_cb_setq          },
        { "enum"        , eval_cb_enum          },
        { "defun"       , eval_cb_defun         },

        { "gc"          , eval_cb_nothing       },
        { "garbage-collect" , eval_cb_nothing   },

        { NULL          , NULL                  }
    };

	register_function( LITHP_STATE * ls, int func, int minargc, int maxargc)
*/
