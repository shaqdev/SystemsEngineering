V1 : LESSION PREVIEW
        - A PROCESS is an ABSTRACTION provided by OS through system calls in linux standard library.
        - How a process is managed and governed by OS ? 
        - By definition, a PROCESS is an instance of program under execution. Also commonly referred as task/job.

V2 : VISUAL METAPHOR
        - A process is like "ORDER OF TOYS"
        - Author has compared three parameters 
            1. State of Execution : The state of the process is defined by Program Counter and stack
            2. Parts and Temporary holding area : data required by the process and memory required for storing register states.
            3. May require special hw : I/O devices, OS will manage which process should access availabe hw

V3 : PROCESS
        - An Application that stored in disk, flash or cloud is an static entity.
        - When we launch the application, OS is responsible to load the program/app in to main memory and put it under execution and we name it process. The process is an active entity.
        - Applications may or maynot have multiple instances under execution. 
        - A process can have different states defined by its state of execution.

V4 : WHAT DOES PROCESS LOOK LIKE ?
        - A Process encapsulated all the instructions and data in the form of process state (which includes instructions, static memory, dynamic memory ...)
        - OS encapsulated this process state in to address space(virual address) which has text, data, heap, stack.
        - state in text and data are static state available when process first loads.
        - heap is dynamic allocation of process states
        - stack is dynamic allocation of process states with LIFO order. which makes it useful for making procedure calls where the return address of caller is stored on top of stack. Once the called function is executed the caller address space is restored.

V5 : CONTINUE...
        - The OS encapsulates process states in a virtual address space that is used by process. While the actual physical address is on DRAM which is absracted by virtual address.
        - Memory management hw + OS (page tables) are responsible to map virtual address space to physical address space.
        - page table has the acutal information of these mappings. while Memory mgt hw helps to allocate memory on physical address.

V6 : CONTINUE...
        - All the allocated virual address space may not find space in DRAM, so OS dynamically chooses mapping of virtual address space on physical memory (DRAM or disk)
        - The process address space is stored on physical memory using swapping between DRAM & DISK. This mapping information is stored in page tables.
        - OS should also store information related to validity to access to memory by process.(read/write)

V7 : How does the OS know what a PROCESS is doing?
		- OS will access process states like PROGRAM COUNTER, STACK POINTER, REGISTERS... to manage process and track process status. 
		- OS stores all this information useful to manage process in PROCESS CONTROL BLOCK(PCB).

v8 : PROCESS CONTROL BLOCK(PCB):
		- OS creates PCB(Data Structure) when it creates a process and it stores all the information required to manage and track particular process.
		- Few important parameters that are stored inside PCB are Process state, Process number, Program counter, Registers, Memory limits, list of open files, priority, signal mask, CPU scheduling info, stack pointer...
		- But how often does OS updates this values as some of them are fixed and some of them change very often like PC, Fot those parameters that change quite often are probably related to CPU.
		- So, OS will gather, all information used by CPU while its running process, whenever the process is no longer running on CPU.

V9 : How is PCB used ?
		- OS will dynamically update the PCB according to process.
		- Ex: We have 2 process, p1 & p2 and their corresponding PCBs pcb1 & pcb2 
				-While p1 is running pcb1 is active and OS will update pcb1 with info related to memory 
				- when p1 is interrupted by p2, all the info of CPU is stored in pcb1 and pcb2 is restored in to cpu and p2 starts execution.
				- This saving and restoring CPU registers which indeed referred as swaping between process is called CONTEXT SWITCH.

v10 : WHAT IS A CONTEXT SWITCHING ?
		- Switching the CPU from context of one process to another is called CONTEXT SWITCHING.	It indeed switches the execution from the context of one process to the context of another process
		- CONTEXT SWITCHING is EXPENSIVE, It involves DIRECT COST & INDIRECT COST. 
		- DIRECT COST : No. of cycles needed to execute LOAD & STORE INSTRUCTIONS to and from memory.
		- INDIRECT COST : CACHE COLD, is a result of CACHE MISSES. To be specific, when a process is 					running its data is stored in cache, which is referred as HOT CACHE. When 					context switch to other process, the data inside cache is replaced by later 					process data. Now when the context is swithced back to earlier process, 					it leads cache misses resulting to load data from memory increasing 						latency and decreasing app performance.

V11 : PROCESS LIFECYCLE
		- State Machine of a single process,

								  interrupt
				 admitted	  |====<<<<<<<=====|	    exit
			NEW ==========> READY			RUNNING ====>>>>====TERMINATED
							| |====>>>>>>>=====|  |
							| schedular dispatch  |
				I/O	or		|  					  | I/0 or 
		   event completion |==<<<==WAITING==<<<==| event wait  					  |

		- The process state changes from READY TO RUNNING when CPU starts executing the process under READY STATE.

V12 : PROCESS CREATION
		- Any OS has privilaged process running as root process right after boot process. Any process that is created after logged in to the system will have its corresponding parent process. Though both parent and child process is running individually, this parent child relation helps to trace the process and manage accordingly.
		- Any new process created is created as child to some or other parent process. There are two mechanisms to create the new process:
			1. FORK - It copies the parent PCB to child PCB and both parent and child process starts executing the instruction next to fork, since both have same PC.
			2. EXEC - It replace child IMAGE with new PCB, it loads new program and starts from first instruction.

		- The actual creation of PROCESS involves two mechanisms, while FORK creates a new process with PARENT PCB and EXEC replace that child image with new program and starts executing from first instruction.

V13 : ROLE OF CPU SCHEDULER?
		- It is OS component that decides which process in READY state does CPU execute.
		- By definition, It is a OS component which determines which process in ready state processes should dispatch to the CPU and how long it should run on CPU.
		- CPU scheduling is carried in three steps:
			1. PREEMPT the current process and save its context
			2. Run SCHEDULING algorithm to choose which process from ready state processes should dispatch to the CPU.
			3. DISPATCH the process on to CPU and switch to its context.

		- The CPU scheduling should be efficient and take minimum cycles to avoid overhead and incrase latency and decrease performance.

V14 : How often do we RUN SCHEDULER?
		- It determines how long does process running on CPU.
		- More frequently running scheduler will waste cpu time running the scheduler. It will reduce the actual time CPU spent on useful work.
		- The time given to a single process to run on CPU is called TIMESLICE. It defines how long scheduler should run.
		- There are even some design principles to consider for scheduling,
			- What are the appropriate timeslice values?
			- Metrics to consider when scheduler is deciding which process it should run.

V15 : What about I/O ? 
		- While a process is running on CPU, and it raise I/O request, it will then moves it to WAITING STATE. When it receives I/O then process is moved in to READY state.
		- Furthermore, there are many other ways a RUNNING PROCESS can go in to ready state,
			1. I/O request
			2. TIMESLICE expired
			3. FORK a child
			4. INTERRUPT 