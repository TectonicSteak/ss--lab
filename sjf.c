struct sjf {
  int pid;
  int atime;
  int btime;
  int ctime;
  int tat;
  int wtime;
}
p[10], temp;
void main() {
    int n;
    float ttat = 0, twt = 0;
    printf("Enter the number of process");
    scanf("%d", & n);
    for (int i = 1; i <= n; i++) {
      p[i].pid = i;
      p[i].atime = 0;
      printf("Enter the burst time of P%d", i);
      scanf("%d", & p[i].btime);
    }
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (p[i].btime > p[j].btime) {
          temp = p[i];
          p[i] = p[j];
          p[j] = temp;
        }
      }
    }
    p[0].wtime = 0;
    p[0].ctime = 0;
    for (int i = 1; i <= n; i++) {
      p[i].ctime = p[i].btime + p[i - 1].ctime;
      p[i].tat = p[i].ctime - p[i].atime;
      ttat = p[i].tat + ttat;
      p[i].wtime = p[i].tat - p[i].btime;
      twt = p[i].wtime + twt;
    }
    printf("\n pid \t atime \t Btime \t ctime \t tat \t wating \t \n");
    for (int i = 1; i <= n; i++) {
      printf("\n %d \t %d \t %d \t %d \t %d \t %d \t \n
        ",p[i].pid,p[i].atime,p[i].btime,p[i].ctime,p[i].tat,p[i].wtime); }
        printf("\n Average TurnAroundTime %f \n Average Waiting Time %f\n", ttat / n, twt / n);
      }
