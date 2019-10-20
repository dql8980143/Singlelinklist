#include "Singlelinklist.h"

//��������ʼ������
void List::listStart()
{
	//Sָ��ͷ��㣬����ͷ����nextָ���ÿ�
	cout<<"ִ�е������ĳ�ʼ������"<<endl;
	S=new list;
	S->next=NULL;
}

//ǰ�巨��������������
void List::listFrontcreate(int num)
{
	cout<<"ִ��ǰ�巨��������������"<<endl;
	listStart();
	int i;
	list* p;
	for(i=0;i<num;i++)
	{
		p=new list;
		printf("�������%d����������:",i+1);
		scanf("%d",&p->data);
		p->next=S->next;
		S->next=p;
	}
}

//��巨��������������
void List::listBackcreate(int num)
{
	cout<<"ִ�к�巨��������������"<<endl;
	listStart();
	list* rear=S;
	int i;
	list* p;
	for(i=0;i<num;i++)
	{
		p=new list;
		printf("�������%d������:",i+1);
		scanf("%d",&p->data);
		p->next=NULL;
		rear->next=p;
		rear=p;
	}
}

//��ӡ���������
void List::disPlay()const
{
	cout<<"ִ�д�ӡ�������������"<<endl;
	linklist p=S->next;
	int i=0;
	while(p!=NULL)
	{
		printf("��%d������:%d\n",i+1,p->data);
		p=p->next;
		i++;
	}
}

//��������ȡֵ����
int List::getValue(int n)const
{
	cout<<"ִ�е�������ȡֵ����"<<endl;
	list* p=S->next;
	int i=1;
	while(i!=n && p!=NULL)
	{
		p=p->next;
		i++;
	}
	if(n<1 || !p)
	{
		cout<<"�����nֵ������"<<endl;
		Sleep(1000);
		exit(1);
	}
	else
		return p->data;
}

//�������Ĳ��Һ���
int List::seekValue(int e)const
{
	cout<<"ִ�е��������ҹ���"<<endl;
	list* p=S->next;
	int i=1;
	while(p!=NULL && p->data!=e )
	{
		p=p->next;
		i++;
	}
	if(!p)
	{
		printf("�������в�����%d����\n",e);
		Sleep(1000);
		exit(2);
	}
	else
		return i;
}

//�������Ĳ��뺯��
void List::insertValue(int n,int e)
{
	cout<<"ִ�е������Ĳ��������ݹ���"<<endl;
	list* p=S;
	int i=0;
	while(p!=NULL && i<n-1)
	{
		p=p->next;
		i++;
	}
	if(!p || n<1)
	{
		cout<<"�����λ��n������"<<endl;
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

//��������ɾ������
int List::deleteValue(int n)
{
	cout<<"ִ�е�������ɾ�����ݹ���"<<endl;
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
		cout<<"ɾ����λ��n������"<<endl;
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

//���������ݴ洢���ı��ļ�
void List::storeDatatofile()const
{
	cout<<"ִ�е��������ݴ洢���ı��ļ�����"<<endl;
	FILE* fp=fopen("Data.txt","w");
	if(!fp)
	{
		cout<<"�ļ���ʧ��"<<endl;
		Sleep(1000);
		exit(5);
	}
	list* p=S->next;
	int i=1;
	while(p!=NULL)
	{
		fprintf(fp,"��%d������:%d\n",i,p->data);
		p=p->next;
		i++;
	}
	fclose(fp);
}

//���ı��ļ��������ݴ���������
void List::importDatafromfile()
{
	cout<<"ִ�д��ı��ļ��������ݴ�������������"<<endl;
	listStart();
	FILE* fp=fopen("Data.txt","r");
	if(!fp)
	{
		cout<<"�ļ���ʧ��"<<endl;
		Sleep(1000);
		exit(6);
	}
	list* rear=S;
	list* s;
	int i;
	do
	{
		s=new list;
		fscanf(fp,"��%d������:%d\n",&i,&s->data);
		s->next=NULL;
		rear->next=s;
		rear=s;
	}while(!feof(fp));
	fclose(fp);
}

//��ӡ���������ܲ˵�
void List::functionDisplay()
{
	string str(20,'=');
	cout<<str<<endl;
	cout<<"    �������Ĺ��ܲ˵�    "<<endl;
	char* p[]={"1-��������ʼ������","2-ǰ�巨��������������","3-��巨��������������",
		"4-��ӡ�������������","5-��������ȡֵ����","6-�������Ĳ��ҹ���",
		"7-�������Ĳ��빦��","8-��������ɾ������","9-���������ݴ洢���ı��ļ�����",
		"10-���ı��ļ��������ݴ�������������","11-��ӡ���������ܲ˵�����"};
	int i;
	for(i=0;i<11;i++)
	{
		cout<<p[i]<<endl;
	}
	cout<<str<<endl;
}

	
		








