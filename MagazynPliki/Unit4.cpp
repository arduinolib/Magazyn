//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit3.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
char wyb = 'k';
AnsiString wyb1="d";

//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

  struct FindCells
{
 int Row;
 int Col;
};
//Funkcja szukaj¹ca tekstu w grig
FindCells FindInGrid(TStringGrid *Grid, String tekst)
{
 FindCells fc;
 fc.Col = -1;
 fc.Row = -1;

 static int row = Grid->FixedRows;
 if(row >= Grid->RowCount - 1)
 row = Grid->FixedRows;

 for(int i = Grid->FixedCols; i < Grid->ColCount; i++)
 {
  for(int j = row; j < Grid->RowCount; j++)
  {
   String find = Grid->Cells[i][j];
   int x = find.Pos(tekst);
   if(x > 0)
   {
    fc.Col = i;
    fc.Row = j;
    row = j + 1;
    return fc;
   }
  }
 }
 row = Grid->FixedRows;
 return fc;
}

//============================================================================
void __fastcall TForm4:: Kategorie(String a)
{
   Form3->BubbleSort1(Form2->StringGrid1, 1);
   for(int i=1;i<Form2->StringGrid1->RowCount;i++)
   {
   String n1=Form2->StringGrid1->Cells[1][i];
   String n2=Form2->StringGrid1->Cells[1][i-1];
   Boolean Result = SameText(n1,n2);
   if(Form2->StringGrid1->Cells[0][i]==Form3->StringGrid1->Cells[0][Form3->StringGrid1->Row])
   {
    if(Result)
    {
     Form3->StringGrid2->RowCount = Form3->StringGrid2->RowCount;
     int lp = Form3->StringGrid2->RowCount-1;
     Form3->StringGrid2->Cells[1][lp] = Form2->StringGrid1->Cells[1][i-1];
    }
    else
    {
     Form3->StringGrid2->RowCount = Form3->StringGrid2->RowCount+1;
     int lp1 = Form3->StringGrid2->RowCount-1;
     Form3->StringGrid2->Cells[1][lp1] = Form2->StringGrid1->Cells[1][i];
    }
   }
   }
   wyb1=a;
   wyb = 'k';
   Form3->Label1->Caption= "Wybierz lub dopisz nazwê";
   Form3->Dodajnow1->Caption= "Dodaj now¹ nazwê";
   if(a=="d")
   Label1->Caption= "Nowa kategoria";
   Form3->StringGrid1->Visible=false;
   Form3->StringGrid2->Visible=true;
   Form3->StringGrid3->Visible=false;
   Form3->Visible=false;

}
//============================================================================
void __fastcall TForm4:: Nazwy(String a)
{

   for(int i=1;i<Form2->StringGrid1->RowCount;i++)
   {
   String n1=Form2->StringGrid1->Cells[1][i];
   String n2=Form2->StringGrid1->Cells[1][i-1];
   Boolean Result = SameText(n1,n2);

   String n3=Form2->StringGrid1->Cells[0][i];
   String n4=Form3->StringGrid1->Cells[0][Form3->StringGrid1->Row];
   Boolean Result1 = SameText(n3,n4);

   String n5=Form2->StringGrid1->Cells[1][i];
   String n6=Form3->StringGrid2->Cells[1][Form3->StringGrid2->Row];
   Boolean Result2 = SameText(n5,n6);

   if(Result1&&Result2)
   {

     Form3->StringGrid3->RowCount = Form3->StringGrid3->RowCount+1;
     int lp = Form3->StringGrid3->RowCount-1;
     Form3->StringGrid3->Cells[2][lp] = Form2->StringGrid1->Cells[2][i];
    }
   }

   wyb1=a;
   wyb = 'n';
   Form3->Label1->Caption= "Dopisz symbol";
   Form3->Dodajnow1->Caption= "Dodaj nowy symbol";
   if(a=="d")
   Label1->Caption= "Nowa nazwa";
   Form3->StringGrid1->Visible=false;
   Form3->StringGrid2->Visible=false;
   Form3->StringGrid3->Visible=true;
   Form3->Visible=false;
}
//============================================================================
void __fastcall TForm4:: Symbole(String a)
{
   wyb1=a;
   wyb = 's';
   Form3->Label1->Caption= "Wybierz lub dopisz kategoriê";
   Form3->Dodajnow1->Caption= "Dodaj now¹ kategoriê";
   Label1->Caption= "Nowy symbol";
   Form3->StringGrid1->Visible=true;
   Form3->StringGrid2->Visible=false;
   Form3->StringGrid3->Visible=false;
   Form3->Visible=false;
}
//============================================================================

