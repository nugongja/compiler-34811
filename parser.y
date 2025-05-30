%{
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
%}

%token TCONST TELSE TIF TINT TRETURN TVOID TWHILE 
%token TCHAR TFLOAT TEQUAL TNOTEQU TLESSE TGREATE TAND TOR TINC TDEC 
%token TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN TLPAREN TRPAREN
%token TLBRACE TRBRACE TASSIGN TFLOATNUM TSTAR TPLUS TMOD TMINUS TSLASH 
%token TINTNUM TIDENT TCHARCONST TNUMBER TSEMI TDOT TSTRING TERROR
%token TCOMMA TLSQUARE TRSQUARE TGREAT TLESS TMUL TDIV TNOT 
%token TINCLUDE TDEFINE

%nonassoc TLOWERTHANELSE
%nonassoc TELSE
%%
mini_c 		: translation_units					{semantic(1);};
translation_units	: translation_unit					{semantic(2);}
			| translation_units translation_unit		{semantic(108);};
translation_unit 	: external_dcl					{semantic(3);}
			| preprocessor 	 				{semantic(100);};
external_dcl 		: function_def					{semantic(4);}
		  	| declaration						{semantic(5);};
preprocessor	: include_stmt              				{semantic(101);}
			| define_stmt                				{semantic(102);};
include_stmt		: TINCLUDE TSTRING           			{semantic(103);};
define_stmt		: TDEFINE TIDENT const_expression 		{
	 if (strcmp(current_type, "const string") == 0)
        	current_kind = "macro";  // 또는 "literal"
    	else
        	current_kind = "scalar"; // int, float 상수
	update_sym_table(st_index, line_num, current_type, current_kind);
	semantic(104);
};
const_expression	: TINTNUM   					{semantic(105);
        									strcpy(type_buffer, "const int");}
			| TFLOATNUM 					{semantic(106);
        									strcpy(type_buffer, "const float");}
			| TSTRING   						{semantic(107);
        									strcpy(type_buffer, "const string");};
function_def 	: function_header compound_st			{
										set_param_info(func_name_index, param_list_buffer, param_count);

										// 버퍼 초기화
    										param_list_buffer[0] = '\0';
    										param_count = 0;
										semantic(6);};
function_header 	: dcl_spec function_name formal_param	{
										current_kind = "function";
										update_sym_table(func_name_index, line_num, current_type, current_kind); 											semantic(7);
										};
dcl_spec 		: dcl_specifiers					{semantic(8);};
dcl_specifiers 	: dcl_specifier					{semantic(9);}
		 	| dcl_specifiers dcl_specifier			{semantic(10);};
dcl_specifier 	: type_qualifier					{semantic(11);}
			| type_specifier					{semantic(12);};
type_qualifier 	: TCONST						{current_qualifier = "const"; semantic(13);};
type_specifier 	: TINT							{strcpy(type_buffer, current_qualifier ? "const int" : "int"); current_qualifier = NULL; semantic(14);}
			| TFLOAT						{strcpy(type_buffer, current_qualifier ? "const float" : "float"); current_qualifier = NULL; semantic(14);}	
		 	| TVOID						{strcpy(type_buffer, current_qualifier ? "const void" : "void"); current_qualifier = NULL; semantic(15);};
function_name 	: TIDENT						{
										func_name_index = st_index;
										semantic(16);
										};
formal_param 	: TLPAREN opt_formal_param TRPAREN 	{semantic(17);};
opt_formal_param 	: formal_param_list					{semantic(18);}
		   	|							{semantic(19);};
formal_param_list 	: param_dcl						{semantic(20);}
		    	| formal_param_list TCOMMA param_dcl 	{semantic(21);};
param_dcl 		: dcl_spec declarator				{
										update_sym_table(st_index, line_num, current_type, current_kind);

										// 파라미터 정보 누적
										if (param_count > 0) strcat(param_list_buffer, ", ");
										strcat(param_list_buffer, current_type);
    										strcat(param_list_buffer, " ");
    										strcat(param_list_buffer, current_kind);
    										param_count++;

										semantic(22);};
compound_st 	: TLBRACE opt_dcl_list opt_stat_list TRBRACE 	{semantic(23);};
opt_dcl_list 		: declaration_list					{semantic(24);}
			|							{semantic(25);};
declaration_list 	: declaration						{semantic(26);}
			| declaration_list declaration 			{semantic(27);};
declaration 		: dcl_spec init_dcl_list TSEMI			{semantic(28);};
init_dcl_list 		: init_declarator					{semantic(29);}
			| init_dcl_list TCOMMA init_declarator 		{semantic(30);};
