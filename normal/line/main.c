#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
	double x;
	double y;
}point;

typedef struct{
	point a;
	point b;
}line;

void move_point(point * p, double xMov, double yMov);
double line_length(line * l);

int main(){

	line l;
	l.a.x = 0;
	l.a.y = 0;
	l.b.x = 1;
	l.b.y = 1;

	printf("Line length: %f	\n", line_length(&l));

	move_point( &l.a, 12, 1234);
	move_point( &l.b, 11, 1234);

	printf("(%f,%f)\n", l.a.x, l.a.y);
	printf("(%f,%f)\n", l.b.x, l.b.y);
	printf("Line length: %f\n", line_length(&l));

}

void move_point(point * p, double xMov, double yMov){

	(*p).x += xMov;
	(*p).y += yMov;
}

double line_length(line * l){

	return pow( pow( (*l).b.x-(*l).a.x, 2) + pow( (*l).b.y-(*l).a.y, 2), .5);
}

double line_bisector_x(line * l){

}

double line_bisector_y(line * l){

}
