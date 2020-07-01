#include<stdio.h>
int main(){


  int r;
  printf("Enter value for r:", r);
  scanf("%d", &r);

  int c;
  printf("Enter value for c:", c);
  scanf("%d", &c);

  printf("c: %d\n", c);
  printf("r: %d\n", r);

  /* 2D array declaration*/
  int disp[r][c];
  /*Counter variables for the loop*/


  int i, j;
  for(i=0; i<r; i++) {
    for(j=0;j<c;j++) {
      printf("Enter value for disp[%d][%d]:", i, j);
      scanf("%d", &disp[i][j]);
    }
  }

  /*
  int r = 2, c = 4;
  int disp[2][4] = {
    {10, 11, 12, 13},
    {14, 15, 16, 17}
  };
  */
  //Displaying array elements
  printf("Two Dimensional array elements:\n");
  for(i=0; i<r; i++) {
    for(j=0;j<c;j++) {
      printf("%d ", disp[i][j]);
      if(j==c-1){
        printf("\n");
      }
    }
  }
  return 0;
}
