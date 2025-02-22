//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;

//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
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


void __fastcall TForm5::Button1Click(TObject *Sender)
{

         Form2->StringGrid1->RowCount = Form2->StringGrid1->RowCount+1; //dopisanie kategorii do Form2->StringGrid1 col[3]
         int lp = Form2->StringGrid1->RowCount-1;
         Form2->StringGrid1->Cells[0][lp] = Form4->Edit2->Text;

         Form2->StringGrid1->RowCount = Form2->StringGrid1->RowCount; //dopisanie nazwy do Form2->StringGrid1 col[3]
         int lp1 = Form2->StringGrid1->RowCount-1;
         Form2->StringGrid1->Cells[1][lp1] = Form4->Edit3->Text;

         Form2->StringGrid1->RowCount = Form2->StringGrid1->RowCount; //dopisanie symbolu do Form2->StringGrid1 col[3]
         int lp8 = Form2->StringGrid1->RowCount-1;
         Form2->StringGrid1->Cells[2][lp8] = Form4->Edit1->Text;


         if(Form3->StringGrid3->Enabled==true){
         if(Edit1->Text==""){   //dla zmie� ilosc
           Application->MessageBox(("Nie wpisano ilosci!!! �" + Edit1->Text + "�").c_str(),
           "Wpisz ilosc", MB_OK | MB_ICONINFORMATION);
           Edit1->Text="";
           return;
         }
         int stil=StrToInt(Edit2->Text);
         int noil=StrToInt(Edit1->Text);

         Form2->StringGrid1->RowCount = Form2->StringGrid1->RowCount; //dopisanie symbolu do Form2->StringGrid1 col[3]
         int lp2 = Form2->StringGrid1->RowCount-1;
         Form2->StringGrid1->Cells[2][lp2] = Form3->Edit1->Text;

         Form2->StringGrid1->RowCount = Form2->StringGrid1->RowCount; //dopisanie ilosci do Form2->StringGrid1 col[3]
         int lp3 = Form2->StringGrid1->RowCount-1;
         Form2->StringGrid1->Cells[3][lp3] = IntToStr(stil+noil);

         Form2->StringGrid1->RowCount = Form2->StringGrid1->RowCount; //dopisanie obrazka do Form2->StringGrid1 col[3]
         int lp4 = Form2->StringGrid1->RowCount-1;
         Form2->StringGrid1->Cells[4][lp4] = Form2->StringGrid1->Cells[4][Form2->StringGrid1->Row];

         Form2->StringGrid1->RowCount = Form2->StringGrid1->RowCount; //dopisanie schematu do Form2->StringGrid1 col[3]
         int lp5 = Form2->StringGrid1->RowCount-1;
         Form2->StringGrid1->Cells[5][lp5] = Form2->StringGrid1->Cells[5][Form2->StringGrid1->Row];

         Form2->StringGrid1->RowCount = Form2->StringGrid1->RowCount; //dopisanie specyfikacji do Form2->StringGrid1 col[3]
         int lp6 = Form2->StringGrid1->RowCount-1;
         Form2->StringGrid1->Cells[6][lp6] = Form2->StringGrid1->Cells[6][Form2->StringGrid1->Row];

         Form2->StringGrid1->RowCount = Form2->StringGrid1->RowCount; //dopisanie opisu do Form2->StringGrid1 col[3]
         int lp7 = Form2->StringGrid1->RowCount-1;
         Form2->StringGrid1->Cells[7][lp7] = Form2->StringGrid1->Cells[7][Form2->StringGrid1->Row];


         DeleteRow(Form2->StringGrid1, Form2->StringGrid1->Row);

         Form3->SaveGridToFile("ListaElementow.roz",(Form2->StringGrid1),false );

         Form4->Close();
         Form3->Close();
         Form5->Close();
         }
         else{
         if(Edit1->Text!=""){               //dla dodaj ilosc
         Form2->StringGrid1->RowCount = Form2->StringGrid1->RowCount; //dopisanie ilosci do Form2->StringGrid1 col[3]
         int lp3 = Form2->StringGrid1->RowCount-1;
         Form2->StringGrid1->Cells[3][lp3] = Edit1->Text;

         Form3->SaveGridToFile("ListaElementow.roz",(Form2->StringGrid1),false );

         Form4->Close();
         Form3->Close();
         Form5->Close();
         Form6->Show();
         }
         else {
          Application->MessageBox(("Nie wpisano ilosci!!! �" + Edit1->Text + "�").c_str(),
   "Wpisz ilosc", MB_OK | MB_ICONINFORMATION);
   Edit1->Text="";
   return;
         }
         }

         
}
//---------------------------------------------------------------------------






void __fastcall TForm5::Button2Click(TObject *Sender)
{
    if(Form2->StringGrid1->Row==0){
      Application->MessageBox("Nie wybrano elementu do edycji", "Edycja elementu", MB_OK | MB_ICONSTOP);
         return;
    }
    if(Form2->StringGrid1->Cells[4][Form2->StringGrid1->Row]!=" ")
    Form7-> Image1->Picture->LoadFromFile(Form2->StringGrid1->Cells[4][Form2->StringGrid1->Row]);
    if(Form2->StringGrid1->Cells[5][Form2->StringGrid1->Row]!=" "){
    Form7-> Image2->Picture->LoadFromFile(Form2->StringGrid1->Cells[5][Form2->StringGrid1->Row]);
    Form7->Image2->Visible=true;}

    if(Form2->StringGrid1->Cells[6][Form2->StringGrid1->Row]!=" ")
    Form7-> Memo1->Lines->LoadFromFile(Form2->StringGrid1->Cells[6][Form2->StringGrid1->Row]);
    else
    Form7-> Memo1->Lines->Text="Brak specyfikacji";
    if(Form2->StringGrid1->Cells[7][Form2->StringGrid1->Row]!=" "){
    Form7->Memo2->Lines-> LoadFromFile(Form2->StringGrid1->Cells[7][Form2->StringGrid1->Row]);
    Form7->Memo2->Visible=true;}
    else
    Form7-> Memo2->Lines->Text="Brak opisu";

    Form7->Edit1->Text=Form2->StringGrid1->Cells[3][Form2->StringGrid1->Row];
    Form7->Label2->Caption =Form2->StringGrid1->Cells[1][Form2->StringGrid1->Row]+" - "+Form2->StringGrid1->Cells[2][Form2->StringGrid1->Row] ;
    Form2->StringGrid1->Row=0;
    Form7->Show();
}
//---------------------------------------------------------------------------

