%{
#include <stdio.h>
#include "Graph.h"
int yylex();
int yyerror(char*);
_ID vid;
_ID eid;
_IDS ids;
_IDS fids;
_IDS tids;
_IDS vids;
_IDS eids;
_IDS tmp_ids;
_popes tmp_pv;
_lists keys;
bool vert;
Direc  dir;
string name;
string label;
string equation;
std::vector<_IDS> tmp_idsv;
auto& graph = Graph::getInstance();
%}

%union
{
	int ivar;
	char* cvar;
	double dvar;
}

%left OR
%left AND
%left OPERATOR
%nonassoc ONE

%token <cvar> INTEGER INT_STRING
%token <cvar> DOUBLE DOUBLE_STRING
%token <cvar> WHITESPACE NEWLINE
%token <cvar> NODE EDGE ID IDENTIFIER TRUE FALSE GRAPH
%token <cvar> CREATE MATCH DELETE RETURN WITH SET EXIT
%token <cvar> BRACKET SBRACKET CAMPARE COLON SEMICOLON COMMA POINT
%token <cvar> FROM TO ANY OF
%token <cvar> MAX MIN AVG OPERATOR

%type <ivar> n_logic_fomula e_logic_fomula n_logic e_logic id
%type <ivar> node_logic edge_logic
%type <cvar> bool STRING 
%type <cvar> ln_dict pv_dict
%type <cvar> pp_assign fore behind
%type <cvar> match_node

%%
Program :
		 |Program Statement NEWLINE
		 |error NEWLINE	{yyclearin;yyerrok;}
		 ;

Statement : create_node
		   |create_edge
		   |match
		   |match operate
		   |quit
		   ;

match : match_node		{vert = true;tmp_idsv.clear();}
	   |match_edge		{vert = false;tmp_idsv.clear();}
	   ;

operate : set
		 |delete
		 |return
		 |set operate
		 |delete operate
		 |return operate
		 ;

STRING : IDENTIFIER
		|INT_STRING
		|DOUBLE_STRING
		;

create_node :  CREATE NODE SBRACKET ln_dict pv_dict SBRACKET
			  {
                vid = graph.add_vert(name, label, tmp_pv);
                tmp_pv.clear();
			  	//printf("create_node %s %s\n\n",$4,$5);
			  };

create_edge : CREATE EDGE SBRACKET IDENTIFIER SEMICOLON pv_dict SBRACKET edge_from edge_to
  			  {
  			  	auto edge = _edge(*fids.begin(), *tids.begin());
  			  	fids.clear();
                tids.clear();
  			  	eid = graph.add_edge(edge, string($4), tmp_pv);
                tmp_pv.clear();
  			  };

edge_from : FROM match_node  {fids = vids;};

edge_to : TO match_node  {tids = vids;};

ln_dict : IDENTIFIER COLON IDENTIFIER SEMICOLON
		{
			//printf("label:%s	name:%s\n",$1,$3);
			name = $3;
			label = $1;
		};

bool : TRUE
	  |FALSE
	  ;

pv_dict : IDENTIFIER COLON bool 
		{
			//printf("property:%s	value:%s type:bool\n",$1,$3);
			tmp_pv.emplace_back(_prop(string($1), make_data(_pack(3, string($3)))));
		}
		 |IDENTIFIER COLON INTEGER 
		{
			//printf("property:%s	value:%s type:integer\n",$1,$3);
			tmp_pv.emplace_back(_prop(string($1), make_data(_pack(1, string($3)))));
		}
		 |IDENTIFIER COLON DOUBLE 
		{
			//printf("property:%s	value:%s type:double\n",$1,$3);
			tmp_pv.emplace_back(_prop(string($1), make_data(_pack(2, string($3)))));
		}
		 |IDENTIFIER COLON STRING 
		{
			//printf("property:%s	value:%s type:string\n",$1,$3);
			tmp_pv.emplace_back(_prop(string($1), make_data(_pack(0, string($3)))));
		}
		 |pv_dict IDENTIFIER COLON bool 
		{
			//printf("property:%s	value:%s type:bool\n",$2,$4);
			tmp_pv.emplace_back(_prop(string($2), make_data(_pack(3, string($4)))));
		}
		 |pv_dict IDENTIFIER COLON INTEGER 
		{
			//printf("property:%s	value:%s type:integer\n",$2,$4);
			tmp_pv.emplace_back(_prop(string($2), make_data(_pack(1, string($4)))));
		}
		 |pv_dict IDENTIFIER COLON DOUBLE 
		{
			//printf("property:%s	value:%s type:double\n",$2,$4);
			tmp_pv.emplace_back(_prop(string($2), make_data(_pack(2, string($4)))));
		}
		 |pv_dict IDENTIFIER COLON STRING 
		{
			//printf("property:%s	value:%s type:string\n",$2,$4);
			tmp_pv.emplace_back(_prop(string($2), make_data(_pack(0, string($4)))));
		};

