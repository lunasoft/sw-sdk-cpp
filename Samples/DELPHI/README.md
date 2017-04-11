Pasos Previos
---------

* Para utilizar los servicios de SW con Delphi se debe tener primeramente el fichero DLL correspondiente a **sw-sdk-cpp.dll** y su dependencia **cpprest140d_2_9.dll**

* Este se puede encontrar en el repositorio de github correspondiente al proyecto **sw-sdk-cpp**  https://github.com/lunasoft/sw-sdk-cpp en la carpeta **Build**

* Otra alternativa seria clonar el proyecto y compilarse para generar el fichero DLL

Implementaci&oacute;n
---------

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
    base_url : PAnsiChar;
    user: PAnsiChar;
    password : PAnsiChar;
     
  begin
    base_url = PAnsiChar(AnsiString('http://services.test.sw.com.mx/security/authenticate')); //Url de nuestro servicio
    user = PAnsiChar(AnsiString('demo')); //Usuario de pruebas
    password = PAnsiChar(AnsiString('123456789')); //Contraseña de pruebas
    result := Authentication(base_url, user, password); //Enviamos nuestros parametros y esperamos la respuesta
    ShowMessage(result);
  end;
```

Pantalla del formulario de Authenticacion
<p align="center">
    ![Auhtentication](https://github.com/lunasoft/sw-sdk-cpp/blob/feature/SDT3.0.2.4/Samples/DELPHI/Resources/screenshots/ResultAuthenticacion.PNG)
</p>


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
    xml : PAnsiChar;
  begin
    base_url := PAnsiChar(AnsiString('http://services.test.sw.com.mx')); //Url de nuestro servicio
    token := PAnsiChar(AnsiString('T2lYQ0t4L0RHVkR4dHZ5Nkk1VH...')); //Token
    xml := PAnsiChar(AnsiString('myxml.xml'));
    result := Stamp(base_url, token, xml); //Enviamos nuestros parametros y esperamos la respuesta
    ShowMessage(result);
  end;
```

Pantalla del formulario de Timbrado
<p align="center">
    ![Auhtentication](https://github.com/lunasoft/sw-sdk-cpp/blob/feature/SDT3.0.2.4/Samples/DELPHI/Resources/screenshots/ResultStamp.PNG)
</p>