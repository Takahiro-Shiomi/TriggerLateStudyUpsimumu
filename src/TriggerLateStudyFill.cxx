#include "../include/TriggerLateStudy.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

void TriggerLateStudy::FillHist()
{
  Clear();
  if(muon_n>=3){Offline();}

  if(tau_pt.size()>0){
    if(TGC_Run3_n>=1){TGC_Run3();}
    if(muctpi_ndatawords>=1){RPC_Run3();}
    if(roi_pt.size()>=3){
      OverlapRemoval();
      Match();
      for(unsigned int i=0;i!=roi_pt.size();i++){
        if(!roi_ovlp.at(i) && roi_match.at(i)){
          RoI_pt.push_back(roi_pt.at(i));
          RoI_eta.push_back(roi_eta.at(i));
          RoI_phi.push_back(roi_phi.at(i));
          RoI_charge.push_back(roi_charge.at(i));
          RoI_source.push_back(roi_source.at(i));
        }
      }
      if(RoI_pt.size()>=3){
        for(int i=0;i!=(int)RoI_pt.size();i++){A_eta->Fill(RoI_eta.at(i),(float)1/(float)RoI_eta.size());}
        for(int i=0;i!=(int)tau_pt.size();i++){R_pt->Fill(tau_pt.at(i)); R_dR->Fill(tau_dr.at(i));}
        Mass();
        DR();
      }
    }
  }
}

void TriggerLateStudy::Clear()
{
    off_eta.clear();
    off_phi.clear();

    tau_pt.clear();
    tau_dr.clear();
    tau_eta.clear();
    tau_phi.clear();

    roi_pt.clear();
    roi_eta.clear();
    roi_phi.clear();
    roi_roi.clear();
    roi_sector.clear();
    roi_source.clear();
    roi_side.clear();
    roi_ovlp.clear();
    roi_match.clear();
    roi_charge.clear();

    RoI_pt.clear();
    RoI_eta.clear();
    RoI_phi.clear();
    RoI_charge.clear();
    RoI_source.clear();
}
