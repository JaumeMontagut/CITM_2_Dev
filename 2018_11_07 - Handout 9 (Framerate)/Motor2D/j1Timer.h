#ifndef __j1TIMER_H__
#define __j1TIMER_H__

#include "p2Defs.h"

class j1Timer
{
public:

	// Constructor
	j1Timer();

	void Start();
	uint32 Read() const;
	float ReadSec() const;

private:
	uint32	start_time;
};

#endif //__j1TIMER_H__