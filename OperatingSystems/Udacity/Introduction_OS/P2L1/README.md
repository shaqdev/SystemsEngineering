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
        - stack is dynamic allocation of process states with LIFO order. which makes it useful for making procedure calls where the return address of callee is stored on top of stack. Once the called function is executed the callee address space is restored.

V5 : CONTINUE...
        - The OS encapsulates process states in a virtual address space that is used by process. While the actual physical address is on DRAM which is absracted by virtual address.
        - Memory management hw + OS (page tables) are responsible to map virtual address space to physical address space.
        - page table has the acutal information of these mappings. while Memory mgt hw helps to allocate memory on physical address.

V6 : CONTINUE...
        - All the allocated virual address space may not find space in DRAM, so OS dynamically chooses mapping of virtual address space on physical memory (DRAM or disk)
        - The process address space is stored on physical memory using swapping between DRAM & DISK. This mapping information is stored in page tables.
        - OS should also store information related to validity to access to memory by process.(read/write)
