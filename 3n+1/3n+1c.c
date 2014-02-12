	
    #include <stdio.h>
	void swap(int *i,int *j)
	{
	int t;
	t=*i;
	*i=*j;
	*j=t;
	}
    main ()
    {
            int n , i , j;
            while(scanf("%d %d",&i,&j)!=EOF)
            {
                    int tempi = i;
                    int tempj = j;
     
                    if(i>j)
                            swap(&i,&j);
                   
                    int maxCycle_Length = 0;
                    int cycle_Length;
     
                    while(i<=j)
                    {
                            n=i;
                            cycle_Length = 1;
     
                            while(n!=1){
                                    if(n%2!=0)
                                            n=(3*n)+1;
                                    else
                                            n = n/2;
                                    cycle_Length++;
                            }
     
                            if(cycle_Length > maxCycle_Length)
                                    maxCycle_Length = cycle_Length;
                            i++;
                    }
					printf("%d %d %d\n",tempi,tempj,maxCycle_Length);
                    
            }
           
           
    }
