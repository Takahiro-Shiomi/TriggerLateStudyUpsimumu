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
#include "TLorentzVector.h"

using namespace std;

void TriggerLateStudy::Mass()
{
    int candidate = RoI_pt.size();
    vector<float> SEta; SEta.clear();
    vector<float> BEta; BEta.clear();
    //Two muon invariant mass
    for(int i=0;i!=candidate;i++){
        for(int j=i+1;j!=candidate;j++){

            bool sign = false;
            if(RoI_source.at(i)!=0 && RoI_source.at(j)!=0){
                if(RoI_charge.at(i) == RoI_charge.at(j)){ sign=true; }
            }
            if(sign) continue;

            TLorentzVector first;
            first.SetPtEtaPhiM(RoI_pt.at(i),RoI_eta.at(i),RoI_phi.at(i),0.10566);
            TLorentzVector second;
            second.SetPtEtaPhiM(RoI_pt.at(j),RoI_eta.at(j),RoI_phi.at(j),0.10566);
            TLorentzVector two;
            two = first + second;

            h_2mass->Fill(two.M());
            h_2dR->Fill(first.DeltaR(second));
            h_2MdR->Fill(two.M(),first.DeltaR(second));
    
            //Three muon invariant mass        
            for(int k=0;k!=candidate;k++){
                if(k==i||k==j){continue;}
                SEta.push_back(RoI_eta.at(i));
                SEta.push_back(RoI_eta.at(j));
                SEta.push_back(RoI_eta.at(k));

                TLorentzVector third;
                third.SetPtEtaPhiM(RoI_pt.at(k),RoI_eta.at(k),RoI_phi.at(k),0.10566);

                TLorentzVector three;
                three = two + third;

                h_3mass->Fill(three.M());
                h_3dR->Fill(third.DeltaR(two));
                h_3MdR->Fill(three.M(),third.DeltaR(two));
                if(third.DeltaR(two)>=0.04 && third.DeltaR(two)<=0.2){
                    if(three.M()>=1.2 && three.M()<=3.5){
                        BEta.push_back(RoI_eta.at(i));
                        BEta.push_back(RoI_eta.at(j));
                        BEta.push_back(RoI_eta.at(k));
                    }
                }
            }
        }
    }
    if(SEta.size()!=0){
        for(int i=0;i!=(int)SEta.size();i++){ C_eta->Fill(SEta.at(i),(float)1/(float)SEta.size()); } 
        h_late->Fill(5);
    }
    if(BEta.size()!=0){
        h_late->Fill(6);
        for(int i=0;i!=(int)BEta.size();i++){
            B_eta->Fill(BEta.at(i),(float)1/(float)BEta.size());
        }
    }
}
