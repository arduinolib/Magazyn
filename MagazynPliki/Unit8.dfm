object Form8: TForm8
  Left = 192
  Top = 125
  Width = 1153
  Height = 584
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
  object Label1: TLabel
    Left = 24
    Top = 8
    Width = 217
    Height = 24
    Caption = 'Dodawanie spesyfikacji'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Memo1: TMemo
    Left = 360
    Top = 48
    Width = 753
    Height = 409
    Color = clMoneyGreen
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
    OnClick = Memo1Click
  end
  object Button1: TButton
    Left = 16
    Top = 464
    Width = 185
    Height = 25
    Caption = 'Dodaj adres specyfikacji'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 360
    Top = 464
    Width = 281
    Height = 25
    Caption = 'Dodaj specyfikacj'#281' do elementu'
    TabOrder = 2
    OnClick = Button2Click
  end
  object StringGrid1: TStringGrid
    Left = 16
    Top = 48
    Width = 337
    Height = 409
    Color = clMoneyGreen
    ColCount = 1
    DefaultColWidth = 380
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
    TabOrder = 3
  end
  object Edit1: TEdit
    Left = 208
    Top = 464
    Width = 145
    Height = 24
    Color = clMoneyGreen
    TabOrder = 4
  end
  object Button3: TButton
    Left = 16
    Top = 464
    Width = 185
    Height = 25
    Caption = 'Dodaj adres opisu'
    TabOrder = 5
    OnClick = Button3Click
  end
  object Edit2: TEdit
    Left = 208
    Top = 464
    Width = 145
    Height = 24
    Color = clMoneyGreen
    TabOrder = 6
  end
  object Button4: TButton
    Left = 360
    Top = 464
    Width = 281
    Height = 25
    Caption = 'Dodaj opis do elementu'
    TabOrder = 7
    OnClick = Button4Click
  end
  object Memo2: TMemo
    Left = 360
    Top = 48
    Width = 753
    Height = 393
    Color = clMoneyGreen
    Lines.Strings = (
      'Memo2')
    TabOrder = 8
    Visible = False
    OnClick = Memo2Click
  end
  object StringGrid2: TStringGrid
    Left = 16
    Top = 48
    Width = 337
    Height = 377
    Color = clMoneyGreen
    ColCount = 1
    DefaultColWidth = 380
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
    TabOrder = 9
    Visible = False
  end
  object OpenDialog1: TOpenDialog
    Options = [ofHideReadOnly, ofNoChangeDir, ofEnableSizing]
    Left = 1000
    Top = 488
  end
end
