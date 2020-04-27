THREADS & CONCURRENCY
---------------------

V1 : Lesson Preview
		- What are Threads ?
		- How Threads differ from Process ?
		- Data Structures and Mechanisms needed to implement Threads ? 

		- Reference Paper - "An Introduction to Programming with Threads" by Birrell

V2 : Visual Metaphor
		- Comparing THREAD with Worker working on toy order.
			1. Active Entity working on unit of process - THREAD
			2. Must work simultaneously with other threads - CONCURRANCY
			3. Must have good coordination - SYNCHRONIZATION

v3 : PROCESS vs THREAD
		- PROCESS has single execution context where THREADS enable process to have multiple execution context. Which means THREADS will have shared virual address but seperate REGISTERS & STACK.
		- PCB in single threaded process is different from PCB from multi threaded process. In multi-threaded process, shared information will be common while individual information will be separated.

V4: Why are THREADS USEFUL ?
		- PARALLELIZATION - Single process is divided in to multiple threads executing the same code but different subset of input (ex : matrix). It will speed up the overall execution.
		- SPECIALIZATION - Single process is divided in to multiple threads that are specialized for multiple tasks. Which means each thread handles separate task corresponding to separate portion of code. In this case threads executing same code and data multiple times can result HOT CACHE which reduce latency and improve performance.
		- Multi threaded will share virtual address space with different execution contexts that makes app to fit in DRAM with less SWAP with disks. Also INTER THREAD COMMUNICATION IS CHEAPER than IPC.

V5 : ARE THREADS USEFUL ON SINGLE CPU ?
		- When a process is RUNNING on a core and it requests I/O, then core will be in idle state till TIMESLICE. If the time the core in idle state in more than 2 x THREAD CONTEXT SWITCH, then having two threads is useful, so second thread will use that T_idle - 2xT_thread_context_switch. 
		- PROCESS CONTEXT SWITCH IS EXPENSIVE THAN THREAD CONTEXT SWITCH due to two main reasons,
			1. Since process have different address space, during context switch MMU should be ALTERED to point to new address space.
			2. It also needs to flush CACHE.
		- DOES THREAD CONTEXT SWITCH CAN LEAD COLD CACHE ? 
			NO, infact it may lead to HOT CACHE because data needed by second thread will provided by first thread in cache.

v6 : MULTI-THREADING is useful to both APP & OS ?
		- OS kernel also uses multi-threaded programming for spawning threads working on behalf of apps and threads that run OS -level services like daemons or device drivers. MORE IN COMING LECTURES.

V7 : What do we need to support threads?
		- Data Structure for threads, to identify threads and their resource usage.
		- Mechanism to create and manage threads
		- Mechanism to safely coordinate between threads while running concurrently.
		- Issues associated with concurrent execution:
			- DATA RACE PROBLEM, since concurrent threads have same virual to physical mappings, multiple threads can access data at same time which leads to corruption.
		The below two mechanisms are SYNCHRONIZATION MECHANISMS :
		---------------------------------------------------------
		- To avoid DATA RACE PROBLEM, threads must have mechanism to execute in mutually exclusive manner. which means the operation that can lead DRP should allow only one thread to perform that operation at a time. Primitive that used for mutual exclusion is MUTEX.
		- Mutual exclusion is also helpful while one thread is waitng for other thread execution to complete and specify what it wants from it. The primitive used for this mechanism is called CONDITION VARIABLE.

V8 : THREAD & THREAD CREATION:
		- We need Thread DS that has information related to thread (like ID, PC, SP, REGISTERS, STACK, ATTRIBUTES used by OS to manage thread)
		- Creating a thread as proposed by BIRREL, FORK that returns thread handler of type thread data structure.
		- BIRREL proposes one more mechanism called JOIN that will make parent thread to wait till child thread terminates and returns the FIRST PROCEDURE VALUE. If child thread terminates even before join call, it returs immediately (WHAT ABOUT RETURN VALUE, WILL IT BE LIVE OR EVAPORATED ? I feel EVAPORATED).

