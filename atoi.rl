/*
 * Convert a string to an integer.
 */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

%%{
	machine atoi;
	write data;
}%%

long long atoi( char *str )
{
	char *p = str, *pe = str + strlen( str );
	int cs;
	long long val = 0;
	bool neg = false;

	%%{
		action see_neg {
			neg = true;
		}

		action add_digit { 
			val = val * 10 + (fc - '0');
		}

		action test1 { 
			std::cout << "test1" << std::endl;
		}
		action test2 { 
			std::cout << "test2" << std::endl;
		}
		#main := 
		# 	( '-'@see_neg | '+' )?
        #    ( digit @add_digit )+
        #     '\n';

        #main := 'hello' @test;

        main := /[a-z][a-z]*/@test1 - ( 'for' | 'int' )@test2;

		# Initialize and execute.
		write init;
		write exec;
	}%%

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
