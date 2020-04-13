#include <stdio.h>
#include <assert.h>

unsigned f2u(float x) {
  return *(unsigned*)&x;
}

int float_le(float x, float y)
{
	unsigned ux = f2u(x);
	unsigned uy = f2u(y);

	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;

	// Shaq sol
	return ((ux << 1 == 0 && uy << 1 == 0) ||
			(sx == sy && ((sx == 1 && ux >= uy) || (sx == 0 && ux <= uy))) || 
			(sx > sy));

	//Ref Sol
//	return (ux << 1 == 0 && uy << 1 == 0) || 	   /* both zeros */
//    		(sx && !sy) ||                         /* x < 0, y >= 0 or x <= 0, y > 0 */
//    		(!sx && !sy && ux <= uy) ||            /* x > 0, y >= 0 or x >= 0, y > 0 */
//    		(sx && sy && ux >= uy);                /* x < 0, y <= 0 or x <= 0, y < 0 */
}

int main()
{
	int float_le_ret = float_le(-4.0, -0.0);
	printf("float_le_ret : %d\n",float_le_ret);

	assert(float_le(-0.0, +0.0));
	assert(float_le(+0.0, -0.0));
	assert(float_le(0, 3));
	assert(float_le(-4, -0));
	assert(float_le(-4, 4));
	return 0;
}