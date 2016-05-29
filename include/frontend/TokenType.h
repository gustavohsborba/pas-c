#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

#include <string>
#include <cmath>
#include <vector>

using std::string;
using std::vector;

#define bit(i) (1L<<i)
#define tok_no(i) ((long)log2(i))

typedef enum TokenType {
	TOK_VAR 		= bit(0),
	TOK_BEGIN 		= bit(1),
	TOK_END 		= bit(2),
	TOK_IS			= bit(3),
	TOK_IF			= bit(4),
	TOK_THEN		= bit(5),
	TOK_ELSE		= bit(6),
	TOK_INT			= bit(7),
	TOK_STRING		= bit(8),
	TOK_DO			= bit(9),
	TOK_WHILE		= bit(10),
	TOK_IN 			= bit(11),
	TOK_OUT			= bit(12),
	TOK_NOT			= bit(13),
	TOK_OR			= bit(14),
	TOK_AND			= bit(15),
	TOK_ID			= bit(16),
	TOK_CONST_INT	= bit(17),
	TOK_CONST_STR	= bit(18),
	TOK_EQUALS		= bit(19),
	TOK_LT			= bit(20),
	TOK_GT			= bit(21),
	TOK_LTE			= bit(22),
	TOK_GTE			= bit(23),
	TOK_DIFF		= bit(24),
	TOK_ADD			= bit(25),
	TOK_SUB			= bit(26),
	TOK_MULT		= bit(27),
	TOK_DIV			= bit(28),
	TOK_ASSIGN		= bit(29),
	TOK_SEMICOLON	= bit(30),
	TOK_COMMA		= bit(31),
	TOK_STR_OPEN	= bit(32),
	TOK_STR_CLOSE	= bit(33),
	TOK_PAR_OPEN	= bit(34),
	TOK_PAR_CLOSE	= bit(35),
	TOK_EOF			= bit(36),

	TOK_UNKNOWN		= bit(37)
}TokenType;

#define MAX_IDENTIFIER_SIZE 15 

const string TOKEN_NAME [] = {
	"TOK_VAR",
	"TOK_BEGIN",
	"TOK_END",
	"TOK_IS",
	"TOK_IF",
	"TOK_THEN",
	"TOK_ELSE",
	"TOK_INT",
	"TOK_STRING",
	"TOK_DO",
	"TOK_WHILE",
	"TOK_IN",
	"TOK_OUT",
	"TOK_NOT",
	"TOK_OR",
	"TOK_AND",
	"TOK_ID",
	"TOK_CONST_INT",
	"TOK_CONST_STR",
	"TOK_EQUALS",
	"TOK_LT",
	"TOK_GT",
	"TOK_LTE",
	"TOK_GTE",
	"TOK_DIFF",
	"TOK_ADD",
	"TOK_SUB",
	"TOK_MULT",
	"TOK_DIV",
	"TOK_ASSIGN",
	"TOK_SEMICOLON",
	"TOK_COMMA",
	"TOK_STR_OPEN",
	"TOK_STR_CLOSE",
	"TOK_PAR_OPEN",
	"TOK_PAR_CLOSE",
	"TOK_EOF",
	"TOK_UNKNOWN",
};

#define tok_name(t) (TOKEN_NAME[tok_no(t)])

/**
 * \brief get a bitmask of TokenTypes and return a list of all TokenTypes separated
 *
 */
vector<TokenType> unmask(long mask);

#endif