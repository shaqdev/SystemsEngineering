PART 1 LESSON 2 : Introduction to Operating Systems
***************************************************
V1 : This lesson covers High level overview of OS and hardware abstraction.

V2: Visual Metophor of Toy Shop, Uses three basic comparisions
    1. Direct Operational Resouces to control use of available resources like cpu, memory and peripheral devices.
    2. Enforce fair, safe and clean working policies
    3. Mitigate complexity of difficult tasks using system calls

V3: What is an Operating System?
    It is the software that operates on underlying system directly and provide following services.
    1. Hides the hardware complexity from app developers & users. Indeed app developers no need to worry about the underlying hardware rather they can focus on how to use services provided by OS.
    2. It manages and control the availabe resouces for single or multiple applications running on the system.
    3. OS helps in isolation and protection of resouces while running multiple applications. 

V6: Abstraction vs Arbitration of OS
    Abstraction : Hiding hardware complexity and provide simplified services
    Arbitration : Managing the available resources to avoid dispute among applications.

V7 : Operating System Examples
     Desktop : MS Windows, Unix - Mac OS X (Berkley System Distribution, BSD unix kernel), Linux ...
     Embedded : Android, ios, symbian ...
     This whole series of video lectures focus on Linux OS. 

V8 : OS Elements
	 Primarily OS has three elements, 
	 1. Abstraction : Sys call interfaces provided by OS to app users/devs (eg - process, threads, file, socket, memory page...)
	 2. Mechanisms : Internally OS incorporates several mechanisms corresponding to the services provided as abstractions (eg - creating & scheduling process, open/write/allocate hw to process...)
	 3. Policies : OS integrated several policies that will determine how mechanisms are used to manage underlying hardware resources (eg - free space using least recently used algorithm, to control max no. of sockets a process can access)

V9 : OS Elements - Memory Management Example
	 An example to demonstrate functionality of OS Elements using Memory Management Module.
	 	Abstraction - Memory Page, its the virtual address space access from user space.
	 	Mechanism - How this memory page is mapped in to physical memory or disk
	 	policy - Rules/conditions it uses to map the page to and from physical memory and disk using 	algoritms like least recently used (LRU).

v10 : Design Principles
	  - Fundamental Prinicple is to separate mechanism from policies. So that Mechanisms are flexible to support several diffirent policies.
	  - Mechanism ensures functioning of system, while policy ensures efficient & optimized functioning of system.
	  - So policies are defined in such a way that they will optimize the OS for particular use.
	  (Ref : Mechanism is like core management while policy determine the overall type of management)

V11 : User/Kernel Protection Boundary
	  Any computer platform is configured with two modes : User Mode, Kernel Mode
	  User Mode : Unprivilaged mode running applications.
	  Kernel Mode : Privilaged mode which has direct access to hardware. 
	  Applications access underlying hardware by switching from user space to kernel space through OS. This switching can occur either through TRAP instructions or System Calls.
	  	- When a instruction requests direct access to hw, it raises TRAP which then verified by OS to allow or reject the request based on hw configuration for that instruction. 
	  	- Whereas SysCalls are synchronous and planned instuctions, where OS take control and executes the request in kernel mode and returns to user mode.
	  Signals - OS will generate signals to user space.

V12 : System Call Flowchart

			     ---------------------------------------------------------------------
	USER		 | User process => calls system call         Return from System Call |
    SPACE	     --------------------------------------------------------------------- 
			  								||			   /\
			  								||			   ||
			  							    \/             ||
	KERNEL		  						   -----------------------
	SPACE	  							   | Execute System Call |
			  							   -----------------------

      - Mode bit for user mode is '1'
      - Mode bit for Kernel mode is '0'
      - System call will set trap mode bit to '0'
      - Returning from system call will set return mode bit to '1' 

      - Executing system call involved switching context from user contex to kernel context, passing arguments for system call procedure, jumping in to location of the system procedure in kernal space.

      - During system call, The arguments can be passed directly from user process to OS or indirectly through pointers.		

      - System call may execute synchrounous or asynchronously with user process.

v13 : Crossing the User/Kernel Protection Boundary
		In short User/Kernel transitions are expensive
		- Hardware must support user/kernel transitions, In cases where app tries to access hw or performs illegal instructions that processor cannot understand, then hw will generate TRAPS. Its up to the OS & its policy to allow or reject TRAP.
		- It takes number of instructions for user/kernel transitions (eg - it takes ~50-100ns in 2Ghz linux machine) which is an overhead
		- System call may also lead to hw cache issues reducing the app performance. During sys call OS will replace app data in cache with system call data, so next time app has to fetch data from memory which is expensive than cache.

V14 : OS Services
		- There are multiple services provided by OS, to name few
			Process Management,
			File Management,
			Device Management,
			Memory Management,
			Storage Management,
			Security,
			...
		- These services are abstracted by system call interface to user process.

V16 : Monolithic OS
		- Its OS organization which packs all the services required by apps or demanded by hw in to single unit. 
		- Advantage : Since everything is packed in to single unit, OS can perform compile time optimizations.
		- Disadvantage : Large memory footprint which can reduce application performance. 

V17 : Modulur OS (eg - linux)
		- Its the modern OS organizaiton followed by Linux. It uses modular approach of integrating the services.
		- The OS provides basic services and interfaces for additional services. Based on the application, additional services can be integrated. These additional services are available as modules. (eg - OS needed for maintaining databases can add File System service optimized for database applications)
		- Advantage : Less memory footprint, easy maintainability, less resource(like memory) needed.
		- Disadvantage : Additional modular interface layer may impact apps performance, This modules are provided by 3 party vendors like IMG so can import bugs in to OS.

		- It is proved practically that modular approach is more beneficial than monolithic approach.

V18 : MicroKernel
		- This kind of OS Kernels are mainly used for embedded platforms which needs less and specific services.
		- It provided very primitive services and their abstractions like IPC, Address Space (page system), threads to name few. While many OS related services will be running in user space.
		- Advantage : less memory footprint, easy verifiability means its exactly behaves like its expected to do. These benefits makes it ideal OS organization for real time embedded applications.
		- Disadvantage : These kind of kernels are highly customized for spcific hw config that makes it difficult to portable across different platforms. So having multiple platform specific kernels will impose software complexity to support them all. Also it has more user/kernle transitions which is expensive in terms of performance.

V19 : Linux & Mac OS Architecture
		LINUX :		      User
						  |
						  LIBRARY INTERFACE (standard utility programs like shell, terminal, editors...) -> USPACE
						  |
						  SYSTEM CALL INTERFACE (standard libraries like glibc) -> USPACE
						  |
						  Linux Kernel (services like file mgt, device mgt, mem mgt...) -> KERNEL SPACE
						  |
						  HW (cpu, disks, memory, terminals...)

		- Linux kernel is organized in a moduler way, so its easy to configure individual service components.

		MAC OS X : 		  GUI (Aqua)
						  |
						  APP ENVIRONMENT & SERVICES (Java, Cocoa, Quicktime, BSD)
						  |
						  MICRO KERNEL + BSD (Mach)
						  |
						  IO KIT + KERNEL EXTENSIONS
						  |
						  HW

		- BSD provides UNIX API to applications and other services.
		- Somewhat similar to modular approach for providing support for extension, It has separate layer where kernel extension can be added.



