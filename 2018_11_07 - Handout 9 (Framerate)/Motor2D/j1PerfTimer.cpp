// ----------------------------------------------------
// j1PerfTimer.cpp
// Slow timer with microsecond precision
// ----------------------------------------------------

#include "j1PerfTimer.h"
#include "SDL\include\SDL_timer.h"

uint64 j1PerfTimer::frequency = 0;

// ---------------------------------------------
j1PerfTimer::j1PerfTimer()
{
	// TODO 2: Fill Constructor, Start(),ReadMs() and ReadTicks() methods
	// they are simple, one line each!
	frequency = SDL_GetPerformanceFrequency();
	Start();
}

// ---------------------------------------------
void j1PerfTimer::Start()
{
	start_cycles = SDL_GetPerformanceCounter();
}

// ---------------------------------------------
double j1PerfTimer::ReadMs() const
{
	return (SDL_GetPerformanceCounter() - start_cycles) * 1000.0 / (double)frequency;
}

// ---------------------------------------------
uint64 j1PerfTimer::ReadCycles() const
{
	return SDL_GetPerformanceCounter() - start_cycles;
}


