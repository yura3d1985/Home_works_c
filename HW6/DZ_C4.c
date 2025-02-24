#include <stdio.h>
#include <math.h>

int fun(int x)
{
	if (x>=-2 && x<2)
		return x*x;
	else
		if (x>=2)
			return (x*x)+(4*x)+5;
		else
			return 4;
}
int main(void)
{
	int x=1,y,max_y = 0;
    while (x!=0)
    {
        scanf("%d", &x);
        y = fun(x);
        if (y > max_y)
            max_y = y;
    }
    printf("%d", max_y);
    return 0;

}

