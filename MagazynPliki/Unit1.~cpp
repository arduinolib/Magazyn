//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <windows.h>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
      Form1->Align = alClient;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Elektronika1Click(TObject *Sender)
{
    Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::WyczyscGrid()
{

  for(int i=1;i<Form3->StringGrid2->RowCount;i++)
  {
    Form3->StringGrid2->Cells[1][i]="";
  }
  Form3->StringGrid2->RowCount=1;
  for(int i=1;i<Form3->StringGrid3->RowCount;i++)
  {
    Form3->StringGrid3->Cells[2][i]="";
  }
  Form3->StringGrid3->RowCount=1;
  Form4->Edit1->Text="";
  Form4->Edit2->Text="";
  Form4->Edit3->Text="";
  Form5->Edit1->Text="";
  Form5->Edit2->Text="";
  Form3->Edit1->Text="";
  Form3->Label4->Caption="";
  Form3->Label5->Caption="";
}
void __fastcall TForm1::Zamknij1Click(TObject *Sender)
{
    Form1->Close();    
}
//---------------------------------------------------------------------------


void __fastcall TForm1::MikrokontrolerryAVR1Click(TObject *Sender)
{
   ShellExecute( 0, "open", "Mikrokontrolery AVR", NULL, NULL, SW_SHOW );
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Tranzystory1Click(TObject *Sender)
{
   ShellExecute( 0, "open", "Tranzystory", NULL, NULL, SW_SHOW );
}
//---------------------------------------------------------------------------

