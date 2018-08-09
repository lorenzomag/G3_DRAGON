#include "TCanvas.h"
#include "TROOT.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TArrow.h"
#include "TLatex.h"
#include <iostream>
#include <string>
#include <iomanip>

void table(){
	
	ofstream myfile("table.csv");
	
	if (myfile.is_open())
	{
		myfile	<<"N,"
			<<"Mean on time of flights (ns),"
			<<"Mean on z-recon. (cm),"
			<<"StdDev on z-recon. (cm)\n";
	}
	else
	{

	}

	auto hist1=new TH1F("gammatofhist","Gammatof",1000,50.,200.);
	auto hist2=new TH1F("zrec","zrec",1000,-20.,20.);

	for(int n=10;n<5001;n+=10){
	if(n<51||(n%50==0 && n<301)||n%500==0){
		

		h1001->Draw("gammatof>>gammatofhist","gammatof<200 & gammatof>80","",n,0);

  		h1001->Draw("gammatof*29.9287458*TMath::Sqrt(2*11.596/(931.494*23))-87.125>>zrec","gammatof<200 & gammatof>80","",n,0);
	
		cout<<fixed<<setprecision(1);
	
		cout<<"N="<<n<<" -- gammatof = "<<gammatofhist.GetMean()
		<<" ns with zrec = "<<zrec.GetMean()
		<<" +- "<<zrec.GetStdDev()<<" cm\n"<<endl;
		
		if (myfile.is_open())
		{
			myfile<<fixed<<setprecision(1);
			myfile	<<n<<","
				<<gammatofhist.GetMean()<<","
				<<zrec.GetMean()<<","
				<<zrec.GetStdDev()<<",\n";
		}
		else{
			cout<<"Unable to open file";
			return 0;
		}

		
		hist1.Reset();
		hist2.Reset();
	}
	}

myfile.close();

}
