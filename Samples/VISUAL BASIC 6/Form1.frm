VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   8265
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   14190
   LinkTopic       =   "Form1"
   ScaleHeight     =   8265
   ScaleWidth      =   14190
   StartUpPosition =   3  'Windows Default
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   13200
      Top             =   600
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.Frame Frame2 
      Caption         =   "Autenticacion"
      Height          =   6855
      Left            =   240
      TabIndex        =   10
      Top             =   600
      Width           =   6495
      Begin VB.CommandButton btnToken 
         Caption         =   "Obtener Token"
         Height          =   1455
         Left            =   4320
         TabIndex        =   18
         Top             =   1200
         Width           =   1575
      End
      Begin VB.TextBox txtToken 
         Height          =   3135
         Left            =   1680
         MultiLine       =   -1  'True
         TabIndex        =   17
         Top             =   3480
         Width           =   4575
      End
      Begin VB.TextBox txtUrlToken 
         Height          =   735
         Left            =   1680
         TabIndex        =   13
         Top             =   480
         Width           =   2415
      End
      Begin VB.TextBox txtPasswordToken 
         Height          =   735
         Left            =   1680
         TabIndex        =   12
         Top             =   2400
         Width           =   2415
      End
      Begin VB.TextBox txtUserToken 
         Height          =   855
         Left            =   1680
         TabIndex        =   11
         Top             =   1320
         Width           =   2415
      End
      Begin VB.Label Label9 
         Caption         =   "Resultado Token"
         Height          =   615
         Left            =   360
         TabIndex        =   21
         Top             =   4680
         Width           =   975
      End
      Begin VB.Label Label6 
         Caption         =   "URL:"
         Height          =   255
         Left            =   240
         TabIndex        =   16
         Top             =   720
         Width           =   615
      End
      Begin VB.Label Label5 
         Caption         =   "Password:"
         Height          =   375
         Left            =   240
         TabIndex        =   15
         Top             =   2520
         Width           =   975
      End
      Begin VB.Label Label4 
         Caption         =   "Usuario:"
         Height          =   375
         Left            =   240
         TabIndex        =   14
         Top             =   1560
         Width           =   1095
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "Timbrado V2"
      Height          =   6855
      Left            =   7080
      TabIndex        =   0
      Top             =   600
      Width           =   6615
      Begin VB.CommandButton btnOpenXml 
         Caption         =   "Seleccionar Archivo"
         Height          =   855
         Left            =   4560
         TabIndex        =   22
         Top             =   480
         Width           =   1695
      End
      Begin VB.TextBox txtXmlB64 
         Height          =   1575
         Left            =   1200
         MultiLine       =   -1  'True
         TabIndex        =   6
         Top             =   3000
         Width           =   5295
      End
      Begin VB.TextBox txtUsuario 
         Height          =   615
         Left            =   1200
         TabIndex        =   5
         Top             =   480
         Width           =   3135
      End
      Begin VB.TextBox txtPass 
         Height          =   615
         Left            =   1200
         TabIndex        =   4
         Top             =   1320
         Width           =   3135
      End
      Begin VB.TextBox txtUrl 
         Height          =   735
         Left            =   1200
         TabIndex        =   3
         Top             =   2160
         Width           =   3135
      End
      Begin VB.TextBox txtstampResult 
         Height          =   1695
         Left            =   1200
         MultiLine       =   -1  'True
         TabIndex        =   2
         Top             =   4800
         Width           =   5295
      End
      Begin VB.CommandButton btnStamp 
         Caption         =   "Timbrar"
         Height          =   1215
         Left            =   4560
         TabIndex        =   1
         Top             =   1680
         Width           =   1695
      End
      Begin VB.Label Label8 
         Caption         =   "Resultado"
         Height          =   615
         Left            =   240
         TabIndex        =   20
         Top             =   5400
         Width           =   735
      End
      Begin VB.Label Label7 
         Caption         =   "Documento a timbrar"
         Height          =   495
         Left            =   120
         TabIndex        =   19
         Top             =   3600
         Width           =   975
      End
      Begin VB.Label Label1 
         Caption         =   "Usuario:"
         Height          =   375
         Left            =   240
         TabIndex        =   9
         Top             =   600
         Width           =   1695
      End
      Begin VB.Label Label2 
         Caption         =   "Password:"
         Height          =   495
         Left            =   240
         TabIndex        =   8
         Top             =   1560
         Width           =   1335
      End
      Begin VB.Label Label3 
         Caption         =   "URL:"
         Height          =   615
         Left            =   240
         TabIndex        =   7
         Top             =   2400
         Width           =   1215
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Function AuthenticationVB Lib "sw-sdk-cpp.dll" (ByVal Url As String, ByVal User As String, ByVal Pass As String, ByVal Token As String) As Long
Private Declare Function StampByTokenVB Lib "sw-sdk-cpp.dll" (ByVal Url As String, ByVal Token As String, ByVal xml As String, ByVal tfd As String) As Long
Private Declare Function StampVB Lib "sw-sdk-cpp.dll" (ByVal Url As String, ByVal User As String, ByVal Pass As String, ByVal xml As String, ByVal tfd As String) As Long
Private Declare Function StampVBV2 Lib "sw-sdk-cpp.dll" (ByVal Url As String, ByVal User As String, ByVal Pass As String, ByVal xml As String, ByVal tfd As String) As Long
Private Declare Function StampVBV3 Lib "sw-sdk-cpp.dll" (ByVal Url As String, ByVal User As String, ByVal Pass As String, ByVal xml As String, ByVal tfd As String) As Long
Private Declare Function StampVBV4 Lib "sw-sdk-cpp.dll" (ByVal Url As String, ByVal User As String, ByVal Pass As String, ByVal xml As String, ByVal tfd As String) As Long
Private Declare Sub InitCommonControls Lib "comctl32.dll" ()


