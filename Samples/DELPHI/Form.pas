unit Form;

interface

uses
  System.SysUtils, System.Types, System.UITypes, System.Classes, System.Variants,
  FMX.Types, FMX.Controls, FMX.Forms, FMX.Graphics, FMX.Dialogs, FMX.Objects,
  FMX.Controls.Presentation, FMX.StdCtrls, FMX.ScrollBox, FMX.Memo,
  FMX.TabControl, FMX.Edit, FMX.MultiView,
  System.NetEncoding, System.JSON, System.IOUtils;

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
    TbItemUnitTest: TTabItem;
    BtnRunTests: TButton;
    chGetToken: TCheckBox;
    chStampOutToken: TCheckBox;
    chStampWithToken: TCheckBox;
    memoGetToken: TMemo;
    memoStampOutToken: TMemo;
    MemoStampWithToken: TMemo;
    chError404: TCheckBox;
    chError401: TCheckBox;
    MemoError401: TMemo;
    MemoError404: TMemo;
    MemoStampMany: TMemo;
    chStampMany: TCheckBox;
    TxtUrlUnitTest: TEdit;
    Text8: TText;
    procedure BtnAuthenticationClick(Sender: TObject);
    procedure BtnStampTokenClick(Sender: TObject);
    procedure BtnStampOutTokenClick(Sender: TObject);
    procedure BtnOpenFileClick(Sender: TObject);
    procedure BtnClearClick(Sender: TObject);
    procedure BtnClearStampClick(Sender: TObject);
    procedure BtnRunTestsClick(Sender: TObject);
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
Function Stamp(url, user, password, xml : PAnsiChar): PAnsiChar; stdcall; external 'sw-sdk-cpp.dll' name 'StampB64';
Function StampByToken(url, token, xml : PAnsiChar): PAnsiChar; stdcall; external 'sw-sdk-cpp.dll' name 'StampByTokenB64';

procedure TForm1.BtnAuthenticationClick(Sender: TObject);
  var
      result : string;
      _url : PAnsiChar;
      _user : PAnsiChar;
      _password : PAnsiChar;
  begin
      with TbControl do
        _url:= PAnsiChar(AnsiString(TxtUrl.Text));
        _user:= PAnsiChar(AnsiString(TxtUser.Text));
        _password := PAnsiChar(AnsiString(TxtPassword.Text));
      if (_url <> '') And (_user <> '' ) And (_password <> '')
        then
          begin
            result := Authentication(_url, _user , _password);
            MemoResult.Lines.Text := result;
          end
      else
        ShowMessage('Los campos Url, Usuario y Contraseņa se necesitan para obtener el token');
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
    _xmlB64 : PAnsiChar;
    x : string;
  begin
    with TbControl do
      _url := PAnsiChar(AnsiString(TxtUrlStamp.Text));
      _user := PAnsiChar(AnsiString(TxtUserStamp.Text));
      _password := PAnsiChar(AnsiString(TxtPassword.Text));
      _Xml := PAnsiChar(AnsiString(MemoXML.Text));
    if (_url <> '') And (_user <> '' ) And (_password <> '') And (_Xml <> '')
      then
        begin
          x := TNetEncoding.Base64.Encode(_Xml);
          _xmlB64 := PAnsiChar(AnsiString(x));
          result := Stamp(_url,_user, _password, _xmlB64);

          MemoResultStamp.Lines.Text := result;
        end
    else
      ShowMessage('Los campos Url, Usuario, Contraseņa y la Ruta del XML deben estar llenos antes de timbrar');
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

procedure TForm1.BtnRunTestsClick(Sender: TObject);
var
    result : string;
    resultGetToken : string;
    resultStampOutToken : string;
    resultStampWithToken : string;
    resultStampMany : string;
     _url : PAnsiChar;
    _user : PAnsiChar;
    _password : PAnsiChar;
    _Xml : PAnsiChar;
    _xmlB64 : PAnsiChar;
    _token : PAnsiChar;
    x : string;
    path : string;
    myXMLFile : TextFile;
    strTemp : string;
    xmlString : string;
    _PxmlString : PAnsiChar;
    List: TStrings;
    LJsonObj: TJSONObject;
    objData: TJSONObject;
    _tokenJson: TJSONString;
    _MessageJson : TJSONString;
    _code : string;
