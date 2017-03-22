//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int net_flag=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
        Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
if(!net_flag)
{
int color,area,k,i,j;
int dist[N][N],s[N],location[N][2];
FILE *fp;
if((fp=fopen("linjie.txt","r"))==NULL)
{
Application->MessageBox("�ļ���ʧ�ܣ�","��ʾ",MB_OK);
}
for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            fscanf(fp,"%d",&(dist[i][j]));
fclose(fp);
if((fp=fopen("location.txt","r"))==NULL)
{
Application->MessageBox("�ļ���ʧ�ܣ�","��ʾ",MB_OK);
}
for(i=0;i<N;i++)
        for(j=0;j<2;j++)
            fscanf(fp,"%d",&(location[i][j]));
fclose(fp);
TColor tcolor[4];//����������ɫ
tcolor[0]=TColor(0x8800FF);
tcolor[1]=TColor(0xFFD700);
tcolor[2]=TColor(0x00FF00);
tcolor[3]=TColor(0x99FFFF);
    if(RadioButton1->Checked)
    s[0]=1;//��һ����������ɫΪ��ɫ1
    if(RadioButton2->Checked)
    s[0]=3;//��һ����������ɫΪ��ɫ2
    if(RadioButton3->Checked)
    s[0]=2;//��һ����������ɫΪ��ɫ3
    if(RadioButton4->Checked)
    s[0]=4;//��һ����������ɫΪ��ɫ4
    area=1;//�ӵڶ�����ʼ��̽Ⱦɫ
    color=1;
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
                color=1;
            }
        }
        if(color>4)//�ܹ���4����ɫ��û���ҵ����ʵ���ɫ����Ҫ���л���
        {
            area=area-1;
            color=s[area]+1;
        }
    }

    for(i=0;i<N;i++)
    {
    j=s[i]-1;
    Image1->Canvas->Brush->Style=bsSolid;
    Image1->Canvas->Brush->Color=tcolor[j];
    Image1->Canvas->FloodFill(location[i][0],location[i][1],clWhite,fsSurface);
    }
}
else
Application->MessageBox("���Ȼ�ԭ��","��ʾ",MB_OK);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
Image1->Picture->LoadFromFile("ChinaMap.bmp");
Label1->Caption="";
net_flag=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
Form3->Show();
net_flag=1;
}
//---------------------------------------------------------------------------

