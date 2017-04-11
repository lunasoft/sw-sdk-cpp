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
    procedure BtnAuthenticationClick(Sender: TObject);
    procedure BtnStampTokenClick(Sender: TObject);
    procedure BtnStampOutTokenClick(Sender: TObject);
    procedure BtnOpenFileClick(Sender: TObject);
    procedure BtnClearClick(Sender: TObject);
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

function StringToPAnsiChar(stringVar : string) : PAnsiChar;
  Var
    AnsString : AnsiString;
    InternalError : Boolean;
  begin
    InternalError := false;
    Result := '';
    try
      if stringVar <> '' Then
      begin
         AnsString := AnsiString(StringVar);
         Result := PAnsiChar(PAnsiString(AnsString));
      end;
    Except
      InternalError := true;
    end;
    if InternalError or (String(Result) <> stringVar) then
    begin
      Raise Exception.Create('Conversion from string to PAnsiChar failed!');
    end;
  end;

function GetToken(url, user, password : string) : String;
  var
    _url : PAnsiChar;
    _user : PAnsiChar;
    _password : PAnsiChar;
  begin
      _url:= StringToPAnsiChar(url);
      _user:= StringToPAnsiChar(user);
      _password := StringToPAnsiChar(password);

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
    path : string;
    myXMLFile : TextFile;
    xmlString : string;
    strTemp : string;
    result : PAnsiChar;
    _url : PAnsiChar;
    _PxmlString : PAnsiChar;
    _token : PAnsiChar;
  begin
    with TbControl do
      path :=  StringToPAnsiChar(TxtFilePath.Text);
      _url := StringToPAnsiChar(TxtUrlStamp.Text);
      _token := StringToPAnsiChar(TxtToken.Text);

    if (_url <> '') And (_token <> '' ) And (path <> '')
      then
        begin
          AssignFile(myXMLFile, path);
          Reset(myXMLFile);
          while not Eof(myXMLFile) do
             begin
               ReadLn(myXMLFile, strTemp);
               xmlString := Concat(xmlString, strTemp);
             end;
          CloseFile(myXMLFile);

          _PxmlString := StringToPAnsiChar(xmlString);

          result := StampByToken(_url,_token, _PxmlString);

          MemoResult.Lines.Text := result;
        end
    else
        ShowMessage('Los campos Url, Token y la Ruta del XML deben estar llenos antes de timbrar');
  end;

procedure TForm1.BtnStampOutTokenClick(Sender: TObject);
  var
    path : string;
    myXMLFile : TextFile;
    xmlString : string;
    strTemp : string;
    result : PAnsiChar;
    _url : PAnsiChar;
    _user : PAnsiChar;
    _password : PAnsiChar;
    _PxmlString : PAnsiChar;
    _token : PAnsiChar;
  begin
    with TbControl do
      path :=  StringToPAnsiChar(TxtFilePath.Text);
      _url := StringToPAnsiChar(TxtUrlStamp.Text);
      _user := StringToPAnsiChar(TxtUserStamp.Text);
      _password := StringToPAnsiChar(TxtPassword.Text);
    if (_url <> '') And (_user <> '' ) And (_password <> '') And (path <> '')
      then
        begin
          AssignFile(myXMLFile, path);
          Reset(myXMLFile);
          while not Eof(myXMLFile) do
             begin
               ReadLn(myXMLFile, strTemp);
               xmlString := Concat(xmlString, strTemp);
             end;
          CloseFile(myXMLFile);

          _PxmlString := StringToPAnsiChar(xmlString);

          result := Stamp(_url,_user, _password, _PxmlString);

          MemoResult.Lines.Text := result;
        end
    else
      ShowMessage('Los campos Url, Usuario, Contraseña y la Ruta del XML deben estar llenos antes de timbrar');
  end;

procedure TForm1.BtnOpenFileClick(Sender: TObject);
  var
    openDialog : topendialog;
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
  end;
procedure TForm1.BtnClearClick(Sender: TObject);
  begin
    MemoResult.Text := '';
  end;
end.
