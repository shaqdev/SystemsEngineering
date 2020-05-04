long instruction_encode()
{
	long x;
	x ^= x;
	x = 0;
	x >>= 61;

	return x;
}