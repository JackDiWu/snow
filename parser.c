#include "parser.h"
#include "snow.yy.h"
#include "lex.yy.h"

yyparse_t yy_init(void) {
    yyparse_t parser = malloc(sizeof(struct _yyparse_t));
    if (parser) {
        yylex_init(&parser->scanner);
    }
    return parser;
}

void yy_destroy(yyparse_t parser) {
    if (parser) {
        yylex_destroy(parser->scanner);
    }
}

int yy_scan(yyparse_t parser, const char *data, int size) {
    if (!parser) {
        return 0;
    }

    yy_scan_bytes(data, size, parser->scanner);

    yyset_lineno(1, parser->scanner);
    yyset_column(1, parser->scanner);

    return yyparse(parser->scanner);
}
