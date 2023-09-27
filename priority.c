struct pri {
  int pid;
  int prio;
  int btime;
  int ctime;
  int ttime;
  int wtime;
}
p[10], temp;
void main() {
    int n;
    float ttat, twt;
    p[0].ctime = 0;
    printf("Enter the number of process");
    scanf("%d", & n);
    for (int i = 1; i <= n; i++) {
      p[i].pid = i;
      printf("Enter the burst time of P%d : ", i);
      scanf("%d", & p[i].btime);
      printf("\n Enter the priority of P%d : ", i);
      scanf("%d", & p[i].prio);
    }
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (p[i].prio > p[j].prio) {
          temp = p[i];
          p[i] = p[j];
          p[j] = temp;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      p[i].ctime = p[i].btime + p[i - 1].ctime;
      p[i].ttime = p[i].ctime;
      ttat = ttat + p[i].ttime;
      p[i].wtime = p[i].ttime - p[i].btime;
      twt = twt + p[i].wtime;
    }
    printf("\n pid \t priority\t Btime \t ctime \t tat \t wating \t \n");
    for (int i = 1; i <= n; i++) {
      printf("\n %d \t %d \t %d \t %d \t %d \t %d \t \n
        ",p[i].pid,p[i].prio,p[i].btime,p[i].ctime,p[i].ttime,p[i].wtime);}
        printf("\n Average TurnAroundTime %f \n Average Waiting Time %f\n", ttat / n, twt / n);
      }
