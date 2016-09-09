
/******************************************************************
* author: zhaozhongshu@baidu.com
*******************************************************************/
//ragel ini_parser.rl -o ini_parser.cpp -G2

#include "ini_parser.h"
using namespace std;

ini_parser::ini_parser(const char* path)
{
	if( path )
	{
		fpath = path;
	}
}

ini_parser::~ini_parser(void)
{
}


static const int ini_parser_start = 17;
static const int ini_parser_first_final = 17;
static const int ini_parser_error = 0;

static const int ini_parser_en_main = 17;




bool ini_parser::load(const char* path)
{
	pairs.clear();
	if( path )
	{
		fpath = path;
	}
	std::string buffer;
	read_file_contents(fpath.c_str(), buffer);
	if( buffer.empty() )
	{
		return false;
	}

	int cs;
	const char* p = buffer.c_str();
	const char* pe = buffer.c_str() + buffer.size();
	const char* p_sec_begin = NULL;
	const char* p_sec_end = NULL;
	const char* p_k_begin = NULL;
	const char* p_k_end = NULL;
	const char* p_v_begin = NULL;
	const char* p_v_end = NULL;
	string section;
	string k;
	string v;

	
	{
	cs = ini_parser_start;
	}

	
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 17:
	switch( (*p) ) {
		case -17: goto tr40;
		case 10: goto st18;
		case 13: goto st5;
		case 32: goto st4;
		case 35: goto tr16;
		case 59: goto tr16;
		case 91: goto tr17;
	}
	if ( 9 <= (*p) && (*p) <= 12 )
		goto st4;
	goto tr12;
tr12:
	{		
	p_k_begin = p;	
	k.clear();
}
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	switch( (*p) ) {
		case 10: goto st0;
		case 13: goto st0;
		case 61: goto tr2;
	}
	goto st1;
st0:
cs = 0;
	goto _out;
tr2:
	{		
	p_k_end = p;
	k.assign(p_k_begin, (int)(p_k_end - p_k_begin));
	str_strip(k);	
	if( k.empty() ){
		{p++; cs = 2; goto _out;}
	}
}
	goto st2;
tr7:
	{		
	p_k_end = p;
	k.assign(p_k_begin, (int)(p_k_end - p_k_begin));
	str_strip(k);	
	if( k.empty() ){
		{p++; cs = 2; goto _out;}
	}
}
	{		
	p_v_begin = p;
	if( k.empty() ){
		{p++; cs = 2; goto _out;}
	}	
	v.clear();
}
	goto st2;
tr39:
	{		
	p_k_end = p;
	k.assign(p_k_begin, (int)(p_k_end - p_k_begin));
	str_strip(k);	
	if( k.empty() ){
		{p++; cs = 2; goto _out;}
	}
}
	{		
	p_k_begin = p;	
	k.clear();
}
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	switch( (*p) ) {
		case 10: goto tr4;
		case 13: goto tr5;
		case 35: goto tr6;
		case 59: goto tr6;
		case 61: goto tr7;
	}
	goto tr3;
tr3:
	{		
	p_v_begin = p;
	if( k.empty() ){
		{p++; cs = 3; goto _out;}
	}	
	v.clear();
}
	goto st3;
tr6:
	{		
	p_v_begin = p;
	if( k.empty() ){
		{p++; cs = 3; goto _out;}
	}	
	v.clear();
}
	{		
	p_v_end = 	p;
	v.assign(p_v_begin, (int)(p_v_end - p_v_begin));
	str_strip(v);
	pairs.insert(std::make_pair(section + "#" + k, v));		
}
	goto st3;
tr11:
	{		
	p_v_end = 	p;
	v.assign(p_v_begin, (int)(p_v_end - p_v_begin));
	str_strip(v);
	pairs.insert(std::make_pair(section + "#" + k, v));		
}
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	switch( (*p) ) {
		case 10: goto tr9;
		case 13: goto tr10;
		case 35: goto tr11;
		case 59: goto tr11;
		case 61: goto tr2;
	}
	goto st3;
tr4:
	{		
	p_v_begin = p;
	if( k.empty() ){
		{p++; cs = 18; goto _out;}
	}	
	v.clear();
}
	{		
	p_v_end = 	p;
	v.assign(p_v_begin, (int)(p_v_end - p_v_begin));
	str_strip(v);
	pairs.insert(std::make_pair(section + "#" + k, v));		
}
	goto st18;
tr9:
	{		
	p_v_end = 	p;
	v.assign(p_v_begin, (int)(p_v_end - p_v_begin));
	str_strip(v);
	pairs.insert(std::make_pair(section + "#" + k, v));		
}
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	switch( (*p) ) {
		case 10: goto st18;
		case 13: goto st5;
		case 32: goto st4;
		case 35: goto tr16;
		case 59: goto tr16;
		case 91: goto tr17;
	}
	if ( 9 <= (*p) && (*p) <= 12 )
		goto st4;
	goto tr12;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	switch( (*p) ) {
		case 10: goto st18;
		case 13: goto st5;
		case 32: goto st4;
		case 35: goto tr16;
		case 59: goto tr16;
		case 91: goto tr17;
	}
	if ( 9 <= (*p) && (*p) <= 12 )
		goto st4;
	goto tr12;
tr5:
	{		
	p_v_begin = p;
	if( k.empty() ){
		{p++; cs = 5; goto _out;}
	}	
	v.clear();
}
	{		
	p_v_end = 	p;
	v.assign(p_v_begin, (int)(p_v_end - p_v_begin));
	str_strip(v);
	pairs.insert(std::make_pair(section + "#" + k, v));		
}
	goto st5;
tr10:
	{		
	p_v_end = 	p;
	v.assign(p_v_begin, (int)(p_v_end - p_v_begin));
	str_strip(v);
	pairs.insert(std::make_pair(section + "#" + k, v));		
}
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 10 )
		goto st18;
	goto st0;
