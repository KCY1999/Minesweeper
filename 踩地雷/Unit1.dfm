object Form1: TForm1
  Left = 0
  Top = 185
  Caption = 'Form1'
  ClientHeight = 580
  ClientWidth = 1004
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 781
    Top = 211
    Width = 42
    Height = 25
    Caption = #38263#23532
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 781
    Top = 479
    Width = 21
    Height = 25
    Caption = #23532
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label3: TLabel
    Left = 904
    Top = 120
    Width = 20
    Height = 45
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -37
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 781
    Top = 265
    Width = 42
    Height = 25
    Caption = #28856#24392
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 845
    Top = 486
    Width = 121
    Height = 21
    TabOrder = 0
    Visible = False
  end
  object Edit2: TEdit
    Left = 845
    Top = 218
    Width = 121
    Height = 21
    TabOrder = 1
  end
  object Button1: TButton
    Left = 781
    Top = 336
    Width = 75
    Height = 25
    Caption = #38283#22987
    Enabled = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit3: TEdit
    Left = 845
    Top = 269
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object Button2: TButton
    Left = 891
    Top = 336
    Width = 75
    Height = 25
    Caption = #37325#26032
    TabOrder = 4
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 597
    Top = 192
    Width = 156
    Height = 177
    TabOrder = 5
  end
  object MainMenu1: TMainMenu
    Left = 688
    Top = 144
    object N1: TMenuItem
      Caption = 'Play'
      object N2: TMenuItem
        Caption = #36938#25138#35498#26126
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object N4: TMenuItem
        Caption = #21021#32026
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = #20013#32026
        OnClick = N5Click
      end
      object N6: TMenuItem
        Caption = #39640#32026
        OnClick = N6Click
      end
    end
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 624
    Top = 144
  end
end
