#include "../include/TriggerLateStudy.h"
#include "/home/shiomi/RootUtils/RootUtils/TLegend_addfunc.h"
#include "/home/shiomi/RootUtils/RootUtils/TCanvas_opt.h"
#include "TStyle.h"
#include "TF1.h"
#include "THStack.h"
#include "TLegend.h"

using namespace std;

void TriggerLateStudy::Draw(TString pdf)
{
    TCanvas_opt *c1 = new TCanvas_opt();
    gStyle->SetOptStat(0);
    c1->SetTopMargin(0.20);
    c1->Print(pdf + "[", "pdf");

    h_dr->Draw("COL");
    c1->Print(pdf,"pdf");

    h_offpt->Draw("COL");
    c1->Print(pdf,"pdf");

    h_L1pt->Draw("COL");
    c1->Print(pdf,"pdf");

    c1->Clear();

    h_mass->Draw();
    h_mass->SetLineColor(kOrange);
    h_mass->SetFillColor(kOrange);
    h_mass->SetFillStyle(3015);
    c1->Print(pdf,"pdf");

    h_dR->Draw();
    h_dR->SetLineColor(kAzure);
    c1->Print(pdf,"pdf");

    c1 -> Print( pdf + "]", "pdf" );
    delete c1;
}
