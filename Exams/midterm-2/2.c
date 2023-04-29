int fun2(long int *ap, long int *bp) {
    long int a = *ap;
    long int b = *bp;
    *ap = b;
    *bp = a;
    return a + b;
}

int main() {
    long int ap = 5;
    long int bp = 10;
    int result = fun2(&ap, &bp);
}