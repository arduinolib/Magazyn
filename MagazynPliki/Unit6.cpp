//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit7.h"
#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
AnsiString foto="";
AnsiString foto1="";
int a=0;
int a1=0;

//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm6::FormCreate(TObject *Sender)
{
 Form3-> LoadGridFromFile("Obraz.roz", StringGrid1);
 Form3-> LoadGridFromFile("Schemat.roz", StringGrid2);
 Label1->Caption="Dodawanie obrazka";
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Image1Click(TObject *Sender)
{

  int c = StringGrid1->RowCount;
  a++; if(a==c)a=1;
  Edit1->Text= StringGrid1->Cells[0][a];

  Image1->Picture->LoadFromFile(Edit1->Text);




}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button3Click(TObject *Sender)
{
    if(Edit1->Text==""){
     Application->MessageBox("Nie wybrano obrazka do dodania", "Dodawanie obrazka", MB_OK | MB_ICONSTOP);
    }
    if(Edit1->Text!=""){

    Form2->StringGrid1->RowCount=Form2->StringGrid1->RowCount;
    int lp= Form2->StringGrid1->RowCount-1;
    Form2->StringGrid1->Cells[4][lp]=Edit1->Text;
    Form3->SaveGridToFile("Obraz.roz", (StringGrid1), false);
    Form3->SaveGridToFile("ListaElementow.roz",(Form2->StringGrid1),false );

    Edit1->Visible=false;
    Image1->Visible=false;
    StringGrid1->Visible=false;
    Button1->Visible=false;
    Button3->Visible=false;

    Edit2->Visible=true;
    Image2->Visible=true;
    StringGrid2->Visible=true;
    Button2->Visible=true;
    Button4->Visible=true;
    Label1->Caption="Dodawanie schematu";
    }
}
//---------------------------------------------------------------------------



//===========================================================================


void __fastcall TForm6::Button1Click(TObject *Sender)
{

        if(OpenPictureDialog1->Execute())
    {
      try
       {
         Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName) ;
         foto = OpenPictureDialog1->FileName;
         Edit1->Text=foto.Delete(1, 29);

         StringGrid1->RowCount= StringGrid1->RowCount+1;
         int lp = StringGrid1->RowCount-1;
         StringGrid1->Cells[0][lp]=Edit1->Text;


       }
       catch (...)
       {
         ShowMessage("B³¹d otwarcia pliku.");
       }
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm6::Button2Click(TObject *Sender)
{

        if(OpenPictureDialog1->Execute())
    {
      try
       {
         Image2->Picture->LoadFromFile(OpenPictureDialog1->FileName) ;
         foto1 = OpenPictureDialog1->FileName;
         Edit2->Text=foto1.Delete(1, 29);

         StringGrid2->RowCount= StringGrid2->RowCount+1;
         int lp = StringGrid2->RowCount-1;
         StringGrid2->Cells[0][lp]=Edit2->Text;


       }
       catch (...)
       {
         ShowMessage("B³¹dotwarcia pliku.");
       }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button4Click(TObject *Sender)
{
    if(Edit2->Text==""){
     Application->MessageBox("Nie wybrano schematu do dodania", "Dodawanie schematu", MB_OK | MB_ICONSTOP);
    }
    if(Edit2->Text!=""){

    Form2->StringGrid1->RowCount=Form2->StringGrid1->RowCount;
    int lp= Form2->StringGrid1->RowCount-1;
    Form2->StringGrid1->Cells[5][lp]=Edit2->Text;
    Form3->SaveGridToFile("Schemat.roz", (StringGrid2), false);
    Form3->SaveGridToFile("ListaElementow.roz",(Form2->StringGrid1),false );


    Edit1->Visible=true;
    Image1->Visible=true;
    StringGrid1->Visible=true;
    Button1->Visible=true;
    Button3->Visible=true;

    Edit2->Visible=false;
    Image2->Visible=false;
    StringGrid2->Visible=false;
    Button2->Visible= false;
    Button4->Visible= false;
    Form6->Close();
    Form8->Show();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Image2Click(TObject *Sender)
{
     int c = StringGrid2->RowCount;
  a1++; if(a1==c)a1=1;
  Edit2->Text= StringGrid2->Cells[0][a1];

  Image2->Picture->LoadFromFile(Edit2->Text);
}
//--------------------------------------------------------------------------
                                        
