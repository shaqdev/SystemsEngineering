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
		- In WRITER/READER example, we have seen how PRIMITIVE LOCK is used to create CUSTOMIZED LOCK mechanism around our real CRITICAL SECTION.
		- In READER THREAD, the LOCK before READ is referred as ENTER CRITICAL SECTION which is our CUSTOMIZED LOCK for READER THREAD. The LOCK after READ is referred as EXIT CRITICAL SECTION which is our CUSTOMIZED UNLOCK for READER THREAD. It's similar to WRITER THREAD as well.

V18 : CRITICAL SECTION STRUCTURE WITH PROXY VARIABLE ?
		- Using PROXY VARIABLE & MUTEX, we can build CUSTOMIZED LOCK MECHANISM that satisfy READER/WRITER REQUIREMENT.
			//ENTER CRITICAL SECTION (primitive mutex structure)
			READ/WRITE SHARED FILE
			//EXIT CRITICAL SECTION (primitive mutex structure)

V19 : COMMON MISTAKES ? 
		- Must use right mutex for right operations in all threads.
		- Use lock/unlock constructs the right way.
		- Ensure single mutex to access single resource.
		- Ensure we are signalling correct condition variable.
		- Ensure correct use of SIGNAL & BROADCAST.
		- SIGNALLING OR BROADCAST doesn't guarentee order of thread wakeups

V20 : SPURIOUS WAKE-UPS ? => UNNECESSARY WAKEUPS
		- As we saw earlier, using SIGNALLING for BROADCAST is will have performance penality but using BROADCAST for SIGNALLING is acceptable.
		- SPURIOUS WAKEUPS doesn't effect CORRECTNESS but can impact PERFORMANCE.
		- In Scenario of WRITER THEAD, after issuing BROADCAST it takes few more cycles to unlock mutex, meanwhile if any wait threads in CONDITION VARIABLE QUEUE will WAKESUP and realizes the MUTEX IS LOCKED and again WAITS on MUTEX QUEUE. It indeed, just bringing threads waiting from in one queue to another queue, which takes CPU cycles and reduce CPU performance. This is referred to SPURIOUS WAKEUPS.
		- It can be avoided by BROADCASTING after UNLOCKING. But this way of doing SIGNALLING is not always possible.

V21 : DEADLOCKS INTRODUCTION ?
		- It is simply two threads waiting on one another and no one goes to finish execution ever.

V22 : DEADLOCK WITH EXAMPLE & FEW STRATEGIES TO AVOID DEADLOCKS ?
		- We have TWO thread that follows, ----->LOCK_A----->LOCK_B----->FOO1(A,B)	
		- In this scenario, if one thread acquires LOCK_A and other thread acquires LOCK_B earlier and after few cycles earlier thread tries to LOCK_B & later thread tries to LOCK_A, then both the threads will have cyclic dependency and obviously fell in to DEADLOCK SITUATION.
		- To avoid such CYCLIC DEPENDENCY PROBLEM, we have few strategies like
			1. FINE-GRAINED LOCKING - In this mechanism, we unlock any already locked mutex before locking next mutex, it seems to work well but not in our case, cause FOO(A,B) needs both the RESOURCES.
			2. SINGLE COMPOUND MUTEX - We can have one customized MUTEX at the beginning of each thread that locks all the required mutex at the beginning, it has overhead on performance.
		   *3. LOCK ORDER - CONSIDERED BEST IN OUR CASE, Having a lock order is refinement of 2, but only aquiring locks when needed.

V23 : WHAT TO DO WITH DEADLOCKS ? 
		- Three ways we can handle DEADLOCKS
			1. PREVENTION, By beforehand analyzing the every acquired lock condition and ensuring it wont cause DEADLOCKS, is very EXPENSIVE.
			2. DETECTION & RECOVERY, It seems to be reliable but practically not possible in real time systems when inputs are coming from external source, It have ROLLBACK OVERHEAD
			3. OSTRICH ALGORITHM, Use V22 defined strategies and DO NOTHING just like an OSTRICH. Even having optimized strategy like LOCK ORDER is not always avoid DEADLOCK SITUATIONS, in that case system will reboot.
		- In PERFORMACE CRITICAL SYSTEMS, since REBOOT is not a better choice, even if it's EXPENSIVE always good to use 1 or 2 according to the situation.

V24 : KERNEL VS USER LEVEL THREADS ?
		- The KERNEL level threads are either threads associated with USER LEVEL threads or threads that performing OS sevices like demon services.
		- There are THREE MODELS that define how kernel level threads are associated with user level threads and are discussed below lectures
		- Before looking in to these models, let's understand why there must be an association between KERNEL & USER THREADS ?????
				==> OS Schduler only schedules KERNEL LEVEL THREADS. For any USER LEVEL THREAD to access hw resources, they must be associated with KERNEL LEVEL THREAD.

