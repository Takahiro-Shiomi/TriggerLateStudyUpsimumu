#include "../include/TriggerLateStudy.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

void TriggerLateStudy::FillHist()
{
    Clear();
    if(muon_n>=2){
        bool off = Offline();
        if(off){
            if(TGC_Run3_n>=1){TGC_Run3();}
            if(muctpi_ndatawords>=1){RPC_Run3();}
            if(roi_pt.size()>=2){
                OverlapRemoval();
                for(unsigned int i=0;i!=roi_pt.size();i++){
                    if(!roi_ovlp.at(i)){
                        RoI_pt.push_back(roi_pt.at(i));
                        RoI_eta.push_back(roi_eta.at(i));
                        RoI_phi.push_back(roi_phi.at(i));
                        RoI_charge.push_back(roi_charge.at(i));
                        RoI_source.push_back(roi_source.at(i));
                    }
                }
                bool match = Match();
                if(match){
                    Mass();
                }
            }
        }
    }
}

void TriggerLateStudy::Clear()
{
    off_eta.clear();
    off_phi.clear();
    off_pt.clear();

    roi_pt.clear();
    roi_eta.clear();
    roi_phi.clear();
    roi_roi.clear();
    roi_sector.clear();
    roi_source.clear();
    roi_side.clear();
    roi_ovlp.clear();
    roi_charge.clear();

    RoI_pt.clear();
    RoI_eta.clear();
    RoI_phi.clear();
    RoI_charge.clear();
    RoI_source.clear();

    match_pt.clear();
    match_eta.clear();
    match_phi.clear();
    match_charge.clear();
    match_source.clear();
}
