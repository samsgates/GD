#if defined(FILETOBEDELETED)

#include "GDL/IDE/Dialogs/OldSpriteObjectEditor.h"

//(*InternalHeaders(OldSpriteObjectEditor)
#include <wx/bitmap.h>
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)
#include <wx/log.h>
#include <wx/ribbon/toolbar.h>
#include <wx/msgdlg.h>
#include <string>
#include <vector>
#include <wx/help.h>
#include <wx/numdlg.h>
#include <wx/config.h>
#include <sstream>
#include <wx/dcbuffer.h>
#include <wx/settings.h>
#include <wx/textdlg.h>
#include <wx/choicdlg.h>
#include <wx/textdlg.h>
#include <wx/msgdlg.h>

#include "GDCore/Tools/HelpFileAccess.h"
#include "GDL/CommonTools.h"
#include "GDL/Game.h"
#include "GDL/Animation.h"
#include "GDL/Direction.h"
#include "GDL/Sprite.h"
#include "GDL/CommonTools.h"
#include "GDL/IDE/MainEditorCommand.h"
#include "GDL/IDE/Dialogs/AjoutPlusImage.h"
#include "GDCore/IDE/CommonBitmapManager.h"

#ifdef __WXGTK__
#include <gtk/gtk.h>
#endif

using namespace std;

//(*IdInit(OldSpriteObjectEditor)
const long OldSpriteObjectEditor::ID_STATICTEXT6 = wxNewId();
const long OldSpriteObjectEditor::ID_STATICTEXT1 = wxNewId();
const long OldSpriteObjectEditor::ID_PANEL2 = wxNewId();
const long OldSpriteObjectEditor::ID_STATICLINE1 = wxNewId();
const long OldSpriteObjectEditor::ID_CHOICE1 = wxNewId();
const long OldSpriteObjectEditor::ID_BUTTON1 = wxNewId();
const long OldSpriteObjectEditor::ID_BUTTON2 = wxNewId();
const long OldSpriteObjectEditor::ID_CHECKBOX1 = wxNewId();
const long OldSpriteObjectEditor::ID_TOGGLEBUTTON8 = wxNewId();
const long OldSpriteObjectEditor::ID_TOGGLEBUTTON7 = wxNewId();
const long OldSpriteObjectEditor::ID_TOGGLEBUTTON6 = wxNewId();
const long OldSpriteObjectEditor::ID_TOGGLEBUTTON5 = wxNewId();
const long OldSpriteObjectEditor::ID_STATICBITMAP2 = wxNewId();
const long OldSpriteObjectEditor::ID_TOGGLEBUTTON1 = wxNewId();
const long OldSpriteObjectEditor::ID_TOGGLEBUTTON2 = wxNewId();
const long OldSpriteObjectEditor::ID_TOGGLEBUTTON3 = wxNewId();
const long OldSpriteObjectEditor::ID_TOGGLEBUTTON4 = wxNewId();
const long OldSpriteObjectEditor::ID_CHECKBOX2 = wxNewId();
const long OldSpriteObjectEditor::ID_AUITOOLBAR1 = wxNewId();
const long OldSpriteObjectEditor::ID_PANEL6 = wxNewId();
const long OldSpriteObjectEditor::ID_STATICLINE3 = wxNewId();
const long OldSpriteObjectEditor::ID_PANEL3 = wxNewId();
const long OldSpriteObjectEditor::ID_SCROLLBAR1 = wxNewId();
const long OldSpriteObjectEditor::ID_SCROLLBAR3 = wxNewId();
const long OldSpriteObjectEditor::ID_PANEL4 = wxNewId();
const long OldSpriteObjectEditor::ID_SCROLLBAR2 = wxNewId();
const long OldSpriteObjectEditor::ID_PANEL5 = wxNewId();
const long OldSpriteObjectEditor::ID_STATICBITMAP1 = wxNewId();
const long OldSpriteObjectEditor::ID_STATICTEXT2 = wxNewId();
const long OldSpriteObjectEditor::ID_TEXTCTRL2 = wxNewId();
const long OldSpriteObjectEditor::ID_STATICTEXT3 = wxNewId();
const long OldSpriteObjectEditor::ID_STATICTEXT4 = wxNewId();
const long OldSpriteObjectEditor::ID_RADIOBUTTON3 = wxNewId();
const long OldSpriteObjectEditor::ID_RADIOBUTTON4 = wxNewId();
const long OldSpriteObjectEditor::ID_STATICLINE2 = wxNewId();
const long OldSpriteObjectEditor::ID_BUTTON3 = wxNewId();
const long OldSpriteObjectEditor::ID_BUTTON5 = wxNewId();
const long OldSpriteObjectEditor::ID_BUTTON4 = wxNewId();
const long OldSpriteObjectEditor::ID_PANEL1 = wxNewId();
const long OldSpriteObjectEditor::idMenuAddFromEnd = wxNewId();
const long OldSpriteObjectEditor::idMenuAddFromAfter = wxNewId();
const long OldSpriteObjectEditor::idMenuAddFromBefore = wxNewId();
const long OldSpriteObjectEditor::ID_MENUITEM1 = wxNewId();
const long OldSpriteObjectEditor::idMenuAddMoreEnd = wxNewId();
const long OldSpriteObjectEditor::idMenuAddMoreAfter = wxNewId();
const long OldSpriteObjectEditor::idMenuAddMoreBefore = wxNewId();
const long OldSpriteObjectEditor::idMenuAddMulti = wxNewId();
const long OldSpriteObjectEditor::idMenuDel = wxNewId();
const long OldSpriteObjectEditor::idMenuDelAll = wxNewId();
const long OldSpriteObjectEditor::idMenuCopyFrom = wxNewId();
const long OldSpriteObjectEditor::idPosPoint = wxNewId();
const long OldSpriteObjectEditor::ID_MENUITEM3 = wxNewId();
const long OldSpriteObjectEditor::ID_MENUITEM5 = wxNewId();
const long OldSpriteObjectEditor::ID_MENUITEM8 = wxNewId();
const long OldSpriteObjectEditor::ID_MENUITEM9 = wxNewId();
const long OldSpriteObjectEditor::ID_MENUITEM6 = wxNewId();
const long OldSpriteObjectEditor::idMenuPosEverywhere2 = wxNewId();
const long OldSpriteObjectEditor::ID_MENUITEM4 = wxNewId();
const long OldSpriteObjectEditor::ID_MENUITEM13 = wxNewId();
const long OldSpriteObjectEditor::ID_MENUITEM12 = wxNewId();
const long OldSpriteObjectEditor::ID_MENUITEM10 = wxNewId();
const long OldSpriteObjectEditor::ID_MENUITEM11 = wxNewId();
const long OldSpriteObjectEditor::ID_MENUITEM2 = wxNewId();
const long OldSpriteObjectEditor::ID_MENUITEM7 = wxNewId();
const long OldSpriteObjectEditor::idMenuPosEverywhere = wxNewId();
const long OldSpriteObjectEditor::ID_MENUITEM14 = wxNewId();
const long OldSpriteObjectEditor::idAddPoint = wxNewId();
const long OldSpriteObjectEditor::idDelPoint = wxNewId();
//*)

const long OldSpriteObjectEditor::ID_BUTTONARRAY = wxNewId();
const long OldSpriteObjectEditor::ID_BITMAPARRAY = wxNewId();
const long OldSpriteObjectEditor::ID_EDITARRAY = wxNewId();

BEGIN_EVENT_TABLE( OldSpriteObjectEditor, wxDialog )
    //(*EventTable(OldSpriteObjectEditor)
    //*)
END_EVENT_TABLE()