V9 : THREAD CREATION:
		- t = fork(procedure, arguments)
		- join(t)

V10 : LINKED LIST updated with THREADS ?
		- While two threads trying to update list concurrently, since two threads will be interleaved on the cores randomly, only last executed thread will be updated while first updated will be overridden.

V11 : MUTUAL EXCLUSION ?
		- MUTUAL EXCLUSION is a mechanism to provide lock around some section of the code. This lock is referred as MUTEX and section is referred as CRITICAL SECTION.
		- The other threads when reached already locked CRITICAL SECTION should wait till the owner of the critical section unlocks it.
		- As soon as the thread that aquired MUTEX unlocks it, any thread already waiting one or just that requested lock can take control of the MUTEX. 
		- More modern OS uses lock and unlock as two separate API's unlike single LOCK CLAUSE with {} by BIRREL.

V12 : USING PREVIOUS LINKED LIST AND APPY MUTEX FOR SAFE INSERTION

V13 : PRODUCER/CONSUMER EXAMPLE ?
		- PRODUCER has 10 threads which contineously insert to the LIST one after other
		- CONSUMER will check if LIST is FULL, PRINTS & CLEARS the LIST if FULL.
		- In the CONSUMER procedure it contineously POOLS to check the condition if LIST is FULL. This is useful operation to POOL and eating core to do this senseless operation. What more meaning ful is to raise INTERRUPT TO WAKE the CONSUMER by PRODUCER when the LIST IS FULL.

V14 : CONDITIONAL VARIABLE ?
		- In the previous PRODUCER/CONSUMER example, the POOLING operation of CONSUMER can be rectified using WAIT CLAUSE, WAIT helps to block the execution of CONSUMER and WAITS till PRODUCER THREADS met certain CONDITION. Indeed PRODUCER THREAD, raise SIGNAL when it meets the coniditon requested by CONSUMER. 

V15 : CONDITION VARIABLE API:
		- CONDITION VARIABLE DATA TYPE (must have reference to MUTEX and waiting threads)
	 	- WAIT (MUTEX, CONDITION VARIABLE)
		- SIGNAL (CONDITION VARIABLE) , It notify one thread waiting on condition and releases MUTEX.
		- BROADCAST (CONDITION VARIABLE), It notify all threads waiting on condition varaibl but release mutex for one thread at a time.	

V15 : READERS/WRITERS PROBLEM ?
		- There is one shared file and can be any number of readers at a given instant but only one or zero writers. Also there cannot be read and write at the same time.
		- Using Mutex lock mechanism is not very useful, cause it limits reader threads to one at any given time.
		- So we use a PROXY VARIABLE for MUTEX to achieve required function. This PROXY VARIABLE can have three states which reflect the state of shared file,
			1. > 0, any no. represents the no. of readers
			2. = 0, No writer No Reader
			3. = -1, Writer

		- Any thread modifying PROXY VARIABLE requires mutex lock.

V16 :  READER/WRITER EXAMPLE ?
		- We need, int resource_counter; Mutex counter_mutex; Condition read_phase, write_phase;
		- READER :
					- Lock counter_mutex
					- check if counter_mutex = -1, True : Wait for read_phase signal , Else : increment resource_counter.
					- Unlock counter_mutex

					// READ THE FILE

					- Lock counter_mutex
					- decrement resource_counter
					- check if resource_counter = 0, if True : Signal write_phase, Else : continue
					- Unlock

		- WRITER :
					- Lock resource_counter
					- check if resource_counter != 0, True : Wait for write_signal; else : set resource_counter= -1.
					- unlock resource_counter

					// WRITE THE FILE

					- Lock the resource_counter
					- Set the resource counter = 0
					- Signal write_phase, Broad_Cast Read_Phase
					- Unlock.

V17 : CRITICAL SECTION STRUCTURE ?