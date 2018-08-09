// As first argument of the recon() fuction, put name (and path if needed) of input file between inverted commas. Otherwise, use default input file.

// Second, third, and fourth arguments of the recon() function are the Initial Beam Energy (MeV), the stopping power of the gas (MeV/cm^2), the atomic mass (amu) of the incident beam particles.

//CURRENT REACTION: 23Mg (p,g) 24Al



void recon(const std::string& outputFileName="outfile_default.root", const std::string& inputFileName="5000events_23Mgp-g24Al.root"){

  
  Float_t amu = 931.5; // MeV/c^2
  Float_t c = 29979245800.*pow(10,-9); // cm/ns
  Float_t half_thickness = 6.14136028; // half-thickness of gas target
  

  TFile *f = new TFile(inputFileName.c_str());

  if (f->IsZombie()) return;


  TTree *h1001 = (TTree*)f->Get("h1001");

  Float_t E_i = 11.6835448658; Float_t SPow = 0.029402297; Float_t m = 22.9941237;
  Float_t gammatof,dt,z;
  
  m=m*amu;//Converts mass in MeV/c^2
  



  //Calculating expected initial velocity of incident particles (non-relativistically)
  Float_t v_i = sqrt(2*E_i/m)*c; // cm/ns
  Float_t t1 = (80.9836397/v_i); //time to reach beginning of gas target (ns)
  
  
  h1001->SetBranchAddress("gammatof",&gammatof);

  TH1F *recon = new TH1F("zrecon","z-coord reconstruction",10000,-7.,7.);
 
  
  Int_t nentries = (Int_t)h1001->GetEntries();

  //Data for graph
  const Int_t num_points_max = 5000;
  Float_t nevts [num_points_max] = {};
  Float_t meanz [num_points_max] = {};
  Float_t xerr [num_points_max] = {};
  Float_t yerr [num_points_max] = {};
  Int_t counter = 0;
  
  for (Int_t i=0;i<nentries;i++){
    h1001->GetEntry(i);
    if(gammatof<200. && gammatof>80.){
      dt = gammatof-t1;
      z = (-SPow*pow(dt,2))/(2*m)*pow(c,2) + v_i*dt-half_thickness; // cm from centre of gas target
      recon->Fill(z);

      if(i<51||(i%50==0 && i<301)||i%500==0){
	nevts[counter]=i;
	meanz[counter]=recon->GetMean();
	yerr[counter]=recon->GetMeanError();
	counter++;
	cout<<counter<<endl;
      }
    }
  }

  
  // TFile outputfile(outputFileName.c_str(),"RECREATE");

  c1 = new TCanvas("c1","A Simple Graph with error bars",200,10,700,500);
  c1.SetLogx();  
  gr = new TGraphErrors(counter,nevts,meanz,xerr,yerr);
  gr->SetTitle("TGraphErrors Example");
  gr->SetMarkerColor(4);
  gr->SetMarkerStyle(21);
  gr->Draw("AP");
  c1->Update();
  

  c2 = new TCanvas("c2","Afefef Simple Graph with error bars",200,10,700,500);
  recon->Draw();
 
 
  

  cout<<"E_i\t"<<E_i<<"\nSPow\t"<<SPow<<"\nm\t"<<m<<endl;
  

}
