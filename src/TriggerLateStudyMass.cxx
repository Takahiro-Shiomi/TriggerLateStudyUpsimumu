#include "../include/TriggerLateStudy.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>
#include "map"
#include "TVector2.h"

using namespace std;

void TriggerLateStudy::Mass()
{
    int candidate = match_pt.size();
    for(int i=0;i!=candidate;i++){
        for(int j=i+1;j!=candidate;j++){

            bool sign = false;
            if(match_source.at(i)!=0 && match_source.at(j)!=0){
                if(match_charge.at(i) == match_charge.at(j)){ sign=true; }
            }
            if(sign) continue;

            float eta_cal = cosh(match_eta.at(i) - match_eta.at(j));
            float phi_cal = cos(match_phi.at(i) - match_phi.at(j));
            float mass = 2*match_pt.at(i)*match_pt.at(j)*(eta_cal - phi_cal);
            h_mass->Fill(sqrt(mass));
            h_L1pt->Fill(match_pt.at(i), match_pt.at(j));

            float deta =abs(match_eta.at(i) - match_eta.at(j));
            float dphi=TVector2::Phi_mpi_pi(match_phi.at(i) - match_phi.at(j));
            float dR=sqrt(deta*deta + dphi*dphi);
            h_dR->Fill(dR);
        }
    }
    /*
    int candidate = RoI_pt.size();
    for(int i=0;i!=candidate;i++){
        for(int j=i+1;j!=candidate;j++){
            if(RoI_pt.at(i)<=11 && RoI_pt.at(j)<=11){
                float eta_cal = cosh(RoI_eta.at(i) - RoI_eta.at(j));
                float phi_cal = cos(RoI_phi.at(i) - RoI_phi.at(j));
                float mass = 2*RoI_pt.at(i)*RoI_pt.at(j)*(eta_cal - phi_cal);
                h_mass->Fill(sqrt(mass));
                h_L1pt->Fill(RoI_pt.at(i), RoI_pt.at(j));
                if(off_pt.size()>=2){
                    h_mass_B->Fill(sqrt(mass));
                }
            }
        }
    }
    */
}
