//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TButton *Button1;
	TLabel *Label4;
	TEdit *Edit3;
	TTimer *Timer1;
	TButton *Button2;
	TMemo *Memo1;
	void __fastcall N2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
		void __fastcall clk(TObject *Sender, TMouseButton Button, TShiftState Shift,
							int X, int Y);
		void start();
		void bomb();
		void restart();
		void recursion();
		void one();
		void two();
		void three();
		void four();
		void five();
		void six();
		void seven();
		void eight();
		void open();
		void good(int);
		void ok();
		void FirstRound(int);//先展開第一圈
		void GameOver();
        void cheat();

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
