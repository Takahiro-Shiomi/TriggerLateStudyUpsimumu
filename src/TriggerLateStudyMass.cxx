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
  //Two muon invariant mass
  for(int i=0;i!=candidate;i++){
    for(int j=i+1;j!=candidate;j++){
      /*
         bool sign = false;
         if(RoI_source.at(i)!=0 && RoI_source.at(j)!=0){
         if(RoI_charge.at(i) == RoI_charge.at(j)){ sign=true; }
         }
         if(sign) continue;
         */
      TLorentzVector first;
      first.SetPtEtaPhiM(RoI_pt.at(i),RoI_eta.at(i),RoI_phi.at(i),0.10566);
      TLorentzVector second;
      second.SetPtEtaPhiM(RoI_pt.at(j),RoI_eta.at(j),RoI_phi.at(j),0.10566);
      TLorentzVector two;
      two = first + second;

      h_2mass->Fill(two.M());
      h_2dR->Fill(first.DeltaR(second));
      h_2MdR->Fill(two.M(),first.DeltaR(second));

      for(int k=0;k!=candidate;k++){
        if(k==i||k==j){continue;}
        TLorentzVector third;
        third.SetPtEtaPhiM(RoI_pt.at(k),RoI_eta.at(k),RoI_phi.at(k),0.10566);

        TLorentzVector three;
        three = two + third;

        h_3mass->Fill(three.M());
        h_3dR->Fill(third.DeltaR(two));
        h_3MdR->Fill(three.M(),third.DeltaR(two));
      }
    }
  }
}

void TriggerLateStudy::DR()
{
  for(int tau=0;tau!=(int)tau_eta.size();tau++){
    float DR=0;
    for(int roi=0;roi!=RoI_eta.size();roi++){
      float deta = abs(tau_eta.at(tau) - RoI_eta.at(roi));
      float dphi = TVector2::Phi_mpi_pi(tau_phi.at(tau) - RoI_phi.at(roi));
      float dR = sqrt(deta*deta + dphi*dphi);
      if(DR<dR){
        DR=dR;
      }
    }
    Tau_dR->Fill(DR);
  }
}
