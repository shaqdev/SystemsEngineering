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



