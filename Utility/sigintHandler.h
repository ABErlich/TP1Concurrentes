#ifndef SIGINT_HANDLER_H_
#define SIGINT_HANDLER_H_

#include <signal.h>
#include <assert.h>
#include <iostream>

#include "eventHandler.h"

class SigintHandler : public EventHandler {

	private:
		sig_atomic_t gracefulQuit;

	public:

		SigintHandler () : gracefulQuit(0) {
		}

		~SigintHandler () {
		}

		virtual int handleSignal ( int signum ) {
			assert ( signum == SIGINT );
			this->gracefulQuit = 1;
			return 0;
		}

		sig_atomic_t getGracefulQuit () const {
			return this->gracefulQuit;
		}

};

#endif /* SIGINT_HANDLER_H_ */
