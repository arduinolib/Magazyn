//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
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

void __fastcall TForm2::FormCreate(TObject *Sender)
{

    Form3->LoadGridFromFile("ListaElementow.roz",StringGrid1);
     Form3->BubbleSort1(Form2->StringGrid1, 0);

     Form2->Align = alClient;
     StringGrid1->ColWidths[0]=245;
     StringGrid1->ColWidths[1]=295;
     StringGrid1->ColWidths[2]=245;
     StringGrid1->ColWidths[3]=100;
     StringGrid1->ColWidths[4]=100;
     StringGrid1->ColWidths[5]=100;
     StringGrid1->ColWidths[6]=100;
     StringGrid1->ColWidths[7]=100;

     StringGrid1->Cells[0][0]= "Kategoria";
     StringGrid1->Cells[1][0]= "Nazwa elementu";
     StringGrid1->Cells[2][0]= "Symbol elementu";
     StringGrid1->Cells[3][0]= "Ilosc";
     StringGrid1->Cells[4][0]= "Obrazek";
     StringGrid1->Cells[5][0]= "Schemat";
     StringGrid1->Cells[6][0]= "Parametry";
     StringGrid1->Cells[7][0]= "Opis";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Dodajnowyelement1Click(TObject *Sender)
{
    Form1->WyczyscGrid();
    Form5->Label2->Visible=false;
    Form5->Edit2->Visible=false;
    Form3->StringGrid1->Visible=true;
    Form3->StringGrid2->Visible=false;
    Form3->StringGrid3->Visible=false;
    Form3->Show();
    Form3->StringGrid3->Enabled=false;
}

//---------------------------------------------------------------------------
void __fastcall DeleteRow(TStringGrid *Grid, int ARow)
{
 if(ARow < Grid->FixedRows)
 {
  Application->MessageBox("Nie wybrano wiersza do usuni�cia", "Usuwanie wiersza", MB_OK | MB_ICONSTOP);
  return;
 }
 if(Grid->RowCount == Grid->FixedRows + 1)
 {
  int id = Application->MessageBox("Conajmniej jeden wiersz (nie licz�c nag��wka) musi pozosta� w tabeli. "
           "Czy chcesz wyczy�ci� zawarto�� kom�rek w tym wierszu?", "Usuwanie wiersza", MB_YESNO | MB_ICONQUESTION);
  if(id == ID_YES)
   for(int y = 0; y < Grid->ColCount; y++)
    Grid->Cells[y][ARow] = "";
  return;
 }
  for(int i = ARow; i <= Grid->RowCount - 1; i++)
  {
   for(int y = 0; y < Grid->ColCount; y++)
   {
    Grid->Cells[y][i] = Grid->Cells[y][i + 1];
    Grid->Cells[y][i + 1] = "";
   }
  }
  Grid->RowCount--;
 Grid->SetFocus();
}

//---------------------------------------------------------------------------



void __fastcall TForm2::Zmieiloscwwybranymelemencie1Click(TObject *Sender)
{
    Form1->WyczyscGrid();
    Form5->Label2->Visible=true;
    Form5->Edit2->Visible=true;
    Form3->StringGrid1->Visible=true;
    Form3->StringGrid2->Visible=false;
    Form3->StringGrid3->Visible=false;
    Form3->Show();
    Form3->StringGrid3->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edytujwybranyelement1Click(TObject *Sender)
{
    if(StringGrid1->Row==0){
      Application->MessageBox("Nie wybrano elementu do edycji", "Edycja elementu", MB_OK | MB_ICONSTOP);
         return;
    }
    if(StringGrid1->Cells[4][StringGrid1->Row]!=" ")
    Form7-> Image1->Picture->LoadFromFile(StringGrid1->Cells[4][StringGrid1->Row]);
    if(StringGrid1->Cells[5][StringGrid1->Row]!=" "){
    Form7-> Image2->Picture->LoadFromFile(StringGrid1->Cells[5][StringGrid1->Row]);
    Form7->Image2->Visible=true;}

    if(StringGrid1->Cells[6][StringGrid1->Row]!=" ")
    Form7-> Memo1->Lines->LoadFromFile(StringGrid1->Cells[6][StringGrid1->Row]);
    else
    Form7-> Memo1->Lines->Text="Brak specyfikacji";
    if(StringGrid1->Cells[7][StringGrid1->Row]!=" "){
    Form7->Memo2->Lines-> LoadFromFile(StringGrid1->Cells[7][StringGrid1->Row]);
    Form7->Memo2->Visible=true;}
    else
    Form7-> Memo2->Lines->Text="Brak opisu";

    Form7->Edit1->Text=StringGrid1->Cells[3][StringGrid1->Row];
    Form7->Label2->Caption =StringGrid1->Cells[1][StringGrid1->Row]+" - "+StringGrid1->Cells[2][StringGrid1->Row] ;
   
    Form7->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Usuwybranyelement1Click(TObject *Sender)
{
      int id = Application->MessageBox("Czy na pewno chcesz usun�� wybrany wiersz?\nOperacji nie b�dzie mo�na cofn��!",
          "Usuwanie wiersza", MB_YESNO | MB_ICONQUESTION);
      if(id == ID_YES){
      if(StringGrid1->Cells[1][1]=="")
        {
          Application->MessageBox("Lista jest pusta", "Usuwanie wiersza", MB_OK | MB_ICONSTOP);
         return;

        }
         if(StringGrid1->Row!=0)
         {
         DeleteRow(StringGrid1, StringGrid1->Row);
         }
         else
         {
         Application->MessageBox("Nie wybrano wiersza do usuni�cia", "Usuwanie wiersza", MB_OK | MB_ICONSTOP);
         return;
         }
         
         Form3->SaveGridToFile("ListaElementow.roz",(Form2->StringGrid1),false );
         }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Zakocz1Click(TObject *Sender)
{
  Form1->Close();
}
//---------------------------------------------------------------------------

