#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int valueSort(const void* p1, const void* p2){
  int n1 = ((int*) p1)[1];
  int n2 = ((int*) p2)[1];
  return n1-n2;
}

int keySort(const void* p1, const void* p2){
  int n1 = ((int*) p1)[0];
  int n2 = ((int*) p2)[0];
  return n1-n2;
}

int main(){
  int n;
  scanf("%d", &n);
  int* orders = malloc(sizeof(int) * n * 2);
  for(int i = 0; i < n; i++){
    scanf("%d %d", &orders[i * 2], &orders[i * 2 + 1]);
  }
  qsort(orders, n , sizeof(int) * 2, keySort);
 
  int sumWaitingTime = 0;
  int timeElapsed = 0;
  int i = 0;
  int orderWindowEnd = -1;
  int newElems = 0;
  while(i < n){
    if(timeElapsed < orders[i * 2]){
      timeElapsed = orders[i * 2];
    }
    if(orderWindowEnd < i){
      while((orderWindowEnd + 1 < n) && (orders[(orderWindowEnd + 1) * 2] == orders[i * 2])){
        orderWindowEnd++;
        newElems = 1;
      }
    }
    while((orderWindowEnd + 1 < n) && (orders[(orderWindowEnd + 1) * 2] <= timeElapsed)){
      orderWindowEnd++;
      newElems = 1;
    }
    if(newElems){
      qsort(orders + i * 2, orderWindowEnd - i + 1, sizeof(int) * 2, &valueSort);
    }
    newElems = 0;

    int toAdd = timeElapsed - orders[i * 2] + orders[i * 2 + 1];
    sumWaitingTime += toAdd;
    timeElapsed += orders[i * 2 + 1];
    i++;
  }
  printf("%d\n", sumWaitingTime / n);
  free(orders);
  return 0;

}