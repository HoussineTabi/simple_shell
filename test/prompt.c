#include "shell.h"

/**
 * prompt - is a funcntion disply the prompt to write command
 */

void prompt(void)
{
	write(1, "#cisfun$ ", sizeof("#cisfun$ "));
}
