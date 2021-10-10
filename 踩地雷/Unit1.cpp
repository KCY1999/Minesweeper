//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#define v 99
#define h 99
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

TButton *btn[v][h];
int ov=0,around=0;
int btt[v][h];//存btn
int vp=v, hp=h, bb=0, bnum=0, x=-1, tm=0;//長,寬,雷,雷數,hint值,時間
int p1,p2,p3,p4,p5,p6,p7,p8;//左上,上,右上,左,右,左下,下,右下
bool Gover=false;//判斷遊戲是否結束
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//開始
void TForm1::start()
{
	x=-1;//bnum = 0;
	for(int i=0;i<vp;i++)
	{
		for(int j=0;j<hp;j++)
		{
			if(btn[i][j]!=NULL)
			{
				return;
			}
			x++;
			btn[i][j]=new TButton(this);
			btn[i][j]->Top=(i*30);
			btn[i][j]->Left=(j*30);
			btn[i][j]->Tag=0;
			btn[i][j]->OnMouseDown=clk;
			btn[i][j]->Height=30;
			btn[i][j]->Width=30;
			btn[i][j]->Parent=this;
			btn[i][j]->Hint = x;
			//btn[i][j]->Caption = btn[i][j]->Hint;
		}
	}
}
void __fastcall TForm1::N2Click(TObject *Sender)
{
    ShowMessage("幾歲了還看說明");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Button1->Enabled = false;
	Button2->Enabled = true;
	Memo1->Clear();
	try
	{
		vp = StrToInt(Edit2->Text.ToInt());
		hp = StrToInt(Edit2->Text.ToInt());
		bb = StrToInt(Edit3->Text.ToInt());

		if(vp<25 && hp<25 && bb < (vp-1)*(hp-1))
		{
			start();
			bomb();
            cheat();
		}
		else
		{
			ShowMessage("炸彈數過多,最多為(長-1)×(寬-1)or長寬有誤,最大長寬為24x30");
			return;
		}
	}
	catch(...)
	{
		ShowMessage("請輸入正確的長寬&炸彈數");
		return;
	}
}
//---------------------------------------------------------------------------
//初級
void __fastcall TForm1::N4Click(TObject *Sender)
{
	Timer1->Enabled = false;
	tm = 0;
    Memo1->Clear();
	for(int i=0;i<vp;i++)
	{
		for(int j=0;j<hp;j++)
		{
			if(btn[i][j]==NULL)
			{
				start();
				return;
			}
			delete btn[i][j];
			btn[i][j]=NULL;
		}
	}
	vp = 9;hp = 9;
	bb=10;
	start();
	bomb();
	Timer1->Enabled = true;
    cheat();
}
//---------------------------------------------------------------------------
//中級
void __fastcall TForm1::N5Click(TObject *Sender)
{
	Timer1->Enabled = false;
	tm = 0;
	Memo1->Clear();
	for(int i=0;i<vp;i++)
	{
		for(int j=0;j<hp;j++)
		{
			if(btn[i][j]==NULL)
			{
				start();
				return;
			}
			delete btn[i][j];
			btn[i][j]=NULL;
		}
	}
	vp = 16;hp = 16;
	bb=40;
	start();
	bomb();
	Timer1->Enabled = true;
    cheat();
}
//---------------------------------------------------------------------------
//高級
void __fastcall TForm1::N6Click(TObject *Sender)
{
	Timer1->Enabled = false;
	tm = 0;
	Memo1->Clear();
	for(int i=0;i<vp;i++)
	{
		for(int j=0;j<hp;j++)
		{
			if(btn[i][j]==NULL)
			{
				start();
				return;
			}
			delete btn[i][j];
			btn[i][j]=NULL;
		}
	}
	vp = 20;hp = 20;
	bb=99;
	start();
	bomb();
	Timer1->Enabled = true;
    cheat();
}
//---------------------------------------------------------------------------
//初始狀態
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	time_t t;
	srand((unsigned)time(&t));
	vp = 9;hp = 9;
    bb = 10;
	start();
	bomb();
	cheat();
}
//---------------------------------------------------------------------------
//設置炸彈
void TForm1::bomb()
{
	int b1,b2;

	for(int i=0;i<bb;i++)
	{
		b1=(rand()%(vp));
		b2=(rand()%(hp));
        //btn[b1][b2]->Caption="*";
		btn[b1][b2]->Tag=99;
	}
	for(int i=0;i<vp;i++)
	{
		for(int j=0;j<hp;j++)
		{

            if(btn[i][j]->Tag != 99)
			{
				good(StrToInt(btn[i][j]->Hint));
				bnum = 0;
				one();two();three();four();
				five();six();seven();eight();

				btn[i][j]->Tag = bnum;
			}
        }
	}
}
//---------------------------------------------------------------------------
//左右點擊
void __fastcall TForm1::clk(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
    //cheat();
	TButton *btnn;
	btnn=(TButton *)Sender;

	if(!Timer1->Enabled)
	{
		Timer1->Enabled = true;
	}
	good(StrToInt(btnn->Hint));

	if(Shift.Contains(ssLeft)) //左鍵
	{
		if(btnn->Tag != 66 && btnn->Caption != "X")
		{
        	btnn->Enabled=false;
			if(btnn->Tag == 99)
			{
				for(int i=0;i<vp;i++)
				{
					for(int j=0;j<hp;j++)
					{
                        btn[i][j]->Enabled = false;
                    }
                }
				ShowMessage("GAME OVER");
			}
			else if(btnn->Tag != 99)
			{
				if(btnn->Tag == 0)
				{
					FirstRound(StrToInt(btnn->Hint));
					recursion();
					btnn->Caption = btnn->Tag;
				}
				else if(btnn->Tag != 0)
				{
					btnn->Caption = btnn->Tag;
				}
			}
		}
	}

	if(Shift.Contains(ssRight)) //右鍵
	{
		if(btnn->Caption != "X")
		{
			btnn->Caption = "X";
		}
		else
		{
			btnn->Caption = "";
		}

	}
	GameOver();
}
//---------------------------------------------------------------------------
//初始化
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Timer1->Enabled = false;
	tm = 0;
	Label3->Caption = IntToStr(tm);

	Button1->Enabled = true;
    bb = 0;
	for(int i=0;i<vp;i++)
	{
		for(int j=0;j<hp;j++)
		{
			if(btn[i][j]==NULL)
			{
                ShowMessage("請按開始");
				return;
			}
			delete btn[i][j];
			btn[i][j]=NULL;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	tm++;
	Label3->Caption = IntToStr(tm);
}
//------------------------------------------------------------------------------
//炸彈判斷
//左上
void TForm1::one()
{
	if(p1%hp == hp-1 || p1 < 0)
	{
		return;
	}
	else if(btn[p1/hp][p1%hp]->Tag == 99)
	{
		bnum+=1;
	}
}
//上
void TForm1::two()
{
	if(p2<0)
	{
		return;
	}
	else if(btn[p2/hp][p2%hp]->Tag == 99)
	{
		bnum+=1;
	}
}
//右上
void TForm1::three()
{
	if(p3 < 0 || p3 % hp == 0)
	{
		return;
	}
	else if(btn[p3/hp][p3%hp]->Tag == 99)
	{
		bnum+=1;
	}
}
//左
void TForm1::four()
{
	if(p4<0 || p4%hp == (hp-1))
	{
		return;
	}
	else if(btn[p4/hp][p4%hp]->Tag == 99)
	{
		bnum+=1;
	}
}
//右
void TForm1::five()
{
	if(p5%hp==0)
	{
		return;
	}
	else if(btn[p5/hp][p5%hp]->Tag == 99)
	{
		bnum+=1;
	}
}
//左下
void TForm1::six()
{
	if(p6%hp == hp-1 || p6>=hp*vp)
	{
		return;
	}
	else if(btn[p6/hp][p6%hp]->Tag == 99)
	{
		bnum+=1;
	}
}
//下
void TForm1::seven()
{
	if(p7>=hp*vp)
	{
		return;
	}
	else if(btn[p7/hp][p7%hp]->Tag == 99)
	{
		bnum+=1;
	}
}
//右下
void TForm1::eight()
{
	if(p8%hp == 0 || p8>=hp*vp)
	{
		return;
	}
	else if(btn[p8/hp][p8%hp]->Tag == 99)
	{
		bnum+=1;
	}
}
//------------------------------------------------------------------------------
//遞迴
void TForm1::recursion()
{
	ov = 0;
	around=0;
	for(int i=0;i<vp;i++)
	{
		for(int j=0;j<hp;j++)
		{
			around=0;//是否還有未打開的

			if(btn[i][j]->Enabled == false)
			{
				good(StrToInt(btn[i][j]->Hint));
				ok();
			}

			if((btn[i][j]->Enabled == false && btn[i][j]->Tag == 0)&&around==1)
			{
				ov = 1;
				open();
			}
		}
	}
	if(ov == 1)
	  recursion();
}
//------------------------------------------------------------------------------
void TForm1:: FirstRound(int bttp)
{
	if((bttp/hp)-1>=0&&(bttp%hp)-1>=0)//左上
	{
		btn[(bttp/hp)-1][bttp%hp-1]->Enabled=false;
		btn[(bttp/hp)-1][bttp%hp-1]->Caption=IntToStr(btn[(bttp/hp)-1][bttp%hp-1]->Tag);
	}
	if((bttp/hp)>=0&&(bttp%hp)-1>=0) //上
	{
		btn[(bttp/hp)][bttp%hp-1]->Enabled=false;
		btn[(bttp/hp)][bttp%hp-1]->Caption=IntToStr(btn[(bttp/hp)][bttp%hp-1]->Tag);
	}
	if((bttp/hp)+1<hp&&(bttp%hp)-1>=0)//右上
	{
		btn[(bttp/hp)+1][bttp%hp-1]->Enabled=false;
		btn[(bttp/hp)+1][bttp%hp-1]->Caption=IntToStr(btn[(bttp/hp)+1][bttp%hp-1]->Tag);
	}
	if((bttp/hp)-1>=0&&(bttp%hp)>=0)//左
	{
		btn[(bttp/hp)-1][bttp%hp]->Enabled=false;
		btn[(bttp/hp)-1][bttp%hp]->Caption=IntToStr(btn[(bttp/hp)-1][bttp%hp]->Tag);
	}
	if((bttp/hp)+1<hp&&(bttp%hp)>=0) //右
	{
		btn[(bttp/hp)+1][bttp%hp]->Enabled=false;
		btn[(bttp/hp)+1][bttp%hp]->Caption=IntToStr(btn[(bttp/hp)+1][bttp%hp]->Tag);
	}
	if((bttp/hp)-1>=0&&(bttp%hp)+1<vp)//左下
	{
		btn[(bttp/hp)-1][bttp%hp+1]->Enabled=false;
		btn[(bttp/hp)-1][bttp%hp+1]->Caption=IntToStr(btn[(bttp/hp)-1][bttp%hp+1]->Tag);
	}
	if((bttp/hp)>=0&&(bttp%hp)+1<vp)// 下
	{
		btn[(bttp/hp)][bttp%hp+1]->Enabled=false;
		btn[(bttp/hp)][bttp%hp+1]->Caption=IntToStr(btn[(bttp/hp)][bttp%hp+1]->Tag);
	}
	if((bttp/hp)+1<hp&&(bttp%hp)+1<vp)//右下
	{
		btn[(bttp/hp)+1][bttp%hp+1]->Enabled=false;
		btn[(bttp/hp)+1][bttp%hp+1]->Caption=IntToStr(btn[(bttp/hp)+1][bttp%hp+1]->Tag);
	}
}
//------------------------------------------------------------------------------
//判斷超出邊界
void TForm1::ok()
{
	if(p1%hp == hp-1 || p1 < 0)  //左上
	{
		//return;
	}
	else if(btn[p1/hp][p1%hp]->Enabled == true)
	{
		around=1;
	}

	if(p2<0)//上
	{
		//return;
	}
	else if(btn[p2/hp][p2%hp]->Enabled == true)
	{
		around=1;
	}

	if(p3 < 0 || p3 % hp == 0)//右上
	{
		//return;
	}
	else	if(btn[p3/hp][p3%hp]->Enabled == true)
	{
		around=1;
	}

	if(p4<0 || p4%hp == (hp-1))//左
	{
		//return;
	}
	else if(btn[p4/hp][p4%hp]->Enabled == true)
	{
		around=1;
	}

	if(p5%hp==0)//右
	{
		//return;
	}
	else if(btn[p5/hp][p5%hp]->Enabled == true)
	{
		around=1;
	}

	if(p6%hp == hp-1 || p6>=hp*vp)//左下
	{
		//return;
	}
	else if(btn[p6/hp][p6%hp]->Enabled == true)
	{
		around=1;
	}

	if(p7>=hp*vp) //下
	{
		//return;
	}
	else if(btn[p7/hp][p7%hp]->Enabled == true)
	{
		around=1;
	}

	if(p8%hp == 0 || p8>=hp*vp) //右下
	{
		//return;
	}
	else if(btn[p8/hp][p8%hp]->Enabled == true)
	{
		around=1;
	}
}
//------------------------------------------------------------------------------
//展開
void TForm1::open()
{
	if(p1%hp == hp-1 || p1 < 0)
	{
		//return;
	}
	else
	{
		btn[p1/hp][p1%hp]->Enabled = false;
		btn[p1/hp][p1%hp]->Caption = btn[p1/hp][p1%hp]->Tag;
	}
	if(p2<0)
	{
		//return;
	}
	else
	{
		btn[p2/hp][p2%hp]->Enabled = false;
		btn[p2/hp][p2%hp]->Caption = btn[p2/hp][p2%hp]->Tag;
	}
	if(p3 < 0 || p3 % hp == 0)
	{
		//return;
	}
	else
	{
		btn[p3/hp][p3%hp]->Enabled = false;
		btn[p3/hp][p3%hp]->Caption = btn[p3/hp][p3%hp]->Tag;
	}
	if(p4<0 || p4%hp == (hp-1))
	{
		//return;
	}
	else
	{
		btn[p4/hp][p4%hp]->Enabled = false;
		btn[p4/hp][p4%hp]->Caption = btn[p4/hp][p4%hp]->Tag;
	}
	if(p5%hp==0)
	{
		//return;
	}
	else
	{
		btn[p5/hp][p5%hp]->Enabled = false;
		btn[p5/hp][p5%hp]->Caption = btn[p5/hp][p5%hp]->Tag;
	}
	if(p6%hp == hp-1 || p6>=hp*vp)
	{
		//return;
	}
	else
	{
		btn[p6/hp][p6%hp]->Enabled = false;
		btn[p6/hp][p6%hp]->Caption = btn[p6/hp][p6%hp]->Tag;
	}
	if(p7>=hp*vp)
	{
		//return;
	}
	else
	{
		btn[p7/hp][p7%hp]->Enabled = false;
		btn[p7/hp][p7%hp]->Caption = btn[p7/hp][p7%hp]->Tag;
	}
	if(p8%hp == 0 || p8>=hp*vp)
	{
		//return;
	}
	else
	{
		btn[p8/hp][p8%hp]->Enabled = false;
		btn[p8/hp][p8%hp]->Caption = btn[p8/hp][p8%hp]->Tag;
	}
}
//------------------------------------------------------------------------------
//計算位置
void TForm1::good(int nb)
{
	p1=(nb*1)-(hp+1); p2=(nb*1)-hp; p3=(nb*1)-(hp-1);
	p4=(nb*1)-1; p5=(nb*1)+1;
	p6=(nb*1)+(hp-1); p7=(nb*1)+hp; p8=(nb*1)+(hp+1);
}
//判斷結束
void TForm1::GameOver()
{
	int a=0;
	for(int i=0;i<vp;i++)
	{
		for(int j=0;j<hp;j++)
		{
			if(btn[i][j]->Tag==99&&btn[i][j]->Caption=="X")
			{
				//炸彈已標期
				a+=1;
			}

			if(btn[i][j]->Tag!=99&&btn[i][j]->Enabled==false)
			{
				//打開的
                a+=1;
			}

        }
	}
	if(a==vp*hp)
	{
        ShowMessage("Game Over");
	}
}
//------------------------------------------------------------------------------
//作弊
void TForm1::cheat()
{
	String str = "";
	for(int i = 0; i < vp; i++)
	{
		for(int j = 0; j < hp; j++)
		{
			if(IntToStr(btn[i][j]->Tag) == "0")
			str += " 0";
		else if(IntToStr(btn[i][j]->Tag) == "99")
			str += " X";
		else
			str += " " + IntToStr(btn[i][j]->Tag);
		}
			str += "\r\n";
	}
	Memo1->Lines->Add(str);
}
