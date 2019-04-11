//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TButton *Button1;
        TEdit *Edit1;
        TLabel *Label1;
        TImage *Image2;
        TLabel *Label2;
        TMemo *Memo1;
        TMemo *Memo2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall Memo2Click(TObject *Sender);
        void __fastcall Memo1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm7(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
