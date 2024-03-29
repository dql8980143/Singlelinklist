#include "Singlelinklist.h"

//单链表初始化函数
void List::listStart()
{
	//S指向头结点，并将头结点的next指针置空
	cout<<"执行单链表的初始化功能"<<endl;
	S=new list;
	S->next=NULL;
}

//前插法创建单链表函数
void List::listFrontcreate(int num)
{
	cout<<"执行前插法创建单链表功能"<<endl;
	listStart();
	int i;
	list* p;
	for(i=0;i<num;i++)
	{
		p=new list;
		printf("请输入第%d个结点的数据:",i+1);
		scanf("%d",&p->data);
		p->next=S->next;
		S->next=p;
	}
}

//后插法创建单链表函数
void List::listBackcreate(int num)
{
	cout<<"执行后插法创建单链表功能"<<endl;
	listStart();
	list* rear=S;
	int i;
	list* p;
	for(i=0;i<num;i++)
	{
		p=new list;
		printf("请输入第%d个数据:",i+1);
		scanf("%d",&p->data);
		p->next=NULL;
		rear->next=p;
		rear=p;
	}
}

//打印输出单链表
void List::disPlay()const
{
	cout<<"执行打印输出单链表功能"<<endl;
	linklist p=S->next;
	int i=0;
	while(p!=NULL)
	{
		printf("第%d个数据:%d\n",i+1,p->data);
		p=p->next;
		i++;
	}
}

//单链表的取值函数
int List::getValue(int n)const
{
	cout<<"执行单链表的取值功能"<<endl;
	list* p=S->next;
	int i=1;
	while(i!=n && p!=NULL)
	{
		p=p->next;
		i++;
	}
	if(n<1 || !p)
	{
		cout<<"输入的n值不合理"<<endl;
		Sleep(1000);
		exit(1);
	}
	else
		return p->data;
}

//单链表的查找函数
int List::seekValue(int e)const
{
	cout<<"执行单链表查找功能"<<endl;
	list* p=S->next;
	int i=1;
	while(p!=NULL && p->data!=e )
	{
		p=p->next;
		i++;
	}
	if(!p)
	{
		printf("单链表中不存在%d数据\n",e);
		Sleep(1000);
		exit(2);
	}
	else
		return i;
}

//单链表的插入函数
void List::insertValue(int n,int e)
{
	cout<<"执行单链表的插入新数据功能"<<endl;
	list* p=S;
	int i=0;
	while(p!=NULL && i<n-1)
	{
		p=p->next;
		i++;
	}
	if(!p || n<1)
	{
		cout<<"插入的位置n不合理"<<endl;
		Sleep(1000);
		exit(3);
	}
	else
	{
		list* s=new list;
		s->data=e;
		s->next=p->next;
		p->next=s;
	}
}

//单链表的删除函数
int List::deleteValue(int n)
{
	cout<<"执行单链表的删除数据功能"<<endl;
	list* p=S;
	int i=0;
	int tmp;
	while(p!=NULL && i<n-1)
	{
		p=p->next;
		i++;
	}

	if(!p->next || n<1)
	{
		cout<<"删除的位置n不合理"<<endl;
		Sleep(1000);
		exit(4);
	}
	else
	{
		list* s=p->next;
		p->next=s->next;
		tmp=s->data;
		delete s;
	}
	return tmp;
}

//单链表数据存储至文本文件
void List::storeDatatofile()const
{
	cout<<"执行单链表数据存储至文本文件功能"<<endl;
	FILE* fp=fopen("Data.txt","w");
	if(!fp)
	{
		cout<<"文件打开失败"<<endl;
		Sleep(1000);
		exit(5);
	}
	list* p=S->next;
	int i=1;
	while(p!=NULL)
	{
		fprintf(fp,"第%d个数据:%d\n",i,p->data);
		p=p->next;
		i++;
	}
	fclose(fp);
}

//从文本文件导入数据创建单链表
void List::importDatafromfile()
{
	cout<<"执行从文本文件导入数据创建单链表功能"<<endl;
	listStart();
	FILE* fp=fopen("Data.txt","r");
	if(!fp)
	{
		cout<<"文件打开失败"<<endl;
		Sleep(1000);
		exit(6);
	}
	list* rear=S;
	list* s;
	int i;
	do
	{
		s=new list;
		fscanf(fp,"第%d个数据:%d\n",&i,&s->data);
		s->next=NULL;
		rear->next=s;
		rear=s;
	}while(!feof(fp));
	fclose(fp);
}

//打印单链表功能菜单
void List::functionDisplay()
{
	string str(20,'=');
	cout<<str<<endl;
	cout<<"    单链表的功能菜单    "<<endl;
	char* p[]={"1-单链表初始化功能","2-前插法创建单链表功能","3-后插法创建单链表功能",
		"4-打印输出单链表功能","5-单链表的取值功能","6-单链表的查找功能",
		"7-单链表的插入功能","8-单链表的删除功能","9-单链表数据存储至文本文件功能",
		"10-从文本文件导入数据创建单链表功能","11-打印单链表功能菜单功能"};
	int i;
	for(i=0;i<11;i++)
	{
		cout<<p[i]<<endl;
	}
	cout<<str<<endl;
}

	
		









