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
TForm8 *Form8;
AnsiString tekst="";
int a=0;
AnsiString tekst1="";
int a1=0;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm8::FormCreate(TObject *Sender)
{
   Form3-> LoadGridFromFile("Specyfikacja.roz", StringGrid1);
   Form3-> LoadGridFromFile("Opis.roz", StringGrid2);
   Label1->Caption="Dodawanie specyfikacji";
   Button3->Visible=false;
   Button4->Visible=false;
   Edit2->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender)
{
          if(OpenDialog1->Execute())
    {
      try
       {
         Memo1->Lines->LoadFromFile(OpenDialog1->FileName) ;
         tekst = OpenDialog1->FileName;
         Edit1->Text=tekst.Delete(1, 29);

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
void __fastcall TForm8::Button2Click(TObject *Sender)
{
    if(Edit1->Text==""){
     Application->MessageBox("Nie wybrano specyfikacji do dodania", "Dodawanie specyfikacji", MB_OK | MB_ICONSTOP);
    }
    if(Edit1->Text!=""){

    Form2->StringGrid1->RowCount=Form2->StringGrid1->RowCount;
    int lp= Form2->StringGrid1->RowCount-1;
    Form2->StringGrid1->Cells[6][lp]=Edit1->Text;
    Form3->SaveGridToFile("Specyfikacja.roz", (StringGrid1), false);
    Form3->SaveGridToFile("ListaElementow.roz",(Form2->StringGrid1),false );

    Edit1->Visible=false;
    Memo1->Visible=false;
    StringGrid1->Visible=false;
    Button1->Visible=false;
    Button2->Visible=false;

    Edit2->Visible=true;
    Memo2->Visible=true;
    StringGrid2->Visible=true;
    Button3->Visible=true;
    Button4->Visible=true;
    Label1->Caption="Dodawanie opisu";
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Memo1Click(TObject *Sender)
{
      int c = StringGrid1->RowCount;
  a++; if(a==c)a=1;
  Edit1->Text= StringGrid1->Cells[0][a];

  Memo1->Lines->LoadFromFile(Edit1->Text);

}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button3Click(TObject *Sender)
{
        if(OpenDialog1->Execute())
    {
      try
       {
         Memo2->Lines->LoadFromFile(OpenDialog1->FileName) ;
         tekst1 = OpenDialog1->FileName;
         Edit2->Text=tekst1.Delete(1, 29);

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

void __fastcall TForm8::Button4Click(TObject *Sender)
{
    if(Edit2->Text==""){
     Application->MessageBox("Nie wybrano opisu do dodania", "Dodawanie opisu", MB_OK | MB_ICONSTOP);
    }
    if(Edit2->Text!=""){

    Form2->StringGrid1->RowCount=Form2->StringGrid1->RowCount;
    int lp= Form2->StringGrid1->RowCount-1;
    Form2->StringGrid1->Cells[7][lp]=Edit2->Text;
    Form3->SaveGridToFile("Opis.roz", (StringGrid2), false);
    Form3->SaveGridToFile("ListaElementow.roz",(Form2->StringGrid1),false );


    Edit1->Visible=true;
    Memo1->Visible=true;
    StringGrid1->Visible=true;
    Button1->Visible=true;
    Button2->Visible=true;

    Edit2->Visible=false;
    Memo2->Visible=false;
    StringGrid2->Visible=false;
    Button3->Visible= false;
    Button4->Visible= false;
    Form8->Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Memo2Click(TObject *Sender)
{
    
     int c = StringGrid2->RowCount;
  a1++; if(a1==c)a1=1;
  Edit2->Text= StringGrid2->Cells[0][a1];

  Memo2->Lines->LoadFromFile(Edit2->Text);
}
//---------------------------------------------------------------------------

