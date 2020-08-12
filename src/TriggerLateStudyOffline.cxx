#include "../include/TriggerLateStudy.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>
#include "TLorentzVector.h"

using namespace std;

bool TriggerLateStudy::Offline()
{
    if(muon_n<2){return false;}
    for(int i=0; i!=muon_n; i++){
        if((*muon_author)[i]!=1 || (*muon_Type)[i]!=0){continue;}
        float can1eta = (*muon_eta)[i];
        float can1phi = (*muon_phi)[i];
        float can1pt = (*muon_pt)[i]/1000;
        float can1m = (*muon_m)[i]/1000;
        TLorentzVector can1;
        can1.SetPtEtaPhiM(can1pt,can1eta,can1phi,can1m);

        for(int j=i+1;j!=muon_n;j++){
            if((*muon_author)[j]!=1 || (*muon_Type)[j]!=0){continue;}
            float can2eta = (*muon_eta)[j];
            float can2phi = (*muon_phi)[j];
            float can2pt = (*muon_pt)[j]/1000;
            float can2m = (*muon_m)[j]/1000;
            TLorentzVector can2;
            can1.SetPtEtaPhiM(can2pt,can2eta,can2phi,can2m);

            float eta_cal = cosh(can1eta - can2eta);
            float phi_cal = cos(can1phi - can2phi);
            float mass = 2*can1pt*can2pt*(eta_cal - phi_cal);

            if(sqrt(mass)>=2.8&&sqrt(mass)<=3.4){
            //if(sqrt(mass)>=5.166&&sqrt(mass)<=5.526){
                off_eta.push_back(can1eta);
                off_eta.push_back(can2eta);
                off_phi.push_back(can1phi);
                off_phi.push_back(can2phi);
                off_pt.push_back(can1pt);
                off_pt.push_back(can2pt);
                h_offpt->Fill(can1pt,can2pt);
            }
        }
    }
    if(off_eta.size()>0){return true;}
    else {return false;}
}

bool TriggerLateStudy::Match()
{
    int roi[(int)off_pt.size()];
    for(int i=0; i!=(int)off_pt.size(); i++){roi[i]=-100;}

    for(int i=0; i!=(int)off_pt.size(); i++){

        int roinum = -100;
        float DR = 10;
        float pT = off_pt.at(i);
        float Eta = -100;
        float Phi = -100;
        float Pt = -100;
        int Source = -1;
        int Charge = -1;

        for(int j=0;j!=(int)RoI_pt.size(); j++){

            bool same = false;
            for(int k=0; k!=(int)off_pt.size(); k++){
                if(roi[k]==j){
                    same = true;
                }
            }
            if(same) continue;

            float deta =abs(off_eta.at(i) - RoI_eta.at(j));
            float dphi=TVector2::Phi_mpi_pi(off_phi.at(i) - RoI_phi.at(j));
            float dR=sqrt(deta*deta + dphi*dphi);
            if(dR<DR){
                roinum = j;
                DR = dR;
                Eta = RoI_eta.at(j);
                Pt = RoI_pt.at(j);
                Phi = RoI_phi.at(j);
                Source = RoI_source.at(j);
                Charge = RoI_charge.at(j);
            }
        }
        h_dr->Fill(pT,DR);

        bool match=false;
        if(pT<=5&&DR<=0.3){match=true;}
        else if((pT>5&&pT<=15)&&DR<=0.4-(0.02*pT)){match=true;}
        else if(pT>15&&DR<=0.1){match=true;}
        if(match){
            roi[i] = roinum;
            match_pt.push_back(Pt);
            match_eta.push_back(Eta);
            match_phi.push_back(Phi);
            match_source.push_back(Source);
            match_charge.push_back(Charge);
        }
    }
    if(match_pt.size()>=2){return true;}
    else{return false;}
}