//dodawanie nowej kategorii, nazwy i symbolu
void __fastcall TForm4::Button1Click(TObject *Sender)
{
//------------------------------------------------------------------------
 if(Edit1->Text == ""&&wyb=='k')   //info ¿e nast¹pi³a próba zapisania pustego pola
 {
   Application->MessageBox(("Nie wpisano kategorii!!! „" + Edit1->Text + "”").c_str(),
   "Wpisz kategoriê do pola!!!", MB_OK | MB_ICONINFORMATION);

  return;
 }
 //------------------------------------------------------------------------
 if(Edit1->Text == ""&&wyb=='n')   //info ¿e nast¹pi³a próba zapisania pustego pola
 {
   Application->MessageBox(("Nie wpisano nazwy!!! „" + Edit1->Text + "”").c_str(),
   "Wpisz nazwê do pola!!!", MB_OK | MB_ICONINFORMATION);

  return;
 }
 //------------------------------------------------------------------------
 if(Edit1->Text == ""&&wyb=='s')   //info ¿e nast¹pi³a próba zapisania pustego pola
 {
   Application->MessageBox(("Nie wpisano symbolu!!! „" + Edit1->Text + "”").c_str(),
   "Wpisz symbol do pola!!!", MB_OK | MB_ICONINFORMATION);

  return;
 }
 //------------------------------------------------------------------------
  else
  {

  //dodanie nowej kategorii
    if(wyb=='k'&&wyb1=='d')
      {

       FindCells fc;
 fc = FindInGrid(Form3->StringGrid1, Edit1->Text);
 //----------------kategoria------------------------
 if(fc.Col == 0&&wyb1=="d")        //info ¿e jest ju¿ taka kategoria
 {
  Application->MessageBox(("Jest ju¿ taka kategoria!!! „" + Edit1->Text + "”").c_str(),
   "Wpisz inn¹", MB_OK | MB_ICONINFORMATION);
   Edit1->Text="";
  return;
 }
         Form4->Edit2->Text = Edit1->Text;
         Form3->Label4->Caption=Edit1->Text;
         Form3->StringGrid1->RowCount = Form3->StringGrid1->RowCount+1; //dopisanie tekstu do Form3->StringGrid1 col[0]
         int lp1 = Form3->StringGrid1->RowCount-1;
         Form3->StringGrid1->Cells[0][lp1] = Edit1->Text;
         Edit1->Text="";
         Form3->Visible=true;
      }
//-------------  koniec kategoria ----------------------------------------

//--------------  nazwa -----------------------
//dodanie nowej nazwy
    if(wyb=='n'&&wyb1=='d')
      {

       FindCells fc;
 fc = FindInGrid(Form3->StringGrid2, Edit1->Text);
 if(fc.Col == 1&&wyb1=="d")        //info ¿e jest ju¿ taka nazwa
 {
  Application->MessageBox(("Jest ju¿ taka nazwa!!! „" + Edit1->Text + "”").c_str(),
   "Wpisz inn¹", MB_OK | MB_ICONINFORMATION);
   Edit1->Text="";
  return;
 }
         Form4->Edit3->Text = Edit1->Text;
         Form3->Label5->Caption= Edit1->Text;
         Form3->StringGrid2->RowCount = Form3->StringGrid2->RowCount+1; //dopisanie tekstu do Form3->StringGrid1 col[0]
         int lp1 = Form3->StringGrid2->RowCount-1;
         Form3->StringGrid2->Cells[1][lp1] = Edit1->Text;
         Edit1->Text="";
         Form3->Visible=true;
      }
      }
//-------------  koniec nazwa ----------------------------------------
//---------------  symbol  -------------------------------------
 //dodanie nowego symbolu
    if(wyb=='s'&&wyb1=='d')
      {
         Form3->StringGrid3->RowCount = Form3->StringGrid3->RowCount; //dopisanie tekstu do Form3->StringGrid1 col[0]
         int lp1 = Form3->StringGrid3->RowCount-1;
         Form3->StringGrid3->Cells[2][lp1] = Edit1->Text;

         Form3->Visible=true;
     }


//-------------  koniec symbol ----------------------------------------
  Form4->Close();
  if(wyb=='s'){
  Form3->Close();
  Form5->Show();
   }
  }

//---------------------------------------------------------------------------


