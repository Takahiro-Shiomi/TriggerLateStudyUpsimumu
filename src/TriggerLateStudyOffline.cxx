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
  float eta[3], phi[3], pt[3], m[3];
  for(int i=0; i!=muon_n; i++){
    if((*muon_author)[i]!=1 || (*muon_Type)[i]!=0){continue;}
    eta[0] = (*muon_eta)[i];
    phi[0] = (*muon_phi)[i];
    pt[0] = (*muon_pt)[i]/1000;
    m[0] = (*muon_m)[i]/1000;
    TLorentzVector can1;
    can1.SetPtEtaPhiM(pt[0],eta[0],phi[0],m[0]);

    for(int j=i+1;j!=muon_n;j++){
      if((*muon_author)[j]!=1 || (*muon_Type)[j]!=0){continue;}
      eta[1] = (*muon_eta)[j];
      phi[1] = (*muon_phi)[j];
      pt[1] = (*muon_pt)[j]/1000;
      m[1] = (*muon_m)[j]/1000;
      if((*muon_charge)[i] == (*muon_charge)[j]){continue;}
      TLorentzVector can2;
      can2.SetPtEtaPhiM(pt[1],eta[1],phi[1],m[1]);

      TLorentzVector two;
      two = can1 + can2;

      O_2mass->Fill(two.M());
      O_2dR->Fill(can1.DeltaR(can2));

      for(int k=0;k!=muon_n;k++){
        if(k==i||k==j){continue;}
        eta[2] = (*muon_eta)[k];
        phi[2] = (*muon_phi)[k];
        pt[2] = (*muon_pt)[k]/1000;
        m[2] = (*muon_m)[k]/1000;

        TLorentzVector can3;
        can3.SetPtEtaPhiM(pt[2],eta[2],phi[2],m[2]);

        TLorentzVector three;
        three = can3 + two;

        O_3mass->Fill(three.M());
        O_3dR->Fill(can3.DeltaR(two));
        if(three.M()>=1.5 && three.M()<=2.0){
          O_pt->Fill(three.Pt());
          tau_pt.push_back(three.Pt());
          tau_eta.push_back(three.Eta());
          tau_phi.push_back(three.Phi());
          off_eta.push_back(eta[0]);
          off_eta.push_back(eta[1]);
          off_eta.push_back(eta[2]);
          off_phi.push_back(phi[0]);
          off_phi.push_back(phi[1]);
          off_phi.push_back(phi[2]);
          float DR=0;
          for(int l=0;l!=3;l++){
            float deta = abs(three.Eta() - eta[l]);
            float dphi = TVector2::Phi_mpi_pi(three.Phi() - phi[l]);
            float dR = sqrt(deta*deta + dphi*dphi);
            if(dR>DR){
              DR=dR;
            }
          }
          O_dR->Fill(DR);
          tau_dr.push_back(DR);

          break;
        }
      }
    }
  }
}

void TriggerLateStudy::Match()
{
  int roi[(int)off_eta.size()];
  for(int i=0; i!=(int)off_eta.size(); i++){roi[i]=-100;}

  for(int i=0; i!=(int)off_eta.size(); i++){
    int roinum = -100;
    float DR = 10;
    for(int j=0;j!=(int)roi_pt.size();j++){
      bool same = false;
      for(int k=0; k!=(int)off_eta.size();k++){
        if(roi[k]==j){same = true;}
      }
      if(same) continue;
      float deta =abs(off_eta.at(i)-roi_eta.at(j));
      float dphi=TVector2::Phi_mpi_pi(off_phi.at(i)-roi_phi.at(j));
      float dR=sqrt(deta*deta + dphi*dphi);
      if(dR<DR){
        roinum = j;
        DR = dR;
      }
    }
    h_dr->Fill(DR);
    bool match=false;
    if(DR<=1.0){match=true;}
    if(match){
      roi[i] = roinum;
      roi_match.at(roinum) = true;
    }
  }
}
