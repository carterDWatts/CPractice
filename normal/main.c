#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int x;
	int y;
}point;

void move(point * p, int xMov, int yMov);

int main(){
	point p;
	p.x = 5;
	p.y = 5;

	move(&p,1,4);

	printf("(%d,%d)\n",p.x,p.y);
}

void move(point * p, int xMov, int yMov){
	(*p).x += xMov;
	(*p).y += yMov;

}
