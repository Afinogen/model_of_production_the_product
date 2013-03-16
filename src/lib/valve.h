/*
 * valve.h
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#ifndef SRC_LIB_VALVE_H_
#define SRC_LIB_VALVE_H_

#include <stdlib.h>
#include "channel.h"

class Valve
{
	public:
		Valve();
		Valve(Channel *channel);
		~Valve();
		void setChannel(Channel *channel);
		Channel *GetChannel() const;
		bool GetStateChannel() const;
	private:
		Channel *control_channel_;
};

#endif  // SRC_LIB_VALVE_H_
