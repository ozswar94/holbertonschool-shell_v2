#include "shell.h"

/**
* handler_ctrlc - manage ctrl + c
* @c: void
*/
void handler_ctrlc(int c)
{
	(void)c;
	_putchar('\n');
	prompt();
}
