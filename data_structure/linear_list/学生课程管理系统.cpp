#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
#define INCREMENT 10
#define  OK 1
#define  ERROR 0
#define  TRUE 1
#define  FALSE 0
#define  INFEASIBLE -1
#define  OVERFLOW -2
typedef int Status;
typedef int ElemType; 
typedef struct {
	Status course_sum;//已存入的课程分数数目 
	int  course[6];  
}Score; //定义结构体用于存储课程 
typedef struct {
	char name[20];
	Score score;  
}student,*stulist; //存储每个学生的姓名，分数； 
Status add(stulist &L,Status stu_num,Status course_num,Status score)//添加学生某门课程的分数 
{
    if(!L) return ERROR;
    else{
    		if(course_num>=7||(L[stu_num].score.course_sum)==6)
			{
			    printf("ERROR!\n");
				return ERROR;
			   }   
			   else {
			   	L[stu_num-1].score.course[course_num-1]=score;
    	     	L[stu_num].score.course_sum++;
			   }
	}
}
Status Delete(stulist &L,Status stu_num,Status course_num)//删除学生某门课程分数 
{
	if(!L)  return ERROR;
	else if(L[stu_num-1].score.course_sum==0) 
	{
		   return ERROR;
	}
	else {
	      L[stu_num-1].score.course[course_num-1]=-1;
		  L[stu_num].score.course_sum--;
	}
}
Status modify(stulist &L,Status stu_num,Status course_num,Status score)//修改分数 
{
	if(!L) return ERROR;
	else{
		 L[stu_num-1].score.course[course_num-1]=score;
	}
}
Status init(stulist &L,Status STU_NUM)//初始化各个学生分数 
{
	int i,j;
	 L=(student*)malloc(MAXSIZE*sizeof(student));
     for(i=0;i<STU_NUM;i++)
     {
     	L[i].score.course_sum=0;
     	printf("输入姓名和成绩：");
     	scanf("%s",L[i].name); 
     	for(j=0;j<6;j++)
     	{
     		scanf("%d",&L[i].score.course[j]);
     	    if(L[i].score.course[j]!=-1)
     	    {
     	    	L[i].score.course_sum++;
			 }
		 }
	 }
}
Status print(stulist &L,Status STU_NUM)//打印每个学生分数 
{
	int i,j;
	for(i=0;i<STU_NUM;i++)
	{
		printf("%s:",L[i].name);
		for(j=0;j<6;j++)
		{
			printf("%d ",L[i].score.course[j]);
		}
		printf("\n");
	 } 
}
int main()
{
	int STU_NUM,choice;
	stulist L;
	printf("		学生课程管理系统		\n");
	printf("		1、增加成绩				\n");
	printf("		2、删除成绩				\n");
	printf("		3、修改成绩				\n");
	printf("		4、查看成绩				\n");
	printf("输入学生人数:\n");
	scanf("%d",&STU_NUM);
	printf("录入成绩，按顺序课程依次为语文，数学，英语，物理，化学，生物，无成绩以-1代替\n");
	init(L,STU_NUM);
	printf("选择操作(0表示退出):");
	fflush(stdin);
	scanf("%d",&choice);
	while(1)
	{
		switch(choice)
		{
			case 0:exit(1); 
			case 1:{
				int stu_num,course_num;
				int score;
				printf("输入学生序号，课程号，分数\n");
				scanf("%d %d %d",&stu_num,&course_num,&score);
				add(L,stu_num,course_num,score);
				break;
			}
			case 2:{
			    int stu_num,course_num;
			    printf("输入学生序号，课程号\n");
				scanf("%d %d",&stu_num,&course_num);
				Delete(L,stu_num,course_num);
				break;
			}
			case 3:{
				int stu_num,course_num;
				int score;
				printf("输入学生序号，课程号，分数\n");
				scanf("%d %d %d",&stu_num,&course_num,&score);
				modify(L,stu_num,course_num,score);
				break;
			}
			case 4:{
				print(L,STU_NUM);
				break;
			} 
			
		}
		printf("选择操作(0表示退出):");
		scanf("%d",&choice);

	 } 
}

