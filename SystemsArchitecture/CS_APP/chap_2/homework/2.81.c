_ _ _ _ _ _ _ _

0 0 0 0 0 0 0 0 

1 1 1 1 1 1 1 1

j = 2, 1 1 1 1 1 1 0 0 

k = 3, 1 1 1 1 1 1 0 0

w - k - j = 3, 0 0 0 1 1 1 0 0

1. Take a w bit data type, x? w = sizeof(unsigned) << 3 ?
2. set k bits of the x to given a

A:
--
x = ~0;
x &= ~0 << k; 

B:
--
x = ~A(k) << j;
