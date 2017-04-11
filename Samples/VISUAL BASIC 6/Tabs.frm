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
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   11880
      Top             =   2160
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin TabDlg.SSTab SSTab2 
      Height          =   9135
      Left            =   720
      TabIndex        =   0
      Top             =   120
      Width           =   9855
      _ExtentX        =   17383
      _ExtentY        =   16113
      _Version        =   393216
      Tab             =   1
      TabHeight       =   520
      TabCaption(0)   =   "Autenticación"
      TabPicture(0)   =   "Tabs.frx":0000
      Tab(0).ControlEnabled=   0   'False
      Tab(0).Control(0)=   "btnGetToken"
      Tab(0).Control(1)=   "txtToken"
      Tab(0).Control(2)=   "txtPass"
      Tab(0).Control(3)=   "txtUser"
      Tab(0).Control(4)=   "txtUrl"
      Tab(0).Control(5)=   "Label2"
      Tab(0).Control(6)=   "Label1"
      Tab(0).Control(7)=   "lblUrl"
      Tab(0).ControlCount=   8
      TabCaption(1)   =   "Timbrado"
      TabPicture(1)   =   "Tabs.frx":001C
      Tab(1).ControlEnabled=   -1  'True
      Tab(1).ControlCount=   0
      TabCaption(2)   =   "Cancelación"
      TabPicture(2)   =   "Tabs.frx":0038
      Tab(2).ControlEnabled=   0   'False
      Tab(2).ControlCount=   0
      Begin VB.CommandButton btnGetToken 
         Caption         =   "Obtener Token"
         Height          =   615
         Left            =   -72840
         TabIndex        =   8
         Top             =   4200
         Width           =   2655
      End
      Begin VB.TextBox txtToken 
         Height          =   3375
         Left            =   -74880
         TabIndex        =   7
         Top             =   5520
         Width           =   9375
      End
      Begin VB.TextBox txtPass 
         Height          =   615
         Left            =   -72840
         TabIndex        =   4
         Top             =   3360
         Width           =   2655
      End
      Begin VB.TextBox txtUser 
         Height          =   615
         Left            =   -72840
         TabIndex        =   3
         Top             =   2280
         Width           =   2655
      End
      Begin VB.TextBox txtUrl 
         Height          =   615
         Left            =   -72840
         TabIndex        =   1
         Top             =   1200
         Width           =   2655
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
         Left            =   -74160
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
         Left            =   -73800
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
         Left            =   -73560
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
Private Declare Function Authentication Lib "sw-sdk-cpp.dll" (ByRef url As String, ByRef user As String, ByRef pass As String) As Long
Private Declare Function AuthenticationVB Lib "sw-sdk-cpp.dll" (ByVal url As String, ByVal user As String, ByVal pass As String, ByVal Token As String) As Long
Private Declare Sub InitCommonControls Lib "comctl32.dll" ()

Private Sub Form_Initialize()
    InitCommonControls
    ChDir App.Path

End Sub
Private Sub btnGetToken_Click()
Form1.txtToken.Text = ""
Dim Token As String
Dim user As String
Dim pass As String
Dim url As String
Dim nLen As String
pass = Form1.txtPass.Text
user = Form1.txtUser.Text
url = Form1.txtUrl.Text
Token = Space$(1024)
nLen = AuthenticationVB(url, user, pass, Token)
Form1.txtToken.Text = Token
End Sub



Private Sub Form_Load()

    Form1.txtToken.Text = ""
    CommonDialog1.Filter = "Apps (*.xml)|*.xml|All files (*.*)|*.*"
    CommonDialog1.DefaultExt = "xml"
    CommonDialog1.DialogTitle = "Select File"
    CommonDialog1.ShowOpen
End Sub

