VERSION 5.00
Object = "{BDC217C8-ED16-11CD-956C-0000C04E4C0A}#1.1#0"; "TABCTL32.OCX"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   8160
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   16935
   LinkTopic       =   "Form1"
   ScaleHeight     =   8160
   ScaleWidth      =   16935
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton btnGetToken 
      Caption         =   "Obtener Token"
      BeginProperty Font 
         Name            =   "Arial Narrow"
         Size            =   14.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   3480
      TabIndex        =   6
      Top             =   3960
      Width           =   2055
   End
   Begin VB.TextBox txtToken 
      Height          =   2295
      Left            =   600
      TabIndex        =   2
      Top             =   4800
      Width           =   9375
   End
   Begin VB.CommandButton Command1 
      Caption         =   "GetCPUSpeed"
      Height          =   375
      Left            =   14280
      TabIndex        =   0
      Top             =   5280
      Width           =   1215
   End
   Begin TabDlg.SSTab SSTab1 
      Height          =   7095
      Left            =   360
      TabIndex        =   7
      Top             =   480
      Width           =   10095
      _ExtentX        =   17806
      _ExtentY        =   12515
      _Version        =   393216
      TabHeight       =   520
      TabCaption(0)   =   "Autenticar"
      TabPicture(0)   =   "Form1.frx":0000
      Tab(0).ControlEnabled=   -1  'True
      Tab(0).Control(0)=   "lblUrl(0)"
      Tab(0).Control(0).Enabled=   0   'False
      Tab(0).Control(1)=   "lblUsuario(1)"
      Tab(0).Control(1).Enabled=   0   'False
      Tab(0).Control(2)=   "lblContrasena"
      Tab(0).Control(2).Enabled=   0   'False
      Tab(0).Control(3)=   "txtUrl(0)"
      Tab(0).Control(3).Enabled=   0   'False
      Tab(0).Control(4)=   "txtUsuario"
      Tab(0).Control(4).Enabled=   0   'False
      Tab(0).Control(5)=   "txtContrasena"
      Tab(0).Control(5).Enabled=   0   'False
      Tab(0).ControlCount=   6
      TabCaption(1)   =   "TimbrarV1"
      TabPicture(1)   =   "Form1.frx":001C
      Tab(1).ControlEnabled=   0   'False
      Tab(1).ControlCount=   0
      TabCaption(2)   =   "Cancelar"
      TabPicture(2)   =   "Form1.frx":0038
      Tab(2).ControlEnabled=   0   'False
      Tab(2).ControlCount=   0
      Begin VB.TextBox txtContrasena 
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
         Left            =   2040
         TabIndex        =   12
         Top             =   2640
         Width           =   3135
      End
      Begin VB.TextBox txtUsuario 
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
         Left            =   2040
         TabIndex        =   10
         Top             =   1680
         Width           =   3135
      End
      Begin VB.TextBox txtUrl 
         BeginProperty Font 
            Name            =   "Arial Narrow"
            Size            =   15.75
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   675
         Index           =   0
         Left            =   2040
         TabIndex        =   1
         Top             =   720
         Width           =   3135
      End
      Begin VB.Label lblContrasena 
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
         Height          =   735
         Left            =   240
         TabIndex        =   11
         Top             =   2760
         Width           =   1695
      End
      Begin VB.Label lblUsuario 
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
         Height          =   495
         Index           =   1
         Left            =   600
         TabIndex        =   9
         Top             =   1680
         Width           =   1215
      End
      Begin VB.Label lblUrl 
         Caption         =   "Url:"
         BeginProperty Font 
            Name            =   "Arial Narrow"
            Size            =   15.75
            Charset         =   0
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   495
         Index           =   0
         Left            =   1080
         TabIndex        =   8
         Top             =   720
         Width           =   735
      End
   End
   Begin VB.CommandButton Command5 
      Caption         =   "FillString()"
      Height          =   615
      Left            =   15960
      TabIndex        =   5
      Top             =   3480
      Width           =   2415
   End
   Begin VB.CommandButton Command3 
      Caption         =   "GetTocken"
      Height          =   495
      Left            =   10800
      TabIndex        =   4
      Top             =   2640
      Width           =   1335
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Sumar"
      Height          =   495
      Left            =   10800
      TabIndex        =   3
      Top             =   1920
      Width           =   855
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Declare Function Suma Lib "MathDLL.dll" (ByVal x As Integer, ByVal y As Integer) As Integer
Private Declare Function GetCpuSpeed Lib "MathDLL.dll" () As Integer
Private Declare Function WritestStr Lib "MathDLL.dll" (ByVal mystr As String) As Long
Private Declare Function GetTocken Lib "MathDLL.dll" (ByVal user As String, ByVal pass As String, ByVal Token As String) As Long
Private Declare Function Authentication Lib "sw-sdk-cpp.dll" (ByRef url As String, ByRef user As String, ByRef pass As String) As Long
Private Declare Function AuthenticationVB Lib "sw-sdk-cpp.dll" (ByVal url As String, ByVal user As String, ByVal pass As String, ByVal Token As String) As Long
Private Declare Sub InitCommonControls Lib "comctl32.dll" ()


Private Sub btnGetToken_Click()
Dim Token As String
Dim user As String
Dim pass As String
Dim url As String
Dim nLen As String
pass = Form1.txtContrasena.Text
user = Form1.txtUsuario.Text
url = Form1.txtUrl.Text
Token = Space$(1024)
nLen = AuthenticationVB(url, user, pass, Token)
Form1.txtToken.Text = Token
End Sub

Private Sub Command2_Click()
Dim result As Integer
Dim sum As String


result = Suma(10, 30)
sum = result
Form1.Text1.Text = "Suma() returned " + sum
End Sub

Private Sub Command3_Click()
 Dim Token As String
 Dim nLen As Long
 Dim user As String
 Dim pass As String
 
 pass = "123456789"
 user = "demo"
 Token = Space$(1024)
 nLen = GetTocken(user, pass, Token)
Form1.Text1.Text = "GetString() returned " + Token
End Sub


Private Sub Command4_Click()
Dim Token As String
Dim user As String
Dim pass As String
Dim url As String
Dim nLen As String
pass = "123456789"
user = "demo"
url = "http://services.test.sw.com.mx"
Token = Space$(1024)
nLen = AuthenticationVB(url, user, pass, Token)
Form1.Text1.Text = "Token: " + Token
End Sub

Private Sub Command5_Click()
 Dim mystr As String
 Dim nLen As Long
 mystr = Space$(1024)
 nLen = WritestStr(mystr)
Form1.Text1.Text = "GetString() returned " + mystr
End Sub

Private Sub Form_Initialize()
    InitCommonControls
    ChDir App.Path

End Sub

Private Sub Command1_Click()
Dim nSpeed As Integer
    Dim s As String
    
    Screen.MousePointer = vbHourglass
    nSpeed = GetCpuSpeed()
    Screen.MousePointer = 0
    
    s = nSpeed
    
    Form1.Text1.Text = "GetCpuSpeed() returned " + s



End Sub

Private Sub Form_Load()

    Form1.Text1.Text = ""
    
End Sub

Private Sub lblContrasena_Click()

End Sub

Private Sub lblUrl_Click(Index As Integer)

End Sub

Private Sub SSTab1_DblClick()

End Sub

Private Sub txtUrl_Change(Index As Integer)

End Sub
