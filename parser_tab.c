
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
#define	TINCLUDE	307
#define	TDEFINE	308
#define	TLOWERTHANELSE	309

#line 1 "parser.y"

#include <stdio.h>
#include <ctype.h>
#include <malloc.h>

/*yacc source for Mini C*/
void semantic(int);
extern void update_sym_table(int, int, char*, char*);
extern void set_param_info(int sym_id, const char* param_str, int count);
char type_buffer[16];					// 변수의 type이 여러개일 경우를 위한 버퍼
char* current_qualifier = NULL;				// const 여부
char* current_type = type_buffer;			// int, float, void 등 변수의 type 저장
char* current_kind;						// scalar, array, function 등 종류 저장
int func_name_index;					// 현재 함수의 symbol table 인덱스 기록
char param_list_buffer[128];				// 현재 함수의 파라미터 정보 임시 저장 버퍼
int param_count = 0;					// 현재 함수의 파라미터 개수 저장
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



#define	YYFINAL		168
#define	YYFLAG		-32768
#define	YYNTBASE	55

#define YYTRANSLATE(x) ((unsigned)(x) <= 309 ? yytranslate[x] : 105)

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
    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    13,    15,    17,    19,
    22,    26,    28,    30,    32,    35,    39,    41,    43,    46,
    48,    50,    52,    54,    56,    58,    60,    64,    66,    67,
    69,    73,    76,    81,    83,    84,    86,    89,    93,    95,
    99,   101,   105,   107,   112,   114,   115,   117,   118,   120,
   123,   125,   127,   129,   131,   133,   136,   138,   139,   145,
   153,   159,   163,   165,   167,   171,   175,   179,   183,   187,
   191,   193,   197,   199,   203,   205,   209,   213,   215,   219,
   223,   227,   231,   233,   237,   241,   243,   247,   251,   255,
   257,   260,   263,   266,   269,   271,   276,   281,   284,   287,
   289,   290,   292,   294,   298,   300,   302,   304,   306
};

static const short yyrhs[] = {    56,
     0,    57,     0,    56,    57,     0,    58,     0,    59,     0,
    63,     0,    78,     0,    60,     0,    61,     0,    52,    42,
     0,    53,    37,    62,     0,    36,     0,    30,     0,    42,
     0,    64,    75,     0,    65,    70,    71,     0,    66,     0,
    67,     0,    66,    67,     0,    68,     0,    69,     0,     3,
     0,     6,     0,    11,     0,     8,     0,    37,     0,    25,
    72,    26,     0,    73,     0,     0,    74,     0,    73,    44,
    74,     0,    65,    81,     0,    27,    76,    83,    28,     0,
    77,     0,     0,    78,     0,    77,    78,     0,    65,    79,
    40,     0,    80,     0,    79,    44,    80,     0,    81,     0,
    81,    29,    39,     0,    37,     0,    37,    45,    82,    46,
     0,    39,     0,     0,    84,     0,     0,    85,     0,    84,
    85,     0,    75,     0,    86,     0,    88,     0,    89,     0,
    90,     0,    87,    40,     0,    91,     0,     0,     5,    25,
    91,    26,    85,     0,     5,    25,    91,    26,    85,     4,
    85,     0,     9,    25,    91,    26,    85,     0,     7,    87,
    40,     0,    92,     0,    93,     0,    99,    29,    92,     0,
    99,    20,    92,     0,    99,    21,    92,     0,    99,    22,
    92,     0,    99,    23,    92,     0,    99,    24,    92,     0,
    94,     0,    93,    17,    94,     0,    95,     0,    94,    16,
    95,     0,    96,     0,    95,    12,    96,     0,    95,    13,
    96,     0,    97,     0,    96,    47,    97,     0,    96,    48,
    97,     0,    96,    15,    97,     0,    96,    14,    97,     0,
    98,     0,    97,    32,    98,     0,    97,    34,    98,     0,
    99,     0,    98,    49,    99,     0,    98,    50,    99,     0,
    98,    33,    99,     0,   100,     0,    34,    99,     0,    51,
    99,     0,    18,    99,     0,    19,    99,     0,   104,     0,
   100,    45,    91,    46,     0,   100,    25,   101,    26,     0,
   100,    18,     0,   100,    19,     0,   102,     0,     0,   103,
     0,    92,     0,   103,    44,    92,     0,    37,     0,    39,
     0,    30,     0,    36,     0,    25,    91,    26,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
    43,    51,    53,    55,    57,    64,    68,    69,    70,    71,
    72,    73,    74,    75,    76,    77,    81,    82,    83,    84,
    85,    86,    97,    98,    99,   100,   101,   102,   103,   104,
   105,   109,   113,   117,   121,   122,   123,   124,   125,   126,
   127,   128,   129,   130,   131,   133,   134,   135,   136,   137,
   138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
   149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
   159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
   169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
   179,   180,   181,   182,   183,   184,   185,   186,   187
};