Private Sub btnSeleccionarFactura_Click()
Dim filename As String
Dim adoStream As ADODB.Stream
Dim var_String As String
CommonDialog1.DialogTitle = "Seleccionar Archivo"
CommonDialog1.ShowOpen
filename = CommonDialog1.filename
Set adoStream = New ADODB.Stream
    adoStream.Charset = "UTF-8"
    adoStream.Open
    adoStream.LoadFromFile CommonDialog1.filename
    var_String = adoStream.ReadText
    txtXmlB64.Text = var_String
End Sub

Private Sub btnOpenXml_Click()
CommonDialog1.ShowOpen
filename = CommonDialog1.filename
    Set adoStream = New ADODB.Stream
    adoStream.Charset = "UTF-8"
    adoStream.Open
    adoStream.LoadFromFile CommonDialog1.filename
    var_String = adoStream.ReadText
    txtXmlB64.Text = var_String
End Sub

Private Sub btnStamp_Click()
Dim User As String
Dim Password As String
Dim Url As String
Dim xml As String
Dim nLen As String
Dim tfd As String
tfd = Space$(20000)
Url = Form1.txtUrl.Text
User = Form1.txtUsuario.Text
Password = Form1.txtPass.Text
xml = Form1.txtXmlB64.Text
If Url = "" Or User = "" Or Password = "" Or xml = "" Then
MsgBox ("Debes tener los datos de Url, usuario, Password y Xml")
Else
nLen = StampVB(Url, User, Password, xml, tfd)
Form1.txtstampResult.Text = tfd
End If
End Sub

Private Sub btnToken_Click()
Dim Token As String
Dim User As String
Dim Pass As String
Dim Url As String
Dim nLen As String
Pass = Form1.txtPasswordToken.Text
User = Form1.txtUserToken.Text
Url = Form1.txtUrlToken.Text
Token = Space$(1024)
If Pass = "" Or User = "" Or Url = "" Then
    MsgBox ("Debes tener los datos de Url, usuario y contraseña")
Else
    nLen = AuthenticationVB(Url, User, Pass, Token)
    Form1.txtToken.Text = Token
End If
End Sub

Private Sub Form_Initialize()
    InitCommonControls
    ChDir App.Path
    Form1.txtUsuario.Text = "demo"
    Form1.txtPass.Text = "123456789"
    Form1.txtUrl.Text = "http://swservicestest-rc.azurewebsites.net"
    Form1.txtPasswordToken.Text = "123456789"
    Form1.txtUserToken.Text = "demo"
    Form1.txtUrlToken.Text = "http://swservicestest-rc.azurewebsites.net"
End Sub