V25 : MULTI-THREADING MODEL ?
		- There are maily three models that defines how kernel level threads and user level threads are assosicated with each other.
			1. ONE-TO-ONE MAPPING : Every created thread at USER LEVEL has its own KERNEL LEVEL THREAD. + => OS manages all the synchronization and scheduling mechanisms. - ==> Expensive due to USER/KERNEL TRANSITIONS and sync and sched is limited by OS policies.
			2. MANY-TO-ONE MAPPING : It has thread management library at USER LEVEL so that it has full support unlike one to one. - ==> when one USER LEVEL thread blocks, OS blocks the whole PROCESS.
			3. MANY-TO-MANY MAPPINGS : Few USER threads are mapped on to single KERNEL THREAD and few USER threads that require contineous execution are mapped on to single KERNEL THREAD. - ==> It must have some co-ordination between USER AND KERNEL LEVEL THREAD MANAGERS. 

V26 : SCOPE OF MULTI-THREADING ?
		- In general, there exists two levels of THREAD MANAGEMENT SYSTEM
			1. PROCESS SCOPE
			2. SYSTEM SCOPE
		- 1. Process Scope : It is managed by USER LEVEL THREAD MANAGEMENT LIBRARY. It can be different instances of same library or different processes have different libraries. What ever each instance has scope limited to single process. It is responsible to schedule and synchronize across threads in corresponding process.
		- 2. System Scope : In this, all the threads are visible to OS scheduler and managed by restricted policies of OS thread management system. 
		- How CPU Core is shared across all user level threads are depend upon what MULTI-THREADING MODEL that process uses.

V27 : MULTI-THREADING PATTERNS ?
		- DESIGN PATTERNS for structuring APPLICATION in to MULTI-THREADING 
		- Example with TOY SHOP ORDER, and different tasks involved are,
			1. Accepting the order
			2. Parsing the order
			3. Cut wooden parts
			4. Paint & add decorations
			5. Assemble the parts
			6. Ship the order
		- Since we cannot have all 6 threads and we should design the whole TOY SHOP ORDER mechanism in effective way.
		- There are 3 MAIN MULTI-THREADING PATTERNS
			1. BOSS/WORKERS PATTERN
			2. PIPELINE PATTERN
			3. LAYERED PATTERN

V28 : BOSS/WORKER PATTERN ?
		- Single BOSS and multiple Workers example for performing TOY SHOP ORDER, where task 1 from above list is executed by BOSS and 2-6 are executed by WORKERS. Worker threads should perform any of the tasks from 2-6.
		- THROUGHPUT of SYSTEM : The number of process system executed per unit time.
		- The THROUGHPUT of the system is majorly limited by BOSS THREAD's performance
		- How the work is shared by BOSS TO WORKERS ?
			1. HANDSHAKE MECHANISM : Where BOSS keep track for every thread and assigns new task to available thread. + is No need of Synch between WORKER THREADS. - is less throughput of the system as BOSS THREAD is doing lot work.
			2. READY QUEUE : It can implement ready queue with PRODUCER-CONSUMER MECHANISM, so that BOSS will just insert new task in to queue and WORKER thread in wait queue automatically signalled, + is more throughput and - is need synch between WORKER THREADS, also need sync b/w BOSS & WORKER THREADS.

V29 : CONTINUE... HOW MANY WORKERS ?
		- With limited number of WORKER threads, if the work need to performed is more. Then the BOSS thread should wait for WORKER thread to be available. In this case throughput of the system will reduce. However, having more number of WORKER THREDS will add more overhead before hand having more work.
		- So there are two techniques which allow BOSS thread to increase number of WORKER THREADS according to demand.
			1. ON DEMAND, dynamically add WORKER THREADS - Sometimes it may have some overhead of loading new thread
			2. WORKER-POOL - Having Pool of workers with size of pool decided statically or dynamically is efficient accroding to the type of work they do.
		- Overall, BOSS - WORKER PATTERN with PRODUCER-CONSUMER shared Queue works WELL but since boss doesn't have any track of workers. The advantage of using right thread for right task will be lost.	 

V30 : CONTINUE...BOSS/WORKER VARIANTS ?
		-  To achieve LOCALITY, (assigning right work to right thread) BOSS THREAD rather than just broadcasting the tasks, it can wake the specialized threads for corresponding tasks.
		- This will enable specialized threads to make use of their CACHE and achieve high perormance. 
		- But in this case LOAD BALANCING is complicated cause in broadcasting we can simply maintain WORKERS POOL but here it's difficult to choose how many threads should assign for each specific task.

V31 : PIPELINE PATTERN ?
		- Whole process is divided in to SEQUENCE OF STAGES
		- Each stage == subtask
		- Each stage == thread pool, It will try to maintain balance between all stages.
		- Must establish buffer based communication b/w each stage.

		+ is Specialized threads leads to LOCALITY
		- is LOAD BALANCIGN & SYNCHRONIZATION, maintaining right thread pool is very important as it may lead to unbalanced stages which increases overhead of waiting earlier threads for later threads to finish execution.

V32 : LAYERED PATTERN ?
		- All the subtasks are grouped in to layers and layers stacked together.
		- Specialized threads for each subtask are assigned to a layer.
		- The execution will traverse end-to-end bi-direction through all the layers.

		+ is LOCALITY and able to choose right pool of threds easily
		- is Not applicable to all applications and synchronization is difficult as the sync must exists in two ways between each layers.
		