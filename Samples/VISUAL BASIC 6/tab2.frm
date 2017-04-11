VERSION 5.00
Object = "{BDC217C8-ED16-11CD-956C-0000C04E4C0A}#1.1#0"; "TABCTL32.OCX"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   10950
   ClientLeft      =   225
   ClientTop       =   555
   ClientWidth     =   20250
   LinkTopic       =   "Form1"
   ScaleHeight     =   10950
   ScaleWidth      =   20250
   StartUpPosition =   3  'Windows Default
   Begin TabDlg.SSTab SSTab2 
      Height          =   9135
      Left            =   720
      TabIndex        =   0
      Top             =   120
      Width           =   9855
      _ExtentX        =   17383
      _ExtentY        =   16113
      _Version        =   393216
      TabHeight       =   520
      TabCaption(0)   =   "Autenticación"
      TabPicture(0)   =   "tab2.frx":0000
      Tab(0).ControlEnabled=   -1  'True
      Tab(0).Control(0)=   "lblUrl"
      Tab(0).Control(0).Enabled=   0   'False
      Tab(0).Control(1)=   "Label1"
      Tab(0).Control(1).Enabled=   0   'False
      Tab(0).Control(2)=   "Label2"
      Tab(0).Control(2).Enabled=   0   'False
      Tab(0).Control(3)=   "txtUrl"
      Tab(0).Control(3).Enabled=   0   'False
      Tab(0).Control(4)=   "txtUser"
      Tab(0).Control(4).Enabled=   0   'False
      Tab(0).Control(5)=   "txtPass"
      Tab(0).Control(5).Enabled=   0   'False
      Tab(0).Control(6)=   "txtToken"
      Tab(0).Control(6).Enabled=   0   'False
      Tab(0).Control(7)=   "btnGetToken"
      Tab(0).Control(7).Enabled=   0   'False
      Tab(0).Control(8)=   "btnCleanAuthentication"
      Tab(0).Control(8).Enabled=   0   'False
      Tab(0).ControlCount=   9
      TabCaption(1)   =   "Timbrado"
      TabPicture(1)   =   "tab2.frx":001C
      Tab(1).ControlEnabled=   0   'False
      Tab(1).Control(0)=   "btnCleanStampResult"
      Tab(1).Control(1)=   "btnStampUser"
      Tab(1).Control(2)=   "txtInvoiceStamped"
      Tab(1).Control(3)=   "txtXMLInvoice"
      Tab(1).Control(4)=   "CommonDialog1"
      Tab(1).Control(5)=   "btnStamp"
      Tab(1).Control(6)=   "btnSelectXml"
      Tab(1).Control(7)=   "txtTolkenStamp"
      Tab(1).Control(8)=   "txtPasswordStamp"
      Tab(1).Control(9)=   "txtUserStamp"
      Tab(1).Control(10)=   "txtUrlStamp"
      Tab(1).Control(11)=   "Label6"
      Tab(1).Control(12)=   "Label5"
      Tab(1).Control(13)=   "Label4"
      Tab(1).Control(14)=   "Label3"
      Tab(1).ControlCount=   15
      TabCaption(2)   =   "Cancelación"
      TabPicture(2)   =   "tab2.frx":0038
      Tab(2).ControlEnabled=   0   'False
      Tab(2).ControlCount=   0
      Begin VB.CommandButton btnCleanStampResult 
         Caption         =   "Limpiar XML y respuesta"
         Height          =   495
         Left            =   -67440
         TabIndex        =   23
         Top             =   5160
         Width           =   1935
      End
      Begin VB.CommandButton btnCleanAuthentication 
         Caption         =   "Limpiar Respuesta"
         Height          =   495
         Left            =   8400
         TabIndex        =   22
         Top             =   8400
         Width           =   1095
      End
      Begin VB.CommandButton btnStampUser 
         Caption         =   "Timbrar Sin Token"
         Height          =   495
         Left            =   -69840
         TabIndex        =   21
         Top             =   5160
         Width           =   1935
      End
      Begin VB.TextBox txtInvoiceStamped 
         Height          =   1335
         Left            =   -74760
         TabIndex        =   16
         Top             =   7560
         Width           =   9255
      End
      Begin VB.TextBox txtXMLInvoice 
         Height          =   1335
         Left            =   -74760
         TabIndex        =   15
         Top             =   6000
         Width           =   9255
      End
      Begin MSComDlg.CommonDialog CommonDialog1 
         Left            =   -74400
         Top             =   5160
         _ExtentX        =   847
         _ExtentY        =   847
         _Version        =   393216
      End
      Begin VB.CommandButton btnStamp 
         Caption         =   "Timbrar con Token"
         Height          =   495
         Left            =   -72000
         TabIndex        =   14
         Top             =   5160
         Width           =   1935
      End
      Begin VB.CommandButton btnSelectXml 
         Caption         =   "Seleccionar XML"
         Height          =   495
         Left            =   -74280
         TabIndex        =   13
         Top             =   5160
         Width           =   1935
      End
      Begin VB.TextBox txtTolkenStamp 
         Height          =   615
         Left            =   -72480
         TabIndex        =   12
         Top             =   4080
         Width           =   2415
      End
      Begin VB.TextBox txtPasswordStamp 
         Height          =   615
         Left            =   -72480
         TabIndex        =   11
         Text            =   "123456789"
         Top             =   3000
         Width           =   2415
      End
      Begin VB.TextBox txtUserStamp 
         Height          =   615
         Left            =   -72480
         TabIndex        =   10
         Text            =   "demo"
         Top             =   1920
         Width           =   2415
      End
      Begin VB.TextBox txtUrlStamp 
         Height          =   615
         Left            =   -72480
         TabIndex        =   9
         Text            =   "http://services.test.sw.com.mx"
         Top             =   960
         Width           =   2415
      End
      Begin VB.CommandButton btnGetToken 
         Caption         =   "Obtener Token"
         Height          =   615
         Left            =   2160
         TabIndex        =   8
         Top             =   4200
         Width           =   2655
      End
      Begin VB.TextBox txtToken 
         Height          =   3375
         Left            =   120
         TabIndex        =   7
         Top             =   5520
         Width           =   9375
      End
      Begin VB.TextBox txtPass 
         Height          =   615
         Left            =   2160
         TabIndex        =   4
         Text            =   "123456789"
         Top             =   3360
         Width           =   2655
      End
      Begin VB.TextBox txtUser 
         Height          =   615
         Left            =   2160
         TabIndex        =   3
         Text            =   "demo"
         Top             =   2280
         Width           =   2655
      End
      Begin VB.TextBox txtUrl 
         Height          =   615
         Left            =   2160
         TabIndex        =   1
         Text            =   "http://services.test.sw.com.mx"
         Top             =   1200
         Width           =   2655
      End
      Begin VB.Label Label6 
         Caption         =   "Token:"
         BeginProperty Font 
            Name            =   "Arial Narrow"
            Size            =   15.75
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   615
         Left            =   -73800
         TabIndex        =   20
         Top             =   4080
         Width           =   855
      End
      Begin VB.Label Label5 
         Caption         =   "Contraseña:"
         BeginProperty Font 
            Name            =   "Arial Narrow"
            Size            =   15.75
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   615
         Left            =   -74400
         TabIndex        =   19
         Top             =   3120
         Width           =   1575
      End
      Begin VB.Label Label4 
         Caption         =   "Usuario:"
         BeginProperty Font 
            Name            =   "Arial Narrow"
            Size            =   15.75
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   615
         Left            =   -73920
         TabIndex        =   18
         Top             =   2040
         Width           =   1215
      End
      Begin VB.Label Label3 
         Caption         =   "URL:"
         BeginProperty Font 
            Name            =   "Arial Narrow"
            Size            =   15.75
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   615
         Left            =   -73440
         TabIndex        =   17
         Top             =   1080
         Width           =   855
      End
      Begin VB.Label Label2 
         Caption         =   "Contraseña:"
         BeginProperty Font 
            Name            =   "Arial Narrow"
            Size            =   11.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   495
         Left            =   840
         TabIndex        =   6
         Top             =   3480
         Width           =   1095
      End
      Begin VB.Label Label1 
         Caption         =   "Usuario:"
         BeginProperty Font 
            Name            =   "Arial Narrow"
            Size            =   11.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   495
         Left            =   1200
         TabIndex        =   5
         Top             =   2400
         Width           =   735
      End
      Begin VB.Label lblUrl 
         Caption         =   "URL:"
         BeginProperty Font 
            Name            =   "Arial Narrow"
            Size            =   11.25
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   495
         Left            =   1440
         TabIndex        =   2
         Top             =   1320
         Width           =   735
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
Private Declare Sub InitCommonControls Lib "comctl32.dll" ()

