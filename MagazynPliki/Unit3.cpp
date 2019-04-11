//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
int licz = 0;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCreate(TObject *Sender)
{

    for(int i=1;i<Form2->StringGrid1->RowCount;i++)
   {
    if(Form2->StringGrid1->Cells[0][i]==Form2->StringGrid1->Cells[0][i-1])
    {
     StringGrid1->RowCount = StringGrid1->RowCount;
     int lp = StringGrid1->RowCount-1;
     StringGrid1->Cells[0][lp] = Form2->StringGrid1->Cells[0][i-1];
    }
    else
    {
     StringGrid1->RowCount = StringGrid1->RowCount+1;
     int lp1 = StringGrid1->RowCount-1;
     StringGrid1->Cells[0][lp1] = Form2->StringGrid1->Cells[0][i];
    }
   }

     StringGrid1->ColWidths[0]=380;
     StringGrid1->Cells[0][0]= "Kategoria";

     StringGrid2->ColWidths[0]=1;
     StringGrid2->ColWidths[1]=379;
     StringGrid2->Cells[1][0]= "Nazwa elementu";

     StringGrid3->ColWidths[0]=1;
     StringGrid3->ColWidths[1]=1;
     StringGrid3->ColWidths[2]=378;
     StringGrid3->Cells[2][0]= "Symbol elementu";

}
//---------------------------------------------------------------------------
  struct FindCells
{
 int Row;
 int Col;
};
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
//-----------------------------------------------------------------------------
  struct Cells
{
 int Row;
 int Col;
};
Cells InGrid(TStringGrid *Grid, String tekst)
{
 Cells fc;
 fc.Col = -1;
 fc.Row = -1;

 static int row = Grid->FixedRows;
 if(row >= Grid->RowCount - 1)
 row = Grid->FixedRows;

 for(int i = Grid->FixedCols; i < Grid->ColCount; i++)
 {
  for(int j = row; j < Grid->RowCount; j++)
  {
   if(Grid->Cells[2][j]==Form3->Edit1->Text&&Grid->Cells[0][j]==Form4->Edit2->Text&&Grid->Cells[1][j]==Form4->Edit3->Text){
   String find = Grid->Cells[i][j];
   Form5->Edit2->Text= Grid->Cells[3][j];
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
 }
 row = Grid->FixedRows;
 return fc;
}
//-----------------------------------------------------------------------------
void __fastcall TForm3::Dodajnow1Click(TObject *Sender)
{
   licz++;
   if(licz==4)
   licz=1;

   if(licz==1)
   {
   Form4->Kategorie("d");
   Form4->Show();
   }
    if(licz==2)
   {
   Form4->Nazwy("d");
   Form4->Show();
   }
    if(licz==3)
   {
   Form4->Symbole("d");
   Form4->Show();
   }
}
//---------------------------------------------------------------------------
 void __fastcall TForm3::SaveGridToFile(AnsiString FileName, TStringGrid *Grid,
        bool csv)
{
 TStringList *Lista = new TStringList;
 String txt_1 = "", txt_2 = "";

 if(!csv)
 Lista->Add("\"Col" + (AnsiString)Grid->ColCount + "\";\"ROW" + (AnsiString)Grid->RowCount + "\"");

 for(int i = 0; i < Grid->RowCount; i++)
 {
  for(int j = Grid->ColCount - 1; j >= 0; j--)
  {
   String temp = Grid->Cells[j][i];
   if(temp.SubString(temp.Length(), temp.Length() + 1) == ";")
    temp = Grid->Cells[j][i] + "'";
   if(!csv)
    txt_1 = ";\"" + temp + "\"" + txt_1;
   else
    txt_1 = "\"" + temp + "\";" + txt_1;

   if(!csv && i == 0)
   {
    txt_2 = (AnsiString)Grid->ColWidths[j] + ";" + txt_2;
    if(j == 0)
    Lista->Add(txt_2);
   }
  }
  Lista->Add(txt_1);
  txt_1 = "";
 }

 Lista->SaveToFile(FileName);
 delete Lista;
}
//--------------------------------

// Plik Ÿród³owy np. Unit1.cpp
//--- FUNKCJA ODCZYTUJ¥CA LICZBÊ KOLUMN I WIERSZY ---------------------------
void SetColRow(AnsiString txt, TStringGrid *Grid)
{
 int t = txt.AnsiPos("\";");
 String txt_1 = txt.SubString(1, t);
 String txt_2 = txt.SubString(t + 2, 10);
 Grid->ColCount = txt_1.SubString(5, txt_1.Length() - 5).ToInt();
 Grid->RowCount = txt_2.SubString(5, txt_2.Length() - 5).ToInt();
}
//--- FUNKCJA PRZEPISUJ¥CA TEKST DO KOMÓREK I ODCZYUJ¥CA SZEROKOŒÆ KOLUMN ---
AnsiString SetCellText(AnsiString txt, AnsiString Wtxt, int &Size, int Col)
{
 String txt_1 = "", txt_2 = "";
 for(int i = -1; i < Col; i++)
 {
  int q = 0;
  int t = txt.AnsiPos(";\"");
  if(i >= 0)
   q = Wtxt.AnsiPos(";");
  txt_1 = txt.SubString(2, t - 3);
  if(i >= 0)
   txt_2 = Wtxt.SubString(1, q - 1);

  if(t > 0)
   txt = txt.Delete(1, t);
  else
   txt_1 = txt.SubString(2, txt.Length() - 2);

  if(i >= 0)
  {
   if(q > 0)
    Wtxt = Wtxt.Delete(1, q);
   else
    txt_2 = Wtxt.SubString(1, Wtxt.Length() - 1);
  }
 }
 Size = txt_2.ToInt();
 if(txt_1.SubString(txt_1.Length() - 1, txt_1.Length() + 1) == ";'")
  txt_1 = txt_1.Delete(txt_1.Length(), txt_1.Length() + 1);

 return txt_1;
}
//--- FUNKCJA ODCZYTUJ¥CA TABELÊ Z PLIKU ------------------------------------
void __fastcall TForm3::LoadGridFromFile(AnsiString FileName, TStringGrid *Grid)
{
 TStringList *Lista = new TStringList;
 Lista->LoadFromFile(FileName);
 SetColRow(Lista->Strings[0], Grid);

 for(int i = 0; i < Grid->RowCount; i++)
 {
  for(int j = 0; j < Grid->ColCount; j++)
  {
   int Size;
   Grid->Cells[j][i] = SetCellText(Lista->Strings[i + 2], Lista->Strings[1], Size, j + 1);
   Grid->ColWidths[j] = Size;
  }
 }
 delete Lista;
}
//---------------------------------------------------------------------------
   void __fastcall TForm3::BubbleSort1(TStringGrid *Tabela, int Col)
{
 AnsiString temp;
 for(int i = Tabela->FixedRows; i < Tabela->RowCount; i++)
 {
  for(int j = Tabela->FixedRows+1; j < i; j++)
  {
   if(Tabela->Cells[Col][i] < Tabela->Cells[Col][j])
   {

    temp = Tabela->Rows[i]->GetText();
    Tabela->Rows[i]->SetText(Tabela->Rows[j]->GetText());
    Tabela->Rows[j]->SetText(temp.c_str());
   }
  }
 }

}
//----------------------------------------------------------------------------
void __fastcall DeleteRow(TStringGrid *Grid, int ARow)
{
 if(ARow < Grid->FixedRows)
 {
  Application->MessageBox("Nie wybrano wiersza do usuniêcia", "Usuwanie wiersza", MB_OK | MB_ICONSTOP);
  return;
 }
 if(Grid->RowCount == Grid->FixedRows + 1)
 {
  int id = Application->MessageBox("Conajmniej jeden wiersz (nie licz¹c nag³ówka) musi pozostaæ w tabeli. "
           "Czy chcesz wyczyœciæ zawartoœæ komórek w tym wierszu?", "Usuwanie wiersza", MB_YESNO | MB_ICONQUESTION);
  if(id == ID_YES)
   for(int y = 0; y < Grid->ColCount; y++)
    Grid->Cells[y][ARow] = "";
  return;
 }

 int id = Application->MessageBox("Czy na pewno chcesz usun¹æ wybrany wiersz?\nOperacji nie bêdzie mo¿na cofn¹æ!",
          "Usuwanie wiersza", MB_YESNO | MB_ICONQUESTION);
 if(id == ID_YES)
 {
  for(int i = ARow; i <= Grid->RowCount - 1; i++)
  {
   for(int y = 0; y < Grid->ColCount; y++)
   {
    Grid->Cells[y][i] = Grid->Cells[y][i + 1];
    Grid->Cells[y][i + 1] = "";
   }
  }
  Grid->RowCount--;
 }
 Grid->SetFocus();
}

//---------------------------------------------------------------------------





void __fastcall TForm3::StringGrid1DblClick(TObject *Sender)
{

      licz++;
      if(licz==4)
      licz=1;

   if(licz==1)
   {
   if(StringGrid1->Row>0)
   {
     Form4->Edit2->Text= StringGrid1->Cells[0][StringGrid1->Row];
     Form3->Label4->Caption=StringGrid1->Cells[0][StringGrid1->Row];
     Form4->Kategorie("w");
     Form3->Visible=true;
   }
   if(StringGrid1->Row==0&&licz==1)
   {
   Application->MessageBox(("Nie wybrano kategorii!!! „"+Form4->Edit1->Text+"”").c_str(),
   "Wybierz kategoriê !!!", MB_OK | MB_ICONINFORMATION);
   licz=0;
   return;
    }
    }




}
//---------------------------------------------------------------------------


void __fastcall TForm3::StringGrid2DblClick(TObject *Sender)
{
    licz++;
    if(licz==4)
    licz=1;
    if(licz==2)
   {
   if(StringGrid2->Row>0)
   {
     Form4->Edit3->Text= StringGrid2->Cells[1][StringGrid2->Row];
     Form3->Label5->Caption=StringGrid2->Cells[1][StringGrid2->Row];
     Form4->Nazwy("w");
     Form3->Visible=true;
   }
   else
   {
    Application->MessageBox(("Nie wybrano nazwy elementu!!! „"+Form4->Edit1->Text+"”").c_str(),
   "Wybierz nazwê elementu !!!", MB_OK | MB_ICONINFORMATION);
   licz=1;
    }
   }


}
//---------------------------------------------------------------------------



void __fastcall TForm3::StringGrid3DblClick(TObject *Sender)
{

    licz++;
      if(licz==4)
      licz=0;

   Edit1->Text=StringGrid3->Cells[2][StringGrid3->Row];
                         Cells fc;
 fc = InGrid(Form2->StringGrid1, Edit1->Text);
 if(fc.Col < 0)
 {
  Application->MessageBox(("Nie mo¿na odnaleŸæ „" + Edit1->Text + "”").c_str(),
   "ZnajdŸ", MB_OK | MB_ICONINFORMATION);
  return;
 }
 Form2->StringGrid1->Col = fc.Col;
 Form2->StringGrid1->Row = fc.Row;
 Form2->StringGrid1->SetFocus();
 Form5->Show();
 
}

//---------------------------------------------------------------------------






