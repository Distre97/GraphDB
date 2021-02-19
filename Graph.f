%{
#include <stdio.h>
#include <string.h>
#include "bison.hpp"
char* btoc(char*);
%}

WHITESPACE		([ \t]+)
NEWLINE 		(\r|\n)
INTEGER			([0-9]+)
DOUBLE			([0-9]+[.]*[0-9]*)

INT_STRING		(["][0-9]+["])
DOUBLE_STRING	(["][0-9]+[.]*[0-9]*["])
IDENTIFIER		([-_0-9A-Za-z]+)

OPERATOR		("+"|"-"|"*"|"/")
CAMPARE 		("<"|">"|"="|"<="|">="|"<>")
POINT			(".")
COLON			(":")
COMMA			(",")
SEMICOLON		(";")
BRACKET			("("|")")
SBRACKET		("["|"]")

TRUE			("TRUE"|"true")
FALSE			("FALSE"|"false")
CREATE			("CREATE"|"create")
MATCH			("MATCH"|"match")
DELETE			("DELETE"|"delete")
RETURN			("RETURN"|"return")
WITH			("WITH"|"with")
SET				("SET"|"set")
EXIT        	("EXIT"|"exit")

NODE			("NODE"|"node")
EDGE			("EDGE"|"edge")
ID     			("ID"|"id")
GRAPH			("GRAPH"|"graph")

FROM			("FROM"|"from")
TO				("TO"|"to")
ANY				("ANY"|"any")
OF				("OF"|"of")

AND				("AND"|"and")
OR				("OR"|"or")

MAX				("MAX"|"max")
MIN				("MIN"|"min")
AVG				("AVG"|"avg")

%%
{WHITESPACE}	;
{NEWLINE}		{return NEWLINE;}
{CAMPARE}		{yylval.cvar = strdup(yytext); return CAMPARE;}
{COLON}			{yylval.cvar = strdup(yytext); return COLON;}
{POINT}			{yylval.cvar = strdup(yytext); return POINT;}
{COMMA}			{yylval.cvar = strdup(yytext); return COMMA;}
{SEMICOLON}		{yylval.cvar = strdup(yytext); return SEMICOLON;}
{BRACKET}		{yylval.cvar = strdup(yytext); return BRACKET;}
{SBRACKET}		{yylval.cvar = strdup(yytext); return SBRACKET;}
{TRUE}			{yylval.cvar = btoc(strdup(yytext)); return TRUE;}
{FALSE}			{yylval.cvar = btoc(strdup(yytext)); return FALSE;}
{CREATE}		{yylval.cvar = strdup(yytext); return CREATE;}
{MATCH}			{yylval.cvar = strdup(yytext); return MATCH;}
{DELETE}		{yylval.cvar = strdup(yytext); return DELETE;}
{RETURN}		{yylval.cvar = strdup(yytext); return RETURN;}
{SET}			{yylval.cvar = strdup(yytext); return SET;}
{EXIT}			{yylval.cvar = strdup(yytext); return EXIT;}
{NODE}			{yylval.cvar = strdup(yytext); return NODE;}
{EDGE}			{yylval.cvar = strdup(yytext); return EDGE;}
{ID}			{yylval.cvar = strdup(yytext); return ID;}
{GRAPH}			{yylval.cvar = strdup(yytext); return GRAPH;}
{WITH}			{yylval.cvar = strdup(yytext); return WITH;}
{FROM}			{yylval.cvar = strdup(yytext); return FROM;}
{TO}			{yylval.cvar = strdup(yytext); return TO;}
{ANY}			{yylval.cvar = strdup(yytext); return ANY;}
{AND}			{yylval.cvar = strdup(yytext); return AND;}
{OR}			{yylval.cvar = strdup(yytext); return OR;}
{OF}			{yylval.cvar = strdup(yytext); return OF;}
{MAX}			{yylval.cvar = strdup(yytext); return MAX;}
{MIN}			{yylval.cvar = strdup(yytext); return MIN;}
{AVG}			{yylval.cvar = strdup(yytext); return AVG;}
{INTEGER}		{yylval.cvar = strdup(yytext); return INTEGER;}
{DOUBLE}		{yylval.cvar = strdup(yytext); return DOUBLE;}
{IDENTIFIER}	{yylval.cvar = strdup(yytext); return IDENTIFIER;}
{OPERATOR}		{yylval.cvar = strdup(yytext); return OPERATOR;}
{INT_STRING}	{yylval.cvar = strdup(yytext); return INT_STRING;}
{DOUBLE_STRING}	{yylval.cvar = strdup(yytext); return DOUBLE_STRING;}

%%
char* btoc(char* torf)
{
	if(strcmp(torf,"TRUE")==0||strcmp(torf,"true")==0)
		return (char*)"true";
	else if(strcmp(torf,"FALSE")==0||strcmp(torf,"false")==0)
		return (char*)"false";
}

int yywrap(void)
{
	return 1;
}
