//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
int licz2=0;
int licz3=0;
int licz4=0;
int licz5=0;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm7::FormCreate(TObject *Sender)
{
     Edit1->Text=Form2->StringGrid1->Cells[3][Form2->StringGrid1->Row];
     
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Image2Click(TObject *Sender)
{
    if(licz2==1){
    Image2->Align= alNone;
    Image2->Height=200;
    Image2->Width=300;
    Image2->Left=88;
    Image2->Top=320;
    Memo1->Visible=true;
    Memo2->Visible=true;
    Label2->Visible=true;
    Edit1->Visible=true;
    Button1->Visible=true;
    licz2=2;
    }
    if(licz2==0){
    Image2->Visible=true;
    Image2->Align= alClient;
    Memo1->Visible=false;
    Memo2->Visible=false;
    Edit1->Visible=false;
    Button1->Visible=false;
    Label2->Visible=false;
    licz2=1;}
    if(licz2==2){
    licz2=0; }
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Image1Click(TObject *Sender)
{
    if(licz3==1){
    Image1->Align= alNone;
    Image1->Height=200;
    Image1->Width=300;
    Image1->Left=88;
    Image1->Top=80;
    Memo1->Visible=true;
    Memo2->Visible=true;
    Image2->Visible=true;
    Label2->Visible=true;
    Edit1->Visible=true;
    Button1->Visible=true;
    licz3=2;
    }
    if(licz3==0){

    Image2->Visible=false;
    Image1->Align= alClient;
    Memo1->Visible=false;
    Memo2->Visible=false;
   // Edit1->Visible=false;
    //Button1->Visible=false;
    Label2->Visible=false;
    licz3=1;}
    if(licz3==2){
    licz3=0; }
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Memo2Click(TObject *Sender)
{
   if(licz4==1){
    Memo2->Align= alNone;
    Memo2->Height=321;
    Memo2->Width=928;
    Memo2->Left=400;
    Memo2->Top=312;
    Memo2->Visible=true;
    Label2->Visible=true;
    Edit1->Visible=true;
    Button1->Visible=true;
    licz4=2;
    }
    if(licz4==0){
    Memo2->Visible=true;
    Memo2->Align= alClient;
    Edit1->Visible=false;
    Button1->Visible=false;
    Label2->Visible=false;
    licz4=1;}
    if(licz4==2){
    licz4=0; }
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Memo1Click(TObject *Sender)
{
   if(licz5==1){
    Memo1->Align= alNone;
    Memo1->Height=227;
    Memo1->Width=929;
    Memo1->Left=400;
    Memo1->Top=70;
    Memo1->Visible=true;
    Memo2->Visible=true;
    Label2->Visible=true;
    Edit1->Visible=true;
    Button1->Visible=true;
    licz5=2;
    }
    if(licz5==0){

    Memo2->Visible=false;
    Memo1->Align= alClient;
   // Edit1->Visible=false;
    //Button1->Visible=false;
    Label2->Visible=false;
    licz5=1;}
    if(licz5==2){
    licz5=0; }
}
//---------------------------------------------------------------------------

