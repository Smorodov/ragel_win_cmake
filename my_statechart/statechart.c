
#line 1 "statechart.rl"
#include <stdlib.h>
#include <stdio.h>

#include <string.h>


#line 7 "statechart.c"
static const char _StateChart_actions[] = {
	0, 1, 1, 1, 2, 1, 3, 1, 
	4, 2, 0, 2, 2, 0, 3, 2, 
	0, 4
};

static const char _StateChart_key_offsets[] = {
	0, 0, 3, 7, 10, 13, 17
};

static const char _StateChart_trans_keys[] = {
	49, 50, 51, 10, 49, 50, 51, 49, 
	50, 51, 49, 50, 51, 10, 49, 50, 
	51, 0
};

static const char _StateChart_single_lengths[] = {
	0, 3, 4, 3, 3, 4, 0
};

static const char _StateChart_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0
};

static const char _StateChart_index_offsets[] = {
	0, 0, 4, 9, 13, 17, 22
};

static const char _StateChart_indicies[] = {
	0, 2, 3, 1, 4, 5, 6, 7, 
	1, 8, 6, 7, 1, 5, 6, 7, 
	1, 4, 8, 6, 7, 1, 1, 0
};

static const char _StateChart_trans_targs[] = {
	2, 0, 3, 5, 6, 2, 3, 5, 
	4
};

static const char _StateChart_trans_actions[] = {
	9, 0, 12, 15, 0, 3, 5, 7, 
	3
};

static const char _StateChart_eof_actions[] = {
	0, 0, 0, 0, 0, 0, 1
};

static const int StateChart_start = 1;
static const int StateChart_first_final = 6;
static const int StateChart_error = 0;

static const int StateChart_en_main = 1;


#line 9 "statechart.rl"


int StateChart( char *str )
{
	char *p = str, *pe = str + strlen( str );
	const char *eof = pe; 
	int cs;

#line 68 "statechart.c"
	{
	cs = StateChart_start;
	}

#line 71 "statechart.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _StateChart_trans_keys + _StateChart_key_offsets[cs];
	_trans = _StateChart_index_offsets[cs];

	_klen = _StateChart_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _StateChart_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _StateChart_indicies[_trans];
	cs = _StateChart_trans_targs[_trans];

	if ( _StateChart_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _StateChart_actions + _StateChart_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 18 "statechart.rl"
	{
	 printf("begin\n");
	}
	break;
	case 2:
#line 27 "statechart.rl"
	{
	 printf("act 1\n");
	}
	break;
	case 3:
#line 31 "statechart.rl"
	{
	 printf("act 2\n");
	}
	break;
	case 4:
#line 35 "statechart.rl"
	{
	 printf("act 3\n");
	}
	break;
#line 164 "statechart.c"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	const char *__acts = _StateChart_actions + _StateChart_eof_actions[cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 1:
#line 22 "statechart.rl"
	{
	 printf("finish\n");
	}
	break;
#line 184 "statechart.c"
		}
	}
	}

	_out: {}
	}

#line 68 "statechart.rl"

	if ( cs == StateChart_error )
		return -1;
	if ( cs >= StateChart_first_final )
		return 1;
	return 0;
}

#define BUFSIZE 1024

int main()
{
printf("hi!\n");
	char buf[BUFSIZE];

	while ( fgets( buf, sizeof(buf), stdin ) != 0 ) {
		StateChart(buf);
	}

	return 0;
}
