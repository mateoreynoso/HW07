#ifndef LANDING_Q_H_
#define LANDING_Q_H_

#include <iostream>
#include <string>
#include <queue>
#include "Plane.h"
#include "Random.h"

extern Random my_random;  // Enables us to access the global variable declared in Simulator.h

class LandingQueue
{
private:
	double arrival_rate;            // plane arrival rate per minute
	std::queue<Plane *> the_queue;  // queue of planes in the landing queue
	int total_wait;  // total accumulated wait time in the landing queue
	int num_served;  // number of planes served through the landing queue

public:
	LandingQueue() : total_wait(0), num_served(0) {}

	void set_arrival_rate(double arrival_rate) 
	{
		this->arrival_rate = arrival_rate;
	}

	int get_total_wait() 
	{
		return total_wait;
	}

	int get_num_served() 
	{
		return num_served;
	}

	void update(int clock) 
	{
		if (my_random.next_double() < arrival_rate)
		{
			Plane *p = new Plane(clock);
			the_queue.push(p);
		}

	}

	friend class ServiceQueue;
};

#endif