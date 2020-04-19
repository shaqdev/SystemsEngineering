
void decode1_swap(long *xp, long *yp, long *zp)
{
    long temp = *xp;
    *xp = *yp;
    *yp = temp;

    temp = *xp;
    *xp = *zp;
    *zp = temp;
}

void decode1_direct(long *xp, long *yp, long *zp)
{
    long x = *xp;
    long y = *yp;
    long z = *zp;

    *yp = x;
    *zp = y;
    *xp = z;
}

int main()
{
  return 0;
}