<p align="center">
    <img src="http://szintezis-net.hu/wp-content/uploads/2016/08/delphi.jpg">
</p>


Pasos Previos
---------

* Para utilizar los servicios de SW con Delphi se debe tener primeramente el fichero DLL correspondiente a **sw-sdk-cpp.dll** y su dependencia **cpprest140d_2_9.dll**.

* Ambos archivos se pueden encontrar en el repositorio de github correspondiente al proyecto **sw-sdk-cpp**  https://github.com/lunasoft/sw-sdk-cpp en la carpeta **Release** (https://github.com/lunasoft/sw-sdk-cpp/tree/feature/SDT3.0.2.4/Release).

* Otra alternativa seria clonar el proyecto y compilarlo para generar ambas DLL.

Interfaz
---------
El proyecto de ejemplo cuenta con un formulario principal el cual tiene dos pestañas la primera prueba el servicio de **Autenticar** y la segunda pestaña prueba el servicio de **Timbrado**

#### Pesta&ntilde;a de Autenticacion #####

<p align="center">
    <img src="https://github.com/lunasoft/sw-sdk-cpp/blob/feature/SDT3.0.2.4/Samples/DELPHI/Resources/screenshots/ResultAuthenticacion.PNG">
</p>

* El primer TEdit recibe la **Url** a donde apuntara el servicio la cual en nuestro ambiente de prueba seria 'http://services.test.sw.com.mx/security/authenticate'
* El segundo TEdit recibe el **Usuario** que se utilizara para autenticarse el cual en nuestro ambiente de pruebas seria 'demo'
* El tercer TEdit recibe la **Contrase&ntilde;a** que necesita para poder obtener el token el cual seria '123456789'
* El Memo1 arroja el resultado del servicio de autenticacion

#### Pesta&ntilde;a de Timbrado #####

<p align="center">
    <img src="https://github.com/lunasoft/sw-sdk-cpp/blob/feature/SDT3.0.2.4/Samples/DELPHI/Resources/screenshots/ResultStamp.PNG">
</p>

* Aquí tenemos dos formas para poder consumir el servicio utilizando solamente un token o facilitando las credenciales necesarias (url, usuario y contrase&ntilde;a) **ambos metodos necesitan de un XML ya selllado**.


* El primer TEdit recibe la **Url** a donde apuntara el servicio la cual en nuestro ambiente de prueba seria 'http://services.test.sw.com.mx/security/authenticate'
* El segundo TEdit recibe el **Usuario** que se utilizara para autenticarse el cual en nuestro ambiente de pruebas seria 'demo'
* El tercer TEdit recibe la **Contrase&ntilde;a** que necesita para poder obtener el token el cual seria '123456789'
* El cuarto TEdit recibe un **Token** 
* En el TButton Buscar se busca el archivo **XML** el cual se desea utilizar para timbrar 
* El Memo1 se utiliza para imprimir el contenido del archivo XML
* El Memo2 arroja el resultado del servicio de timbrado


Codigo del Ejemplo de la Pestaña de Autenticar
---------
Nuestro Bot&oacute;n Obtener Token tiene lo siguiente 

**Obtener Token**
```delphi
//Declaramos los metodos que importaremos de la DLL
//El fichero DLL debe estar en el mismo directorio en donde esta el fichero .exe de la aplicación de Delphi.
//Creamos la depependencia a nuestra libreria antes de nuestros procedures para poder llamarla mas tarde
//La forma en como se hace la referencia es la siguiente:
//Nombre de la funcion (Paramentros que resive) tipo de respesta, ruta de la DLL y por ultimo el nombre de la funcion que se expone en la DLL

Function Authentication(url, user, password : PAnsiChar): PAnsiChar; stdcall; external 'sw-sdk-cpp.dll' name 'Authentication';
 
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
        ShowMessage('Los campos Url, Usuario y Contraseña se necesitan para obtener el token');
  end;
```

El ejemplo anterior la respuesta es un objeto tipo **JSON** y dentro de el se encuentra el **Token**

```json
{"data":{"token":"T2lYQ0t4L0RHVkR4dHZ5Nkk1VHNEakZ3Y0J4Nk9GODZuRyt4cE1wVm5tbXB3..."},"status":"success"}
```

#### Timbrar CFDI V1 #####
**Stamp** Recibe el contenido de un **XML** ya emitido (sellado) en formato **String** si la factura y el token son correctos devuelve el complemento timbre en un string (**TFD**), en caso contrario lanza una excepción.

**Timbrar XML en formato string utilizando usuario y contraseña**

```delphi
//Declaramos los metodos que importaremos de la DLL
//El fichero DLL debe estar en el mismo directorio en donde esta el fichero .exe de la aplicación de Delphi.
//Creamos la depependencia a nuestra libreria antes de nuestros procedures para poder llamarla mas tarde
//La forma en como se hace la referencia es la siguiente:
//Nombre de la funcion (Paramentros que resive) tipo de respesta, ruta de la DLL y por ultimo el nombre de la funcion que se expone en la DLL

Function Stamp(url, user, password : PAnsiChar): PAnsiChar; stdcall; external 'sw-sdk-cpp.dll' name 'Stamp';
 
procedure TForm1.BtnTimbrarConTokenClick(Sender: TObject);
  var
    result : string;
    base_url : PAnsiChar;
    token: PAnsiChar;
    xmlString : string;
    xml : PAnsiChar;
    myXMLFile : TextFile;
    path : string;
    strTemp : string;
  begin
    base_url := PAnsiChar(AnsiString('http://services.test.sw.com.mx')); //Url de nuestro servicio
    token := PAnsiChar(AnsiString('T2lYQ0t4L0RHVkR4dHZ5Nkk1VH...')); //Token

    path :=  PAnsiChar(AnsiString('miXml.xml'));
    AssignFile(myXMLFile, path);
    Reset(myXMLFile);
    while not Eof(myXMLFile) do
       begin
         ReadLn(myXMLFile, strTemp);
         xmlString := Concat(xmlString, strTemp);
       end;
    CloseFile(myXMLFile);

    xml := PAnsiChar(AnsiString(xmlString));
    result := Stamp(base_url, token, xml); //Enviamos nuestros parametros y esperamos la respuesta
    ShowMessage(result);
  end;
```

Pantalla del formulario de Timbrado
<p align="center">
    <img src="https://github.com/lunasoft/sw-sdk-cpp/blob/feature/SDT3.0.2.4/Samples/DELPHI/Resources/screenshots/ResultStamp.PNG">
</p>