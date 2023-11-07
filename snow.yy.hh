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

#ifndef YY_YY_SNOW_YY_HH_INCLUDED
# define YY_YY_SNOW_YY_HH_INCLUDED
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
    TOKEN_LP = 269,                /* TOKEN_LP  */
    TOKEN_RP = 270,                /* TOKEN_RP  */
    TOKEN_LS = 271,                /* TOKEN_LS  */
    TOKEN_RS = 272,                /* TOKEN_RS  */
    TOKEN_LC = 273,                /* TOKEN_LC  */
    TOKEN_RC = 274,                /* TOKEN_RC  */
    TOKEN_LA = 275,                /* TOKEN_LA  */
    TOKEN_RA = 276,                /* TOKEN_RA  */
    TOKEN_DOUBLE_AND = 277,        /* TOKEN_DOUBLE_AND  */
    TOKEN_DOUBLE_OR = 278,         /* TOKEN_DOUBLE_OR  */
    TOKEN_DOUBLE_LA = 279,         /* TOKEN_DOUBLE_LA  */
    TOKEN_DOUBLE_RA = 280,         /* TOKEN_DOUBLE_RA  */
    TOKEN_DOUBLE_EQUAL = 281,      /* TOKEN_DOUBLE_EQUAL  */
    TOKEN_LA_EQUAL = 282,          /* TOKEN_LA_EQUAL  */
    TOKEN_RA_EQUAL = 283,          /* TOKEN_RA_EQUAL  */
    TOKEN_NOT_EQUAL = 284,         /* TOKEN_NOT_EQUAL  */
    TOKEN_AND = 285,               /* TOKEN_AND  */
    TOKEN_OR = 286,                /* TOKEN_OR  */
    TOKEN_QUESTION = 287,          /* TOKEN_QUESTION  */
    TOKEN_POINT = 288,             /* TOKEN_POINT  */
    TOKEN_BROKEN_ISSUE = 289,      /* TOKEN_BROKEN_ISSUE  */
    TOKEN_EXCLAMATION = 290,       /* TOKEN_EXCLAMATION  */
    TOKEN_AT = 291,                /* TOKEN_AT  */
    TOKEN_HASHTAG = 292,           /* TOKEN_HASHTAG  */
    TOKEN_DOLLAR = 293,            /* TOKEN_DOLLAR  */
    TOKEN_PERCENT = 294,           /* TOKEN_PERCENT  */
    TOKEN_XOR = 295,               /* TOKEN_XOR  */
    TOKEN_COLON = 296,             /* TOKEN_COLON  */
    TOKEN_SEMICOLON = 297,         /* TOKEN_SEMICOLON  */
    TOKEN_BACKSLASH = 298          /* TOKEN_BACKSLASH  */
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


#endif /* !YY_YY_SNOW_YY_HH_INCLUDED  */