static const char * const yytname[] = {   "$","error","$undefined.","TCONST",
"TELSE","TIF","TINT","TRETURN","TVOID","TWHILE","TCHAR","TFLOAT","TEQUAL","TNOTEQU",
"TLESSE","TGREATE","TAND","TOR","TINC","TDEC","TADDASSIGN","TSUBASSIGN","TMULASSIGN",
"TDIVASSIGN","TMODASSIGN","TLPAREN","TRPAREN","TLBRACE","TRBRACE","TASSIGN",
"TFLOATNUM","TSTAR","TPLUS","TMOD","TMINUS","TSLASH","TINTNUM","TIDENT","TCHARCONST",
"TNUMBER","TSEMI","TDOT","TSTRING","TERROR","TCOMMA","TLSQUARE","TRSQUARE","TGREAT",
"TLESS","TMUL","TDIV","TNOT","TINCLUDE","TDEFINE","TLOWERTHANELSE","mini_c",
"translation_units","translation_unit","external_dcl","preprocessor","include_stmt",
"define_stmt","const_expression","function_def","function_header","dcl_spec",
"dcl_specifiers","dcl_specifier","type_qualifier","type_specifier","function_name",
"formal_param","opt_formal_param","formal_param_list","param_dcl","compound_st",
"opt_dcl_list","declaration_list","declaration","init_dcl_list","init_declarator",
"declarator","opt_number","opt_stat_list","statement_list","statement","expression_st",
"opt_expression","if_st","while_st","return_st","expression","assignment_exp",
"logical_or_exp","logical_and_exp","equality_exp","relational_exp","additive_exp",
"multiplicative_exp","unary_exp","postfix_exp","opt_actual_param","actual_param",
"actual_param_list","primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    55,    56,    56,    57,    57,    58,    58,    59,    59,    60,
    61,    62,    62,    62,    63,    64,    65,    66,    66,    67,
    67,    68,    69,    69,    69,    70,    71,    72,    72,    73,
    73,    74,    75,    76,    76,    77,    77,    78,    79,    79,
    80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
    85,    85,    85,    85,    85,    86,    87,    87,    88,    88,
    89,    90,    91,    92,    92,    92,    92,    92,    92,    92,
    93,    93,    94,    94,    95,    95,    95,    96,    96,    96,
    96,    96,    97,    97,    97,    98,    98,    98,    98,    99,
    99,    99,    99,    99,   100,   100,   100,   100,   100,   101,
   101,   102,   103,   103,   104,   104,   104,   104,   104
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     1,     1,     1,     1,     2,
     3,     1,     1,     1,     2,     3,     1,     1,     2,     1,
     1,     1,     1,     1,     1,     1,     3,     1,     0,     1,
     3,     2,     4,     1,     0,     1,     2,     3,     1,     3,
     1,     3,     1,     4,     1,     0,     1,     0,     1,     2,
     1,     1,     1,     1,     1,     2,     1,     0,     5,     7,
     5,     3,     1,     1,     3,     3,     3,     3,     3,     3,
     1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
     3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
     2,     2,     2,     2,     1,     4,     4,     2,     2,     1,
     0,     1,     1,     3,     1,     1,     1,     1,     3
};

