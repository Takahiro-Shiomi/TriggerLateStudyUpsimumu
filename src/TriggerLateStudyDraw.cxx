#include "../include/TriggerLateStudy.h"
#include "/home/shiomi/RootUtils/RootUtils/TLegend_addfunc.h"
#include "/home/shiomi/RootUtils/RootUtils/TCanvas_opt.h"
#include "TStyle.h"
#include "TF1.h"
#include "THStack.h"
#include "TLegend.h"
#include "TEfficiency.h"

using namespace std;

void TriggerLateStudy::Draw(TString pdf)
{
    TCanvas_opt *c1 = new TCanvas_opt();
    gStyle->SetOptStat(0);
    c1->SetTopMargin(0.20);
    c1->Print(pdf + "[", "pdf");

    O_2mass->Draw();
    O_2mass->SetLineColor(kOrange+8);
    O_2mass->SetFillColor(kOrange+8);
    O_2mass->SetFillStyle(3004);
    c1->Print(pdf,"pdf");
    
    O_2dR->Draw();
    O_2dR->SetLineColor(kOrange+8);
    O_2dR->SetFillColor(kOrange+8);
    O_2dR->SetFillStyle(3004);
    c1->Print(pdf,"pdf");

    O_3mass->Draw();
    O_3mass->SetLineColor(kOrange+8);
    O_3mass->SetFillColor(kOrange+8);
    O_3mass->SetFillStyle(3004);
    c1->Print(pdf,"pdf");
    
    O_3dR->Draw();
    O_3dR->SetLineColor(kOrange+8);
    O_3dR->SetFillColor(kOrange+8);
    O_3dR->SetFillStyle(3004);
    c1->Print(pdf,"pdf");

    h_2mass->Draw();
    h_2mass->SetLineColor(kOrange+8);
    h_2mass->SetFillColor(kOrange+8);
    h_2mass->SetFillStyle(3004);
    c1->Print(pdf,"pdf");

    h_2dR->Draw();
    h_2dR->SetLineColor(kOrange+8);
    h_2dR->SetFillColor(kOrange+8);
    h_2dR->SetFillStyle(3004);
    c1->Print(pdf,"pdf");

    h_3mass->Draw();
    h_3mass->SetLineColor(kOrange+8);
    h_3mass->SetFillColor(kOrange+8);
    h_3mass->SetFillStyle(3004);
    c1->Print(pdf,"pdf");
    
    h_3dR->Draw();
    h_3dR->SetLineColor(kOrange+8);
    h_3dR->SetFillColor(kOrange+8);
    h_3dR->SetFillStyle(3004);
    c1->Print(pdf,"pdf");

    h_2MdR->Draw("colz");
    c1->Print(pdf,"pdf");

    h_3MdR->Draw("colz");
    c1->Print(pdf,"pdf");

    A_eta->Draw("hist");
    c1->Print(pdf,"pdf");

    h_dr->Draw();
    c1->Print(pdf,"pdf");

    O_pt->Draw("hist");
    O_pt->SetFillColor(kGreen);
    R_pt->Draw("hist same");
    R_pt->SetFillColor(kYellow);
    c1->Print(pdf,"pdf");
    cout<<R_pt->Integral()<<endl;

    TEfficiency *h_eff;
    if(TEfficiency::CheckConsistency(*R_pt, *O_pt)){
        h_eff = new TEfficiency(*R_pt, *O_pt);
        h_eff->Draw("ALP");
        h_eff->SetTitle(";p^{offline}_{T} [GeV];Efficiency");
        h_eff->SetMarkerStyle(8);
        h_eff->SetLineWidth(1);
        h_eff->SetLineStyle(7);
        h_eff->Write();
    }
    c1->Print(pdf,"pdf");

    O_dR->Draw("hist");
    O_dR->SetFillColor(kGreen);
    R_dR->Draw("hist same");
    R_dR->SetFillColor(kYellow);
    c1->Print(pdf,"pdf");
    cout<<R_dR->Integral()<<endl;

    TEfficiency *DR_eff;
    if(TEfficiency::CheckConsistency(*R_dR, *O_dR)){
        DR_eff = new TEfficiency(*R_dR, *O_dR);
        DR_eff->Draw("ALP");
        DR_eff->SetTitle(";#DeltaR;Efficiency");
        DR_eff->SetMarkerStyle(8);
        DR_eff->SetLineWidth(1);
        DR_eff->SetLineStyle(7);
        DR_eff->Write();
    }
    c1->Print(pdf,"pdf");

    Tau_dR->Draw("hist");
    c1->Print(pdf,"pdf");

    c1 -> Print( pdf + "]", "pdf" );
    delete c1;
}
