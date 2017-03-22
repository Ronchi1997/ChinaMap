//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
int father[N],son[N];
struct edge//边相关信息
    {
        int from;
        int to;
        int weight;
    }a[N*(N-1)/2];
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
Form3->Close();
}
//---------------------------------------------------------------------------
int cmp(const void *a,const void *b)
{
    return ((struct edge*)a)->weight - ((struct edge*)b)->weight;
}
//查找根结点+路径压缩
int unionsearch(int x)
{
    return x == father[x] ? x : unionsearch(father[x]);
}
int join(int x, int y) //合并
{
    int root1, root2;
    root1 = unionsearch(x);
    root2 = unionsearch(y);
    if(root1 == root2) //为环
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

void __fastcall TForm3::Button1Click(TObject *Sender)
{
int n = 0,i,j,cnt = 0,num = 0,weight = 0;
Graph G = (Graph)malloc(sizeof(Gra));
int x[N],location[N][2];
FILE *fp;
if((fp=fopen("linjie.txt","r"))==NULL)
{
Application->MessageBox("文件打开失败！","提示",MB_OK);
}
for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            fscanf(fp,"%d",&(G->dist[i][j]));
fclose(fp);
if((fp=fopen("location.txt","r"))==NULL)
{
Application->MessageBox("文件打开失败！","提示",MB_OK);
}
for(i=0;i<N;i++)
        for(j=0;j<2;j++)
            fscanf(fp,"%d",&(location[i][j]));
fclose(fp);
if(CheckBox1->Checked)
x[n++]=0;
if(CheckBox2->Checked)
x[n++]=1;
if(CheckBox3->Checked)
x[n++]=2;
if(CheckBox4->Checked)
x[n++]=3;
if(CheckBox5->Checked)
x[n++]=4;
if(CheckBox6->Checked)
x[n++]=5;
if(CheckBox7->Checked)
x[n++]=6;
if(CheckBox8->Checked)
x[n++]=7;
if(CheckBox9->Checked)
x[n++]=8;
if(CheckBox10->Checked)
x[n++]=9;
if(CheckBox11->Checked)
x[n++]=10;
if(CheckBox12->Checked)
x[n++]=11;
if(CheckBox13->Checked)
x[n++]=12;
if(CheckBox14->Checked)
x[n++]=13;
if(CheckBox15->Checked)
x[n++]=14;
if(CheckBox16->Checked)
x[n++]=15;
if(CheckBox17->Checked)
x[n++]=16;
if(CheckBox18->Checked)
x[n++]=17;
if(CheckBox19->Checked)
x[n++]=18;
if(CheckBox20->Checked)
x[n++]=19;
if(CheckBox21->Checked)
x[n++]=20;
if(CheckBox22->Checked)
x[n++]=21;
if(CheckBox23->Checked)
x[n++]=22;
if(CheckBox24->Checked)
x[n++]=23;
if(CheckBox25->Checked)
x[n++]=24;
if(CheckBox26->Checked)
x[n++]=25;
if(CheckBox27->Checked)
x[n++]=26;
if(CheckBox28->Checked)
x[n++]=27;
if(CheckBox29->Checked)
x[n++]=28;
if(CheckBox30->Checked)
x[n++]=29;
if(CheckBox31->Checked)
x[n++]=30;
if(CheckBox32->Checked)
x[n++]=31;
for(i=0;i<n;i++)
            for(j=i;j<n;j++)
                if(G->dist[x[i]][x[j]])
                {
                    a[cnt].from = x[i];
                    a[cnt].to = x[j];
                    a[cnt].weight = G->dist[x[i]][x[j]]*G->dist[x[j]][x[i]];
                    cnt++;
                }
        qsort(a, cnt, sizeof(a[0]), cmp);
        for(i=0;i<N;i++) //初始化
        {
            father[i] = i;
            son[i] = 1;
        }
        for(i=0;i<cnt && num<n-1;i++)
        {
            if(join(a[i].from,a[i].to))
            {
                num++; //边数加1
                weight+=a[i].weight; //记录权值之和
                Form1->Image1->Canvas->Pen->Color=clRed;
                Form1->Image1->Canvas->Pen->Width=3;
                Form1->Image1->Canvas->MoveTo(location[a[i].from][0],location[a[i].from][1]);
                Form1->Image1->Canvas->LineTo(location[a[i].to][0],location[a[i].to][1]);
            }
        }
Form1->Label1->Caption="架设通信网花费："+IntToStr(weight);
free(G);
Form3->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::CheckBox33Click(TObject *Sender)
{
if(CheckBox33->Checked)
{
CheckBox1->Checked=true;
CheckBox2->Checked=true;
CheckBox3->Checked=true;
CheckBox4->Checked=true;
CheckBox5->Checked=true;
CheckBox6->Checked=true;
CheckBox7->Checked=true;
CheckBox8->Checked=true;
CheckBox9->Checked=true;
CheckBox10->Checked=true;
CheckBox11->Checked=true;
CheckBox12->Checked=true;
CheckBox13->Checked=true;
CheckBox14->Checked=true;
CheckBox15->Checked=true;
CheckBox16->Checked=true;
CheckBox17->Checked=true;
CheckBox18->Checked=true;
CheckBox19->Checked=true;
CheckBox20->Checked=true;
CheckBox21->Checked=true;
CheckBox22->Checked=true;
CheckBox23->Checked=true;
CheckBox24->Checked=true;
CheckBox25->Checked=true;
CheckBox26->Checked=true;
CheckBox27->Checked=true;
CheckBox28->Checked=true;
CheckBox29->Checked=true;
CheckBox30->Checked=true;
CheckBox31->Checked=true;
CheckBox32->Checked=true;
}
else
{
CheckBox1->Checked=false;
CheckBox2->Checked=false;
CheckBox3->Checked=false;
CheckBox4->Checked=false;
CheckBox5->Checked=false;
CheckBox6->Checked=false;
CheckBox7->Checked=false;
CheckBox8->Checked=false;
CheckBox9->Checked=false;
CheckBox10->Checked=false;
CheckBox11->Checked=false;
CheckBox12->Checked=false;
CheckBox13->Checked=false;
CheckBox14->Checked=false;
CheckBox15->Checked=false;
CheckBox16->Checked=false;
CheckBox17->Checked=false;
CheckBox18->Checked=false;
CheckBox19->Checked=false;
CheckBox20->Checked=false;
CheckBox21->Checked=false;
CheckBox22->Checked=false;
CheckBox23->Checked=false;
CheckBox24->Checked=false;
CheckBox25->Checked=false;
CheckBox26->Checked=false;
CheckBox27->Checked=false;
CheckBox28->Checked=false;
CheckBox29->Checked=false;
CheckBox30->Checked=false;
CheckBox31->Checked=false;
CheckBox32->Checked=false;
}
}
//---------------------------------------------------------------------------

