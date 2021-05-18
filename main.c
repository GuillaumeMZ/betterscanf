#include "betterscanf.h"

int main(void)
{
    char buffer[50];
    int result;

    int firstscan_1;
    result = betterscanf("%d", buffer, 50, &firstscan_1);
    printf("%d value read: %d\n", result, firstscan_1);

    char secondscan_1[50];
    result = betterscanf("%s", buffer, 50, secondscan_1);
    printf("%d values read: %s\n", result, secondscan_1);

    int thirdscan_1;
    float thirdscan_2;
    char thirdscan_3;

    result = betterscanf("%d %f %c", buffer, 50, &thirdscan_1, &thirdscan_2, &thirdscan_3);
    printf("%d values read: %d %f %c\n", result, thirdscan_1, thirdscan_2, thirdscan_3);

    return 0;
}