id : INTEGER	{/*printf("id:%s\n", $2);*/ids.emplace(atoi($1));}
	|id INTEGER	{/*printf("id:%s\n", $2);*/ids.emplace(atoi($2));}
	;

match_node : MATCH NODE ID SBRACKET id SBRACKET
			{
				//printf("match_id_1\n");
				vids = ids;
				ids.clear();
			}
			|MATCH NODE SBRACKET node_logic SBRACKET
			{
				//printf("match_node_1\n");
				vids = tmp_idsv[$4];
				//cout<< *vids.begin();
			}
			|MATCH NODE ID SBRACKET id SBRACKET any_edge
			{
				//printf("match_id_2\n");
				vids = ids;
				ids.clear();
				tmp_ids = graph.inq_vert(eids, dir);
				vids = vids & tmp_ids;
			}
			|MATCH NODE SBRACKET node_logic SBRACKET any_edge
			{
				//printf("match_node_2\n");
				vids = tmp_idsv[$4];
				tmp_ids = graph.inq_vert(eids, dir);
				vids = vids & tmp_ids;
			}
			|MATCH NODE ID SBRACKET id SBRACKET with_edge
			{
				//printf("match_id_3\n");
				vids = ids;
				ids.clear();
				tmp_ids = graph.inq_vert(eids, dir);
				vids = vids & tmp_ids;
			}
			|MATCH NODE SBRACKET node_logic SBRACKET with_edge
			{
				//printf("match_node_3\n");
				vids = tmp_idsv[$4];
				tmp_ids = graph.inq_vert(eids, dir);
				vids = vids & tmp_ids;
			};

any_edge : WITH EDGE SBRACKET edge_logic SBRACKET FROM ANY
			{
				dir = Direc::TO;
		  		eids = tmp_idsv[$4];
			}
		  |WITH EDGE SBRACKET edge_logic SBRACKET TO ANY
		  	{
		  		dir = Direc::FROM;
		  		eids = tmp_idsv[$4];
		  	};

with_edge : WITH EDGE SBRACKET edge_logic SBRACKET edge_from
			{
				dir = Direc::TO;
		  		eids = tmp_idsv[$4] & graph.inq_edge(fids, Direc::OUT);
			}
		   |WITH EDGE SBRACKET edge_logic SBRACKET edge_to
		   {
				dir = Direc::FROM;
		  		eids = tmp_idsv[$4] & graph.inq_edge(tids, Direc::IN);
			};

match_edge : MATCH EDGE ID SBRACKET id SBRACKET
			{
				//printf("edge_id_1\n");eids = tmp_ids;
				eids = ids;
				ids.clear();
			}
			 |MATCH EDGE SBRACKET edge_logic SBRACKET FROM ANY TO ANY
			{
				//printf("edge_id_1\n");eids = tmp_ids;
				eids = tmp_idsv[$4];
			}
			 |MATCH EDGE SBRACKET edge_logic SBRACKET edge_from edge_to
			{
				//printf("edge_id_1\n");eids = tmp_ids;
				eids = tmp_idsv[$4];
				tmp_ids = graph.inq_edge(fids, Direc::OUT) & graph.inq_edge(tids, Direc::IN);
				eids = eids & tmp_ids;

			}
			 |MATCH EDGE SBRACKET edge_logic SBRACKET edge_from TO ANY
			{
				//printf("edge_id_1\n");eids = tmp_ids;
				eids = tmp_idsv[$4];
				tmp_ids = graph.inq_edge(fids, Direc::OUT);
				eids = eids & tmp_ids;
			}
			 |MATCH EDGE SBRACKET edge_logic SBRACKET FROM ANY edge_to
			{
				//printf("edge_id_1\n");eids = tmp_ids;
				eids = tmp_idsv[$4];
				//cout<<*eids.begin()<<endl;
				tmp_ids = graph.inq_edge(tids, Direc::IN);
				eids = eids & tmp_ids;
				//cout<<*tmp_ids.begin()<<endl;
			};

node_logic : n_logic
			{
				if ($1<0)
					$$ = -1*$1-1;
				else
					$$=$1;
			};

