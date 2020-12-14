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

    h_etaphi->Draw("colz");
    c1->Print(pdf,"pdf");

    h_late->Draw("hist text");
    h_late->SetLineColor(kAzure-4);
    h_late->GetXaxis()->SetBinLabel(1,"All");
    h_late->GetXaxis()->SetBinLabel(2,"3Muon");
    h_late->GetXaxis()->SetBinLabel(3,"3sta");
    h_late->GetXaxis()->SetBinLabel(4,"HotRoI");
    h_late->GetXaxis()->SetBinLabel(5,"OvlpRmvl");
    h_late->GetXaxis()->SetBinLabel(6,"Charge");
    h_late->GetXaxis()->SetBinLabel(7,"T");
    h_late->GetXaxis()->SetBinLabel(8,"");
    c1->Print(pdf,"pdf");

    A_eta->Draw("hist");
    A_eta->SetFillColor(kOrange-2);
    A_eta->SetLineWidth(1);
    S_eta->Draw("hist same");
    S_eta->SetFillColor(kOrange+8);
    S_eta->SetLineWidth(1);
    H_eta->Draw("hist same");
    H_eta->SetFillColor(kViolet+1);
    H_eta->SetLineWidth(1);
    O_eta->Draw("hist same");
    O_eta->SetFillColor(kAzure+1);
    O_eta->SetLineWidth(1);
    C_eta->Draw("hist same");
    C_eta->SetFillColor(kSpring+5);
    C_eta->SetLineWidth(1);
    B_eta->Draw("hist same");
    B_eta->SetFillColor(kGreen-1);
    B_eta->SetLineWidth(1);
    c1->Print(pdf,"pdf");

    c1 -> Print( pdf + "]", "pdf" );
    delete c1;
}
