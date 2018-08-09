void macro5(){

auto cntrh=new TH1F("count_rate","count Rate; N-{Counts};# occurrencies", 100, -0.5, 15.5);

auto mean_count=3. 6f;
TRandom3 rndgen;

for (int imeas=0;imeas<400;imeas++)
	cntrh->Fill(rndgen.Poisson(mean_count));


auto c=new TCanvas();
cntrh->Draw();


auto c_norm=new TCanvas();
cntrh->DrawNormalized();


cout << "Moments of Distribution:\n"
	<< "- Mean	= "	<< cntrh->GetMean()	<< " +-"
	<< 			<< cntrh->GetMeanError()<<"\n"
	<< "- StdDev = "	<< cntrh->GetStdDev()	<< end;

}
