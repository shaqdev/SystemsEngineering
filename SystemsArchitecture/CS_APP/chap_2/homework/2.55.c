// Determine byte ordering of any machine, using show_bytes method used in this chapter.
//1. determine hex value of given unsigned int

#include <stdio.h>
#include <stdbool.h>

bool show_bytes(unsigned u_value)
{
	unsigned char * ptr_ch = &u_value;
	bool little_endian = false;

	printf("Hex value of given unsigned number : %x\n",u_value);
	printf("\n");
	
	for (int i = 0; i < sizeof(u_value); ++i)
	{
		printf("Byte at %d position (%p) : %x\n", i, &ptr_ch[i], ptr_ch[i]);

		// determint littlte or big endian
		if (ptr_ch[i] == (unsigned char)((u_value & (0xFF << i*8)) >> i*8))
			little_endian = true;
		else
			little_endian = false;
	}
return little_endian;
}

int main()
{
	unsigned int u_value = 0xafab2344;
	bool little_endian =  show_bytes(u_value);
	if (!little_endian)
		printf("BIG ENDIAN MACHINE\n");
	else
		printf("LITTLE ENDIAN MACHINE\n");
return 0;
}