#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	double x;
	double y;
}point;

void move_point_0(point * p, double xMov, double yMov);
void move_point_1(point * p, double xMov, double yMov);
void move_point_2(point p, double xMove, double yMov);

int main(){

	point a = {.x = 1, .y = 1};
	move_point_0(&a, 1, 1);
	printf("a: (%f,%f)\n", a.x, a.y);

	point b = {.x = 1, .y = 1};
	move_point_1(&b, 1, 1);
	printf("b: (%f,%f)\n", b.x, b.y);

	point c = {.x = 1, .y = 1};
	move_point_1(&c, 1, 1);
	printf("c: (%f,%f)\n", c.x, c.y);

	printf("%p ", &c);
	printf("%f ", c);

}

void move_point_0(point * p, double xMov, double yMov){

	(*p).x += xMov;
	(*p).y += yMov;
}

void move_point_1(point * p, double xMov, double yMov){

	p->x += xMov;
	p->y += yMov;
}

void move_point_2(point p, double xMov, double yMov){

	p.x += xMov;
	p.y += yMov;
}
