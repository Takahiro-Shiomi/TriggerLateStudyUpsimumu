#include "../include/TriggerLateStudy.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

void TriggerLateStudy::RPC_Run3()
{
    for(int j=0;j!=muctpi_ndatawords;j++){
        if(muctpi_source->at(j)!=0)continue;
        if(muctpi_candidateVetoed->at(j)==1)continue;
        if(muctpi_bcid->at(j)!=(bcid&0x7))continue;
        
        int rpc_pt=muctpi_thrNumber->at(j);
        float Run3_pt=9999999;
        if(rpc_pt==1){Run3_pt=4;}
        if(rpc_pt==2){Run3_pt=6;}
        if(rpc_pt==3){Run3_pt=10;}
        if(rpc_pt==4){Run3_pt=10;}
        if(rpc_pt==5){Run3_pt=20;}
        if(rpc_pt==6){Run3_pt=20;}
        if(Run3_pt>20){continue;}

        float rpc_eta = (*muctpi_eta)[j];
        float rpc_phi = (*muctpi_phi)[j];
        int   rpc_roi = (*muctpi_roi)[j];
        int   rpc_sector = (*muctpi_sectorID)[j];
        int   rpc_source = (*muctpi_source)[j];
        int   rpc_side = (*muctpi_hemisphere)[j];

        roi_pt.push_back(Run3_pt);
        roi_eta.push_back(rpc_eta);
        roi_phi.push_back(rpc_phi);
        roi_roi.push_back(rpc_roi);
        roi_sector.push_back(rpc_sector);
        roi_source.push_back(rpc_source);
        roi_side.push_back(rpc_side);
        roi_ovlp.push_back(false);
        roi_charge.push_back(2);
    }
}
