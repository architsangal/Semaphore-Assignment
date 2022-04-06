ABOUT
	This directory contains files that illustrate use of sysVipc semaphores.

FILE DESCRIPTIONS
	mysemops.h :: Declaration of a simplified interface to semaphore operations
	mysemops.c :: Implementation of a simplified interface to semaphores

	The other file use the above library to create simple examples
	1. sem_ctl.c  :: A sample implementation of semaphore operations. Usable as commandline standalone

	2. A producer consumer implementation with shared memory 
   	   
		safe_ops.c      :: safe implementations of put and get using semaphores.
        shm_producer.c  :: A producer that writes 
		shm_consumer.c  :: A consumer that reads
	    shm_ctl.c       :: Implementing a simple shared memory structure for the producer and consumer

RUNNING
	./shm_ctl -h on how to create a new shared memory structure for the producer/consumer example, initialize it and monitor it.
	./sem_ctl -h on how to create a new semaphore initialize it and monitor it.

	Use these for the producer/consumer problem as below
	// setup the shared memory
	./shm_ctl -n 8888; ./shm_ctl -i 8888
	// setup the three semaphores
	./sem_ctl -n 7777; ./sem_ctl -i 7777 1 # (mutex)
	./sem_ctl -n 7776; ./sem_ctl -i 7776 2 # (empty slots)
	./sem_ctl -n 7775; ./sem_ctl -i 7775 0 # (filled slots)

	./pr # (multiple executions of the producer)
	./cn # (multiple executions of the consumer)

NB: 
These are implemented 'quick and dirty'. 
In reality 
	* check the return values to make sure the operations worked as intended
	* else report perror() and exit(1).
	* Template        if (ret = do_sem_or_shm_func(args) < 0) {
	*                         perror("This func():");
	*			  exit(1);
	*		  }