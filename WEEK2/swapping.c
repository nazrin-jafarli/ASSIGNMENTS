#include <stdio.h>

int main()

{
	int x;
	int y;

	printf("value of x:");
	scanf("%d",&x);

	printf("\nvalue of y:");
	scanf("%d",&y);

	int temp=x;
	x=y;
	y=temp;

	printf("\nafter swapping\nx=%d\ny=%d",x,y);
	return 0;

}