Private Sub btnCleanAuthentication_Click()
Form1.txtToken.Text = ""
End Sub

Private Sub btnCleanStampResult_Click()
Form1.txtInvoiceStamped.Text = ""
Form1.txtXMLInvoice.Text = ""
End Sub

Private Sub btnSelectXml_Click()
Dim filename As String
Dim adoStream As ADODB.Stream
Dim var_String As String
CommonDialog1.Filter = "Apps (*.xml)|*.xml|All files (*.*)|*.*"
CommonDialog1.DefaultExt = "xml"
CommonDialog1.DialogTitle = "Seleccionar Archivo"
CommonDialog1.ShowOpen

filename = CommonDialog1.filename
    Set adoStream = New ADODB.Stream
    adoStream.Charset = "UTF-8"
    adoStream.Open
    adoStream.LoadFromFile CommonDialog1.filename
    var_String = adoStream.ReadText
    Form1.txtXMLInvoice.Text = var_String
End Sub

Private Sub btnStamp_Click()
Dim Token As String
Dim Url As String
Dim xml As String
Dim nLen As String
Dim tfd As String
tfd = Space$(10000)
Url = Form1.txtUrlStamp.Text
xml = Form1.txtXMLInvoice.Text
Token = Form1.txtTolkenStamp.Text

