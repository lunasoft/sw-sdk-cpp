<p align="center">
   <img src="https://mcodegeeks.com/assets/uploads/2016/11/icon-c.png">
</p>
<p align="center">
  <img src="http://sw.com.mx/images/logo.png">
</p>

A continuación encontrara ejemplos de implementacion de diferentes de lenguajes para consumir nuestro SDK de servicios proveido por **SmarterWeb** para Timbrado de **CFDI 3.3**

Compatibilidad
-------------
* CFDI 3.3


Dependencias
------------
* [CPPREST SDK](https://github.com/Microsoft/cpprestsdk)

----------------
Instalaci&oacute;n
---------
Para poder hacer uso de nuestro SDK de servicios primero tenemos que añadir la referencia de los respositorios de nuget proveidos por **SmarterWeb**.

#### Instalar la libreria (SDK) #####

* Paso 1:
Abrir la consola de **Pacakge Manager Console** dentro de visual studio
* Paso 2:
Escribir en la consola **Install-Package sw-sdk-cpp**
* Paso 4:
Usted debera ver un mensaje de confirmacion diciendo **Successfully installed 'sw-sdk-cpp 0.0.1.0'**


Implementaci&oacute;n
---------

La librería cuenta con dos servicios principales los que son la Autenticacion y el Timbrado de CFDI.

#### Aunteticaci&oacute;n #####
El servicio de Autenticación es utilizado principalmente para obtener el **token** el cual sera utilizado para poder timbrar nuestro CFDI (xml) ya emitido (sellado), para poder utilizar este servicio es necesario que cuente con un **usuario** y **contraseña** para posteriormente obtenga el token, usted puede utilizar los que estan en este ejemplo para el ambiente de **Pruebas**.

**Obtener Token**
```c++
//Incluimos el header correspondiente a la libreria (sw-sdk-cpp.h)
#include "stdafx.h"
#include <iostream>
#include "sw-sdk-cpp.h"
 
int main()
{
    //Inicializamos las variables necesarias para realizar la autenticación (url del servicio, usuario, password)
    char *url = "http://services.test.sw.com.mx";
    char *user = "demo";
    char *password = "123456789";
    //Asignamos el resultado del metodo "Authentication" a una variable
    string tkn = Authentication(url, user, password);
    cout << tkn;
    return 0;
}

```

El ejemplo anterior la respuesta es un objeto tipo **JSON** y dentro de el se encuentra el **Token**

```json
{"data":{"token":"T2lYQ0t4L0RHVkR4dHZ5Nkk1VHNEakZ3Y0J4Nk9GODZuRyt4cE1wVm5tbXB3..."},"status":"success"}
```

#### Timbrar CFDI V1 #####
**Stamp** Recibe el contenido de un **XML** ya emitido (sellado) en formato **String** posteriormente si la factura y el token son correctos devuelve el complemento timbre en un string (**TFD**), en caso contrario regresa una excepción.

**Timbrar XML en formato string utilizando usuario y contraseña**
```c++
//Incluimos el header correspondiente a la libreria (sw-sdk-cpp.h)
#include "stdafx.h"
#include <iostream>
#include "sw-sdk-cpp.h"
int main()
{
   char *url = "http://services.test.sw.com.mx";
   char *user = "demo";
   char *password = "123456789";
   string tfd = Stamp(url, user, password, "xml en string");
   cout << tfd;
   return 0;
}
```
El ejemplo anterior la respuesta es un objeto tipo **JSON** y dentro de el se encuentra el **TFD** 

```json
{"data":{"tfd":"<tfd:TimbreFiscalDigital xsi:schemaLocation=\"http://www.sat.gob.mx/TimbreFiscalDigital http://www.sat.gob.mx/sitio_internet/cfd/TimbreFiscalDigital/TimbreFiscalDigitalv11.xsd..."},"status":"success"}
```

Es posible que si usted utiliza un xml con fecha anterior a 3 dias a la actual obtenga el siguiente mensaje lo cual tambien indica que usted pudo consumir el servicio solo que su xml ya vencio

```json
{"message":"T401. El rango de la fecha de generacion no debe de ser mayor a 72 horas para la emision del timbre...","status":"error"}
```

**Timbrar XML en formato string utilizando token**
```c
//Incluimos el header correspondiente a la libreria (sw-sdk-cpp.h)
#include "stdafx.h"
#include <iostream>
#include "sw-sdk-cpp.h"
int main()
{
   char *url = "http://services.test.sw.com.mx";
   char *token = "T2lYQ0t4L0RHVkR4dHZ5Nkk1VHNEakZ3Y0J4Nk9GODZuRyt4...";
   string tfd = StampByToken(url, token, "xml en string");
   cout << tfd;
   return 0;
}
```

El ejemplo anterior la respuesta es un objeto tipo **JSON** y dentro de el se encuentra el **TFD** 

```json
{"data":{"tfd":"<tfd:TimbreFiscalDigital xsi:schemaLocation=\"http://www.sat.gob.mx/TimbreFiscalDigital http://www.sat.gob.mx/sitio_internet/cfd/TimbreFiscalDigital/TimbreFiscalDigitalv11.xsd..."},"status":"success"}
```

Es posible que si usted utiliza un xml con fecha anterior a 3 dias a la actual obtenga el siguiente mensaje lo cual tambien indica que usted pudo consumir el servicio solo que su xml ya vencio

```json
{"message":"T401. El rango de la fecha de generacion no debe de ser mayor a 72 horas para la emision del timbre...","status":"error"}
```

----------------
Cancelaci&oacute;n
---------
**Datos de prueba para cancelación por XML**
Para cancelar por XML es posible utilizar los siguientes XML de cancelación de prueba.
```xml
<?xml version='1.0' encoding='utf-8'?><Cancelacion xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance' xmlns:xsd='http://www.w3.org/2001/XMLSchema' RfcEmisor='LAN7008173R5' Fecha='2017-06-23T11:46:44' xmlns='http://cancelacfd.sat.gob.mx'><Folios><UUID>3eaeabc9-ea41-4627-9609-c6856b78e2b1</UUID></Folios><Signature xmlns='http://www.w3.org/2000/09/xmldsig#'><SignedInfo><CanonicalizationMethod Algorithm='http://www.w3.org/TR/2001/REC-xml-c14n-20010315' /><SignatureMethod Algorithm='http://www.w3.org/2000/09/xmldsig#rsa-sha1' /><Reference URI=''><Transforms><Transform Algorithm='http://www.w3.org/2000/09/xmldsig#enveloped-signature' /></Transforms><DigestMethod Algorithm='http://www.w3.org/2000/09/xmldsig#sha1' /><DigestValue>thYuQszvcb6Tvd5ui3RL30+t5KE=</DigestValue></Reference></SignedInfo><SignatureValue>fodsbdc+agN1YGd9pjaA7YOYWUsLJ7Xe7nCgL7nwYEw/ODWKDaW/0wMnQu/h96BzKToQ12JJl1Qi4oYy+QCl7hXYPs56Gxlvq3aFP7ynsOOraAhe23+kr/ox1sx+87eofEhKNd74VhCoX/qMJQ6Ejkz1C1DZgJkCp9goWFw0s+gCrUASVvYmZ3J3Qu7NVb54nSa7ACd0pNZ5ywuEJgLUa3LqVM8zsx/sfuMy7kq6k3N6Q7E9fLzjs+/NvqJ2w2NuuwjHMHief3tgAj+qSK7Yk0RA9DtqBSX+tmtHiaNTRHYff6XAlK6fniU+nCAJp6F7kUuUzP2Yf5IACo4bEAfFng==</SignatureValue><KeyInfo><X509Data><X509IssuerSerial><X509IssuerName>OID.1.2.840.113549.1.9.2=Responsable: ACDMA, OID.2.5.4.45=SAT970701NN3, L=Coyoacán, S=Distrito Federal, C=MX, PostalCode=06300, STREET='Av. Hidalgo 77, Col. Guerrero', E=asisnet@pruebas.sat.gob.mx, OU=Administración de Seguridad de la Información, O=Servicio de Administración Tributaria, CN=A.C. 2 de pruebas(4096)</X509IssuerName><X509SerialNumber>3230303031303030303030333030303232383135</X509SerialNumber></X509IssuerSerial><X509Certificate>MIIFxTCCA62gAwIBAgIUMjAwMDEwMDAwMDAzMDAwMjI4MTUwDQYJKoZIhvcNAQELBQAwggFmMSAwHgYDVQQDDBdBLkMuIDIgZGUgcHJ1ZWJhcyg0MDk2KTEvMC0GA1UECgwmU2VydmljaW8gZGUgQWRtaW5pc3RyYWNpw7NuIFRyaWJ1dGFyaWExODA2BgNVBAsML0FkbWluaXN0cmFjacOzbiBkZSBTZWd1cmlkYWQgZGUgbGEgSW5mb3JtYWNpw7NuMSkwJwYJKoZIhvcNAQkBFhphc2lzbmV0QHBydWViYXMuc2F0LmdvYi5teDEmMCQGA1UECQwdQXYuIEhpZGFsZ28gNzcsIENvbC4gR3VlcnJlcm8xDjAMBgNVBBEMBTA2MzAwMQswCQYDVQQGEwJNWDEZMBcGA1UECAwQRGlzdHJpdG8gRmVkZXJhbDESMBAGA1UEBwwJQ295b2Fjw6FuMRUwEwYDVQQtEwxTQVQ5NzA3MDFOTjMxITAfBgkqhkiG9w0BCQIMElJlc3BvbnNhYmxlOiBBQ0RNQTAeFw0xNjEwMjUyMTUyMTFaFw0yMDEwMjUyMTUyMTFaMIGxMRowGAYDVQQDExFDSU5ERU1FWCBTQSBERSBDVjEaMBgGA1UEKRMRQ0lOREVNRVggU0EgREUgQ1YxGjAYBgNVBAoTEUNJTkRFTUVYIFNBIERFIENWMSUwIwYDVQQtExxMQU43MDA4MTczUjUgLyBGVUFCNzcwMTE3QlhBMR4wHAYDVQQFExUgLyBGVUFCNzcwMTE3TURGUk5OMDkxFDASBgNVBAsUC1BydWViYV9DRkRJMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAgvvCiCFDFVaYX7xdVRhp/38ULWto/LKDSZy1yrXKpaqFXqERJWF78YHKf3N5GBoXgzwFPuDX+5kvY5wtYNxx/Owu2shNZqFFh6EKsysQMeP5rz6kE1gFYenaPEUP9zj+h0bL3xR5aqoTsqGF24mKBLoiaK44pXBzGzgsxZishVJVM6XbzNJVonEUNbI25DhgWAd86f2aU3BmOH2K1RZx41dtTT56UsszJls4tPFODr/caWuZEuUvLp1M3nj7Dyu88mhD2f+1fA/g7kzcU/1tcpFXF/rIy93APvkU72jwvkrnprzs+SnG81+/F16ahuGsb2EZ88dKHwqxEkwzhMyTbQIDAQABox0wGzAMBgNVHRMBAf8EAjAAMAsGA1UdDwQEAwIGwDANBgkqhkiG9w0BAQsFAAOCAgEAJ/xkL8I+fpilZP+9aO8n93+20XxVomLJjeSL+Ng2ErL2GgatpLuN5JknFBkZAhxVIgMaTS23zzk1RLtRaYvH83lBH5E+M+kEjFGp14Fne1iV2Pm3vL4jeLmzHgY1Kf5HmeVrrp4PU7WQg16VpyHaJ/eonPNiEBUjcyQ1iFfkzJmnSJvDGtfQK2TiEolDJApYv0OWdm4is9Bsfi9j6lI9/T6MNZ+/LM2L/t72Vau4r7m94JDEzaO3A0wHAtQ97fjBfBiO5M8AEISAV7eZidIl3iaJJHkQbBYiiW2gikreUZKPUX0HmlnIqqQcBJhWKRu6Nqk6aZBTETLLpGrvF9OArV1JSsbdw/ZH+P88RAt5em5/gjwwtFlNHyiKG5w+UFpaZOK3gZP0su0sa6dlPeQ9EL4JlFkGqQCgSQ+NOsXqaOavgoP5VLykLwuGnwIUnuhBTVeDbzpgrg9LuF5dYp/zs+Y9ScJqe5VMAagLSYTShNtN8luV7LvxF9pgWwZdcM7lUwqJmUddCiZqdngg3vzTactMToG16gZA4CWnMgbU4E+r541+FNMpgAZNvs2CiW/eApfaaQojsZEAHDsDv4L5n3M1CC7fYjE/d61aSng1LaO6T1mh+dEfPvLzp7zyzz+UgWMhi5Cs4pcXx1eic5r7uxPoBwcCTt3YI1jKVVnV7/w=</X509Certificate></X509Data></KeyInfo></Signature></Cancelacion>
```

**Datos de prueba para cancelación por CSD**
Para cancelar por CSD, es posible utilizar los siguientes datos de prueba.
```json
{
 "uuid": "06a46e4b-b154-4c12-bb77-f9a63ed55ff2",
 "rfc": "LAN7008173R5",
 "password": "12345678a",
 "b64Cer": "MIIFxTCCA62gAwIBAgIUMjAwMDEwMDAwMDAzMDAwMjI4MTUwDQYJKoZIhvcNAQELBQAwggFmMSAwHgYDVQQDDBdBLkMuIDIgZGUgcHJ1ZWJhcyg0MDk2KTEvMC0GA1UECgwmU2VydmljaW8gZGUgQWRtaW5pc3RyYWNpw7NuIFRyaWJ1dGFyaWExODA2BgNVBAsML0FkbWluaXN0cmFjacOzbiBkZSBTZWd1cmlkYWQgZGUgbGEgSW5mb3JtYWNpw7NuMSkwJwYJKoZIhvcNAQkBFhphc2lzbmV0QHBydWViYXMuc2F0LmdvYi5teDEmMCQGA1UECQwdQXYuIEhpZGFsZ28gNzcsIENvbC4gR3VlcnJlcm8xDjAMBgNVBBEMBTA2MzAwMQswCQYDVQQGEwJNWDEZMBcGA1UECAwQRGlzdHJpdG8gRmVkZXJhbDESMBAGA1UEBwwJQ295b2Fjw6FuMRUwEwYDVQQtEwxTQVQ5NzA3MDFOTjMxITAfBgkqhkiG9w0BCQIMElJlc3BvbnNhYmxlOiBBQ0RNQTAeFw0xNjEwMjUyMTUyMTFaFw0yMDEwMjUyMTUyMTFaMIGxMRowGAYDVQQDExFDSU5ERU1FWCBTQSBERSBDVjEaMBgGA1UEKRMRQ0lOREVNRVggU0EgREUgQ1YxGjAYBgNVBAoTEUNJTkRFTUVYIFNBIERFIENWMSUwIwYDVQQtExxMQU43MDA4MTczUjUgLyBGVUFCNzcwMTE3QlhBMR4wHAYDVQQFExUgLyBGVUFCNzcwMTE3TURGUk5OMDkxFDASBgNVBAsUC1BydWViYV9DRkRJMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAgvvCiCFDFVaYX7xdVRhp/38ULWto/LKDSZy1yrXKpaqFXqERJWF78YHKf3N5GBoXgzwFPuDX+5kvY5wtYNxx/Owu2shNZqFFh6EKsysQMeP5rz6kE1gFYenaPEUP9zj+h0bL3xR5aqoTsqGF24mKBLoiaK44pXBzGzgsxZishVJVM6XbzNJVonEUNbI25DhgWAd86f2aU3BmOH2K1RZx41dtTT56UsszJls4tPFODr/caWuZEuUvLp1M3nj7Dyu88mhD2f+1fA/g7kzcU/1tcpFXF/rIy93APvkU72jwvkrnprzs+SnG81+/F16ahuGsb2EZ88dKHwqxEkwzhMyTbQIDAQABox0wGzAMBgNVHRMBAf8EAjAAMAsGA1UdDwQEAwIGwDANBgkqhkiG9w0BAQsFAAOCAgEAJ/xkL8I+fpilZP+9aO8n93+20XxVomLJjeSL+Ng2ErL2GgatpLuN5JknFBkZAhxVIgMaTS23zzk1RLtRaYvH83lBH5E+M+kEjFGp14Fne1iV2Pm3vL4jeLmzHgY1Kf5HmeVrrp4PU7WQg16VpyHaJ/eonPNiEBUjcyQ1iFfkzJmnSJvDGtfQK2TiEolDJApYv0OWdm4is9Bsfi9j6lI9/T6MNZ+/LM2L/t72Vau4r7m94JDEzaO3A0wHAtQ97fjBfBiO5M8AEISAV7eZidIl3iaJJHkQbBYiiW2gikreUZKPUX0HmlnIqqQcBJhWKRu6Nqk6aZBTETLLpGrvF9OArV1JSsbdw/ZH+P88RAt5em5/gjwwtFlNHyiKG5w+UFpaZOK3gZP0su0sa6dlPeQ9EL4JlFkGqQCgSQ+NOsXqaOavgoP5VLykLwuGnwIUnuhBTVeDbzpgrg9LuF5dYp/zs+Y9ScJqe5VMAagLSYTShNtN8luV7LvxF9pgWwZdcM7lUwqJmUddCiZqdngg3vzTactMToG16gZA4CWnMgbU4E+r541+FNMpgAZNvs2CiW/eApfaaQojsZEAHDsDv4L5n3M1CC7fYjE/d61aSng1LaO6T1mh+dEfPvLzp7zyzz+UgWMhi5Cs4pcXx1eic5r7uxPoBwcCTt3YI1jKVVnV7/w=",
 "b64Key": "MIIFDjBABgkqhkiG9w0BBQ0wMzAbBgkqhkiG9w0BBQwwDgQIAgEAAoIBAQACAggAMBQGCCqGSIb3DQMHBAgwggS9AgEAMASCBMh4EHl7aNSCaMDA1VlRoXCZ5UUmqErAbucRBAKNQXH8t1GNfLDIQejtcocS39VvWnpNXjZJeCg65Y2wI36UGn78gvnU0NOmyUkXksPVrkz7hqNtAVojPUtN65l+MVAsIRVD6OLJeKZ2bLx5z78zrx6Tp1zCGT/NpxL+CJSy5iY6TKqbJcK/9198noOvT2p8rKVqUUF3wLRvD6R/b3BC5wCon/exp3BUTZeiWJqGRRgaW4rn49ZbJPVIcDmUO8mojPesFHjJDSnA0nBnWaUvTYXi0srT+dLZOewsBR8d5GdSWh9ZkM29wJbjYHCMsXkObZjaap3YM8fU29zRyZ8KAqaCnBHCfYjbib56m+Lmnk+ScqMkQQ+S/+2pzn2LzauvBI4p/OjQgBDeblo22X7sX9OA9YaqB3q6CCjQ5tkDNrz3HOgTm+amh/kI8TEn9rcKf4Ru7mC1T7VMaFgBqpIS8YJNbcgegF0IF1FpCS05wjdU5CktYAnPnvC+Pj+MFDeH+184kIHBWqPNG6dAzALxRgtKTlGdJ1l5Do+4EWI+0mvKojREnKoDczFnDeCFnM51u3I9Vce3rkf0djRQKFomPVUnPDqxlR5lDAssYAYNcECAkvGxKcBDbjWi/6NHlwjS1r28+0Jhvfxjx9O6hi4AW82Q2/kBE5P/eOwln/jKSbLgi7Iyim1FFHxkQH1FY5kcKhAzFcIq85rGFlzHRfPF9OIQSmONI9kcWQCxkk8aG1u1zwbjZRYLTxlwmZvynOgaWRpTN8Y4ReBDIG1klhva7nqqoM416oXBG71IKaCtjAwRlE6pgaqnIz/WQAb2FR541pqynX6dB6DB1nIWnatsWZJZlu+Bnhf9DBlUsO9ZSAf9Fa9nJAzwFCzaKIsvGJIeKSZ/h+vInkjaO/rxswErVROTfZy1lO2CJ/xnAgzFGrpDxNJPliv3McO9TGwYy/zHhE6Pdo8Xu6NsMisNU6TB8Bc26uLNv/7kWhNmNnBA1qt5akln6hOHrPBXGBiTNUL0IoFVPNdCbS0834zAYXfgtZLDzVpeLqmeMpqXbIYK0/NXe9etxuOcN40O+B/fTHHmO7dMgBZ4vAApVQUPr7ilumVHsWSMRP/0p5R9q4qr1bDm9S5YCPevdyYWTSceGSrXHmjYzJLBtpc/s77mynNqZEYjhnKk2XRNp6kp/FYRu+QdsX9vaDJbLKR2EnSC4fU6UOTO03IZU15j3wOsg30QrXoKntSJ/beF99cvFHuPrQPWxCtws0lLwkkHNVOm6XNO948Moy1w1pL4i68CwmceYZaYrYhmHGdLuescFQrZQaULDWhpK2Stys8Vs/XwwxNi9MHAFSXpdy/b+Aro5n87w+0MHRcllF8ZKbtQ/ym4oG7aREuo7o71JXJQPjZKTOtVM1EQx/FLM/5brnDSoyvLtoYtv9/tTnIC+8gR6eErkzaGmn8pftPhGNuz6yzx8JeLFoMD7VWbGTefj46KS+yMweFJnpReHEqwnukXpEYq19EWVyQa/Sb7navtKt80y/vRs0aNZp3iL23AOs0u1kQ1CFNY2y12Gor1koaH2FUd5jAQnaSKmgarLy0H/QVvR2g8B3+Fh49QhKYrd8N6LvvI80cwbEoqYWn5DWA="
}
```

**Cancelación por XML y por Usuario y Password**
```c
//Incluimos el header correspondiente a la libreria (sw-sdk-cpp.h)
#include "stdafx.h"
#include <iostream>
#include "sw-sdk-cpp.h"
int main()
{
   char *url = "http://services.test.sw.com.mx";
   char *user="demo";
   char *password="123456789";
   string acuse = CancelByXml(url, user, password, "xml de cancelación en string");
   cout << acuse;
   return 0;
}
```

**Cancelación por XML y por Token generado**
```c
//Incluimos el header correspondiente a la libreria (sw-sdk-cpp.h)
#include "stdafx.h"
#include <iostream>
#include "sw-sdk-cpp.h"
int main()
{
   char *url = "http://services.test.sw.com.mx";
   char *token = "T2lYQ0t4L0RHVkR4dHZ5Nkk1VHNEakZ3Y0J4Nk9GODZuRyt4...";
   string acuse = CancelByXmlToken(url, token, "xml de cancelación en string");
   cout << acuse;
   return 0;
}
```

**Cancelación por CSD y por Usuario y Password**
```c
//Incluimos el header correspondiente a la libreria (sw-sdk-cpp.h)
#include "stdafx.h"
#include <iostream>
#include "sw-sdk-cpp.h"
int main()
{
   char *url = "http://services.test.sw.com.mx";
   char *user="demo";
   char *password="123456789";
   char *b64Cer="";
   char *b64Key="";
   char *csdPassword="";
   char *rfc="";
   char *uuid="";
   string acuse = CancelByCSD(url, user, password, b64Cer, b64Key, csdPassword, rfc, uuid);
   cout << acuse;
   return 0;
}
```

**Cancelación por XML y por Token generado**
```c
//Incluimos el header correspondiente a la libreria (sw-sdk-cpp.h)
#include "stdafx.h"
#include <iostream>
#include "sw-sdk-cpp.h"
int main()
{
   char *url = "http://services.test.sw.com.mx";
   char *token = "T2lYQ0t4L0RHVkR4dHZ5Nkk1VHNEakZ3Y0J4Nk9GODZuRyt4...";
   char *b64Cer="";
   char *b64Key="";
   char *csdPassword="";
   char *rfc="";
   char *uuid="";
   string acuse = CancelByCSDToken(url, token, b64Cer, b64Key, csdPassword, rfc, uuid);
   cout << acuse;
   return 0;
}
```
En los ejemplos anteriores la respuesta es un objeto tipo **JSON** y dentro de el se encuentra el **Acuse** y el **UUID** a cancelar con su respectivo código de respuesta a la cancelación.

```json
{
    "data": {
        "acuse": "<?xml version=\"1.0\" encoding=\"utf-8\"?><Acuse xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" Fecha=\"2017-07-13T12:30:29.0272967\" RfcEmisor=\"LAN7008173R5\"><Folios xmlns=\"http://cancelacfd.sat.gob.mx\"><UUID>06A46E4B-B154-4C12-BB77-F9A63ED55FF2</UUID><EstatusUUID>202</EstatusUUID></Folios><Signature Id=\"SelloSAT\" xmlns=\"http://www.w3.org/2000/09/xmldsig#\"><SignedInfo><CanonicalizationMethod Algorithm=\"http://www.w3.org/TR/2001/REC-xml-c14n-20010315\" /><SignatureMethod Algorithm=\"http://www.w3.org/2001/04/xmldsig-more#hmac-sha512\" /><Reference URI=\"\"><Transforms><Transform Algorithm=\"http://www.w3.org/TR/1999/REC-xpath-19991116\"><XPath>not(ancestor-or-self::*[local-name()='Signature'])</XPath></Transform></Transforms><DigestMethod Algorithm=\"http://www.w3.org/2001/04/xmlenc#sha512\" /><DigestValue>5d/9GnkB3eJuCddNHhlMGvIL/Ce14Rhrx70y3hiRtiX9GfvbF4DVYYVd6uC0qsEW7BXmE0X8fgOCJtq4Q5v4nA==</DigestValue></Reference></SignedInfo><SignatureValue>BfnenEsqoWalOH/9MIfS9stPrKEY84lbHVoAn+DDMS8TxXSef0n0SdhOE3t2NWj52rVZ3jBCPqcE6rftv+fQAQ==</SignatureValue><KeyInfo><KeyName>00001088888810000001</KeyName><KeyValue><RSAKeyValue><Modulus>vAr6QLmcvW6auTg7a+Ogm0veNvqJ30rD3j0iSAHxGzGVrg1d0xl0Fj5l+JX9EivD+qhkSY7pfLnJoObLpQ3GGZZOOihJVS2tbJDmnn9TW8fKUOVg+jGhcnpCHaUPq/Poj8I2OVb3g7hiaREORm6tLtzOIjkOv9INXxIpRMx54cw46D5F1+0M7ECEVO8Jg+3yoI6OvDNBH+jABsj7SutmSnL1Tov/omIlSWausdbXqykcl10BLu2XiQAc6KLnl0+Ntzxoxk+dPUSdRyR7f3Vls6yUlK/+C/4FacbR+fszT0XIaJNWkHaTOoqz76Ax9XgTv9UuT67j7rdTVzTvAN363w==</Modulus><Exponent>AQAB</Exponent></RSAKeyValue></KeyValue></KeyInfo></Signature></Acuse>",
        "uuid": {
            "06A46E4B-B154-4C12-BB77-F9A63ED55FF2": "202"
        }
    },
    "status": "success"
}
```