tr16:
	{		
	p_k_begin = p;	
	k.clear();
}
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	switch( (*p) ) {
		case 10: goto st18;
		case 13: goto st5;
		case 61: goto tr2;
	}
	goto st6;
tr17:
	{		
	p_k_begin = p;	
	k.clear();
}
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	switch( (*p) ) {
		case 10: goto st0;
		case 13: goto st0;
		case 32: goto tr20;
		case 61: goto tr21;
	}
	if ( 9 <= (*p) && (*p) <= 12 )
		goto tr20;
	goto tr19;
tr19:
	{	
	p_sec_begin = p;
	section.clear();
}
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	switch( (*p) ) {
		case 10: goto st0;
		case 13: goto st0;
		case 61: goto tr23;
		case 93: goto tr24;
	}
	goto st8;
tr23:
	{		
	p_k_end = p;
	k.assign(p_k_begin, (int)(p_k_end - p_k_begin));
	str_strip(k);	
	if( k.empty() ){
		{p++; cs = 9; goto _out;}
	}
}
	goto st9;
tr27:
	{		
	p_k_end = p;
	k.assign(p_k_begin, (int)(p_k_end - p_k_begin));
	str_strip(k);	
	if( k.empty() ){
		{p++; cs = 9; goto _out;}
	}
}
	{		
	p_v_begin = p;
	if( k.empty() ){
		{p++; cs = 9; goto _out;}
	}	
	v.clear();
}
	goto st9;
tr21:
	{	
	p_sec_begin = p;
	section.clear();
}
	{		
	p_k_end = p;
	k.assign(p_k_begin, (int)(p_k_end - p_k_begin));
	str_strip(k);	
	if( k.empty() ){
		{p++; cs = 9; goto _out;}
	}
}
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	switch( (*p) ) {
		case 10: goto tr4;
		case 13: goto tr5;
		case 35: goto tr26;
		case 59: goto tr26;
		case 61: goto tr27;
		case 93: goto tr28;
	}
	goto tr25;
tr25:
	{		
	p_v_begin = p;
	if( k.empty() ){
		{p++; cs = 10; goto _out;}
	}	
	v.clear();
}
	goto st10;
