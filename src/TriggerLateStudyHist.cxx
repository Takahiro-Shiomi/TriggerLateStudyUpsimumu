#include "../include/TriggerLateStudy.h"
#include <TH2.h>
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
    h_2mass = new TH1D("h_2mass",";M^{L1}_{#mu#mu#mu} [GeV];Events",70,0,7);
    h_2dR = new TH1D("h_2dR",";#DeltaR;Events",50,0,1.0);
    h_3mass = new TH1D("h_3mass",";M^{L1}_{#mu#mu#mu} [GeV];Events",70,0,7);
    h_3dR = new TH1D("h_3dR",";#DeltaR;Events",50,0,1.0);
    h_2MdR = new TH2D("h_2MdR",";M^{L1}_{#mu#mu#mu} [GeV];#DeltaR",70,0,7,50,0,1.0);
    h_3MdR = new TH2D("h_3MdR",";M^{L1}_{#mu#mu#mu} [GeV];#DeltaR",70,0,7,50,0,1.0);
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
}
