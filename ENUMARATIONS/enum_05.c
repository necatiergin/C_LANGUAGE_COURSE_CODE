enum TokenKind {
    TOK_IDENTIFIER,
    TOK_NUMBER,
    TOK_PLUS,
    TOK_MINUS,
    TOK_STAR,
    TOK_SLASH,

    TOK_COUNT
};

static const char *token_names[TOK_COUNT] = {
    [TOK_IDENTIFIER] = "identifier",
    [TOK_NUMBER]     = "number",
    [TOK_PLUS]       = "+",
    [TOK_MINUS]      = "-",
    [TOK_STAR]       = "*",
    [TOK_SLASH]      = "/"
};
