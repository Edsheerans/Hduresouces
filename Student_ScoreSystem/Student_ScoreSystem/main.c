#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
struct Student
{
      char name[20];
      char sex[10];
      int num;
      float CN;    //语文
      float MT;    //数学
      float EN;    //英语
      float SC;    //科学

}stu[40];
int n=0;
//将学生信息读出
void getDate()
{
      FILE *p;
      int size = 1;
      p = fopen("stu_data.txt","r");
      while(~fscanf(p,"%s%s%d%f%f%f%f",stu[size].name,stu[size].sex,&stu[size].num,&stu[size].CN,&stu[size].MT,&stu[size].EN,&stu[size].SC))
         {
               size++;
               n++;
         }
      fclose(p);
}
//保存修改
void stu_save()
{
	int size;
	FILE *p = fopen("stu_data.txt","w");
	for(size=1;size<=n;size++)
      {
            fprintf(p,"%s  %s  %d  %.2f  %.2f  %.2f  %.2f\n",stu[size].name,stu[size].sex,stu[size].num,stu[size].CN,stu[size].MT,stu[size].EN,stu[size].SC);
      }
      fclose(p);
}
//得到正确的指令
int getNum()
{
	int num;
	char b[50];
	scanf("%s",b);
	getchar();
	if ((strlen(b)==1)&&b[0]>='0'&&b[0]<='9')
		num=b[0]-48;
		else
		 {
		 	printf("请输入正确的指令！\n");
                  num=getNum();
            }
     return num;
}
//退出系统
void exitSy()
{
	 printf("\n系统将于  3  秒后关闭...");
	 	Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b \b%d  秒后关闭...",2);
		Sleep(1000);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b \b%d  秒后关闭...",1);
		Sleep(1000);
	exit(0);

 }
 //录入每个同学的学号、姓名、性别和各科的考试成绩；
