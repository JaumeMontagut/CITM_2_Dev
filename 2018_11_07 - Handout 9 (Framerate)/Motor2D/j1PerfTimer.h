#ifndef __j1PERFTIMER_H__
#define __j1PERFTIMER_H__

#include "p2Defs.h"

class j1PerfTimer
{
public:

	// Constructor
	j1PerfTimer();

	void Start();
	double ReadMs() const;
	uint64 ReadCycles() const;

private:
	uint64	start_cycles;
	static uint64 frequency;
};

#endif //__j1PERFTIMER_H__