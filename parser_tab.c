
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TCONST	258
#define	TELSE	259
#define	TIF	260
#define	TINT	261
#define	TRETURN	262
#define	TVOID	263
#define	TWHILE	264
#define	TCHAR	265
#define	TFLOAT	266
#define	TEQUAL	267
#define	TNOTEQU	268
#define	TLESSE	269
#define	TGREATE	270
#define	TAND	271
#define	TOR	272
#define	TINC	273
#define	TDEC	274
#define	TADDASSIGN	275
#define	TSUBASSIGN	276
#define	TMULASSIGN	277
#define	TDIVASSIGN	278
#define	TMODASSIGN	279
#define	TLPAREN	280
#define	TRPAREN	281
#define	TLBRACE	282
#define	TRBRACE	283
#define	TASSIGN	284
#define	TFLOATNUM	285
#define	TSTAR	286
#define	TPLUS	287
#define	TMOD	288
#define	TMINUS	289
#define	TSLASH	290
#define	TINTNUM	291
#define	TIDENT	292
#define	TCHARCONST	293
#define	TNUMBER	294
#define	TSEMI	295
#define	TDOT	296
#define	TSTRING	297
#define	TERROR	298
#define	TCOMMA	299
#define	TLSQUARE	300
#define	TRSQUARE	301
#define	TGREAT	302
#define	TLESS	303
#define	TMUL	304
#define	TDIV	305
#define	TNOT	306
#define	TINTEGER	307
#define	TLOWERTHANELSE	308

#line 1 "parser.y"

#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

/*yacc source for Mini C*/
void semantic(int);
extern void update_sym_table(int, int, char*, char*);
char type_buffer[16];
char* current_qualifier = NULL;
char* current_type = type_buffer;
char* current_kind;
int func_name_index;
extern int st_index;
extern int line_num;
extern char* yytext;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		154
#define	YYFLAG		-32768
#define	YYNTBASE	54

#define YYTRANSLATE(x) ((unsigned)(x) <= 308 ? yytranslate[x] : 99)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    18,    20,    22,
    25,    27,    29,    31,    33,    35,    37,    39,    43,    45,
    46,    48,    52,    55,    60,    62,    63,    65,    68,    72,
    74,    78,    80,    84,    86,    91,    93,    94,    96,    97,
    99,   102,   104,   106,   108,   110,   112,   115,   117,   118,
   124,   132,   138,   142,   144,   146,   150,   154,   158,   162,
   166,   170,   172,   176,   178,   182,   184,   188,   192,   194,
   198,   202,   206,   210,   212,   216,   220,   222,   226,   230,
   234,   236,   239,   242,   245,   248,   250,   255,   260,   263,
   266,   268,   269,   271,   273,   277,   279,   281
};

static const short yyrhs[] = {    55,
     0,    56,     0,    55,    56,     0,    57,     0,    72,     0,
    58,    69,     0,    59,    64,    65,     0,    60,     0,    61,
     0,    60,    61,     0,    62,     0,    63,     0,     3,     0,
     6,     0,    11,     0,     8,     0,    37,     0,    25,    66,
    26,     0,    67,     0,     0,    68,     0,    67,    44,    68,
     0,    59,    75,     0,    27,    70,    77,    28,     0,    71,
     0,     0,    72,     0,    71,    72,     0,    59,    73,    40,
     0,    74,     0,    73,    44,    74,     0,    75,     0,    75,
    29,    39,     0,    37,     0,    37,    45,    76,    46,     0,
    39,     0,     0,    78,     0,     0,    79,     0,    78,    79,
     0,    69,     0,    80,     0,    82,     0,    83,     0,    84,
     0,    81,    40,     0,    85,     0,     0,     5,    25,    85,
    26,    79,     0,     5,    25,    85,    26,    79,     4,    79,
     0,     9,    25,    85,    26,    79,     0,     7,    81,    40,
     0,    86,     0,    87,     0,    93,    29,    86,     0,    93,
    20,    86,     0,    93,    21,    86,     0,    93,    22,    86,
     0,    93,    23,    86,     0,    93,    24,    86,     0,    88,
     0,    87,    17,    88,     0,    89,     0,    88,    16,    89,
     0,    90,     0,    89,    12,    90,     0,    89,    13,    90,
     0,    91,     0,    90,    47,    91,     0,    90,    48,    91,
     0,    90,    15,    91,     0,    90,    14,    91,     0,    92,
     0,    91,    32,    92,     0,    91,    34,    92,     0,    93,
     0,    92,    49,    93,     0,    92,    50,    93,     0,    92,
    33,    93,     0,    94,     0,    34,    93,     0,    51,    93,
     0,    18,    93,     0,    19,    93,     0,    98,     0,    94,
    45,    85,    46,     0,    94,    25,    95,    26,     0,    94,
    18,     0,    94,    19,     0,    96,     0,     0,    97,     0,
    86,     0,    97,    44,    86,     0,    37,     0,    39,     0,
    25,    85,    26,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    30,    31,    32,    33,    34,    36,    37,    41,    42,    43,
    44,    45,    46,    47,    48,    49,    50,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
    68,    69,    73,    77,    81,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    97,    98,    99,   100,
   101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   113,   114,   115,   116,   117,   118,   119,   120,   121,
   122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
   132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
   142,   143,   144,   145,   146,   147,   148,   149
};

