#include "Net.h"

void net::wait(float seconds)
{
	Sleep((int)(seconds * 1000.0f));
}