init_declarator 	: declarator						{
										update_sym_table(st_index, line_num, current_type, current_kind);
										semantic(31);
										}
		 	| declarator TASSIGN TNUMBER			{
										update_sym_table(st_index, line_num, current_type, current_kind);
										semantic(32);
										};
declarator 		: TIDENT						{
										current_kind = "scalar";
										semantic(33);
										}
	     		| TIDENT TLSQUARE opt_number TRSQUARE			{
										current_kind = "array";
										semantic(34);
										};
opt_number 	: TNUMBER					{semantic(35);}
	     		|						{semantic(36);};
opt_stat_list 		: statement_list				{semantic(37);}
		 	|						{semantic(38);};
statement_list 	: statement					{semantic(39);}
		 	| statement_list statement 			{semantic(40);};
statement 		: compound_st				{semantic(41);}
	   		| expression_st				{semantic(42);}
	   		| if_st						{semantic(43);}
	   		| while_st					{semantic(44);}
	   		| return_st					{semantic(45);}
	   		;
expression_st 	: opt_expression TSEMI				{semantic(46);};
opt_expression 	: expression					{semantic(47);}
		 	|						{semantic(48);};
if_st 			: TIF TLPAREN expression TRPAREN statement %prec TLOWERTHANELSE		{semantic(49);}
			| TIF TLPAREN expression TRPAREN statement TELSE statement %prec TLOWERTHANELSE	{semantic(50);};
while_st 		: TWHILE TLPAREN expression TRPAREN statement 		{semantic(51);};
return_st 		: TRETURN opt_expression TSEMI			{semantic(52);};
expression 		: assignment_exp				{semantic(53);};
assignment_exp 	: logical_or_exp				{semantic(54);}
			| unary_exp TASSIGN assignment_exp 		{semantic(55);}
			| unary_exp TADDASSIGN assignment_exp 	{semantic(56);}
			| unary_exp TSUBASSIGN assignment_exp 	{semantic(57);}
			| unary_exp TMULASSIGN assignment_exp 	{semantic(58);}
			| unary_exp TDIVASSIGN assignment_exp 	{semantic(59);}
			| unary_exp TMODASSIGN assignment_exp 	{semantic(60);}
			;
logical_or_exp 	: logical_and_exp				{semantic(61);}
			| logical_or_exp TOR logical_and_exp 	{semantic(62);};
logical_and_exp 	: equality_exp					{semantic(63);}
		 	| logical_and_exp TAND equality_exp 	{semantic(64);};
equality_exp 	: relational_exp				{semantic(65);}
			| equality_exp TEQUAL relational_exp 	{semantic(66);}
			| equality_exp TNOTEQU relational_exp 	{semantic(67);};
relational_exp 	: additive_exp 				{semantic(68);}
			| relational_exp TGREAT additive_exp 		{semantic(69);}
			| relational_exp TLESS additive_exp 		{semantic(70);}
			| relational_exp TGREATE additive_exp 	{semantic(71);}
			| relational_exp TLESSE additive_exp 	{semantic(72);};
additive_exp 	: multiplicative_exp				{semantic(73);}
			| additive_exp TPLUS multiplicative_exp 	{semantic(74);}
			| additive_exp TMINUS multiplicative_exp 	{semantic(75);};
multiplicative_exp 	: unary_exp					{semantic(76);}
		    	| multiplicative_exp TMUL unary_exp 		{semantic(77);}
		    	| multiplicative_exp TDIV unary_exp 		{semantic(78);}
		    	| multiplicative_exp TMOD unary_exp 		{semantic(79);};
unary_exp 		: postfix_exp					{semantic(80);}
	   		| TMINUS unary_exp				{semantic(81);}
	   		| TNOT unary_exp				{semantic(82);}
	   		| TINC unary_exp				{semantic(83);}
	   		| TDEC unary_exp				{semantic(84);};
postfix_exp 		: primary_exp					{semantic(85);}
	      		| postfix_exp TLSQUARE expression TRSQUARE 		{semantic(86);}
	      		| postfix_exp TLPAREN opt_actual_param TRPAREN 	{semantic(87);}
	      		| postfix_exp TINC				{semantic(88);}
	      		| postfix_exp TDEC				{semantic(89);};
opt_actual_param 	: actual_param				{semantic(90);}
		  	|						{semantic(91);};
actual_param 	: actual_param_list				{semantic(92);};
actual_param_list 	: assignment_exp				{semantic(93);}
		   	| actual_param_list TCOMMA assignment_exp 	{semantic(94);};
primary_exp 		: TIDENT						{semantic(95);}
	     		| TNUMBER					{semantic(96);}
			| TFLOATNUM				{semantic(98);}
			| TINTNUM					{semantic(99);}
	     		| TLPAREN expression TRPAREN				{semantic(97);};
%%

void semantic(int n)
{	
	printf("reduced rule number = %d\n",n);
}
