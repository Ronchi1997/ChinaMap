//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button2Click(TObject *Sender)
{
        Label2->Caption="";
        Label4->Caption="";
        Label6->Caption="";
        Label8->Caption="";
        Label10->Caption="";
        Form2->Close();
        Form1->Image1->Picture->LoadFromFile("ChinaMap.bmp");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
char *proName[] = {"beijing","tianjin","hebei","shanxi","neimeng","liaoning","jilin","heilongjiang","shanghai","jiangsu","zhejiang","fujian","anhui","jiangxi","shandong","henan","hubei","hunan","guangdong","guangxi","hainan","chongqing","sichuan","guizhou","yunnan","xizang","shaanxi","gansu","ningxia","xinjiang","qinghai","taiwan"};
    Graph G = (Graph)malloc(sizeof(Gra));
    FILE *fp;
    int i,j,flag=0;
    int location[N][2];
    if((fp=fopen("data.txt","r"))==NULL)
    {
    Application->MessageBox("文件打开失败！","提示",MB_OK);
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
    if((fp=fopen("location.txt","r"))==NULL)
{
Application->MessageBox("文件打开失败！","提示",MB_OK);
}
for(i=0;i<N;i++)
        for(j=0;j<2;j++)
            fscanf(fp,"%d",&(location[i][j]));
fclose(fp);
    String s=Edit1->Text;
    char *pro=s.c_str();
    for(i=0;i<N;i++)
    {
    if(strcmp(pro, proName[i])==0)
    {
    Label2->Caption=G->pro[i].name;
    Label4->Caption=G->pro[i].capital;
    Label6->Caption=G->pro[i].quhao;
    Label8->Caption=G->pro[i].population;
    Label10->Caption=G->pro[i].location;
    Form1->Image1->Canvas->Brush->Style=bsSolid;
    Form1->Image1->Canvas->Brush->Color=clRed;
    Form1->Image1->Canvas->FloodFill(location[i][0],location[i][1],clWhite,fsSurface);
    flag = 1;
    break;
    }
    }
    if(!flag)
    Application->MessageBox("输入有误，请重新输入！","提示",MB_OK);
    Edit1->Text="";
    free(G);
}
//---------------------------------------------------------------------------
