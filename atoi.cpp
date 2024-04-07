
#line 1 "atoi.rl"
/*
 * Convert a string to an integer.
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#line 13 "atoi.cpp"
static const char _atoi_actions[] = {
	0, 1, 0, 2, 0, 1
};

static const char _atoi_key_offsets[] = {
	0, 0, 4, 6, 8, 11, 14, 17
};

static const char _atoi_trans_keys[] = {
	102, 105, 97, 122, 97, 122, 97, 122, 
	111, 97, 122, 114, 97, 122, 110, 97, 
	122, 116, 97, 122, 0
};

static const char _atoi_single_lengths[] = {
	0, 2, 0, 0, 1, 1, 1, 1
};

static const char _atoi_range_lengths[] = {
	0, 1, 1, 1, 1, 1, 1, 1
};

static const char _atoi_index_offsets[] = {
	0, 0, 4, 6, 8, 11, 14, 17
};

static const char _atoi_indicies[] = {
	2, 3, 0, 1, 0, 1, 0, 1, 
	4, 0, 1, 5, 0, 1, 6, 0, 
	1, 5, 0, 1, 0
};

static const char _atoi_trans_targs[] = {
	3, 0, 4, 6, 5, 2, 7
};

static const char _atoi_trans_actions[] = {
	1, 0, 1, 1, 1, 3, 1
};

static const int atoi_start = 1;
static const int atoi_first_final = 3;
static const int atoi_error = 0;

static const int atoi_en_main = 1;


#line 12 "atoi.rl"


long long atoi( char *str )
{
	char *p = str, *pe = str + strlen( str );
	int cs;
	long long val = 0;
	bool neg = false;

	
#line 72 "atoi.cpp"
	{
	cs = atoi_start;
	}

#line 77 "atoi.cpp"
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
	_keys = _atoi_trans_keys + _atoi_key_offsets[cs];
	_trans = _atoi_index_offsets[cs];

	_klen = _atoi_single_lengths[cs];
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

	_klen = _atoi_range_lengths[cs];
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
	_trans = _atoi_indicies[_trans];
	cs = _atoi_trans_targs[_trans];

	if ( _atoi_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _atoi_actions + _atoi_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 30 "atoi.rl"
	{ 
			std::cout << "test1" << std::endl;
		}
	break;
	case 1:
#line 33 "atoi.rl"
	{ 
			std::cout << "test2" << std::endl;
		}
	break;
#line 163 "atoi.cpp"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

#line 48 "atoi.rl"


	// if ( neg )
	// 	val = -1 * val;

	// if ( cs < atoi_first_final )
	// 	fprintf( stderr, "atoi: there was an error\n" );

    std::cout << "cs = " << cs << std::endl;

	return val;
};


#define BUFSIZE 1024

int main()
{
	char buf[BUFSIZE];
	while ( fgets( buf, sizeof(buf), stdin ) != 0 ) {
		long long value = atoi( buf );
		printf( "%lld\n", value );
	}
	return 0;
}
