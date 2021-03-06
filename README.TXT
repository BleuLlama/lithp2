----------------------------------------
                                  LITHP2
          A Common-LISP like interpreter

                          Scott Lawrence
                           2006 November
                        yorgle@gmail.com

              http://www.umlautllama.com


----------------------------------------
                                OVERVIEW

This is a simple Common LISP-like implementation.  It was created
to be an engine for use in many different projects I'm involved
with.  It is easily extendable enough to be used for other projects
as well.

This project is meant to be included within your own work.  There is a
sample executable that gets built that reads in from a file, and
interprets it, but it is very easy to integrate this source into your
own projects.

It is also very easy to register your own methods into the evaluation
core.


----------------------------------------
                      Supported Commands

Misc:

#	# foo		comment to end of line - skipped during parsing
;	; foo		comment to end of line - skipped during parsing

A	(A)		returns the value

Variables, Functions:
set	(set A B ... )	sets A to B, evaluating both.  Returns B.
setf	(setf A B ... )	sets A to B, evaluating only B.  Returns B.
setq	(setq x 4 y 3)	same as 'setf'
defun	(defun A B C)	defines a function called A with parameter list B
			and code block C.  Returns A.
	(A X Y)		Calling the above (if there were two parameters.)
			Wrong number of parameters returns NIL w/o evaluating
enum	(enum a b c)	sets up N variables with incrementing values.

Numbers:

+	(+ A B C)	add a list
-	(- A B C)       subtract a list
*	(* A B C)       multiply a list
/	(/ A B C)       divide a list
%	(% A B)		After A is divided by B, what's the leftover?

1+	(1+ A)		returns the number plus one
1-	(1- A)		returns the number minus one


Comparisons:

<	(<  A B)	returns T if A <  B, otherwise NIL
<=	(<= A B)	returns T if A <= B, otherwise NIL
>	(>  A B)	returns T if A >  B, otherwise NIL
>=	(>= A B)	returns T if A >= B, otherwise NIL
=	(=  A B)	returns T if A == B, otherwise NIL

and	(and A B)	eval's the arguments until it hits a NIL
or	(or A B)	eval's the arguments while args are NIL
not	(not A)		returns the opposite of A (T->NIL),(NIL->T)
null	(null A)	same as 'not'

if 	(if A B C)	if A is true, then B else C. if there's no C, return NIL
unless	(unless A B C)	unless A is true, do B, C and any others.
when	(when A B C)	when A is true, do B, C and any others.
cond	(cond (A B C))  if A is true then do B,C... otherwise, try the next set
select	(select A B C)	case statement.  Evaluates 'A', then compares it to
			the first values of lists B and C.  If they were equal,
			the rest of the list gets evaluated, and last return 
			gets returned.


Evaluations:

eval	(eval (A B))	evaluates (A B) as if it were directly input
prog1	(prog1 A B C)	evaluates all parts, returns the first's return value
prog2	(prog2 A B C)	evaluates all parts, returns the second's return value
progn	(progn A B C)	evaluates all parts, returns the last's return value


Lists:

quote	quote (A B)	returns the element instead of evaluating it
'	'(A B)		same as 'quote'

atom 	(atom E)	returns T if E evaluates to an atom, not a list
equal	(equal A B)	returns T if A and B have the same structure and atoms

car 	(car E)		returns the head of list E
cdr 	(cdr E)		returns all but the head of list E
cons 	(cons A B)	returns a appended to the head of list B
list	(list A B)	returns a list of the elements as passed in


Output:

princ	(princ A B)	print out the list entries and atoms
terpri	(terpri)	print out a new line (terminate printing)


Misc:

gc	(gc)		garbage collect.  Returns "T".  (does nothing)
garbage-collect		same as 'gc'

----------------------------------------
                                   BUILD

You should be able to just type 'make' or 'gmake' or whatever your
GNU-compatible 'make' utility is called.


----------------------------------------
                                 VERSION

The latest version of this should be available off of 

	http://www.umlautllama.com/project.php?ShortName=Lithp2

	or

	http://www.umlautllama.com/projects/lithp2

Be sure you're using the latest version.



----------------------------------------
                                 LICENSE

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published
by the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
USA
