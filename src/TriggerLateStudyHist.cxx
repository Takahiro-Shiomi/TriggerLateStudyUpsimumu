#include "../include/TriggerLateStudy.h"
#include <TH2.h>
#include <TMath.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

void TriggerLateStudy::InitHist()
{
    O_2mass = new TH1D("O_2mass",";M^{L1}_{#mu#mu#mu} [GeV];Events",50,0,3);
    O_2dR = new TH1D("O_2dR",";#DeltaR;Events",50,0,1.0);
    O_3mass = new TH1D("O_3mass",";M^{L1}_{#mu#mu#mu} [GeV];Events",50,0,3);
    O_3dR = new TH1D("O_3dR",";#DeltaR;Events",50,0,1.0);
    h_2mass = new TH1D("h_2mass","2Muon;M^{L1}_{#mu#mu#mu} [GeV];Events",70,0,7);
    h_2dR = new TH1D("h_2dR","2Muon;#DeltaR;Events",50,0,1.0);
    h_3mass = new TH1D("h_3mass","3Muon;M^{L1}_{#mu#mu#mu} [GeV];Events",70,0,7);
    h_3dR = new TH1D("h_3dR","3Muon;#DeltaR;Events",50,0,1.0);
    h_2MdR = new TH2D("h_2MdR","2Muon;M^{L1}_{#mu#mu#mu} [GeV];#DeltaR",70,0,7,50,0,1.0);
    h_3MdR = new TH2D("h_3MdR","3Muon;M^{L1}_{#mu#mu#mu} [GeV];#DeltaR",70,0,7,50,0,1.0);

    h_late = new TH1D("h_late",";;Events",8,0,8);

    h_etaphi = new TH2D("h_etaphi",";#eta;#phi",100,-2.5,2.5,96,-TMath::Pi(),TMath::Pi());
    A_eta = new TH1D("A_eta",";#eta^{RoI};Events",75,-2.7,2.7);
    S_eta = new TH1D("S_eta",";#eta^{RoI};Events",75,-2.7,2.7);
    H_eta = new TH1D("H_eta",";#eta^{RoI};Events",75,-2.7,2.7);
    O_eta = new TH1D("O_eta",";#eta^{RoI};Events",75,-2.7,2.7);
    C_eta = new TH1D("C_eta",";#eta^{RoI};Events",75,-2.7,2.7);
    B_eta = new TH1D("B_eta",";#eta^{RoI};Events",75,-2.7,2.7);
}

void TriggerLateStudy::End()
{
    if(O_2mass!=0){delete O_2mass;}
    if(O_2dR!=0){delete O_2dR;}
    if(O_3mass!=0){delete O_3mass;}
    if(O_3dR!=0){delete O_3dR;}
    if(h_2mass!=0){delete h_2mass;}
    if(h_2dR!=0){delete h_2dR;}
    if(h_3mass!=0){delete h_3mass;}
    if(h_3dR!=0){delete h_3dR;}
    if(h_2MdR!=0){delete h_2MdR;}
    if(h_3MdR!=0){delete h_3MdR;}

    if(h_late!=0){delete h_late;}
    if(h_etaphi!=0){delete h_etaphi;}
    if(A_eta!=0){delete A_eta;}
    if(S_eta!=0){delete S_eta;}
    if(H_eta!=0){delete H_eta;}
    if(O_eta!=0){delete O_eta;}
    if(C_eta!=0){delete C_eta;}
    if(B_eta!=0){delete B_eta;}
}