n_logic : n_logic_fomula
		{
			//printf("logic %s\n",$1);
			$$ = $1;
		}
	   	|n_logic AND n_logic
		{
			_IDS ids1;
			_IDS ids2;
			//printf("AND %d %d\n",$1,$3);
			if ($1 < 0) ids1 = tmp_idsv[-1*$1-1];
			else ids1 = tmp_idsv[$1];
			if ($3 < 0) ids1 = tmp_idsv[-1*$3-1];
			else ids2 = tmp_idsv[$3];
			tmp_ids = ids1 & ids2;
			tmp_idsv.emplace_back(tmp_ids);
			$$ = -1*tmp_idsv.size();
		}
	   |n_logic OR n_logic
	   {
	   		_IDS ids1;
	   		_IDS ids2;
	   		//printf("OR %d %d\n",$1,$3);
	   		if ($1 < 0) ids1 = tmp_idsv[-1*$1-1];
	   		else ids1 = tmp_idsv[$1];
	   		if ($3 < 0) ids1 = tmp_idsv[-1*$3-1];
	   		else ids2 = tmp_idsv[$3];
	   		tmp_ids = ids1 | ids2;
	   		tmp_idsv.emplace_back(tmp_ids);
	   		$$ = -1*tmp_idsv.size();
	   }
	   |BRACKET n_logic AND n_logic BRACKET	%prec ONE
	   {
	   		_IDS ids1;
	   		_IDS ids2;
	   		//printf("AND %d %d\n",$2,$4);
	   		if ($2 < 0) ids1 = tmp_idsv[-1*$2-1];
	   		else ids1 = tmp_idsv[$2];
	   		if ($4 < 0) ids1 = tmp_idsv[-1*$4-1];
	   		else ids2 = tmp_idsv[$4];
	   		tmp_ids = ids1 & ids2;
	   		tmp_idsv.emplace_back(tmp_ids);
	   		$$ = -1*tmp_idsv.size();
	   }
	   |BRACKET n_logic OR n_logic BRACKET 	%prec ONE
	   {
	   		_IDS ids1;
	   		_IDS ids2;
	   		//printf("OR %d %d\n",$2,$4);
	   		if ($2 < 0) ids1 = tmp_idsv[-1*$2-1];
	   		else ids1 = tmp_idsv[$2];
	   		if ($4 < 0) ids1 = tmp_idsv[-1*$4-1];
	   		else ids2 = tmp_idsv[$4];
	   		tmp_ids = ids1 | ids2;
	   		tmp_idsv.emplace_back(tmp_ids);
	   		$$ = -1*tmp_idsv.size();
	   };

edge_logic : e_logic{
	if ($1<0)
		$$ = -1*$1-1;
	else
		$$=$1;
};
e_logic : e_logic_fomula
		{
			//printf("logic %s\n",$1);
			$$ = $1;
		}
		 |e_logic AND e_logic
		{
			_IDS ids1;
			_IDS ids2;
			//printf("AND %d %d\n",$1,$3);
			if ($1 < 0) ids1 = tmp_idsv[-1*$1-1];
			else ids1 = tmp_idsv[$1];
			if ($3 < 0) ids1 = tmp_idsv[-1*$3-1];
			else ids2 = tmp_idsv[$3];
			tmp_ids = ids1 & ids2;
			tmp_idsv.emplace_back(tmp_ids);
			$$ = -1*tmp_idsv.size();
		}
		 |e_logic OR e_logic
		{
			_IDS ids1;
			_IDS ids2;
			//printf("OR %d %d\n",$1,$3);
			if ($1 < 0) ids1 = tmp_idsv[-1*$1-1];
			else ids1 = tmp_idsv[$1];
			if ($3 < 0) ids1 = tmp_idsv[-1*$3-1];
			else ids2 = tmp_idsv[$3];
			tmp_ids = ids1 | ids2;
			tmp_idsv.emplace_back(tmp_ids);
			$$ = -1*tmp_idsv.size();
		}
		 |BRACKET e_logic AND e_logic BRACKET	%prec ONE
		{
			_IDS ids1;
			_IDS ids2;
			//printf("AND %d %d\n",$2,$4);
			if ($2 < 0) ids1 = tmp_idsv[-1*$2-1];
			else ids1 = tmp_idsv[$2];
			if ($4 < 0) ids1 = tmp_idsv[-1*$4-1];
			else ids2 = tmp_idsv[$4];
			tmp_ids = ids1 & ids2;
			tmp_idsv.emplace_back(tmp_ids);
			$$ = -1*tmp_idsv.size();
		}
		 |BRACKET e_logic OR e_logic BRACKET 	%prec ONE
		{
			_IDS ids1;
			_IDS ids2;
			//printf("OR %d %d\n",$2,$4);
			if ($2 < 0) ids1 = tmp_idsv[-1*$2-1];
			else ids1 = tmp_idsv[$2];
			if ($4 < 0) ids1 = tmp_idsv[-1*$4-1];
			else ids2 = tmp_idsv[$4];
			tmp_ids = ids1 | ids2;
			tmp_idsv.emplace_back(tmp_ids);
			$$ = -1*tmp_idsv.size();
		};

