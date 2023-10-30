/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SNOW_YY_H_INCLUDED
# define YY_YY_SNOW_YY_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_UNKNOW = 258,            /* TOKEN_UNKNOW  */
    TOKEN_WORD = 259,              /* TOKEN_WORD  */
    TOKEN_STRING = 260,            /* TOKEN_STRING  */
    TOKEN_DEC = 261,               /* TOKEN_DEC  */
    TOKEN_HEX = 262,               /* TOKEN_HEX  */
    TOKEN_FLOAT = 263,             /* TOKEN_FLOAT  */
    TOKEN_EQUAL = 264,             /* TOKEN_EQUAL  */
    TOKEN_PLUS = 265,              /* TOKEN_PLUS  */
    TOKEN_SUB = 266,               /* TOKEN_SUB  */
    TOKEN_TIMES = 267,             /* TOKEN_TIMES  */
    TOKEN_DIVIDE = 268,            /* TOKEN_DIVIDE  */
    TOKEN_POINT = 269,             /* TOKEN_POINT  */
    TOKEN_LP = 270,                /* TOKEN_LP  */
    TOKEN_RP = 271,                /* TOKEN_RP  */
    TOKEN_LS = 272,                /* TOKEN_LS  */
    TOKEN_RS = 273,                /* TOKEN_RS  */
    TOKEN_LC = 274,                /* TOKEN_LC  */
    TOKEN_RC = 275,                /* TOKEN_RC  */
    TOKEN_LA = 276,                /* TOKEN_LA  */
    TOKEN_RA = 277,                /* TOKEN_RA  */
    TOKEN_DOUBLE_AND = 278,        /* TOKEN_DOUBLE_AND  */
    TOKEN_DOUBLE_OR = 279,         /* TOKEN_DOUBLE_OR  */
    TOKEN_DOUBLE_LA = 280,         /* TOKEN_DOUBLE_LA  */
    TOKEN_DOUBLE_RA = 281,         /* TOKEN_DOUBLE_RA  */
    TOKEN_AND = 282,               /* TOKEN_AND  */
    TOKEN_OR = 283,                /* TOKEN_OR  */
    TOKEN_BROKEN_ISSUE = 284,      /* TOKEN_BROKEN_ISSUE  */
    TOKEN_AT = 285,                /* TOKEN_AT  */
    TOKEN_EXCLAMATION = 286,       /* TOKEN_EXCLAMATION  */
    TOKEN_HASHTAG = 287,           /* TOKEN_HASHTAG  */
    TOKEN_DOLLAR = 288,            /* TOKEN_DOLLAR  */
    TOKEN_PERCENT = 289,           /* TOKEN_PERCENT  */
    TOKEN_START = 290,             /* TOKEN_START  */
    TOKEN_COLON = 291,             /* TOKEN_COLON  */
    TOKEN_SEMICOLON = 292          /* TOKEN_SEMICOLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (void *parser);


#endif /* !YY_YY_SNOW_YY_H_INCLUDED  */
