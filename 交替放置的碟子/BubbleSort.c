#include<stdio.h>

int main(){
	
	int bubble_num,i ;
	void sortDisplay(int bubble_set[],int length);
	
	printf("请输入盘子总数:");	
	scanf("%d",&bubble_num);
	printf("\n");
	
	int bubble_set[bubble_num];
	int length = sizeof(bubble_set)/sizeof(bubble_set[0]);
	 
	for(i=0;i<=(length-2)/2;i++){
			bubble_set[2*i]=2;
			bubble_set[2*i+1]=1;
		}

	printf("盘子的初始顺序为：\n");	
	sortDisplay(bubble_set,length);

	printf("\n");
		
	for(i=0;i<length-1;i++){
			int j; 
			for(j=0;j<length-1-i;j++){
				if(bubble_set[j+1]<bubble_set[j]){
					int t=bubble_set[j];
					bubble_set[j]=bubble_set[j+1];
					bubble_set[j+1]=t;
				}
			}
		}
		
	printf("盘子排序后的顺序为：\n");
	sortDisplay(bubble_set,length);
		
	return 0;
}

void sortDisplay(int bubble_set[],int length){
	int i; 
	for(i=0;i<length;i++){
//			printf("%d ",bubble_set[i]); 
			if(bubble_set[i]==1){
				printf("白 ");
			}else{
				printf("黑 ");;
			}
		}
	printf("\n");
}
