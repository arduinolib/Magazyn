object Form6: TForm6
  Left = 192
  Top = 125
  Width = 928
  Height = 494
  Caption = 'KATALOG ELEKTRONIKI'
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = [fsBold]
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 16
  object Image1: TImage
    Left = 432
    Top = 40
    Width = 441
    Height = 329
    Stretch = True
    OnClick = Image1Click
  end
  object Image2: TImage
    Left = 432
    Top = 40
    Width = 425
    Height = 313
    Stretch = True
    Visible = False
    OnClick = Image2Click
  end
  object Label1: TLabel
    Left = 56
    Top = 8
    Width = 184
    Height = 24
    Caption = 'Dodawanie obrazka'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StringGrid1: TStringGrid
    Left = 56
    Top = 40
    Width = 345
    Height = 329
    Color = clMoneyGreen
    ColCount = 1
    DefaultColWidth = 380
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
    TabOrder = 0
  end
  object Button1: TButton
    Left = 56
    Top = 376
    Width = 225
    Height = 25
    Caption = 'Dodaj adres obrazka do listy'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 288
    Top = 376
    Width = 113
    Height = 24
    Color = clMoneyGreen
    TabOrder = 2
  end
  object Button3: TButton
    Left = 432
    Top = 376
    Width = 217
    Height = 25
    Caption = ' Dodaj obrazek do elementu'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button2: TButton
    Left = 56
    Top = 400
    Width = 225
    Height = 25
    Caption = 'Dodaj adres schematu do listy'
    TabOrder = 4
    Visible = False
    OnClick = Button2Click
  end
  object Edit2: TEdit
    Left = 288
    Top = 400
    Width = 113
    Height = 24
    Color = clMoneyGreen
    TabOrder = 5
    Visible = False
  end
  object Button4: TButton
    Left = 432
    Top = 400
    Width = 217
    Height = 25
    Caption = 'Dodaj schemat do elementu'
    TabOrder = 6
    Visible = False
    OnClick = Button4Click
  end
  object StringGrid2: TStringGrid
    Left = 56
    Top = 40
    Width = 345
    Height = 305
    Color = clMoneyGreen
    ColCount = 1
    DefaultColWidth = 380
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
    TabOrder = 7
    Visible = False
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Options = [ofNoChangeDir]
    Left = 856
    Top = 408
  end
end
