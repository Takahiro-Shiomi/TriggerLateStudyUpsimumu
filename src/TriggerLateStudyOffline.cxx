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

void TriggerLateStudy::Offline()
{
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
            if((*muon_charge)[i] == (*muon_charge)[j]){continue;}
            TLorentzVector can2;
            can2.SetPtEtaPhiM(can2pt,can2eta,can2phi,can2m);

            TLorentzVector two;
            two = can1 + can2;

            O_2mass->Fill(two.M());
            O_2dR->Fill(can1.DeltaR(can2));

            for(int k=0;k!=muon_n;k++){
                if(k==i||k==j){continue;}
                TLorentzVector can3;
                can3.SetPtEtaPhiM((*muon_pt)[k]/1000,(*muon_eta)[k],(*muon_phi)[k],(*muon_m)[k]/1000);

                TLorentzVector three;
                three = can3 + two;

                O_3mass->Fill(three.M());
                O_3dR->Fill(can3.DeltaR(two));
            }
        }
    }
}

bool TriggerLateStudy::Match()
{
    /*
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
    */
}

