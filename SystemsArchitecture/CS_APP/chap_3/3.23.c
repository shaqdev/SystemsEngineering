short dw_loop(short x){
    short y = x/9;
    short *p = &x;
    short n = 4*x;
    do {
        x += y;
        *p += 5;
        n -= 2;
    } while (n > 0);

    return x;
}