begin
    List := TStringList.Create;
    with TbControl do
        _url := PAnsiChar(AnsiString(TxtUrlUnitTest.Text));
        _user := PAnsiChar(AnsiString('demo'));
        _password := PAnsiChar(AnsiString('123456789'));
        resultGetToken := Authentication(_url, _user , _password);
        MemoGetToken.Lines.Text := resultGetToken;

        LJsonObj := TJSONObject.ParseJSONValue(TEncoding.UTF8.GetBytes(resultGetToken), 0) as TJSONObject;
        objData := LJsonObj.GetValue('data') as TJSONObject;
        _tokenJson := objData.GetValue('token') as TJSONString;
        _token := PAnsiChar(AnsiString(_tokenJson.Value));
        if (resultGetToken <> '') and (resultGetToken.Contains('token'))
          then
            begin
              chGetToken.IsChecked := True;
            end
        else
          chGetToken.IsChecked := False;

        //StampOutToken
        path :=  PAnsiChar(AnsiString('..//..//Resources/XMLFile.xml'));
        AssignFile(myXMLFile, path);
        Reset(myXMLFile);
        while not Eof(myXMLFile) do
           begin
             ReadLn(myXMLFile, strTemp);
             xmlString := Concat(xmlString, strTemp);
           end;
        CloseFile(myXMLFile);

        _PxmlString := PAnsiChar(AnsiString(xmlString));

         x := TNetEncoding.Base64.Encode(_PxmlString);
         _xmlB64 := PAnsiChar(AnsiString(x));
        resultStampOutToken := Stamp(_url,_user, _password, _xmlB64);
        MemoStampOutToken.Lines.Text := resultStampOutToken;
        if (resultStampOutToken <> '') and (resultStampOutToken.Contains('tfd'))
          then
            begin
              chStampOutToken.IsChecked := True;
            end
        else
          chStampOutToken.IsChecked := False;

        //StampWithToken
        resultStampWithToken := StampByToken(_url, _token, _xmlB64);
        MemoStampWithToken.Lines.Text := resultStampWithToken;
        if (resultStampWithToken <> '') and (resultStampWithToken.Contains('tfd'))
          then
            begin
              chStampWithToken.IsChecked := True;
            end
        else
          chStampWithToken.IsChecked := False;

       //Error 404
        result := StampByToken(PAnsiChar(AnsiString('http://services.test.sw.com.mx/fa')), _token, _xmlB64);
        MemoError404.Lines.Text := result;

        LJsonObj := TJSONObject.ParseJSONValue(TEncoding.UTF8.GetBytes(result), 0) as TJSONObject;
        _MessageJson := LJsonObj.GetValue('message') as TJSONString;
        if _MessageJson <> nil
          then
              begin
                _code := _MessageJson.Value;

                if (_code = '404')
                  then
                    begin
                      chError404.IsChecked := True;
                    end
                else
                  chError404.IsChecked := False;
              end
        else
           MemoError404.Lines.Text := 'ERROR EN LA COMUNICACION CON LA DLL ';

        //Error 401
        result := StampByToken(_url, PAnsiChar(AnsiString('badtoken')), _xmlB64);
        MemoError401.Lines.Text := result;

        LJsonObj := TJSONObject.ParseJSONValue(TEncoding.UTF8.GetBytes(result), 0) as TJSONObject;
        _MessageJson := LJsonObj.GetValue('message') as TJSONString;
        if _MessageJson <> nil
          then
              begin
                _code := _MessageJson.Value;

                if (_code = '401')
                  then
                    begin
                      chError401.IsChecked := True;
                    end
                else
                  chError401.IsChecked := False;
              end
        else
           MemoError401.Lines.Text := 'ERROR EN LA COMUNICACION CON LA DLL ';

        //Stamp Many
        path :=  PAnsiChar(AnsiString('..//..//Resources/conceptos5.xml'));
        xmlString := '';
        AssignFile(myXMLFile, path);
        Reset(myXMLFile);
        while not Eof(myXMLFile) do
           begin
             ReadLn(myXMLFile, strTemp);
             xmlString := Concat(xmlString, strTemp);
           end;
        CloseFile(myXMLFile);

        _PxmlString := PAnsiChar(AnsiString(xmlString));

         x := TNetEncoding.Base64.Encode(_PxmlString);
         _xmlB64 := PAnsiChar(AnsiString(x));
        resultStampMany := StampByToken(_url, _token, _xmlB64);
        MemoStampMany.Lines.Text := resultStampMany;
        if (resultStampMany <> '') and (resultStampMany.Contains('tfd'))
          then
            begin
               chStampMany.IsChecked := True;
            end
        else
          chStampMany.IsChecked := False;
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
