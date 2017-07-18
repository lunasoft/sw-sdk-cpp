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