object Form3: TForm3
  Left = 183
  Top = 29
  Width = 425
  Height = 668
  VertScrollBar.ParentColor = False
  VertScrollBar.Tracking = True
  VertScrollBar.Visible = False
  Caption = 'KATALOG ELEKTRONIKI'
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = [fsBold]
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 16
    Top = 80
    Width = 241
    Height = 20
    Caption = 'Wybierz lub dopisz kategori'#281
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 8
    Width = 87
    Height = 20
    Caption = 'Kategoria:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 40
    Width = 83
    Height = 20
    Caption = 'Nazwa el:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 104
    Top = 8
    Width = 6
    Height = 20
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 104
    Top = 40
    Width = 6
    Height = 20
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 104
    Width = 385
    Height = 489
    Color = clMoneyGreen
    ColCount = 1
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
    TabOrder = 0
    OnDblClick = StringGrid1DblClick
  end
  object StringGrid2: TStringGrid
    Left = 8
    Top = 104
    Width = 385
    Height = 489
    Color = clMoneyGreen
    ColCount = 2
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
    TabOrder = 1
    Visible = False
    OnDblClick = StringGrid2DblClick
  end
  object StringGrid3: TStringGrid
    Left = 8
    Top = 104
    Width = 385
    Height = 489
    Color = clMoneyGreen
    ColCount = 3
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect]
    TabOrder = 2
    Visible = False
    OnDblClick = StringGrid3DblClick
  end
  object Edit1: TEdit
    Left = 272
    Top = 16
    Width = 121
    Height = 24
    Color = clMoneyGreen
    TabOrder = 3
    Visible = False
  end
  object MainMenu1: TMainMenu
    Left = 232
    Top = 496
    object Dodajnow1: TMenuItem
      Caption = 'Dodaj now'#261' kategori'#281
      OnClick = Dodajnow1Click
    end
  end
end
