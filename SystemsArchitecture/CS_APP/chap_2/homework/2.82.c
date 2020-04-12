Lets assume random will generate int values in their range (INT_MIN - INT_MAX) 

int x = random()
int y = random()

unsigned ux = (unsigned) x;
unsigned uy = (unsigned) y;

Check the following expressions:

1. (x < y) == (-x > -y) => FALSE, Fails when x = INT_MIN

2. ((x+y) << 4) + y-x == 17*y+15*x , TRUE, arithmatic ops are Distributive, so equally overflows on both sides

3.  -x = ~x + 1;
	-y = ~y + 1;

	~x + ~y + 2 = -x - y;
	~x + ~y + 1 = -x - y -1; ---------------> eq 1

	-(x+y) = ~(x+y) + 1;
	~(x+y) = -(x+y) - 1; -------------------> eq 2

	-(x+y) = -x -y ? (Distributive property for negation)

	TRUE

4. /*
 * right
 *
 * (ux - uy) == -(unsigned) (y - x)
 *   =>
 * -(ux - uy) == (unsigned) (y - x)
 *   =>
 * (ux - uy) == (unsigned) (x - y)
 */

	TRUE

5. TRUE