static const short yydefact[] = {     0,
    22,    23,    25,    24,     0,     0,     1,     2,     4,     5,
     8,     9,     6,     0,     0,    17,    18,    20,    21,     7,
    10,     0,     3,    35,    15,    43,     0,     0,    39,    41,
    19,    13,    12,    14,    11,     0,    48,    34,    36,    46,
    29,    16,    38,     0,     0,    43,     0,    58,     0,     0,
     0,     0,   107,     0,   108,   105,   106,     0,    51,     0,
    47,    49,    52,     0,    53,    54,    55,    57,    63,    64,
    71,    73,    75,    78,    83,    86,    90,    95,    37,    45,
     0,     0,     0,    28,    30,    40,    42,     0,     0,     0,
    93,    94,     0,    91,    92,    33,    50,    56,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    98,    99,   101,
     0,    44,    32,    27,     0,     0,    62,     0,   109,    72,
    86,    74,    76,    77,    82,    81,    79,    80,    84,    85,
    89,    87,    88,    66,    67,    68,    69,    70,    65,   103,
     0,   100,   102,     0,    31,    58,    58,    97,     0,    96,
    59,    61,   104,    58,    60,     0,     0,     0
};

static const short yydefgoto[] = {   166,
     7,     8,     9,    10,    11,    12,    35,    13,    14,    15,
    16,    17,    18,    19,    27,    42,    83,    84,    85,    59,
    37,    38,    20,    28,    29,    30,    81,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,   151,   152,   153,    78
};

static const short yypact[] = {    13,
-32768,-32768,-32768,-32768,   -32,    12,    13,-32768,-32768,-32768,
-32768,-32768,-32768,    19,    41,    83,-32768,-32768,-32768,-32768,
-32768,     9,-32768,    83,-32768,   -11,    25,   -27,-32768,    51,
-32768,-32768,-32768,-32768,-32768,    47,    74,    83,-32768,    46,
    83,-32768,-32768,    47,    58,    45,    73,   102,    75,   102,
   102,   102,-32768,   102,-32768,-32768,-32768,   102,-32768,    77,
    74,-32768,-32768,    66,-32768,-32768,-32768,-32768,-32768,    90,
    93,    23,    -6,   -12,    -2,    53,   -13,-32768,-32768,-32768,
    70,    47,    86,    78,-32768,-32768,-32768,   102,    84,   102,
-32768,-32768,    92,-32768,-32768,-32768,-32768,-32768,   102,   102,
   102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
   102,   102,   102,   102,   102,   102,   102,-32768,-32768,   102,
   102,-32768,-32768,-32768,    83,    97,-32768,   100,-32768,    93,
-32768,    23,    -6,    -6,   -12,   -12,   -12,   -12,    -2,    -2,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   104,-32768,    87,    88,-32768,   110,   110,-32768,   102,-32768,
   129,-32768,-32768,   110,-32768,   142,   143,-32768
};