If Url = "" Or xml = "" Or Token = "" Then
MsgBox ("Debes tener los datos de Url, Token y Xml")
Else
nLen = StampByTokenVB(Url, Token, xml, tfd)
Form1.txtInvoiceStamped.Text = tfd
End If
End Sub

Private Sub btnStampUser_Click()
Dim User As String
Dim Password As String
Dim Url As String
Dim xml As String
Dim nLen As String
Dim tfd As String
tfd = Space$(10000)
Url = Form1.txtUrlStamp.Text
User = Form1.txtUrlStamp.Text
Password = Form1.txtPasswordStamp.Text
xml = Form1.txtXMLInvoice.Text

If Url = "" Or User = "" Or Password = "" Or xml = "" Then
MsgBox ("Debes tener los datos de Url, usuario, Password y Xml")
Else
nLen = StampVB(Url, User, Password, xml, tfd)
Form1.txtInvoiceStamped.Text = tfd
End If
End Sub

Private Sub Form_Initialize()
    InitCommonControls
    ChDir App.Path

End Sub
Private Sub btnGetToken_Click()
Form1.txtToken.Text = ""

Dim Token As String
Dim User As String
Dim Pass As String
Dim Url As String
Dim nLen As String
Pass = Form1.txtPass.Text
User = Form1.txtUser.Text
Url = Form1.txtUrl.Text
Token = Space$(1024)

If Pass = "" Or User = "" Or Url = "" Then
    MsgBox ("Debes tener los datos de Url, usuario y contraseña")
Else
    nLen = AuthenticationVB(Url, User, Pass, Token)
    Form1.txtToken.Text = Token
End If
End Sub



Private Sub Form_Load()

    Form1.txtToken.Text = ""
    Form1.txtTolkenStamp.Text = "T2lYQ0t4L0RHVkR4dHZ5Nkk1VHNEakZ3Y0J4Nk9GODZuRyt4cE1wVm5tbXB3YVZxTHdOdHAwVXY2NTdJb1hkREtXTzE3dk9pMmdMdkFDR2xFWFVPUXpTUm9mTG1ySXdZbFNja3FRa0RlYURqbzdzdlI2UUx1WGJiKzViUWY2dnZGbFloUDJ6RjhFTGF4M1BySnJ4cHF0YjUvbmRyWWpjTkVLN3ppd3RxL0dJPQ.T2lYQ0t4L0RHVkR4dHZ5Nkk1VHNEakZ3Y0J4Nk9GODZuRyt4cE1wVm5tbFlVcU92YUJTZWlHU3pER1kySnlXRTF4alNUS0ZWcUlVS0NhelhqaXdnWTRncklVSWVvZlFZMWNyUjVxYUFxMWFxcStUL1IzdGpHRTJqdS9Zakw2UGRiMTFPRlV3a2kyOWI5WUZHWk85ODJtU0M2UlJEUkFTVXhYTDNKZVdhOXIySE1tUVlFdm1jN3kvRStBQlpLRi9NeWJrd0R3clhpYWJrVUMwV0Mwd3FhUXdpUFF5NW5PN3J5cklMb0FETHlxVFRtRW16UW5ZVjAwUjdCa2g0Yk1iTExCeXJkVDRhMGMxOUZ1YWlIUWRRVC8yalFTNUczZXdvWlF0cSt2UW0waFZKY2gyaW5jeElydXN3clNPUDNvU1J2dm9weHBTSlZYNU9aaGsvalpQMUxrUndzK0dHS2dpTittY1JmR3o2M3NqNkh4MW9KVXMvUHhZYzVLQS9UK2E1SVhEZFJKYWx4ZmlEWDFuSXlqc2ZRYXlUQk1ldlZkU2tEdU10NFVMdHZKUURLblBxakw0SDl5bUxabDFLNmNPbEp6b3Jtd2Q1V2htRHlTdDZ6eTFRdUNnYnVvK2tuVUdhMmwrVWRCZi9rQkU9.7k2gVCGSZKLzJK5Ky3Nr5tKxvGSJhL13Q8W-YhT0uIo"
End Sub

Private Sub Text1_Change()

End Sub