static const char * const yytname[] = {   "$","error","$undefined.","TCONST",
"TELSE","TIF","TINT","TRETURN","TVOID","TWHILE","TCHAR","TFLOAT","TEQUAL","TNOTEQU",
"TLESSE","TGREATE","TAND","TOR","TINC","TDEC","TADDASSIGN","TSUBASSIGN","TMULASSIGN",
"TDIVASSIGN","TMODASSIGN","TLPAREN","TRPAREN","TLBRACE","TRBRACE","TASSIGN",
"TFLOATNUM","TSTAR","TPLUS","TMOD","TMINUS","TSLASH","TINTNUM","TIDENT","TCHARCONST",
"TNUMBER","TSEMI","TDOT","TSTRING","TERROR","TCOMMA","TLSQUARE","TRSQUARE","TGREAT",
"TLESS","TMUL","TDIV","TNOT","TINTEGER","TLOWERTHANELSE","mini_c","translation_unit",
"external_dcl","function_def","function_header","dcl_spec","dcl_specifiers",
"dcl_specifier","type_qualifier","type_specifier","function_name","formal_param",
"opt_formal_param","formal_param_list","param_dcl","compound_st","opt_dcl_list",
"declaration_list","declaration","init_dcl_list","init_declarator","declarator",
"opt_number","opt_stat_list","statement_list","statement","expression_st","opt_expression",
"if_st","while_st","return_st","expression","assignment_exp","logical_or_exp",
"logical_and_exp","equality_exp","relational_exp","additive_exp","multiplicative_exp",
"unary_exp","postfix_exp","opt_actual_param","actual_param","actual_param_list",
"primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    54,    55,    55,    56,    56,    57,    58,    59,    60,    60,
    61,    61,    62,    63,    63,    63,    64,    65,    66,    66,
    67,    67,    68,    69,    70,    70,    71,    71,    72,    73,
    73,    74,    74,    75,    75,    76,    76,    77,    77,    78,
    78,    79,    79,    79,    79,    79,    80,    81,    81,    82,
    82,    83,    84,    85,    86,    86,    86,    86,    86,    86,
    86,    87,    87,    88,    88,    89,    89,    89,    90,    90,
    90,    90,    90,    91,    91,    91,    92,    92,    92,    92,
    93,    93,    93,    93,    93,    94,    94,    94,    94,    94,
    95,    95,    96,    97,    97,    98,    98,    98
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     3,     1,     1,     2,
     1,     1,     1,     1,     1,     1,     1,     3,     1,     0,
     1,     3,     2,     4,     1,     0,     1,     2,     3,     1,
     3,     1,     3,     1,     4,     1,     0,     1,     0,     1,
     2,     1,     1,     1,     1,     1,     2,     1,     0,     5,
     7,     5,     3,     1,     1,     3,     3,     3,     3,     3,
     3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
     3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
     1,     2,     2,     2,     2,     1,     4,     4,     2,     2,
     1,     0,     1,     1,     3,     1,     1,     3
};