OldSpriteObjectEditor::OldSpriteObjectEditor( wxWindow* parent, Game & game_, SpriteObject & object_, MainEditorCommand & mainEditorCommand_ ) :
animation(0),
direction(0),
position(0),
game(game_),
mainEditorCommand(mainEditorCommand_),
object(object_),
selectedImage(0),
placingPoint(false),
spritePosX(0),
spritePosY(0),
editingMask(false),
movingBox(false),
selectedBox(0),
xSelectionOffset(0),
ySelectionOffset(0)
{
    //(*Initialize(OldSpriteObjectEditor)
    wxFlexGridSizer* FlexGridSizer16;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer5;
    wxFlexGridSizer* FlexGridSizer9;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer2;
    wxFlexGridSizer* FlexGridSizer7;
    wxFlexGridSizer* thumbsSizer;
    wxFlexGridSizer* FlexGridSizer15;
    wxFlexGridSizer* FlexGridSizer8;
    wxStaticBoxSizer* animationSizer;
    wxFlexGridSizer* FlexGridSizer14;
    wxFlexGridSizer* FlexGridSizer13;
    wxFlexGridSizer* FlexGridSizer12;
    wxFlexGridSizer* FlexGridSizer6;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer11;
    wxFlexGridSizer* FlexGridSizer17;

    Create(parent, wxID_ANY, _("Editer l\'objet"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(356,215));
    wxIcon FrameIcon;
    FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("res/objeticon.png"))));
    SetIcon(FrameIcon);
    FlexGridSizer1 = new wxFlexGridSizer(1, 1, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(0);
    Core = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer2->AddGrowableCol(0);
    FlexGridSizer2->AddGrowableRow(0);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer3->AddGrowableCol(0);
    FlexGridSizer3->AddGrowableRow(0);
    Panel2 = new wxPanel(Core, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    Panel2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    FlexGridSizer12 = new wxFlexGridSizer(0, 3, 0, 0);
    StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT6, _("Objet :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer12->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    NomObjetTxt = new wxStaticText(Panel2, ID_STATICTEXT1, _("Sans nom"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont NomObjetTxtFont(wxDEFAULT,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    NomObjetTxt->SetFont(NomObjetTxtFont);
    FlexGridSizer12->Add(NomObjetTxt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2->SetSizer(FlexGridSizer12);
    FlexGridSizer12->Fit(Panel2);
    FlexGridSizer12->SetSizeHints(Panel2);
    FlexGridSizer3->Add(Panel2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer2->Add(FlexGridSizer3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    StaticLine1 = new wxStaticLine(Core, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer2->Add(StaticLine1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer4 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer4->AddGrowableCol(0);
    FlexGridSizer4->AddGrowableRow(1);
    animationSizer = new wxStaticBoxSizer(wxHORIZONTAL, Core, _("Animation"));
    FlexGridSizer5 = new wxFlexGridSizer(1, 3, 0, 0);
    AnimationsBox = new wxChoice(Core, ID_CHOICE1, wxDefaultPosition, wxSize(139,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    AnimationsBox->Append(_("Pas d\'animations"));
    FlexGridSizer5->Add(AnimationsBox, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    AddAnimBt = new wxButton(Core, ID_BUTTON1, _("Ajouter une animation"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    AddAnimBt->SetToolTip(_("Ajoutez des animations � l\'objet avec ce bouton."));
    FlexGridSizer5->Add(AddAnimBt, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DelAnimBt = new wxButton(Core, ID_BUTTON2, _("Supprimer l\'animation"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    DelAnimBt->SetToolTip(_("Supprime l\'animation actuelle."));
    FlexGridSizer5->Add(DelAnimBt, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    animationSizer->Add(FlexGridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer4->Add(animationSizer, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer10 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer10->AddGrowableCol(0);
    FlexGridSizer10->AddGrowableRow(0);
    animAndDirecSizer = new wxFlexGridSizer(0, 2, 0, 0);
    animAndDirecSizer->AddGrowableCol(1);
    animAndDirecSizer->AddGrowableRow(0);
    directionSizer = new wxStaticBoxSizer(wxHORIZONTAL, Core, _("Direction"));
    FlexGridSizer6 = new wxFlexGridSizer(0, 1, 0, 0);
    NormalCheck = new wxCheckBox(Core, ID_CHECKBOX1, _("Normal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    NormalCheck->SetValue(false);
    NormalCheck->SetToolTip(_("En mode normal, 8 directions sont disponibles.\nVous pouvez changer la direction de l\'objet en cours de jeu gr�ce aux actions du th�me \"Direction\"."));
    FlexGridSizer6->Add(NormalCheck, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer3 = new wxGridSizer(3, 3, 0, 0);
    Bt5 = new wxToggleButton(Core, ID_TOGGLEBUTTON8, _("5"), wxDefaultPosition, wxSize(26,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON8"));
    GridSizer3->Add(Bt5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Bt6 = new wxToggleButton(Core, ID_TOGGLEBUTTON7, _("6"), wxDefaultPosition, wxSize(26,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON7"));
    GridSizer3->Add(Bt6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Bt7 = new wxToggleButton(Core, ID_TOGGLEBUTTON6, _("7"), wxDefaultPosition, wxSize(26,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON6"));
    GridSizer3->Add(Bt7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Bt4 = new wxToggleButton(Core, ID_TOGGLEBUTTON5, _("4"), wxDefaultPosition, wxSize(26,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON5"));
    GridSizer3->Add(Bt4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    StaticBitmap1 = new wxStaticBitmap(Core, ID_STATICBITMAP2, wxBitmap(wxImage(_T("res/direction.png")).Rescale(wxSize(25,25).GetWidth(),wxSize(25,25).GetHeight())), wxDefaultPosition, wxSize(25,25), wxNO_BORDER, _T("ID_STATICBITMAP2"));
    GridSizer3->Add(StaticBitmap1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Bt0 = new wxToggleButton(Core, ID_TOGGLEBUTTON1, _("0"), wxDefaultPosition, wxSize(26,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
    Bt0->SetValue(true);
    GridSizer3->Add(Bt0, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Bt3 = new wxToggleButton(Core, ID_TOGGLEBUTTON2, _("3"), wxDefaultPosition, wxSize(26,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON2"));
    GridSizer3->Add(Bt3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Bt2 = new wxToggleButton(Core, ID_TOGGLEBUTTON3, _("2"), wxDefaultPosition, wxSize(26,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON3"));
    GridSizer3->Add(Bt2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Bt1 = new wxToggleButton(Core, ID_TOGGLEBUTTON4, _("1"), wxDefaultPosition, wxSize(26,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON4"));
    GridSizer3->Add(Bt1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer6->Add(GridSizer3, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    RotationCheck = new wxCheckBox(Core, ID_CHECKBOX2, _("Rotation automatique"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    RotationCheck->SetValue(false);
    RotationCheck->SetToolTip(_("En mode Rotation automatique, Game Develop fera tourner l\'objet suivant sa direction, de 0 � 360.\nVous pouvez changer la direction de l\'objet en cours de jeu gr�ce aux actions du th�me \"Direction\"."));
    FlexGridSizer6->Add(RotationCheck, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    directionSizer->Add(FlexGridSizer6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    animAndDirecSizer->Add(directionSizer, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    imagesSizer = new wxStaticBoxSizer(wxHORIZONTAL, Core, _("Images"));
    FlexGridSizer7 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer7->AddGrowableCol(0);
    FlexGridSizer7->AddGrowableRow(2);
    FlexGridSizer13 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer13->AddGrowableCol(0);
    FlexGridSizer13->AddGrowableRow(0);
    toolbarPanel = new wxPanel(Core, ID_PANEL6, wxDefaultPosition, wxSize(-1,25), wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    AuiManager1 = new wxAuiManager(toolbarPanel, wxAUI_MGR_DEFAULT);
    toolbar = new wxAuiToolBar(toolbarPanel, ID_AUITOOLBAR1, wxDefaultPosition, wxSize(139,35), wxAUI_TB_DEFAULT_STYLE);
    toolbar->Realize();
    AuiManager1->AddPane(toolbar, wxAuiPaneInfo().Name(_T("PaneName")).ToolbarPane().Caption(_("Pane caption")).Layer(10).Top().DockFixed().Dockable(false).BestSize(wxSize(139,35)).Movable(false).Gripper(false));
    AuiManager1->Update();
    FlexGridSizer13->Add(toolbarPanel, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer7->Add(FlexGridSizer13, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    StaticLine3 = new wxStaticLine(Core, ID_STATICLINE3, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
    FlexGridSizer7->Add(StaticLine3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer15 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer15->AddGrowableCol(0);
    FlexGridSizer15->AddGrowableRow(0);
    FlexGridSizer17 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer17->AddGrowableCol(0);
    FlexGridSizer17->AddGrowableRow(0);
    imagePanel = new wxPanel(Core, ID_PANEL3, wxDefaultPosition, wxSize(307,160), wxSUNKEN_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    imagePanel->SetBackgroundColour(wxColour(128,128,128));
    imagePanel->SetToolTip(_("Aper�u de l\'image"));
    FlexGridSizer17->Add(imagePanel, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    scrollHeight = new wxScrollBar(Core, ID_SCROLLBAR1, wxDefaultPosition, wxDefaultSize, wxSB_VERTICAL, wxDefaultValidator, _T("ID_SCROLLBAR1"));
    scrollHeight->SetScrollbar(0, 1, 10, 1);
    FlexGridSizer17->Add(scrollHeight, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    scrollWidth = new wxScrollBar(Core, ID_SCROLLBAR3, wxDefaultPosition, wxDefaultSize, wxSB_HORIZONTAL, wxDefaultValidator, _T("ID_SCROLLBAR3"));
    scrollWidth->SetScrollbar(0, 1, 10, 1);
    FlexGridSizer17->Add(scrollWidth, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer15->Add(FlexGridSizer17, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer7->Add(FlexGridSizer15, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    thumbsSizer = new wxFlexGridSizer(0, 1, 0, 0);
    thumbsSizer->AddGrowableCol(0);
    Panel1 = new wxPanel(Core, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxRAISED_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    FlexGridSizer16 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer16->AddGrowableCol(0);
    thumbsPanel = new wxPanel(Panel1, ID_PANEL4, wxDefaultPosition, wxSize(296,54), wxNO_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    thumbsPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWFRAME));
    thumbsPanel->SetToolTip(_("Liste des images de la direction.\nUtilisez le clic droit ou la barre d\'outils pour modifier les images."));
    FlexGridSizer16->Add(thumbsPanel, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    thumbsScroll = new wxScrollBar(Panel1, ID_SCROLLBAR2, wxDefaultPosition, wxSize(296,17), wxSB_HORIZONTAL, wxDefaultValidator, _T("ID_SCROLLBAR2"));
    thumbsScroll->SetScrollbar(0, 1, 10, 1);
    FlexGridSizer16->Add(thumbsScroll, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Panel1->SetSizer(FlexGridSizer16);
    FlexGridSizer16->Fit(Panel1);
    FlexGridSizer16->SetSizeHints(Panel1);
    thumbsSizer->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer7->Add(thumbsSizer, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer8 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer9 = new wxFlexGridSizer(0, 4, 0, 0);
    CheckTempsEntreImg = new wxStaticBitmap(Core, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxSize(16,16), 0, _T("ID_STATICBITMAP1"));
    FlexGridSizer9->Add(CheckTempsEntreImg, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Core, ID_STATICTEXT2, _("Temps entre chaque image :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer9->Add(StaticText2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TempsEdit = new wxTextCtrl(Core, ID_TEXTCTRL2, _("1"), wxDefaultPosition, wxSize(68,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TempsEdit->SetToolTip(_("Utilisez le point ( . ) pour entrer des valeurs interm�diaires :\n0.35, 1.75..."));
    FlexGridSizer9->Add(TempsEdit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(Core, ID_STATICTEXT3, _("secondes"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer9->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer8->Add(FlexGridSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer11 = new wxFlexGridSizer(0, 3, 0, 0);
    StaticText1 = new wxStaticText(Core, ID_STATICTEXT4, _("R�p�ter les images :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer11->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoucleOuiCheck = new wxRadioButton(Core, ID_RADIOBUTTON3, _("Oui"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
    BoucleOuiCheck->SetToolTip(_("Apr�s la derni�re image, l\'animation reprendra du d�part."));
    FlexGridSizer11->Add(BoucleOuiCheck, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoucleNonCheck = new wxRadioButton(Core, ID_RADIOBUTTON4, _("Non"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON4"));
    BoucleNonCheck->SetValue(true);
    BoucleNonCheck->SetToolTip(_("Une fois l\'animation arriv�e � la derni�re image, elle s\'arr�tera � celle ci."));
    FlexGridSizer11->Add(BoucleNonCheck, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer8->Add(FlexGridSizer11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer7->Add(FlexGridSizer8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    imagesSizer->Add(FlexGridSizer7, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    animAndDirecSizer->Add(imagesSizer, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer10->Add(animAndDirecSizer, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer4->Add(FlexGridSizer10, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer2->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    StaticLine2 = new wxStaticLine(Core, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    BoxSizer2->Add(StaticLine2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer14 = new wxFlexGridSizer(0, 3, 0, 0);
    FlexGridSizer14->AddGrowableCol(0);
    ListImageBt = new wxButton(Core, ID_BUTTON3, _("Afficher la banque d\'images"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    ListImageBt->SetToolTip(_("Consulter et/ou �diter la banque d\'image."));
    FlexGridSizer14->Add(ListImageBt, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    OkBt = new wxButton(Core, ID_BUTTON5, _("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    FlexGridSizer14->Add(OkBt, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    AideBt = new wxButton(Core, ID_BUTTON4, _("Aide"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    FlexGridSizer14->Add(AideBt, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(FlexGridSizer14, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    FlexGridSizer2->Add(BoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Core->SetSizer(FlexGridSizer2);
    FlexGridSizer2->Fit(Core);
    FlexGridSizer2->SetSizeHints(Core);
    FlexGridSizer1->Add(Core, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(FlexGridSizer1);
    MenuItem6 = new wxMenu();
    MenuItem11 = new wxMenuItem(MenuItem6, idMenuAddFromEnd, _("...� la fin"), wxEmptyString, wxITEM_NORMAL);
    MenuItem11->SetBitmap(wxBitmap(wxImage(_T("res/2rightarrow.png"))));
    MenuItem6->Append(MenuItem11);
    MenuItem12 = new wxMenuItem(MenuItem6, idMenuAddFromAfter, _("...apr�s celle-ci"), wxEmptyString, wxITEM_NORMAL);
    MenuItem12->SetBitmap(wxBitmap(wxImage(_T("res/1rightarrow.png"))));
    MenuItem6->Append(MenuItem12);
    MenuItem13 = new wxMenuItem(MenuItem6, idMenuAddFromBefore, _("...avant celle-ci"), wxEmptyString, wxITEM_NORMAL);
    MenuItem13->SetBitmap(wxBitmap(wxImage(_T("res/1leftarrow.png"))));
    MenuItem6->Append(MenuItem13);
    contextMenu.Append(ID_MENUITEM1, _("Ajouter l\'image selectionn�e dans la banque d\'image"), MenuItem6, wxEmptyString);
    MenuItem5 = new wxMenu();
    MenuItem8 = new wxMenuItem(MenuItem5, idMenuAddMoreEnd, _("...� la fin"), wxEmptyString, wxITEM_NORMAL);
    MenuItem8->SetBitmap(wxBitmap(wxImage(_T("res/2rightarrow.png"))));
    MenuItem5->Append(MenuItem8);
    MenuItem9 = new wxMenuItem(MenuItem5, idMenuAddMoreAfter, _("...apr�s celle-ci"), wxEmptyString, wxITEM_NORMAL);
    MenuItem9->SetBitmap(wxBitmap(wxImage(_T("res/1rightarrow.png"))));
    MenuItem5->Append(MenuItem9);
    MenuItem10 = new wxMenuItem(MenuItem5, idMenuAddMoreBefore, _("...avant celle-ci"), wxEmptyString, wxITEM_NORMAL);
    MenuItem10->SetBitmap(wxBitmap(wxImage(_T("res/1leftarrow.png"))));
    MenuItem5->Append(MenuItem10);
    contextMenu.Append(idMenuAddMulti, _("Ajouter plusieurs images"), MenuItem5, wxEmptyString);
    contextMenu.AppendSeparator();
    MenuItem7 = new wxMenuItem((&contextMenu), idMenuDel, _("Supprimer l\'image"), wxEmptyString, wxITEM_NORMAL);
    MenuItem7->SetBitmap(wxBitmap(wxImage(_T("res/deleteicon.png"))));
    contextMenu.Append(MenuItem7);
    MenuItem14 = new wxMenuItem((&contextMenu), idMenuDelAll, _("Supprimer toutes les images"), wxEmptyString, wxITEM_NORMAL);
    contextMenu.Append(MenuItem14);
    contextMenu.AppendSeparator();
    MenuItem15 = new wxMenuItem((&contextMenu), idMenuCopyFrom, _("Copier toutes les images depuis..."), wxEmptyString, wxITEM_NORMAL);
    MenuItem15->SetBitmap(wxBitmap(wxImage(_T("res/copyicon.png"))));
    contextMenu.Append(MenuItem15);
    MenuItem1 = new wxMenuItem((&imageContextMenu), idPosPoint, _("Editer les points"), wxEmptyString, wxITEM_NORMAL);
    MenuItem1->SetBitmap(wxBitmap(wxImage(_T("res/pointmod.png"))));
    imageContextMenu.Append(MenuItem1);
    MenuItem2 = new wxMenuItem((&imageContextMenu), ID_MENUITEM3, _("Editer le masque de collision"), wxEmptyString, wxITEM_NORMAL);
    MenuItem2->SetBitmap(wxBitmap(wxImage(_T("res/maskEdit16.png"))));
    imageContextMenu.Append(MenuItem2);
    MenuItem3 = new wxMenuItem((&maskContextMenu), ID_MENUITEM5, _("Arr�ter l\'�dition du masque"), wxEmptyString, wxITEM_NORMAL);
    maskContextMenu.Append(MenuItem3);
    maskContextMenu.AppendSeparator();
    MenuItem4 = new wxMenuItem((&maskContextMenu), ID_MENUITEM8, _("Ajouter un rectangle de collision"), wxEmptyString, wxITEM_NORMAL);
    MenuItem4->SetBitmap(wxBitmap(wxImage(_T("res/maskAdd16.png"))));
    maskContextMenu.Append(MenuItem4);
    MenuItem22 = new wxMenu();
    MenuItem23 = new wxMenuItem(MenuItem22, ID_MENUITEM9, _("Supprimer"), wxEmptyString, wxITEM_NORMAL);
    MenuItem23->SetBitmap(wxBitmap(wxImage(_T("res/maskRemove16.png"))));
    MenuItem22->Append(MenuItem23);
    MenuItem20 = new wxMenuItem(MenuItem22, ID_MENUITEM6, _("Modifier"), wxEmptyString, wxITEM_NORMAL);
    MenuItem22->Append(MenuItem20);
    MenuItem25 = new wxMenuItem(MenuItem22, idMenuPosEverywhere2, _("Positionner pr�cisement"), wxEmptyString, wxITEM_NORMAL);
    MenuItem22->Append(MenuItem25);
    maskContextMenu.Append(ID_MENUITEM4, _("Rectangle s�lectionn�"), MenuItem22, wxEmptyString);
    MenuItem16 = new wxMenu();
    applyMaskToAllDirectionSprites = new wxMenuItem(MenuItem16, ID_MENUITEM13, _("Appliquer � toutes les images de la direction"), wxEmptyString, wxITEM_CHECK);
    MenuItem16->Append(applyMaskToAllDirectionSprites);
    maskContextMenu.Append(ID_MENUITEM12, _("Options"), MenuItem16, wxEmptyString);
    maskContextMenu.AppendSeparator();
    MenuItem24 = new wxMenuItem((&maskContextMenu), ID_MENUITEM10, _("Retourner au masque par d�faut"), wxEmptyString, wxITEM_NORMAL);
    maskContextMenu.Append(MenuItem24);
    MenuItem26 = new wxMenuItem((&pointsContextMenu), ID_MENUITEM11, _("Arr�ter de positionner les points"), wxEmptyString, wxITEM_NORMAL);
    pointsContextMenu.Append(MenuItem26);
    pointsContextMenu.AppendSeparator();
    MenuItem27 = new wxMenuItem((&pointsContextMenu), ID_MENUITEM2, _("Choisir le point"), wxEmptyString, wxITEM_NORMAL);
    pointsContextMenu.Append(MenuItem27);
    MenuItem28 = new wxMenuItem((&pointsContextMenu), ID_MENUITEM7, _("Positionner pr�cisement"), wxEmptyString, wxITEM_NORMAL);
    pointsContextMenu.Append(MenuItem28);
    MenuItem29 = new wxMenu();
    posEverywhereMenuItem = new wxMenuItem(MenuItem29, idMenuPosEverywhere, _("Positionner en m�me temps sur les autres images"), wxEmptyString, wxITEM_CHECK);
    MenuItem29->Append(posEverywhereMenuItem);
    pointsContextMenu.Append(ID_MENUITEM14, _("Options"), MenuItem29, wxEmptyString);
    pointsContextMenu.AppendSeparator();
    MenuItem31 = new wxMenuItem((&pointsContextMenu), idAddPoint, _("Ajouter un point"), wxEmptyString, wxITEM_NORMAL);
    pointsContextMenu.Append(MenuItem31);
    MenuItem32 = new wxMenuItem((&pointsContextMenu), idDelPoint, _("Supprimer un point"), wxEmptyString, wxITEM_NORMAL);
    pointsContextMenu.Append(MenuItem32);
    FlexGridSizer1->SetSizeHints(this);
    Center();

    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnAnimationsBoxSelect);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnAddAnimBtClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnDelAnimBtClick);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnNormalCheckSelect);
    Connect(ID_TOGGLEBUTTON8,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnBt5Toggle);
    Connect(ID_TOGGLEBUTTON7,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnBt6Toggle);
    Connect(ID_TOGGLEBUTTON6,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnBt7Toggle);
    Connect(ID_TOGGLEBUTTON5,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnBt4Toggle);
    Connect(ID_TOGGLEBUTTON1,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnBt0Toggle);
    Connect(ID_TOGGLEBUTTON2,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnBt3Toggle);
    Connect(ID_TOGGLEBUTTON3,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnBt2Toggle);
    Connect(ID_TOGGLEBUTTON4,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnBt1Toggle);
    Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnRotationCheckSelect);
    toolbarPanel->Connect(wxEVT_SIZE,(wxObjectEventFunction)&OldSpriteObjectEditor::OntoolbarPanelResize,0,this);
    imagePanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&OldSpriteObjectEditor::OnimagePanelPaint,0,this);
    imagePanel->Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&OldSpriteObjectEditor::OnimagePanelLeftDown,0,this);
    imagePanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&OldSpriteObjectEditor::OnimagePanelLeftUp,0,this);
    imagePanel->Connect(wxEVT_RIGHT_UP,(wxObjectEventFunction)&OldSpriteObjectEditor::OnimagePanelRightUp,0,this);
    imagePanel->Connect(wxEVT_MOTION,(wxObjectEventFunction)&OldSpriteObjectEditor::OnimagePanelMouseMove,0,this);
    Connect(ID_SCROLLBAR1,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnscrollHeightScroll);
    Connect(ID_SCROLLBAR1,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnscrollHeightScroll);
    Connect(ID_SCROLLBAR3,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnscrollWidthScroll);
    Connect(ID_SCROLLBAR3,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnscrollWidthScroll);
    thumbsPanel->Connect(wxEVT_PAINT,(wxObjectEventFunction)&OldSpriteObjectEditor::OnthumbsPanelPaint,0,this);
    thumbsPanel->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&OldSpriteObjectEditor::OnthumbsPanelLeftUp,0,this);
    thumbsPanel->Connect(wxEVT_RIGHT_UP,(wxObjectEventFunction)&OldSpriteObjectEditor::OnthumbsPanelRightUp,0,this);
    thumbsPanel->Connect(wxEVT_SIZE,(wxObjectEventFunction)&OldSpriteObjectEditor::OnthumbsPanelResize,0,this);
    Connect(ID_SCROLLBAR2,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnthumbsScrollScroll);
    Connect(ID_SCROLLBAR2,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnthumbsScrollScroll);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnTempsEditText);
    Connect(ID_RADIOBUTTON3,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnBoucleOuiCheckSelect);
    Connect(ID_RADIOBUTTON4,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnBoucleNonCheckSelect);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnButton1Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnOkBtClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnAideBtClick);
    Connect(idMenuAddFromEnd,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnAddFromEndSelected);
    Connect(idMenuAddFromAfter,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnAddFromAfterSelected);
    Connect(idMenuAddFromBefore,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnAddFromBeforeSelected);
    Connect(idMenuAddMoreEnd,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnAddMoreEndSelected);
    Connect(idMenuAddMoreAfter,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnAddMoreAfterSelected);
    Connect(idMenuAddMoreBefore,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnAddMoreBeforeSelected);
    Connect(idMenuDel,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnDeleteSelected);
    Connect(idMenuDelAll,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnDeleteAllBtClick);
    Connect(idMenuCopyFrom,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnCopyBtClick);
    Connect(idPosPoint,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnModPointSelected);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnEditMaskSelected);
    Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnEditMaskSelected);
    Connect(ID_MENUITEM8,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnAddMaskRectangleSelected);
    Connect(ID_MENUITEM9,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnDelMaskRectangleSelected);
    Connect(ID_MENUITEM6,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnModifyMaskRectangleSelected);
    Connect(idMenuPosEverywhere2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnEnterMaskRectanglePositionSelected);
    Connect(ID_MENUITEM10,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnautomaticMaskSelected);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnModPointSelected);
    Connect(ID_MENUITEM7,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnModPointPrecisSelected);
    Connect(idAddPoint,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnAddPointSelected);
    Connect(idDelPoint,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&OldSpriteObjectEditor::OnDelPointSelected);
    //*)

    toolbar->ClearTools();
    toolbar->SetToolBitmapSize( wxSize( 16, 16 ) );
    toolbar->AddTool( idMenuAddFromEnd, _( "Ajouter l'image � la fin" ), wxBitmap( wxImage( "res/addfromimagebanque.png" ) ), _( "Ajouter une image � la fin depuis la banque d'image" ) );
    toolbar->AddTool( idMenuDel, _( "Supprimer l'image selectionn�e" ), wxBitmap( wxImage( "res/deleteicon.png" ) ), _( "Supprimer l'image selectionn�e" ) );
    toolbar->AddTool( idMenuCopyFrom, _( "Copier les images depuis une animation/direction" ), wxBitmap( wxImage( "res/copyicon.png" ) ), _( "Copier les images depuis une animation/direction" ) );
    toolbar->AddSeparator();
    toolbar->AddTool( idPosPoint, _( "Positionner un point" ), wxBitmap( wxImage( "res/pointmod.png" ) ), _( "Positionner un point" ) );
    toolbar->AddTool( idAddPoint, _( "Ajouter un point" ), wxBitmap( wxImage( "res/pointadd.png" ) ), _( "Ajouter un point" ) );
    toolbar->AddTool( idDelPoint, _( "Supprimer un point" ), wxBitmap( wxImage( "res/pointdel.png" ) ), _( "Supprimer un point" ) );
    toolbar->AddSeparator();
    toolbar->AddTool( ID_MENUITEM3, _( "Editer le masque de collision" ), wxBitmap( wxImage( "res/maskEdit16.png" ) ), _( "Editer le masque de collision" ) );
    toolbar->AddTool( ID_MENUITEM8, _( "Ajouter un rectangle au masque" ), wxBitmap( wxImage( "res/maskAdd16.png" ) ), _( "Ajouter un rectangle au masque" ) );
    toolbar->AddTool( ID_MENUITEM9, _( "Supprimer le rectangle selectionn� du masque" ), wxBitmap( wxImage( "res/maskRemove16.png" ) ), _( "Supprimer le rectangle selectionn� du masque" ) );
    toolbar->Realize();

    toolbar->EnableTool(idAddPoint, false);
    toolbar->EnableTool(idDelPoint, false);
    toolbar->EnableTool(ID_MENUITEM8, false);
    toolbar->EnableTool(ID_MENUITEM9, false);

    NomObjetTxt->SetLabel( object.GetName() );

    m_mgr.SetManagedWindow( this );

    editorImagesPnl = new ResourcesEditor( this, game, mainEditorCommand );
    editorImagesPnl->Refresh();

    m_mgr.AddPane( Core, wxAuiPaneInfo().Name( wxT( "Core" ) ).Center().CaptionVisible(false) );
    m_mgr.AddPane( editorImagesPnl, wxAuiPaneInfo().Name( wxT( "EI" ) ).Left().Caption( _( "Editeur de la banque d'images" ) ).MaximizeButton( true ).MinimizeButton( false ).MinSize(150, 100).Show(true) );

    m_mgr.SetFlags( wxAUI_MGR_ALLOW_FLOATING | wxAUI_MGR_ALLOW_ACTIVE_PANE | wxAUI_MGR_TRANSPARENT_HINT
                    | wxAUI_MGR_TRANSPARENT_DRAG | wxAUI_MGR_HINT_FADE | wxAUI_MGR_NO_VENETIAN_BLINDS_FADE );

    m_mgr.Update();

    RefreshFromObjet();
    Core->Layout();
    SetSize(GetSize().GetWidth()+150, GetSize().GetHeight());
    Center();
}

OldSpriteObjectEditor::~OldSpriteObjectEditor()
{
    //(*Destroy(OldSpriteObjectEditor)
    //*)

    m_mgr.UnInit();
	AuiManager1->UnInit();
}

////////////////////////////////////////////////////////////
/// Rafraichit les controles
///
/// Rafraichit les controles ( Animation, type de direction ) en fonction de l'objet
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::RefreshFromObjet()
{
    //Les animations
    AnimationsBox->Clear();
    for ( unsigned int i = 0;i < object.GetAnimationCount();i++ )
    {
        AnimationsBox->Append( ToString( i ) );
    }
    if ( !object.HasNoAnimations() )
    {
        AnimationsBox->SetSelection( animation );
        animAndDirecSizer->Show(directionSizer);
        animAndDirecSizer->Show(imagesSizer);
    }
    else //Pas d'animations
    {
        AnimationsBox->SetSelection( -1 );
        NormalCheck->SetValue( true );
        RotationCheck->SetValue( false );
        Bt0->Enable( true );
        Bt1->Enable( true );
        Bt2->Enable( true );
        Bt3->Enable( true );
        Bt4->Enable( true );
        Bt5->Enable( true );
        Bt6->Enable( true );
        Bt7->Enable( true );
        animAndDirecSizer->Show(directionSizer, false);
        animAndDirecSizer->Show(imagesSizer, false);
    }


    RefreshImages();
}

void OldSpriteObjectEditor::OnScrollBar1Scroll( wxScrollEvent& event )
{
    position = event.GetPosition();

    RefreshImages();
}


////////////////////////////////////////////////////////////
/// Rafraichir les images
///
/// Rafraichit la liste des images en fonction de la position
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::RefreshImages()
{
    if ( animation >= object.GetAnimationCount() || direction >= object.GetAnimation( animation ).GetDirectionsNumber())
        return;

    //Type de directions
    if ( !object.GetAnimation( animation ).useMultipleDirections )
    {
        RotationCheck->SetValue( true );
        NormalCheck->SetValue( false );
        Bt0->Enable( false );
        Bt1->Enable( false );
        Bt2->Enable( false );
        Bt3->Enable( false );
        Bt4->Enable( false );
        Bt5->Enable( false );
        Bt6->Enable( false );
        Bt7->Enable( false );
    }
    else
    {
        NormalCheck->SetValue( true );
        RotationCheck->SetValue( false );
        Bt0->Enable( true );
        Bt1->Enable( true );
        Bt2->Enable( true );
        Bt3->Enable( true );
        Bt4->Enable( true );
        Bt5->Enable( true );
        Bt6->Enable( true );
        Bt7->Enable( true );
    }

    //Temps
    TempsEdit->ChangeValue( ToString( object.GetAnimation( animation ).GetDirection( direction ).GetTimeBetweenFrames() ) );

    //Boucle
    BoucleOuiCheck->SetValue( object.GetAnimation( animation ).GetDirection( direction ).IsLooping() );
    BoucleNonCheck->SetValue( !object.GetAnimation( animation ).GetDirection( direction ).IsLooping() );

    //Rafraichissement du reste
    thumbsPanel->Refresh();
    thumbsPanel->Update(); //Imm�diatement
    imagePanel->Refresh();
    imagePanel->Update(); //Imm�diatement
    Core->Layout();
}

void OldSpriteObjectEditor::OnBt0Toggle( wxCommandEvent& event )
{
    Bt1->SetValue( false );
    Bt2->SetValue( false );
    Bt3->SetValue( false );
    Bt4->SetValue( false );
    Bt5->SetValue( false );
    Bt6->SetValue( false );
    Bt7->SetValue( false );

    direction = 0;
    RefreshImages();
}

void OldSpriteObjectEditor::OnBt1Toggle( wxCommandEvent& event )
{
    Bt0->SetValue( false );
    Bt2->SetValue( false );
    Bt3->SetValue( false );
    Bt4->SetValue( false );
    Bt5->SetValue( false );
    Bt6->SetValue( false );
    Bt7->SetValue( false );
    direction = 1;
    RefreshImages();
}

void OldSpriteObjectEditor::OnBt2Toggle( wxCommandEvent& event )
{
    Bt0->SetValue( false );
    Bt1->SetValue( false );
    Bt3->SetValue( false );
    Bt4->SetValue( false );
    Bt5->SetValue( false );
    Bt6->SetValue( false );
    Bt7->SetValue( false );
    direction = 2;
    RefreshImages();
}

void OldSpriteObjectEditor::OnBt3Toggle( wxCommandEvent& event )
{
    Bt0->SetValue( false );
    Bt1->SetValue( false );
    Bt2->SetValue( false );
    Bt4->SetValue( false );
    Bt5->SetValue( false );
    Bt6->SetValue( false );
    Bt7->SetValue( false );
    direction = 3;
    RefreshImages();
}

void OldSpriteObjectEditor::OnBt4Toggle( wxCommandEvent& event )
{
    Bt1->SetValue( false );
    Bt2->SetValue( false );
    Bt3->SetValue( false );
    Bt0->SetValue( false );
    Bt5->SetValue( false );
    Bt6->SetValue( false );
    Bt7->SetValue( false );
    direction = 4;
    RefreshImages();
}

void OldSpriteObjectEditor::OnBt5Toggle( wxCommandEvent& event )
{
    Bt1->SetValue( false );
    Bt2->SetValue( false );
    Bt3->SetValue( false );
    Bt4->SetValue( false );
    Bt0->SetValue( false );
    Bt6->SetValue( false );
    Bt7->SetValue( false );
    direction = 5;
    RefreshImages();
}

void OldSpriteObjectEditor::OnBt6Toggle( wxCommandEvent& event )
{
    Bt1->SetValue( false );
    Bt2->SetValue( false );
    Bt3->SetValue( false );
    Bt4->SetValue( false );
    Bt5->SetValue( false );
    Bt0->SetValue( false );
    Bt7->SetValue( false );
    direction = 6;
    RefreshImages();
}

void OldSpriteObjectEditor::OnBt7Toggle( wxCommandEvent& event )
{
    Bt1->SetValue( false );
    Bt2->SetValue( false );
    Bt3->SetValue( false );
    Bt4->SetValue( false );
    Bt5->SetValue( false );
    Bt6->SetValue( false );
    Bt0->SetValue( false );
    direction = 7;
    RefreshImages();
}

bool OldSpriteObjectEditor::AnimationAndDirectionValid()
{
    if ( animation < object.GetAnimationCount() && direction < object.GetAnimation( animation ).GetDirectionsNumber())
        return true;

    return false;
}

bool OldSpriteObjectEditor::SpriteValid()
{
    if ( AnimationAndDirectionValid() && selectedImage >= 0 && static_cast<unsigned>(selectedImage) < object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSpritesToModify().size() )
        return true;

    return false;
}

Sprite & OldSpriteObjectEditor::GetEditedSprite()
{
    return object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(selectedImage);
}

Animation & OldSpriteObjectEditor::GetEditedAnimation()
{
    return object.GetAnimation( animation );
}

Direction & OldSpriteObjectEditor::GetEditedDirection()
{
    return object.GetAnimation( animation ).GetDirectionToModify( direction );
}

void OldSpriteObjectEditor::OnAddAnimBtClick( wxCommandEvent& event )
{
    Animation newAnimation;
    newAnimation.SetDirectionsNumber(8);
    object.AddAnimation( newAnimation );

    AnimationsBox->Append( ToString( object.GetAnimationCount() - 1 ) );

    RefreshFromObjet();
}

void OldSpriteObjectEditor::OnDelAnimBtClick( wxCommandEvent& event )
{
    int animNb = AnimationsBox->GetSelection();
    if ( animNb == wxNOT_FOUND ) return;

    if ( animNb >= 0 && static_cast<unsigned>(animNb) < object.GetAnimationCount() )
        object.RemoveAnimation( animNb );

    animation--;

    RefreshFromObjet();
}

void OldSpriteObjectEditor::OnAnimationsBoxSelect( wxCommandEvent& event )
{
    animation = AnimationsBox->GetSelection();

    RefreshImages();
}

////////////////////////////////////////////////////////////
/// Changement valeur tempsEntre
///
/// Changement de la valeur du temps entre les images
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnTempsEditText( wxCommandEvent& event )
{
    if ( AnimationAndDirectionValid() ) GetEditedDirection().SetTimeBetweenFrames( ToFloat(string(TempsEdit->GetValue().mb_str())) );
}

////////////////////////////////////////////////////////////
/// Clic sur le bouton Oui
///
/// Change le bouclage de la direction en true
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnBoucleOuiCheckSelect( wxCommandEvent& event )
{
   if ( AnimationAndDirectionValid() ) GetEditedDirection().SetLoop( true );
}

////////////////////////////////////////////////////////////
/// Clic sur le bouton Non
///
/// Change le bouclage de la direction en false
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnBoucleNonCheckSelect( wxCommandEvent& event )
{
    if ( AnimationAndDirectionValid() ) GetEditedDirection().SetLoop( false );
}

/**
 * Display Image Bank Editor
 */
void OldSpriteObjectEditor::OnButton1Click( wxCommandEvent& event )
{
    //Update the window size
    if ( !m_mgr.GetPane( editorImagesPnl ).IsShown() )
        SetSize(GetSize().GetWidth()+150, GetSize().GetHeight());

    m_mgr.GetPane( editorImagesPnl ).Show();
    m_mgr.Update();
}

void OldSpriteObjectEditor::OnRotationCheckSelect( wxCommandEvent& event )
{
    if ( !RotationCheck->GetValue() ) //Imitation d'un radio button
    {
        RotationCheck->SetValue( true );
        return;
    }
    NormalCheck->SetValue( false );

    if ( AnimationAndDirectionValid() ) GetEditedAnimation().useMultipleDirections = false;

    direction = 0;
    Bt0->Enable( false );
    Bt1->Enable( false );
    Bt2->Enable( false );
    Bt3->Enable( false );
    Bt4->Enable( false );
    Bt5->Enable( false );
    Bt6->Enable( false );
    Bt7->Enable( false );
}

void OldSpriteObjectEditor::OnNormalCheckSelect( wxCommandEvent& event )
{
    if ( !NormalCheck->GetValue() ) //Imitation d'un radio button
    {
        NormalCheck->SetValue( true );
        return;
    }
    RotationCheck->SetValue( false );

    if ( AnimationAndDirectionValid() ) GetEditedAnimation().useMultipleDirections = true;


    Bt0->Enable( true );
    Bt1->Enable( true );
    Bt2->Enable( true );
    Bt3->Enable( true );
    Bt4->Enable( true );
    Bt5->Enable( true );
    Bt6->Enable( true );
    Bt7->Enable( true );
}

void OldSpriteObjectEditor::OnAideBtClick( wxCommandEvent& event )
{
    if ( GDpriv::LocaleManager::GetInstance()->locale->GetLanguage() == wxLANGUAGE_FRENCH )
        gd::HelpFileAccess::GetInstance()->DisplaySection(47);
    else
        gd::HelpFileAccess::GetInstance()->OpenURL(_("http://www.wiki.compilgames.net/doku.php/en/game_develop/documentation/manual/built_sprite"));
}

void OldSpriteObjectEditor::OnOkBtClick(wxCommandEvent& event)
{
    EndModal(0);
}


////////////////////////////////////////////////////////////
/// Suppression de toutes les images
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnDeleteAllBtClick(wxCommandEvent& event)
{
    if ( !AnimationAndDirectionValid() ) return;

    if (wxMessageBox("Etes-vous s�r de vouloir supprimer toutes les images ?", "�tes vous sur ?",wxYES_NO ) == wxYES)
        GetEditedDirection().RemoveAllSprites();

    RefreshImages();
}

////////////////////////////////////////////////////////////
/// Ajout rapide de plusieurs images
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnAjoutPlusBtClick(wxCommandEvent& event)
{
    if ( !AnimationAndDirectionValid() ) return;

    AjoutPlusImage dialog(this);
    if ( dialog.ShowModal() == 0 ) return;

    //Ajout des images
    for (unsigned int i = 0;i<dialog.ImagesToAdd.size();++i)
    {
        Sprite sprite;
        sprite.SetImageName(dialog.ImagesToAdd.at(i));
        GetEditedDirection().AddSprite(sprite);
    }

    RefreshImages();
}

////////////////////////////////////////////////////////////
/// Copier les images d'une animation/direction � la place de celle ci
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnCopyBtClick(wxCommandEvent& event)
{
    if ( !AnimationAndDirectionValid() ) return;

    int animToCopy = wxGetNumberFromUser( "Animation � copier", "", "Entrez le num�ro de l'animation dans laquelle se trouve la direction � copier", 0, 0, object.GetAnimationCount()-1, this);
    if (animToCopy < 0 || static_cast<unsigned int>(animToCopy) >= object.GetAnimationCount()) return;

    int directionToCopy = 0;

    if (object.GetAnimation( animToCopy ).useMultipleDirections)
    {
        directionToCopy = wxGetNumberFromUser( "Direction � copier", "", "Entrez le num�ro de la direction dans laquelle se trouve les images � copier", 0, 0, object.GetAnimation( animToCopy ).GetDirectionsNumber()-1, this);
        if (directionToCopy < 0 || static_cast<unsigned int>(directionToCopy) >= object.GetAnimation( animToCopy ).GetDirectionsNumber() ) return;
    }

    GetEditedAnimation().SetDirection(object.GetAnimation(animToCopy).GetDirection(directionToCopy), direction);

    RefreshImages();
}

////////////////////////////////////////////////////////////
/// Mise � jour de la barre de miniatures si redimensionnement
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnthumbsPanelResize(wxSizeEvent& event)
{
    thumbsPanel->Refresh();
    thumbsPanel->Update(); //Imm�diatement
}

////////////////////////////////////////////////////////////
/// Mise � jour de la barre de miniatures
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnthumbsPanelPaint(wxPaintEvent& event)
{
    thumbsPanel->SetBackgroundStyle( wxBG_STYLE_PAINT );
    wxPaintDC dc( thumbsPanel ); //Cr�ation obligatoire du wxBufferedPaintDC

    wxSize size = thumbsPanel->GetSize();

    gd::CommonBitmapManager * CommonBitmapManager = gd::CommonBitmapManager::GetInstance();

    //Fond gris avec des fl�ches
    dc.SetPen(wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWFRAME )));
    dc.SetBrush(CommonBitmapManager->backthumbsBg);
    dc.DrawRectangle(0,0, size.GetWidth(), size.GetHeight());

    int decalage = thumbsScroll->GetThumbPosition();

    //Fond en damier pour les images
    dc.SetBrush(CommonBitmapManager->transparentBg);

    //Affichage des images
    if ( !AnimationAndDirectionValid() ) return;
    const Direction & directionToDisplay = object.GetAnimation( animation ).GetDirection( direction );

    for (unsigned int i = 0;i<directionToDisplay.GetSpriteCount();++i)
    {
        dc.SetPen(*wxBLACK_PEN);

        if ( selectedImage >= 0 && i == static_cast<unsigned>(selectedImage) )
            dc.SetPen(wxPen(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT)));
        dc.DrawRectangle(wxRect(2+i*48+i*3-decalage,2,50,50));

        if ( game.resourceManager.HasResource(directionToDisplay.GetSprite(i).GetImageName()) )
        {
            try
            {
                ImageResource & image = dynamic_cast<ImageResource&>(game.resourceManager.GetResource(directionToDisplay.GetSprite(i).GetImageName()));

                if ( wxFileExists(image.GetAbsoluteFile(game)) )
                {
                    wxBitmap bmp( image.GetAbsoluteFile(game), wxBITMAP_TYPE_ANY);
                    if ( bmp.GetWidth() != 48 || bmp.GetHeight() != 48 )
                    {
                        wxImage bmpImage = bmp.ConvertToImage();
                        bmp = wxBitmap(bmpImage.Scale(48, 48));
                    }

                    if ( bmp.IsOk() ) dc.DrawBitmap(bmp, 2+i*48+i*3+1-decalage, 3, true);
                }
                else
                {
                    dc.DrawBitmap(wxBitmap( "res/error48.png", wxBITMAP_TYPE_ANY ), 2+i*48+i*3+1-decalage, 3);
                }
            }
            catch(...)
            {
                //Resource is probably not an image.
            }
        }
    }
    if ( directionToDisplay.HasNoSprites() )
    {
        dc.SetFont(*wxNORMAL_FONT);
        dc.DrawLabel(_("Pas d'images. \nUtilisez le clic droit ou la barre d'outils pour ajouter des images."), wxRect(thumbsPanel->GetSize()),  wxALIGN_LEFT | wxALIGN_CENTER);
    }

    //Rafraichissement de la scrollbar
    thumbsScroll->SetScrollbar(thumbsScroll->GetThumbPosition(),
                               thumbsPanel->GetSize().GetWidth(),
                               (directionToDisplay.GetSpriteCount())*48+(directionToDisplay.GetSpriteCount())*3,
                               thumbsPanel->GetSize().GetWidth());
}

////////////////////////////////////////////////////////////
/// Scroll de la barre de miniatures
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnthumbsScrollScroll(wxScrollEvent& event)
{
    thumbsPanel->Refresh();
    thumbsPanel->Update(); //Imm�diatement
}

////////////////////////////////////////////////////////////
/// Clic sur la barre de miniatures
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnthumbsPanelLeftUp(wxMouseEvent& event)
{
    int X = event.GetX() + thumbsScroll->GetThumbPosition()-2;
    selectedImage = X/(48+3);

    thumbsPanel->Refresh();
    thumbsPanel->Update(); //Imm�diatement

    imagePanel->Refresh();
    imagePanel->Update(); //Imm�diatement
}

////////////////////////////////////////////////////////////
/// Affichage de l'image selectionn�e
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnimagePanelPaint(wxPaintEvent& event)
{
    imagePanel->SetBackgroundStyle( wxBG_STYLE_PAINT );
    wxPaintDC dc( imagePanel ); //Cr�ation obligatoire du wxBufferedPaintDC

    wxSize size = imagePanel->GetSize();

    gd::CommonBitmapManager * CommonBitmapManager = gd::CommonBitmapManager::GetInstance();

    //Fond en damier
    dc.SetBrush(CommonBitmapManager->transparentBg);
    dc.DrawRectangle(0,0, size.GetWidth(), size.GetHeight());

    if ( !AnimationAndDirectionValid() ) return;

    if ( selectedImage >= 0 && static_cast<unsigned>(selectedImage) < object.GetAnimation( animation ).GetDirection( direction ).GetSpriteCount() )
    {
        const Sprite & sprite = object.GetAnimation( animation ).GetDirection( direction ).GetSprite(selectedImage);
        try
        {
            ImageResource & image = dynamic_cast<ImageResource&>(game.resourceManager.GetResource(sprite.GetImageName()));

            if ( wxFileExists(image.GetAbsoluteFile(game)) )
            {
                //Chargement de l'image
                wxBitmap bmp( image.GetAbsoluteFile(game), wxBITMAP_TYPE_ANY);
                wxBitmap point( CommonBitmapManager->point );

                scrollWidth->SetScrollbar(scrollWidth->GetThumbPosition(),size.GetWidth(), bmp.GetWidth(),size.GetWidth());
                scrollHeight->SetScrollbar(scrollHeight->GetThumbPosition(), size.GetHeight(), bmp.GetHeight(), size.GetHeight());

                spritePosX = (size.GetWidth() - bmp.GetWidth() - scrollWidth->GetThumbPosition()) / 2;
                spritePosY = (size.GetHeight() - bmp.GetHeight() - scrollHeight->GetThumbPosition()) / 2;

                if ( bmp.IsOk() )
                    dc.DrawBitmap(bmp, spritePosX, spritePosY, true /* use mask */); //Affichage de l'image

                //Affichage du point
                if ( placingPoint && sprite.HasPoint(selectedPoint))
                {
                    dc.DrawBitmap(point,
                                  sprite.GetPoint(selectedPoint).GetX() - point.GetWidth()/2 + ((size.GetWidth() - bmp.GetWidth() - scrollWidth->GetThumbPosition()) / 2),
                                  sprite.GetPoint(selectedPoint).GetY() - point.GetHeight()/2 + ((size.GetHeight() - bmp.GetHeight() - scrollHeight->GetThumbPosition()) / 2),
                                  true /* use mask */);
                }

                //Display hit boxes
                if ( editingMask )
                {
                    //dc.SetLogicalFunction(wxINVERT);
                    std::vector<RotatedRectangle> boxes = sprite.GetCollisionMask();
                    for (unsigned int i = 0;i<boxes.size();++i)
                    {
                        dc.SetBrush(wxBrush(wxColour(128,128,128), wxBRUSHSTYLE_FDIAGONAL_HATCH));
                        if ( i == selectedBox ) dc.SetBrush(wxBrush(wxColour(255,255,255), wxBRUSHSTYLE_FDIAGONAL_HATCH));
                        dc.DrawRectangle(spritePosX+boxes[i].center.x-boxes[i].halfSize.x,
                                         spritePosY+boxes[i].center.y-boxes[i].halfSize.y,
                                         boxes[i].halfSize.x*2,
                                         boxes[i].halfSize.y*2);
                    }
                }
            }
        }
        catch(...)
        {
            //Resource is probably not an image.
        }
    }
}

////////////////////////////////////////////////////////////
/// Clic droit sur la barre de miniatures
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnthumbsPanelRightUp(wxMouseEvent& event)
{
    //On v�rifie que la banque d'image est affich�e
    if ( m_mgr.GetPane( editorImagesPnl ).IsShown() )
    {
        MenuItem11->Enable();
        MenuItem12->Enable();
        MenuItem13->Enable();
    }
    else
    {
        MenuItem11->Enable(false);
        MenuItem12->Enable(false);
        MenuItem13->Enable(false);
    }

    PopupMenu(&contextMenu);
}

void OldSpriteObjectEditor::OnAddMoreEndSelected(wxCommandEvent& event)
{
    if ( !AnimationAndDirectionValid() ) return;

    //Fen�tre d'ajouts de plusieurs images
    AjoutPlusImage dialog(this);
    if ( dialog.ShowModal() == 0 )
        return;

    for (unsigned int i = 0;i<dialog.ImagesToAdd.size();++i)
    {
        Sprite sprite;
        sprite.SetImageName(dialog.ImagesToAdd.at(i));
        object.GetAnimation( animation ).GetDirectionToModify( direction ).AddSprite(sprite);
    }

    thumbsPanel->Refresh();
    thumbsPanel->Update(); //Imm�diatement
}

void OldSpriteObjectEditor::OnAddMoreAfterSelected(wxCommandEvent& event)
{
    if ( !AnimationAndDirectionValid() ) return;

    //Fen�tre d'ajouts de plusieurs images
    AjoutPlusImage dialog(this);
    if ( dialog.ShowModal() == 0 )
        return;

    vector < Sprite > & sprites = object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSpritesToModify();

    for (unsigned int i = 0;i<dialog.ImagesToAdd.size();++i)
    {
        Sprite sprite;
        sprite.SetImageName(dialog.ImagesToAdd.at(i));

        if ( static_cast<unsigned>(selectedImage)+1+i < sprites.size() )
            sprites.insert(sprites.begin() + selectedImage + 1 + i, sprite);
        else
            sprites.push_back(sprite);
    }

    thumbsPanel->Refresh();
    thumbsPanel->Update(); //Imm�diatement
}

void OldSpriteObjectEditor::OnAddMoreBeforeSelected(wxCommandEvent& event)
{
    if ( !AnimationAndDirectionValid() ) return;

    //Fen�tre d'ajouts de plusieurs images
    AjoutPlusImage dialog(this);
    if ( dialog.ShowModal() == 0 )
        return;

    vector < Sprite > & sprites = object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSpritesToModify();

    for (unsigned int i = 0;i<dialog.ImagesToAdd.size();++i)
    {
        Sprite sprite;
        sprite.SetImageName(dialog.ImagesToAdd.at(i));

        if ( static_cast<unsigned>(selectedImage)+i < sprites.size() )
            sprites.insert(sprites.begin() + selectedImage+i, sprite);
        else
            sprites.push_back(sprite);
    }

    thumbsPanel->Refresh();
    thumbsPanel->Update(); //Imm�diatement
}

void OldSpriteObjectEditor::OnAddFromEndSelected(wxCommandEvent& event)
{
    if ( !AnimationAndDirectionValid() )
    {
        return;
    }

    if ( !m_mgr.GetPane( editorImagesPnl ).IsShown() )
    {
        wxLogMessage(_("Affichez l'�diteur de la banque d'image, et s�lectionnez une image avant de cliquer sur ce bouton."));
        return;
    }

    if ( !editorImagesPnl->m_itemSelected.IsOk() || editorImagesPnl->m_itemSelected == editorImagesPnl->resourcesTree->GetRootItem())
    {
        wxLogMessage(_("Choisissez une image dans la banque d'image."));
        return;
    }

    Sprite sprite;
    sprite.SetImageName(string(editorImagesPnl->resourcesTree->GetItemText(editorImagesPnl->m_itemSelected).mb_str()));
    object.GetAnimation( animation ).GetDirectionToModify( direction ).AddSprite(sprite);

    thumbsPanel->Refresh();
    thumbsPanel->Update(); //Imm�diatement
}

void OldSpriteObjectEditor::OnAddFromAfterSelected(wxCommandEvent& event)
{
    if ( !AnimationAndDirectionValid() ) return;

    if ( !m_mgr.GetPane( editorImagesPnl ).IsShown() )
    {
        wxLogMessage(_("Affichez l'�diteur de la banque d'image, et s�lectionnez une image avant de cliquer sur ce bouton."));
        return;
    }

    if ( !editorImagesPnl->m_itemSelected.IsOk() || editorImagesPnl->m_itemSelected == editorImagesPnl->resourcesTree->GetRootItem())
    {
        wxLogMessage(_("Choisissez une image dans la banque d'image."));
        return;
    }

    Sprite sprite;
    sprite.SetImageName(string(editorImagesPnl->resourcesTree->GetItemText(editorImagesPnl->m_itemSelected).mb_str()));

    vector < Sprite > & sprites = object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSpritesToModify();

    if ( static_cast<unsigned>(selectedImage)+1 < sprites.size() )
    {
        sprites.insert(sprites.begin() + selectedImage+1, sprite);
    }
    else
    {
        sprites.push_back(sprite);
    }

    thumbsPanel->Refresh();
    thumbsPanel->Update(); //Imm�diatement
}

void OldSpriteObjectEditor::OnAddFromBeforeSelected(wxCommandEvent& event)
{
    if ( !AnimationAndDirectionValid() ) return;

    if ( !m_mgr.GetPane( editorImagesPnl ).IsShown() )
    {
        wxLogMessage(_("Affichez l'�diteur de la banque d'image, et s�lectionnez une image avant de cliquer sur ce bouton."));
        return;
    }

    if ( !editorImagesPnl->m_itemSelected.IsOk() || editorImagesPnl->m_itemSelected == editorImagesPnl->resourcesTree->GetRootItem())
    {
        wxLogMessage(_("Choisissez une image dans la banque d'image."));
        return;
    }

    Sprite sprite;
    sprite.SetImageName(string(editorImagesPnl->resourcesTree->GetItemText(editorImagesPnl->m_itemSelected).mb_str()));

    vector < Sprite > & sprites = object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSpritesToModify();

    if ( static_cast<unsigned>(selectedImage) < sprites.size() )
    {
        sprites.insert(sprites.begin() + selectedImage, sprite);
    }
    else
    {
        sprites.push_back(sprite);
    }

    thumbsPanel->Refresh();
    thumbsPanel->Update(); //Imm�diatement
}

void OldSpriteObjectEditor::OnDeleteSelected(wxCommandEvent& event)
{
    if ( !AnimationAndDirectionValid() ) return;

    vector < Sprite > & sprites = object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSpritesToModify();

    if ( selectedImage >= 0 && static_cast<unsigned>(selectedImage) < sprites.size() )
        sprites.erase(sprites.begin() + selectedImage);

    thumbsPanel->Refresh();
    thumbsPanel->Update(); //Imm�diatement

    imagePanel->Refresh();
    imagePanel->Update(); //Imm�diatement
}


////////////////////////////////////////////////////////////
/// Redimensionnement de la toolbar : Mise � jour
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OntoolbarPanelResize(wxSizeEvent& event)
{
    toolbar->SetSize(toolbarPanel->GetSize().x, -1);
}

////////////////////////////////////////////////////////////
/// Rafraichissement de l'aper�u quand on se d�place avec la scrollbar
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnscrollHeightScroll(wxScrollEvent& event)
{
    imagePanel->Refresh();
    imagePanel->Update(); //Imm�diatement
}

////////////////////////////////////////////////////////////
/// Rafraichissement de l'aper�u quand on se d�place avec la scrollbar
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnscrollWidthScroll(wxScrollEvent& event)
{
    imagePanel->Refresh();
    imagePanel->Update(); //Imm�diatement
}

////////////////////////////////////////////////////////////
/// Clic droit sur l'aper�u
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnimagePanelRightUp(wxMouseEvent& event)
{
    if ( !SpriteValid() )return;

    if ( !editingMask && !placingPoint )
        PopupMenu(&imageContextMenu);
    else if ( editingMask )
        PopupMenu(&maskContextMenu);
    else if ( placingPoint )
        PopupMenu(&pointsContextMenu);

}

////////////////////////////////////////////////////////////
/// Clic gauche
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnimagePanelLeftUp(wxMouseEvent& event)
{
    if ( !SpriteValid() ) return;

    if ( editingMask && movingBox )
        movingBox = false;
    else if ( placingPoint )
    {
        if ( !game.resourceManager.HasResource(GetEditedSprite().GetImageName()) )
            return;

        try
        {
            ImageResource & image = dynamic_cast<ImageResource&>(game.resourceManager.GetResource(GetEditedSprite().GetImageName()));

            //Tailles n�cessaire pour placer le point
            wxSize size = imagePanel->GetSize();
            wxBitmap bmp( image.GetAbsoluteFile(game), wxBITMAP_TYPE_ANY);

            int SpritePosX = (size.GetWidth() - bmp.GetWidth() - scrollWidth->GetThumbPosition()) / 2;
            int SpritePosY = (size.GetHeight() - bmp.GetHeight() - scrollHeight->GetThumbPosition()) / 2;

            MovePoint(GetEditedSprite(), selectedPoint, event.GetX() - SpritePosX, event.GetY() - SpritePosY);

            //Repositionnement pour les autres sprites si besoin
            if ( posEverywhereMenuItem->IsChecked() )
            {
                for (unsigned int i =0;i<object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSpriteCount();++i)
                {
                    MovePoint(object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(i),
                              selectedPoint, event.GetX() - SpritePosX, event.GetY() - SpritePosY);
                }
            }
        }
        catch(...)
        {
        }
    }

    imagePanel->Refresh();
    imagePanel->Update(); //Imm�diatement
}

////////////////////////////////////////////////////////////
/// Choisir le point � placer
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnModPointSelected(wxCommandEvent& event)
{
    if ( !SpriteValid() ) return;

    Sprite & sprite = object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(selectedImage);

    wxArrayString points;
    points.Add("Origin");
    points.Add("Centre");
    for (unsigned int i =0;i<sprite.GetAllNonDefaultPoints().size();++i)
        points.Add(sprite.GetAllNonDefaultPoints().at(i).GetName());

    string name = static_cast<string>(wxGetSingleChoice(_("Choisissez le point � �diter.\nVous pourrez ensuite le placer en faisant un clic gauche sur l'image."), _("Choisir le point � positionner"), points));
    if ( name == "" ) return;
    if ( name == "Centre" )
    {
        if (wxMessageBox(_("Le point centre peut �tre positionn� automatiquement par Game Develop au centre (comportement par d�faut).\nVoulez vous modifier ce point ?\nCliquez sur oui pour le modifier, cliquez sur non pour que Game Develop le place automatiquement."),
                       _("Position du point \"Centre\""), wxYES_NO ) == wxNO)
        {
            sprite.SetCentreAutomatic(true);

            imagePanel->Refresh();
            imagePanel->Update(); //Imm�diatement

            return;
        }
        sprite.SetCentreAutomatic(false);
    }

    placingPoint = true;
    toolbar->EnableTool(ID_MENUITEM8, false);
    toolbar->EnableTool(ID_MENUITEM9, false);
    toolbar->EnableTool(idAddPoint, true);
    toolbar->EnableTool(idDelPoint, true);
    editingMask = false;

    selectedPoint = name;

    imagePanel->Refresh();
    imagePanel->Update(); //Imm�diatement
}

////////////////////////////////////////////////////////////
/// Placer un point de fa�on pr�cise
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnModPointPrecisSelected(wxCommandEvent& event)
{
    if ( !SpriteValid() ) return;

    Sprite & sprite = object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(selectedImage);

    //Choix du point
    wxArrayString points;
    points.Add("Origin");
    points.Add("Centre");
    for (unsigned int i =0;i<sprite.GetAllNonDefaultPoints().size();++i)
        points.Add(sprite.GetAllNonDefaultPoints().at(i).GetName());

    string name = static_cast<string>(wxGetSingleChoice(_("Choisissez le point � �diter.\nVous pourrez ensuite le placer en faisant un clic gauche sur l'image."), _("Choisir le point � positionner"), points));
    if ( name == "" ) return;
    if ( name == "Centre" )
    {
        if (wxMessageBox(_("Le point centre peut �tre positionn� automatiquement par Game Develop au centre (comportement par d�faut).\nVoulez vous modifier ce point ?\nCliquez sur oui pour le modifier, cliquez sur non pour que Game Develop le place automatiquement."),
                       _("Position du point \"Centre\""), wxYES_NO ) == wxNO)
        {
            sprite.SetCentreAutomatic(true);

            imagePanel->Refresh();
            imagePanel->Update(); //Imm�diatement

            return;
        }
        sprite.SetCentreAutomatic(false);
    }

    selectedPoint = name;

    string x_str = static_cast<string>(wxGetTextFromUser(_("Entrez la position X du point par rapport � l'image"), "Position X du point",ToString(sprite.GetPoint(name).GetX())));
    string y_str = static_cast<string>(wxGetTextFromUser(_("Entrez la position Y du point par rapport � l'image"), "Position Y du point",ToString(sprite.GetPoint(name).GetY())));

    MovePoint(sprite, name, ToInt(x_str), ToInt(y_str));

    //Repositionnement pour les autres sprites si besoin
    if ( posEverywhereMenuItem->IsChecked() )
    {
        for (unsigned int i =0;i<object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSpriteCount();++i)
        {
            MovePoint(object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(i),
                      name, ToInt(x_str), ToInt(y_str));
        }
    }

    imagePanel->Refresh();
    imagePanel->Update(); //Imm�diatement
}

void OldSpriteObjectEditor::MovePoint(Sprite & sprite, string pointName, int X, int Y)
{
    //V�rification de la validit�
    if ( !sprite.HasPoint(pointName) )
        sprite.AddPoint(pointName);

    Point & point = sprite.GetPoint(pointName);

    point.SetX(X);
    point.SetY(Y);
}

////////////////////////////////////////////////////////////
/// Ajouter un point
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnAddPointSelected(wxCommandEvent& event)
{
    if ( !SpriteValid() ) return;

    Sprite & sprite = object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(selectedImage);

    string name = static_cast<string>(wxGetTextFromUser(_("Entrez le nom du nouveau point"), _("Cr�ation d'un point")));
    if ( name == "" ) return;
    if ( sprite.HasPoint(name) )
    {
        wxLogMessage(_("Un point ayant ce nom existe d�j� !"));
        return;
    }

    sprite.AddPoint(name);
    if (wxMessageBox(_("Voulez vous ajouter ce point � toutes les images de la direction ?"),
                   _("Ajouter ce point � toutes les images"), wxYES_NO ) == wxYES)
    {
        for (unsigned int i =0;i<object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSpritesToModify().size();++i)
        {
            object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(i).AddPoint(name);
        }
    }

    selectedPoint = name;
}

////////////////////////////////////////////////////////////
/// Supprimer un point
////////////////////////////////////////////////////////////
void OldSpriteObjectEditor::OnDelPointSelected(wxCommandEvent& event)
{
    if ( !SpriteValid() ) return;

    Sprite & sprite = GetEditedSprite();

    wxArrayString points;
    for (unsigned int i =0;i<sprite.GetAllNonDefaultPoints().size();++i)
        points.Add(sprite.GetAllNonDefaultPoints().at(i).GetName());

    if ( points.IsEmpty() )
    {
        wxLogMessage(_("Aucun point � �diter. Ajoutez un point avant de pouvoir le positionner."));
        return;
    }

    string name = static_cast<string>(wxGetSingleChoice(_("Choisissez le point � �diter."), _("Choisir le point � positionner"), points));
    if ( name == "" ) return;

    sprite.DelPoint(name);

    if (wxMessageBox(_("Voulez vous supprimer ce point de toutes les images de la direction ?"),
                   _("Supprimer ce point de toutes les images"), wxYES_NO ) == wxYES)
    {
        for (unsigned int i =0;i<object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSpritesToModify().size();++i)
        {
            object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(i).DelPoint(name);
        }
    }
}

void OldSpriteObjectEditor::OnautomaticMaskSelected(wxCommandEvent& event)
{
    if ( !SpriteValid() ) return;

    Sprite & sprite = object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(selectedImage);
    sprite.SetCollisionMaskAutomatic(true);
    std::vector<RotatedRectangle> emptyVector;
    sprite.SetCustomCollisionMask(emptyVector);

    imagePanel->Refresh();
    imagePanel->Update(); //Imm�diatement
}

void OldSpriteObjectEditor::OnimagePanelLeftDown(wxMouseEvent& event)
{
    if ( editingMask && SpriteValid())
    {
        std::vector<RotatedRectangle> boxes = GetEditedSprite().GetCollisionMask();
        for (unsigned int i = 0;i<boxes.size();++i)
        {
            if ( spritePosX+boxes[i].center.x-boxes[i].halfSize.x < event.GetX() &&
                             spritePosY+boxes[i].center.y-boxes[i].halfSize.y <  event.GetY() &&
                             spritePosX+boxes[i].center.x+boxes[i].halfSize.x >  event.GetY()&&
                             spritePosY+boxes[i].center.y+boxes[i].halfSize.y >  event.GetY() )
             {
                movingBox = true;
                selectedBox = i;
                xSelectionOffset = boxes[i].center.x-event.GetX()+spritePosX;
                ySelectionOffset = boxes[i].center.y-event.GetY()+spritePosY;
             }
        }
    }
}

void OldSpriteObjectEditor::OnimagePanelMouseMove(wxMouseEvent& event)
{
    if ( editingMask && movingBox && SpriteValid())
    {
        std::vector<RotatedRectangle> boxes = GetEditedSprite().GetCollisionMask();
        if ( selectedBox < boxes.size())
        {
            boxes[selectedBox].center.x = event.GetX()-spritePosX-xSelectionOffset;
            boxes[selectedBox].center.y = event.GetY()-spritePosY-ySelectionOffset;
        }
        GetEditedSprite().SetCollisionMaskAutomatic(false);
        GetEditedSprite().SetCustomCollisionMask(boxes);

        if ( applyMaskToAllDirectionSprites->IsChecked() )
        {
            for (unsigned int i =0;i<object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSpritesToModify().size();++i)
            {
                object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(i).SetCollisionMaskAutomatic(false);
                object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(i).SetCustomCollisionMask(boxes);
            }
        }

        imagePanel->Refresh();
        imagePanel->Update(); //Imm�diatement
    }
}

void OldSpriteObjectEditor::OnDelMaskRectangleSelected(wxCommandEvent& event)
{
    if ( editingMask && SpriteValid())
    {
        std::vector<RotatedRectangle> boxes = GetEditedSprite().GetCollisionMask();
        if ( selectedBox < boxes.size())
            boxes.erase(boxes.begin() + selectedBox);

        GetEditedSprite().SetCollisionMaskAutomatic(false);
        GetEditedSprite().SetCustomCollisionMask(boxes);

        if ( applyMaskToAllDirectionSprites->IsChecked() )
        {
            for (unsigned int i =0;i<object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSpritesToModify().size();++i)
            {
                object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(i).SetCollisionMaskAutomatic(false);
                object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(i).SetCustomCollisionMask(boxes);
            }
        }

        imagePanel->Refresh();
        imagePanel->Update(); //Imm�diatement
    }
}

void OldSpriteObjectEditor::OnAddMaskRectangleSelected(wxCommandEvent& event)
{
    if ( editingMask && SpriteValid())
    {
        std::vector<RotatedRectangle> boxes = GetEditedSprite().GetCollisionMask();

        RotatedRectangle newRectangle;
        newRectangle.halfSize.x = ToFloat(string(wxGetTextFromUser(_("Entrez la largeur du rectangle"), _("Nouveau rectangle"), "32").mb_str()))/2.0f;
        newRectangle.halfSize.y = ToFloat(string(wxGetTextFromUser(_("Entrez la hauteur du rectangle"), _("Nouveau rectangle"), "32").mb_str()))/2.0f;
        newRectangle.angle = 0;
        boxes.push_back(newRectangle);

        GetEditedSprite().SetCollisionMaskAutomatic(false);
        GetEditedSprite().SetCustomCollisionMask(boxes);

        if ( applyMaskToAllDirectionSprites->IsChecked() )
        {
            for (unsigned int i =0;i<object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSpritesToModify().size();++i)
            {
                object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(i).SetCollisionMaskAutomatic(false);
                object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(i).SetCustomCollisionMask(boxes);
            }
        }

        imagePanel->Refresh();
        imagePanel->Update(); //Imm�diatement
    }
}

void OldSpriteObjectEditor::OnEditMaskSelected(wxCommandEvent& event)
{
    editingMask = !editingMask;

    if ( editingMask )
    {
        placingPoint = false;

        toolbar->EnableTool(idAddPoint, false);
        toolbar->EnableTool(idDelPoint, false);
        toolbar->EnableTool(ID_MENUITEM8, true);
        toolbar->EnableTool(ID_MENUITEM9, true);
    }
    else
    {
        toolbar->EnableTool(ID_MENUITEM8, false);
        toolbar->EnableTool(ID_MENUITEM9, false);
    }

    imagePanel->Refresh();
    imagePanel->Update(); //Imm�diatement
}

void OldSpriteObjectEditor::OnModifyMaskRectangleSelected(wxCommandEvent& event)
{
    if ( editingMask && SpriteValid())
    {
        std::vector<RotatedRectangle> boxes = GetEditedSprite().GetCollisionMask();
        if ( selectedBox < boxes.size())
        {
            float width = ToFloat(string(wxGetTextFromUser(_("Entrez la largeur du rectangle"), _("Edition d'un rectangle"), ToString(boxes[selectedBox].halfSize.x*2.0f)).mb_str()));
            if ( width != 0 ) boxes[selectedBox].halfSize.x = width/2.0f;
            float height = ToFloat(string(wxGetTextFromUser(_("Entrez la hauteur du rectangle"), _("Edition d'un rectangle"), ToString(boxes[selectedBox].halfSize.y*2.0f)).mb_str()));
            if ( height != 0 ) boxes[selectedBox].halfSize.y = height/2.0f;
        }
        GetEditedSprite().SetCollisionMaskAutomatic(false);
        GetEditedSprite().SetCustomCollisionMask(boxes);

        if ( applyMaskToAllDirectionSprites->IsChecked() )
        {
            for (unsigned int i =0;i<object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSpritesToModify().size();++i)
            {
                object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(i).SetCollisionMaskAutomatic(false);
                object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(i).SetCustomCollisionMask(boxes);
            }
        }

        imagePanel->Refresh();
        imagePanel->Update(); //Imm�diatement
    }
}


void OldSpriteObjectEditor::OnEnterMaskRectanglePositionSelected(wxCommandEvent& event)
{
    if ( editingMask && SpriteValid())
    {
        std::vector<RotatedRectangle> boxes = GetEditedSprite().GetCollisionMask();
        if ( selectedBox < boxes.size())
        {
            boxes[selectedBox].center.x = ToFloat(string(wxGetTextFromUser(_("Entrez la position X rectangle"), _("Edition d'un rectangle"), ToString(boxes[selectedBox].center.x)).mb_str()));
            boxes[selectedBox].center.y = ToFloat(string(wxGetTextFromUser(_("Entrez la position Y rectangle"), _("Edition d'un rectangle"), ToString(boxes[selectedBox].center.y)).mb_str()));
        }
        GetEditedSprite().SetCollisionMaskAutomatic(false);
        GetEditedSprite().SetCustomCollisionMask(boxes);

        if ( applyMaskToAllDirectionSprites->IsChecked() )
        {
            for (unsigned int i =0;i<object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSpritesToModify().size();++i)
            {
                object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(i).SetCollisionMaskAutomatic(false);
                object.GetAnimation( animation ).GetDirectionToModify( direction ).GetSprite(i).SetCustomCollisionMask(boxes);
            }
        }

        imagePanel->Refresh();
        imagePanel->Update(); //Imm�diatement
    }
}

/**
 * Exit point editing
 */
void OldSpriteObjectEditor::OnEditPointsSelected(wxCommandEvent& event)
{
    placingPoint = false;

    toolbar->EnableTool(idAddPoint, false);
    toolbar->EnableTool(idDelPoint, false);
}

#endif