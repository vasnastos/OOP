#include "popup.hpp"

popupWidget::popupWidget(wxWindow *parent):wxPopupTransientWindow(parent,wxBORDER_NONE|wxPU_CONTAINS_CONTROLS)
{
    this->w_panel=new wxScrolledWindow(this,wxID_ANY);
    wxPanel *panel=new wxPanel(this->w_panel,wxID_ANY);
    this->w_panel->SetSize(300,300);
    auto size=this->w_panel->GetSize();
    wxBoxSizer *bs=new wxBoxSizer(wxVERTICAL);
    this->w_button=new wxButton(panel,wxID_ANY,wxT("EVENT"),wxDefaultPosition,wxSize(100,20));
    this->w_button->Bind(wxEVT_BUTTON,&popupWidget::ButtonClicked,this);
    this->w_static_text=new wxStaticText(panel,wxID_ANY,wxT("POPUP COSTUM WIDGET"),wxDefaultPosition,wxSize(300,30));
    this->w_static_text->SetFont(wxFont(15,wxFONTFAMILY_ROMAN,wxNORMAL,wxBOLD));
    this->w_static_text->SetForegroundColour(wxColor("#40132c"));
    bs->AddSpacer(30);
    bs->Add(this->w_static_text,0,wxALIGN_CENTER);
    bs->AddSpacer(30);
    bs->Add(this->w_button,0,wxALIGN_CENTER);
    bs->AddSpacer(40);
    panel->SetSizer(bs);
    wxBoxSizer *b=new wxBoxSizer(wxVERTICAL);
    b->Add(panel,0,wxALIGN_CENTER);
    this->w_panel->SetSizer(b);
    this->w_panel->SetSize(100,100);
    this->w_panel->SetScrollRate(10,10);
    // If we want to disable the scroll
    // b->Fit(this->w_panel);
    SetClientSize(this->w_panel->GetSize());
}

popupWidget::~popupWidget() {
}

void popupWidget::ButtonClicked(wxCommandEvent &event)
{
    wxMessageBox(wxT("Button clicked!!!"));
}

void popupWidget::Popup(wxWindow* WXUNUSED(focus))
{
    wxPopupTransientWindow::Popup();
}

void popupWidget::OnDismiss()
{
    wxPopupTransientWindow::OnDismiss();
}

bool popupWidget::Show(bool show)
{
    wxPopupTransientWindow::Show(show);
    return show;
}