static const short yydefact[] = {     0,
    13,    14,    16,    15,     1,     2,     4,     0,     0,     8,
     9,    11,    12,     5,     3,    26,     6,    34,     0,     0,
    30,    32,    10,     0,    39,    25,    27,    37,    20,     7,
    29,     0,     0,    34,     0,    49,     0,     0,     0,     0,
     0,    96,    97,     0,    42,     0,    38,    40,    43,     0,
    44,    45,    46,    48,    54,    55,    62,    64,    66,    69,
    74,    77,    81,    86,    28,    36,     0,     0,     0,    19,
    21,    31,    33,     0,     0,     0,    84,    85,     0,    82,
    83,    24,    41,    47,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    89,    90,    92,     0,    35,    23,    18,
     0,     0,    53,     0,    98,    63,    77,    65,    67,    68,
    73,    72,    70,    71,    75,    76,    80,    78,    79,    57,
    58,    59,    60,    61,    56,    94,     0,    91,    93,     0,
    22,    49,    49,    88,     0,    87,    50,    52,    95,    49,
    51,     0,     0,     0
};

static const short yydefgoto[] = {   152,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    19,
    30,    69,    70,    71,    45,    25,    26,    14,    20,    21,
    22,    67,    46,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
   137,   138,   139,    64
};

static const short yypact[] = {    70,
-32768,-32768,-32768,-32768,    70,-32768,-32768,   -13,    -1,    70,
-32768,-32768,-32768,-32768,-32768,    70,-32768,   -20,    20,     2,
-32768,    40,-32768,    34,    65,    70,-32768,    36,    70,-32768,
-32768,    34,    38,    35,    54,    93,    57,    93,    93,    93,
    93,-32768,-32768,    93,-32768,    59,    65,-32768,-32768,    48,
-32768,-32768,-32768,-32768,-32768,    72,    75,    31,    -7,   -21,
   -23,    10,     4,-32768,-32768,-32768,    47,    34,    68,    56,
-32768,-32768,-32768,    93,    58,    93,-32768,-32768,    81,-32768,
-32768,-32768,-32768,-32768,    93,    93,    93,    93,    93,    93,
    93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
    93,    93,    93,-32768,-32768,    93,    93,-32768,-32768,-32768,
    70,    83,-32768,    87,-32768,    75,-32768,    31,    -7,    -7,
   -21,   -21,   -21,   -21,   -23,   -23,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    88,-32768,    71,    55,
-32768,   101,   101,-32768,    93,-32768,   113,-32768,-32768,   101,
-32768,   121,   122,-32768
};

static const short yypgoto[] = {-32768,
-32768,   118,-32768,-32768,   -14,-32768,   114,-32768,-32768,-32768,
-32768,-32768,-32768,    14,   123,-32768,-32768,    12,-32768,    97,
    66,-32768,-32768,-32768,   -47,-32768,   100,-32768,-32768,-32768,
   -39,   -82,-32768,    52,    53,   -40,   -25,    -8,   -35,-32768,
-32768,-32768,-32768,-32768
};


#define	YYLAST		152


static const short yytable[] = {    83,
    79,    24,    77,    78,   -17,    80,    89,    90,    81,    95,
    93,    24,    94,    16,    68,   130,   131,   132,   133,   134,
   135,   104,   105,   136,    28,    96,    97,    27,   106,    98,
    99,   100,   101,   102,   112,    18,   114,    65,   103,    91,
    92,    31,    87,    88,    29,    32,   119,   120,   107,   117,
   117,   117,   117,   117,   117,   117,   117,   117,   117,   127,
   128,   129,   149,   121,   122,   123,   124,   140,    33,    35,
    34,    36,     1,    37,    66,     2,    73,     3,    74,    28,
     4,    76,    38,    39,   125,   126,    82,    84,    85,    40,
    86,    16,   108,   110,   147,   148,    68,   113,    41,   111,
   146,    42,   151,    43,   -49,    35,   115,    36,   142,    37,
    38,    39,   143,   144,   145,    44,   150,    40,    38,    39,
   153,   154,    15,    23,   141,    40,    41,    16,    72,    42,
    17,    43,     0,   109,    41,    75,   116,    42,   118,    43,
     0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
     0,    44
};