tr26:
	{		
	p_v_begin = p;
	if( k.empty() ){
		{p++; cs = 10; goto _out;}
	}	
	v.clear();
}
	{		
	p_v_end = 	p;
	v.assign(p_v_begin, (int)(p_v_end - p_v_begin));
	str_strip(v);
	pairs.insert(std::make_pair(section + "#" + k, v));		
}
	goto st10;
tr30:
	{		
	p_v_end = 	p;
	v.assign(p_v_begin, (int)(p_v_end - p_v_begin));
	str_strip(v);
	pairs.insert(std::make_pair(section + "#" + k, v));		
}
	goto st10;
tr31:
	{	
	p_sec_end = p;	
	section.assign(p_sec_begin, (int)(p_sec_end - p_sec_begin));
	str_strip(section);	
	if( section.empty() ){
		{p++; cs = 10; goto _out;}
	}
}
	goto st10;
tr28:
	{	
	p_sec_end = p;	
	section.assign(p_sec_begin, (int)(p_sec_end - p_sec_begin));
	str_strip(section);	
	if( section.empty() ){
		{p++; cs = 10; goto _out;}
	}
}
	{		
	p_v_begin = p;
	if( k.empty() ){
		{p++; cs = 10; goto _out;}
	}	
	v.clear();
}
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	switch( (*p) ) {
		case 10: goto tr9;
		case 13: goto tr10;
		case 35: goto tr30;
		case 59: goto tr30;
		case 61: goto tr23;
		case 93: goto tr31;
	}
	goto st10;
tr24:
	{	
	p_sec_end = p;	
	section.assign(p_sec_begin, (int)(p_sec_end - p_sec_begin));
	str_strip(section);	
	if( section.empty() ){
		{p++; cs = 11; goto _out;}
	}
}
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	switch( (*p) ) {
		case 10: goto st18;
		case 13: goto st5;
		case 32: goto st11;
		case 35: goto st12;
		case 59: goto st12;
		case 61: goto tr23;
		case 93: goto tr24;
	}
	if ( 9 <= (*p) && (*p) <= 12 )
		goto st11;
	goto st8;
tr34:
	{	
	p_sec_end = p;	
	section.assign(p_sec_begin, (int)(p_sec_end - p_sec_begin));
	str_strip(section);	
	if( section.empty() ){
		{p++; cs = 12; goto _out;}
	}
}
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	switch( (*p) ) {
		case 10: goto st18;
		case 13: goto st5;
		case 61: goto tr23;
		case 93: goto tr34;
	}
	goto st12;
tr20:
	{	
	p_sec_begin = p;
	section.clear();
}
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	switch( (*p) ) {
		case 10: goto st0;
		case 13: goto st0;
		case 32: goto st13;
		case 61: goto tr23;
	}
	if ( 9 <= (*p) && (*p) <= 12 )
		goto st13;
	goto st8;
tr40:
	{		
	p_k_begin = p;	
	k.clear();
}
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	switch( (*p) ) {
		case -69: goto st15;
		case 10: goto st0;
		case 13: goto st0;
		case 61: goto tr2;
	}
	goto st1;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	switch( (*p) ) {
		case -65: goto st19;
		case 10: goto st0;
		case 13: goto st0;
		case 61: goto tr2;
	}
	goto st1;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	switch( (*p) ) {
		case 10: goto st18;
		case 13: goto st5;
		case 32: goto st16;
		case 35: goto tr16;
		case 59: goto tr16;
		case 61: goto tr39;
		case 91: goto tr17;
	}
	if ( 9 <= (*p) && (*p) <= 12 )
		goto st16;
	goto tr12;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
	switch( (*p) ) {
		case 10: goto st18;
		case 13: goto st5;
		case 32: goto st16;
		case 35: goto tr16;
		case 59: goto tr16;
		case 61: goto tr39;
		case 91: goto tr17;
	}
	if ( 9 <= (*p) && (*p) <= 12 )
		goto st16;
	goto tr12;
	}
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 

	_test_eof: {}
	_out: {}
	}

	if( cs < 17 )
	{
		pairs.clear();
		return false;
	}
	return true;
}