object Form5: TForm5
  Left = 309
  Top = 293
  Width = 371
  Height = 252
  Caption = 'KATALOG ELEKTRONIKI'
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clBlack
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = [fsBold]
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 8
    Top = 120
    Width = 252
    Height = 16
    Caption = 'Podaj ilosc  dodawanych element'#243'w'
  end
  object Label2: TLabel
    Left = 8
    Top = 56
    Width = 125
    Height = 16
    Caption = 'Stan w magazynie'
  end
  object Label3: TLabel
    Left = 8
    Top = 16
    Width = 224
    Height = 20
    Caption = 'Zmiana stanu w magazynie'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 8
    Top = 136
    Width = 249
    Height = 24
    Color = clMoneyGreen
    TabOrder = 0
  end
  object Button1: TButton
    Left = 48
    Top = 168
    Width = 75
    Height = 25
    Caption = 'Zapisz'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 8
    Top = 72
    Width = 249
    Height = 24
    Color = clMoneyGreen
    TabOrder = 2
  end
  object Button2: TButton
    Left = 184
    Top = 168
    Width = 75
    Height = 25
    Caption = 'Edytuj'
    TabOrder = 3
    OnClick = Button2Click
  end
end
