object Form4: TForm4
  Left = 181
  Top = 317
  Width = 338
  Height = 157
  Caption = 'KATALOG ELEKTRONIKI'
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = [fsBold]
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 40
    Top = 16
    Width = 110
    Height = 16
    Caption = 'Nowa kategoria'
  end
  object Edit1: TEdit
    Left = 16
    Top = 32
    Width = 289
    Height = 24
    Color = clMoneyGreen
    TabOrder = 0
  end
  object Button1: TButton
    Left = 24
    Top = 72
    Width = 75
    Height = 25
    Caption = 'Dodaj'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 184
    Top = 0
    Width = 121
    Height = 24
    TabOrder = 2
    Visible = False
  end
  object Edit3: TEdit
    Left = 184
    Top = 64
    Width = 121
    Height = 24
    TabOrder = 3
    Visible = False
  end
end
