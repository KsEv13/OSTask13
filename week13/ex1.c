#include <stdio.h>

int main(void) {
  FILE *input = fopen("input.txt", "r");
  FILE *output = fopen("output.txt", "w");
  int nr=0;
  int np=0;
  int C[np][nr];
  int E[nr];
  int A[nr];
  int R[np][nr];
  printf("Number of resouces:");
  scanf("%d", &nr);
  for (int i=0; i<nr; i++){
   fscanf(input,"%d", &E[i]);
  }
  for (int i=0; i<nr; i++){
    fscanf(input,"%d", &A[i]);
  }
  printf("Number of processes:");
  scanf("%d", &np);
  for (int i=0; i<np; i++){
    for (int j=0; j<nr; j++){
      fscanf(input,"%d", &C[i][j]);
    }
  }
  for (int i=0; i<np; i++){
    for (int j=0; j<nr; j++){
      fscanf(input,"%d", &R[i][j]);
    }
  }
  int process[np];
  for (int i=0; i<np; i++){
    process[i]=1;
  }
  for (int i=0; i<np; i++){
    for (int k=0; k<np; k++){
        if (process[k]==1){
            int ok=0;
            for (int j=0; j<nr;j++){
                if (R[k][j]<A[j]+1){
                    ok++;
                }
            }
            if (ok==nr){
                for (int j=0; j<nr;j++){
                    A[j]+=C[k][j];
                }
                process[k]=0;
            }
        }
     }
  }
  int deadlock=0;
  for (int i=0; i<np; i++){
      if(process[i]==1){
          deadlock=1;
          fprintf(output,"Process %d is in a deadlock\n",i+1);
      }
  }
  if(deadlock==0){
     fprintf(output,"No deadlock");
  }
  fclose(input);
  fclose(output);
  return 0;
}