static const short yycheck[] = {    47,
    40,    16,    38,    39,    25,    41,    14,    15,    44,    33,
    32,    26,    34,    27,    29,    98,    99,   100,   101,   102,
   103,    18,    19,   106,    45,    49,    50,    16,    25,    20,
    21,    22,    23,    24,    74,    37,    76,    26,    29,    47,
    48,    40,    12,    13,    25,    44,    87,    88,    45,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,   145,    89,    90,    91,    92,   107,    29,     5,
    37,     7,     3,     9,    39,     6,    39,     8,    25,    45,
    11,    25,    18,    19,    93,    94,    28,    40,    17,    25,
    16,    27,    46,    26,   142,   143,   111,    40,    34,    44,
    46,    37,   150,    39,    40,     5,    26,     7,    26,     9,
    18,    19,    26,    26,    44,    51,     4,    25,    18,    19,
     0,     0,     5,    10,   111,    25,    34,    27,    32,    37,
     8,    39,    -1,    68,    34,    36,    85,    37,    86,    39,
    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    51
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 30 "parser.y"
{semantic(1);;
    break;}
case 2:
#line 31 "parser.y"
{semantic(2);;
    break;}
case 3:
#line 32 "parser.y"
{semantic(3);;
    break;}
case 4:
#line 33 "parser.y"
{semantic(4);;
    break;}
case 5:
#line 34 "parser.y"
{semantic(5);;
    break;}
case 6:
#line 36 "parser.y"
{semantic(6);;
    break;}
case 7:
#line 37 "parser.y"
{
										current_kind = "function";
										update_sym_table(func_name_index, line_num, current_type, current_kind); 											semantic(7);
										;
    break;}
case 8:
#line 41 "parser.y"
{semantic(8);;
    break;}
case 9:
#line 42 "parser.y"
{semantic(9);;
    break;}
case 10:
#line 43 "parser.y"
{semantic(10);;
    break;}
case 11:
#line 44 "parser.y"
{semantic(11);;
    break;}
case 12:
#line 45 "parser.y"
{semantic(12);;
    break;}
case 13:
#line 46 "parser.y"
{current_qualifier = "const"; semantic(13);;
    break;}
case 14:
#line 47 "parser.y"
{strcpy(type_buffer, current_qualifier ? "const int" : "int"); current_qualifier = NULL; semantic(14);;
    break;}
case 15:
#line 48 "parser.y"
{strcpy(type_buffer, current_qualifier ? "const float" : "float"); current_qualifier = NULL; semantic(14);;
    break;}
case 16:
#line 49 "parser.y"
{strcpy(type_buffer, current_qualifier ? "const void" : "void"); current_qualifier = NULL; semantic(15);;
    break;}
case 17:
#line 50 "parser.y"
{
										printf(">> 함수 이름: %s (st_index=%d)\n", yytext, st_index); // 디버깅용
										func_name_index = st_index;
										semantic(16);
										;
    break;}
case 18:
#line 55 "parser.y"
{semantic(17);;
    break;}
case 19:
#line 56 "parser.y"
{semantic(18);;
    break;}
case 20:
#line 57 "parser.y"
{semantic(19);;
    break;}
case 21:
#line 58 "parser.y"
{semantic(20);;
    break;}
case 22:
#line 59 "parser.y"
{semantic(21);;
    break;}
case 23:
#line 60 "parser.y"
{semantic(22);;
    break;}
case 24:
#line 61 "parser.y"
{semantic(23);;
    break;}
case 25:
#line 62 "parser.y"
{semantic(24);;
    break;}
case 26:
#line 63 "parser.y"
{semantic(25);;
    break;}
case 27:
#line 64 "parser.y"
{semantic(26);;
    break;}
case 28:
#line 65 "parser.y"
{semantic(27);;
    break;}
case 29:
#line 66 "parser.y"
{semantic(28);;
    break;}
case 30:
#line 67 "parser.y"
{semantic(29);;
    break;}
case 31:
#line 68 "parser.y"
{semantic(30);;
    break;}
case 32:
#line 69 "parser.y"
{
										update_sym_table(st_index, line_num, current_type, current_kind);
										semantic(31);
										;
    break;}
case 33:
#line 73 "parser.y"
{
										update_sym_table(st_index, line_num, current_type, current_kind);
										semantic(32);
										;
    break;}
case 34:
#line 77 "parser.y"
{
										current_kind = "scalar";
										semantic(33);
										;
    break;}
case 35:
#line 81 "parser.y"
{
										current_kind = "array";
										semantic(34);
										;
    break;}
case 36:
#line 85 "parser.y"
{semantic(35);;
    break;}
case 37:
#line 86 "parser.y"
{semantic(36);;
    break;}
case 38:
#line 87 "parser.y"
{semantic(37);;
    break;}
case 39:
#line 88 "parser.y"
{semantic(38);;
    break;}
case 40:
#line 89 "parser.y"
{semantic(39);;
    break;}
case 41:
#line 90 "parser.y"
{semantic(40);;
    break;}
case 42:
#line 91 "parser.y"
{semantic(41);;
    break;}
case 43:
#line 92 "parser.y"
{semantic(42);;
    break;}
case 44:
#line 93 "parser.y"
{semantic(43);;
    break;}
case 45:
#line 94 "parser.y"
{semantic(44);;
    break;}
case 46:
#line 95 "parser.y"
{semantic(45);;
    break;}
case 47:
#line 97 "parser.y"
{semantic(46);;
    break;}
case 48:
#line 98 "parser.y"
{semantic(47);;
    break;}
case 49:
#line 99 "parser.y"
{semantic(48);;
    break;}
case 50:
#line 100 "parser.y"
{semantic(49);;
    break;}
case 51:
#line 101 "parser.y"
{semantic(50);;
    break;}
case 52:
#line 102 "parser.y"
{semantic(51);;
    break;}
case 53:
#line 103 "parser.y"
{semantic(52);;
    break;}
case 54:
#line 104 "parser.y"
{semantic(53);;
    break;}
case 55:
#line 105 "parser.y"
{semantic(54);;
    break;}
case 56:
#line 106 "parser.y"
{semantic(55);;
    break;}
case 57:
#line 107 "parser.y"
{semantic(56);;
    break;}
case 58:
#line 108 "parser.y"
{semantic(57);;
    break;}
case 59:
#line 109 "parser.y"
{semantic(58);;
    break;}
case 60:
#line 110 "parser.y"
{semantic(59);;
    break;}
case 61:
#line 111 "parser.y"
{semantic(60);;
    break;}
case 62:
#line 113 "parser.y"
{semantic(61);;
    break;}
case 63:
#line 114 "parser.y"
{semantic(62);;
    break;}
case 64:
#line 115 "parser.y"
{semantic(63);;
    break;}
case 65:
#line 116 "parser.y"
{semantic(64);;
    break;}
case 66:
#line 117 "parser.y"
{semantic(65);;
    break;}
case 67:
#line 118 "parser.y"
{semantic(66);;
    break;}
case 68:
#line 119 "parser.y"
{semantic(67);;
    break;}
case 69:
#line 120 "parser.y"
{semantic(68);;
    break;}
case 70:
#line 121 "parser.y"
{semantic(69);;
    break;}
case 71:
#line 122 "parser.y"
{semantic(70);;
    break;}
case 72:
#line 123 "parser.y"
{semantic(71);;
    break;}
case 73:
#line 124 "parser.y"
{semantic(72);;
    break;}
case 74:
#line 125 "parser.y"
{semantic(73);;
    break;}
case 75:
#line 126 "parser.y"
{semantic(74);;
    break;}
case 76:
#line 127 "parser.y"
{semantic(75);;
    break;}
case 77:
#line 128 "parser.y"
{semantic(76);;
    break;}
case 78:
#line 129 "parser.y"
{semantic(77);;
    break;}
case 79:
#line 130 "parser.y"
{semantic(78);;
    break;}
case 80:
#line 131 "parser.y"
{semantic(79);;
    break;}
case 81:
#line 132 "parser.y"
{semantic(80);;
    break;}
case 82:
#line 133 "parser.y"
{semantic(81);;
    break;}
case 83:
#line 134 "parser.y"
{semantic(82);;
    break;}
case 84:
#line 135 "parser.y"
{semantic(83);;
    break;}
case 85:
#line 136 "parser.y"
{semantic(84);;
    break;}
case 86:
#line 137 "parser.y"
{semantic(85);;
    break;}
case 87:
#line 138 "parser.y"
{semantic(86);;
    break;}
case 88:
#line 139 "parser.y"
{semantic(87);;
    break;}
case 89:
#line 140 "parser.y"
{semantic(88);;
    break;}
case 90:
#line 141 "parser.y"
{semantic(89);;
    break;}
case 91:
#line 142 "parser.y"
{semantic(90);;
    break;}
case 92:
#line 143 "parser.y"
{semantic(91);;
    break;}
case 93:
#line 144 "parser.y"
{semantic(92);;
    break;}
case 94:
#line 145 "parser.y"
{semantic(93);;
    break;}
case 95:
#line 146 "parser.y"
{semantic(94);;
    break;}
case 96:
#line 147 "parser.y"
{semantic(95);;
    break;}
case 97:
#line 148 "parser.y"
{semantic(96);;
    break;}
case 98:
#line 149 "parser.y"
{semantic(97);;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 150 "parser.y"


void semantic(int n)
{	
	printf("reduced rule number = %d\n",n);
}
