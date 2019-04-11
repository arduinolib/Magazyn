//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TMainMenu *MainMenu1;
        TStringGrid *StringGrid1;
        TMenuItem *Dodajnow1;
        TStringGrid *StringGrid2;
        TStringGrid *StringGrid3;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *Edit1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Dodajnow1Click(TObject *Sender);
        void __fastcall StringGrid1DblClick(TObject *Sender);
        void __fastcall StringGrid2DblClick(TObject *Sender);
        void __fastcall StringGrid3DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
        void __fastcall TForm3::SaveGridToFile(AnsiString FileName, TStringGrid *Grid,
        bool csv);
        void __fastcall TForm3::LoadGridFromFile(AnsiString FileName, TStringGrid *Grid);
        void __fastcall TForm3::BubbleSort1(TStringGrid *Tabela, int Col);
       
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
