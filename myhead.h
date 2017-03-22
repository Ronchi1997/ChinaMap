#ifndef myhead_h
#define myhead_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 32 //�й�ʡ��������������ۡ�����

typedef struct
{
    char name[20];
    char capital[20];
    char quhao[10];
    char population[10];
    char location[30];
}Province;
typedef struct
{
    struct edge//�������Ϣ
    {
        int from;
        int to;
        int weight;
    }a[N*(N-1)/2];
    Province pro[N];//ʡ����Ϣ
    int dist[N][N];//�ڽӾ���
}Gra,*Graph;

char *proName[] = {"beijing","tianjin","hebei","shanxi","neimeng","liaoning","jilin","heilongjiang","shanghai","jiangsu","zhejiang","fujian","anhui","jiangxi","shandong","henan","hubei","hunan","guangdong","guangxi","hainan","chongqing","sichuan","guizhou","yunnan","xizang","shaanxi","gansu","ningxia","xinjiang","qinghai","taiwan"};
int father[N],son[N];

void InitData(Graph G);
void MapColor(int dist[N][N],int s[N]);
void Search(Graph G);
void Network(Graph G);
int join(int x, int y); //�ϲ�
//����������
int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
int cmp(const void *a,const void *b)
{
    return((struct edge*)a)->weight - ((struct edge*)b)->weight;
}
//���Ҹ����+·��ѹ��
int unionsearch(int x)
{
    return x == father[x] ? x : unionsearch(father[x]);
}

#endif /* myhead_h */
