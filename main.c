#include "myhead.h"

int main()
{
    Graph G = (Graph)malloc(sizeof(Gra));
    InitData(G);
    int op = 1;
    while(op)
    {
        system("cls");
        printf("\n~��ӭʹ���й���������ͼȾɫ����Ϣ��ѯϵͳ��~ \n");
        printf("-------------------------------------\n");
        printf("    	  1. ��ͼȾɫ \n\n");
        printf("    	  2. ʡ����Ϣ��ѯ \n\n");
        printf("    	  3. ����ͨ���� \n\n");
        printf("    	  0. �˳� \n");
        printf("-------------------------------------\n");
        printf("    ����������ִ�еĹ���: " );
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            {
                int i,color[N]={0};
                MapColor(G->dist,color);
                printf("��ͼ��Ⱦɫ���Ϊ��" );
                for(i=0;i<N;i++)
                    printf("%d ",color[i]);
                printf("\n");
                getchar();getchar();
                break;
            }
            case 2:
            {
                Search(G);
                getchar();getchar();
                break;
            }
            case 3:
            {
                Network(G);
                getchar();getchar();
                break;
            }
            case 0:
                break;
            default:
                printf("\n     �������������ԣ�\n ");
                getchar();getchar();
        }
    }
    printf("\n     �ڴ������´�ʹ�ã�\n ");
    free(G);
    return 0;
}

void InitData(Graph G)
{
    FILE *fp;
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            G->dist[i][j] = 0;
    if((fp=fopen("linjie.txt","r"))==NULL)
    {
        printf("Open the file failure...\n");
        exit(0);
    }
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            fscanf(fp,"%d",&(G->dist[i][j]));
    fclose(fp);
    if((fp=fopen("data.txt","r"))==NULL)
    {
        printf("Open the file failure...\n");
        exit(0);
    }
    for(i=0;i<N;i++)
    {
        fscanf(fp,"%s",(char*)&(G->pro[i].name));
        fscanf(fp,"%s",(char*)&(G->pro[i].capital));
        fscanf(fp,"%s",(char*)&(G->pro[i].quhao));
        fscanf(fp,"%s",(char*)&(G->pro[i].population));
        fscanf(fp,"%s",(char*)&(G->pro[i].location));
    }
    fclose(fp);
}

void MapColor(int dist[N][N],int s[N])
{
    int color,area,k;
    s[0]=1;//��һ����������ɫΪ��ɫ1
    area=1;//�ӵڶ�����ʼ��̽Ⱦɫ
    color=1;//�ӵ�һ����ɫ��ʼ��̽
    while(area<N)//�Ƿ�ȫ��Ⱦɫ���
    {
        
        while(color<=4)
        {
            if(area>=N)
                break;
            k=0;
            while((k<area)&&(s[k]*dist[area][k]!=color))//�ж��Ƿ���ɫ
                k++;
            if(k<area)
                color++;
            else
            {
                s[area]=color;
                area++;
                color=2;
            }
        }
        if(color>4)//�ܹ���4����ɫ��û���ҵ����ʵ���ɫ����Ҫ���л���
        {
            area=area-1;
            color=s[area]+1;
        }
        
    }
}

void Search(Graph G)
{
    int i,flag = 0;
    char pro[20];
    do
    {
        printf("��������Ҫ��ѯ��ʡ�ݣ� \n");
        scanf("%s",pro);
        for (i=0;i<N;i++)
        {
            if(strcmp(pro, proName[i])==0)
            {
                printf("name:%s\n",G->pro[i].name);
                printf("capital:%s\n",G->pro[i].capital);
                printf("quhao:%s\n",G->pro[i].quhao);
                printf("population:%s\n",G->pro[i].population);
                printf("location:%s\n",G->pro[i].location);
                flag = 1;
                break;
            }
        }
        if(!flag)
            printf("�����������������룡\n\n" );
    }
    while(!flag);
}

void Network(Graph G)
{
    int n,i,j,cnt = 0,num = 0,weight = 0,flag = 0;
    printf("���������ͨ�����ĵ������� :" );
    scanf("%d",&n);
    if(n>0 && n<=32)
    {
        int x[n];
        char *s[n];
        for(i=0;i<n;i++)
            s[i] = (char*)malloc(sizeof(char*));
        do
        {
            printf("��������Щʡ���� :" );
            for(i=0;i<n;i++)
                scanf("%s",s[i]);
            for(i=0;i<n;i++)
                for(j=0;j<N;j++)
                    if(strcmp(s[i],proName[j])==0)
                    {
                        x[i] = j;
                        cnt++;
                        if(cnt==n)
                            flag = 1;
                        break;
                    }
            if(!flag)
                printf("�����������������룡\n\n" );
            cnt = 0;
        }
        while(!flag);
        for(i=0;i<n;i++)
            free(s[i]);
        qsort(x, n, sizeof(int), comp);
        for(i=0;i<n;i++)
            for(j=i;j<n;j++)
                if(G->dist[x[i]][x[j]])
                {
                    G->a[cnt].from = x[i];
                    G->a[cnt].to = x[j];
                    G->a[cnt].weight = G->dist[x[i]][x[j]]*G->dist[x[j]][x[i]];
                    cnt++;
                }
        qsort(G->a, cnt, sizeof(G->a[0]), cmp);
        //��С��������Kruskal�㷨
        for(i=0;i<N;i++) //��ʼ��
        {
            father[i] = i;
            son[i] = 1;
        }
        for(i=0;i<cnt && num<n-1;i++)
        {
            if(join(G->a[i].from,G->a[i].to))
            {
                num++; //������1
                weight+=G->a[i].weight; //��¼Ȩֵ֮��
                printf("��С�������м���ߣ�%s to %s\n",proName[G->a[i].from],proName[G->a[i].to]);
            }
        }
        printf("��С��������ȨֵΪ��%d\n", weight);
    }
    else
        printf("�������\n" );
}

int join(int x, int y) //�ϲ�
{
    int root1, root2;
    root1 = unionsearch(x);
    root2 = unionsearch(y);
    if(root1 == root2) //Ϊ��
        return 0;
    else if(son[root1] >= son[root2])
    {
        father[root2] = root1;
        son[root1] += son[root2];
    }
    else
    {
        father[root1] = root2;
        son[root2] += son[root1];
    }
    return 1;
}
