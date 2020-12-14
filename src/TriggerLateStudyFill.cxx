#include "../include/TriggerLateStudy.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

void TriggerLateStudy::FillHist()
{
    Clear();
    bool hlt = HLT();

    if(hlt){
        h_late->Fill(0);
        if(TGC_Run3_n>=1){TGC_Run3();}
        if(muctpi_ndatawords>=1){RPC_Run3();}
        if(roi_pt.size()>=3){
            h_late->Fill(1);

            int s_count=0;
            int h_count=0;
            for(int i=0;i!=(int)roi_pt.size();i++){ 
                if(roi_station.at(i)){s_count = s_count+1;}
                if(roi_station.at(i) && !roi_hotroi.at(i)){h_count = h_count+1;}
                A_eta->Fill(roi_eta.at(i),(float)1/(float)roi_eta.size()); 
            }

            if(s_count>=3){
                h_late->Fill(2);
                for(int i=0;i!=(int)roi_eta.size();i++){
                    if(roi_station.at(i)){
                        S_eta->Fill(roi_eta.at(i),(float)1/(float)s_count); 
                    }
                }
                if(h_count>=3){
                    h_late->Fill(3);
                    for(int i=0;i!=(int)roi_pt.size();i++){
                        if(roi_station.at(i) && !roi_hotroi.at(i)){
                            H_eta->Fill(roi_eta.at(i),(float)1/(float)h_count);
                        }
                    }
                    OverlapRemoval();
                    for(unsigned int i=0;i!=roi_pt.size();i++){
                        if(roi_station.at(i) && !roi_hotroi.at(i)){
                            if(!roi_ovlp.at(i)){
                                RoI_pt.push_back(roi_pt.at(i));
                                RoI_eta.push_back(roi_eta.at(i));
                                RoI_phi.push_back(roi_phi.at(i));
                                RoI_charge.push_back(roi_charge.at(i));
                                RoI_source.push_back(roi_source.at(i));
                            }
                        }
                    }
                    if(RoI_pt.size()>=3){
                        h_late->Fill(4);
                        for(int i=0;i!=(int)RoI_pt.size();i++){ O_eta->Fill(RoI_eta.at(i),(float)1/(float)RoI_eta.size()); }
                        Mass();
                    }
                }
            }
        }
    }
}

void TriggerLateStudy::Clear()
{
    roi_pt.clear();
    roi_eta.clear();
    roi_phi.clear();
    roi_roi.clear();
    roi_sector.clear();
    roi_source.clear();
    roi_side.clear();
    roi_ovlp.clear();
    roi_charge.clear();
    roi_station.clear();
    roi_hotroi.clear();

    RoI_pt.clear();
    RoI_eta.clear();
    RoI_phi.clear();
    RoI_charge.clear();
    RoI_source.clear();
}
