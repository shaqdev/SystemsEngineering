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