void stu_input()
{
      system("CLS");
      int i,j,num;
      char k;
      char sub[][4]={"CN:","MT:","EN:","SC:"};
      float grades[4];
      printf("\n当前有%d个学生的信息:\n",n);
      printf("\n你想录入几位同学的信息:");
      scanf("%d",&num);
      getchar();
      for(i=1;i<=num;i++)
      {
            printf("\n请输入第%d位学生的姓名+性别(male(男)/fema(女))+学号\n\n",i);
            scanf("%s%*c%s%*c%d%*c",stu[n+i].name,stu[n+i].sex,&stu[n+i].num);//%*c,*表示跳过一个字符
            printf("\n请输入第%d位学生的成绩：\n\n",i);
            for(j=0;j<4;j++)
            {
                  printf("%s",sub[j]);
                  scanf("%f",&grades[j]);
            }
            getchar();

            if(num>=1)
            {
                  printf("\n你确定输入正确吗？(确定请输入Y，返回请输入N):");
                  scanf("%c",&k);
                  getchar();
            }
                  if(k=='Y')
                  {
                        stu[n+i].CN=grades[0];
                        stu[n+i].MT=grades[1];
                        stu[n+i].EN=grades[2];
                        stu[n+i].SC=grades[3];
                  }
                  if(k=='N')
                  {
                        system("CLS");
                        stu_input();
                  }
            if(n+num==40)
            {
                  printf("学生人数已满，不能再添加！");
                  printf("请按任意键返回主菜单...\n");
                  getchar();
            }
            if(num!=0)
            {
                  printf("\n您录入的学生信息为：\n\n");
                  printf("\n姓名    性别     学号        语文(CN)    数学(MT)    英文(EN)    科学(SC)\n");
                  for(i=1;i<=num;i++)
                  {
                        printf("%-5s  %5s   %6d   %8.2f  %10.2f  %10.2f  %10.2f ",
                        stu[n+i].name,stu[n+i].sex,stu[n+i].num,stu[n+i].CN,stu[n+i].MT,stu[n+i].EN,stu[n+i].SC);
                        printf("\n");
                  }
            }
      }
      n+=num;
      stu_save();
      printf("\n请按任意键返回主菜单...\n");
      getchar();
}
//按照学号检索修改成绩
void stu_modify()
{
      system("CLS");
      struct Student example;
      int i,num;
      char k;
      if (n==0)
      {
	  	printf("当前共有0位学生,无法进行修改 \n");
	  	printf("\n请按任意键回到主菜单... \n");
	  	getchar();
		return;
	 }
      printf("\n请输入想要修改成绩学生的学号：");
      scanf("%d",&example.num);
      int flag=0;
      for(i=1;i<=n;i++)
      {
            if(example.num==stu[i].num)
            {
                  flag=1;
                  printf("\n现在系统有以下几科成绩可以进行修改：\n");
                  printf("\n1.语文成绩\n");
                  printf("\n2.数学成绩\n");
                  printf("\n3.英语成绩\n");
                  printf("\n4.科学成绩\n");
                  printf("\n请输入想要修改的成绩序号:");
                  scanf("%d",&num);
                  switch(num)
                  {
                        case 1:printf("\n请输入要修改的语文成绩：");
                               scanf("%f",&example.CN);getchar();
                                printf("\n您确定将  %.2f  修改为  %.2f  吗？(确定请输入Y，返回请输入N)：",stu[i].CN,example.CN);
                                scanf("%c",&k);
                                getchar();
                                if(k=='Y')
                                {
                                    stu[i].CN=example.CN;
                                }
                                if(k=='N')
                                {
                                    system("CLS");
                                    stu_modify();
                                }
                                break;
                        case 2:printf("\n请输入要修改的数学成绩：");
                               scanf("%f",&example.MT);
                                printf("\n您确定将  %f  修改为  %f  吗？(确定请输入Y，返回请输入N)：",stu[i].MT,example.MT);
                                scanf("%c",&k);
                                getchar();
                                if(k=='Y')
                                {
                                    stu[i].CN=example.CN;
                                }
                                if(k=='N')
                                {
                                    system("CLS");
                                    stu_modify();
                                }
                                break;
                        case 3:printf("\n请输入要修改的英语成绩：");
                               scanf("%f",&example.MT);
                                printf("\n您确定将  %f  修改为  %f  吗？(确定请输入Y，返回请输入N)：",stu[i].EN,example.EN);
                                scanf("%c",&k);
                                getchar();
                                if(k=='Y')
                                {
                                    stu[i].EN=example.EN;
                                }
                                if(k=='N')
                                {
                                    system("CLS");
                                    stu_modify();
                                }
                                break;
                        case 4:printf("\n请输入要修改的科学成绩：");
                               scanf("%f",&example.MT);
                                printf("\n您确定将  %f  修改为  %f  吗？(确定请输入Y，返回请输入N)：",stu[i].SC,example.SC);
                                scanf("%c",&k);
                                getchar();
                                if(k=='Y')
                                {
                                    stu[i].SC=example.SC;
                                }
                                if(k=='N')
                                {
                                    system("CLS");
                                    stu_modify();
                                }
                                break;


                  }
                  printf("\n您所修改后的学生信息为：\n\n");
                  printf("姓名    性别     学号        语文(CN)    数学(MT)    英文(EN)    科学(SC)\n");
                  printf("%-5s  %5s   %6d   %8.2f  %10.2f  %10.2f  %10.2f ",
                  stu[i].name,stu[i].sex,stu[i].num,stu[i].CN,stu[i].MT,stu[i].EN,stu[i].SC);
                  printf("\n");
            }
      }
      if(!flag)

      {
            printf("没有查询到该学生，请按任意键返回主菜单... \n");
            getchar();

      }
      stu_save();
      printf("\n请按任意键返回主菜单...\n");
      getchar();
}
//按照姓名查询
void name_search()
{
      int i,k=-2,a;
      int j;
      struct Student temp;
      float sum[40],ave[40];

      for(i=1;i<=n;i++)
      {
            sum[i]=stu[i].CN+stu[i].MT+stu[i].EN+stu[i].SC;
            ave[i]=sum[i]/4.0;
      }
      for(i=1;i<=n;i++)
            for(j=1;j<=n-1;j++)
            {
                  if (sum[j]<sum[j+1])
                  {
                        temp=stu[j];
                        stu[j]=stu[j+1];
                        stu[j+1]=temp;
                        a=sum[j];
                        sum[j]=sum[j+1];
                        sum[j+1]=a;
                  }
            }

      char s[10];
      printf("\n请输入要查询的学生姓名：");
       for(i=0;i<10;i++)
		s[i]='\0';
      gets(s);
      for (i=1;i<=n;i++)
      {
            if (strcmp(s,stu[i].name)==0)
            {
                  k=i;
                  printf("\n该学生的成绩信息如下所示:\n");
                  printf("\n姓名    性别     学号        语文(CN)    数学(MT)    英文(EN)    科学(SC)    总分       平均分         排名\n");
                  printf("%-5s  %5s   %6d   %8.2f  %10.2f  %10.2f  %10.2f  %10.2f  %10.2f %10d",
                  stu[i].name,stu[i].sex,stu[i].num,stu[i].CN,stu[i].MT,stu[i].EN,stu[i].SC,sum[i],ave[i],i);
                  printf("\n");
                      break;
            }
      }
      if (k==-2)
      {
         printf("查无此人，请重新输入：\n");
      }
}
//按照学号查询
void num_search()
{
      int i,j,a,k=-2;
      struct Student temp;
      float sum[40],ave[40];
      for(i=1;i<=n;i++)
      {
            sum[i]=stu[i].CN+stu[i].MT+stu[i].EN+stu[i].SC;
            ave[i]=sum[i]/4.0;
      }
      for(i=1;i<=n;i++)
            for(j=1;j<=n-1;j++)
            {
                  if (sum[j]<sum[j+1])
                  {
                        temp=stu[j];
                        stu[j]=stu[j+1];
                        stu[j+1]=temp;
                        a=sum[j];
                        sum[j]=sum[j+1];
                        sum[j+1]=a;
                  }
            }

      int id;
      printf("\n请输入要查询的学生学号：");
      scanf("%d",&id);
      getchar();
      for (i=1;i<=n;i++)
      {
            if(id==stu[i].num)
            {
                  k=i;
                  printf("\n该学生的成绩信息如下所示:\n");
                  printf("\n姓名    性别     学号        语文(CN)    数学(MT)    英文(EN)    科学(SC)    总分       平均分         排名\n");
                  printf("%-5s  %5s   %6d   %8.2f  %10.2f  %10.2f  %10.2f  %10.2f  %10.2f %10d",
                  stu[i].name,stu[i].sex,stu[i].num,stu[i].CN,stu[i].MT,stu[i].EN,stu[i].SC,sum[i],ave[i],i);
                  printf("\n");
                  break;
            }
      }
      if (k==-2)
      {
         printf("查无此人，请重新输入：\n");
      }
}
//查询
//按姓名查询学生的各科成绩、总分、平均分及在班级的排名；
//按学号查询学生的各科成绩、总分、平均分及在班级的排名；
int stu_seek()
{
      system("CLS");
      if (n==0)
      {
            printf("当前共有0个学生数据，无法进行查找操作！\n");
            printf("请按任意键返回主菜单...\n");
            getchar();
            return;
      }
      int num;
      int k=-2;
      printf("\n请选择按照以下哪种方式查询：\n");
      printf("\n1.按照姓名查询学生的各科成绩，总分，平均分及在班级的排名：\n");
      printf("\n2.按照学号查询写上的各科成绩，总分，平均分以及在班级的排名：\n");
      printf("\n请输入菜单旁边对应的数字进入相应功能：");
      num=getNum();
      switch(num)
      {
            case 1:name_search();break;
            case 2:num_search();break;
      }
      printf("\n请按任意键继续下一步或者返回主菜单...");
      getchar();
      return k;
}
//删除学生信息
void stu_delete()
{
      int i,j,k=-2;
      char s[10];
      char m;
	struct Student example;
	if (n==0)
      {
	  	printf("当前共有0位学生,无法进行删除操作 \n");
	  	printf("请按任意键回到主菜单... \n");
	  	getchar();
		return;
      }
      k=stu_seek();
      printf("\n请您确认删除该学生的信息吗？(确定请输入Y，返回请输入N)：");
      scanf("%c",&m);getchar();
      if(m=='Y')
      {

            for(i=k+1;i<=n;i++)
            {
                  stu[i-1]=stu[i];
            }
            printf("\n您已经成功删除该学生的信息！\n");
      }
      if(m=='N')
      {
            system("CLS");
            stu_seek();
      }
      n--;
      stu_save();
      printf("\n现在所有学生的成绩信息为：\n");
      printf("\n姓名    性别     学号        语文(CN)    数学(MT)    英文(EN)    科学(SC)\n");
      for(i=1;i<=n;i++)
      {
            printf("%-5s  %5s   %6d   %8.2f  %10.2f  %10.2f  %10.2f",
            stu[i].name,stu[i].sex,stu[i].num,stu[i].CN,stu[i].MT,stu[i].EN,stu[i].SC);
            printf("\n");
      }
      printf("\n请按任意键返回主菜单...\n");
      getchar();

}
//显示每个学生的姓名、学号、性别、各门课程的考试成绩、总分、平均分及在班级内的排名；
void stu_show()
{
      system("cls");
      int i,j,a;
      struct Student temp;
      float sum[40],ave[40];
      for(i=1;i<=n;i++)
      {
            sum[i]=stu[i].CN+stu[i].MT+stu[i].EN+stu[i].SC;
            ave[i]=sum[i]/4.0;
      }
      for(i=1;i<=n;i++)
            for(j=1;j<=n-1;j++)
            {
                  if (sum[j]<sum[j+1])
                  {
                        temp=stu[j];
                        stu[j]=stu[j+1];
                        stu[j+1]=temp;
                        a=sum[j];
                        sum[j]=sum[j+1];
                        sum[j+1]=a;
                  }
            }

      printf("\n每位学生的姓名，学号，性别，各门课程的考试成绩，总分，平均分，按照总分从高到低输出打印：\n");
      printf("姓名    性别     学号        语文(CN)    数学(MT)    英文(EN)    科学(SC)    总分       平均分         排名\n");
      for(i=1;i<=n;i++)
      {
            printf("%-5s  %5s   %6d   %8.2f  %10.2f  %10.2f  %10.2f  %10.2f  %10.2f %10d",
            stu[i].name,stu[i].sex,stu[i].num,stu[i].CN,stu[i].MT,stu[i].EN,stu[i].SC,sum[i],ave[i],i);
            printf("\n");
      }
      printf("请按任意键返回主菜单...\n");
      getchar();

}
//按照总分排序
void sort1()
{
      int i,j,a;
      struct Student temp;
      float sum[40];
      for(i=1;i<=n;i++)
      {
            sum[i]=stu[i].CN+stu[i].MT+stu[i].EN+stu[i].SC;
      }
      for(i=1;i<=n;i++)
            for(j=1;j<=n-1;j++)
            {
                  if (sum[j]<sum[j+1])
                  {
                        temp=stu[j];
                        stu[j]=stu[j+1];
                        stu[j+1]=temp;
                        a=sum[j];
                        sum[j]=sum[j+1];
                        sum[j+1]=a;
                  }
            }
      printf("\n按照总分从高到底低排序的结果如下：\n");
      printf("\n姓名    性别     学号        语文(CN)    数学(MT)    英文(EN)    科学(SC)    总分\n");
      for(i=1;i<=n;i++)
      {
            printf("%-5s  %5s   %6d   %8.2f  %10.2f  %10.2f  %10.2f  %10.2f",
            stu[i].name,stu[i].sex,stu[i].num,stu[i].CN,stu[i].MT,stu[i].EN,stu[i].SC,sum[i]);
            printf("\n");
      }
      printf("\n请按任意键返回主菜单...\n");
      getchar();
}
//按学号排出成绩表
void sort2()
{
      struct Student example;
      int i,j;
      for(i=1;i<=n;i++)
      for(j=1;j<=n-1;j++)
      {
            if (stu[j].num>stu[j+1].num)
            {
                   example=stu[j];
                   stu[j]=stu[j+1];
			 stu[j+1]=example;
            }
      }
      printf("\n按照学号从低到高排序的结果如下：\n");
      printf("\n姓名    性别     学号        语文(CN)    数学(MT)    英文(EN)    科学(SC)\n");
      for(i=1;i<=n;i++)
      {
            printf("%-5s  %5s   %6d   %8.2f  %10.2f  %10.2f  %10.2f",
            stu[i].name,stu[i].sex,stu[i].num,stu[i].CN,stu[i].MT,stu[i].EN,stu[i].SC);
            printf("\n");
      }
      printf("\n请按任意键返回主菜单...\n");
      getchar();
}
//按姓名的字典顺序排出成绩表
void sort3()
{
      struct Student example;
	int i,j;
      for(i=1;i<=n-1;i++)
      for(j=1;j<=n-1;j++)
      {
            if (strcmp(stu[j].name,stu[j+1].name)==1)
            {
                  example=stu[j];
                  stu[j]=stu[j+1];
                  stu[j+1]=example;
            }
      }
      printf("\n按照姓名的字典顺序排序的结果如下：\n");
      printf("\n姓名    性别     学号        语文(CN)    数学(MT)    英文(EN)    科学(SC)\n");
      for(i=1;i<=n;i++)
      {
            printf("%-5s  %5s   %6d   %8.2f  %10.2f  %10.2f  %10.2f",
            stu[i].name,stu[i].sex,stu[i].num,stu[i].CN,stu[i].MT,stu[i].EN,stu[i].SC);
            printf("\n");
      }
      printf("\n请按任意键返回主菜单...\n");
      getchar();

}
//按每个学生的总分进行排序sort1()；按学号排出成绩表sort2()；按姓名的字典顺序排出成绩表sort3()；
void stu_sort()
{
      system("CLS");
      int num;
      printf("\n1.按总分进行排序\n");
      printf("\n2.按学号进行排序\n");
      printf("\n3.按姓名的字典顺序排出成绩表\n");
      printf("\n请输入菜单旁边对应的数字进入相应功能：");
      num=getNum();
      switch(num)
      {
            case 1:sort1();break;
            case 2:sort2();break;
            case 3:sort3();break;
      }
}
//计算每门课程的总分和平均分
void statistics1()
{
  	float ave[4],sum[4];
  	int i,j;
  	for (i=1;i<=n;i++)
  	{
  		sum[0]+=stu[i].CN;
  		sum[1]+=stu[i].MT;
  		sum[2]+=stu[i].EN;
  		sum[3]+=stu[i].SC;
    }
    for (i=0;i<4;i++)
      ave[i]=sum[i]/n;
            printf("\n每门课程的总分和平均分为：\n\n");
            printf("              |  语文(CN)  |  数学(MT)  | 英语(EN)  | 科学(SC)             \n") ;
            printf("       总分： |  %7.2f   |  %7.2f   |  %7.2f  | %7.2f\n",sum[0],sum[1],sum[2],sum[3]) ;
            printf("      平均分: |  %7.2f   |  %7.2f   |  %7.2f  | %7.2f\n",ave[0],ave[1],ave[2],ave[3]) ;
      printf("\n请按任意键返回主菜单...\n");
      getchar();
}
//计算每个学生所有课程的总分和平均分
void statistics2()
{
    stu_show();

}
//对每门课程按优、良、中、及格、不及格统计人数及所占的百分比
void statistics3()
{
      system("cls");
      int i,j;
	int sum[4][5]={0};

	for (i=1;i<=n;i++)
    	{
                  if (stu[i].CN>=90&&stu[i].CN<=100) sum[0][0]++;
			if (stu[i].CN>=80&&stu[i].CN<=89)  sum[0][1]++;
			if (stu[i].CN>=70&&stu[i].CN<=79) sum[0][2]++;
			if (stu[i].CN>=60&&stu[i].CN<=69) sum[0][3]++;
			if (stu[i].CN >=0&&stu[i].CN<=59) sum[0][4]++;

			if (stu[i].MT>=90&&stu[i].MT<=100) sum[1][0]++;
			if (stu[i].MT>=80&&stu[i].MT<=89)  sum[1][1]++;
			if (stu[i].MT>=70&&stu[i].MT<=79)  sum[1][2]++;
			if (stu[i].MT>=60&&stu[i].MT<=69)  sum[1][3]++;
			if (stu[i].MT >=0&&stu[i].MT<=59)  sum[1][4]++;

			if (stu[i].EN>=90&&stu[i].EN<=100) sum[2][0]++;
			if (stu[i].EN>=80&&stu[i].EN<=89)  sum[2][1]++;
			if (stu[i].EN>=70&&stu[i].EN<=79)  sum[2][2]++;
			if (stu[i].EN>=60&&stu[i].EN<=69)  sum[2][3]++;
			if (stu[i].EN >=0&&stu[i].EN<=59)  sum[2][4]++;

			if (stu[i].SC>=90&&stu[i].SC<=100) sum[3][0]++;
			if (stu[i].SC>=80&&stu[i].SC<=89)  sum[3][1]++;
			if (stu[i].SC>=70&&stu[i].SC<=79)  sum[3][2]++;
			if (stu[i].SC>=60&&stu[i].SC<=69)  sum[3][3]++;
			if (stu[i].SC >=0&&stu[i].SC<=59)  sum[3][4]++;
		}
    printf("\n每门课程按优（90~100）、良（80~89）、中（70~79）、及格（60~69）、不及格（0~59）统计人数，及所占的百分比：\n");
    printf("\n\n1.人数：\n\n") ;
            printf(" \t| 语文(CN)  |  数学(MT)  |   英语(EN)  |   科学(SC)   \n");
            printf("   优   |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][0],sum[1][0],sum[2][0],sum[3][0]);
            printf("   良   |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][1],sum[1][1],sum[2][1],sum[3][1]);
            printf("   中   |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][2],sum[1][2],sum[2][2],sum[3][2]);
            printf("  及格  |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][3],sum[1][3],sum[2][3],sum[3][3]);
            printf(" 不及格 |    %2d     |     %2d     |     %2d      |      %2d        \n",sum[0][4],sum[1][4],sum[2][4],sum[3][4]);
    printf("\n\n2.百分比：\n\n");
          printf(" \t|  语文(CN)  |   数学(MT)  |   英语(EN)  |   科学(SC)   \n");
          printf("   优   |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][0]*100.0/n,sum[1][0]*100.0/n,sum[2][0]*100.0/n,sum[3][0]*100.0/n);
          printf("   良   |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][1]*100.0/n,sum[1][1]*100.0/n,sum[2][1]*100.0/n,sum[3][1]*100.0/n);
          printf("   中   |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][2]*100.0/n,sum[1][2]*100.0/n,sum[2][2]*100.0/n,sum[3][2]*100.0/n);
          printf("  及格  |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][3]*100.0/n,sum[1][3]*100.0/n,sum[2][3]*100.0/n,sum[3][3]*100.0/n);
          printf(" 不及格 |  %6.2f%%   |  %6.2f%%    |   %6.2f%%   |   %6.2f%%        \n",sum[0][4]*100.0/n,sum[1][4]*100.0/n,sum[2][4]*100.0/n,sum[3][4]*100.0/n);
    printf("\n请按任意键返回主菜单...\n");
    getchar();
}
//统计学生成绩信息
void stu_statistics()
{
      system("CLS");
      int num;
      printf("\n1.计算每门课程的总分和平均分\n");
      printf("\n2.计算每个学生所有课程的总分和平均分\n");
      printf("\n3.对每门课程按优、良、中、及格、不及格统计人数及所占的百分比\n");
      printf("\n请输入菜单旁边对应的数字进入相应功能：");
      num=getNum();
      switch(num)
      {
            case 1:statistics1();break;
            case 2:statistics2();break;
            case 3:statistics3();break;
      }

}
//显示菜单
void menu()
{
      void stu_input();
      void stu_modify();
      int stu_seek();
      void stu_delete();
      void stu_show();
      void stu_sort();
      void stu_statistics();
      void exitSy();
      void getDate();                     //数据函数：读取数据
      void data_save();                   //数据函数：存储数据
      system("CLS");                      //清屏,清除所有显示的信息。
      int num;
            printf("\n*****************************欢迎进入成绩管理系统！*****************************\n\n");
            printf("1.录入学生信息\n");
            printf("2.修改成绩信息\n");
            printf("3.查询学生信息\n");
            printf("4.删除学生信息\n");
            printf("5.显示学生信息\n");
            printf("6.排序学生信息\n");
            printf("7.统计学生信息\n");
            printf("8.退出管理系统\n");
            printf("\n请输入菜单旁边对应的数字进入相应功能：");
      num=getNum();
      switch(num)
      {
            case 1:stu_input();break;
            case 2:stu_modify();break;
            case 3:stu_seek();break;
            case 4:stu_delete();break;
            case 5:stu_show();break;
            case 6:stu_sort();break;
            case 7:stu_statistics();break;
            case 8:exitSy();break;
      }
}
int main()
{
      getDate();                          //读取数据
      while(1)
            menu();
      stu_save();                         //保存数据
  return 0;
}