n_logic_fomula : IDENTIFIER CAMPARE bool
				{
					//printf("%s %s %s\n",$1,$2,$3);
					tmp_idsv.emplace_back(graph.inq_vert(_cond(set_token(string($2)),_prop(string($1), make_data(_pack(3, string($3)))))));
					$$ = tmp_idsv.size() - 1;
				}
			  |IDENTIFIER CAMPARE INTEGER
			 	{
					//printf("%s %s %s\n",$1,$2,$3);
					tmp_idsv.emplace_back(graph.inq_vert(_cond(set_token(string($2)),_prop(string($1), make_data(_pack(1, string($3)))))));
					$$ = tmp_idsv.size() - 1;
				}
			  |IDENTIFIER CAMPARE DOUBLE
			  	{
					//printf("%s %s %s\n",$1,$2,$3);
					tmp_idsv.emplace_back(graph.inq_vert(_cond(set_token(string($2)),_prop(string($1), make_data(_pack(2, string($3)))))));
					$$ = tmp_idsv.size() - 1;
				}
			  |IDENTIFIER CAMPARE STRING
			  	{
					//printf("%s %s %s\n",$1,$2,$3);
					tmp_idsv.emplace_back(graph.inq_vert(_cond(set_token(string($2)),_prop(string($1), make_data(_pack(0, string($3)))))));
					$$ = tmp_idsv.size() - 1;
				}
			  ;

e_logic_fomula : IDENTIFIER CAMPARE bool
				{
					//printf("%s %s %s\n",$1,$2,$3);
					tmp_idsv.emplace_back(graph.inq_edge(_cond(set_token(string($2)),_prop(string($1), make_data(_pack(3, string($3)))))));
					$$ = tmp_idsv.size() - 1;
				}
			  |IDENTIFIER CAMPARE INTEGER
			 	{
					//printf("%s %s %s\n",$1,$2,$3);
					tmp_idsv.emplace_back(graph.inq_edge(_cond(set_token(string($2)),_prop(string($1), make_data(_pack(1, string($3)))))));
					$$ = tmp_idsv.size() - 1;
				}
			  |IDENTIFIER CAMPARE DOUBLE
			  	{
					//printf("%s %s %s\n",$1,$2,$3);
					tmp_idsv.emplace_back(graph.inq_edge(_cond(set_token(string($2)),_prop(string($1), make_data(_pack(2, string($3)))))));
					$$ = tmp_idsv.size() - 1;
				}
			  |IDENTIFIER CAMPARE STRING
			  	{
					//printf("%s %s %s\n",$1,$2,$3);
					tmp_idsv.emplace_back(graph.inq_edge(_cond(set_token(string($2)),_prop(string($1), make_data(_pack(0, string($3)))))));
					$$ = tmp_idsv.size() - 1;
				};

property : IDENTIFIER					{/*printf("%s\n",$1);*/keys.emplace_back(string($1));}
		  |property IDENTIFIER			 {/*printf("%s\n",$1);*/keys.emplace_back(string($2));}
		  ;

return : RETURN SBRACKET property SBRACKET
		{
			//printf("return ok\n\n");
			if (vert)
				graph.show_vert(vids, keys);
			else
				graph.show_edge(eids, keys);
			keys.clear();
		}
		|RETURN
		{
			//printf("return ok\n\n");
			if (vert)
				graph.show_vert(vids,{});
			else
				graph.show_edge(eids,{});
			//cout<<*eids.begin()<<endl;
		}
		|RETURN MAX OF IDENTIFIER 								
		{
			//printf("return %s\n\n",$2);
			if (vert)
				graph.inq_vert(string($4), Stats::MAX, vids);
			else
				graph.inq_edge(string($4), Stats::MAX, eids);
		}
		|RETURN MIN OF IDENTIFIER 								
		{
			//printf("return %s\n\n",$2);
			if (vert)
				graph.inq_vert(string($4), Stats::MIN, vids);
			else
				graph.inq_edge(string($4), Stats::MIN, eids);
		}
		|RETURN AVG OF IDENTIFIER									
		{
			//printf("return %s\n\n",$2);
			if (vert)
				graph.inq_vert(string($4), Stats::AVG, vids);
			else
				graph.inq_edge(string($4), Stats::AVG, eids);
		}
		|RETURN GRAPH
		{
			graph.show_graph(vids);
		};

