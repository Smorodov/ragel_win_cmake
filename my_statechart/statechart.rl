#include <stdlib.h>
#include <stdio.h>

#include <string.h>

%%{
	machine StateChart;
	write data;
}%%

int StateChart( char *str )
{
	char *p = str, *pe = str + strlen( str );
	const char *eof = pe; 
	int cs;
%%{
	action begin
	{
	 printf("begin\n");
	}
	action finish
	{
	 printf("finish\n");
	}

	action act1 
	{
	 printf("act 1\n");
	}
	action act2
	{
	 printf("act 2\n");
	}
	action act3 
	{
	 printf("act 3\n");
	}

		main :=(
		start:
		(
		 ''-> state1
		),
		state1: (			
			'3' @act3 -> state3 |
			'2' @act2 -> state2 |
			'1' @act1 -> state1			
			'\n' -> final			
			),

		state2: (
			'1' @act1 -> state1 |
			'2' @act2 -> state2 |
			'3' @act3 -> state3
			'\n' -> final			
		),

	state3: (       '1' @act1 -> state1 |
			'2' @act2 -> state2 |
			'3' @act3 -> state3 |
			'\n' -> final
		)

	) >begin %finish;
	# Initialize and execute.
	write init;
	write exec;
}%%
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
