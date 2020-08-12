#include "../include/TriggerLateStudy.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

void TriggerLateStudy::OverlapRemoval()
{
    int can = (int)roi_pt.size();
    for(int i=0;i!=can;i++){
        int roi1 = roi_roi.at(i);
        int sec1 = roi_sector.at(i);
        int source1 = roi_source.at(i);
        int side1 = roi_side.at(i);

        for(int j=i+1;j!=can;j++){
            int roi2 = roi_roi.at(j);
            int sec2 = roi_sector.at(j);
            int source2 = roi_source.at(j);
            int side2 = roi_side.at(j);

            bool OvlpFlag=false;

            if(side1==side2){
                if(source1==1&&source2==1){OvlpFlag = EndcapEndcap(roi1,roi2,sec1,sec2);}/*EE OvelapRemoval*/
                else if(source1==2&&source2==2){OvlpFlag = ForwardForward(roi1,roi2,sec1,sec2);}/*FF OvelapRemoval*/
                else if((source1==1&&source2==2)||(source1==2&&source2==1)){OvlpFlag = ForwardEndcap(source1,source2,roi1,roi2,sec1,sec2);}/*FE OvelapRemoval*/
                else if((source1==0&&source2==1)||(source1==1&&source2==0)){OvlpFlag = BarrelEndcap(side1,side2,source1,source2,roi1,roi2,sec1,sec2);}/*BE OvelapRemoval*/
            }
            if(OvlpFlag){
                roi_ovlp.at(i)=true;
                break;
            }
        }
    }
}
bool TriggerLateStudy::EndcapEndcap(int roi1,int roi2,int sec1,int sec2)
{
    int dsec = abs(sec1-sec2);
    int droi = abs(roi1-roi2);
    bool flag=false;

    if((dsec==1)||(dsec==47)){
        if(sec1>sec2){
            if(sec1%2==0){if(roi1%4==0){if(roi2%4==0){if((droi==0)||(droi==4)){flag=true;}}}}
            if(sec1%2==1){if(roi1%4==3){if(roi2%4==3){if((droi==0)||(droi==4)){flag=true;}}}}
        }
        if(sec2>sec1){
            if(sec2%2==0){if(roi2%4==0){if(roi1%4==0){if((droi==0)||(droi==4)){flag=true;}}}}
            if(sec2%2==1){if(roi2%4==3){if(roi1%4==3){if((droi==0)||(droi==4)){flag=true;}}}}
        }
    }
    return flag;
}
bool TriggerLateStudy::ForwardForward(int roi1,int roi2,int sec1,int sec2)
{
    int dsec = abs(sec1-sec2);
    int droi = abs(roi1-roi2);
    bool flag=false;

    if((dsec==1)||(dsec==23)){
        if(sec1>sec2){if(roi1%4==3){if(roi2%4==0){if((droi==1)||(droi==3)||(droi==7)){flag=true;}}}}
        if(sec2>sec1){if(roi1%4==0){if(roi2%4==3){if((droi==1)||(droi==3)||(droi==7)){flag=true;}}}}
    }
    return flag;
}
bool TriggerLateStudy::ForwardEndcap(int source1,int source2,int a,int b,int c,int d)
{
    int roi1;
    int roi2;
    int sec1;
    int sec2;
    if(source1==1&&source2==2){roi1=a; roi2=b; sec1=c; sec2=d;}//1==Endcap,2==Forward
    if(source1==2&&source2==1){roi1=b; roi2=a; sec1=d; sec2=c;}//1==Endcap,2==Forward
    bool flag=false;

    if((int)(sec1/2)==sec2){
        if(roi1==145||roi1==144){if(roi2==0||roi2==3){flag=true;}}
        if(roi1==146||roi1==147){if(roi2==1||roi2==2){flag=true;}}
    }
    return flag;
}
bool TriggerLateStudy::BarrelEndcap(int side1,int side2,int source1,int source2,int a,int b,int c,int d)
{
    int roi1;
    int roi2;
    int sec1;
    int sec2;
    if(source1==0&&source2==1){roi1=a; roi2=b; sec1=c; sec2=d;}//1==Barrel,2==Endcap
    if(source1==1&&source2==0){roi1=b; roi2=a; sec1=d; sec2=c;}//1==Barrel,2==Endcap
    bool flag=false;

    if(side1==0&&side2==0){
        if(sec1%4==3){
            if(sec2%6==0){
                if(roi1==27){if((roi2>=1&&roi2<=3)||(roi2>=5&&roi2<=7)||(roi2>=9&&roi2<=11)){flag=true;}}
                if(roi1==22){if((roi2>=1&&roi2<=3)||(roi2>=5&&roi2<=7)){flag=true;}}
            }
            if(sec2%6==1){
                if(roi1==27){if(roi2==3||roi2==7||roi2==11){flag=true;}}
                if(roi1==22){if(roi2==3||roi2==7){flag=true;}}
                if(roi1==25){if(roi2>=0&&roi2<=11){flag=true;}}
                if(roi1==20){if(roi2>=0&&roi2<=7){flag=true;}}
            }
            if(sec2%6==2){
                if(roi1==25){if(roi2==0||roi2==4||roi2==8){flag=true;}}
                if(roi1==20){if(roi2==0||roi2==4){flag=true;}}
            }
        }
        if(sec1%4==0){
            if(sec2%6==3){
                if(roi1==26){if((roi2>=1&&roi2<=3)||(roi2>=5&&roi2<=7)||(roi2>=9&&roi2<=11)){flag=true;}}
                if(roi1==23){if((roi2>=1&&roi2<=3)||(roi2>=5&&roi2<=7)){flag=true;}}
            }
            if(sec2%6==2){
                if(roi1==26){if(roi2==3||roi2==7||roi2==11){flag=true;}}
                if(roi1==23){if(roi2==3||roi2==7){flag=true;}}
                if(roi1==24){if(roi2>=0&&roi2<=11){flag=true;}}
                if(roi1==21){if(roi2>=0&&roi2<=7){flag=true;}}
            }
            if(sec2%6==1){
                if(roi1==24){if(roi2==0||roi2==4||roi2==8){flag=true;}}
                if(roi1==21){if(roi2==0||roi2==4){flag=true;}}
            }
        }
    }
    if(side1==1&&side2==1){
        if(sec1%4==0){
            if(sec2%6==3){
                if(roi1==27){if((roi2>=1&&roi2<=3)||(roi2>=5&&roi2<=7)||(roi2>=9&&roi2<=11)){flag=true;}}
                if(roi1==22){if((roi2>=1&&roi2<=3)||(roi2>=5&&roi2<=7)){flag=true;}}
            }
            if(sec2%6==2){
                if(roi1==27){if(roi2==3||roi2==7||roi2==11){flag=true;}}
                if(roi1==22){if(roi2==3||roi2==7){flag=true;}}
                if(roi1==25){if(roi2>=0&&roi2<=11){flag=true;}}
                if(roi1==20){if(roi2>=0&&roi2<=7){flag=true;}}
            }
            if(sec2%6==1){
                if(roi1==25){if(roi2==0||roi2==4||roi2==8){flag=true;}}
                if(roi1==20){if(roi2==0||roi2==4){flag=true;}}
            }
        }
        if(sec1%4==3){
            if(sec2%6==0){
                if(roi1==26){if((roi2>=1&&roi2<=3)||(roi2>=5&&roi2<=7)||(roi2>=9&&roi2<=11)){flag=true;}}
                if(roi1==23){if((roi2>=1&&roi2<=3)||(roi2>=5&&roi2<=7)){flag=true;}}
            }
            if(sec2%6==1){
                if(roi1==26){if(roi2==3||roi2==7||roi2==11){flag=true;}}
                if(roi1==23){if(roi2==3||roi2==7){flag=true;}}
                if(roi1==24){if(roi2>=0&&roi2<=11){flag=true;}}
                if(roi1==21){if(roi2>=0&&roi2<=7){flag=true;}}
            }
            if(sec2%6==2){
                if(roi1==24){if(roi2==0||roi2==4||roi2==8){flag=true;}}
                if(roi1==21){if(roi2==0||roi2==4){flag=true;}}
            }
        }
    }
    return flag;
}
