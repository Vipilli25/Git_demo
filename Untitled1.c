

int max(int a,int b) 
{
	if(a>b)
	{
		return a;
	}
	return b;
}

void add(char a[size],char b[size],int c[size+1],int k,int i,int j)
{
	int x,y,l,sum,carry=0;
	for(l=0;l<k;l++)
	{
		c[l]=0;          
	}
	int m=k-1;
	i--;
	j--;
	while(m>=0)
	{
		x=a[i]-'0';                                    // converting character datatype into integer datatype
        y=b[j]-'0';
		if(i<0)                                       // if iterator becomes negative (possible only when 
		{
			x=0;
		}
		if(j<0)  
		{
			y=0;
		}
		sum=x+y+carry;
		if(sum>9)
		{
			c[m]=sum-10;
		}
		else
		{
			c[m]=sum;
		}
		
		carry=sum/10;
		i--;
		j--;
		m--;
	}
	c[m]=carry;
	
	for(i=0;i<k;i++)
	{
	   printf("%d",c[i]); 
	}
}

void sub(char a[size],char b[size],int c[size+1],int k,int i,int j)
{
	int x,y,l,borrow,res=0;
	for(l=0;l<k;l++)
	{
		c[l]=0;          
	}
	int m=k-1;
	i--;
	j--;
	while(m>0)
	{
		x=a[i]-'0';                                    // converting character datatype into integer datatype
        y=b[j]-'0';
		if(i<0)                                       // if iterator becomes negative (possible only when 
		{
			x=0;
		}
		if(j<0)  
		{
			y=0;
		}
		res=x-y; 
		c[m]=res-borrow;
        if(c[m]<0)
        {
       	  c[m]=10+c[m];
		  borrow=1;
		} 
		i--;
		j--;
		m--;
	}
	
	for(i=0;i<k;i++)
	{
	   printf("%d",c[i]); 
	}
	
}

void multiply(char a[size],char b[size],int d[2*size],int k,int i,int j)
{
	int res,carry1,x,y,l,p,q,count=0,carry2=0,r=k-1;
	
	for(l=0;l<k;l++)                                     // initializing all elements of array d to 0
	{
		d[l]=0;           // 5 d elemets
	}
	i--;
	j--;
	for(p=i;p>=0;p--)
	{
		x=a[p]-'0';
		r=k-1-count;
		for(q=j;q>=0;q--)
		{
			y=b[q]-'0';
			res=x*y + carry1;
			carry1=res/10;
			if(res>9)
			{
				res=res%10;
			}
			
			d[r]=d[r]+res+carry2;
	         
			if(d[k]>9)
			{
				carry2=d[r]/10;
				d[r]=d[r]%10;
			}
			r--;
		}

		d[r]=carry1+carry2;
		
		carry1=0;
		carry2=0;
		count++;
	}
	
	for(l=0;l<k;l++)
	{
	   printf("%d",d[l]); 
	}
}
void main()
{
	char a[size],b[size];
	int i=0,j=0,c[size + 1],d[2*size];
	printf("enter a number\n");
	gets(a);
	printf("enter a number\n");
	gets(b);
	while(a[i]!='\0')
	{
		i++;
	}
	while(b[j]!='\0')
	{
		j++;
	}
	int k = max(i,j) + 1;              // maximum possible size of result arrray
	printf("\naddition : \n");
	add(a,b,c,k,i,j);
	printf("\nsubtraction: \n");
	sub(a,b,c,k,i,j);
	 k =i+j;                           // maximum possible size of result arrray
	printf("\nmultiplication: \n");
	multiply(a,b,d,k,i,j);
	
}
