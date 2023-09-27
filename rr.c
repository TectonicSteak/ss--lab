struct rr{
	int pid; int atime; int btime; int ctime;
	int tat; int wtime;
}p[10],temp;

void main(){
	int n,i=0,ts,rt[10],time=0,remain;
	float ttat=0,twt=0;
	printf("Enter the number of process");
	scanf("%d",&n);
	printf("Enter the time slice process");
	scanf("%d",&ts);
	for(int j=0;j<n;j++){
		p[j].pid=j;
		printf("Enter the arival time of P%d",j);
		scanf("%d",&p[j].atime);
		printf("Enter the burst time of P%d",j);
		scanf("%d",&p[j].btime);
		rt[j]=p[j].btime;
	}
	remain=n;
	while(remain!=0){
		if(rt[i]<=ts && rt[i]>0){
			time=time+rt[i];
			rt[i]=0;
			remain=remain-1;
			p[i].ctime=time;
			p[i].tat=time-p[i].atime;
			ttat=ttat+p[i].tat;
			p[i].wtime=p[i].tat-p[i].btime;
			twt=twt+p[i].wtime;	
		}else if(rt[i]>0){
			rt[i]=rt[i]-ts;
			time=time+ts;
		}
		if(i==n-1){
			i=0;
		}else if(p[i+1].atime<=time){
			i=i+1;
		}else{
			i=0;
		}
	}
	printf("\n pid \t atime \t Btime \t ctime \ttat \t wating \t \n");
	for(int i=0;i<n;i++){
		printf("\n %d \t %d \t %d \t %d \t %d \t%d \t \n",p[i].pid,p[i].atime,p[i].btime,p[i].ctime,p[i].tat,p[i].wtime);
	}
	printf("\n Average TurnAroundTime %f\n Average Waiting Time%f\n",ttat/n,twt/n);
}