static const short yypgoto[] = {-32768,
-32768,   138,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   -23,
-32768,   132,-32768,-32768,-32768,-32768,-32768,-32768,    26,   136,
-32768,-32768,    -1,-32768,   108,    72,-32768,-32768,-32768,   -61,
-32768,   107,-32768,-32768,-32768,   -50,   -87,-32768,    57,    59,
   -58,   -36,   -20,   -47,-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		161


static const short yytable[] = {    97,
    36,    93,    91,    92,   118,   119,    94,   103,   104,    21,
    95,   120,    43,   -26,    36,     1,    44,    82,     2,   107,
     3,   108,    39,     4,   144,   145,   146,   147,   148,   149,
   109,   121,   150,    40,   101,   102,    79,   126,    32,   128,
   105,   106,   133,   134,    33,    24,   110,   111,    22,    41,
    34,   131,   131,   131,   131,   131,   131,   131,   131,   131,
   131,   141,   142,   143,     5,     6,   135,   136,   137,   138,
   154,   163,   112,   113,   114,   115,   116,    26,    47,    45,
    48,   117,    49,    46,    80,     1,   139,   140,     2,    40,
     3,    50,    51,     4,   161,   162,    87,    88,    52,    90,
    24,    82,   165,    53,    96,    98,    99,    54,   100,    55,
    56,   124,    57,   -58,    47,   122,    48,   129,    49,    50,
    51,   125,   156,   127,    58,   157,    52,    50,    51,   158,
   159,    53,   164,   160,    52,    54,    24,    55,    56,    53,
    57,   167,   168,    54,    23,    55,    56,    31,    57,    25,
   155,    86,    58,   123,    89,   130,     0,     0,   132,     0,
    58
};

static const short yycheck[] = {    61,
    24,    52,    50,    51,    18,    19,    54,    14,    15,    42,
    58,    25,    40,    25,    38,     3,    44,    41,     6,    32,
     8,    34,    24,    11,   112,   113,   114,   115,   116,   117,
    33,    45,   120,    45,    12,    13,    38,    88,    30,    90,
    47,    48,   101,   102,    36,    27,    49,    50,    37,    25,
    42,    99,   100,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,    52,    53,   103,   104,   105,   106,
   121,   159,    20,    21,    22,    23,    24,    37,     5,    29,
     7,    29,     9,    37,    39,     3,   107,   108,     6,    45,
     8,    18,    19,    11,   156,   157,    39,    25,    25,    25,
    27,   125,   164,    30,    28,    40,    17,    34,    16,    36,
    37,    26,    39,    40,     5,    46,     7,    26,     9,    18,
    19,    44,    26,    40,    51,    26,    25,    18,    19,    26,
    44,    30,     4,    46,    25,    34,    27,    36,    37,    30,
    39,     0,     0,    34,     7,    36,    37,    16,    39,    14,
   125,    44,    51,    82,    48,    99,    -1,    -1,   100,    -1,
    51
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
#line 33 "parser.y"
{semantic(1);;
    break;}
case 2:
#line 34 "parser.y"
{semantic(2);;
    break;}
case 3:
#line 35 "parser.y"
{semantic(108);;
    break;}
case 4:
#line 36 "parser.y"
{semantic(3);;
    break;}
case 5:
#line 37 "parser.y"
{semantic(100);;
    break;}
case 6:
#line 38 "parser.y"
{semantic(4);;
    break;}
case 7:
#line 39 "parser.y"
{semantic(5);;
    break;}
case 8:
#line 40 "parser.y"
{semantic(101);;
    break;}
case 9:
#line 41 "parser.y"
{semantic(102);;
    break;}
case 10:
#line 42 "parser.y"
{semantic(103);;
    break;}
case 11:
#line 43 "parser.y"
{
	 if (strcmp(current_type, "const string") == 0)
        	current_kind = "macro";  // 또는 "literal"
    	else
        	current_kind = "scalar"; // int, float 상수
	update_sym_table(st_index, line_num, current_type, current_kind);
	semantic(104);
;
    break;}
case 12:
#line 51 "parser.y"
{semantic(105);
        									strcpy(type_buffer, "const int");;
    break;}
case 13:
#line 53 "parser.y"
{semantic(106);
        									strcpy(type_buffer, "const float");;
    break;}
case 14:
#line 55 "parser.y"
{semantic(107);
        									strcpy(type_buffer, "const string");;
    break;}
case 15:
#line 57 "parser.y"
{
										set_param_info(func_name_index, param_list_buffer, param_count);

										// 버퍼 초기화
    										param_list_buffer[0] = '\0';
    										param_count = 0;
										semantic(6);;
    break;}
case 16:
#line 64 "parser.y"
{
										current_kind = "function";
										update_sym_table(func_name_index, line_num, current_type, current_kind); 											semantic(7);
										;
    break;}
case 17:
#line 68 "parser.y"
{semantic(8);;
    break;}
case 18:
#line 69 "parser.y"
{semantic(9);;
    break;}
case 19:
#line 70 "parser.y"
{semantic(10);;
    break;}
case 20:
#line 71 "parser.y"
{semantic(11);;
    break;}
case 21:
#line 72 "parser.y"
{semantic(12);;
    break;}
case 22:
#line 73 "parser.y"
{current_qualifier = "const"; semantic(13);;
    break;}
case 23:
#line 74 "parser.y"
{strcpy(type_buffer, current_qualifier ? "const int" : "int"); current_qualifier = NULL; semantic(14);;
    break;}
case 24:
#line 75 "parser.y"
{strcpy(type_buffer, current_qualifier ? "const float" : "float"); current_qualifier = NULL; semantic(14);;
    break;}
case 25:
#line 76 "parser.y"
{strcpy(type_buffer, current_qualifier ? "const void" : "void"); current_qualifier = NULL; semantic(15);;
    break;}
case 26:
#line 77 "parser.y"
{
										func_name_index = st_index;
										semantic(16);
										;
    break;}
case 27:
#line 81 "parser.y"
{semantic(17);;
    break;}
case 28:
#line 82 "parser.y"
{semantic(18);;
    break;}
case 29:
#line 83 "parser.y"
{semantic(19);;
    break;}
case 30:
#line 84 "parser.y"
{semantic(20);;
    break;}
case 31:
#line 85 "parser.y"
{semantic(21);;
    break;}
case 32:
#line 86 "parser.y"
{
										update_sym_table(st_index, line_num, current_type, current_kind);

										// 파라미터 정보 누적
										if (param_count > 0) strcat(param_list_buffer, ", ");
										strcat(param_list_buffer, current_type);
    										strcat(param_list_buffer, " ");
    										strcat(param_list_buffer, current_kind);
    										param_count++;

										semantic(22);;
    break;}
case 33:
#line 97 "parser.y"
{semantic(23);;
    break;}
case 34:
#line 98 "parser.y"
{semantic(24);;
    break;}
case 35:
#line 99 "parser.y"
{semantic(25);;
    break;}
case 36:
#line 100 "parser.y"
{semantic(26);;
    break;}
case 37:
#line 101 "parser.y"
{semantic(27);;
    break;}
case 38:
#line 102 "parser.y"
{semantic(28);;
    break;}
case 39:
#line 103 "parser.y"
{semantic(29);;
    break;}
case 40:
#line 104 "parser.y"
{semantic(30);;
    break;}
case 41:
#line 105 "parser.y"
{
										update_sym_table(st_index, line_num, current_type, current_kind);
										semantic(31);
										;
    break;}
case 42:
#line 109 "parser.y"
{
										update_sym_table(st_index, line_num, current_type, current_kind);
										semantic(32);
										;
    break;}
case 43:
#line 113 "parser.y"
{
										current_kind = "scalar";
										semantic(33);
										;
    break;}
case 44:
#line 117 "parser.y"
{
										current_kind = "array";
										semantic(34);
										;
    break;}
case 45:
#line 121 "parser.y"
{semantic(35);;
    break;}
case 46:
#line 122 "parser.y"
{semantic(36);;
    break;}
case 47:
#line 123 "parser.y"
{semantic(37);;
    break;}
case 48:
#line 124 "parser.y"
{semantic(38);;
    break;}
case 49:
#line 125 "parser.y"
{semantic(39);;
    break;}
case 50:
#line 126 "parser.y"
{semantic(40);;
    break;}
case 51:
#line 127 "parser.y"
{semantic(41);;
    break;}
case 52:
#line 128 "parser.y"
{semantic(42);;
    break;}
case 53:
#line 129 "parser.y"
{semantic(43);;
    break;}
case 54:
#line 130 "parser.y"
{semantic(44);;
    break;}
case 55:
#line 131 "parser.y"
{semantic(45);;
    break;}
case 56:
#line 133 "parser.y"
{semantic(46);;
    break;}
case 57:
#line 134 "parser.y"
{semantic(47);;
    break;}
case 58:
#line 135 "parser.y"
{semantic(48);;
    break;}
case 59:
#line 136 "parser.y"
{semantic(49);;
    break;}
case 60:
#line 137 "parser.y"
{semantic(50);;
    break;}
case 61:
#line 138 "parser.y"
{semantic(51);;
    break;}
case 62:
#line 139 "parser.y"
{semantic(52);;
    break;}
case 63:
#line 140 "parser.y"
{semantic(53);;
    break;}
case 64:
#line 141 "parser.y"
{semantic(54);;
    break;}
case 65:
#line 142 "parser.y"
{semantic(55);;
    break;}
case 66:
#line 143 "parser.y"
{semantic(56);;
    break;}
case 67:
#line 144 "parser.y"
{semantic(57);;
    break;}
case 68:
#line 145 "parser.y"
{semantic(58);;
    break;}
case 69:
#line 146 "parser.y"
{semantic(59);;
    break;}
case 70:
#line 147 "parser.y"
{semantic(60);;
    break;}
case 71:
#line 149 "parser.y"
{semantic(61);;
    break;}
case 72:
#line 150 "parser.y"
{semantic(62);;
    break;}
case 73:
#line 151 "parser.y"
{semantic(63);;
    break;}
case 74:
#line 152 "parser.y"
{semantic(64);;
    break;}
case 75:
#line 153 "parser.y"
{semantic(65);;
    break;}
case 76:
#line 154 "parser.y"
{semantic(66);;
    break;}
case 77:
#line 155 "parser.y"
{semantic(67);;
    break;}
case 78:
#line 156 "parser.y"
{semantic(68);;
    break;}
case 79:
#line 157 "parser.y"
{semantic(69);;
    break;}
case 80:
#line 158 "parser.y"
{semantic(70);;
    break;}
case 81:
#line 159 "parser.y"
{semantic(71);;
    break;}
case 82:
#line 160 "parser.y"
{semantic(72);;
    break;}
case 83:
#line 161 "parser.y"
{semantic(73);;
    break;}
case 84:
#line 162 "parser.y"
{semantic(74);;
    break;}
case 85:
#line 163 "parser.y"
{semantic(75);;
    break;}
case 86:
#line 164 "parser.y"
{semantic(76);;
    break;}
case 87:
#line 165 "parser.y"
{semantic(77);;
    break;}
case 88:
#line 166 "parser.y"
{semantic(78);;
    break;}
case 89:
#line 167 "parser.y"
{semantic(79);;
    break;}
case 90:
#line 168 "parser.y"
{semantic(80);;
    break;}
case 91:
#line 169 "parser.y"
{semantic(81);;
    break;}
case 92:
#line 170 "parser.y"
{semantic(82);;
    break;}
case 93:
#line 171 "parser.y"
{semantic(83);;
    break;}
case 94:
#line 172 "parser.y"
{semantic(84);;
    break;}
case 95:
#line 173 "parser.y"
{semantic(85);;
    break;}
case 96:
#line 174 "parser.y"
{semantic(86);;
    break;}
case 97:
#line 175 "parser.y"
{semantic(87);;
    break;}
case 98:
#line 176 "parser.y"
{semantic(88);;
    break;}
case 99:
#line 177 "parser.y"
{semantic(89);;
    break;}
case 100:
#line 178 "parser.y"
{semantic(90);;
    break;}
case 101:
#line 179 "parser.y"
{semantic(91);;
    break;}
case 102:
#line 180 "parser.y"
{semantic(92);;
    break;}
case 103:
#line 181 "parser.y"
{semantic(93);;
    break;}
case 104:
#line 182 "parser.y"
{semantic(94);;
    break;}
case 105:
#line 183 "parser.y"
{semantic(95);;
    break;}
case 106:
#line 184 "parser.y"
{semantic(96);;
    break;}
case 107:
#line 185 "parser.y"
{semantic(98);;
    break;}
case 108:
#line 186 "parser.y"
{semantic(99);;
    break;}
case 109:
#line 187 "parser.y"
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
#line 188 "parser.y"


void semantic(int n)
{	
	printf("reduced rule number = %d\n",n);
}