set : SET SBRACKET pv_dict SBRACKET							
	{
		//printf("set ok\n\n");
		if (vert)
			for (auto id : vids) graph.add_vert_prop(id, tmp_pv);
		else
			for (auto id : eids) graph.add_edge_prop(id, tmp_pv);
		tmp_pv.clear();
	}
	 |SET SBRACKET pp_assign SBRACKET		
	{
		//printf("set ok\n\n");cout<<equation;
		if (vert)
				graph.alt_vert(vids, equation);
			else
				graph.alt_edge(eids, equation);
		equation="";
	};

pp_assign: fore behind ;

fore :  IDENTIFIER COLON INTEGER				{equation = equation+string($1)+"="+string($3);}
	   |IDENTIFIER COLON DOUBLE 				{equation = equation+string($1)+"="+string($3);}
	   |IDENTIFIER COLON IDENTIFIER				{equation = equation+string($1)+"="+string($3);}
	   |IDENTIFIER COLON BRACKET INTEGER		{equation = equation+string($1)+"="+string($3)+string($4);}
	   |IDENTIFIER COLON BRACKET DOUBLE 		{equation = equation+string($1)+"="+string($3)+string($4);}
	   |IDENTIFIER COLON BRACKET IDENTIFIER		{equation = equation+string($1)+"="+string($3)+string($4);}
	   ;

behind : BRACKET								{equation = equation+string($1);}
		|OPERATOR INTEGER						{equation = equation+string($1)+string($2);}
		|OPERATOR DOUBLE						{equation = equation+string($1)+string($2);}
		|OPERATOR IDENTIFIER					{equation = equation+string($1)+string($2);}
		|OPERATOR BRACKET INTEGER				{equation = equation+string($1)+string($2)+string($3);}
		|OPERATOR BRACKET DOUBLE				{equation = equation+string($1)+string($2)+string($3);}
		|OPERATOR BRACKET IDENTIFIER			{equation = equation+string($1)+string($2)+string($3);}
		|OPERATOR INTEGER BRACKET				{equation = equation+string($1)+string($2)+string($3);}
		|OPERATOR DOUBLE BRACKET				{equation = equation+string($1)+string($2)+string($3);}
		|OPERATOR IDENTIFIER BRACKET			{equation = equation+string($1)+string($2)+string($3);}
		|behind BRACKET							{equation = equation+string($2);}
		|behind OPERATOR INTEGER				{equation = equation+string($2)+string($3);}
		|behind OPERATOR DOUBLE					{equation = equation+string($2)+string($3);}
		|behind OPERATOR IDENTIFIER				{equation = equation+string($2)+string($3);}
		|behind OPERATOR BRACKET INTEGER		{equation = equation+string($2)+string($3)+string($4);}
		|behind OPERATOR BRACKET DOUBLE			{equation = equation+string($2)+string($3)+string($4);}
		|behind OPERATOR BRACKET IDENTIFIER		{equation = equation+string($2)+string($3)+string($4);}
		|behind OPERATOR INTEGER BRACKET		{equation = equation+string($2)+string($3)+string($4);}
		|behind OPERATOR DOUBLE BRACKET			{equation = equation+string($2)+string($3)+string($4);}
		|behind OPERATOR IDENTIFIER BRACKET		{equation = equation+string($2)+string($3)+string($4);}
		;

delete : DELETE										
		{
			//printf("DELETE_ok_1\n\n");
			if (vert)
				graph.del_vert(vids);
			else
				graph.del_edge(eids);
		}
		|DELETE SBRACKET property SBRACKET				
		{
			//printf("DELETE_ok_2\n\n");
			if (vert)
				graph.del_vert(vids, keys);
			else
				graph.del_edge(eids, keys);
			keys.clear();
		};

quit : EXIT
	  {
		  graph.save();
		  printf("Graph_db closed\n");
		  exit(0);
	  }

%%
int yyerror(char *s)
	{
        fprintf(stdout, "%s\n", s);
        return 0;
    }

int main(void)
{
	yyparse();
	return 1;
}