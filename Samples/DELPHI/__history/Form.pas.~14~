unit Form;

interface

uses
  System.SysUtils, System.Types, System.UITypes, System.Classes, System.Variants,
  FMX.Types, FMX.Controls, FMX.Forms, FMX.Graphics, FMX.Dialogs, FMX.Objects,
  FMX.Controls.Presentation, FMX.StdCtrls, FMX.ScrollBox, FMX.Memo,
  FMX.TabControl, FMX.Edit, FMX.MultiView;

type
  TForm1 = class(TForm)
    BtnAuthentication: TButton;
    BtnStampToken: TButton;
    MemoResult: TMemo;
    BtnStampOutToken: TButton;
    TbControl: TTabControl;
    TbItemAuthenticatio: TTabItem;
    TbItemStampV1: TTabItem;
    Text1: TText;
    Text2: TText;
    Text3: TText;
    TxtUrl: TEdit;
    TxtUser: TEdit;
    TxtPassword: TEdit;
    Text4: TText;
    Text5: TText;
    Text6: TText;
    TxtPasswordStamp: TEdit;
    TxtUrlStamp: TEdit;
    TxtUserStamp: TEdit;
    Text7: TText;
    TxtToken: TEdit;
    BtnOpenFile: TButton;
    TxtFilePath: TEdit;
    BtnClear: TButton;
    MemoResultStamp: TMemo;
    Button1: TButton;
    MemoXML: TMemo;
    procedure BtnAuthenticationClick(Sender: TObject);
    procedure BtnStampTokenClick(Sender: TObject);
    procedure BtnStampOutTokenClick(Sender: TObject);
    procedure BtnOpenFileClick(Sender: TObject);
    procedure BtnClearClick(Sender: TObject);
    procedure BtnClearStampClick(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
implementation

{$R *.fmx}
Function Authentication(url, user, password : PAnsiChar): PAnsiChar; stdcall; external 'sw-sdk-cpp.dll' name 'Authentication';
Function Stamp(url, user, password, xml : PAnsiChar): PAnsiChar; stdcall; external 'sw-sdk-cpp.dll' name 'Stamp';
Function StampByToken(url, token, xml : PAnsiChar): PAnsiChar; stdcall; external 'sw-sdk-cpp.dll' name 'StampByToken';

function GetToken(url, user, password : string) : String;
  var
    _url : PAnsiChar;
    _user : PAnsiChar;
    _password : PAnsiChar;
  begin
      _url:= PAnsiChar(AnsiString(url));
      _user:= PAnsiChar(AnsiString(user));
      _password := PAnsiChar(AnsiString(password));

      Result := Authentication(_url,_user,_password);
  end;

procedure TForm1.BtnAuthenticationClick(Sender: TObject);
  var
      result : string;
  begin
      with TbControl do
        result := GetToken(TxtUrl.Text, TxtUser.Text, TxtPassword.Text);
      MemoResult.Lines.Text := result;
  end;

procedure TForm1.BtnStampTokenClick(Sender: TObject);
  var
    result : PAnsiChar;
    _url : PAnsiChar;
    _token : PAnsiChar;
    _Xml : PAnsiChar;
  begin
    with TbControl do
      _url := PAnsiChar(AnsiString(TxtUrlStamp.Text));
      _token := PAnsiChar(AnsiString(TxtToken.Text));
      _Xml := PAnsiChar(AnsiString(MemoXML.Text));

    if (_url <> '') And (_token <> '' ) And (_Xml <> '')
      then
        begin
          result := StampByToken(_url,_token, _Xml);

          MemoResultStamp.Lines.Text := result;
        end
    else
        ShowMessage('Los campos Url, Token y la Ruta del XML deben estar llenos antes de timbrar');
  end;

procedure TForm1.BtnStampOutTokenClick(Sender: TObject);
  var
    result : PAnsiChar;
    _url : PAnsiChar;
    _user : PAnsiChar;
    _password : PAnsiChar;
    _token : PAnsiChar;
    _Xml : PAnsiChar;
  begin
    with TbControl do
      _url := PAnsiChar(AnsiString(TxtUrlStamp.Text));
      _user := PAnsiChar(AnsiString(TxtUserStamp.Text));
      _password := PAnsiChar(AnsiString(TxtPassword.Text));
      _Xml := PAnsiChar(AnsiString(MemoXML.Text));
    if (_url <> '') And (_user <> '' ) And (_password <> '') And (_Xml <> '')
      then
        begin
          result := Stamp(_url,_user, _password, _Xml);

          MemoResultStamp.Lines.Text := result;
        end
    else
      ShowMessage('Los campos Url, Usuario, Contraseña y la Ruta del XML deben estar llenos antes de timbrar');
  end;

procedure TForm1.BtnOpenFileClick(Sender: TObject);
  var
    openDialog : topendialog;
    path : string;
    myXMLFile : TextFile;
    strTemp : string;
    xmlString : string;
    _PxmlString : PAnsiChar;
  begin
    openDialog := TOpenDialog.Create(self);

    openDialog.InitialDir := GetCurrentDir;

    openDialog.Filter :=
      'Archivos XML|*.xml';

    openDialog.FilterIndex := 2;

    if openDialog.Execute
      then
        with TbControl do
          TxtFilePath.Text := openDialog.FileName;

    openDialog.Free;
    path :=  PAnsiChar(AnsiString(TxtFilePath.Text));
    AssignFile(myXMLFile, path);
    Reset(myXMLFile);
    while not Eof(myXMLFile) do
       begin
         ReadLn(myXMLFile, strTemp);
         xmlString := Concat(xmlString, strTemp);
       end;
    CloseFile(myXMLFile);

    _PxmlString := PAnsiChar(AnsiString(xmlString));
    with TbControl do
      MemoXML.Text := _PxmlString;

  end;
procedure TForm1.BtnClearClick(Sender: TObject);
  begin
    MemoResult.Text := '';
  end;

procedure TForm1.BtnClearStampClick(Sender: TObject);
  begin
    with TbControl do
      MemoXML.Text := '';
      MemoResultStamp.Text := '';
      TxtFilePath.Text := '';
  end;
end.
