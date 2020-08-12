#include "../include/TriggerLateStudy.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

bool TriggerLateStudy::HotRoI(int tgc)
{
    int phisector = (*TGC_Run3_PhiSector)[tgc];
    int roi = (*TGC_Run3_RoI)[tgc];
    bool Flag = false;

    if((*TGC_Run3_IsEndcap)[tgc]){
            if(phisector%6==1){
            if(roi==44 || roi==48 || roi==52){Flag = true;}
            //if(roi==40 || roi==44 || roi==45 || roi==48 || roi==49 || roi==52){Flag = true;}
            }
            if(phisector%6==0){
            if(roi==52){Flag = true;}
            //if(roi==44 || roi==45 || roi==48 || roi==49 || roi==52){Flag = true;}
            }
            if(phisector%6==3){
            if(roi==75 || roi==79 || roi==83 || roi==87 || roi==91 || roi==94 || roi==95 || roi==99){Flag = true;}
            }
            if(phisector%6==4){
            if(roi==79 || roi==83 || roi==87 || roi==91 || roi==95 || roi==99){Flag = true;}
            }
    }
    return Flag;
}
