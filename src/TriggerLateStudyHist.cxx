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
    h_mass = new TH1D("h_mass",";M^{L1}_{#mu#mu} [GeV];Events",45,0,15);
    h_dR = new TH1D("h_dR",";#DeltaR;Events",50,0,1.5);
    h_mass_B = new TH1D("h_mass_B",";M^{L1}_{#mu#mu} [GeV];Events",45,0,15);
    h_offpt = new TH2D("h_offpt",";p^{offline}_{T};p^{offline}_{T}",30,0,30,30,0,30);
    h_L1pt = new TH2D("h_L1pt",";p^{offline}_{T};p^{offline}_{T}",21,0,21,21,0,21);
    h_dr = new TH2D("h_dr",";p^{offline}_{T};#DeltaR",100,0,30,100,0,1);
}

void TriggerLateStudy::End()
{
    if(h_mass!=0){delete h_mass;}
    if(h_mass_B!=0){delete h_mass_B;}
    if(h_offpt!=0){delete h_offpt;}
    if(h_L1pt!=0){delete h_L1pt;}
    if(h_dr!=0){delete h_dr;}
    if(h_dR!=0){delete h_dR;}
}
