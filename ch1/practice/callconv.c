int callee(int, int, int);

int caller(void)
{
    return callee(1, 2, 3) + 5;
}

