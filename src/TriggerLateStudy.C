#define TriggerLateStudy_cxx
#include "../include/TriggerLateStudy.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

void TriggerLateStudy::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();

   Long64_t nbytes = 0, nb = 0;
   //for (Long64_t jentry=0; jentry<100;jentry++) {
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if((int)jentry % ((int)nentries/10)==0){
          std::cout<<"JOBS....."<<(int)jentry / ((int)nentries/100)<<"%....COMPLETE"<<std::endl;
      }
      FillHist();
   }
}
